#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;
#include "list_child.h"
#include "list_parent.h"

int main()
{
    List_child lc;
    createList(lc);
    List_parent lp;
    createList(lp);
    infotype_parent infop;
    infotype_child infoc;
    int pilihan;
    int biaya_spp, nem, nisn;
    string nama_sekolah,jenis,akreditasi,alamat,alamatm,nama,tempat,tanggal_lahir,jenis_kelamin;

    do
    {
        system("cls");
        cout<<"Jasa Berlangganan Provider Televisi : "<<endl;
        cout<<" "<<endl;
        cout<<"1. Masukkan Data Provider "<<endl;
        cout<<"2. Masukkan Data Pelanggan"<<endl;
        cout<<"3. Tambah Data Pelanggan"<<endl;
        cout<<"4. Cari Data Provider"<<endl;
        cout<<"5. Cari Data Pelanggan"<<endl;
        cout<<"6. Delete Data Provider"<<endl;
        cout<<"7. Lihat Semua Data"<<endl;
        cout<<"8.Report Provider"<<endl;
        cout<<"9.Report Pelanggan"<<endl;
        cout<<"10.Keluar"<<endl;
        cout<<"Pilihan : ";
        cin>>pilihan;
        if(pilihan==1)
        {
            cout<<"Masukkan Data Provider"<<endl;
            cout<<"No. Registrasi    :";
            cin>> infop.no_registrasi;
            cout<<"Nama Provider     :";
            cin>> infop.nama;
            cout<<"Jenis Layanan     :";
            cin>>infop.jenis;
            cout<<"Kelas             :";
            cin>>infop.kelas;
            cout<<"Alamat            :";
            cin>>infop.alamat;
            cout<<"Harga             :";
            cin>>infop.harga;


            address_parent p = alokasi(infop);
            ascending(lp,p);
            getch();
        }
        else if(pilihan==2)
        {
            cout<<"Masukkan Data Pelanggan"<<endl;
            cout<<"Nama Pelanggan         :";
            cin>>infoc.nama;
            cout<<"ID                     :";
            cin>>infoc.id;
            cout<<"Alamat                 :";
            cin>>infoc.alamat;
            cout<<"Tempat Tanggal Lahir   :";
            cin>>infoc.ttl;
            cout<<"Jenis Kelamin          :";
            cin>>infoc.jenis_kelamin;
            cout<<"Usia                   :";
            cin>>infoc.umur;

            address_child c = alokasi(infoc);
            ascending1(lc,c);
            getch();
        }
        else if(pilihan==3)
        {
            cout<<"Tambah Pelanggan"<<endl;
            cout<<"ID Pelanggan   :";
            cin>> infoc.id;
            cout<<"No. Registrasi :";
            cin>> infop.no_registrasi;
            address_parent p= findElm(lp, infop);
            address_child c=findElm(lc,infoc);
            if(p!=NULL && c!=NULL)
            {
                address_relasi r = alokasi(c);
                insertFirst(p->child,r);
            }
            else
            {
                cout<<"Not Found"<<endl;
            }

            getch();
        }
        else if(pilihan==4)
        {
            cout<<"Cari Data Provider        :"<<endl;
            cout<<"Masukkan No. Registrasi   :";
            cin>> infop.no_registrasi;

            address_parent p= findElm(lp, infop);
            if(p!=NULL )
            {
                cout<<"No. Regisrtasi    :"<<infop.no_registrasi<< endl;
                cout<<"Nama Provider     :"<<infop.nama<<endl;
                cout<<"Jenis             :"<<infop.jenis<<endl;
                cout<<"Kelas             :"<<infop.kelas<<endl;
                cout<<"Harga             :"<<infop.harga<<endl;
                cout<<"Alamat            :"<<infop.alamat<<endl;


            }
            else
            {
                cout<<"Provider Tidak Ditemukan"<<endl;
            }

            getch();
        }

        else if(pilihan==5)
        {
            cout<<"Cari Data Pelanggan         :"<<endl;
            cout<<"Masukkan ID Pelanggan       :";
            cin>> infoc.id;

            address_child c= findElm(lc, infoc);
            if(c!=NULL )
            {
                cout<<"Nama                 :"<<infoc.nama <<endl;
                cout<<"ID                   :"<<infoc.id <<endl;
                cout<<"Alamat               :"<<infoc.alamat <<endl;
                cout<<"Tempat Tanggal Lahir :"<<infoc.ttl<<endl;
                cout<<"Jenis Kelamin        :"<<infoc.jenis_kelamin <<endl;
                cout<<"Usia                 :"<<infoc.umur <<endl;
            }
            else
            {
                cout<<"Data Pelanggan Tidak Ditemukan"<<endl;
            }

            getch();
        }

        else if(pilihan==6)
        {
            cout<<"Delete Data"<<endl;
            {
                createList(lp);
                createList(lc);
            }

            cout<<"Data Sudah di Hapus"<<endl;

            getch();
        }
        else if(pilihan==7)
        {
            cout<<" Lihat Semua Data"<<endl;
            {
                printInfo(lp);
                printInfo(lc);
            }


            getch();
        }

        else if(pilihan==8)
        {
            cout<<"Rata-Rata Harga"<<endl;
            rataharga(lp);

            getch();
        }
        else if(pilihan==9)
        {
            cout<<"Rata-Rata Usia"<<endl;
            rataumur(lc);

            getch();
        }
        else if(pilihan==10)
        {
            cout<<"Terima Kasih :)";
            getch();
        }
        else
        {
            cout<<"Menu Tidak Tersedia"<<endl;
            getch();
        }
    }
    while(pilihan!=10);
}
