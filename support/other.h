#include <string.h>
#include <cstdlib>
#include <cstdio>

#ifndef OTHER_FUNCTIONS
#define OTHER_FUNCTIONS

class function {

    public:
        char* concat(char* first_string, char* second_string) {
            if (second_string != NULL) {
                char* result_string = (char*) malloc(
                    strlen(first_string) +
                    strlen(second_string) + 1
                );
                if (result_string != NULL) {
                    strcpy(result_string, first_string);
                    strcat(result_string, second_string);
                    return result_string;
                }
            }
            return first_string;

        };

        char* process(const char* command) {
            FILE * fp;
            char path[1035];
            char* result = strdup("");;

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

        void gen_random(char *s, const int len) {
            static const char alphanum[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";

            for (int i = 0; i < len; ++i) {
                s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
            }

            s[len] = 0;
        }

};

#endif