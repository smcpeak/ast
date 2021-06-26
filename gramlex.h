// gramlex.h            see license.txt for copyright and terms of use
// GrammarLexer: a c++ lexer class for use with Flex's generated c++ scanner
// this lexer class is used both for parsing both AST and grammar descriptions;
// they differ in their .lex description, but their lexing state is the same

#ifndef __GRAMLEX_H
#define __GRAMLEX_H


// Due to the funky way I am sharing this file between ast and elkhound,
// it does not know which generated header to include, so that must be
// done by the includer of this file.
#ifndef yyFlexLexer_CLASS_DEFINED
#  error "Either agramlex.yy.h or gramlex.yy.h must be included first."
#endif

#include "sm-iostream.h"      // istream

// token code definitions
#define TOK_EOF 0             // better name
#define TOK_INCLUDE 1         // not seen by parser


// other includes
#include "str.h"              // string
#include "objlist.h"          // ObjList
#include "srcloc.h"           // SourceLoc
#include "embedded.h"         // EmbeddedLang
#include "strtable.h"         // StringTable, StringRef


// this class just holds the lexer state so it is properly encapsulated
// (and therefore, among other things, re-entrant)
class GrammarLexer : public yyFlexLexer, public ReportError {
public:      // types
  enum Constants {
    lexBufferSize = 4096,          // size of new lex buffers
  };

  // return true if the given token code is one of those representing
  // embedded text
  typedef bool (*isEmbedTok)(int tokCode);

  // error reporter that uses fileState instead of tokenStartLoc
  class AltReportError : public ReportError {
    GrammarLexer &lexer;

  public:
    AltReportError(GrammarLexer &L) : lexer(L) {}

    virtual void reportError(rostring msg) override;
    virtual void reportWarning(rostring msg) override;
  };
  friend class AltReportError;

public:      // data
  // exposed so a user-provided 'embedded' can use it
  AltReportError altReporter;

private:     // data
  // state of a file we were or are lexing
  struct FileState {
    SourceLoc loc;                 // location in the file
    istream *source;               // (owner?) source stream
    yy_buffer_state_t *bufstate;   // (owner?) flex's internal buffer state

  public:
    FileState(rostring filename, istream *source);
    ~FileState();

    FileState(FileState const &obj);
    FileState& operator= (FileState const &obj);
  };

  FileState fileState;             // state for file we're lexing now
  ObjList<FileState> fileStack;    // stack of files we will return to

  SourceLoc tokenStartLoc;         // location of start of current token

  // support for embedded code
  char embedStart;                 // if nonzero, punctuation that triggers
                                   // embedded processing
  char embedFinish;                // which character ends the embedded section
  int embedMode;                   // TOK_FUNDECL_BODY or TOK_FUN_BODY
  EmbeddedLang *embedded;          // (owner) the processor
  isEmbedTok embedTokTest;         // for printing diagnostics
  bool allowInit;                  // true if embedded can have an initializer

  int prevState;                   // so /**/ doesn't change start state

  int prevToken;                   // last token code yielded (ugly hack)

public:      // data
  // todo: can eliminate commentStartLine in favor of tokenStartLoc?
  //int commentStartLine;            // for reporting unterminated C comments
  int integerLiteral;              // to store number literal value
  StringRef stringLiteral;         // string in quotes, minus the quotes
  StringRef includeFileName;       // name in an #include directive

  // defined in the base class, FlexLexer:
  //   const char *YYText();           // start of matched text
  //   int YYLeng();                   // number of matched characters

  StringTable &strtable;           // string table

  // count of errors encountered
  int errors;

private:     // funcs
  // disallowed
  GrammarLexer(GrammarLexer const &);

  // called to advance the column count
  void advCol(int n)
    { fileState.loc = sourceLocManager->advCol(fileState.loc, n); }

  // called when a newline is encountered
  void newLine()
    { fileState.loc = sourceLocManager->advLine(fileState.loc); }

  // adds a string with only the specified # of chars
  StringRef addString(char const *str, int len) const;

  // nominally true if 'ch' equals 'embedFinish', but with a niggle
  bool embedFinishMatches(char ch) const;

public:      // funcs
  // create a new lexer that will read from to named stream,
  // or stdin if it is NULL
  GrammarLexer(isEmbedTok embedTokTest,
               StringTable &strtable,
               char const *fname = "<stdin>",
               istream * /*owner*/ source = NULL,
               EmbeddedLang * /*owner*/ embedded = NULL /*i.e. assume C lexics*/);

  // clean up
  ~GrammarLexer();

  // get current token as a string
  StringRef curToken() const;
  int curLen() const { return this->yym_leng(); }

  // current token's embedded text
  StringRef curFuncBody() const;
  StringRef curDeclBody() const { return curFuncBody(); }    // implementation artifact
  StringRef curDeclName() const;

  // read the next token and return its code; returns TOK_EOF for end of file;
  // this function is defined in flex's output source code; this one
  // *does* return TOK_INCLUDE
  int yym_lex();

  // similar to yylex, but process TOK_INCLUDE internally
  int yylexInc();

  // begin an embedded sequence
  void beginEmbed(char finish, int mode, int initNest = 0)
  {
    embedded->reset(initNest);
    embedFinish = finish;
    embedMode = mode;
  }

  // info about location of current token
  char const *curFname() const
    { return sourceLocManager->getFile(tokenStartLoc); }
  int curLine() const
    { return sourceLocManager->getLine(tokenStartLoc); }
  int curCol() const
    { return sourceLocManager->getCol(tokenStartLoc); }
  SourceLoc curLoc() const { return tokenStartLoc; }
  string curLocStr() const;    // string with file/line/col

  // error reporting; called by the lexer code
  void err(rostring msg) { reportError(msg); }     // msg should not include a newline
  void errorUnterminatedComment();
  void errorMalformedInclude();
  void errorIllegalCharacter(char ch);

  void printError(SourceLoc loc, rostring msg);
  void printWarning(SourceLoc loc, rostring msg);

  // for processing includes
  void recursivelyProcess(rostring fname, istream * /*owner*/ source);
  void popRecursiveFile();
  bool hasPendingFiles() const;

  // ReportError funcs
  virtual void reportError(rostring msg) override;
  virtual void reportWarning(rostring msg) override;
};


#endif // __GRAMLEX_H
