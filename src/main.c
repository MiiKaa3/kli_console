#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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
    
    if(!strcmp("exit", tempBuffers[4])) KLI_exit(&running);
    else if(!strcmp("help", tempBuffers[4])) KLI_help(input);
    else if(!strcmp("print", tempBuffers[5])) KLI_print(input);
    else if(!strcmp("compute", tempBuffers[7])) KLI_compute(input, inputMaxLength);
  }

  freeTempBuffers(tempBuffers, numTempBuffers);
  free(tempBuffers);
  free(input);  

  return 0;
}