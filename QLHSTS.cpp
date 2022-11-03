/*
Nhom 7 - Hanoi Close University Manager
- Nguyen Quang Ha - 2110A03
- Nguyen Van Dung - 2110A03
- Ta Huu Cuong - 2110A03
*/

#include <bits/stdc++.h>

using namespace std;
const int NGANH_MAX = 3;
const int KHOA_MAX = 3;
const int NGANH_DKI_MAX = 10;

struct Nganh {
	char sMaNganh[50];
	char sTenNganh[50];
	float fDiemChuan;
	int iChiTieu;
};

struct Khoa {
	char sMaKhoa[50];
	char sTenKhoa[50];
	char sDiaChi[50];
	Nganh dsNG[NGANH_MAX];
};

struct ThiSinh
{
	char sMaHS[50];
	char sSBD[50];
	char sHoTen[50];
	char sNgaySinh[50];
	char sQueQuan[50];
	char sKhuVuc[50];
	char sGioiTinh[50];
	char sSDT[50];
	char NganhDKI[NGANH_DKI_MAX][50];
	float fDiemUT;
	float fDiemMon1;
	float fDiemMon2;
	float fDiemMon3;
	float fTongDiem;
	int slng;
};

struct QuanLyHoSoThiSinh {
	int sts;
	ThiSinh TS;
	// Khoa dsKH[KHOA_MAX];
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
	{{"NN1", "Tieng Trung", 24.94f, 150}, {"NN2", "Tieng Anh", 23.85f, 200},
	{"NN3", "Tieng Nhat", 22.5f, 100}},
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

// float DUT(string KV) {
// 	float UT = 0.0f;
// 	if (KV == "KV01")
// 		UT = 0.75f;
// 	else if (KV == "KV02")
// 		UT = 0.5f;
// 	else if (KV == "KV03")
// 		UT = 0.25f;
// 	else if (KV == "KV04")
// 		UT = 0.1f;
// 	return UT;
// }

void NhapThiSinh(ThiSinh& a) {
	std::cin.ignore();
	std::cout << "Nhap ma ho so: "; gets( a.sMaHS);
	std::cout << "Nhap so bao danh: "; gets( a.sSBD);
	std::cout << "Nhap ho ten thi sinh: "; gets( a.sHoTen);
	std::cout << "Nhap ngay sinh: "; gets( a.sNgaySinh);
	std::cout << "Nhap que quan: "; gets( a.sQueQuan);
	std::cout << "Nhap khu vuc: "; gets( a.sKhuVuc);
	std::cout << "Nhap gioi tinh: "; gets( a.sGioiTinh);
	std::cout << "Nhap so dien thoai: "; gets( a.sSDT);

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
		gets( a.NganhDKI[i]);
	}

	// Lay diem uu tien
	// a.fDiemUT = DUT(a.sKhuVuc);
	a.fDiemUT = (a.sKhuVuc == "KV01") ? 0.75 : (a.sKhuVuc == "KV02") ? 0.5 : (a.sKhuVuc == "KV03") ? 0.25 : (a.sKhuVuc == "KV04") ? 0.1 :0;

	std::cout << "Nhap diem mon 1: "; cin >> a.fDiemMon1;
	std::cout << "Nhap diem mon 2: "; cin >> a.fDiemMon2;
	std::cout << "Nhap diem mon 3: "; cin >> a.fDiemMon3;
	a.fTongDiem = a.fDiemMon1 + a.fDiemMon2 + a.fDiemMon3 + a.fDiemUT;


}

void TieuDeThiSinh()
{
	std::cout << std::endl << std::setw(5) << std::setiosflags(std::ios::left) << "STT";
	std::cout << std::setw(15) << "MA HS";
	std::cout << std::setw(15) << "SBD";
	std::cout << std::setw(32) << "Ho Ten";
	std::cout << std::setw(15) << "Ngay Sinh";
	std::cout << std::setw(15) << "Que Quan";
	std::cout << std::setw(10) << "KV";
	std::cout << std::setw(8) << "GT";
	std::cout << std::setw(15) << "So DT";
	std::cout << std::setw(12) << "Tong Diem";
}

void InThiSinh(ThiSinh a) {
	TieuDeThiSinh();
	std::cout << std::endl << std::setw(1) << std::setiosflags(std::ios::left) << "*)   ";
	std::cout << std::setw(15) << a.sMaHS;
	std::cout << std::setw(15) << a.sSBD;
	std::cout << std::setw(32) << a.sHoTen;
	std::cout << std::setw(15) << a.sNgaySinh;
	std::cout << std::setw(15) << a.sQueQuan;
	std::cout << std::setw(10) << a.sKhuVuc;
	std::cout << std::setw(8) << a.sGioiTinh;
	std::cout << std::setw(15) << a.sSDT;
	std::cout << std::setw(12) << a.fTongDiem;

	std::cout << "\n(Cac ma nganh dang ki)\n";
	for (int i = 0; i < a.slng; i++)
		cout << "- Ma nganh " << i + 1 << " : " << a.NganhDKI[i] << endl;
}

void NhapQuanLyHoSo(QuanLyHoSoThiSinh& a) {
	cout << "\n===NHAP THONG TIN HO SO===\n";
	// std::cout << "\nNhap so thi sinh muon nhap: "; cin >> a.sts;
	// for (int i = 0; i < a.sts; i++)
	// {
	// 	cout << "\n\n(Nhap Thi sinh thu " << i + 1 << ")" << endl;
	// 	NhapThiSinh(a.TS);
	// }
	NhapThiSinh(a.TS);

}



void InQuanLyHoSo(QuanLyHoSoThiSinh& a) {
	cout << "\n===HO SO CUA CAC THI SINH===\n";
	// for (int i = 0; i < a.sts; i++)
	// 	InThiSinh(a.dsTS[i]);
	InThiSinh(a.TS);
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

void NhapDSQLHSTS(ListQuanLyHoSoThiSinh& Q){
	int n,i;
	NodeQuanLyHoSoThiSinh* p;
	QuanLyHoSoThiSinh x;
	cout<<"Nhap so ho so can quan ly : ";
	cin>>n;
	for(i=0;i<n;i++){
		NhapQuanLyHoSo(x);
		p = getNodeQLHSTS(x);
		ChenDauQLHSTS(Q,p);
	}
}

// void NhapDSQLHSTS(ListQuanLyHoSoThiSinh& Q) {
// 	NodeQuanLyHoSoThiSinh* p;
// 	QuanLyHoSoThiSinh x;
// 	NhapQuanLyHoSo(x);
// 	p = getNodeQLHSTS(x);
// 	ChenDauQLHSTS(Q, p);
// }

void InDSQLHSTS(ListQuanLyHoSoThiSinh& Q) {
	NodeQuanLyHoSoThiSinh* p;
	cout<<"Danh sach ho so sinh vien\n";
	for (p = Q.head; p != NULL; p = p->next) {
		InQuanLyHoSo(p->info);
	}
}

void  sapXepDiem_Desc(ListQuanLyHoSoThiSinh& Q){
	NodeQuanLyHoSoThiSinh* p,*q;
	QuanLyHoSoThiSinh temp;
	for (p = Q.head; p != NULL; p = p->next){
		for (q = p -> next; q != NULL; q = q-> next) {
			if(p->info.TS.fTongDiem < q->info.TS.fTongDiem){
				temp = p->info;
				p->info = q->info;
				q->info = temp;
			}
		}
	}
	

}
NodeQuanLyHoSoThiSinh *search_Name(ListQuanLyHoSoThiSinh& Q, string name){
	NodeQuanLyHoSoThiSinh* p;
	p= Q.head;
	while(p != NULL) {
		if(p->info.TS.sHoTen == name){
			return p;

		}
		p= p->next;
	}

}
void timkiemDSName(ListQuanLyHoSoThiSinh& Q){
	string name;
	cin.ignore();
	cout <<"Nhap ten thi sinh can tim : ";
	getline(cin, name);
	NodeQuanLyHoSoThiSinh *p = search_Name(Q, name);
	if(p != NULL){
		for(p= Q.head; p != NULL; p = p->next){
			if(p->info.TS.sHoTen == name){
				InQuanLyHoSo(p->info);
			}
		}
	}else{
		cout<<"Error search_Name";
	}


}
void removeHS_dautien(ListQuanLyHoSoThiSinh& Q){
	NodeQuanLyHoSoThiSinh* p;
	if(Q.head != NULL){
		p = Q.head; 
		Q.head = Q.head -> next;
		delete p;
		if(Q.head == NULL){
			Q.tail= NULL;
		}
		cout<<"Remove complete!"<<endl;
	}else{
		cout<<"Not exist list !!!"<<endl;
	}

}

void MenuTitle()
{
	std::cout << "============= HE_THONG_TUYEN_SINH =============\n";
	std::cout << "|| 1. Nhap thong tin ho so                   ||\n";
	std::cout << "|| 2. Hien cac ho so                         ||\n";
	std::cout << "|| 3. Thong tin nganh va khoa cua truong     ||\n";
	std::cout << "|| 4. Sap xep thi sinh theo diem\n";
	std::cout << "|| 5. Tim kiem thi sinh theo ten\n";
	std::cout << "|| 6. Xoa ho so dau tien\n";
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
		sapXepDiem_Desc(QLHSTS);
		break;
	}
	case 5:
	{
		timkiemDSName(QLHSTS);
		break;
	}
	case 6:
	{
		removeHS_dautien(QLHSTS);
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

