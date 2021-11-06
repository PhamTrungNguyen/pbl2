#include "NhanVien.h"
ifstream NhanVien::FileIn;
ofstream NhanVien::FileOut;
void NhanVien::InPut()
{
    getline(FileIn, HoTen, ',');
    FileIn.seekg(1, ios_base::cur);
    getline(FileIn, MSSV, ',');
    FileIn.seekg(1, ios_base::cur);
    getline(FileIn, CMND, ',');
    FileIn.seekg(1, ios_base::cur);
    getline(FileIn, DiaChi, ',');
    FileIn.seekg(1, ios_base::cur);
    getline(FileIn, GioiTinh, ',');
    FileIn.seekg(1, ios_base::cur);
    getline(FileIn, NgaySinh, ',');
    FileIn.seekg(1, ios_base::cur);
    FileIn >> SDT;
    FileIn.seekg(2, ios_base::cur);
}
void NhanVien::OutPut()
{
    FileOut << "Ho Ten: " << HoTen << endl;
    FileOut << "MSSV: " << MSSV << endl;
    FileOut << "CMND: " << CMND << endl;
    FileOut << "Dia Chi: " << DiaChi << endl;
    FileOut << "Gioi tinh: " << GioiTinh << endl;
    FileOut << "NgaySinh: " << NgaySinh << endl;
    FileOut << "SDT: 0" << (size_t)SDT << endl;
}
float NhanVien::TinhLuong()
{
    return 0;
}