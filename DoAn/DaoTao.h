#pragma once
#include "List.h"
#include <iostream>
#include <vector>
using namespace std;
class NhanVien;
class DaoTao
{
private:
	List<NhanVien*> nhanvien;
	string CoSo;
	string Bangdt;
public:
	DaoTao(string = "");
	~DaoTao();
	bool AddNhanVien(NhanVien*);
	string GetCoSo();
	string GetBDT();
	void InPut();
	void OutPut();
	friend ostream& operator<<(ostream&, DaoTao&);
	friend class NhanVien;
};


