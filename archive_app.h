#include <string.h>

class archive_format {

    public:
        char * app_name;
        char * options;
        char * input_files;
        char * output_files;
        char * temporary_var;

        ~archive_format() {
            free(this->temporary_var);
        }

        int check_available() {
            return system(this->app_name);
        }

        int compress() {}

        int extract() {}
};


class zip: public archive_format {

    public:

        int compress() {
            this->app_name = strdup("zip");
            this->options = strdup("-r");

            this->temporary_var = (char*)malloc(
                strlen(this->app_name)     +
                strlen(this->options)      +
                strlen(this->output_files) +
                strlen(this->input_files)
            );
            sprintf(
                this->temporary_var,
                "%s %s %s %s",
                this->app_name,
                this->options,
                this->output_files,
                this->input_files
            );
            return system(this->temporary_var);
        }

        int extract(char * input_file) {
            this->temporary_var = this->temporary_var = (char*)malloc(
                strlen("unzip") + strlen(input_file)
            );
            sprintf(
                this->temporary_var,
                "%s %s",
                "unzip", input_file
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
                this->output_files, this->input_files
            );
            return system(this->temporary_var);
        }

        int extract(char * input_file) {
            this->temporary_var = (char*)malloc(
                strlen(this->app_name) + 1 +
                strlen(input_file)
            );
            sprintf(
                this->temporary_var,
                "%s %s %s",
                this->app_name,
                "x",
                input_file
            );
            return system(this->temporary_var);
        }
};