#include <iostream>
#include "other.h"
#include <unistd.h>

class object {

    public:
        char * permissions;
        char * type;
        char * location;
        time_t modified;
        time_t accessed;
        time_t status;
        char * open(char * arg) {};
        char * delete(int arg) {
            /*
                0: can restore
                1: can not restore
            */
        };
        int * create_archive() {};
        int * rename(char * new_one) {};
}