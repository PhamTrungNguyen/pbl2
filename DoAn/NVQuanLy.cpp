#include "NVQuanLy.h"
void NVQuanLy::DocFile(fstream& File) {
	NhanVien::DocFile(File);
	File >> this->Coefficients_salary;
	File.seekg(2, SEEK_CUR);
	File >> this->Basic_salary;
}
void NVQuanLy::XuatFile(fstream& File) {
	NhanVien::XuatFile(File);
	File << "Coefficients salary: " << this->Coefficients_salary << endl; // hệ số lương
	File << "Basic salary: " << this->Basic_salary << endl; // lương căn bảng
	File << "Wage => " << TinhLuong() << endl;

}
void NVQuanLy::InPut() {
	NhanVien::InPut();
	cout << "\nNhap he so luong: ";
	cin >> this->Coefficients_salary;
	cout << "\nNhap luong can ban: ";
	cin >> this->Basic_salary;
}
void NVQuanLy::OutPut() {
	NhanVien::OutPut();
	cout << "He so luong: " << this->Coefficients_salary << endl;
	cout << "Luong can ban: " << this->Basic_salary << endl;
	cout << "Luong: " << TinhLuong();
}
int NVQuanLy::TinhLuong() {
	return this->Coefficients_salary * this->Basic_salary;
}