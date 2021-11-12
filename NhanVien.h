#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class NhanVien
{
protected:
    string Name;
    string MSNV;
    int CMND;
    string Address;
    string Gender;
    string Date;
    double SDT;
public:
    virtual void DocFile(fstream&);
    virtual void XuatFile(fstream&);
    virtual void InPut();
    virtual void OutPut();
    virtual int TinhLuong();
    string Get_MSNV();
    void Set_SDT(double);
};
