/*
Nhom 7 - Hanoi Close University Manager
- Nguyen Quang Ha - 2110A03
- Nguyen Van Dung - 2110A03
- Ta Huu Cuong - 2110A03
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
const int NGANH_MAX = 3;
const int KHOA_MAX = 3;
const int NGANH_DKI_MAX = 10;

struct Nganh {
	string sMaNganh;
	string sTenNganh;
	float fDiemChuan;
	int iChiTieu;
};

struct Khoa {
	string sMaKhoa;
	string sTenKhoa;
	string sDiaChi;
	Nganh dsNG[NGANH_MAX];
};

struct ThiSinh
{
	string sMaHS;
	string sSBD;
	string sHoTen;
	string sNgaySinh;
	string sQueQuan;
	string sKhuVuc;
	string sGioiTinh;
	string sSDT;
	string NganhDKI[NGANH_DKI_MAX];
	float fDiemUT;
	float fDiemMon1;
	float fDiemMon2;
	float fDiemMon3;
	float fTongDiem;
	int slng;
};

struct QuanLyHoSoThiSinh {
	int sts;
	ThiSinh dsTS[100];
	Khoa dsKH[KHOA_MAX];
};

struct NodeQuanLyHoSoThiSinh {
	QuanLyHoSoThiSinh info;
	struct NodeQuanLyHoSoThiSinh* next;
};

struct ListQuanLyHoSoThiSinh {
	NodeQuanLyHoSoThiSinh* head;
	NodeQuanLyHoSoThiSinh* tail;
};

ListQuanLyHoSoThiSinh QLHSTS;


Khoa CNTT =
{ "CNTTDC96", "Cong Nghe Thong Tin", "96 Dinh Cong",
	{{"CNTT1", "Khoa Hoc May Tinh", 28.94f, 150}, {"CNTT2", "Cong Nghe Thong Tin", 27.85f, 300},
	{"CNTT3", "Toan Tin", 26.5f, 100}},
};

Khoa NN =
{ "NNNHB101", "Ngoai Ngu", "101 Nguyen Hien",
	{{"NN1", "Tieng Trung", 34.94f, 150}, {"NN2", "Tieng Anh", 33.85f, 200},
	{"NN3", "Tieng Nhat", 26.5f, 100}},
};

Khoa BC =
{ "BC32DVCG", "Bao Chi", "32 Dich Vong",
	{{"BC1", "Phong Vien", 24.94f, 175}, {"BC2", "Phat Thanh Vien", 23.35f, 100},
	{"BC3", "Lich Su Hoc", 25.12f, 50}},
};


void TieuDeKhoa() {
	std::cout << std::endl << std::setw(5) << std::setiosflags(std::ios::left) << "STT";
	std::cout << std::setw(15) << "MA KHOA";
	std::cout << std::setw(20) << "TEN KHOA";
	std::cout << std::setw(20) << "DIA CHI";
}

void InNganh(Nganh a) {
	cout << "- Ma Nganh: " << a.sMaNganh << endl;
	cout << "- Ten Nganh: " << a.sTenNganh << endl;
	cout << "- Diem Chuan: " << a.fDiemChuan << endl;
	cout << "- Chi tieu: " << a.iChiTieu << endl;
	cout << endl;
}

void InKhoa(Khoa a) {
	TieuDeKhoa();
	std::cout << std::endl << std::setw(1) << std::setiosflags(std::ios::left) << "*)   ";
	std::cout << std::setw(15) << a.sMaKhoa;
	std::cout << std::setw(20) << a.sTenKhoa;
	std::cout << std::setw(20) << a.sDiaChi;
	cout << endl;
	cout << "\n(Cac nganh trong khoa " << a.sTenKhoa << ")\n" << endl;
	for (int i = 0; i < NGANH_MAX; i++)
		InNganh(a.dsNG[i]);
}

void InThongTinKhoaVaNganh() {
	InKhoa(CNTT);
	InKhoa(NN);
	InKhoa(BC);
}

float DUT(string KV) {
	float UT = 0.0f;
	if (KV == "KV01")
		UT = 0.75f;
	else if (KV == "KV02")
		UT = 0.5f;
	else if (KV == "KV03")
		UT = 0.25f;
	else if (KV == "KV04")
		UT = 0.1f;
	return UT;
}

void NhapThiSinh(ThiSinh& a) {
	std::cin.ignore();
	std::cout << "Nhap ma ho so: "; getline(cin, a.sMaHS);
	std::cout << "Nhap so bao danh: "; getline(cin, a.sSBD);
	std::cout << "Nhap ho ten thi sinh: "; getline(cin, a.sHoTen);
	std::cout << "Nhap ngay sinh: "; getline(cin, a.sNgaySinh);
	std::cout << "Nhap que quan: "; getline(cin, a.sQueQuan);
	std::cout << "Nhap khu vuc: "; getline(cin, a.sKhuVuc);
	std::cout << "Nhap gioi tinh: "; getline(cin, a.sGioiTinh);
	std::cout << "Nhap so dien thoai: "; getline(cin, a.sSDT);

	// DKI NGANH
	a.slng = 0;
	do
	{
		std::cout << "\nNhap so luong nganh muon dang ki: ", cin >> a.slng;
		if (a.slng > NGANH_DKI_MAX) {
			cout << "\nChi duoc nhap duoi 10 nganh dang ki\nVui long nhap lai...";
		}
	} while (a.slng > NGANH_DKI_MAX);
	std::cout << "\nThong tin ve cac nganh va khoa cua Hanoi Close University\n";
	InThongTinKhoaVaNganh();
	std::cin.ignore();
	for (int i = 0; i < a.slng; i++)
	{
		std::cout << "Nhap ma nganh so " << i + 1 << ":";
		getline(cin, a.NganhDKI[i]);
	}

	// Lay diem uu tien
	a.fDiemUT = DUT(a.sKhuVuc);

	std::cout << "Nhap diem mon 1: "; cin >> a.fDiemMon1;
	std::cout << "Nhap diem mon 2: "; cin >> a.fDiemMon2;
	std::cout << "Nhap diem mon 3: "; cin >> a.fDiemMon3;
	a.fTongDiem = a.fDiemMon1 + a.fDiemMon2 + a.fDiemMon3 + a.fDiemUT;


}

void TieuDeThiSinh()
{
	std::cout << std::endl << std::setw(5) << std::setiosflags(std::ios::left) << "STT";
	std::cout << std::setw(8) << "MA HS";
	std::cout << std::setw(10) << "SBD";
	std::cout << std::setw(25) << "Ho Ten";
	std::cout << std::setw(15) << "Ngay Sinh";
	std::cout << std::setw(15) << "Que Quan";
	std::cout << std::setw(6) << "KV";
	std::cout << std::setw(5) << "GT";
	std::cout << std::setw(15) << "So DT";
	std::cout << std::setw(12) << "Tong Diem";
}

void InThiSinh(ThiSinh a) {
	TieuDeThiSinh();
	std::cout << std::endl << std::setw(1) << std::setiosflags(std::ios::left) << "*)   ";
	std::cout << std::setw(8) << a.sMaHS;
	std::cout << std::setw(10) << a.sSBD;
	std::cout << std::setw(25) << a.sHoTen;
	std::cout << std::setw(15) << a.sNgaySinh;
	std::cout << std::setw(15) << a.sQueQuan;
	std::cout << std::setw(6) << a.sKhuVuc;
	std::cout << std::setw(5) << a.sGioiTinh;
	std::cout << std::setw(15) << a.sSDT;
	std::cout << std::setw(12) << a.fTongDiem;

	std::cout << "\n(Cac ma nganh dang ki)\n";
	for (int i = 0; i < a.slng; i++)
		cout << "- Ma nganh " << i + 1 << " : " << a.NganhDKI[i] << endl;
}

void NhapQuanLyHoSo(QuanLyHoSoThiSinh& a) {
	cout << "\n===NHAP THONG TIN HO SO===\n";
	std::cout << "\nNhap so thi sinh muon nhap: "; cin >> a.sts;
	for (int i = 0; i < a.sts; i++)
	{
		cout << "\n\n(Nhap Thi sinh thu " << i + 1 << ")" << endl;
		NhapThiSinh(a.dsTS[i]);
	}

}

void InQuanLyHoSo(QuanLyHoSoThiSinh& a) {
	cout << "\n===HO SO CUA CAC THI SINH===\n";
	for (int i = 0; i < a.sts; i++)
		InThiSinh(a.dsTS[i]);
}

void QuanLyHoSoIniatior(ListQuanLyHoSoThiSinh& Q) {
	Q.head = NULL;
	Q.tail = NULL;
}

NodeQuanLyHoSoThiSinh* getNodeQLHSTS(QuanLyHoSoThiSinh x) {
	NodeQuanLyHoSoThiSinh* p;
	p = new NodeQuanLyHoSoThiSinh();
	if (p == NULL) {
		cout << "\nGet Node Failed!";
		exit(0);
	}
	p->info = x;
	p->next = NULL;
	return p;
}

void ChenDauQLHSTS(ListQuanLyHoSoThiSinh& Q, NodeQuanLyHoSoThiSinh* p) {
	if (Q.head == NULL) {
		Q.head = p;
		Q.tail = p;
	}
	else
	{
		p->next = Q.head;
		Q.head = p;
	}
}

void NhapDSQLHSTS(ListQuanLyHoSoThiSinh& Q) {
	NodeQuanLyHoSoThiSinh* p;
	QuanLyHoSoThiSinh x;
	NhapQuanLyHoSo(x);
	p = getNodeQLHSTS(x);
	ChenDauQLHSTS(Q, p);
}

void InDSQLHSTS(ListQuanLyHoSoThiSinh& Q) {
	NodeQuanLyHoSoThiSinh* p;
	for (p = Q.head; p != NULL; p = p->next) {
		InQuanLyHoSo(p->info);
	}
}


void MenuTitle()
{
	std::cout << "============= HE_THONG_TUYEN_SINH =============\n";
	std::cout << "|| 1. Nhap thong tin ho so                   ||\n";
	std::cout << "|| 2. Hien cac ho so                         ||\n";
	std::cout << "|| 3. Thong tin nganh va khoa cua truong     ||\n";
	std::cout << "|| 4. ||\n";
	std::cout << "|| 5. ||\n";
	std::cout << "|| 6. ||\n";
	std::cout << "|| 7. ||\n";
	std::cout << "|| 8. ||\n";
	std::cout << "|| 9. ||\n";
	std::cout << "===============================================\n";
}
int lua_chon_menu()
{
	int m = 0;
	std::cout << "\nNhap thong tin can thuc hien : ";
	std::cin >> m;
	if (m > 0 || m < 10)
	{
		return m;
	}
	else
	{
		return lua_chon_menu();
	}
}
void xu_li_du_lieu()
{
	int number = lua_chon_menu();
	switch (number)
	{
	case 1:
	{
		NhapDSQLHSTS(QLHSTS);
		break;
	}
	case 2:
	{
		InDSQLHSTS(QLHSTS);
		break;
	}
	case 3:
	{
		InThongTinKhoaVaNganh();
		break;
	}
	case 4:
	{
		break;
	}
	case 5:
	{
		break;
	}
	case 6:
	{
		break;
	}
	case 7:
	{
		break;
	}
	case 8:
	{
		break;
	}
	case 9:
	{
		break;
	}
	}
}

void QuanLyTheoMenu() {
	while (true)
	{
		MenuTitle();
		xu_li_du_lieu();
		std::cout << "\n\n";
		system("pause");
		system("cls");
	}
}

int main() {
	QuanLyHoSoIniatior(QLHSTS);
	QuanLyTheoMenu();
}

