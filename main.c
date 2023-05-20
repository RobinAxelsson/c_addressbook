#include <stdio.h>

typedef struct {
    char name[20];
    char number[11];
} Contact;

const Contact NULL_CONTACT = { '\0', '\0' };

typedef struct {
    Contact contacts[3];
} AddressBook;

typedef struct {
    Contact *contacts;
    int size;
} DynAddressBook;

DynAddressBook dynAddressBook_init(){
    DynAddressBook dynAddressBook = { NULL, 0};
    printf("Dyn book init");
    return dynAddressBook;
}

int contact_is_null(Contact contact){
    return contact.name[0] == NULL_CONTACT.name[0] && contact.number[0] == NULL_CONTACT.number[0];
}


void AddContactWithPtr(AddressBook *book, Contact contact){
    
    int length = sizeof((*book).contacts)/sizeof(Contact);
    for (int i = 0; i < length; ++i) {
        if(contact_is_null((*book).contacts[i])){
            (*book).contacts[i] = contact;
            printf("Added %s\n", contact.name);
            return;
        }
    }
    printf("%s could not be added, book is full!\n", contact.name);
}

//DynAddressBook DynAddContact(DynAddressBook book, Contact contact){
//
//    for (int i = 0; i < book.size; ++i) {
//        if(contact_is_null(book.contacts[i])){
//            book.contacts[i] = contact;
//            printf("Added %s\n", contact.name);
//            return book;
//        }
//    }
//    printf("Allocating more memory for %s!\n", contact.name);
//    Contact* ptr = (Contact*)malloc(sizeof(Point));
//    if (ptr == NULL) {
//        printf("Memory allocation failed.\n");
//        return 1;
//    }
//
//}

AddressBook AddContact(AddressBook book, Contact contact){

    int length = sizeof(book.contacts)/sizeof(Contact);
    for (int i = 0; i < length; ++i) {
        if(contact_is_null(book.contacts[i])){
            book.contacts[i] = contact;
            printf("Added %s\n", contact.name);
            return book;
        }
    }
    printf("%s could not be added, book is full!\n", contact.name);
}

void print_all_contacts(AddressBook book){
    int length = sizeof(book.contacts)/sizeof(Contact);
    printf("Address book contacts:\n");
    for (int i = 0; i < length; ++i) {
        Contact contact = book.contacts[i];
        printf("name: %s\nnumber: %s\n", contact.name, contact.number);
    }
}

AddressBook init_book() {
    AddressBook book;
    int length = sizeof(book.contacts)/sizeof(Contact);
    for (int i = 0; i < length; ++i) {
        book.contacts[i] = NULL_CONTACT;
    }
    return book;
}

int main() {
    printf("This is your address book:\n");

    AddressBook addressBook = init_book();

    printf("address book pointer: %p\n", &addressBook);

    Contact contact = {"Robin", "0723079232"};
    addressBook = AddContact(addressBook, contact);

    Contact contact2 = {"Shan", "0723079333"};
    addressBook = AddContact(addressBook, contact2);

    Contact contact3 = {"Ahmed", "0723079888"};
    addressBook = AddContact(addressBook, contact3);

    Contact contact4 = {"Billy", "0723079111"};
    addressBook = AddContact(addressBook, contact4);

    printf("address book pointer: %p\n", &addressBook);

    print_all_contacts(addressBook);

    return 0;
}