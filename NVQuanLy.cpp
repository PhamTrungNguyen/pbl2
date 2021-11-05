#include "NVQuanLy.h"
void NVQuanLy::InPut()
{
    NhanVien::InPut();
    NhanVien::FileIn >> HeSoLuong;
    NhanVien::FileIn.seekg(1, ios_base::cur);
    NhanVien::FileIn >> LuongCanBan;
}
void NVQuanLy::OutPut()
{
    NhanVien::OutPut();
    NhanVien::FileOut << "He so luong: " << HeSoLuong << endl;
    NhanVien::FileOut << "Luong can bang: " << LuongCanBan << endl;
    NhanVien::FileOut << " => " << TinhLuong() << endl;
}
float NVQuanLy::TinhLuong()
{
    return (HeSoLuong * LuongCanBan);
}