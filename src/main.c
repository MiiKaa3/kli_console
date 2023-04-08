#include <stdbool.h>
#include <tempbuffers.h>
#include <modes.h>

int main(int argc, char** argv)
{
  bool running = true;
  int returnCode = 0;
  
  size_t inputMaxLength = 120;
  char* input = (char*)calloc(inputMaxLength, sizeof(char));
  
  size_t numTempBuffers = 10;
  char** tempBuffers = (char**)calloc(numTempBuffers, sizeof(char*));
  initTempBuffers(tempBuffers, numTempBuffers);

  if(argc == 1)
    returnCode = KLI_replEnv(&running, input, inputMaxLength, tempBuffers, numTempBuffers);
  if(argc == 2)
    returnCode = KLI_scriptEnv(&running, input, inputMaxLength, tempBuffers, numTempBuffers, argv[1]);

  freeTempBuffers(tempBuffers, numTempBuffers);
  free(tempBuffers);
  free(input);  

  return returnCode;
}