#include "support/other.h"
#include "object/object.h"
#include "object/path.h"
#include <vector>

#ifndef FILE_MANAGER
#define FILE_MANAGER

class manager {

    private:
        function other;

    public:
        path current_path;
        std::vector<object> selected_files;
        std::vector<object> virtual_clipboard;

        int create_new_blank_file();
        int open();
        int delt();
        int create_archive();

        int copy() {
            int len_selected_files = this->selected_files.size();
            int len_virtual_clipboard = this->virtual_clipboard.size();

            if (len_selected_files) {
                for (int i=0; i<len_selected_files; i++) {
                    virtual_clipboard.push_back(this->selected_files[i]);
                }
            }

            return 0;
        }

        int paste() {
            char * command = strdup("cp -r ");
            int len_virtual_clipboard = this->virtual_clipboard.size();
            
            for (int i=0; i<len_virtual_clipboard; i++) {
                command = this->other.concat(
                    command,
                    this->other.concat(
                        this->virtual_clipboard[i].path_file.link,
                        strdup(" ")
                    )
                );
            }
            command = this->other.concat(command, this->current_path.link);

            return system(command);
        }
};


#endif