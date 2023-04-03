#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <tempbuffers.h>
#include <clifunctions.h>

int main()
{
  bool running = true;
  
  size_t inputMaxLength = 120;
  char* input = (char*)calloc(inputMaxLength, sizeof(char));
  
  size_t numTempBuffers = 10;
  char** tempBuffers = (char**)calloc(numTempBuffers, sizeof(char*));
  initTempBuffers(tempBuffers, numTempBuffers);

  while(running)
  {
    printf("KLI>>> ");
    getline(&input, &inputMaxLength, stdin);
    setTempBuffers(tempBuffers, numTempBuffers, input);
    
    if(!strcmp("exit", tempBuffers[4])) running = false;
    if(!strcmp("help", tempBuffers[4])) help(input);
    if(!strcmp("print", tempBuffers[5])) print(input);
    if(!strcmp("compute", tempBuffers[7])) compute(input, inputMaxLength);
  }

  freeTempBuffers(tempBuffers, numTempBuffers);
  free(tempBuffers);
  free(input);  

  return 0;
}