#include "NVSanXuat.h"
void NVSanXuat::InPut()
{
    NhanVien::InPut();
    NhanVien::FileIn >> SoSanPham;
}
void NVSanXuat::OutPut()
{
    NhanVien::OutPut();
    NhanVien::FileOut << "So san pham: " << SoSanPham;
    NhanVien::FileOut << " => " << TinhLuong();
}
float NVSanXuat::TinhLuong()
{
    return SoSanPham * 50000;
}