  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOK_NAME = 258,                /* TOK_NAME  */
    TOK_INTLIT = 259,              /* TOK_INTLIT  */
    TOK_EMBEDDED_CODE = 260,       /* TOK_EMBEDDED_CODE  */
    TOK_LBRACE = 261,              /* "{"  */
    TOK_RBRACE = 262,              /* "}"  */
    TOK_SEMICOLON = 263,           /* ";"  */
    TOK_ARROW = 264,               /* "->"  */
    TOK_LPAREN = 265,              /* "("  */
    TOK_RPAREN = 266,              /* ")"  */
    TOK_LANGLE = 267,              /* "<"  */
    TOK_RANGLE = 268,              /* ">"  */
    TOK_STAR = 269,                /* "*"  */
    TOK_AMPERSAND = 270,           /* "&"  */
    TOK_COMMA = 271,               /* ","  */
    TOK_EQUALS = 272,              /* "="  */
    TOK_COLON = 273,               /* ":"  */
    TOK_CLASS = 274,               /* "class"  */
    TOK_PUBLIC = 275,              /* "public"  */
    TOK_PRIVATE = 276,             /* "private"  */
    TOK_PROTECTED = 277,           /* "protected"  */
    TOK_VERBATIM = 278,            /* "verbatim"  */
    TOK_IMPL_VERBATIM = 279,       /* "impl_verbatim"  */
    TOK_CTOR = 280,                /* "ctor"  */
    TOK_DTOR = 281,                /* "dtor"  */
    TOK_PURE_VIRTUAL = 282,        /* "pure_virtual"  */
    TOK_CUSTOM = 283,              /* "custom"  */
    TOK_DEFINE_CUSTOMIZABLE = 284, /* "define_customizable"  */
    TOK_OPTION = 285,              /* "option"  */
    TOK_NEW = 286,                 /* "new"  */
    TOK_ENUM = 287                 /* "enum"  */
  };
