#include "supermarket.h"

int main() {
  List_parent LParent;
  List_child LChild;
  address_parent adrParent, alokasiParent;
  address_child adrChild, alokasiChild;
  infotype_parent barang, dataParent;
  infotype_child supplier, dataChild;

  ParentcreateList(LParent);
  ChildcreateList(LChild);

  string x;
  int n, menu, MenuBarang, MenuSupplier;

      cout<<"\n"
    "=========================ʕ•́ᴥ•̀ʔ TUGAS BESAR STRUKTUR DATA ʕ•́ᴥ•̀ʔ=========================\n"
    "\n"
    "                     =========================================\n"
    "                     =                                       =\n"
    "                     =          > KELOMPOK API <             =\n"
    "                     =                                       =\n"
    "                     =    Benaya Obed Sinaga - 1301213264    =\n"
    "                     =    Velman Noeli Harefa - 1301213178   =\n"
    "                     =                                       =\n"
    "                     =========================================\n"
    "\n";
    cout<<"\n                         TEKAN ENTER UNTUK MELANJUTKAN\n";
    getchar();

  label:
  Menu_Main();
  cout << "Masukan Menu: ";
  cin >> menu;
  while(menu != 0){
    cout << endl;
    //cin >> menu;
    switch(menu){
      case 1:
                    // Membuka Menu Barang
                    Menu_Barang();
                    cout << "Masukan Menu: ";
                    cin >> MenuBarang;
                    while (MenuBarang != 0){
                      switch (MenuBarang){
                        case 1:
                          //Input data Barang
                          cout << "Banyak Data Yang Di Input : ";
                          cin >> n;

                          for (int i = 1; i <= n; i++){
                            cout << "INPUT DATA BARANG" << endl;
                            cout << "=========================" << endl;
                            cout << "1. ID Barang : ";
                            cin >> barang.ID_Barang;
                            cout << "2. Nama Barang : ";
                            cin >> barang.Nama_Barang;
                            cout << "3. Jenis Barang : ";
                            cin >> barang.Jenis_Barang;
                            cout << "4. Jumlah Barang : ";
                            cin >> barang.Jumlah_Barang;
                            cout << "5. Harga Jual Barang : ";
                            cin >> barang.Harga_Jual;
                            cout << "6. Data Supplier Barang : ";
                            cin >> barang.ID_Supplier;
                            cout << "=========================" << endl;

                            dataParent = newDataParent(barang.ID_Barang, barang.Nama_Barang, barang.Jenis_Barang, barang.ID_Supplier, barang.Jumlah_Barang, barang.Harga_Jual);
                            alokasiParent = Parentalokasi(dataParent);
                            ParentinsertFirst(LParent, alokasiParent);
                          }
                          cout << "Kembali ke menu utama? (Y/N) :";
                          cin >> x;
                          while (x != "Y"){
                            if (x != "Y"){
                              cout << "Sudah Menginput Data" << endl;
                            }
                            cout << "Kembali Ke Menu Utama? (Y/N):";
                            cin >> x;
                          }
                          break;

                        case 2:
                          //Delete Data Barang
                          break;

                        case 3:
                          //Search Barang
                          cout << "=========================" << endl;
                          cout << "Masukan ID Barang :";
                          cin >> barang.ID_Barang;
                          cout << "=========================" << endl;
                          ParentfindElm(LParent, barang);
                          break;

                        case 4:
                          //Show Data Barang
                          cout << "=========================" << endl;
                          ParentprintInfo(LParent);
                          cout << "=========================" << endl;
                          break;

                        case 5:
                          //Balik Ke Menu Utama
                          goto label;
                          break;

                        case 6:
                          //Keluar dari Program
                          exit(0);
                      }
                      Menu_Barang();
                      cout << "Masukan Menu: ";
                      cin >> MenuBarang;
                    }
                    break;

      case 2:
                        //Membuka Menu Supplier
                        Menu_Supplier();
                        cout << "Masukan Menu :";
                        cin >> MenuSupplier;
                        while (MenuSupplier != 0){
                          switch(MenuSupplier){
                            case 1:
                              //imput data Supplier
                              cout << "Banyak Data Yang Di Input : ";
                              cin >> n;

                              for (int i = 1; i <= n; i++){
                                cout << "INPUT DATA SUPPLIER" << endl;
                                cout << "=========================" << endl;
                                cout << "1. ID Supplier : ";
                                cin >> supplier.ID_Supplier;
                                cout << "2. ID Barang : ";
                                cin >> supplier.ID_Barang;
                                cout << "3. Alamat Supplier : ";
                                cin >> supplier.Alamat;
                                cout << "4. No Telp. : ";
                                cin >> supplier.No_Telp;
                                cout << "5. Barang Supply : ";
                                cin >> supplier.Barang_Supply;
                                cout << "6. Harga Jual Supplier : ";
                                cin >> supplier.Harga_Supplier;
                                cout << "=========================" << endl;

                                dataChild = newDataChild(supplier.ID_Supplier, supplier.ID_Barang, supplier.Alamat, supplier.Barang_Supply, supplier.No_Telp, supplier.Harga_Supplier);

                                alokasiChild = Childalokasi(dataChild);
                                ChildinsertFirst(LChild, alokasiChild);
                              }
                              cout << "Kembali ke menu utama? (Y/N) :";
                              cin >> x;
                              while (x != "Y"){
                                if (x != "Y"){
                                  cout << "Sudah Menginput Data" << endl;
                                }
                                cout << "Kembali Ke Menu Utama? (Y/N):";
                                cin >> x;
                              }
                              break;

                            case 2:
                              //delete suppliero
                              break;

                            case 3:
                              //search data supplier
                              cout << "=========================" << endl;
                              cout << "Masukan ID Supplier :";
                              cin >> supplier.ID_Supplier;
                              cout << "=========================" << endl;
                              ChildfindElm(LChild, supplier);
                              break;
                            case 4:
                              //Show data
                              cout << "=========================" << endl;
                              ChildprintInfo(LChild);
                              cout << "=========================" << endl;
                              break;
                            case 5:
                              //Menu Utama
                              goto label;
                              break;
                            case 6:
                              //Keluar
                              exit(0);

                          Menu_Supplier();
                          cout << "Masukan Menu :";
                          cin >> MenuSupplier;
                          break;
                          }
                        }

      case 3:
        exit(0);
        break;
    }
    return 0;
  }
}
