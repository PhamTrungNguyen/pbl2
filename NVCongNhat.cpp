#include "NVCongNhat.h"
void NVCongNhat::DocFile(fstream& File) {
	NhanVien::DocFile(File);
	File >> this->Number_of_workdays;
}
void NVCongNhat::XuatFile(fstream& File) {
	NhanVien::XuatFile(File);
	File << "So ngay cong: " << this->Number_of_workdays << endl;
	File << "Luong: " << TinhLuong();
}
void NVCongNhat::InPut() {
	NhanVien::InPut();
	cout << "\nNhap so ngay cong: ";
	cin >> this->Number_of_workdays;
}
void NVCongNhat::OutPut() {
	NhanVien::OutPut();
	cout << "So ngay cong: " << this->Number_of_workdays << endl;
	cout << "Luong: " << TinhLuong();
}
int NVCongNhat::TinhLuong() {
	return this->Number_of_workdays * 100000;
}