#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

void create(char *dir) {
    char table_name[50];
    cout << "Enter the table name: ";
    cin >> table_name;
    strcat(table_name, ".txt");
    strcat(dir, "/");
    strcat(dir, table_name);
    FILE *file = fopen(dir, "a");
    if (file == nullptr) {
        cerr << "Error opening file\n";
        return;
    }
    fclose(file);
}

void insert(char *dir, char *data) {
    char table_name[50];
    cout << "Enter the table name: ";
    cin >> table_name;
    strcat(table_name, ".txt");
    strcat(dir, "/");
    strcat(dir, table_name);
    FILE *file = fopen(dir, "a");
    if (file == nullptr) {
        cerr << "Error opening file\n";
        return;
    }
    fprintf(file, "%s", data);
    fclose(file);
}

void find(char *dir) {
    char table_name[50];
    cout << "Enter the table name: ";
    cin >> table_name;
    strcat(table_name, ".txt");
    strcat(dir, "/");
    strcat(dir, table_name);
    FILE *file = fopen(dir, "r");
    if (file == nullptr) {
        cerr << "Error opening file\n";
        return;
    }
    char line[100];
    while (fgets(line, sizeof(line), file) != nullptr) {
          if(line[0]=='2'){
            cout<<line<<endl;
          }
    }
    fclose(file);
}

int main() {
    FILE *file_ptr;
    char *dir = new char[256]; // Allocating memory for the directory path
    if (dir == nullptr) {
        cerr << "Memory allocation failed\n";
        return 1;
    }
    strcpy(dir, getenv("HOME"));
    strcat(dir, "/db"); // Assuming db is the database directory

    const char *data = "1 pramod classa 80\n";
    find(dir);
    free(dir); // Freeing allocated memory
    return 0;
}
