#include <string.h>

class function {

    public:
        char * concat(char * first_string, char * second_string) {
            if (second_string != NULL) {
                char * result_string = (char*) malloc(
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

        char * join(char * item, char * array) {
            return strdup;
        }

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