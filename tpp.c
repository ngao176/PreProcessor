#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv) {
    int i=1;

    if(argc < 2){
        printf("Please input at least 1 file\n");
        return 0;
    }

    int x = strlen(argv[i]) -1;
    if(argv[i][x] != 'c' ){
        printf("Please input a .c file\n");
        return 0;
    }

    while(argv[i] != NULL){

        FILE *file = fopen(argv[i],"r");

        if (file == NULL){
            printf("File %s does not exist\n",argv[i]);
            return 0;
        }

        int len = strlen(argv[i]) -1;
        char *out = argv[i];
        out[len] = 'i';
        FILE *outs = fopen(out, "w");

        char *line = NULL;
        size_t length = 0;
        ssize_t nread;
        while((nread = getline(&line, &length, file)) != -1) {

            if(strstr(line, "#include ")){
                recursive(line, outs);
            }else {
                fwrite(line, 1, nread, outs);
            }

        }
        free(line);
        fclose(file);
        i++;    
    }
    return 0;
}

void recursive(char *line, FILE *outs){
    char name[50]; 
    int len = strlen(line);

    strncpy(name, line + 10, len - 9);
   
    int size = strlen(name);
   
    name[size-2] = '\0';

    FILE *fp = fopen(name,"r");

    char *line2 = NULL;
    size_t length = 0;
    ssize_t nread;
    while((nread = getline(&line2, &length, fp)) != -1) {

        if(strstr(line2, "#include ")){
            
            recursive(line2, outs);
        }else {
            fwrite(line2, 1, nread, outs);
        }

    }
    free(line2);         
    fclose(fp);
}
