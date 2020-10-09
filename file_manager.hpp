#ifndef FILE_MANAGER
#define FILE_MANAGER

#include "global.var"
#include "support/other.hpp"
#include "object/file.hpp"
#include "status/status.h"
#include <vector>


class Template {

//    public:

};


class Manager {


    public: // private default | open public for debugging easily

        struct __action_command {char* name; char* command;};

        __action_command action_copy = {.name = strdup("copy"), 
                                        .command = strdup("cp -r ")};
        __action_command action_cut = {.name = strdup("cut"), 
                                       .command = strdup("mv ")};

        struct __action_command current_action;
        Function* func;
        std::vector<Object> virtual_clipboard;


    public:

        const char* current_path;
        std::vector<Object> selected_files;
        status_return present_status = {.code=EX_OK, .message=NULL};


    public: // private default | open public for debugging easily

        void* __transfer_clipboard_(struct __action_command action) {

            if (this->selected_files.size() == 0) {
                this->present_status = (status_return){
                                        .code=EX_IOERR, 
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

    
        void* __paste_(struct __action_command action) {

            char * command = action.command;
            int len_virtual_clipboard = this->virtual_clipboard.size();
            
            for (int i=0; i<len_virtual_clipboard; i++) {
                this->virtual_clipboard[i].load_details();
                command = strcat(command, 
                                 strcat(this->virtual_clipboard[i].__full, 
                                        strdup(" ")));
            }
            command = strcat(command, this->current_path);
            printf("%s\n", command);

            /* this->present_status = func->process(command);*/
            /* start demo mode */
            this->present_status = (status_return){.code=EX_OK, 
                                                   .message="NULL"};
            /* end demo mode */

            return NULL; // exit

        }


    public:

        Manager(const char* current_path): current_path(strdup(current_path)){};
        void create_new_blank_file();
        void* notify();


        void* open();
        
        status_return delt();
        status_return create_archive();
        
        void copy() {this->__transfer_clipboard_(this->action_copy);}
        
        void cut() {this->__transfer_clipboard_(this->action_cut);}

        void* paste() {
            if (this->virtual_clipboard.size() == 0) {
                
                this->present_status = (status_return){
                    .code=EX__BASE, 
                    .message="paste ur fukg brain here!\n"
                             "did u copy or cut any thing?"};
                
                /* Trigger */
                this->notify();
                return NULL;


            } else if (strcmp(this->current_action.name, 
                              this->action_copy.name) == 0) {
                
                this->__paste_(this->action_copy);
                
            } else if (strcmp(this->current_action.name,
                              this->action_cut.name) == 0) {
                
                this->__paste_(this->action_cut);
                this->selected_files.clear();
                this->virtual_clipboard.clear();

            }
            return NULL;
        };
        
};


void* Manager::notify() {
    /* Console mode */
    printf("<-->\n"
           "Exit code: %d\n"
           "Message: `%s`\n"
           "<-->\n",
           Manager::present_status.code,
           Manager::present_status.message
    );
    return NULL;
}

void* Manager::open() {
    /* open first selected file in vector selected_files */
    return NULL;
}


#endif
