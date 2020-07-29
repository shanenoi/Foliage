#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // chdir
#include <sys/types.h> // permissions
#include <sys/stat.h> // permissions

// move to trash, delete
int remove(const char *pathname);

// create archive
struct Machine {
    char* name;
    char* params;
    char* inp;
    char* outp;
} zip = {"zip", "-r", "", ""};

char* gender(struct Machine a) {
    char* result = (char*)malloc(
        strlen(a.name) +
        strlen(a.params) +
        strlen(a.inp) + 
        strlen(a.outp) +4
    );
    sprintf(result, "%s %s %s %s", a.name, a.params, a.outp, a.inp);
    return result;
}

// rename
int rename(const char *old_n, const char *new_n);

// create blank text
int create_new_file(
        char name[],
        char template[]
){
   FILE *fptr;
   fptr = fopen(name,"w");
   if(fptr == NULL)
   {
      return 1;
   }
   fprintf(fptr,template);
   fclose(fptr);
   return 0;
}

// chdir to another path
int chdir(const char *path);

char* permissions(char *file){
    struct stat st;
    char *modeval = malloc(sizeof(char) * 9 + 1);
    if(stat(file, &st) == 0){
        mode_t perm = st.st_mode;
        modeval[0] = (perm & S_IRUSR) ? 'r' : '-';
        modeval[1] = (perm & S_IWUSR) ? 'w' : '-';
        modeval[2] = (perm & S_IXUSR) ? 'x' : '-';
        modeval[3] = (perm & S_IRGRP) ? 'r' : '-';
        modeval[4] = (perm & S_IWGRP) ? 'w' : '-';
        modeval[5] = (perm & S_IXGRP) ? 'x' : '-';
        modeval[6] = (perm & S_IROTH) ? 'r' : '-';
        modeval[7] = (perm & S_IWOTH) ? 'w' : '-';
        modeval[8] = (perm & S_IXOTH) ? 'x' : '-';
        modeval[9] = '\0';
        return modeval;
    }
    else{
        return "error";
    }
}
