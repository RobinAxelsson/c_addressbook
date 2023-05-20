#include <stdio.h>
#include <string.h>
#include "addressbook.h"


int main(){
    char* input = "Hello";
    char name[20];
    strcpy(name, input);
    printf("%s", name);
    AddressBook* book = AddressBook_init();
    AddContact(book, "Robin", "0723079232");
    AddContact(book, "Shan", "0707318599");
    AddressBook_print(book);
    AddressBook_deinit(book);
}