#include "NVThucTap.h"
void NVThucTap::InPut()
{
    NhanVien::InPut();
    NhanVien::FileIn >> this->Experience_time;
}
void NVThucTap::OutPut()
{
    NhanVien::OutPut();
    NhanVien::FileOut << "Experience time: " << this->Experience_time << endl;
NhanVien:
    FileOut << "Wage => " << TinhLuong() << endl;
}
int NVThucTap::TinhLuong()
{
    return this->Experience_time * 30000;
}