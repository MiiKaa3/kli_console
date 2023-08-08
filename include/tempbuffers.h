#include <stdlib.h>

void initTempBuffers(char** buffers, size_t numBuffers);
void freeTempBuffers(char** buffers, size_t numBuffers);
void setTempBuffers(char** buffers, size_t numBuffers, char* in);

void DEBUG_printTempBuffers(char** buffers, size_t numBuffers);
void DEBUG_printTempBuffer(char** buffers, size_t buffer);