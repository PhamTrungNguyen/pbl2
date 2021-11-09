#pragma once
#include "NhanVien.h"
class NVThucTap : public NhanVien
{
private:
    int ThoiGianKinhNghiem;

public:
    void InPut();
    void OutPut();
    float TinhLuong();
};