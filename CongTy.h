#pragma once
#include "NVQuanLy.h"
#include "NVSanXuat.h"
#include "NVCongNhat.h"
#include "NVThucTap.h"
#include "List.h"
class CongTy
{
private:
	List<NhanVien*> list;
public:
	void DocFile(fstream&);
	void XuatFile(fstream&);
	void InPut();
	void OutPut();
	int TinhLuong();
	void ThemVaoViTriBatKy(int);
	int IndexOf(string);
	void Update(string);
	void Delete();
	void addNV();
	void SapXepNVTheoLuong();
	void TimNVTheoMSNV(fstream&);

};
