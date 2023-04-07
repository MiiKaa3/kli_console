#include <stdbool.h>

bool isNumeric(char* ptr);
bool isLetter(char* ptr);
bool isOp(char* ptr);
bool isWhitespace(char* ptr);

char* extractNumber(char* ptr);
char* extractWord(char* ptr);