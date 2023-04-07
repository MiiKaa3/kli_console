#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <functions.h>
#include <helpers.h>
#include <messages.h>

void KLI_compute(char* input, int inputMaxLength)
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

void KLI_print(char* input)
{
  char* ptr = input;
  while(*(ptr++) != '"');
  while(*ptr != '"') putchar(*(ptr++));
  putchar('\n');
}

void KLI_help(char* input)
{
  char* cmd = extractWord(input + 4);

  if(!strcmp("exit", cmd)) printf(HELP_EXIT_MESSAGE);
  if(!strcmp("help", cmd)) printf(HELP_HELP_MESSAGE);
  if(!strcmp("print", cmd)) printf(HELP_PRINT_MESSAGE);
  if(!strcmp("compute", cmd)) printf(HELP_COMPUTE_MESSAGE);

  free(cmd);
}

void KLI_exit(bool* running)
{
  *running = false;
}