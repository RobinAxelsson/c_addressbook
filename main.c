#include <stdio.h>

struct Contact {
    char name[20];
    char number[10];
};

const struct Contact NULL_CONTACT = { '\0', '\0' };

struct AddressBook {
    struct Contact contacts[5];
};

int contact_is_null(struct Contact contact){
    return contact.name[0] == NULL_CONTACT.name[0] && contact.number[0] == NULL_CONTACT.number[0];
}

void print_contact(struct Contact contact){
    printf("name: %s\nnumber: %s\n", contact.name, contact.number);
}

struct AddressBook SeedBook(struct AddressBook addressBook) {
    struct Contact contact = {"Robin", "0723079232"};
    struct Contact contact2 = {"Shan", "0723079333"};
    addressBook.contacts[0] = contact;
    addressBook.contacts[1] = contact2;

    return addressBook;
}

void print_all_contacts(struct AddressBook addressBook){
    int i = 0;
    while(!contact_is_null(addressBook.contacts[i])){
        print_contact(addressBook.contacts[i]);
        i++;
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
    addressBook = SeedBook(addressBook);
    print_all_contacts(addressBook);
    return 0;
}

