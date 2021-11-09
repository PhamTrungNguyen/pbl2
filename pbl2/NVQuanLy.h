#pragma once
#include "NhanVien.h"
class NVQuanLy :public NhanVien
{
private:
    double Coefficients_salary;
    double Basic_salary;

public:
    void InPut();
    void OutPut();
    int TinhLuong();
};

