#pragma once
#include "NhanVien.h"
class NVSanXuat : public NhanVien
{
private:
    int Product_number;

public:
    void InPut();
    void OutPut();
    int TinhLuong();
};
