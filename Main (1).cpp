#include <iostream>
#include <string>
#include <vector>
using namespace std;
class NhanVien {
protected:
	string MaSo, HoTen, NgaySinh, DiaChi;
	int id;
public:
	 virtual void Nhap() {
		 rewind(stdin);
		 /*cout << "\nNhap ma so: ";
		 getline(cin, MaSo);*/
		 cout << "\nNhap ho ten: ";
		 getline(cin, HoTen);
		 cout << "\nNhap ngay sinh: ";
		 getline(cin, NgaySinh);
		 cout << "\nNhap dia chi: ";
		 getline(cin, DiaChi);
	}
	 virtual void Xuat() {
		 cout << "\nMa so: " << MaSo;
		 cout << "\nHo ten: " << HoTen;
		 cout << "\nNgay sinh: " << NgaySinh;
		 cout << "\nDia chi: " << DiaChi;
	 }
	 virtual double TinhTienLuong() {
		 return 0;
	 }
	 int Getter_ID() {
		 return id;
	 }
	 void Setter_ID(int id_new) {
		 id = id_new;
	 }
	 string Getter_MaSo() {
		 return MaSo;
	 }
	 void Setter_MaSo(string ms) {
		 MaSo = ms;
	 }
	 NhanVien(void) {
	 }
	 virtual ~NhanVien(void) {
	 }
};
class NhanVienCongNhat:public NhanVien {
private:
	int SoNgayCong;
public:
	void Nhap() {
		NhanVien::Nhap();
		do {
			rewind(stdin);
			cout << "\nNhap so ngay cong: ";
			cin >> SoNgayCong;
			if (SoNgayCong < 0) {
				cout << "\nso ngay cong k hop le xin kiem tra lai";
			}
		} while (SoNgayCong < 0);
		id = 1;
	}
	void Xuat() {
		NhanVien::Xuat();
		cout << "\nSo ngay cong: " << SoNgayCong;
	}
	double TinhTienLuong() {
		return SoNgayCong * 55000;
	}
};
class NhanVienSanXuat :public NhanVien {
private:
	int SoSanPham;
public:
	void Nhap() {
		NhanVien::Nhap();
		rewind(stdin);
		cout << "\nNhap so san pham: ";
		cin >> SoSanPham;
		id = 2;
	}
	void Xuat() {
		NhanVien::Xuat();
		cout << "\nSo san pham: " << SoSanPham;
	}
	double TinhTienLuong() {
		return SoSanPham * 20000;
	}
};
class NhanVienQuanLy :public NhanVien {
private:
	double HeSoLuong, LuongCanBan;
public:
	void Nhap() {
		NhanVien::Nhap();
			rewind(stdin);
			cout << "\nNhap he so luong: ";
			cin >> HeSoLuong;
			cout << "\nNhap luong can ban: ";
			cin >> LuongCanBan;
			id = 3;
	}
	void Xuat() {
		NhanVien::Xuat();
		cout << "\nHe so luong: " << HeSoLuong;
		cout << "\nLuong can ban: " << (size_t)LuongCanBan;
	}
	double TinhTienLuong() {
		return HeSoLuong * LuongCanBan;
	}
};
class CongTy {
private:
	vector<NhanVien*>List;
public:
	void NhapCongTy() {
		int luachon;
		NhanVien* NV = NULL;
		do {
			cout << "\n-----------------------Menu---------------------------\n";
			cout << "\n1.Nhan vien cong nhat";
			cout << "\n2.Nhan vien san xuat";
			cout << "\n3.Nhan vien quan ly";
			cout << "\n0.Thoat";
			cout << "\n--------------------------------------------------------\n";
			do {
				cout << "\nMoi nhap lua chon cua ban: ";
				cin >> luachon;
				if (luachon < 0 || luachon>3) {
					cout << "\nLua chon ko hop le xin nhap lai";
				}
			} while (luachon < 0 || luachon>3);
			if (luachon == 1) {
				NV = new NhanVienCongNhat;
			}
			else if (luachon == 2) {
				NV = new NhanVienSanXuat;
			}
			else if (luachon == 3) {
				NV = new NhanVienQuanLy;
			}
			if (luachon != 0) {
				string MaSo;
				bool check;
				do {
					check = true;
					rewind(stdin);
					cout << "\nNhap ma so: ";
					getline(cin, MaSo);
					int size = List.size();
					for (int i = 0; i < size; i++) {
						if (List[i]->Getter_MaSo() == MaSo) {
							check = false;
							break;
						}
					}
					if (check == false) {
						cout << "\nMa so da bi trung xin hay nhap lai";
					}
				} while (check==false);
				NV->Setter_MaSo(MaSo);
				NV->Nhap();
				List.push_back(NV);
			}
		} while (luachon != 0);
	}
	void XuatCongTy() {
		int size = List.size();
		for (int i = 0; i < size; i++) {
			cout << "\nThong tin nhan vien thu " << i + 1 << " la\n";
			List[i]->Xuat();
		}
	}
	double TinhTongLuongCongTy() {
		double Tong = 0;
		int size = List.size();
		for (int i = 0; i < size; i++) {
			Tong += List[i]->TinhTienLuong();
		}
		return Tong;
	}
	double TimTienLuongMax() {
		double Max = List[0]->TinhTienLuong();
		int size = List.size();
		for (int i = 1; i < size; i++) {
			if (List[i]->TinhTienLuong() > Max) {
				Max = List[i]->TinhTienLuong();
			}
		}
		return Max;
	}
	void LietKeCacNhanVienCoLuongMax() {
		double LuongMax = TimTienLuongMax();
		int size = List.size();
		for (int i = 0; i < size; i++) {
			if (List[i]->TinhTienLuong() == LuongMax) {
				List[i]->Xuat();
			}
		}
	}
	double TinhTienLuongCuaNhanVienSanXuat() {
		double Tong = 0;
		int size = List.size();
		for (int i = 0; i < size; i++) {
			if (List[i]->Getter_ID() == 2) {
				Tong += List[i]->TinhTienLuong();
			}
		}
		return Tong;
	}
};
int main() {
	CongTy ct;
	ct.NhapCongTy();
	ct.XuatCongTy();
	cout << "\nTong luong: " << (size_t)ct.TinhTongLuongCongTy();
	cout << "\nThong tin cac nhan vien co luong MAX la\n ";
	ct.LietKeCacNhanVienCoLuongMax();
	return 0;
}