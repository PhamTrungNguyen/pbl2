#include "CongTy.h"
#include <Windows.h>
int lc;
char w;
string LC;
void CongTy::NVDT()
{
	DaoTao* d1 = new DaoTao("Cap bac A");
	DaoTao* d2 = new DaoTao("Cap bac B");
	DaoTao* d3 = new DaoTao("Cap bac C");
	cout << "++Lop dao tao\n";
	cout << "1.Dao tao cap bac A\n";
	cout << "2.Dao tao cap bac B\n";
	cout << "3.Dao tao cap bac C\n";
	while (true)
	{
		string a;
		bool check = false;
		cout << "\--Moi nhap MS nhan vien de di dao tao: ";
		rewind(stdin);
		getline(cin, a);
		fflush(stdin);
		int i = 0;
		for (i = 0; i < list.Size(); i++) {
			if (list[i]->Get_MSNV() == a) {
				check = true;

				break;
			}
		}
		cout << "*Vui long chon lop dao tao.\n";
		int d;
		rewind(stdin);
		cout << "->";
		cin >> d;
		fflush(stdin);
		if (check == true)
		{
			if (d == 1)
			{
				if (d1->AddNhanVien(list[i]) == 0) cout << "Nhan vien da ton tai!!!\n";
				else cout << "Nhan vien da duoc them!!!\n";
			}
			else if (d == 2)
			{
				if (d2->AddNhanVien(list[i]) == 0) cout << "Nhan vien da ton tai!!!\n";
				else cout << "Nhan vien da duoc them!!!\n";
			}
			else if (d == 3)
			{
				if (d3->AddNhanVien(list[i]) == 0) cout << "Nhan vien da ton tai!!!\n";
				else cout << "Nhan vien da duoc them!!!\n";

			}
			else
			{
				cout << "Vui long chon ( 1 hoac 2 hoac 3 )\n";
			}
			//*d1->OutPut();
			//list[2]->OutPut();
		}
		else if (check != true) cout << "Nhan Vien khong ton tai!!!\n";
		int j;
		cout << "--Tiep tuc them (1-co/2-khong):";
		rewind(stdin);
		cin >> j;
		fflush(stdin);
		Sleep(700);
		if (j == 2) break;

	}
	cout << "++Danh sach dao tao\n";
	cout << "1.Xuat ra ds nhan vien dao tap cap bac A.\n";
	cout << "2.Xuat ra ds nhan vien dao tap cap bac B.\n";
	cout << "3.Xuat ra ds nhan vien dao tap cap bac C.\n";
	cout << "4.Dung.\n";
	while (true)
	{
		cout << "--Moi ban nhap lua chon:\n";
		Sleep(700);
		int y;
		
		cout << "->";
		cin >> y;
		if (y == 1) cout << *d1;
		else if (y == 2) cout << *d2;
		else if (y == 3) cout << *d3;
		else if (y == 4) break;
		else
		{
			cout << "Vui long chon ( 1 hoac 2 hoac 3 hoac 4)\n";
		}
	}
	while (true)
	{
		cout << "--Nhap ma so nhan vien ban muon xuat ra bang dao tao :";
		int ms;
		cin >> ms;
		cout << list[ms - 1]->GetName() << ":" << *list[ms - 1];
		Sleep(700);
		cout << "Tiep tuc xuat (1-co/2-khong):";
		int k;
		cin >> k;
		if (k != 1) break;

	}
}
void MENU()
{
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
	cout << "\n               8. Dao Tao                                                             \n";
	cout << "\n               9. Thoat                                                               \n";
	cout << " ===========================================================================================================================\n";
}
int KiemTra(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			return 0;
		}
	}
	return 1;
}
void CongTy::DocFile(fstream& File)
{
	int n;
	File >> n;
	for (int i = 0; i < n; i++)
	{
		char chr;
		File >> chr;
		File.seekg(2, ios_base::cur);
		if (chr == 'A')
		{
			NhanVien* x = new NVQuanLy;
			x->DocFile(File);
			list.push_back(x);
		}
		else if (chr == 'B')
		{
			NhanVien* x = new NVSanXuat;
			x->DocFile(File);
			list.push_back(x);
		}
		else if (chr == 'C')
		{
			NhanVien* x = new NVCongNhat;
			x->DocFile(File);
			list.push_back(x);
		}
		else if (chr == 'D')
		{
			NhanVien* x = new NVThucTap;
			x->DocFile(File);
			list.push_back(x);
		}
	}
}
void CongTy::XuatFile(fstream& File)
{
	for (int i = 0; i < list.Size(); i++)
	{
		File << "\nTHONG TIN NHAN VIEN THU " << i + 1 << endl;
		list[i]->XuatFile(File);
	}
	File << "\nTong luong cong ty phai tra: " << TinhLuong() << endl;
}
void CongTy::OutPut()
{
	for (int i = 0; i < list.Size(); i++)
	{
		list[i]->OutPut();
	}
}
int CongTy::TinhLuong()
{
	int TONG = 0;
	for (int i = 0; i < list.Size(); i++)
	{
		TONG += list[i]->TinhLuong();
	}
	return TONG;
}
void CongTy::ThemVaoViTriBatKy(int index)
{
	int cv;
	cout << "\n1. Nhan vien quan ly\n";
	cout << "\n2. Nhan vien san xuat\n";
	cout << "\n3. Nhan vien cong nhat\n";
	cout << "\n4. Nhan vien thuc tap\n";
	cout << "\nBan muon them nhan vien nao vao LIST: ";
	cin >> cv;
	if (cv == 1)
	{
		NVQuanLy* temp = new NVQuanLy;
		cout << "Nhap thong tin nhan vien muon them: " << endl;
		string msnv;
		bool check;
		do
		{
			check = true;
			rewind(stdin);
			cout << "\nNhap MSSV: ";
			getline(cin, msnv);
			for (int i = 0; i < list.Size(); i++)
			{
				if (list[i]->Get_MSNV() == msnv)
				{
					check = false;
					break;
				}
			}
			if (check == false)
			{
				cout << "\nMNSV da bi trung xin ktr lai!!!";
			}
		} while (check == false);
		temp->Set_MSNV(msnv);
		temp->InPut();
		list.add(index, temp);
	}
	else if (cv == 2)
	{
		NVSanXuat* temp = new NVSanXuat;
		cout << "Nhap thong tin nhan vien muon them: " << endl;
		string msnv;
		bool check;
		do
		{
			check = true;
			rewind(stdin);
			cout << "\nNhap MSSV: ";
			getline(cin, msnv);
			for (int i = 0; i < list.Size(); i++)
			{
				if (list[i]->Get_MSNV() == msnv)
				{
					check = false;
					break;
				}
			}
			if (check == false)
			{
				cout << "\nMNSV da bi trung xin ktr lai!!!";
			}
		} while (check == false);
		temp->Set_MSNV(msnv);
		temp->InPut();
		list.add(index, temp);
	}
	else if (cv == 3)
	{
		NVCongNhat* temp = new NVCongNhat;
		cout << "Nhap thong tin nhan vien muon them: " << endl;
		string msnv;
		bool check;
		do
		{
			check = true;
			rewind(stdin);
			cout << "\nNhap MSSV: ";
			getline(cin, msnv);
			for (int i = 0; i < list.Size(); i++)
			{
				if (list[i]->Get_MSNV() == msnv)
				{
					check = false;
					break;
				}
			}
			if (check == false)
			{
				cout << "\nMNSV da bi trung xin ktr lai!!!";
			}
		} while (check == false);
		temp->Set_MSNV(msnv);
		temp->InPut();
		list.add(index, temp);
	}
	else if (cv == 4)
	{
		NVThucTap* temp = new NVThucTap;
		cout << "Nhap thong tin nhan vien muon them: " << endl;
		string msnv;
		bool check;
		do
		{
			check = true;
			rewind(stdin);
			cout << "\nNhap MSSV: ";
			getline(cin, msnv);
			for (int i = 0; i < list.Size(); i++)
			{
				if (list[i]->Get_MSNV() == msnv)
				{
					check = false;
					break;
				}
			}
			if (check == false)
			{
				cout << "\nMNSV da bi trung xin ktr lai!!!";
			}
		} while (check == false);
		temp->Set_MSNV(msnv);
		temp->InPut();
		list.add(index, temp);
	}
}
void CongTy::SapXepNVTheoLuong()
{
	char yeucau;
	cout << "\nBan muon sap xep tang dan hay giam dan(t/g): ";
	cin >> yeucau;
	int x;
	for (int i = 0; i < list.Size() - 1; i++)
	{
		x = i;
		for (int j = i + 1; j < list.Size(); j++)
		{
			if (yeucau == 't')
			{
				if (list[j]->TinhLuong() < list[x]->TinhLuong())
					x = j;
			}
			else if (yeucau == 'g')
			{
				if (list[j]->TinhLuong() > list[x]->TinhLuong())
					x = j;
			}
		}
		if (x != i)
		{
			NhanVien* temp = list[i];
			list[i] = list[x];
			list[x] = temp;
		}
	}
}
void CongTy::TimNVTheoMSNV(fstream& File)
{
	string a;
	bool check = false;
	cout << "\nMoi nhap nhan vien co ma ban muon tim: ";
	getline(cin, a);
	int i = 0;
	for (i = 0; i < list.Size(); i++)
	{
		if (list[i]->Get_MSNV() == a)
		{
			check = true;
			break;
		}
	}
	if (check == true)
	{
		File << "Thong tin nhan vien co ma so can tim la:\n";
		list[i]->XuatFile(File);
	}
	else
	{
		cout << "\nKhong tim thay nhan vien co ma: " << a;
	}
}
int CongTy::IndexOf(string nv)
{
	int index = -1;
	for (int i = 0; i < list.Size(); i++)
	{
		if (list[i]->Get_MSNV() == nv)
		{
			index = i;
			break;
		}
	}
	return index;
}
void CongTy::Update(string& m)
{
	int index = IndexOf(m);
	if (index >= 0)
	{
		cout << "\n-----Danh sach UPDATE------\n";
		cout << "\n 1. Name           \n";
		cout << "\n 2. MSNV           \n";
		cout << "\n 3. CMND           \n";
		cout << "\n 4. Address        \n";
		cout << "\n 5. Gender         \n";
		cout << "\n 6. Date           \n";
		cout << "\n 7. SDT            \n";
		cout << "\n 0. Thoat          \n";
		int lc;
		do
		{
			cout << "Nhap lua chon ban muon UPDATE: ";
			cin >> lc;
			if (lc == 1)
			{
				rewind(stdin);
				string name;
				cout << "\nNhap name new: ";
				getline(cin, name);
				list[index]->Set_Name(name);
			}
			else if (lc == 2)
			{
				rewind(stdin);
				string msnv;
				cout << "\nNhap msnv new: ";
				getline(cin, msnv);
				list[index]->Set_MSNV(msnv);
			}
			else if (lc == 3)
			{
				int cmnd;
				cout << "\nNhap cmnd new: ";
				cin >> cmnd;
				list[index]->Set_CMND(cmnd);
			}
			else if (lc == 4)
			{
				rewind(stdin);
				string address;
				cout << "\nNhap address new: ";
				getline(cin, address);
				list[index]->Set_Address(address);
			}
			else if (lc == 5)
			{
				rewind(stdin);
				string gender;
				cout << "\nNhap gender new: ";
				getline(cin, gender);
				list[index]->Set_Gender(gender);
			}
			else if (lc == 6)
			{
				rewind(stdin);
				string date;
				cout << "\nNhap date new: ";
				getline(cin, date);
				list[index]->Set_Date(date);
			}
			else if (lc == 7)
			{
				double sdt;
				cout << "\nNhap sdt new: ";
				cin >> sdt;
				list[index]->Set_SDT(sdt);
			}
		} while (lc != 0);
		list[index]->OutPut();
	}
	else
	{
		cout << "\nKo tim thay nhan vien co ma ban vua nhap!!!";
	}
}
void CongTy::Delete(string m)
{
	int index = IndexOf(m);
	if (index >= 0)
	{
		list.erase(index);
	}
	else
	{
		cout << "\nVi tri xoa khong hop le!!!";
	}
}
int main()
{
	fstream File;
	CongTy x;
	for (;;)
	{
		MENU();
		do
		{
			system("color 0A");
			system("color 0B");
			system("color 0C");
			system("color 0E");
			system("color 0D");
			system("color 0F");
			while (true)
			{
				do
				{
					cout << "\nMoi ban nhap lua chon: ";
					rewind(stdin);
					getline(cin, LC);
					if (KiemTra(LC) == 0)
					{
						cout << "\nLoi kieu du lieu, xin hay nhap lai yeu cau";
						cout << "\n------------------------------------------------------------------------------------\n";
					}
				} while (KiemTra(LC) == 0);
				lc = atoi((char*)LC.c_str());
				switch (lc)
				{
				case 1:
				{
					File.open("INPUT.txt", ios_base::in);
					x.DocFile(File);
					File.close();
					cout << "\n---------DONE-------------\n";
					break;
				}
				case 2:
				{
					File.open("OUTPUT1.txt", ios_base::out);
					x.XuatFile(File);
					File.close();
					cout << "\n-----------DONE-------------\n";
					break;
				}
				case 3:
				{
					x.SapXepNVTheoLuong();
					File.open("OUTPUT2.txt", ios_base::out);
					File << "Danh sach nhan vien sau khi sap xep\n";
					x.XuatFile(File);
					File.close();
					cout << "\n-----------DONE-------------\n";
					break;
				}
				case 4:
				{
					File.open("OUTPUT3.txt", ios_base::out);
					x.TimNVTheoMSNV(File);
					File.close();
					cout << "\n-----------DONE-------------\n";
					break;
				}
				case 5:
				{
					int index;
					cout << "\nNhap vi tri ma ban muon them vao LIST: ";
					cin >> index;
					x.ThemVaoViTriBatKy(index);
					File.open("OUTPUT4.txt", ios_base::out);
					x.XuatFile(File);
					File.close();
					cout << "\n-----------DONE-------------\n";
					break;
				}
				case 6:
				{
					string y;
					cout << "\nNhap MSNV ma ban muon update:";
					getline(cin, y);
					x.Update(y);
					break;
				}
				case 7:
				{
					string m;
					cout << "\nNhap ma so nhan vien ban muon xoa: ";
					getline(cin, m);
					x.Delete(m);
					File.open("OUTPUT5.txt", ios_base::out);
					File << "Danh sach nhan vien sau khi DELETE\n";
					x.XuatFile(File);
					cout << "\n-----------DONE-------------\n";
					break;
				}
				case 8:
				{
					File.open("INPUT.txt", ios_base::in);
					x.DocFile(File);
					File.close();
					x.NVDT();
				}
				case 9:
				{
					cout << "\n----------------THE END--------------------\n";
					break;
				}
				default:
				{
					cout << "\nBan da chon chuc nang khong co trong menu. Moi ban chon lai MENU!\n";
					cout << "\n------------------------------------------------------------------------------------\n";
					break;
				}
				}
				if (lc <= 9)
					break;
			}
		} while (lc <= 7);
		cout << "\nBan co muon chay lai chuong trinh khong,Neu co hay an (y||Y), neu khong hay an 1 phim bat ky de thoat: ";
		rewind(stdin);
		cin >> w;
		if (w != 'y' && w != 'Y')
			break;
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}