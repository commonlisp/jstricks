
#include <boost/optional.hpp>
#include <string>

#define FOR_EACH_TOKEN_KIND_WITH_RANGE(macro, range) \
  macro(SEMI,  ";") \
  macro(COMMA, ",") \
  macro(HOOK, "?") \
  macro(COLON, ":") \
  macro(INC, "++") \
  macro(DEC, "--") \
  macro(DOT, ".") \
macro( TRIPLEDOT , "...") \
macro( LB , "[") \
macro( RB , "]") \
macro( LC , "{") \
macro( RC , "}") \
macro( LP , "(") \
macro( RP , ")") \
macro( NAME , "identifier") \
macro( NUMBER , "numeric literal") \
macro( STRING , "string literal") \
macro( TEMPLATE_HEAD , "${") \
macro( NO_SUBS_TEMPLATE , "template literal") \
macro( REGEXP , "regular expression literal") \
macro( TRUE , "boolean literal 'true'") \
macro( FALSE , "boolean literal 'false'") \
macro( NULL , "null literal") \
macro( THIS , "keyword 'this'") \
macro( FUNCTION , "keyword 'function'") \
macro( IF , "keyword 'if'") \
macro( ELSE , "keyword 'else'") \
macro( SWITCH , "keyword 'switch'") \
macro( CASE , "keyword 'case'") \
macro( DEFAULT , "keyword 'default'") \
macro( WHILE , "keyword 'while'") \
macro( DO , "keyword 'do'") \
macro( FOR , "keyword 'for'") \
macro( BREAK , "keyword 'break'") \
macro( CONTINUE , "keyword 'continue'") \
macro( VAR , "keyword 'var'") \
macro( CONST , "keyword 'const'") \
macro( WITH , "keyword 'with'") \
macro( RETURN , "keyword 'return'") \
macro( NEW , "keyword 'new'") \
macro( DELETE , "keyword 'delete'") \
macro( TRY , "keyword 'try'") \
macro( CATCH , "keyword 'catch'") \
macro( FINALLY , "keyword 'finally'") \
macro( THROW , "keyword 'throw'") \
macro( DEBUGGER , "keyword 'debugger'") \
macro( YIELD , "keyword 'yield'") \
macro( LET , "keyword 'let'") \
macro( EXPORT , "keyword 'export'") \
macro( IMPORT , "keyword 'import'") \
macro( RESERVED , "reserved keyword") \
macro( STRICT_RESERVED , "reserved keyword") \

macro( OR , "||") \
macro( AND , "&&") \
macro( BITOR , "|") \
macro( BITXOR , "^") \
macro( BITAND , "&") \
macro( STRICTEQ , "===") \
macro( EQ , "==") \
macro( STRICTNE , "!==") \
macro( LT , "<") \
macro( LE , "<=") \
macro( GT , ">") \
macro( GE , ">=") \

macro( INSTANCEOF , "keyword 'instanceof'") \
macro( IN , "keyword 'in'") \

macro( LSH , "<<") \
macro( RSH , ">>") \
macro( URSH , ">>>") \

macro( ADD, "+") \
macro( SUB , "-") \
macro( MUL , "*") \
macro( DIV , "/") \
macro( MOD , "%") \

macro( TYPEOF , "keyword 'typeof'") \
macro( VOID , "keyword 'void'") \
macro( NOT , "!") \
macro( BITNOT , "~") \
macro( ARROW , "=>") \

macro( ASSIGN , "=") \
macro( ADDASSIGN , "+=") \
macro( SUBASSIGN , "-=") \
macro( BITORASSIGN , "|=") \
macro( BITXORASSIGN , "^=") \
macro( BITANDASSIGN , "&=") \
macro( LSHASSIGN , "<<=") \
macro( RSHASSIGN , ">>=") \
macro( URSHASSIGN , ">>>=") \
macro( MULASSIGN , "*=") \
macro( DIVASSIGN , "/=") \
macro( MODASSIGN , "%=")

enum TokenKind {
#define EMIT_ENUM(name, desc) TOK_##name,
#define EMIT_ENUM_RANGE(name, value) TOK_##name = TOK_##value,
    FOR_EACH_TOKEN_KIND_WITH_RANGE(EMIT_ENUM, EMIT_ENUM_RANGE)
#undef EMIT_ENUM
#undef EMIT_ENUM_RANGE
    TOK_LIMIT                      // domain size
};


template<type T>
class CircularBuf<T> {
  static const size_t bufSize = 4;
  T items[bufSize];
  int cursor; 
public: 
  
};

enum Token {
  
};

class Buf {
  
};

enum FirstCharKind {
    OneChar_Min = 0,
    OneChar_Max = TOK_LIMIT - 1,

    Space = TOK_LIMIT,
    Ident,
    Dec,
    String,
    EOL,
    BasePrefix,
    Other
};

#define _______     Other
static const uint8_t firstCharKinds[] = {
/*         0        1        2        3        4        5        6        7        8        9    */
/*   0+ */ _______, _______, _______, _______, _______, _______, _______, _______, _______,   Space,
/*  10+ */     EOL,   Space,   Space,     EOL, _______, _______, _______, _______, _______, _______,
/*  20+ */ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
/*  30+ */ _______, _______,   Space, _______,  String, _______,   Ident, _______, _______,  String,
/*  40+ */  TOK_LP,  TOK_RP, _______, _______, TOK_COMMA,_______,  _______, _______,BasePrefix,  Dec,
/*  50+ */     Dec,     Dec,     Dec,     Dec,     Dec,     Dec,     Dec,    Dec,  TOK_COLON,TOK_SEMI,
/*  60+ */ _______, _______, _______,TOK_HOOK, _______,   Ident,   Ident,   Ident,   Ident,   Ident,
/*  70+ */   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,
/*  80+ */   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,
/*  90+ */   Ident,  TOK_LB, _______,  TOK_RB, _______,   Ident, Templat,   Ident,   Ident,   Ident,
/* 100+ */   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,
/* 110+ */   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,
/* 120+ */   Ident,   Ident,   Ident,  TOK_LC, _______,  TOK_RC,T_BITNOT, _______
};
#undef _______


class Scanner {
  std::istream tokStream;
public:
  Scanner(std::istream _tokStream) : tokStream(_tokStream) { }

  /*
    Spidermonkey's tokenize function has the following control flow structure:

    retry:
    switch (c) {
      case ...:
        goto badchar
      badchar:
      default:
    }
    out:
    error:
   */
  boost::optional<Token> getToken() {
    for (;;) {
      if (tokStream.eof()) {
	return boost::optional<Token>();
      }
      int c = tokStream.get();
      // Cases:
      // 1. Single character token
      // 2. Whitespace
      // 3. Identifier
      // 4. Decimal 
      // 5. String or Template String
      // 6. EOL
      // 7. Hex, octal, binary
      // 8. Operators 
    }
};

