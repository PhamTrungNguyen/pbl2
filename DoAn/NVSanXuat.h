#pragma once
#include "NhanVien.h"
class NVSanXuat :public NhanVien
{
private:
    int Product_number;
public:
    NVSanXuat();
    void DocFile(fstream&);
    void XuatFile(fstream&);
    void InPut();
    void OutPut();
    int TinhLuong();
};
