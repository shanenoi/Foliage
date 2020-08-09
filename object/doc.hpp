#ifndef __DOC__
#define __DOC__

#include <stdio.h>

void* doc_open(char* path, char** start, char** end) {
	// this function will interac with file
	printf("open %s\n", path);
	return NULL;
}

#endif /*__DOC__*/