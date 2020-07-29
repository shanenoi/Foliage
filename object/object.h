#include "path.h"

#ifndef OBJECT_FILE
#define OBJECT_FILE

class object {

    public:
        path path_file = NULL;

        object(const char* _path);

        int open(char * arg);
        int delt(int arg)// {
            /*
                0: can restore
                1: can not restore
            */
        //}
        ;
        int create_archive();
        int rename(char * new_one);
};

object::object(const char* _path){
            object::path_file = path(strdup(_path));
}

#endif