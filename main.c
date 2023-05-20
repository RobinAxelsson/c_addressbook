#include <stdio.h>
#include <malloc.h>

typedef struct {
    char name[20];
    char number[11];
} Contact;

typedef struct {
    Contact *contacts;
    int size;
} AddressBook;

AddressBook AddContact(AddressBook* self, Contact contact){
    self->size++;
    Contact *ptr = realloc(self->contacts, sizeof(Contact) * self->size);
    self->contacts = ptr;
    self->contacts[self->size - 1] = contact;
}

AddressBook* AddressBook_init(){
    AddressBook *self = malloc(sizeof(AddressBook));
    self->contacts = NULL;
    self->size = 0;
    return self;
}

int main(){
    AddressBook *book = AddressBook_init();
    Contact contact = {"Robin", "0723079232"};
    AddContact(book, contact);
    Contact contact2 = {"Shan", "0723079333"};
    AddContact(book, contact2);

    for (int i = 0; i < book->size; ++i) {
        printf("name %s, number %s, ptr: %p\n", book->contacts[i].name, book->contacts[i].number, (void*)&book->contacts[i]);
    }

    free(book);
}