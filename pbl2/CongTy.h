#pragma once
#include <Windows.h>
#include "NVQuanLy.h"
#include "NVSanXuat.h"
#include "NVCongNhat.h"
#include "NVThucTap.h"
#include "List.h"
//dt
#include "NhanVien.h"
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
	void Update(string&);
	void Delete(string);
	void addNV();
	void SapXepNVTheoLuong();
	void TimNVTheoMSNV(fstream&);
	void NVDT();
};