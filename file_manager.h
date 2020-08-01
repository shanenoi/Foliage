#include "support/other.h"
#include "object/object.h"
#include "status/status.h"
#include <vector>

#ifndef FILE_MANAGER
#define FILE_MANAGER

class manager {

    public:
        char* action_command[2] = {
            strdup("cp -r "),
            strdup("mv "),
        };
        char* current_action;
        char* current_path;
        function* func;
        std::vector<object> selected_files;
        std::vector<object> virtual_clipboard;

    public:

        manager(const char*);
        status_return create_new_blank_file();
        status_return open();
        status_return delt();
        status_return create_archive();
        void __transfer_(char*);
        void copy() {
            this->__transfer_(strdup("copy"));
        };
        void cut() {
            this->__transfer_(strdup("cut"));
        };
        status_return __paste_(char*);
        status_return paste() {
            if (strcmp(this->current_action, "copy") == 0) {
                return this->__paste_(this->action_command[0]);
            } else if (strcmp(this->current_action, "cut") == 0) {
                return this->__paste_(this->action_command[1]);
            }
            return (status_return) {
                .code = EX__BASE,
                .message = "paste what?"
            };
        };
        
};

manager::manager(const char* current_path) {
    manager::current_path = strdup(current_path);
}

void manager::__transfer_(char* action) {
    int len_selected_files = manager::selected_files.size();
    int len_virtual_clipboard = manager::virtual_clipboard.size();

    if (len_selected_files) {
        for (int i=0; i<len_selected_files; i++) {
            virtual_clipboard.push_back(manager::selected_files[i]);
        }
    }

    manager::current_action = action;

}

status_return manager::__paste_(char* action) {
    char * command = action;
    int len_virtual_clipboard = manager::virtual_clipboard.size();
    
    for (int i=0; i<len_virtual_clipboard; i++) {
        command = strcat(
            command,
            strcat(
                manager::virtual_clipboard[i].__full,
                strdup(" ")
            )
        );
    }
    command = strcat(command, manager::current_path);

    /*return func->process(command);*/
    /**/
    printf("%s", command);
    status_return status = {
        .code = EX_OK,
        .message = NULL,
    };
    return status;
    /**/
}
#endif