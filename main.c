#include <stdio.h>

struct Contact {
    char name[20];
    char number[11];
};

const struct Contact NULL_CONTACT = { '\0', '\0' };

struct AddressBook {
    struct Contact contacts[3];
};

int contact_is_null(struct Contact contact){
    return contact.name[0] == NULL_CONTACT.name[0] && contact.number[0] == NULL_CONTACT.number[0];
}

void AddContactWithPtr(struct AddressBook *book, struct Contact contact){
    
    int length = sizeof((*book).contacts)/sizeof(struct Contact);
    for (int i = 0; i < length; ++i) {
        if(contact_is_null((*book).contacts[i])){
            (*book).contacts[i] = contact;
            printf("Added %s\n", contact.name);
            return;
        }
    }
    printf("%s could not be added, book is full!\n", contact.name);
}

struct AddressBook AddContact(struct AddressBook book, struct Contact contact){

    int length = sizeof(book.contacts)/sizeof(struct Contact);
    for (int i = 0; i < length; ++i) {
        if(contact_is_null(book.contacts[i])){
            book.contacts[i] = contact;
            printf("Added %s\n", contact.name);
            return book;
        }
    }
    printf("%s could not be added, book is full!\n", contact.name);
}

void print_all_contacts(struct AddressBook book){
    int length = sizeof(book.contacts)/sizeof(struct Contact);
    printf("Address book contacts:\n");
    for (int i = 0; i < length; ++i) {
        struct Contact contact = book.contacts[i];
        printf("name: %s\nnumber: %s\n", contact.name, contact.number);
    }
}

struct AddressBook init_book() {
    struct AddressBook book;
    int length = sizeof(book.contacts)/sizeof(struct Contact);
    for (int i = 0; i < length; ++i) {
        book.contacts[i] = NULL_CONTACT;
    }
    return book;
}

int main() {
    printf("This is your address book:\n");

    struct AddressBook addressBook = init_book();

    printf("address book pointer: %p\n", &addressBook);
    
    struct Contact contact = {"Robin", "0723079232"};
    addressBook = AddContact(addressBook, contact);

    struct Contact contact2 = {"Shan", "0723079333"};
    addressBook = AddContact(addressBook, contact2);

    struct Contact contact3 = {"Ahmed", "0723079888"};
    addressBook = AddContact(addressBook, contact3);

    struct Contact contact4 = {"Billy", "0723079111"};
    addressBook = AddContact(addressBook, contact4);

    printf("address book pointer: %p\n", &addressBook);

    print_all_contacts(addressBook);

    return 0;
}

