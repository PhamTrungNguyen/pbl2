#include "CongTy.h"
void CongTy::InPut()
{
    while (!NhanVien::FileIn.eof())
    {
        char a;
        NhanVien::FileIn >> a;
        NhanVien::FileIn.seekg(2, ios_base::cur);
        NhanVien *x;
        if (a == '1')
        {
            x = new NVQuanLy;
            x->InPut();
            list.push_back(x);
        }
        else if (a == '2')
        {
            x = new NVCongNhat;
            x->InPut();
            list.push_back(x);
        }
        else if (a == '3')
        {
            x = new NVSanXuat;
            x->InPut();
            list.push_back(x);
        }
        else if (a == '4')
        {
            x = new NVThucTap;
            x->InPut();
            list.push_back(x);
        }
    }
}
void CongTy::OutPut()
{
    for (int i = 0; i < list.Size(); i++)
    {
        NhanVien::FileOut << "Thong tin cua nhan vien thu " << i + 1 << endl;

        list[i]->OutPut();
    }
}
float CongTy::TinhLuong()
{
    float Luong = 0;
    for (int i = 0; i < list.Size(); i++)
    {
        Luong += list[i]->TinhLuong();
    }
    return Luong;
<<<<<<< HEAD:.history/CongTy _20211106121849.cpp
}
=======
}
>>>>>>> ac7b89e2210df5145628f13dfbc0323c429f674f:CongTy/CongTy.cpp
