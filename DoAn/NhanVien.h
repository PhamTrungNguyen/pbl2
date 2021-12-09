#pragma once
#include <iostream>
#include <string>
#include <fstream>
//dt
#include "DaoTao.h"
using namespace std;
//dt
class DaoTao;
class NhanVien
{
protected:
    string Name;
    double MSNV;
    int CMND;
    string Address;
    string Gender;
    string Date;
    double SDT;
    //dt
    List<DaoTao*> daotao;
public:
    virtual void DocFile(fstream&);
    virtual void XuatFile(fstream&);
    virtual void InPut();
    virtual void OutPut();
    virtual int TinhLuong();
    double Get_MSNV();
    void Set_Name(string);
    void Set_MSNV(double);
    void Set_CMND(int);
    void Set_Address(string);
    void Set_Gender(string);
    void Set_Date(string);
    void Set_SDT(double);
    //dt
    friend ostream& operator<<(ostream&, NhanVien&);
    string GetName();
    void AddDaoTao(DaoTao*);
    friend class DaoTao;
    //cn
    int GetCMND();
    string GetAddress();
    double GetSDT();

};