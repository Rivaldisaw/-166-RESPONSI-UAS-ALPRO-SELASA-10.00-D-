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
};


int jumlahData = 0;

void bacaFile(){
	ifstream file("file.txt");
		if(file.is_open()){
			for(int i = 0; i<jumlahData; i++){
				cin>>Pemesanan[i].kode>>Pemesanan[i].namaMaskapai>>Pemesanan[i].BandaraA>>Pemesanan[i].BandaraT>>Pemesanan[i].tanggalP>>Pemesanan[i].jamP>>Pemesanan[i].jamK>>Pemesanan[i].harga;
			}
			file.close();
		}
}

void inputFile(){
	
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
