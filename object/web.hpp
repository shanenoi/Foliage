#ifndef __WEB__
#define __WEB__

#include <stdio.h>

void* web_open(char* path, char** start, char** end) {
	// this function will interac with file
	printf("open %s\n", path);
	return NULL;
}

#endif /*__WEB__*/