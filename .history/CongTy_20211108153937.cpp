#include "CongTy.h"
#include <Windows.h>
void MENU() {
	cout << "\n-------------------------------Do an--------------------------\n";
	cout << "\n                       DE TAI: QUAN LY CONG TY               \n";
	cout << "\n                        ......        ...... ";
	cout << "\n                Pham Trung Nguyen = = = HO KY HUY";
	cout << " ===========================================================================================================================\n";
	cout << "\n              ....................NHOM 1......................\n\n";
	cout << " ===========================================================================================================================\n";
	cout << "\n           1. Doc du lieu tu file INPUT.txt                 \n";
	cout << "\n           2. Tinh tong luong va xuat du lieu ra file OUTPUT1.txt                 \n";
	cout << "\n           3. Sap xep nhan vien theo luong xuat ra file OUTPUT2.txt               \n";
	cout << "\n             4. Tim kiem nhan vien theo MSNV va xuat ra file OUTPUT3.txt            \n";

}
void CongTy::InPut()
{
	NhanVien* x = NULL;
	while (!NhanVien::FileIn.eof())
	{
		char chr;
		NhanVien::FileIn >> chr;
		NhanVien::FileIn.seekg(2, ios_base::cur);
		if (chr == 'A')
		{
			x = new NVQuanLy;
			x->InPut();
			list.push_back(x);
		}
		else if (chr == 'B')
		{
			x = new NVSanXuat;
			x->InPut();
			list.push_back(x);
		}
		else if (chr == 'C')
		{
			x = new NVCongNhat;
			x->InPut();
			list.push_back(x);
		}
		else if (chr == 'D')
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
	NhanVien::FileOut << "Tong luong cong ty phai tra cho nhan vien la => " << TinhLuong();
}
int CongTy::TinhLuong() {
	int TongLuong = 0;
	for (int i = 0; i < list.Size(); i++) {
		TongLuong += list[i]->TinhLuong();
	}
	return TongLuong;
}
void CongTy::SapXepNVTheoLuong() {
	int min;
	for (int i = 0; i < list.Size() - 1; i++) {
		min = i;
		for (int j = i + 1; j < list.Size(); j++) {
			if (list[j]->TinhLuong() < list[min]->TinhLuong())
				min = j;
		}
		if (min != i) {
			NhanVien *temp = list[i];
			list[i] = list[min];
			list[min] = temp;	
		}
	}
}
void CongTy::TimNVTheoMSNV() {
	rewind(stdin);
	string a;
	bool check = false;
	cout << "\nMoi nhap nhan vien co ma ban muon tim: ";
	getline(cin, a);
	int i = 0;
	for ( i = 0; i < list.Size(); i++) {
		if (list[i]->Get_MSNV() == a) {
			check = true;
			break;
		}
	}
	if (check == true) {
		list[i]->OutPut();
	}
	else {
		cout << "\nNo find";
	}
}
int main()

{ 
	int lc;
	do {
		cout << "Nhap lua chon: ";
		cin >> lc;
		switch (lc)
		{
		case 1: {
			NhanVien::FileIn.open("INPUT.txt", ios_base::in);
			CongTy x;
			x.InPut();
			NhanVien::FileIn.close();
			cout << "Da doc file";
			break;
		}
		case 2: {
			NhanVien::FileIn.open("INPUT.txt", ios_base::in);
			CongTy x;
			x.InPut();
			NhanVien::FileIn.close();
			NhanVien::FileOut.open("OUTPUT.txt", ios_base::out);
			x.OutPut();
			NhanVien::FileOut.close();
			break;
		}
		case 3:
		{
			NhanVien::FileIn.open("INPUT.txt", ios_base::in);
			CongTy x;
			x.InPut();
			NhanVien::FileIn.close();
			x.SapXepNVTheoLuong();
			NhanVien::FileOut.open("OUTPUT1.txt", ios_base::out);
			x.OutPut();
			NhanVien::FileOut.close();
			break;
		}
		case 4: {
			NhanVien::FileIn.open("INPUT.txt", ios_base::out);
			CongTy x;
			x.InPut();
			NhanVien::FileOut.close();
			NhanVien::FileOut.open("OUTPUT2.txt", ios_base::out);
			x.TimNVTheoMSNV();
			break;
		}
		}
	} while (lc != 0);
	system("pause");
	return 0;
}