#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

class path {
    private:
        struct stat st;

        char* concat(char* a, char* b) {
            if ( b != NULL ) {
                char *c = (char*)malloc(strlen(a) + strlen(b) + 1);
                if ( c != NULL ) {
                    strcpy(c, a);
                    strcat(c, b);
                    return c;
                }
            }
            return a;
        
        }

        char* process(char* command) {
            FILE* fp;
            char path[1035];
            char* result = strdup("");;

            fp = popen(command, "r");
            if (fp == NULL) {
                printf("Failed to run command\n" );
                return result;
            }

            while (fgets(path, sizeof(path), fp) != NULL) {
                result = concat(result, path);
            }
            pclose(fp);
            return result;
        }

    public:
        char* link;
        int size() {
            stat(this->link, &this->st);
            return this->st.st_size;
        }
        char* permissions() {
            char* modeval = (char*)malloc(sizeof(char) * 9 + 1);
            if(stat(this->link, &this->st) == 0){
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
            }
            else{
                return NULL;
            }
        }

        char* type() {
            return this->process(
                this->concat(
                    strdup("file "),
                    this->link
                )
            );
        }

        time_t modified() {
            stat(this->link, &this->st);
            return this->st.st_mtime;
        }

        time_t accessed() {
            stat(this->link, &this->st);
            return this->st.st_atime;
        }

        time_t status() {
            stat(this->link, &this->st);
            return this->st.st_ctime;
        }

};