//
// Created by robin.salihaxelsson on 2023-05-20.
//

#ifndef C_ADDRESSBOOK_ADDRESSBOOK_H
#define C_ADDRESSBOOK_ADDRESSBOOK_H

typedef struct AddressBook AddressBook;

AddressBook* AddressBook_init();

void AddContact(AddressBook* self, char *name, char *number);

void AddressBook_print(const AddressBook* self);

void AddressBook_deinit(const AddressBook* self);

#endif //C_ADDRESSBOOK_ADDRESSBOOK_H
