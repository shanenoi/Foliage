#include <sysexits.h>

#ifndef STATUS
#define STATUS

typedef struct {
	int code;
	const char* message;
} status_return;

#endif