#include "NVQuanLy.h"
void NVQuanLy::InPut()
{
    NhanVien::InPut();
    NhanVien::FileIn >> this->Coefficients_salary;
    NhanVien::FileIn.seekg(2, ios_base::cur);
    NhanVien::FileIn >> this->Basic_salary;
}
void NVQuanLy::OutPut()
{
    NhanVien::OutPut();
    NhanVien::FileOut << "Coefficients salary: " << this->Coefficients_salary << endl;
    NhanVien::FileOut << "Basic salary: " << this->Basic_salary << endl;
    NhanVien::FileOut << "Wage => " << TinhLuong() << endl;
}
int NVQuanLy::TinhLuong()
{
    return this->Coefficients_salary * this->Basic_salary;
}