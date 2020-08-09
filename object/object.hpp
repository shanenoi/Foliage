#ifndef __PATH_OBJECT__
#define __PATH_OBJECT__

#include <sys/stat.h>
#include <string.h>
#include "file.hpp"
#include "../support/other.hpp"


typedef struct stat _stat;

class object {

    private:
        _stat st;
        function* func;


    public:

        meta_path path;
        char* __full;
        time_t modified;
        time_t accessed;
        time_t status;
        size_t size;
        char* permissions;
        char* type_content;
        status_return present_status = {.code=EX_OK, .message=NULL};
        void* (*open)(char* /*path*/, char** /*start*/, char** /*end*/);
        object(meta_path);

};


object::object(meta_path path):path(path) {

    object::__full = strdup(path.path);
    object::__full = strcat(strcat(object::__full, "/"), path.name);
    
    int stat_status = stat(object::__full, &(object::st));

    object::modified = object::st.st_mtime;
    object::accessed = object::st.st_atime;
    object::status = object::st.st_ctime;
    object::size = object::st.st_size;

    if (stat_status == 0) {
        //object::permissions = (char* ) malloc(sizeof(char) * 9 + 1);
        mode_t perm = object::st.st_mode;
        const char permissions[] = {(perm & S_IRUSR) ? 'r' : '-', (perm & S_IWUSR) ? 'w' : '-', (perm & S_IXUSR) ? 'x' : '-',
                                    (perm & S_IRGRP) ? 'r' : '-', (perm & S_IWGRP) ? 'w' : '-', (perm & S_IXGRP) ? 'x' : '-',
                                    (perm & S_IROTH) ? 'r' : '-', (perm & S_IWOTH) ? 'w' : '-', (perm & S_IXOTH) ? 'x' : '-',
                                    '\0',};
        object::permissions = strdup(permissions);
    }

    char* file_command = strdup("file ");
    object::type_content = strdup(object::func->process(strcat(file_command, object::__full)).message);

};

#endif