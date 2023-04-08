#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <tempbuffers.h>
#include <functions.h>
#include <modes.h>

int KLI_replEnv(bool* running, char* input, size_t inputMaxLength, char** tempBuffers, size_t numTempBuffers)
{
  while(*running)
  {
    printf("KLI>>> ");
    getline(&input, &inputMaxLength, stdin);
    setTempBuffers(tempBuffers, numTempBuffers, input);
    KLI_execute(tempBuffers, input, inputMaxLength, running);   
  }

  return 0;
}

int KLI_scriptEnv(bool* running, char* input, size_t inputMaxLength, char** tempBuffers, size_t numTempBuffers, char* filename)
{
  FILE* file = fopen(filename, "r");

  if(file == NULL)
  {
    printf("That file does not exist!\n");
    return 1;
  }

  while (fgets(input, inputMaxLength, file) && *running)
  {
    setTempBuffers(tempBuffers, numTempBuffers, input);
    KLI_execute(tempBuffers, input, inputMaxLength, running);   
  }

  return 0;
}