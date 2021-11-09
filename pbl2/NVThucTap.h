#pragma once
#include "NhanVien.h"
class NVThucTap :public NhanVien
{
private:
    int Experience_time;

public:
    void InPut();
    void OutPut();
    int TinhLuong();
};

