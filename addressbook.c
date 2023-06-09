#include <malloc.h>
#include "addressbook.h"
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    char number[11];
} Contact;

struct AddressBook{
    Contact *contacts;
    int size;
};

AddressBook* AddressBook_init(){
    AddressBook *self = malloc(sizeof(AddressBook));
    self->contacts = NULL;
    self->size = 0;
    return self;
}

void AddContact(AddressBook* self, char *name, char *number){
    Contact contact;
    strcpy(contact.name, name);
    strcpy(contact.number, number);

    self->size++;
    Contact *ptr = realloc(self->contacts, sizeof(Contact) * self->size);
    self->contacts = ptr;
    self->contacts[self->size - 1] = contact;
}

void AddressBook_print(const AddressBook* self){
    for (int i = 0; i < self->size; ++i) {
        printf("name %s, number %s, ptr: %p\n", self->contacts[i].name, self->contacts[i].number, (void*)&self->contacts[i]);
    }
}

void AddressBook_deinit(const AddressBook* self){
    free(self->contacts);
    free(self);
}