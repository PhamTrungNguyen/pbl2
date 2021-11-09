#include "NVSanXuat.h"
void NVSanXuat::InPut()
{
    NhanVien::InPut();
    NhanVien::FileIn >> this->Product_number;
}
void NVSanXuat::OutPut()
{
    NhanVien::OutPut();
    NhanVien::FileOut << "Product number: " << this->Product_number << endl;
    NhanVien::FileOut << "Wage => " << TinhLuong() << endl;
}
int NVSanXuat::TinhLuong()
{
    return this->Product_number * 50000;
}