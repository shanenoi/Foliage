#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../support/other.h"

#ifndef PATH_OBJECT
#define PATH_OBJECT

class path {

    private:
        struct stat st;
        function * func;


    public:
        char* link;

        path(const char* link) {
            this->link = strdup(link);
            stat(this->link, & this->st);
        }

        int size() {
            stat(this->link, & this->st);
            return this->st.st_size;
        }

        char* permissions() {
            char* modeval = (char* ) malloc(sizeof(char) * 9 + 1);
            if (stat(this->link, & this->st) == 0) {
                mode_t perm = this->st.st_mode;
                modeval[0] = (perm & S_IRUSR) ? 'r' : '-';
                modeval[1] = (perm & S_IWUSR) ? 'w' : '-';
                modeval[2] = (perm & S_IXUSR) ? 'x' : '-';
                modeval[3] = (perm & S_IRGRP) ? 'r' : '-';
                modeval[4] = (perm & S_IWGRP) ? 'w' : '-';
                modeval[5] = (perm & S_IXGRP) ? 'x' : '-';
                modeval[6] = (perm & S_IROTH) ? 'r' : '-';
                modeval[7] = (perm & S_IWOTH) ? 'w' : '-';
                modeval[8] = (perm & S_IXOTH) ? 'x' : '-';
                modeval[9] = '\0';
                return modeval;
            } else {
                return NULL;
            }
        }

        char* type() {
            return this->func->process(
                this->func->concat(
                    strdup("file "),
                    this->link
                )
            );
        }

        time_t modified() {
            return this->st.st_mtime;
        }

        time_t accessed() {
            return this->st.st_atime;
        }

        time_t status() {
            return this->st.st_ctime;
        }

};

#endif