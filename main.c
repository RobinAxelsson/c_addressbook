#include "addressbook.h"

int main(){
    AddressBook* book = AddressBook_init();
    Contact contact = {"Robin", "0723079232"};
    AddContact(book, contact);
    Contact contact2 = {"Shan", "0723079333"};
    AddContact(book, contact2);
    AddressBook_print(book);
    AddressBook_deinit(book);
}