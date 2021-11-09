#include "NVCongNhat.h"
void NVCongNhat::InPut()
{
    NhanVien::InPut();
    NhanVien::FileIn >> this->Number_of_workdays;
}
void NVCongNhat::OutPut()
{
    NhanVien::OutPut();
    NhanVien::FileOut << "Number of workdays: " << this->Number_of_workdays << endl;
    NhanVien::FileOut << "Wage => " << TinhLuong() << endl;
}
int NVCongNhat::TinhLuong()
{
    return this->Number_of_workdays * 100000;
}