#include "NVQuanLy.h"

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
    return 0;
}