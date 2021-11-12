#include "NhanVien.h"
void NhanVien::DocFile(fstream& File) {
	getline(File, this->Name, ',');
	File.seekg(1, SEEK_CUR);
	getline(File, this->MSNV, ',');
	File.seekg(1, SEEK_CUR);
	File >> this->CMND;
	File.seekg(2, SEEK_CUR);
	getline(File, this->Address, ',');
	File.seekg(1, SEEK_CUR);
	getline(File, this->Gender, ',');
	File.seekg(1, SEEK_CUR);
	getline(File, this->Date, ',');
	File.seekg(1, SEEK_CUR);
	File >> this->SDT;
	File.seekg(2, SEEK_CUR);
}
void NhanVien::XuatFile(fstream& File) {
	File << "Name: " << this->Name << endl;
	File << "MSNV: " << this->MSNV << endl;
	File << "CMND: " << this->CMND << endl;
	File << "Address: " << this->Address << endl;
	File << "Gender: " << this->Gender << endl;
	File << "Date: " << this->Date << endl;
	File << "So dien thoai: 0" << (size_t)this->SDT << endl;
}
void NhanVien::InPut() {
	rewind(stdin);
	cout << "\nNhap ho ten: ";
	getline(cin, this->Name);
	cout << "\nNhap MSNV: ";
	getline(cin, this->MSNV);
	cout << "\nNhap so CMND: ";
	cin >> this->CMND;
	rewind(stdin);
	cout << "\nNhap dia chi: ";
	getline(cin, this->Address);
	cout << "\nNhap gioi tinh: ";
	getline(cin, this->Gender);
	cout << "\nNhap ngay sinh: ";
	getline(cin, this->Date);
	cout << "\nNhap SDT: ";
	cin >> this->SDT;
}
void NhanVien::OutPut() {
	cout << "Ho ten: " << this->Name << endl;
	cout << "MSNV: " << this->MSNV << endl;
	cout << "CMND: " << this->CMND << endl;
	cout << "Dia chi: " << this->Address << endl;
	cout << "Gioi tinh: " << this->Gender << endl;
	cout << "Ngay sinh: " << this->Date << endl;
	cout << "SDT: " << this->SDT << endl;
}
int NhanVien::TinhLuong() {
	return 0;
}
string NhanVien::Get_MSNV() {
	return this->MSNV;
}
void NhanVien::Set_SDT(double value) {
	this->SDT = value;
}