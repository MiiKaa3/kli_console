#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <messages.h>

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





void compute(char* input, int inputMaxLength)
{
  char* A = extractNumber(input);
  char* op = input; while(!isOp(++op));
  char* B = extractNumber(op);

  switch(*op)
  {
    case '+': printf("%d", atoi(A) + atoi(B)); break;
    case '-': printf("%d", atoi(A) - atoi(B)); break;
    case '*': printf("%d", atoi(A) * atoi(B)); break;
    case '/': printf("%d", atoi(A) / atoi(B)); break;
    case '^': printf("%0.f", pow((double)atoi(A), (double)atoi(B))); break;
    default: printf("OP ERROR"); 
  }

  putchar('\n');

  free(A);
  free(B);
}

void print(char* input)
{
  char* ptr = input;
  while(*(ptr++) != '"');
  while(*ptr != '"') putchar(*(ptr++));
  putchar('\n');
}

void help(char* input)
{
  char* cmd = extractWord(input + 4);

  if(!strcmp("exit", cmd)) printf(HELP_EXIT_MESSAGE);
  if(!strcmp("help", cmd)) printf(HELP_HELP_MESSAGE);
  if(!strcmp("print", cmd)) printf(HELP_PRINT_MESSAGE);
  if(!strcmp("compute", cmd)) printf(HELP_COMPUTE_MESSAGE);

  free(cmd);
}
