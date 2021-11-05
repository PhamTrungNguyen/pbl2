#pragma once
#include "NhanVien.h"
class NVCongNhat : public NhanVien
{
private:
    int SoNgayCong;

public:
    void InPut();
    void OutPut();
    float TinhLuong();
};