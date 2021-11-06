#include "NhanVien.h"
#include "NVQuanLy.h"
#include "NVSanXuat.h"
#include "NVCongNhat.h"
#include "NVThucTap.h"
#include "List.h"
class CongTy
{
private:
    List<NhanVien *> list;

public:
    void InPut();
    void OutPut();
    float TinhLuong();
    void ThemVaoCuoiList();
    void ThemVaoViTriBatKy();
    void Update();
    void Delete();
    void SapXepNVTheoLuong();
    string TimNVTheoMSNV();
};