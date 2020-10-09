#ifndef __PATH_Object__
#define __PATH_Object__

#include <sys/stat.h>
#include <string.h>
#include "file.hpp"
#include "../support/other.hpp"


typedef struct stat _stat;

class Object {

    private:
        _stat st;
        Function* func;


    public:

        meta_path path;
        char* __full;
        time_t modified;
        time_t accessed;
        time_t status;
        size_t size;
        char* permissions;
        enum TYPES type_content;
        status_return present_status = {.code=EX_OK, .message=NULL};
        void* (*open)(char* /*path*/, char** /*start*/, char** /*end*/);
        Object(meta_path path):path(path){};
        void load_details();

};


void Object::load_details() {

    Object::__full = strcat( strcat(strdup(Object::path.path), strdup("/")),
                             strdup(Object::path.name));
    
    int stat_status = stat(Object::__full, &(Object::st));

    Object::modified = Object::st.st_mtime;
    Object::accessed = Object::st.st_atime;
    Object::status   = Object::st.st_ctime;
    Object::size     = Object::st.st_size;

    if (stat_status == 0) {
        //Object::permissions = (char* ) malloc(sizeof(char) * 9 + 1);
        mode_t perm = Object::st.st_mode;
        const char permissions[] = {
                (perm & S_IRUSR) ? 'r' : '-', (perm & S_IWUSR) ? 'w' : '-',
                (perm & S_IXUSR) ? 'x' : '-', (perm & S_IRGRP) ? 'r' : '-',
                (perm & S_IWGRP) ? 'w' : '-', (perm & S_IXGRP) ? 'x' : '-',
                (perm & S_IROTH) ? 'r' : '-', (perm & S_IWOTH) ? 'w' : '-',
                (perm & S_IXOTH) ? 'x' : '-', '\0',};
        Object::permissions = strdup(permissions);
    }

    DETECTER->file = Object::path.path;
    Object::type_content = DETECTER->astype();


};

#endif
