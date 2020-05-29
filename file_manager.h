#include "other"

class manager {

    private:
        function other;

    public:
        char * current_path = ".";
        char * selected_files[];
        char * virtual_clipboard[];

        int create_new_blank_file() {};
        int open() {};
        int delete() {};
        int * create_archive() {};

        int copy() {
            int len_selected_files = sizeof(selected_files)/sizeof(selected_files[0]);
            int len_virtual_clipboard = sizeof(virtual_clipboard)/sizeof(*virtual_clipboard);

            if (len_selected_files) {
                for (int i=0; i<len_selected_files; i++) {
                    *(virtual_clipboard + len_virtual_clipboard + i) = *(selected_files + i);
                }
            }

            return 0;
        }

        int paste() {
            char * command = "cp -r ";
            int len_virtual_clipboard = sizeof(virtual_clipboard)/sizeof(*virtual_clipboard);
            
            for (int i=0; i<len_virtual_clipboard; i++) {
                command = this->other.concat(
                    command,
                    this->other.concat(
                        *(virtual_clipboard+i),
                        " "
                    )
                );
            }
            command = this->other.concat(command, current_path);
            return system(command);
        }
}