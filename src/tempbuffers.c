#include <stdio.h>
#include <string.h>
#include <tempbuffers.h>

void initTempBuffers(char** buffers, size_t numBuffers)
{
  for(size_t i = 0; i < numBuffers; i++)
  {
    char* ptr = (char*)calloc(i, sizeof(char));
    buffers[i] = ptr;
  } 
}

void freeTempBuffers(char** buffers, size_t numBuffers)
{
  for(size_t i = 0; i < numBuffers; i++) free(buffers[i]);
}

void setTempBuffers(char** buffers, size_t numBuffers, char* in)
{
  for(size_t i = 0; i < numBuffers; i++)
  {
    char* ptr = buffers[i];
    strncpy(ptr, in, i);
    ptr[i + 1] = '\0';
  }
}

void DEBUG_printTempBuffers(char** buffers, size_t numBuffers)
{
  for(size_t i = 0; i < numBuffers; i++)
  {
    char* ptr = buffers[i];
    printf("buffer%d: %s\n", (int)i, ptr);
  }
}

void DEBUG_printTempBuffer(char** buffers, size_t buffer)
{
    char* ptr = buffers[buffer];
    printf("buffer%d: %s\n", (int)buffer, ptr);
}