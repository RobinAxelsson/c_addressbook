//
// Created by robin.salihaxelsson on 2023-05-20.
//

#ifndef C_ADDRESSBOOK_ADDRESSBOOK_H
#define C_ADDRESSBOOK_ADDRESSBOOK_H

typedef struct {
    char name[20];
    char number[11];
} Contact;

typedef struct {
    Contact *contacts;
    int size;
} AddressBook;

AddressBook* AddressBook_init();

AddressBook AddContact(AddressBook* self, Contact contact);

void AddressBook_print(AddressBook* self);

void AddressBook_deinit(AddressBook* self);

#endif //C_ADDRESSBOOK_ADDRESSBOOK_H
