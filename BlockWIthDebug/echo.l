%{
#include <stdio.h>
#include <string.h>
#include <map> // Include map header for C++
#include <string>
std::map<std::string, std::string> varMap;
int varCount = 0;
int smtCount = 0;
int functionCount = 0;
int arrCount = 0;
%}


%option noyywrap
%x IN_FUNCTION

%%

import[ \t]+([a-zA-Z0-9_\/\.\-]+) { printf("Package import detected %s\n", yytext); }
"//"[^"\n"]*               { printf("Single-line comment detected: %s\n", yytext); }
"<<"[^">"]*">>"            { printf("Multi-line comment detected: %s\n", yytext); }
print\(`([^`$]+|\$[a-zA-Z_][a-zA-Z_0-9]*)*`\); { printf("Output Statement Detected %s\n", yytext); smtCount++; }

([a-zA-Z_][a-zA-Z_0-9]*)[ \t]*=>>[ \t]*\(\"([^"]*)\"\); { printf("Input Statement detected: %s\n", yytext); smtCount++; }

var[ \t]+([a-zA-Z_][a-zA-Z_0-9]*)[ \t]*:[ \t]*(int|float|char|double|string)[ \t]*=[ \t]*[0-9]+; {
  printf("Complex variable declaration detected: %s\n", yytext);
  
  smtCount++;
  char* start = yytext + 3; 
  char* colon = strchr(start, ':');
  char* equal = strchr(start, '=');

  if (colon && equal) {
    std::string varNameStr(start, colon - start);
    std::string varTypeStr(colon + 1, equal - colon - 1);

    // Trim whitespaces from both the variable name and the type
    varNameStr.erase(0, varNameStr.find_first_not_of(" \t"));
    varNameStr.erase(varNameStr.find_last_not_of(" \t") + 1);

    varTypeStr.erase(0, varTypeStr.find_first_not_of(" \t"));
    varTypeStr.erase(varTypeStr.find_last_not_of(" \t") + 1);

    if (varMap.find(varNameStr) != varMap.end()) {
      printf("Variable collision detected for variable: %s\n", varNameStr.c_str());
    } else {
      varMap[varNameStr] = varTypeStr;
      varCount++;
    }
  }
}

var[ \t]+([a-zA-Z_][a-zA-Z_0-9]*)[ \t]*:[ \t]*(int|float|char|double|string)([ \t]*=[ \t]*[0-9]+)?(,[ \t]*[a-zA-Z_]+[ \t]*:[ \t]*(int|float|char|double)([ \t]*=[ \t]*[0-9]+)?)*; {
  printf("Complex multiple variable declaration detected: %s\n", yytext);
  
  smtCount++;
  char* start = yytext + 3; // Skip 'var'
  char* ptr = start;
  char* end = yytext + yyleng;
  
  while (ptr < end) {
    char* colon = strchr(ptr, ':');
    char* comma_or_semicolon = strpbrk(ptr, ",;");
    
    if (colon && comma_or_semicolon) {
      std::string varNameStr(ptr, colon - ptr);  // Extract from ptr to ':'
      std::string varTypeStr(colon + 1, comma_or_semicolon - colon - 1);  // Extract from ':' to ',' or ';'
      
      // Trim whitespaces from both ends of variable name and type
      varNameStr.erase(0, varNameStr.find_first_not_of(" \t"));
      varNameStr.erase(varNameStr.find_last_not_of(" \t") + 1);
      
      varTypeStr.erase(0, varTypeStr.find_first_not_of(" \t"));
      varTypeStr.erase(varTypeStr.find_last_not_of(" \t") + 1);
      
      if (varMap.find(varNameStr) != varMap.end()) {
        printf("Variable collision detected for variable: %s\n", varNameStr.c_str());
      } else {
        varMap[varNameStr] = varTypeStr;
        varCount++;
      }
      
      ptr = comma_or_semicolon + 1;  // Move to the character after ',' or ';'
    } else {
      break; // Invalid format or end of line
    }
  }
}


var[ \t]+([a-zA-Z_][a-zA-Z_0-9]*)[ \t]*; {
  printf("Variable declaration without assignment detected: %s\n", yytext);
  
  smtCount++;
  char* start = yytext + 3; // Skip 'var'
  char* end = yytext + yyleng - 1; // Point to the last valid character, which is before ';'
  
  std::string varNameStr(start, end - start); // Extract the variable name
  
  // Trim whitespaces from both ends of variable name
  varNameStr.erase(0, varNameStr.find_first_not_of(" \t"));
  varNameStr.erase(varNameStr.find_last_not_of(" \t") + 1);
  
  if (varMap.find(varNameStr) != varMap.end()) {
    printf("Variable collision detected for variable: %s\n", varNameStr.c_str());
  } else {
    // Set to some default type, or use an empty string to indicate an unknown type
    varMap[varNameStr] = "";
    varCount++; 
  }
}

var[ \t]+([a-zA-Z_][a-zA-Z_0-9]*)[ \t]*=[ \t]*[0-9]+; {
  printf("Variable declaration with assignment detected: %s\n", yytext);
  
  smtCount++;
  char* start = yytext + 3; // Skip 'var'
  char* equal = strchr(start, '='); // Point to the position of '='
  
  if (equal) {
    std::string varNameStr(start, equal - start); // Extract from start to '='
    
    // Trim whitespaces from both ends of variable name
    varNameStr.erase(0, varNameStr.find_first_not_of(" \t"));
    varNameStr.erase(varNameStr.find_last_not_of(" \t") + 1);
    
    if (varMap.find(varNameStr) != varMap.end()) {
      printf("Variable collision detected for variable: %s\n", varNameStr.c_str());
    } else {
      // Use a default type or an empty string to indicate that the type is unknown
      varMap[varNameStr] = ""; 
      varCount++;
    }
  }
}

[a-zA-Z_][a-zA-Z_0-9]*[ \t]*=[ \t]*[0-9]+; {
  printf("Variable assignment detected: %s\n", yytext);
  
  smtCount++;
  char* start = yytext;
  char* equal = strchr(start, '='); // Point to the position of '='
  
  if (equal) {
    std::string varNameStr(start, equal - start); // Extract from start to '='
    
    // Trim whitespaces from both ends of variable name
    varNameStr.erase(0, varNameStr.find_first_not_of(" \t"));
    varNameStr.erase(varNameStr.find_last_not_of(" \t") + 1);
    
    if (varMap.find(varNameStr) == varMap.end()) {
      printf("Cannot match anything with the variable name: %s\n", varNameStr.c_str());
    } else {
      printf("Variable %s has been previously declared %s.\n", varNameStr.c_str(), varMap[varNameStr].c_str());
    }
  }
}

var[ \t]+([a-zA-Z_][a-zA-Z_0-9]*)[ \t]*:[ \t]*(int|float|char|double|string)\[[0-9]+\](\s*=\s*\{([0-9]+(\.[0-9]+)?,?\s*)*\})?; {
  printf("Array declared %s\n", yytext);
  arrCount++;
  smtCount++;
}

"return"[ \t]+([a-zA-Z_][a-zA-Z_0-9]*)\; { printf("Return Statement Detected: %s\n", yytext); smtCount++; }
"function"[ \t]+[a-zA-Z_][a-zA-Z_0-9]*[ \t]*":"[ \t]*("int"|"float"|"char"|"double"|"string")[ \t]*"("[a-zA-Z_][a-zA-Z_0-9]*[ \t]*":"[ \t]*("int"|"float"|"char"|"double"|"string")([ \t]*","[ \t]*[a-zA-Z_][a-zA-Z_0-9]*[ \t]*":"[ \t]*("int"|"float"|"char"|"double"|"string"))*[ \t]*")"[ \t]*("{"[^@]*"}")@  { printf("Entire function declaration and body detected: %s\n", yytext); functionCount++;}
"function"[ \t]+[a-zA-Z_][a-zA-Z_0-9]*[ \t]*":"[ \t]*("int"|"float"|"char"|"double"|"string")[ \t]*"("[ \t]*[a-zA-Z_][a-zA-Z_0-9]*[ \t]*":"[ \t]*("int"|"float"|"char"|"double"|"string")([ \t]*"="[ \t]*[a-zA-Z_0-9]+)?([ \t]*","[ \t]*[a-zA-Z_][a-zA-Z_0-9]*[ \t]*":"[ \t]*("int"|"float"|"char"|"double"|"string")([ \t]*"="[ \t]*[a-zA-Z_0-9]+)?)?[ \t]*")"[ \t]*"{@"[^@]*"@}" {
  printf("Entire function declaration with optional default values and body detected: %s\n", yytext);
  functionCount++;
  BEGIN(IN_FUNCTION);
}

<IN_FUNCTION>"//".*\n {
  printf("Comment detected inside function: %s\n", yytext);
}

<IN_FUNCTION>"@}" {
  printf("End of function detected: %s\n", yytext);
  BEGIN(INITIAL);
}

"if"[ \t]*"("[^)]*")"[ \t]*"{"[^}]*"}" { printf("If block detected: %s\n", yytext); }
"else"[ \t]*"if"[ \t]*"("[^)]*")"[ \t]*"{"[^}]*"}"[ \t]*"else"[ \t]*"{"[^}]*"}" { printf("else-if-else block detected: %s\n", yytext); }
"else"[ \t]*"if"[ \t]*"("[^)]*")"[ \t]*"{"[^}]*"}" { printf("else-if block detected: %s\n", yytext); }
"if"[ \t]*"("[^)]*")"[ \t]*"{"[^}]*"}"[ \t]*("else"[ \t]*"{"[^}]*"}")? { printf("If-else block detected: %s\n", yytext); }
"for"[ \t]*"\("[ \t]*("int"|"float"|"char"|"double"|"string")[ \t]+[a-zA-Z_][a-zA-Z_0-9]*[ \t]*"="[ \t]*[0-9]+[ \t]*";"[ \t]*[a-zA-Z_][a-zA-Z_0-9]*[ \t]*("<"|"<="|">"|">="|"=="|"!=")[ \t]*[0-9]+[ \t]*";"[ \t]*[a-zA-Z_][a-zA-Z_0-9]*[ \t]*"="[ \t]*[a-zA-Z_][a-zA-Z_0-9]*[ \t]*("+"|"-"|"*"|"/")[ \t]*[0-9]+[ \t]*"\)"[ \t]*("{"[^@]*"}")@ { printf("For loop detected: %s\n", yytext); }
"for"[ \t]*"\("[ \t]*("int"|"float"|"char"|"double"|"string")[ \t]+[a-zA-Z_][a-zA-Z_0-9]*[ \t]*"="[ \t]*[0-9]+[ \t]*";"[ \t]*[a-zA-Z_][a-zA-Z_0-9]*[ \t]*("<"|"<="|">"|">="|"=="|"!=")[ \t]*[0-9]+[ \t]*";\)"[ \t]*("{"[^@]*"}")@ { printf("For loop detected without incrementing: %s\n", yytext); }
"for"[ \t]*"\("[ \t]*("int"|"float"|"char"|"double"|"string")[ \t]+[a-zA-Z_][a-zA-Z_0-9]*[ \t]*"="[ \t]*[0-9]+[ \t]*";;\)"[ \t]*("{"[^@]*"}")@ { printf("For loop detected without condition and incrementing: %s\n", yytext); }
"While"[ \t]+<[^>]+>[ \t]*\{[ \n]*[ \t]*("pre"[ \t]*"\{"[^\}]*"\}")?[ \n]*("body"[ \t]*"\{"[^\}]*"\}")?[ \n]*("post"[ \t]*"\{"[^\}]*"\}")?[ \n]*("always"[ \t]*"\{"[^\}]*"\}")?[ \n]*[ \n]*\}@ { printf("While loop detected %s\n", yytext); }



[a-zA-Z_][a-zA-Z_0-9]*    { printf("Identifier detected: %s\n", yytext); }
":"                       { printf("Type separator detected: %s\n", yytext); }
"="                       { printf("Assignment operator detected: %s\n", yytext); }
[0-9]+                    { printf("Integer literal detected: %s\n", yytext); }
[0-9]+"."[0-9]+           { printf("Floating-point literal detected: %s\n", yytext); }
"\"[^\"]*\""              { printf("String literal detected: %s\n", yytext); }
"\'[^\']*\'"              { printf("Character literal detected: %s\n", yytext); }
";"                       { printf("Statement end detected: %s\n", yytext); }
"+"|"-"|"*"|"/"|"%"       { printf("Arithmetic operator detected: %s\n", yytext); }
"<"|"<="|">"|">="|"=="|"!=" { printf("Relational operator detected: %s\n", yytext); }
"&&"|"||"|"!"             { printf("Logical operator detected: %s\n", yytext); }
"("|")"                   { printf("Round parenthesis detected: %s\n", yytext); }
"{"|"}"                   { printf("Curly braces detected: %s\n", yytext); }
"["|"]"                   { printf("Square parenthesis detected: %s\n", yytext); }


\n { printf("\n"); }
.                         { printf("Unrecognized character: %s\n", yytext); }

%%

int main() {
  yylex();
  printf("Total number of variables declared: %d\n", varCount);
  printf("Total number of Statements announced: %d\n", smtCount);
  printf("Total number of Functions Declared: %d\n", functionCount);
  printf("Total number of Array declared %d\n", arrCount);
  return 0;
}
