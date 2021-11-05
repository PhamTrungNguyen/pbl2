#pragma once
#include "NhanVien.h"
class NVQuanLy : public NhanVien
{
private:
    double HeSoLuong, LuongCanBan;

public:
    void InPut();
    void OutPut();
    float TinhLuong();
};
