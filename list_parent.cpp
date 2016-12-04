#include "list_parent.h"

void createList(List_parent &L)
/* I.S. Sembarang
   F.S. Terbentuk List Induk Kosong */
{
    /**
    * FS : first(L) diset Nil
    */
    first(L) = NULL;
}

address_parent alokasi(infotype_parent x)
/* mengirim address dari alokasi sebuah elemen
   jika alokasi berhasil maka nilai address tidak nil dan jika gagal niali address Nil */
{
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address_parent P;
    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    createList(child(P));
    return P;
}

void insertFirst(List_parent &L, address_parent P)
/* I.S. sembarang, P sudah dialokasikan
   F.S. menempatkan elemen beralamat P pada awal list */
{
    /**
    * IS : List_parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_parent L
    *      next dari last elemen menunjuk ke first elemen
    */
    address_parent Q;
    if(first(L) == NULL)
    {
        first(L) = P;
        next(P) = P;
    }
    else
    {
        Q = first(L);
        while(next(Q) != first(L))
        {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void insertLast(List_parent &L, address_parent P)
/* sembarang, P sudah dialokasikan
   menempatkan elemen beralamat P sesudah elemen beralamat Prec */
{
    if(L.first == NULL)
    {
        L.first = P;
    }
    else
    {
        address_parent q = L.first;
        while(q->next != NULL)
        {
            q=q->next;
        }
        q->next = P;
    }
}

void printInfo(List_parent L)
/*I.S. list mungkin kosong
  F.S. jika list tidak kososng menampilkan semua info yang ada pada list */
{
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    address_parent P = first(L);
    if(first(L)!=NULL)
    {
        do
        {
            cout<<"NO REGISTRASI               :"<<info(P).no_registrasi<<endl;
            cout<<"NAMA PROVIDER               :"<<info(P).nama<<endl;
            cout<<"JENIS                       :"<<info(P).jenis<<endl;
            cout<<"KELAS                       :"<<info(P).kelas<<endl;
            cout<<"HARGA                       :"<<info(P).harga<<endl;
            cout<<"ALAMAT                      :"<<info(P).alamat<<endl;
            printInfo(child(P));
            P = next(P);
        }
        while((P)!=first(L));
    }
}

void deleteFirst(List_parent &L, address_parent &P)
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
void deleteLast(List_parent &L, address_parent &P)
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
            address_parent q=P;
            while(q->next->next != NULL)
            {
                q=q->next;
            }
            P = q->next;
            q->next = NULL;

        }
    }
}
void insertAfter(List_parent &L, address_parent Prec, address_parent P)
/* I.S. Sembarang, P dan Prec alamat salah satu elemen list
   F.S. menempatkan elemen beralamat P sesudah elemen beralamat Prec */
{
    P->next = Prec->next;
    Prec->next = P;
}

void deleteAfter(List_parent &L, address_parent Prec, address_parent &P)
/* I.S. list tidak kosong, Prec alamat salah satu elemen list
   F.S. P adalah alamat dari next(Prec), menghapus next(Prec) dari list */

{
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
}
address_parent findElm(List_parent L, infotype_parent x)
/*mencari apakah ada elemen list dengan info(P) = x
  jika ada mengembalikan address elemen tab, dan Nil jika sebaliknya */

{
    /**
    * IS : List_parent L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */
    address_parent P = first(L);
    if (P != NULL)
    {
        do
        {
            if(info(P).no_registrasi == x.no_registrasi)
            {
                return P;
            }
            P = next(P);
        }
        while(P != first(L));
    }

    return NULL;
}

void sorting(List_parent L)
/* mengurutkan data */
{
    List_parent lp;
    createList(lp);
    infotype_parent infop;

    address_parent P = first (L);
    address_parent Q;
    do
    {
        infop.no_registrasi=info(P).no_registrasi;
        infop.nama=info(P).nama;
        infop.jenis=info(P).jenis;
        infop.kelas=info(P).kelas;
        infop.harga=info(P).harga;
        infop.alamat=info (P).alamat;

        Q = alokasi(infop);
        ascendingharga(lp,Q);

        P = next(P);

    }
    while(P !=first(L));
    printInfo(lp);


}
void ascending(List_parent &L, address_parent P)
/* mengurutkan data */
{
    address_parent Q=first(L);
    address_parent prec=first(L);
    address_parent r=findElm(L,info(P));
    if(r==NULL)
    {

        if ((first(L) == NULL) || (info(P).no_registrasi <info(Q).no_registrasi))
        {
            insertFirst(L,P);
        }
        else
        {
            Q = next(Q);
            while ((info(P).no_registrasi > info(Q).no_registrasi) && (Q !=first(L)))
            {
                Q= next(Q);
                prec =next(prec);
            }
            insertAfter(L,prec,P);
        }
    }
    else
    {
        cout<< "No. Registrasi Sudah Tidak Berlaku" <<endl;
    }

}

void ascendingharga(List_parent &L, address_parent P)
/* mengurutkan data */
{
    address_parent Q=first(L);
    address_parent prec=first(L);

    if ((first(L) == NULL) || (info(P).harga <=info(Q).harga))
    {
        insertFirst(L,P);
    }
    else
    {
        Q = next(Q);
        while ((info(P).harga >= info(Q).harga) && (Q !=first(L)))
        {
            Q= next(Q);
            prec =next(prec);
        }
        insertAfter(L,prec,P);
    }
}

void rataharga (List_parent L)
/* menghitung rata-rata */
{
    address_parent P = first(L);
    int jumlah=0;
    double rata = 0;
    int i = 0;

    if (P != NULL)
    {
        do
        {
            i++;
            jumlah = jumlah + info(P).harga;
            P = next(P);
        }
        while (P != first(L));
    }
    rata = jumlah/i;
    cout << rata << endl;
}




