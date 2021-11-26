#include "ChiNhanh.h"
ChiNhanh::ChiNhanh(string n, string a) : name(n), diachi(a)
{

}
ChiNhanh::~ChiNhanh()
{
  
}
bool ChiNhanh::AddNhanVien(NhanVien* t)
{
    for (int i = 0;i < nhanvien.Size();i++)
    {
        if (nhanvien[i]->Get_MSNV() == t->Get_MSNV()) return 0;
    }
    this->nhanvien.push_back(t);
}
bool ChiNhanh::checkid(NhanVien* t)
{
    for (int i = 0;i < nhanvien.Size();i++)
    {
        if (nhanvien[i]->Get_MSNV() == t->Get_MSNV()) return 0;
    }
}
ostream& operator<<(ostream& o,  ChiNhanh& d)
{
    o << "Ten Chi Nhanh:"<<d.name<<", Dia Chi:"<<d.diachi<<endl;
    o << "Danh Sach Nhan Vien cua chi nhanh:"<<endl;
    o << "Ten \t\t" << "MSNV \t" << "CMND \t" << "     Dia Chi" << endl;
    for (int i = 0; i < d.nhanvien.Size(); i++)
    {
        o << d.nhanvien[i]->GetName()<<"   "<< d.nhanvien[i]->Get_MSNV()<<"      "<< d.nhanvien[i]->GetCMND()
            <<"     "<< d.nhanvien[i]->GetAddress();
        o << endl;
    }
    return o;
}