#include "scanner.hh"
#include <cctype>

using namespace std;

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
Scanner::getToken() {
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
      if (isspace(tokStream.get())) continue;
      
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
      if (initialKind == String) {
	
      }
      // 6. EOL
      // 7. Hex, octal, binary
      if (initialKind == BasePrefix) {
	c = tokStream.get();
	if (c == 'x' || c == 'X') {

	} else if (c == 'b' || c == 'B') {

	} else if (c == 'o' || c == 'O') {

	} else if (isASCIIDecimal(c)) {

	} else {
	}
      }
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
      case '=':
	c = tokStream.get();
	if (c == '=') {
	  if (tokStream.get() == '=') token.type = TOK_STRICTEQ;
	  else token.type = TOK_EQ;
	} else if (c == '>') {
	  token.type = TOK_ARROW;
	} else {
	  token.type = TOK_ASSIGN;
	}
	return boost::optional<boost::variant<Token, Decimal> >(token);
      }
    }
}
