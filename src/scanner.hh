
#include <boost/optional.hpp>
#include <string>

using namespace std;

const string SEMI = ";";
const string COMMA = ",";
const string HOOK = "?";
const string COLON = ":";
const string INC = "++";
const string DEC = "--";
const string DOT = ".";
const string TRIPLEDOT = "...";
const string LB = "[";
const string RB = "]";
const string LC = "{";
const string RC = "}";
const string LP = "(";
const string RP = ")";
const string NAME = "identifier";
const string NUMBER = "numeric literal";
const string STRING = "string literal";
const string TEMPLATE_HEAD = "${";
const string NO_SUBS_TEMPLATE = "template literal";
const string REGEXP = "regular expression literal";
const string TRUE = "boolean literal 'true'";
const string FALSE = "boolean literal 'false'";
const string NULL = "null literal";
const string THIS = "keyword 'this'";
const string FUNCTION = "keyword 'function'";
const string IF = "keyword 'if'";
const string ELSE = "keyword 'else'";
const string SWITCH = "keyword 'switch'";
const string CASE = "keyword 'case'";
const string DEFAULT = "keyword 'default'";
const string WHILE = "keyword 'while'";
const string DO = "keyword 'do'";
const string FOR = "keyword 'for'";
const string BREAK = "keyword 'break'";
const string CONTINUE = "keyword 'continue'";
const string VAR = "keyword 'var'";
const string CONST = "keyword 'const'";
const string WITH = "keyword 'with'";
const string RETURN = "keyword 'return'";
const string NEW = "keyword 'new'";
const string DELETE = "keyword 'delete'";
const string TRY = "keyword 'try'";
const string CATCH = "keyword 'catch'";
const string FINALLY = "keyword 'finally'";
const string THROW = "keyword 'throw'";
const string DEBUGGER = "keyword 'debugger'";
const string YIELD = "keyword 'yield'";
const string LET = "keyword 'let'";
const string EXPORT = "keyword 'export'";
const string IMPORT = "keyword 'import'";
const string RESERVED = "reserved keyword";
const string STRICT_RESERVED = "reserved keyword";

const string OR = "||";
const string AND = "&&";
const string BITOR = "|";
const string BITXOR = "^";
const string BITAND = "&";
const string STRICTEQ = "===";
const string EQ = "==";
const string STRICTNE = "!==";
const string LT = "<";
const string LE = "<=";
const string GT = ">";
const string GE = ">=";

const string INSTANCEOF = "keyword 'instanceof'";
const string IN = "keyword 'in'";

const string LSH = "<<";
const string RSH = ">>";
const string URSH = ">>>";

const string ADD = "+";
const string SUB = "-";
const string MUL = "*";
const string DIV = "/";
const string MOD = "%";

const string TYPEOF = "keyword 'typeof'";
const string VOID = "keyword 'void'";
const string NOT = "!";
const string BITNOT = "~";
const string ARROW = "=>";

const string ASSIGN = "=";
const string ADDASSIGN = "+=";
const string SUBASSIGN = "-=";
const string BITORASSIGN = "|=";
const string BITXORASSIGN = "^=";
const string BITANDASSIGN = "&=";
const string LSHASSIGN = "<<=";
const string RSHASSIGN = ">>=";
const string URSHASSIGN = ">>>=";
const string MULASSIGN = "*=";
const string DIVASSIGN = "/=";
const string MODASSIGN = "%=";

template<type T>
class CircularBuf<T> {
  static const size_t bufSize = 4;
  T items[bufSize];
};

enum Token {
  
};

class Scanner {
  boost::optional<Token> getToken();
};

