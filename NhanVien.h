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
    string CMND;
    string Address;
    string Gender;
    string Date;
    double SDT;

public:
    static ifstream FileIn;
    static ofstream FileOut;

public:
    virtual void InPut();
    virtual void OutPut();
    virtual int TinhLuong();
    string Get_MSNV();

};

