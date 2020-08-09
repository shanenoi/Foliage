#ifndef __AUDIO__
#define __AUDIO__

#include <stdio.h>

void* audio_open(char* path, char** start, char** end) {
	// this function will interac with file
	printf("open %s\n", path);
	return NULL;
}

#endif /*__AUDIO__*/