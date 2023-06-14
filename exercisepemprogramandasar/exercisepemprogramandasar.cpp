#include <iostream>
#include <vector>
using namespace std;

class penerbit;
class pengarang {
public:
	string nama;
	vector<penerbit*> daftar_penerbit;
	pengarang(string pNama) :nama(pNama) {
	}
	
	~pengarang() {
	}

	void tambahpenerbit(penerbit*);
	void cetakpenerbit();
};

class penerbit {
public:
	string nama;
	vector<pengarang*> daftar_pengarang;

	penerbit(string pNama) :nama(pNama) {
		
	}
	~penerbit() {
		
	}

	void tambahpengarang(pengarang*);
	void cetakpengarang();
};

class buku {
public:
	string nama;
	vector<pengarang*> daftar_pengarang;

	buku(string pNama) :nama(pNama) {
	}

	~buku() {
	}

	void tambahpengarang(pengarang*);
	void cetakpengarang();
};
void buku::tambahpengarang(pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
}
void buku::cetakpengarang() {
	cout << "Daftar Buku yang dikarang \"" << this->nama << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

void pengarang::tambahpenerbit(penerbit* pPenerbit) {
	daftar_penerbit.push_back(pPenerbit);
}
void pengarang::cetakpenerbit() {
	cout << "Daftar penerbit yang diikuti \"" << this->nama << "\":\n";
	for (auto& a : daftar_penerbit) {
		cout << a->nama << "\n";
	}
	cout << endl;
}
void penerbit::tambahpengarang(pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
	pPengarang->tambahpenerbit(this);
}
void penerbit::cetakpengarang() {
	cout << "Daftar pengarang pada penerbit \"" << this->nama << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

int main() {
	penerbit* varPenerbit1 = new penerbit("Game Press");
	penerbit* varPenerbit2 = new penerbit("Intan Pariwara");
	pengarang* varPengarang1 = new pengarang("Joko");
	pengarang* varPengarang2 = new pengarang("Lia");
	pengarang* varPengarang3 = new pengarang("Asroni");
	pengarang* varPengarang4 = new pengarang("Giga");
	buku* varBuku1 = new buku("Fisika");
	buku* varBuku2 = new buku("Algoritma");
	buku* varBuku3 = new buku("Basisdata");
	buku* varBuku4 = new buku("Dasar Pemprograman");
	buku* varBuku5 = new buku("Matematika");
	buku* varBuku6 = new buku("Multimedia 1");

	varPenerbit1->tambahpengarang(varPengarang1);
	varPenerbit1->tambahpengarang(varPengarang2);
	varPenerbit1->tambahpengarang(varPengarang4);
	varPenerbit2->tambahpengarang(varPengarang3);
	varPenerbit2->tambahpengarang(varPengarang4);

	varPenerbit1->cetakpengarang();
	varPenerbit2->cetakpengarang();
	varPengarang4->cetakpenerbit();

	delete varPengarang4;
	delete varPenerbit1;
	delete varPenerbit2;

	return 0;
}