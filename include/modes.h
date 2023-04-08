#include <stdlib.h>
#include <stdbool.h>

int KLI_replEnv(bool* running, char* input, size_t inputMaxLength, char** tempBuffers, size_t numTempBuffers);
int KLI_scriptEnv(bool* running, char* input, size_t inputMaxLength, char** tempBuffers, size_t numTempBuffers, char* filename);
