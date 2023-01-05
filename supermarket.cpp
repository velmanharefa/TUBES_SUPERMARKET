#include "supermarket.h"

//Parent
void ParentcreateList(List_parent &L) {
    first(L) = NULL;
}

infotype_parent newDataParent (string ID_Barang, string Nama_Barang, string Jenis_Barang, string ID_Supplier, int Jumlah_Barang, int Harga_Jual){
  infotype_parent dataParent;
  dataParent.ID_Barang = ID_Barang;
  dataParent.Nama_Barang = Nama_Barang;
  dataParent.Jenis_Barang = Jenis_Barang;
  dataParent.ID_Supplier = ID_Supplier;
  dataParent.Jumlah_Barang = Jumlah_Barang;
  dataParent.Harga_Jual = Harga_Jual;

  return dataParent;
}

void RelasiAlloc(List_relasi &L){
  first(L) = NULL;
}

void ChildcreateList(List_child &L) {
  first(L) = NULL;
  last(L) = NULL;
}

address_parent Parentalokasi(infotype_parent x) {
  address_parent P = new elmlist_parent;
  info(P) = x;
  next(P) = NULL;
  P->Child = NULL;
  //RelasiAlloc(P->relasi);
  return P;
}

address_child Childalokasi(infotype_child x){
  address_child P = new elmlist_child;
  info(P) = x;
  next(P) = NULL;
  P->prev = NULL;
  return P;
}

void ParentinsertFirst(List_parent &L, address_parent P) {
  address_parent Q;
  if(first(L) == NULL) {
      first(L) = P;
      next(P) = P;
  } else {
      Q = first(L);
      while(next(Q) != first(L)) {
          Q = next(Q);
      }
      next(P) = first(L);
      next(Q) = P;
      first(L) = P;
  }
}

void ParentinsertLast(List_parent &L, address_parent P){
  address_parent current;
  if(first(L) == NULL){
    ParentinsertFirst(L,P);
  }else {
    current = first(L);
    while (next(current) != NULL){
      current = next(current);
      next(current) = P;
    }
  }
}

void ParentdeleteFirst(List_parent &L, address_parent &P){
  if(first(L) != NULL){
    P = first(L);
    first(L) = next(first(L));
    next(P) = NULL;
    }
}

void ParentdeleteLast(List_parent &L, address_parent &P){
  address_parent current;
  if (first(L)!=NULL){
    if(L.first->next == NULL){
      ParentdeleteFirst(L,P);
    }else {
      current = first(L);
      while(next(next(current)) != NULL){
        current = next(current);
        P = next(current);
        next(current) = NULL;
      }
    }
  }
}

void ParentprintInfo(List_parent L) {
    address_parent P = first(L);
    if(first(L)!=NULL) {
      cout << " === Parent === " << endl;
        do {

            cout<< "ID BARANG : " <<info(P).ID_Barang<<endl;
            cout<< "ID Supplier : " <<info(P).ID_Supplier <<endl;
            cout<< "Nama: " <<info(P).Nama_Barang<<endl;
            cout<< "Jenis Barang : " <<info(P).Jenis_Barang<<endl;
            cout<< "Jumlah Barang: " <<info(P).Jumlah_Barang <<endl;
            cout<< "Harga Jual : " <<info(P).Harga_Jual <<endl << endl;


            P = next(P);
        } while((P)!=first(L));
    }
}

address_parent ParentfindElm(List_parent L, infotype_parent x) {
    address_parent P = first(L);
    do {
        if(info(P).ID_Barang == x.ID_Barang) {
            return P;
            cout<< "ID BARANG : " <<info(P).ID_Barang<<endl;
            cout<< "ID Supplier : " <<info(P).ID_Supplier <<endl;
            cout<< "Nama: " <<info(P).Nama_Barang<<endl;
            cout<< "Jenis Barang : " <<info(P).Jenis_Barang<<endl;
            cout<< "Jumlah Barang: " <<info(P).Jumlah_Barang <<endl;
            cout<< "Harga Jual : " <<info(P).Harga_Jual <<endl << endl;
        }
      P = next(P);
    } while(P != first(L));
    return NULL;
}

int countMinimumChild(address_parent L, infotype_parent &data) {
	int total = 0; int temp; address_parent current; address_child child;
	if (L != NULL) {
		current = L;
		while (current != NULL) {
			child = current->Child;
			temp = 0;
			while (child != NULL) {
				temp++;
				child = child->next;
			}
			if (temp > total) {
				data = current->info;
				temp = total;
			}
			current = current->next;
		}
		return total;
	}
	else return -1;
}

int countMaximumChild(address_parent L, infotype_parent &data) {
	int total = 0; int temp; address_parent current; address_child child;
	if (L != NULL) {
		current = L;
		while (current != NULL) {
			child = current->Child;
			temp = 0;
			while (child != NULL) {
				temp++;
				child = child->next;
			}
			if (temp > total) {
				data = current->info;
				temp = total;
			}
			current = current->next;
		}
		return total;
	}
	else return -1;
}

void countAllChild(address_parent L) {
	int total, temp; address_parent current; address_child child;
	total = 0;
	if (L != NULL) {
		current = L;
		while (current != NULL) {
			child = current->Child;
			temp = 0;
			while (child != NULL) {
				temp++;
				child = child->next;
			}
			current = current->next;
		}
	}
	else std::cout << "[ERROR] List Armada Kosong!!" << std::endl;
}

address_parent findBarangByID(address_parent L, infotype_parent search) {
	address_parent current;
	if (L != NULL) {
		current = L;
		while (current != NULL && current->info.ID_Barang != search.ID_Barang) current = current->next;
		return current;
	}
	else return NULL;
}

// CHILD
infotype_child newDataChild(string ID_Supplier, string ID_Barang, string Alamat, string Barang_Supply, int No_Telp, int Harga_Supplier){
  infotype_child dataChild;
  dataChild.ID_Supplier = ID_Supplier;
  dataChild.ID_Barang = ID_Barang;
  dataChild.Alamat = Alamat;
  dataChild.Barang_Supply = Barang_Supply;
  dataChild.No_Telp = No_Telp;
  dataChild.Harga_Supplier = Harga_Supplier;

  return dataChild;
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

// Relasi
address_relasi ChildAlokasiRelasi(address_child C) {
  address_relasi P = new elmlist_relasi;
  info(P) = C;
  next(P) = NULL;
  return P;
}
void insertFirst(List_relasi &L, address_relasi P) {
  next(P) = first(L);
  first(L) = P;
}

void printInfo(List_relasi L) {
  address_relasi P = first(L);
  while(P !=NULL) {
      cout<<"->"<< info(info(P)).ID_Supplier<<endl;
      P = next(P);
  }
}

address_relasi findElm(List_relasi L, address_child C) {
  address_relasi P = first(L);
  while(P != NULL) {
      if(info(P)== C) {
          return P;
      }
      P = next(P);
  }
  return NULL;
}

void insertAfter(address_relasi &Prec, address_relasi P) {
  next(P) = next(Prec);
  next(Prec) = P;
}

void Menu_Main(){
  system("cls");
  cout << "============MAIN============" << endl;
  cout << "1. Barang" << endl;
  cout << "2. Supplier" << endl;
  cout << "3. EXIT" << endl;
  cout << "=============================" << endl;
  cout << endl;
}

void Menu_Barang(){
  system("cls");
  cout << "============Menu Barang============" << endl;
  cout << "1. Input Data Barang" << endl;
  cout << "2. Delete Data Barang" << endl;
  cout << "3. Search Barang" << endl;
  cout << "4. Show Data" << endl;
  cout << "5. Menu Utama" << endl;
  cout << "6. EXIT" << endl;
  cout << "===================================" << endl;
  cout << endl;
}
void Menu_Supplier(){
  system("cls");
  cout << "============Menu Supplier============" << endl;
  cout << "1. Input Data Supplier" << endl;
  cout << "2. Delete Data Supplier" << endl;
  cout << "3. Search Data Supplier" << endl;
  cout << "4. Show Data" << endl;
  cout << "5. Menu Utama" << endl;
  cout << "6. EXIT" << endl;
  cout << "=====================================" << endl;
  cout << endl;
}
