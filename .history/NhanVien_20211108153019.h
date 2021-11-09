#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class NhanVien
{
protected:
    string HoTen, MSSV, CMND, DiaChi, GioiTinh, NgaySinh;
    double SDT;

public:
    static ifstream FileIn;
    static ofstream FileOut;

public:
    virtual void InPut();
    virtual void OutPut();
    virtual float TinhLuong();
    string 
};
