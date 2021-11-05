#include "NVCongNhat.h"
void NVCongNhat::InPut()
{
    NhanVien::InPut();
    NhanVien::FileIn >> SoNgayCong;
}
void NVCongNhat::OutPut()
{
    NhanVien::OutPut();
    NhanVien::FileOut << "So ngay cong: " << SoNgayCong << endl;
    NhanVien::FileOut << " => " << TinhLuong() << endl;
}
float NVCongNhat::TinhLuong()
{
    return SoNgayCong * 100000;
}