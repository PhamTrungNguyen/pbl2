#include "NhanVien.h"
#include "DaoTao.h"
DaoTao::DaoTao(string d) :CoSo(d)
{

}

bool DaoTao::AddNhanVien(NhanVien* n)
{
    for (int i = 0;i < nhanvien.Size();i++)
    {
        if (nhanvien[i]->Get_MSNV() == n->Get_MSNV()) return 0;
    }
    this->nhanvien.push_back(n);
    n->AddDaoTao(this);
    
    
}
string DaoTao::GetCoSo()
{
    return this->CoSo;
}
string DaoTao::GetBDT()
{
    return this->Bangdt;
}
ostream& operator<<(ostream& o, DaoTao& d)
{
    if (d.nhanvien.Size() == 0) {
        o << d.CoSo << " Khong co nhan vien nao.\n";
    }
    else
    {
          cout << "------------------------\n";
          cout << "|MSNV \tTen nhan vien  |\n";
        for (int i = 0;i < d.nhanvien.Size();i++)
        {
            o  <<"|" << d.nhanvien[i]->Get_MSNV() << "\t" << d.nhanvien[i]->GetName() << "  |\n";
            cout << "------------------------\n";
        }
        o << endl;
    }
    return o;

}