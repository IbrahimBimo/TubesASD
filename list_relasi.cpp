#include "list_relasi.h"

void createList(List_relasi &L)
/* I.S. Sembarang
   F.S. Terbentuk List Induk Kosong */
{
    first(L) = NULL;
}

address_relasi alokasi(address_child C)
/* mengirim address dari alokasi sebuah elemen
   jika alokasi berhasil maka nilai address tidak nil dan jika gagal niali address Nil */
{
    address_relasi P = new elmlist_relasi;
    info(P) = C;
    next(P) = NULL;
    return P;
}

void insertFirst(List_relasi &L, address_relasi P)
/* I.S. sembarang, P sudah dialokasikan
   F.S. menempatkan elemen beralamat P pada awal list */
{
    next(P) = first(L);
    first(L) = P;
}

void insertLast(List_relasi &L, address_relasi P)
/* sembarang, P sudah dialokasikan
   menempatkan elemen beralamat P sesudah elemen beralamat Prec */

{
    if(L.first == NULL)
    {
        L.first = P;
    }
    else
    {
        address_relasi q = L.first;
        while(q->next != NULL)
        {
            q=q->next;
        }
        q->next = P;
    }
}

void deleteFirst(List_relasi &L, address_relasi &P)
/* I.S. List tidak kosong
   F.S. adalah alamat dari alamat elemen dari list */
{
    if(L.first == NULL)
    {
        // isi pesan dalam kutip
        //cout << "List Telah Kosong. Tidak ada elemen yang dapat dihapus"<<endl;
    }
    else
    {
        P = L.first;
        L.first = P->next;
        P->next = NULL;

    }
}
void deleteLast(List_relasi &L, address_relasi &P)
/* I.S. list tidak kosong
   F.S. adalah alamat dari alamat elemen terakhir list sebelum elemen terakhir list dihapus
        elemen terakhir list hilang dan list mungkin menjadi kosong
        last elemen yang baru adalah alamat elemen sebelum last elemen yang lama */
{
    if(L.first == NULL)
    {
        // isi pesan dalam kutip
        //cout << "List Telah Kosong. Tidak ada elemen yang dapat dihapus"<<endl;
    }
    else
    {
        P=L.first;
        if(P->next == NULL)
        {
            L.first = NULL;

        }
        else
        {
            address_relasi q=P;
            while(q->next->next != NULL)
            {
                q=q->next;
            }
            P = q->next;
            q->next = NULL;

        }
    }
}

void printInfo(List_relasi L)
/*I.S. list mungkin kosong
  F.S. jika list tidak kososng menampilkan semua info yang ada pada list */
{
    address_relasi P = first(L);
    if ( P == NULL )
    {
        cout << "Tidak Ada Pelanggan" << endl << endl;
    }
    else
    {
      while(P !=NULL)
      {
          cout<<"ID Pelanggan             :"<<info(info(P)).id<<endl;
        P = next(P);
      }
    }

}


address_relasi findElm(List_relasi L, address_child C)
/*mencari apakah ada elemen list dengan info(P) = x
  jika ada mengembalikan address elemen tab, dan Nil jika sebaliknya */

{
    address_relasi P = first(L);
    while(P != NULL)
    {
        if(info(P)== C)
        {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertAfter(address_relasi &Prec, address_relasi P)
/* I.S. Sembarang, P dan Prec alamat salah satu elemen list
   F.S. menempatkan elemen beralamat P sesudah elemen beralamat Prec */
{
    next(P) = next(Prec);
    next(Prec) = P;
}

void deleteAfter(address_relasi Prec, address_relasi &P)
/* I.S. list tidak kosong, Prec alamat salah satu elemen list
   F.S. P adalah alamat dari next(Prec), menghapus next(Prec) dari list */
{
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;

}
