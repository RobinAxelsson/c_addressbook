#include <stdio.h>
#include <malloc.h>

typedef struct {
    char name[20];
    char number[11];
} Contact;

typedef struct {
    Contact *contacts;
    int size;
} DynAddressBook;

DynAddressBook dynAddressBook_init(){
    DynAddressBook dynAddressBook = { NULL, 0};
    printf("This is your dynamic address book:\n");
    return dynAddressBook;
}

DynAddressBook DynAddContactPtr(DynAddressBook *book, Contact contact){
    printf("book.contacts %p\n", (*book).contacts);
    (*book).size++;
    Contact* ptr = (Contact*)malloc(sizeof(Contact)*(*book).size);
    printf("book.contacts %p\n", (*book).contacts);
    printf("malloc.ptr %p\n", ptr);
    (*book).contacts = ptr;
    printf("book.contacts %p\n", (*book).contacts);
    (*book).contacts[0] = contact;
    printf("name %s, number %s\n", (*book).contacts[0].name, (*book).contacts[0].number);
}

DynAddressBook DynAddContact(DynAddressBook book, Contact contact){
    printf("book.contacts %p\n", (book).contacts);
    (book).size++;
    Contact *ptr = (Contact*)malloc(sizeof(Contact)*(book).size);
    printf("book.contacts %p\n", (book).contacts);
    printf("malloc.ptr %p\n", ptr);
    (book).contacts = ptr;
    printf("book.contacts %p\n", (book).contacts);
    (book).contacts[0] = contact;
    printf("name %s, number %s, ptr: %p\n", (book).contacts[0].name, (book).contacts[0].number, &(book).contacts[0]);
}

int main(){
    DynAddressBook book;
    book.contacts = NULL;
    printf("book.contacts %p\n", (void*)book.contacts);

    book.size++;
    Contact *ptr = malloc(sizeof(Contact) * book.size);

    printf("malloc.ptr %p\n", (void*)ptr);

    book.contacts = ptr;

    printf("book.contacts %p\n", (void*)book.contacts);

    Contact contact = {"Robin", "0723079232"};
    book.contacts[0] = contact;

    printf("name %s, number %s, ptr: %p\n", book.contacts[0].name, book.contacts[0].number, (void*)&book.contacts[0]);

    free(ptr);
}

//int main(){
//    DynAddressBook addressBook = dynAddressBook_init();
//    Contact contact = {"Robin", "0723079232"};
//    addressBook = DynAddContactPtr(&addressBook, contact);
//    //addressBook = DynAddContact(addressBook, contact);
//
////    Contact contact2 = {"Shan", "0723079333"};
////    addressBook = DynAddContact(addressBook, contact2);
////
//    printf("%p\n", &addressBook.contacts[0]);
//    Contact contact2 = addressBook.contacts[0];
//    printf("name: %s\nnumber: %s\n", contact2.name, contact2.number);
//}

//int main() {
//    printf("This is your address book:\n");
//
//    AddressBook addressBook = init_book();
//
//    printf("address book pointer: %p\n", &addressBook);
//
//    Contact contact = {"Robin", "0723079232"};
//    addressBook = AddContact(addressBook, contact);
//
//    Contact contact2 = {"Shan", "0723079333"};
//    addressBook = AddContact(addressBook, contact2);
//
//    Contact contact3 = {"Ahmed", "0723079888"};
//    addressBook = AddContact(addressBook, contact3);
//
//    Contact contact4 = {"Billy", "0723079111"};
//    addressBook = AddContact(addressBook, contact4);
//
//    printf("address book pointer: %p\n", &addressBook);
//
//    print_all_contacts(addressBook);
//
//    return 0;
//}