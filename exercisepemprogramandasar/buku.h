#ifndef BUKU_H
#define BUKU_H

class buku {
public:
	string nama;
	vector<pengarang*> daftar_pengarang;

	buku(string pNama) :nama(pNama) {
	}

	~buku() {
	}

	void (tambahpengarang*);
	void cetakAnak();
};
void ibu::tambahAnak(anak* pAnak) {
	daftar_anak.push_back(pAnak);
}
void ibu::cetakAnak() {
	cout << "Daftar Anak dari Ibu \"" << this->nama << "\":\n";
	for (auto& a : daftar_anak) {
		cout << a->nama << "\n";
	}
	cout << endl;
}