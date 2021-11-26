#include "NhanVien.h"
void NhanVien::DocFile(fstream& File)
{
    getline(File, this->Name, ',');
    File.seekg(1, SEEK_CUR);
    getline(File, this->MSNV, ',');
    File.seekg(1, SEEK_CUR);
    File >> this->CMND;
    File.seekg(2, SEEK_CUR);
    getline(File, this->Address, ',');
    File.seekg(1, SEEK_CUR);
    getline(File, this->Gender, ',');
    File.seekg(1, SEEK_CUR);
    getline(File, this->Date, ',');
    File.seekg(1, SEEK_CUR);
    File >> this->SDT;
    File.seekg(2, SEEK_CUR);
}
void NhanVien::XuatFile(fstream& File)
{
    File << "Name: " << this->Name << endl;
    File << "MSNV: " << this->MSNV << endl;
    File << "CMND: " << this->CMND << endl;
    File << "Address: " << this->Address << endl;
    File << "Gender: " << this->Gender << endl;
    File << "Date: " << this->Date << endl;
    File << "So dien thoai: 0" << (size_t)this->SDT << endl;
}
void NhanVien::InPut()
{
    rewind(stdin);
    cout << "Input name: ";
    getline(cin, this->Name);
    /* cout << "Input MSNV: ";
     getline(cin, this->MSNV);*/
    cout << "Input CMND: ";
    cin >> this->CMND;
    rewind(stdin);
    cout << "Input Address: ";
    getline(cin, this->Address);
    cout << "Input Gender: ";
    getline(cin, this->Gender);
    cout << "Input date: ";
    getline(cin, this->Date);
    cout << "Input SDT: ";
    cin >> this->SDT;
}
void NhanVien::OutPut()
{
    cout << "Name: " << this->Name << endl;
    cout << "MSNV: " << this->MSNV << endl;
    cout << "CMND: " << this->CMND << endl;
    cout << "Address: " << this->Address << endl;
    cout << "Gender: " << this->Gender << endl;
    cout << "Date: " << this->Date << endl;
    cout << "SDT: " << this->SDT << endl;
}
int NhanVien::TinhLuong()
{
    return 0;
}
string NhanVien::Get_MSNV()
{
    return this->MSNV;
}
void NhanVien::Set_Name(string name)
{
    this->Name = name;
}
void NhanVien::Set_MSNV(string msnv)
{
    this->MSNV = msnv;
}
void NhanVien::Set_CMND(int cmnd)
{
    this->CMND = cmnd;
}
void NhanVien::Set_Address(string address)
{
    this->Address = address;
}
void NhanVien::Set_Gender(string gender)
{
    this->Gender = gender;
}
void NhanVien::Set_Date(string date)
{
    this->Date = date;
}
void NhanVien::Set_SDT(double value)
{
    this->SDT = value;
}
//dt
string NhanVien::GetName()
{
    return this->Name;
}
void NhanVien::AddDaoTao(DaoTao* d)
{
    this->daotao.push_back(d);
}
ostream& operator<<(ostream& o, NhanVien& d)
{
    if (d.daotao.Size() == 0)
        o << " Chua co bang dao tao\n";
    else
    {


        for (int i = 0;i < d.daotao.Size();i++)
        {
            o << d.daotao[i]->GetCoSo() << " ";
        }
        o << endl;
    }
    return o;
}

//cn
int NhanVien::GetCMND()
{
    return this->CMND;
}
string NhanVien::GetAddress()
{
    return this->Address;
}
double NhanVien::GetSDT()
{
    return this->SDT;
}
