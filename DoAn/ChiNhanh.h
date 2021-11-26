#pragma once
#include <iostream>
#include "NhanVien.h"   
using namespace std;
class ChiNhanh
{
private:
    List<NhanVien*> nhanvien;
    string name;
    string diachi;
public:
    ChiNhanh(string = " ", string = " ");
    ~ChiNhanh();
    bool AddNhanVien(NhanVien*);
    bool checkid(NhanVien*);
    friend ostream& operator<<(ostream&,  ChiNhanh&);
};

