#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct Pemesanan{
	char kode[10];
	char namaMaskapai[30];
	char BandaraA[30];
	char BandaraT[30];
	int tanggalP;
	int jamP;
	int jamK;
	int harga;
;};

void bacaFile(){
	int jumlahData = 0;
	for(int i = 0; i<jumlahData; i++){
		cout<<"Masukkan kode penerbangan ["<<i<<"]";
		cin>>Pemesanan[i].kode;
		cout<<"Masukkan nama Maskapai :";
		cin>>Pemesanan[i].namaMaskapai;
		cout<<"Masukkan bandara asal :";
		cin>>Pemesanan[i].BandaraA;
		cout<<"Masukkan Bandara tujuan :";
		cin>>Pemesanan[i].BandaraT;
		cout<<"Masukkan Tanggal Penerbangan :";
		cin>>Pemesanan[i].tanggalP
		cout<<"Masukkan Jam Keberangkatan : ";
		cin>>Pemesanan[i].jamP;
		cout<<"Masukkan Jam kedatangan :";
		cin>>Pemesanan[i].jamK;
		cout<<"MAsukkan harga :";
		cin>>harga;
}

void bacaFile(){
	ifstream file("file.txt");
		file >> pemesanan;
		if(file.is_open()){
			for(int i = 0; i<jumlahDAta; i++){
				cin>>Pemesanan[i].kode>>Pemesanan[i].namaMaskapai>>Pemesanan[i].BandaraA>>Pemesanan[i].BandaraT>>Pemesanan[i].tanggalP>>Pemesanan[i].jamP>>Pemesanan[i].jamK>>Pemesanan[i].harga;
			}
			file.close();
		}
}

void SortingFile(){
	 
}

void menampilkanFIle(){
	
}

int main(){
	int pilihan;
	cout<<"--- Pemesanan Tiket Pesawat ---"<<endl;
	cout<<"1. mencari penerbangan berdasarkan rute penerbangan"<<endl;
	cout<<"2. penerbangan maskapai penerbangan"<<endl;
	cout<<"3. mencari Harga tiket"<<endl;
	cout<<"pilih menu :";
	cin>>pilihan;
	switch(pilihan)	{
		case 1:
			bacaFile();
		case 2:
			
		case 3:
			
	}
}
