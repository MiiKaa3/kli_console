#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <tempbuffers.h>
#include <functions.h>
#include <repl.h>

int main(int argc, char** argv)
{
  int returnCode;

  if(argc == 1)
    returnCode = KLI_replEvironment();

  return returnCode;
}