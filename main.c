#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void create(char * dir){
    char table_name[50];
    printf("Enter the table name: ");
    scanf("%s", table_name);
    strcat(table_name,".txt");
    strcat(dir, "/");
    strcat(dir, table_name);
    FILE *file = fopen(dir, "a");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    fclose(file);
}
void insert(char * dir,char * data){
    char table_name[50];
    printf("Enter the table name: ");
    scanf("%s", table_name);
    strcat(table_name,".txt");
    strcat(dir, "/");
    strcat(dir, table_name);
    FILE *file = fopen(dir, "a");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    fprintf(file,"%s",data);
    fclose(file);
}
void find(char * dir){
    char table_name[50];
    printf("Enter the table name: ");
    scanf("%s", table_name);
    strcat(table_name,".txt");
    strcat(dir, "/");
    strcat(dir, table_name);
    FILE * file=fopen(dir,"r");
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
        printf("line");
    }             
}
int main() {
    FILE *file_ptr;
    char *dir = malloc(256); // Allocating memory for the directory path
    if (dir == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    strcpy(dir, getenv("HOME"));
    strcat(dir, "/db"); // Assuming db is the database directory



    char * data="1 pramod classa 80\n";
    find(dir);
    free(dir); // Freeing allocated memory
    return 0;
}

