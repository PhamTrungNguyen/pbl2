#pragma once
#include "NhanVien.h"
class NVCongNhat :public NhanVien
{
private:
    int Number_of_workdays;
public:
    void DocFile(fstream&);
    void XuatFile(fstream&);
    void InPut();
    void OutPut();
    int TinhLuong();
};
