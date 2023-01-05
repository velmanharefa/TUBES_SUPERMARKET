#ifndef SUPERMARKET_H_INCLUDED
#define SUPERMARKET_H_INCLUDED
#include <iostream>


using namespace std;

#define first(L) L.first
#define last(L) L.last

#define next(P) P->next
#define prev(P) P->prev

#define info(P) P->info
#define child(P) P->child

struct infotype_parent{
  string ID_Barang, Nama_Barang, Jenis_Barang, ID_Supplier;
    int Jumlah_Barang, Harga_Jual;
};
struct infotype_child{
  string ID_Supplier, ID_Barang, Alamat, Barang_Supply;
  int No_Telp, Harga_Supplier;
};

typedef struct elmlist_parent *address_parent;
typedef struct elmlist_child *address_child;
typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi next;
    address_child info;
};

struct List_relasi{
    address_relasi first;
};

struct elmlist_parent {
    infotype_parent info;
    List_relasi relasi;
    address_parent next;
    address_child Child;
};

struct List_parent {
    address_parent first;
};

struct elmlist_child {
  infotype_child info;
  address_child next;
  address_child prev;
};

struct List_child {
  address_child first;
  address_child last;
};

//Parent
void ParentcreateList(List_parent &L);
infotype_parent newDataParent (string ID_Barang, string Nama_Barang, string Jenis_Barang, string ID_Supplier, int Jumlah_Barang, int Harga_Jual);
void RelasiAlloc(List_child &L);
void ParentinsertFirst(List_parent &L, address_parent P);
void ParentinsertAfter(List_parent &L, address_parent Prec, address_parent P);
void ParentinsertLast(List_parent &L, address_parent P);
void ParentdeleteFirst(List_parent &L, address_parent &P);
void ParentdeleteLast(List_parent &L, address_parent &P);
void ParentdeleteAfter(List_parent &L, address_parent Prec, address_parent &P);

address_parent Parentalokasi(infotype_parent x);
void Parentdealokasi(address_parent &P);
address_parent ParentfindElm(List_parent L, infotype_parent x);
void ParentprintInfo(List_parent L);
int countMinimumChild(address_parent L, infotype_parent &data);
int countMaximumChild(address_parent L, infotype_parent &data);
void countAllChild(address_parent L);
address_parent findBarangByID(address_parent L, infotype_parent search);

//Child
void ChildcreateList(List_child &L);
infotype_child newDataChild(string ID_Supplier, string ID_Barang, string Alamat, string Barang_Supply, int No_Telp, int Harga_Supplier);
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

//MENUs
void Menu_Main();
void Menu_Barang();
void Menu_Supplier();

#endif // SUPERMARKET_H_INCLUDED
