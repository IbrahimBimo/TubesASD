#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED


#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

typedef struct murid infotype_child;
typedef struct elmlist_child *address_child;

struct murid
{
    string nama;
    long id;
    string alamat;
    string ttl;
    string jenis_kelamin;
    int umur;
};
struct elmlist_child
{
    address_child next;
    address_child prev;
    infotype_child info;
};

struct List_child
{
    address_child first;
    address_child last;
};


void createList(List_child &L);
void insertFirst(List_child &L, address_child P);
void insertLast(List_child &L, address_child P);
void insertAfter(address_child Prec, address_child P);
void deleteFirst(List_child &L, address_child &P);
void deleteLast(List_child &L, address_child &P);
void deleteAfter(address_child Prec, address_child &P);
void ascending1(List_child &L, address_child P);
void ascendingumur(List_child &L, address_child P);

address_child alokasi(infotype_child x);
void dealokasi(address_child &P);
address_child findElm(List_child L, infotype_child x);
void printInfo(List_child L);
void sorting1(List_child L);
void rataumur(List_child L);

#endif // LIST_CHILD_H_INCLUDED
