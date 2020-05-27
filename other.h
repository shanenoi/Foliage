#include <string.h>

class function {

    public:
        char * concat(char * a, char * b) {
            if (b != NULL) {
                char * c = (char * ) malloc(strlen(a) + strlen(b) + 1);
                if (c != NULL) {
                    strcpy(c, a);
                    strcat(c, b);
                    return c;
                }
            }
            return a;

        };

        char * process(char * command) {
            FILE * fp;
            char path[1035];
            char * result = strdup("");;

            fp = popen(command, "r");
            if (fp == NULL) {
                return strdup("error");
            }

            while (fgets(path, sizeof(path), fp) != NULL) {
                result = this->concat(result, path);
            }
            pclose(fp);
            return result;
        }

};