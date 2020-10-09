#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "../status/status.h"

#ifndef OTHER_FUNCTIONS
#define OTHER_FUNCTIONS 

class Function {

    public:

        /* I FORGOT STRCAT CAN RETURN VALUE 😂 */
        // char* concat(char* first_string, char* second_string) {
        //     if (second_string != NULL) {
        //         char* result_string = (char*) malloc(
        //             strlen(first_string) +
        //             strlen(second_string) + 1
        //         );
        //         if (result_string != NULL) {
        //             strcpy(result_string, first_string);
        //             strcat(result_string, second_string);
        //             return result_string;
        //         }
        //     }
        //     return first_string;
        // };

        status_return process(char* command) {

            /* BECAUSE THESE LINES CAN EXECUTE SOME CODE*/
            // FILE * fp;
            // char path[1035];
            // char* _result = strdup("");
            // status_return result;

            // fp = popen(command, "r");
            // if (fp == NULL) {
            //     result = {
            //         .code = EX_USAGE,
            //         .message = "command not found",
            //     };
            //     return result;
            // }
            // while (fgets(path, sizeof(path), fp) != NULL) {
            //     _result = strcat(_result, path);
            // }
            // result = {
            //     .code = WEXITSTATUS(pclose(fp)),
            //     .message = _result,
            // };
            // return result;

            /* BECAUSE OF SOME FUCKING STUCK, I HAVE TO USE BOTH FUCKING_STRING AND RAW STRING 🤦
                    I NEED YOUR HELP
            */
            char* fucking_string = strdup(".temp_file3264111");
            status_return result;
            int code = system(strcat(strcat(command, ">"), fucking_string));
            int chr, index=0;
            FILE *file = fopen(".temp_file3264111", "r");
            fseek(file, 0, SEEK_END);
            char* temp_string = (char*)malloc(ftell(file)*sizeof(char));
            fseek(file, 0, SEEK_SET);
            if (file) {
                while ((chr = getc(file)) != EOF)
                    *(temp_string+index++) = chr;
                fclose(file);
            }
            result = {.code = code, .message = temp_string};
            system("rm .temp_file3264111");
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