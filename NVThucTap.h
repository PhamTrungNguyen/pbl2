#pragma once
#include "NhanVien.h"
class NVThucTap :public NhanVien
{
private:
    int Experience_time;
public:
    void DocFile(fstream&);
    void XuatFile(fstream&);
    void InPut();
    void OutPut();
    int TinhLuong();
};
