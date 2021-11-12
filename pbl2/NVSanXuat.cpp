#include "NVSanXuat.h"
NVSanXuat::NVSanXuat() {

}
void NVSanXuat::DocFile(fstream& File) {
	NhanVien::DocFile(File);
	File >> this->Product_number;
}
void NVSanXuat::XuatFile(fstream& File) {
	NhanVien::XuatFile(File);
	File << "So san pham: " << this->Product_number << endl;
	File << "Luong: " << TinhLuong();
}
void NVSanXuat::InPut() {
	NhanVien::InPut();
	cout << "\nNhap so san pham: ";
	cin >> this->Product_number;
}
void NVSanXuat::OutPut() {
	NhanVien::OutPut();
	cout << "So san pham: " << this->Product_number << endl;
	cout << "Luong: " << TinhLuong();
}
int NVSanXuat::TinhLuong() {
	return this->Product_number * 50000;
}