#pragma once
#include "NhanVien.h"
class NVSanXuat : public NhanVien
{
private:
    int SoSanPham;

public:
    void InPut();
    void OutPut();
    float TinhLuong();
};