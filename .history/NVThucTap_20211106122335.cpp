#include "NVThucTap.h"
void NVThucTap::InPut()
{
    NhanVien::InPut();
    NhanVien::FileIn >> ThoiGianKinhNghiem;
}
void NVThucTap::OutPut()
{
    NhanVien::OutPut();
    NhanVien::FileOut << "Thoi gian kinh nghiem: " << ThoiGianKinhNghiem << endl;
    NhanVien::FileOut << " => " << TinhLuong();
}
float NVThucTap::TinhLuong()
{
    return ThoiGianKinhNghiem * 30000;
}