#include <stdbool.h>

void KLI_compute(char* input, int inputMaxLength);
void KLI_print(char* input);
void KLI_help(char* input);
void KLI_exit(bool* running);
void KLI_execute(char** tempBuffers, char* input, int inputMaxLength, bool* running);