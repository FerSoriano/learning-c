#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void setContact(char*, char*, size_t);

typedef struct
{
    char name[50];
    char phone[50];
}
person;


int main() {

    size_t arr_size = 3;
    person *people = malloc(arr_size * sizeof(person)); // heap

    if (people == NULL) {
        printf("Falta de memoria...\n");
        return 1;
    }

    for (int i = 0; i < arr_size; i++) {
        setContact("Name", people[i].name, sizeof(people[i].name));
        setContact("Phone", people[i].phone, sizeof(people[i].phone));
        printf("\n");
    }
    
    printf("\n-----------------------\n\n");

    for (int i = 0; i < arr_size; i++) {
        printf("Contact Info: %s - %s\n", people[i].name, people[i].phone);
    }

    free(people);
    return 0;
}

void setContact(char *msg, char *value, size_t max_size){
    printf("%s: ", msg);
    fgets(value, max_size, stdin);
    char *n = strchr(value, '\n');
    if (n != NULL) {
        *n = '\0'; // direccion de '\n'
    }
}

void setContact2(char *msg, char *value){
    char buffer[50]; // aqui esta mal porque esta variable no se esta usando y el valor es statico
    printf("%s: ", msg);
    fgets(value, sizeof(buffer), stdin);
    char *n = strchr(value, '\n');
    if (n != NULL) {
        *n = '\0'; // direccion de '\n'
    }
}