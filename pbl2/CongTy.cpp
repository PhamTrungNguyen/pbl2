#include "CongTy.h"
#include <Windows.h>
#include <conio.h>
string LC;
int lc;
char w;
void MENU() {
	cout << "\n\t------------------------------------------------------Do an PBL2------------------------------------------------\n";
	cout << "\n\t                                              DE TAI: QUAN LY CONG TY               \n";
	cout << "\n\t                                                ......        ...... ";
	cout << "\n\t                                           Pham Trung Nguyen = = = HO KY HUY";
	cout << "\n\t=============================================================================================================\n";
	cout << "\n\t                                      ....................NHOM 1......................\n\n";
	cout << "\t=============================================================================================================\n";
	cout << "\n\t               1. Doc du lieu tu file INPUT.txt                 \n";
	cout << "\n\t               2. Tinh tong luong va xuat du lieu ra file OUTPUT1.txt                 \n";
	cout << "\n\t               3. Sap xep nhan vien theo luong xuat ra file OUTPUT2.txt               \n";
	cout << "\n\t               4. Tim kiem nhan vien theo MSNV va xuat ra file OUTPUT3.txt            \n";

}
int KiemTra(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] < '0' || s[i]>'9') {
			return 0;
		}
	}
	return 1;
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
			NhanVien* temp = list[i];
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
	for (i = 0; i < list.Size(); i++) {
		if (list[i]->Get_MSNV() == a) {
			check = true;
			break;
		}
	}
	if (check == true) {
		NhanVien::FileOut << "Thong tin nhan vien co ma so can tim la:\n";
		list[i]->OutPut();
		cout << "\n-----------Da xuat ra file-------------\n";
	}
	else {
		cout << "\nKhong tim thay nhan vien co ma: " << a;;
	}
}
int main()
{
	for (;;) {
		MENU();
		do {
			system("color 0A");
			Sleep(100);
			system("color 0B");
			Sleep(100);
			system("color 0C");
			Sleep(100);
			system("color 0F");
			Sleep(100);
			while (true) {
				do {
					cout << "\nMoi ban nhap lua chon: ";
					rewind(stdin);
					getline(cin, LC);
					if (KiemTra(LC) == 0) {
						cout << "\nLoi kieu du lieu, xin hay nhap lai yeu cau";
						cout << "\n------------------------------------------------------------------------------------\n";
					}
				} while (KiemTra(LC) == 0);
				lc = atoi((char*)LC.c_str());
				switch (lc) {
				case 1: {
					NhanVien::FileIn.open("INPUT.txt", ios_base::in);
					CongTy x;
					x.InPut();
					NhanVien::FileIn.close();
					cout << "\n---------Da doc du lieu tu file-------------\n";
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
					cout << "\n-----------Da xuat ra file-------------\n";
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
					NhanVien::FileOut << "Danh sach nhan vien sau khi sap xep\n";
					x.OutPut();
					NhanVien::FileOut.close();
					cout << "\n-----------Da xuat ra file-------------\n";
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
				default: {
					cout << "\nBan da chon chuc nang khong co trong menu. Moi ban chon lai MENU!\n";
					cout << "\n------------------------------------------------------------------------------------\n";
					break;
				}

				}
				if (lc <= 4) break;
			}
		} while (lc <= 3);
		cout << "\nBan co muon chay lai chuong trinh khong,Neu co hay an (y||Y), neu khong hay an 1 phim bat ky de thoat: ";
		rewind(stdin);
		cin >> w;
		if (w != 'y' && w != 'Y') break;
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}