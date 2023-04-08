#include <stdlib.h>
#include <helpers.h>

bool isNumeric(char* ptr)
{
  return (*ptr >= '0' && *ptr <= '9');
}

bool isLetter(char* ptr)
{
  return (*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z');
}

bool isOp(char* ptr)
{
  switch(*ptr)
  {
    case '+': return true;
    case '-': return true;
    case '*': return true;
    case '/': return true;
    case '^': return true;
    default: return false; 
  }
}

bool isWhitespace(char* ptr)
{
  switch(*ptr)
  {
    case ' ': return true;
    case '\t': return true;
    case '\n': return true;
    default: return false;
  }
}

char* extractNumber(char* ptr)
{
  while(!isNumeric(++ptr));
  char* end = ptr;
  while(!isWhitespace(++end));
  size_t dist = end - ptr;
  char* num = (char*)calloc(dist + 1, sizeof(char));
  for(int i = 0; i < dist; i++) num[i] = ptr[i];
  num[dist] = '\0';

  return num;
}

char* extractWord(char* ptr)
{
  while(!isLetter(++ptr));
  char* end = ptr;
  while(!isWhitespace(++end));
  size_t dist = end - ptr;
  char* word = (char*)calloc(dist + 1, sizeof(char));
  for(int i = 0; i < dist; i++) word[i] = ptr[i];
  word[dist] = '\0';

  return word;
}
