#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED
#include <iostream>

using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

struct infotype_child{
    string ID_Supplier, ID_Barang, Alamat, Barang_Supply;
    int No_Telp, Harga_Supplier;
};

typedef struct elmlist_child *address_child;

struct elmlist_child {
    infotype_child info;
    address_child next;
    address_child prev;
};

struct List_child {
    address_child first;
    address_child last;
};

void ChildcreateList(List_child &L);

void ChildinsertFirst(List_child &L, address_child P);
void ChildinsertAfter(address_child Prec, address_child P);
void ChildinsertLast(List_child &L, address_child P);

void ChilddeleteFirst(List_child &L, address_child &P);
void ChilddeleteLast(List_child &L, address_child &P);
void ChilddeleteAfter(address_child Prec, address_child &P);

address_child Childalokasi(infotype_child x);
void Childdealokasi(address_child &P);
address_child ChildfindElm(List_child L, infotype_child x);
void ChildprintInfo(List_child L);


#endif // CHILD_H_INCLUDED
