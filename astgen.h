// astgen.h
// Declarations for astgen.cc.

#ifndef AST_ASTGEN_H
#define AST_ASTGEN_H

#include "ast/ast.ast.h"               // ASTGen specification AST nodes

#include "smbase/astlist.h"            // ASTList
#include "smbase/objlist.h"            // ObjList
#include "smbase/sm-fstream.h"         // ofstream
#include "smbase/str.h"                // string


// ----------------------------- ListClass -----------------------------
// propertly a member of ListClass below, but I don't like nested
// things
enum ListKind {
  LK_NONE,
  LK_ASTList,
  LK_FakeList,
};

// a product type of the information relevant to a list member of a
// class; used to construct the traverse calls and visitors to the
// fictional list classes
struct ListClass {
  ListKind lkind;
  string classAndMemberName;
  string elementClassName;
  explicit ListClass(ListKind lkind0, rostring classAndMemberName0, rostring elementClassName0)
    : lkind(lkind0)
    , classAndMemberName(classAndMemberName0)
    , elementClassName(elementClassName0)
  {}
  char const * kindName() const;
};


// --------------------------- TreeNodeKind ----------------------------
enum TreeNodeKind { TKN_NONE, TKN_SUPERCLASS, TKN_SUBCLASS };


// -------------------------------- Gen --------------------------------
class Gen {
protected:        // data
  string srcFname;                  // name of source file
  ObjList<string> const &modules;   // extension modules
  string destFname;                 // name of output file
  ofstream out;                     // output stream
  ASTSpecFile const &file;          // AST specification

public:           // funcs
  Gen(rostring srcFname, ObjList<string> const &modules,
      rostring destFname, ASTSpecFile const &file);
  ~Gen();

  // shared output sequences
  void headerComments();
  void doNotEdit();
  void emitFiltered(ASTList<Annotation> const &decls, AccessCtl mode,
                    rostring indent);

  // Construct the header include latch symbol name.
  std::string makeIncludeLatch() const;
};


// ------------------------------ FwdGen -------------------------------
class FwdGen : public Gen {
public:        // funcs
  FwdGen(
    rostring srcFname,
    ObjList<string> const &modules,
    rostring destFname,
    ASTSpecFile const &file)
    : Gen(srcFname, modules, destFname, file)
  {}
  void emitFile();
};


// ------------------------------- HGen --------------------------------
class HGen : public Gen {
private:        // data
  // Name of the associated forward header file.
  std::string m_fwdFname;

private:        // funcs
  void emitVerbatim(TF_verbatim const &v);
  void emitTFClass(TF_class const &cls);
  void emitBaseClassDecls(ASTClass const &cls, int ct);
  static char const *virtualIfChildren(TF_class const &cls);
  void emitCtorFields(ASTList<CtorArg> const &args,
                      ASTList<CtorArg> const &lastArgs);
  void innerEmitCtorFields(ASTList<CtorArg> const &args);
  void emitCtorFormal(int &ct, CtorArg const *arg);
  void emitCtorFormals(int &ct, ASTList<CtorArg> const &args);
  void emitCtorDefn(ASTClass const &cls, ASTClass const *parent);
  void passParentCtorArgs(int &ct, ASTList<CtorArg> const &args);
  void initializeMyCtorArgs(int &ct, ASTList<CtorArg> const &args);
  void emitCommonFuncs(rostring virt, rostring over);
  void emitUserDecls(ASTList<Annotation> const &decls);
  void emitCtor(ASTClass const &ctor, ASTClass const &parent);

  void emitVisitorInterfacePrelude(rostring visitorName);
  void emitVisitorInterface();
  void emitDVisitorInterface();
  void emitMVisitorInterface();

public:         // funcs
  HGen(rostring srcFname, ObjList<string> const &modules,
       rostring destFname, ASTSpecFile const &file,
       rostring fwdFname)
    : Gen(srcFname, modules, destFname, file),
      m_fwdFname(fwdFname)
  {}
  void emitFile();
};


// ------------------------------- CGen --------------------------------
class CGen : public Gen {
public:
  string hdrFname;      // name of associated .h file

public:
  CGen(rostring srcFname, ObjList<string> const &modules,
       rostring destFname, ASTSpecFile const &file,
       rostring hdr)
    : Gen(srcFname, modules, destFname, file),
      hdrFname(hdr)
  {}

  void emitFile();
  void emitTFClass(TF_class const &cls);
  void emitDestructor(ASTClass const &cls);
  void emitDestroyField(bool isOwner, rostring type, rostring name);
  void emitPrintCtorArgs(ASTList<CtorArg> const &args);
  void emitPrintFields(ASTList<Annotation> const &decls);
  void emitPrintField(rostring print,
                      bool isOwner, rostring type, rostring name);

  bool emitCustomCode(ASTList<Annotation> const &list, rostring tag);

  void emitCloneCtorArg(CtorArg const *arg, int &ct);
  void emitCloneCtorArgs(int &ct, ASTList<CtorArg> const &args);
  void emitCloneCode(ASTClass const *super, ASTClass const *sub);

  void emitUserDefinedCustomHooks(ASTClass const &cls);
  void emitUserDefinedCustomHook(ASTClass const &cls,
    string const &declaration);

  void emitVisitorImplementation();

  private:
  void emitDVisitorImplVisitedCheck(char const *name);
  public:
  void emitDVisitorImplementation();
  void emitTraverse(ASTClass const *c, ASTClass const * /*nullable*/ super,
                    bool hasChildren);
  private:
  void emitOneTraverseCall(rostring className, string name, string type);

  public:
  void emitMVisitorImplementation();
  void emitMTraverse(ASTClass const *c, rostring obj, rostring ident);
  void emitMTraverseCall(rostring i, rostring eltType, rostring argVar);
};


#endif // AST_ASTGEN_H
