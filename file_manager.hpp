#include "support/other.hpp"
#include "object/file.hpp"
#include "status/status.h"
#include <vector>

#ifndef FILE_MANAGER
#define FILE_MANAGER

class manager {

    public: //private default

        struct __action_command {
            char* name;
            char* command;
        };
        __action_command action_copy = {.name = strdup("copy"), .command = strdup("cp -r ")};
        __action_command action_cut = {.name = strdup("cut"), .command = strdup("mv ")};

        char* current_action;
        function* func;
        std::vector<object> virtual_clipboard;


    public:

        const char* current_path;
        std::vector<object> selected_files;
        status_return present_status = {.code=EX_OK, .message=NULL};


    public: // private default

        void* __transfer_clipboard_(char* action) {

            if (this->selected_files.size() == 0) {
                this->present_status = (status_return){.code=EX_IOERR, 
                                                       .message="selected files not found!"};
                return NULL;
            }

            int len_selected_files = this->selected_files.size();
            int len_virtual_clipboard = this->virtual_clipboard.size();

            if (len_selected_files) {
                for (int i=0; i<len_selected_files; i++) {
                    this->virtual_clipboard.push_back(this->selected_files[i]);
                }
            }
            this->current_action = action;

            this->present_status = (status_return){.code=EX_OK, .message=NULL};
            return NULL;

        }

        void* __paste_(char* action) {
            char * command = action;
            int len_virtual_clipboard = this->virtual_clipboard.size();
            
            for (int i=0; i<len_virtual_clipboard; i++) {
                command = strcat(command, strcat(this->virtual_clipboard[i].__full, strdup(" ")));
            }
            command = strcat(command, this->current_path);
            printf("%s\n", command);
            // this->clean_clipboard();
            /*return func->process(command);*/
            /**/
            this->present_status = (status_return){.code=EX_OK, .message="NULL"};

            return NULL; // exit
            /**/
        }


    public:

        manager(const char* current_path): current_path(strdup(current_path)){};
        status_return create_new_blank_file();

        void open() {
            // this->selected_files[0].open();
            // this->present_status = this->selected_files[0].present_status;
        }
        
        status_return delt();
        status_return create_archive();
        
        void copy() {this->__transfer_clipboard_(this->action_copy.name);}
        
        void cut() {this->__transfer_clipboard_(this->action_cut.name);}

        void* paste() {
            if (this->virtual_clipboard.size() == 0) {
                
                this->present_status = (status_return){
                    .code=EX__BASE, 
                    .message="paste ur fukg brain here!\ndid u copy or cut any thing?"};

            } else if (strcmp(this->current_action, this->action_copy.name) == 0) {
                
                this->__paste_(this->action_copy.command);
                
            } else if (strcmp(this->current_action, this->action_cut.name) == 0) {
                
                this->__paste_(this->action_cut.command);
                this->selected_files.clear();
                this->virtual_clipboard.clear();

            }
            return NULL;
        };
        
};


#endif