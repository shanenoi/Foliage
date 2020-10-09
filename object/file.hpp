#ifndef __INCLD_ININT__
#define __INCLD_ININT__

#include "object.hpp"
#include "archive.hpp"
#include "audio.hpp"
#include "code.hpp"
#include "image.hpp"
#include "video.hpp"

#endif /*__INCLD_ININT__*/

#ifndef __META_PATH__
#define __META_PATH__


typedef struct {const char* path; const char* name;} meta_path;


#endif /*__META_PATH__*/

#ifndef __DETECT_TYPE__
#define __DETECT_TYPE__

#include <string.h>
#include <stdlib.h>
#include <stdio.h> 
#include "types.hpp"

class Detecter {

    private:
    
        int max_size = 13;
        int *stor = (int*)malloc(sizeof(int)*this->max_size);
        FILE *fp;


    public:
        const char *file;
        char *extension = (char*)malloc(sizeof(char)*9);

        Detecter() {init_type();}
        ~Detecter() {free(this->stor);
                     free_type();}
        char *get_extension();
        int compare(int*, int, int*);


    private:
    
        void read() {
            this->fp = fopen(this->file, "rb");
            int single_char;
            int index = 0;
            while ((single_char=getc(fp))!= EOF && index!=this->max_size) {
                this->stor[index++] = single_char;
            }
            fclose(this->fp);
        }


    public:

        enum TYPES astype() {
            this->read();
            this->get_extension();
            for (int i=0; i<DEFAULT_LEN; i++) {
                if (this->compare(DEFAULT[i].header, DEFAULT[i].len, this->stor)) {
                    if (DEFAULT[i].name==ZIP &&
                        strcmp(this->extension, "docx")==0) {return DOCX;}
                    return DEFAULT[i].name;
                }
            }
            return TXT;
        }

        void __test_read() {this->read();}

};


char *Detecter::get_extension() {
    Detecter::extension = strdup("");
    char buff[2] = {' ', '\0'};
    int len_file_name = strlen(Detecter::file);
    for (int i=len_file_name-1; i!=0; i--) {
        if (Detecter::file[i]=='.' or Detecter::file[i]=='/') break;
        buff[0] = Detecter::file[i];
        Detecter::extension = strcat(strdup(buff), Detecter::extension);
    }   
    return Detecter::extension;
}


int Detecter::compare(int *header, int len_header, int *str2) {
    for(int i=0; i<len_header; i++) {
        if (header[i] != str2[i]) {return 0;}
    }
    return 1;
}


static Detecter* DETECTER = new Detecter();

#endif /*__DETECT_TYPE__*/
