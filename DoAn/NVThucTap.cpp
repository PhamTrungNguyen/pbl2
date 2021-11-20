#include "NVThucTap.h"
void NVThucTap::DocFile(fstream& File) {
	NhanVien::DocFile(File);
	File >> this->Experience_time;
}
void NVThucTap::XuatFile(fstream& File) {
	NhanVien::XuatFile(File);
	File << "Thoi gian kinh nghiem(thang): " << this->Experience_time << endl;
	File << "=>Luong: " << TinhLuong();
}
void NVThucTap::InPut() {
	NhanVien::InPut();
	cout << "\nNhap thoi gian kinh nghiem(thang): ";
	cin >> this->Experience_time;
}
void NVThucTap::OutPut() {
	NhanVien::OutPut();
	cout << "Thoi gian kinh nghiem(thang): " << this->Experience_time << endl;
	cout << "=>Luong: " << TinhLuong();
}
int NVThucTap::TinhLuong() {
	return this->Experience_time * 30000;
}