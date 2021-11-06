#include "CongTy.h"
int main()
{
    NhanVien::FileIn.open("INPUT.txt", ios_base::in);
    CongTy *x = new CongTy;
    x->InPut();
    NhanVien::FileIn.close();
    NhanVien::FileOut.open("OUTPUT.txt", ios_base::out);
    x->OutPut();
    NhanVien::FileOut.close();
    delete x;
    system("pause");
    return 0;
}