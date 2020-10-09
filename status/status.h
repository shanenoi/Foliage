#include <sysexits.h>

#ifndef __STATUS__
#define __STATUS__

typedef struct {
	int code;
	const char* message;
} status_return;

#endif /*__STATUS__*/