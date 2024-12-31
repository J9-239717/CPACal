#include "include_h.h"

void parse(char *filename,table *t){
    FILE *f = fopen(filename, "r");   
    assert(f != NULL);
    char line[100];
    fgets(line, 100, f);
    line[strlen(line)-1] = '\0';
    int c_4,c_3,c_2;
    sscanf(line, "%d,%d,%d", &c_4, &c_3, &c_2);
    line[0] = '\0';
    t->_list_credit[0].capacity = c_4;
    t->_list_credit[1].capacity = c_3;
    t->_list_credit[2].capacity = c_2;
    for(int i = 0; i < 3; i++){
        t->_list_credit[i].list = (float*)malloc(sizeof(float)*t->_list_credit[i].capacity);
        fgets(line, 100, f);
        line[strlen(line)-1] = '\0';
        char *token = strtok(line, ",");
        int j = 0;
        while(token != NULL){
            t->_list_credit[i].list[j] = atof(token);
            token = strtok(NULL, ",");
            j++;
        }
        line[0] = '\0';
    }
    fclose(f);
}