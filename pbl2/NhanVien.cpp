#include "NhanVien.h"
ifstream NhanVien::FileIn;
ofstream NhanVien::FileOut;
void NhanVien::InPut()
{
    getline(FileIn, this->Name, ',');
    FileIn.seekg(1, ios_base::cur);
    getline(FileIn, this->MSNV, ',');
    FileIn.seekg(1, ios_base::cur);
    getline(FileIn, this->CMND, ',');
    FileIn.seekg(1, ios_base::cur);
    getline(FileIn, this->Address, ',');
    FileIn.seekg(1, ios_base::cur);
    getline(FileIn, this->Gender, ',');
    FileIn.seekg(1, ios_base::cur);
    getline(FileIn, this->Date, ',');
    FileIn.seekg(1, ios_base::cur);
    FileIn >> SDT;
    FileIn.seekg(2, ios_base::cur);
}
void NhanVien::OutPut()
{
    FileOut << "Name: " << this->Name << endl;
    FileOut << "MSNV: " << this->MSNV << endl;
    FileOut << "CMND: " << this->CMND << endl;
    FileOut << "Address: " << this->Address << endl;
    FileOut << "Gender: " << this->Gender << endl;
    FileOut << "Date: " << this->Date << endl;
    FileOut << "So dien thoai: 0" << (size_t)this->SDT << endl;
}
int NhanVien::TinhLuong()
{
    return 0;
}
string NhanVien::Get_MSNV() {
    return this->MSNV;
}