#ifndef SECURE_INPUT_H
#define SECURE_INPUT_H

#if defined(__cplusplus)
extern "C"
{
#endif

void flush_input(void);
char* secure_input(char *const restrict buffer, int const size);

#if defined(__cplusplus)
}
#endif

#endif