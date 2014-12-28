#ifndef SCANNER_H
#define SCANNER_H 

#include <boost/optional.hpp>
#include <boost/variant.hpp>
#include <string>

enum TokenKind {
  TOK_SEMI,
  TOK_COMMA,
  TOK_HOOK,
  TOK_COLON,
  TOK_INC,
  TOK_DEC,
  TOK_DOT,
  TOK_TRIPLEDOT, 
  TOK_LB,
  TOK_RB,
  TOK_LC,
  TOK_RC,
  TOK_LP,
  TOK_RP,
  TOK_NAME,
  TOK_NUMBER,
  TOK_STRING,
  TOK_TEMPLATE_HEAD,
  TOK_NO_SUBS_TEMPLATE,
  TOK_REGEXP,
  TOK_TRUE,
  TOK_FALSE,
  TOK_NULL,
  TOK_THIS,
  TOK_FUNCTION,
  TOK_IF,
  TOK_ELSE,
  TOK_SWITCH,
  TOK_CASE,
  TOK_DEFAULT,
  TOK_WHILE,
  TOK_DO,
  TOK_FOR,
  TOK_BREAK,
  TOK_CONTINUE,
  TOK_VAR,
  TOK_CONST,
  TOK_WITH,
  TOK_RETURN,
  TOK_NEW,
  TOK_DELETE,
  TOK_TRY,
  TOK_CATCH,
  TOK_FINALLY,
  TOK_THROW,
  TOK_DEBUGGER,
  TOK_YIELD,
  TOK_LET,
  TOK_EXPORT,
  TOK_IMPORT,
  TOK_RESERVED,
  TOK_STRICT_RESERVED,
  TOK_OR,
  TOK_AND,
  TOK_BITOR, 
  TOK_BITXOR, 
  TOK_BITAND,
  TOK_STRICTEQ, 
  TOK_EQ,
  TOK_STRICTNE, 
  TOK_LT,
  TOK_LE, 
  TOK_GT,
  TOK_GE, 
  TOK_INSTANCEOF,
  TOK_IN, 
  TOK_LSH,
  TOK_RSH, 
  TOK_URSH,
  TOK_ADD, 
  TOK_SUB,
  TOK_MUL, 
  TOK_DIV,
  TOK_MOD, 
  TOK_TYPEOF,
  TOK_VOID, 
  TOK_NOT,
  TOK_BITNOT, 
  TOK_ARROW,
  TOK_ASSIGN, 
  TOK_ADDASSIGN,
  TOK_SUBASSIGN, 
  TOK_BITORASSIGN,
  TOK_BITXORASSIGN, 
  TOK_BITANDASSIGN,
  TOK_LSHASSIGN, 
  TOK_RSHASSIGN,
  TOK_URSHASSIGN, 
  TOK_MULASSIGN,
  TOK_DIVASSIGN,
  TOK_MODASSIGN,
  TOK_LIMIT                      // domain size
};


template<typename T>
class CircularBuf {
  static const size_t bufSize = 4;
  T items[bufSize];
  int cursor; 
public: 
  
};

struct Pos {
  int begin;
  int end;
};

struct Token {
  TokenKind type;
  Pos pos;
  union {
  private:
    double number;
  } info;
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
/*  90+ */   Ident,  TOK_LB, _______,  TOK_RB, _______,   Ident,   String,   Ident,   Ident,   Ident,
/* 100+ */   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,
/* 110+ */   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,   Ident,
/* 120+ */   Ident,   Ident,   Ident,  TOK_LC, _______,  TOK_RC,TOK_BITNOT, _______
};
#undef _______

struct Decimal {
  int index;
  Decimal(int index_) : index(index_) {}
};


class Scanner {
  std::istream tokStream;

  inline bool isASCIIDecimal(char c) { return (unsigned)c - '0' <= 9; }

public:

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
  boost::optional<boost::variant<Token, Decimal> >
  getToken() {
    for (;;) {
      Token token;
      
      if (tokStream.eof()) {
	return boost::optional<boost::variant<Token, Decimal> >();
      }
      int c = tokStream.get();
      auto initialKind = FirstCharKind(firstCharKinds[c]);
      // Cases:
      // 1. Single character token
      if (initialKind <= OneChar_Max) {
	return boost::optional<boost::variant<Token, Decimal> >(Token());
      }
      // 2. Whitespace
      // 3. Identifier
      for (;;) {
	c = tokStream.get();
	
      }
      // 4. Decimal 
      if (isASCIIDecimal(c)) {
	while (isASCIIDecimal(c)) {
	  c = tokStream.get();
	  if (c == '.') {
	    do {
	      c = tokStream.get();
	    } while (isASCIIDecimal(c));
	  }
	  if (c == 'e' || c == 'E') {
	    c = tokStream.get();
	    if (c == '+' || c == '-') 
	      c = tokStream.get();
	    if (!isASCIIDecimal(c)) {
	      std::cerr << "error: malformed decimal" << std::endl; 
	      return boost::optional<boost::variant<Token, Decimal> >();
	    }
	    do {
	      c = tokStream.get();
	    } while (isASCIIDecimal(c));
	  }
	}
	
      }
      // 5. String or Template String
      // 6. EOL
      // 7. Hex, octal, binary
      // 8. Operators
      switch (c) {
      case '.':
	c = tokStream.get();
	if (isASCIIDecimal(c)) {
	  return boost::optional<boost::variant<Token, Decimal> >(Decimal(tokStream.tellg()));
	}
	if (c == '.' && tokStream.get() == '.') {
	  token.type = TOK_TRIPLEDOT;
	  return boost::optional<boost::variant<Token, Decimal> >(token);
	}
      }
    }
  }
};

#endif /* SCANNER_H */
