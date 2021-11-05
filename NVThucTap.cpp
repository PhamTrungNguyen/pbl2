#include "NVThucTap.h"
void NVThucTap::InPut()
{
    NhanVien::InPut();
    NhanVien::FileIn >> ThoiGianKinhNghiem;
}
void NVThucTap::OutPut()
{
    NhanVien::OutPut();
    NhanVien::FileOut << "Thoi gian kinh nghiem: " << ThoiGianKinhNghiem;
}
float NVThucTap::TinhLuong()
{
    return ThoiGianKinhNghiem * 30000;
}