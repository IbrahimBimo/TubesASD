#include "list_child.h"

void createList(List_child &L)
/* I.S. Sembarang
   F.S. Terbentuk List Induk Kosong */
{
    first(L) = NULL;
    last(L) = NULL;
}

address_child alokasi(infotype_child x)
/* mengirimkan address dari alokasi sebuah elemen induk
   jika alokasi berhasil maka nilai address tidak nil dan jika gagal nilai address anak Nil */
{
    address_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst(List_child &L, address_child P)
/* I.S. sembarang, P sudah dialokasikan
   F.S. menempatkan elemen beralamat P pada awal list */
{
    if(first(L) == NULL)
    {
        last(L) = P;
        first(L) = P;
    }
    else
    {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List_child &L, address_child P)
/* sembarang, P sudah dialokasikan
   menempatkan elemen beralamat P sesudah elemen beralamat Prec */

{
    if(first(L) == NULL)
    {
        first(L) = P;
        last(L) = P;
    }
    else
    {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}
void deleteFirst(List_child &L,address_child&P)
/* I.S. List tidak kosong
   F.S. adalah alamat dari alamat elemen dari list */

{
    if(first(L)!=NULL)
    {
        P = first(L);

        if(first(L) == L.last)
        {
            L.last = NULL;
            L.first = NULL;
        }
        else
        {
            L.first = P->next;
            L.first->prev = NULL;
            P->next = NULL;
        }
    }
}
void deleteLast(List_child &L, address_child &P)
/* I.S. list tidak kosong
   F.S. adalah alamat dari alamat elemen terakhir list sebelum elemen terakhir list dihapus
        elemen terakhir list hilang dan list mungkin menjadi kosong
        last elemen yang baru adalah alamat elemen sebelum last elemen yang lama */
{
    if(L.first!=NULL)
    {
        P = L.last;

        if(L.first == L.last)
        {
            L.first = NULL;
            L.last = NULL;
        }
        else
        {
            L.last = P->prev;
            L.last->next = NULL;
            P->prev = NULL;
        }
    }
}
void printInfo(List_child L)
/*I.S. list mungkin kosong
  F.S. jika list tidak kososng menampilkan semua info yang ada pada list */

{
    address_child P = first(L);
    while(P !=NULL)
    {
        cout<<"NAMA PELANGGAN        :"<<info(P).nama<<endl;
        cout<<"ID                    :"<<info(P).id<<endl;
        cout<<"ALAMAT                :"<<info(P).alamat<<endl;
        cout<<"TEMPAT TANGGAL LAHIR  :"<<info(P).ttl<<endl;
        cout<<"JENIS KELAMIN         :"<<info(P).jenis_kelamin<<endl;
        cout<<"USIA                  :"<<info(P).umur<<endl;
        P = next(P);
    }
}


address_child findElm(List_child L, infotype_child x)
/* mencari apakah ada elemen list anak dengan info(P)=x
   jika ada mengembalikan address elemen tab, dan nil jika sebaliknya */
{
    address_child P = first(L);
    while(P != NULL)
    {
        if(info(P).id==x.id)
        {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertAfter(address_child Prec, address_child P)
/* I.S. Sembarang, P dan Prec alamat salah satu elemen list
   F.S. menempatkan elemen beralamat P sesudah elemen beralamat Prec */

{
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}

void deleteAfter(address_child Prec, address_child &P)
/* I.S. list tidak kosong, Prec alamat salah satu elemen list
   F.S. P adalah alamat dari next(Prec), menghapus next(Prec) dari list */
{
    P= Prec->next;

    Prec->next = P->next;
    Prec->next->prev = P->prev;

    P->next = NULL;
    P->prev = NULL;
}


void sorting1(List_child L)
/* mengurutkan data */
{
    List_child lc;
    createList(lc);
    infotype_child infoc;

    address_child P = first (L);
    address_child Q;
    while(P !=NULL)
    {
        infoc.nama=info(P).nama;
        infoc.id=info(P).id;
        infoc.alamat=info(P).alamat;
        infoc.ttl=info(P).ttl;
        infoc.jenis_kelamin=info(P).jenis_kelamin;
        infoc.umur=info (P).umur;

        Q = alokasi(infoc);
        ascendingumur(lc,Q);

        P = next(P);

    }
    ;
    printInfo(lc);


}
void ascending1(List_child &L, address_child P)
/* mengurutkan data */
{
    address_child Q=first(L);
    address_child prec=first(L);
    address_child r=findElm(L,info(P));
    if(r==NULL)
    {

        if ((first(L) == NULL) || (info(P).id <info(Q).id))
        {
            insertFirst(L,P);
        }
        else
        {
            Q = next(Q);

            while (Q !=NULL)
            {
                if (info(P).id> info(Q).id)
                {

                    prec =next(prec);
                }
                Q= next(Q);
            }
            if (next(prec) !=NULL)
            {
                insertAfter(prec,P);
            }
            else
            {
                insertLast(L,P);
            }


        }
    }
    else
    {
        cout<< "ID Sudah Dipakai" <<endl;
    }

}


void ascendingumur(List_child &L, address_child P)
/* mengurutkan data */
{
    address_child Q=first(L);
    address_child prec=first(L);

    if ((first(L) == NULL) || (info(P).umur <info(Q).umur))
    {
        insertFirst(L,P);
    }
    else
    {
        Q = next(Q);

        while (Q !=NULL)
        {
            if (info(P).umur> info(Q).umur)
            {

                prec =next(prec);
            }
            Q= next(Q);
        }
        if (next(prec) !=NULL)
        {
            insertAfter(prec,P);
        }
        else
        {
            insertLast(L,P);
        }
    }
}

void rataumur(List_child L)
/* mengurutkan rata-rata */
{
    address_child P = first(L);
    int jumlah=0;
    double rata = 0;
    int i = 0;

    if (P != NULL)
    {
        while (P != NULL)
        {
            i++;
            jumlah = jumlah + info(P).umur;
            P = next(P);
        };

    }
    rata = jumlah/i;
    cout << rata << endl;
}





