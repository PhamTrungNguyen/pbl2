#pragma once
#include "NhanVien.h"
class NVCongNhat : public NhanVien
{
private:
    int Number_of_workdays;

public:
    void InPut();
    void OutPut();
    int TinhLuong();
};

