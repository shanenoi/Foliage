#include <string.h>
#include <cstdlib>
#include <cstdio>

#ifndef ARCHIVEAPP
#define ARCHIVEAPP


class archive_format {

    public:
        const char* app_name;
        const char* options;
        const char* input_files;
        const char* output_file;
        char* temporary_var;

        ~archive_format() {
            free(this->temporary_var);
        };

        int check_available() {
            return system(this->app_name);
        };

        int compress();

        int extract();
};


class zip: public archive_format {

    public:

        int compress() {
            this->app_name = "zip";
            this->options = "-r";

            this->temporary_var = (char*)malloc(
                strlen(this->app_name)     +
                strlen(this->options)      +
                strlen(this->output_file) +
                strlen(this->input_files)
            );
            sprintf(
                this->temporary_var,
                "%s %s %s %s",
                this->app_name,
                this->options,
                this->output_file,
                this->input_files
            );
            return system(this->temporary_var);
        }

        int extract(const char* input_file) {
            this->options = "-o";
            this->temporary_var = this->temporary_var = (char*)malloc(
                strlen("unzip") + 
                strlen(input_file) + 
                strlen(this->options) + 2
            );
            sprintf(
                this->temporary_var,
                "%s %s %s",
                "unzip", this->options, input_file
            );
            return system(this->temporary_var);
        }

};


class seven_zip: public archive_format {
    public:

        int compress() {
            this->app_name = strdup("7z");
            this->options = strdup("a");

            this->temporary_var = (char*)malloc(
                sizeof(this->app_name)*4
            );
            sprintf(
                this->temporary_var,
                "%s %s %s %s",
                this->app_name, this->options,
                this->output_file, this->input_files
            );
            return system(this->temporary_var);
        }

        int extract(const char* input_file) {
            this->options = "x -aoa";
            this->temporary_var = (char*)malloc(
                strlen(this->app_name) + 2 +
                strlen(this->options) +
                strlen(input_file)
            );
            sprintf(
                this->temporary_var,
                "%s %s %s",
                this->app_name,
                this->options,
                input_file
            );
            return system(this->temporary_var);
        }
};


#endif