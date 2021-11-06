#include "NVQuanLy.h"
#include "CongTy.h"
int main()
{
    NVQuanLy::FileIn.open("INPUT.txt", ios_base::in);
    NVQuanLy *x = new NVQuanLy;
    x->InPut();
    NVQuanLy::FileIn.close();
    NVQuanLy::FileOut.open("OUTPUT.txt", ios_base::out);
    x->OutPut();
    NVQuanLy::FileOut.close();
    delete x;
    NhanVien::FileIn.open("INPUT1.txt", ios_base::in);
    CongTy *y = new CongTy;
    y->InPut();
    NhanVien::FileIn.close();
    NhanVien::FileOut.open("OUTPUT1.txt", ios_base::out);
    x->OutPut();
    NhanVien::FileOut.close();
    delete x;
    return 0;
}