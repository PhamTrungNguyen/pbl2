#include "CongTy.h"
#include <Windows.h>
int lc;
char w;
string LC;
void MENU() {
	cout << "\n------------------------------------------------------Do an PBL2------------------------------------------------\n";
	cout << "\n                                              DE TAI: QUAN LY CONG TY               \n";
	cout << "\n                                                ......        ...... ";
	cout << "\n                                           Pham Trung Nguyen = = = HO KY HUY";
	cout << "\n===========================================================================================================================\n";
	cout << "\n                                      ....................NHOM 1......................\n\n";
	cout << " ===========================================================================================================================\n";
	cout << "\n               1. Doc du lieu tu file INPUT.txt                                       \n";
	cout << "\n               2. Tinh tong luong va xuat du lieu ra file OUTPUT1.txt                 \n";
	cout << "\n               3. Sap xep nhan vien theo luong xuat ra file OUTPUT2.txt               \n";
	cout << "\n               4. Tim kiem nhan vien theo MSNV va xuat ra file OUTPUT3.txt            \n";
	cout << "\n               5. Them nhan vien vao 1 vi tri bat ky va xuat ra file OUTPUT4.txt      \n";
	cout << "\n               6. Update nhan vien theo MSNV                                          \n";
	cout << "\n               7. Delete va xuat ra file OUTPUT5.txt                                  \n";
	cout << " ===========================================================================================================================\n";
}
int KiemTra(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] < '0' || s[i]>'9') {
			return 0;
		}
	}
	return 1;
}
void CongTy::DocFile(fstream& File) {
	int n;
	File >> n;
	for (int i = 0; i < n; i++)
	{
		char chr;
		File >> chr;
		File.seekg(2, SEEK_CUR);
		if (chr == 'A') {
			NhanVien* x = new NVQuanLy;
			x->DocFile(File);
			list.push_back(x);
		}
		else if (chr == 'B') {
			NhanVien* x = new NVSanXuat;
			x->DocFile(File);
			list.push_back(x);
		}
		else if (chr == 'C') {
			NhanVien* x = new NVCongNhat;
			x->DocFile(File);
			list.push_back(x);
		}
		else if (chr == 'D') {
			NhanVien* x = new NVThucTap;
			x->DocFile(File);
			list.push_back(x);
		}
	}
}
void CongTy::XuatFile(fstream& File) {
	for (int i = 0; i < list.Size(); i++) {
		File << "\nThong tin nhan vien thu " << i + 1 << endl;
		list[i]->XuatFile(File);
	}
	File << "\nTong luong cong ty phai tra: " << TinhLuong() << endl;
}
int CongTy::TinhLuong() {
	int TONG = 0;
	for (int i = 0; i < list.Size(); i++) {
		TONG += list[i]->TinhLuong();
	}
	return TONG;
}
void CongTy::ThemVaoViTriBatKy(int index) {
	int cv;
	cout << "\n1. Nhan vien quan ly\n";
	cout << "\n2. Nhan vien san xuat\n";
	cout << "\n3. Nhan vien cong nhat\n";
	cout << "\n4. Nhan vien thuc tap\n";
	cout << "\nBan muon them nhan vien nao vao LIST: ";
	cin >> cv;
	if (cv == 1) {
		NVQuanLy* temp = new NVQuanLy;
		cout << "Nhap thong tin nhan vien muon them: " << endl;
		temp->InPut();
		list.add(index, temp);
	}
	else if (cv == 2) {
		NVSanXuat* temp = new NVSanXuat;
		cout << "Nhap thong tin nhan vien muon them: " << endl;
		temp->InPut();
		list.add(index, temp);
	}
	else if (cv == 3) {
		NVCongNhat* temp = new NVCongNhat;
		cout << "Nhap thong tin nhan vien muon them: " << endl;
		temp->InPut();
		list.add(index, temp);
	}
	else if (cv == 4) {
		NVThucTap* temp = new NVThucTap;
		cout << "Nhap thong tin nhan vien muon them: " << endl;
		temp->InPut();
		list.add(index, temp);
	}
	else cout << "Du Lieu nhap vao khong hop le!!!";
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
void CongTy::TimNVTheoMSNV(fstream& File) {
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
		File << "Thong tin nhan vien co ma so can tim la:\n";
		list[i]->XuatFile(File);
	}
	else {
		cout << "\nKhong tim thay nhan vien co ma: " << a;;
	}
}
int CongTy::IndexOf(string nv) {
	int index = -1;
	for (int i = 0; i <= list.Size(); i++) {
		if (list[i]->Get_MSNV() == nv) {
			index = i;
			break;
		}
	}
	return index;
}
void CongTy::Update(string m) {
	int cv;
	NhanVien* nv = NULL;
	cout << "\n1. Nhan vien quan ly\n";
	cout << "\n2. Nhan vien san xuat\n";
	cout << "\n3. Nhan vien cong nhat\n";
	cout << "\n4. Nhan vien thuc tap\n";
	cout << "\nBan muon UPDATE nhan vien nao: ";
	cin >> cv;
	if (cv == 1) {
		nv = new NVQuanLy;
		nv->InPut();
		list.push_back(nv);
		int index = IndexOf(m);
		if (index >= 0) {
			double sdt;
			cout << "\nNhap so sdt new: ";
			cin >> sdt;
			list[index]->Set_SDT(sdt);
		}
		cout << "Thong tin nhan vien sau khi UPDATE\n";
		nv->OutPut();
	}
	else if (cv == 2) {
		nv = new NVSanXuat;
		nv->InPut();
		list.push_back(nv);
		int index = IndexOf(m);
		if (index >= 0) {
			double sdt;
			cout << "\nNhap so sdt new: ";
			cin >> sdt;
			list[index]->Set_SDT(sdt);
		}
		cout << "Thong tin nhan vien sau khi UPDATE\n";
		nv->OutPut();
	}
	else if (cv == 3) {
		nv = new NVCongNhat;
		nv->InPut();
		list.push_back(nv);
		int index = IndexOf(m);
		if (index >= 0) {
			double sdt;
			cout << "\nNhap so sdt new: ";
			cin >> sdt;
			list[index]->Set_SDT(sdt);
		}
		cout << "Thong tin nhan vien sau khi UPDATE\n";
		nv->OutPut();
	}
	else if (cv == 4) {
		nv = new NVThucTap;
		nv->InPut();
		list.push_back(nv);
		int index = IndexOf(m);
		if (index >= 0) {
			double sdt;
			cout << "\nNhap so sdt new: ";
			cin >> sdt;
			list[index]->Set_SDT(sdt);
		}
		cout << "Thong tin nhan vien sau khi UPDATE\n";
		nv->OutPut();
	}
	else cout << "Du lieu khong hop le!!! Moi ban thuc hien lai.";
}
void CongTy::Delete() {
	fstream File;
	int index;
	cout << "\nBan muon xoa nhan vien nao: ";
	cin >> index;
	if (index < list.Size()) {
		list.erase(index);
	}
	else {
		cout << "\nVi tri xoa khong hop le!!!";
	}
}
int main() {
	fstream File;
	for (;;) {
		MENU();
		do {
			system("color 0A");
			system("color 0B");
			system("color 0C");
			system("color 0E");
			system("color 0D");
			system("color 0F");
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
					File.open("INPUT.txt", ios_base::in);
					CongTy x;
					x.DocFile(File);
					File.close();
					cout << "\n---------DONE-------------\n";
					break;
				}
				case 2: {
					File.open("INPUT.txt", ios_base::in);
					CongTy x;
					x.DocFile(File);
					File.close();
					File.open("OUTPUT1.txt", ios_base::out);
					x.XuatFile(File);
					File.close();
					cout << "\n-----------DONE-------------\n";
					break;
				}
				case 3:
				{
					File.open("INPUT.txt", ios_base::in);
					CongTy x;
					x.DocFile(File);
					File.close();
					x.SapXepNVTheoLuong();
					File.open("OUTPUT2.txt", ios_base::out);
					File << "Danh sach nhan vien sau khi sap xep\n";
					x.XuatFile(File);
					File.close();
					cout << "\n-----------DONE-------------\n";
					break;
				}
				case 4: {
					File.open("INPUT.txt", ios_base::in);
					CongTy x;
					x.DocFile(File);
					File.close();
					File.open("OUTPUT3.txt", ios_base::out);
					x.TimNVTheoMSNV(File);
					File.close();
					cout << "\n-----------DONE-------------\n";
					break;
				}
				case 5: {
					File.open("INPUT.txt", ios_base::in);
					CongTy x;
					x.DocFile(File);
					File.close();
					int index;
					cout << "\nNhap vi tri ma ban muon them nhan vien vao LIST: ";
					cin >> index;
					x.ThemVaoViTriBatKy(index);
					File.open("OUTPUT4.txt", ios_base::out);
					x.XuatFile(File);
					File.close();
					cout << "\n-----------DONE-------------\n";
					break;
				}
				case 6: {
					CongTy x;
					string y;
				pbl2:
					cout << "\nNhap MSNV ma ban muon update:";
					getline(cin, y);
					x.Update(y);
					char r;
					cout << "\nBan co muon tiep tuc update nhan vien khong.Neu co hay an (y||Y), neu khong hay an 1 phim bat ky de thoat:: ";
					cin >> r;
					if (r == 'y' || r == 'Y') goto pbl2;
					break;
				}
				case 7: {
					File.open("INPUT.txt", ios_base::in);
					CongTy x;
					x.DocFile(File);
					File.close();
					x.Delete();
					File.open("OUTPUT5.txt", ios_base::out);
					File << "Danh sach nhan vien sau khi DELETE\n";
					x.XuatFile(File);
					cout << "\n-----------DONE-------------\n";
					break;
				}
				default: {
					cout << "\nBan da chon chuc nang khong co trong menu. Moi ban chon lai MENU!\n";
					cout << "\n------------------------------------------------------------------------------------\n";
					break;
				}
				}
				if (lc <= 7) break;
			}
		} while (lc <= 6);
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