#include "child.h"
#include "child.h"

using namespace std;

/** Alloc */
void ChildcreateList(List_child &L) {
  first(L) = NULL;
  last(L) = NULL;
}

address_child Childalokasi(infotype_child x) {
  address_child P = new elmlist_child;
  info(P) = x;
  next(P) = NULL;
  prev(P) = NULL;
  return P;
}

/** Insert */
void ChildinsertFirst(List_child &L, address_child P) {
  if (first(L) == NULL) {
    last(L) = P;
    first(L) = P;
  } else {
    next(P) = first(L);
    prev(first(L)) = P;
    first(L) = P;
  }
}

void ChildinsertLast(List_child &L, address_child P) {
  if (first(L) == NULL) {
    last(L) = P;
    first(L) = P;
  } else {
    prev(P) = last(L);
    next(last(L)) = P;
    last(L) = P;
  }
}

void ChildinsertAfter(address_child &Prec, address_child P) {
  prev(next(Prec)) = P;
  next(P) = next(Prec);
  prev(P) = Prec;
  next(Prec) = P;
}

/** Delete */
void ChilddeleteFirst(List_child &L, address_child &P) {
  if (first(L) != NULL) {
    if (first(L) == last(L)) {
      P = first(L);
      first(L) = NULL;
      last(L) = NULL;
    } else {
      P = first(L);
      first(L) = next(P);
      prev(first(L)) = NULL;
      next(P) = NULL;
    }
  }
}

void ChilddeleteLast(List_child &L, address_child &P) {
  if (first(L) != NULL) {
    if (first(L) == last(L)) {
      P = first(L);
      first(L) = NULL;
      last(L) = NULL;
    } else {
      P = last(L);
      last(L) = prev(P);
      next(last(L)) = NULL;
      prev(P) = NULL;
    }
  }
}

void ChilddeleteAfter(List_child &L, address_child Prec, address_child &P) {
  if (first(L) != NULL) {
    if (Prec != NULL) {
      if (Prec != last(L)) {
        P = next(Prec);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
      }
    }
  }
}

/** Print And Find */
void ChildprintInfo(List_child L) {
  address_child P = first(L);
  while (P != NULL) {
    cout << "ID Supplier : " << info(P).ID_Supplier << endl;
    cout << "ID Barang : " << info(P).ID_Barang << endl;
    cout << "Barang Supply : " << info(P).Barang_Supply << endl;
    cout << "Harga Supplier : " << info(P).Harga_Supplier << endl;
    cout << "Alamat : " << info(P).Alamat << endl;
    cout << "No Telp : " << info(P).No_Telp << endl << endl;
    P = next(P);
  }
}

address_child ChildfindElm(List_child L, infotype_child x) {
  address_child P = first(L);
  while (P != NULL) {
    if (info(P).ID_Supplier == x.ID_Supplier) {
      return P;
    }
    P = next(P);
  }
  return NULL;
}
