/*
Nhom 7 - Hanoi Close University Management
- Nguyen Quang Ha (2110A03)
- Nguyen Van Dung (2110A03)
- Ta Huu Cuong    (2110A03)
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;
const int MAJOR_MAX = 3;
const int FACULTY_MAX = 3;
const int MAJOR_SIGN_MAX = 10;
FILE* file;

struct Major {
	char sMajorCode[100];
	char sMajorName[100];
	float fBenchMark;
	int iTarget;
};

struct Faculty {
	char sFacultyCode[100];
	char sFacultyName[100];
	char sAddress[100];
	Major MajorList[MAJOR_MAX];
};

struct Student
{
	char sProfileCode[100] = "NULL";
	char sNumber[100] = "NULL";
	char sName[100] = "NULL";
	char sDOB[100] = "NULL";
	char sHometown[100] = "NULL";
	char sArea[100] = "NULL";
	char sGender[100] = "NULL";
	char sPhoneNumber[100] = "NULL";
	char MajorSign[MAJOR_SIGN_MAX][100];
	float fPlusPoint = 0.0f;
	float fPoint1 = 0.0f;
	float fPoint2 = 0.0f;
	float fPoint3 = 0.0f;
	float fOverallPoint = 0.0f;
	int iMJAmount = 0;
};

struct ProfileManagement {
	Student Student;
};

struct NodeProfileManagement {
	ProfileManagement info;
	struct NodeProfileManagement* next = next;
};

struct ListProfileManagement {
	NodeProfileManagement* head;
	NodeProfileManagement* tail;
};

ListProfileManagement QLHSTS;

// ===================================================================================

Faculty FIT =
{ "FIT", "Information Technology", "96 DC Street",
	{{"IT1", "Computer Sience", 28.94f, 150}, {"IT2", "General IT", 27.85f, 300},
	{"IT3", "Tech Math", 26.5f, 100}},
};

Faculty FOL =
{ "FOL", "Mutiple Languages", "101 NH Street",
	{{"OL1", "Chinese", 27.94f, 150}, {"OL2", "English", 28.35f, 200},
	{"OL3", "Japanese", 26.5f, 100}},
};

Faculty FJC =
{ "FJC", "Journalism And Communication", "32 DV Street",
	{{"JC1", "Reporter", 24.94f, 175}, {"JC2", "Event Analysis", 23.35f, 100},
	{"JC3", "Editor", 25.12f, 50}},
};


void FacultyTitle() {
	std::cout << std::endl << std::setw(5) << std::setiosflags(std::ios::left) << "STT";
	std::cout << std::setw(15) << "FacultyCode";
	std::cout << std::setw(30) << "Name";
	std::cout << std::setw(20) << "Address";
}

void ShowMajor(Major a) {
	cout << "- Major Code: " << a.sMajorCode << endl;
	cout << "- Major Name: " << a.sMajorName << endl;
	cout << "- Bench Mark: " << a.fBenchMark << endl;
	cout << "- Target: " << a.iTarget << endl;
	cout << endl;
}

void ShowFaculty(Faculty a) {
	FacultyTitle();
	std::cout << std::endl << std::setw(1) << std::setiosflags(std::ios::left) << "*)   ";
	std::cout << std::setw(15) << a.sFacultyCode;
	std::cout << std::setw(30) << a.sFacultyName;
	std::cout << std::setw(20) << a.sAddress;
	cout << endl;
	cout << "\n(Majors In Faculty Of " << a.sFacultyName << ")\n" << endl;
	for (int i = 0; i < MAJOR_MAX; i++)
		ShowMajor(a.MajorList[i]);
}

float PlusPoint(string Area) {
	float Plus = 0.0f;
	if (Area == "AR01")
		Plus = 0.75f;
	else if (Area == "AR02")
		Plus = 0.5f;
	else if (Area == "AR03")
		Plus = 0.25f;
	else if (Area == "AR04")
		Plus = 0.0f;
	return Plus;
}

void InputStudent(Student& a, ListProfileManagement& Q, bool& primaryKeyCheck) {
	primaryKeyCheck = true;
	NodeProfileManagement* p;
	std::cin.ignore();
	std::cout << "Type Profile code: "; std::cin.getline(a.sProfileCode, 100);
	for (p = Q.head; p != NULL; p = p->next) {
		if (strcmp(p->info.Student.sProfileCode, a.sProfileCode) == 0) {
			cout << "\nProfile Code is Duplicated!";
			primaryKeyCheck = false;
			return;
		}
	}
	std::cout << "Type Number: "; std::cin.getline(a.sNumber, 100);
	std::cout << "Type Name: "; std::cin.getline(a.sName, 100);
	std::cout << "Type Date of birth: "; std::cin.getline(a.sDOB, 100);
	std::cout << "Type Hometown: "; std::cin.getline(a.sHometown, 100);
	std::cout << "Type Area (AR__): "; std::cin.getline(a.sArea, 100);
	std::cout << "Type Gender: "; std::cin.getline(a.sGender, 100);
	std::cout << "Type Phone number: "; std::cin.getline(a.sPhoneNumber, 100);

	a.iMJAmount = 0;
	do
	{
		std::cout << "\nType your desired major amount (<10): ", cin >> a.iMJAmount;
		if (a.iMJAmount > MAJOR_SIGN_MAX) {
			cout << "\nLess than 10 majors is allowed\nPlease try again....";
		}
	} while (a.iMJAmount > MAJOR_SIGN_MAX);
	std::cin.ignore();
	for (int i = 0; i < a.iMJAmount; i++)
	{
		std::cout << "Type major " << i + 1 << "(Only major code is allowed): ";
		std::cin.getline(a.MajorSign[i], 100);
	}

	a.fPlusPoint = PlusPoint(a.sArea);

	std::cout << "Type subject 1 point: "; cin >> a.fPoint1;
	std::cout << "Type subject 2 point: "; cin >> a.fPoint2;
	std::cout << "Type subject 3 point: "; cin >> a.fPoint3;
	a.fOverallPoint = a.fPoint1 + a.fPoint2 + a.fPoint3 + a.fPlusPoint;
}


void StudentTitle()
{
	std::cout << std::endl << std::setw(0) << std::setiosflags(std::ios::left);
	std::cout << std::setw(8) << "ProCode";
	std::cout << std::setw(10) << "Number";
	std::cout << std::setw(20) << "Name";
	std::cout << std::setw(15) << "DateOfBirth";
	std::cout << std::setw(15) << "Hometown";
	std::cout << std::setw(8) << "Area";
	std::cout << std::setw(9) << "Gender";
	std::cout << std::setw(15) << "PhoneNumber";
	std::cout << std::setw(12) << "OverallPoint";
}

void ShowStudent(Student a) {
	std::cout << std::endl << std::setw(0) << std::setiosflags(std::ios::left);
	std::cout << std::setw(8) << a.sProfileCode;
	std::cout << std::setw(10) << a.sNumber;
	std::cout << std::setw(20) << a.sName;
	std::cout << std::setw(15) << a.sDOB;
	std::cout << std::setw(15) << a.sHometown;
	std::cout << std::setw(8) << a.sArea;
	std::cout << std::setw(9) << a.sGender;
	std::cout << std::setw(15) << a.sPhoneNumber;
	std::cout << std::setw(12) << a.fOverallPoint;
}

void ShowMajorSignedUp(Student a) {
	std::cout << "\n(Major Of Profile " << a.sProfileCode << " Signed Up)\n";
	for (int i = 0; i < a.iMJAmount; i++)
		cout << "- Major code " << i + 1 << " : " << a.MajorSign[i] << endl;
}

void InputProfile(ProfileManagement& a, bool& primaryKeyCheck) {
	cout << "\n=== PROFILE INPUT ===\n";
	InputStudent(a.Student, QLHSTS, primaryKeyCheck);
}

void ShowMajorSignedUp(ProfileManagement& a) {
	ShowMajorSignedUp(a.Student);
}

void ShowProfile(ProfileManagement& a) {
	ShowStudent(a.Student);	
}

// ===================================================================================

void ProfileManagementIniatiator(ListProfileManagement& Q) {
	Q.head = NULL;
	Q.tail = NULL;
}

void SwapNode(NodeProfileManagement* p, NodeProfileManagement* q) {
	ProfileManagement temp;
	temp = p->info;
	p->info = q->info;
	q->info = temp;
}

NodeProfileManagement* GetNodeQLHSTS(ProfileManagement x) {
	NodeProfileManagement* p;
	p = new NodeProfileManagement();
	if (p == NULL) {
		cout << "\nGet Node Failed!";
		exit(0);
	}
	p->info = x;
	p->next = NULL;
	return p;
}

void AddHead(ListProfileManagement& Q, NodeProfileManagement* p) {
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

// OPTION 1: Input info to the list
void InputListProfile(ListProfileManagement& Q) {
	NodeProfileManagement* p;
	ProfileManagement x;
	bool check = true;
	InputProfile(x, check);
	if (check) {
		cout << "\nInput Successfully!";
		p = GetNodeQLHSTS(x);
		AddHead(Q, p);
	}
}

// OPTION 2: Show list
void ShowListProfile(ListProfileManagement& Q) {
	NodeProfileManagement* p;
	cout << "\n=== PROFILE INFOMATION ===\n";
	StudentTitle();
	for (p = Q.head; p != NULL; p = p->next) {
		ShowProfile(p->info);
	}
}

// OPTION 3: Show Majors And Faculty Info
void ShowFacultyAndMajor() {
	ShowFaculty(FIT);
	ShowFaculty(FOL);
	ShowFaculty(FJC);
}

// OPTION 4: Sort Profile By Descending OverallPoint
void SortDescendOP(ListProfileManagement& Q) {
	NodeProfileManagement* p, * q;
	ProfileManagement temp;
	for (p = Q.head; p != NULL; p = p->next) {
		for (q = p->next; q != NULL; q = q->next)
			if (p->info.Student.fOverallPoint < q->info.Student.fOverallPoint) {
				SwapNode(p, q);
			}
	}
	cout << "\nSuccessfully Sort By Descend!";
}

// OPTION 5: Sort Profile By Ascending OverallPoint
void SortAscendOP(ListProfileManagement& Q) {
	NodeProfileManagement* p, * q;
	ProfileManagement temp;
	for (p = Q.head; p != NULL; p = p->next) {
		for (q = p->next; q != NULL; q = q->next)
			if (p->info.Student.fOverallPoint > q->info.Student.fOverallPoint) {
				SwapNode(p, q);
			}
	}
	cout << "\nSuccessfully Sort By Ascend!";
}

// Return a node if code K exist in list
NodeProfileManagement* FindProfileCodeByK(ListProfileManagement Q, string h) {
	NodeProfileManagement* p;
	float min = Q.head->info.Student.fOverallPoint;
	p = Q.head;
	for (p = Q.head; p != NULL; p = p->next) {
		if (p->info.Student.sProfileCode == h)
			return p;
	}
}

// OPTION 6: Look For Profile By ProfileCode
void FindProfileCodeByK(ListProfileManagement& Q) {
	string h;
	cin.ignore();
	cout << "\nType your desired profile code to find: "; getline(cin, h);
	
	NodeProfileManagement* p;
	p = FindProfileCodeByK(Q, h);
	
	if (p == NULL)
		cout << "\nThis profile code is not valid!\n";
	else
		for (p = Q.head; p != NULL; p = p->next) {
			if (p->info.Student.sProfileCode == h)
			{
				StudentTitle();
				ShowProfile(p->info);
			}
				
		}
}

// OPTION 7: Delete First Profile
void RemoveHead(ListProfileManagement& Q) {
	NodeProfileManagement* p;
	if (Q.head != NULL) {
		p = Q.head;
		Q.head = Q.head->next;
		delete p;
		if (Q.head == NULL)
			Q.tail = NULL;
	}
}

// OPTION 8: Show Student With Max OverallPoint
void FindMaxPointProfile(ListProfileManagement Q) {
	NodeProfileManagement* p;
	float max = Q.head->info.Student.fOverallPoint;
	p = Q.head;
	while (p != NULL) {
		if (p->info.Student.fOverallPoint > max) {
			max = p->info.Student.fOverallPoint;
		}
		p = p->next;
	}
	StudentTitle();
	for (p = Q.head; p != NULL; p = p->next) {
		if (p->info.Student.fOverallPoint == max)
			ShowProfile(p->info);
	}
}

// OPTION 9: Show Student With Min OverallPoint
void ShowMinPoint(ListProfileManagement Q)
{
	NodeProfileManagement* p;
	float min = Q.head->info.Student.fOverallPoint;
	p = Q.head;
	while (p != NULL) {
		if (p->info.Student.fOverallPoint < min)
		{
			min = p->info.Student.fOverallPoint;
		}
		p = p->next;
	}
	StudentTitle();
	for (p = Q.head; p != NULL; p = p->next)
	{
		if (p->info.Student.fOverallPoint == min)
			ShowProfile(p->info);
	}
}

// OPTION 10: Save Profile To File
void SaveFile(ListProfileManagement Q) {
	FILE* f;
	f = fopen("ProfileList.dat", "wb");
	int n = 0;
	NodeProfileManagement* p;

	for (p = Q.head; p != NULL; p = p->next)
		n = n + 1;
	fwrite(&n, sizeof(int), 1, f);

	for (p = Q.head; p != NULL; p = p->next)
		fwrite(&p->info, sizeof(ProfileManagement), 1, f);
	fclose(f);
	cout << "\nSuccessfully Saved File!";
}

// OPTION 11: Read Profile From File
void ReadFile(ListProfileManagement& Q) {
	FILE* f;
	ProfileManagement x;
	int i, n;
	NodeProfileManagement* p;
	NodeProfileManagement* q;
	f = fopen("ProfileList.dat", "rb");
	fread(&n, sizeof(int), 1, f);
	bool check = true;
	int count = 0;
	
	for (i = 0; i < n; i++) {
		fread(&x, sizeof(ProfileManagement), 1, f);
		p = GetNodeQLHSTS(x);
		for (q = Q.head; q != NULL; q = q->next) {
			if (strcmp(p->info.Student.sProfileCode, q->info.Student.sProfileCode) == 0) {
				check = false;
			}
		}
		if (check) {
			AddHead(Q, p);
			count++;
		}
	}
	if (count > 0)
		cout << "\nSuccessfully Read File!";
	else
		cout << "\nUnsuccessfully Read File Due To Duplicated ProfileCode!";
	fclose(f);
}

// OPTION 12: Show Major(s) Signed Up
void ShowListMajorSignedUp(ListProfileManagement& Q) {
	NodeProfileManagement* p;
	cout << "\n=== MAJOR SIGNED UP ===\n";
	for (p = Q.head; p != NULL; p = p->next) {
		ShowMajorSignedUp(p->info);
	}
}

// OPTION 13: Sort Profile By Ascending Name
void SortProfilesByAscendByName(ListProfileManagement& Q) {
	ProfileManagement temp;
	NodeProfileManagement* p, * q;
	for (p = Q.head; p != NULL; p = p->next) {
		for (q = Q.head; q != NULL; q = q->next) {
			if (strcmp(p->info.Student.sName, q->info.Student.sName) > 0) {
				SwapNode(p, q);
			}
		}
	}
	cout << "\nSorted Successfully!";
}

// OPTION 14: Sort Profile By Descending Name
void SortProfilesByDescendByName(ListProfileManagement& Q) {
	ProfileManagement temp;
	NodeProfileManagement* p, * q;
	for (p = Q.head; p != NULL; p = p->next) {
		for (q = Q.head; q != NULL; q = q->next) {
			if (strcmp(p->info.Student.sName, q->info.Student.sName) < 0) {
				SwapNode(p, q);
			}
		}
	}
	cout << "\nSorted Successfully!";
}

// OPTION 15: Check Profile Status By ProfileCode

float ReturnMajorBenchMark(Major a) {
	return a.fBenchMark;
}

string ReturnMajorName(Major a) {
	return a.sMajorName;
}

string ReturnMajorCode(Major a) {
	return a.sMajorCode;
}

void CheckStatus(Faculty a, float ProfileOverallPoint, string MajorSignName) {
	for (int i = 0; i < MAJOR_MAX; i++)
	{
		if (ProfileOverallPoint > ReturnMajorBenchMark(a.MajorList[i])) {
			if (MajorSignName == ReturnMajorCode(a.MajorList[i])) {
				cout << "\nThis Profile Passed Major: " << ReturnMajorName(a.MajorList[i]) << endl;
				cout << "- Benchmark: " << ReturnMajorBenchMark(a.MajorList[i]) << endl;
				cout << "- Major Code: " << ReturnMajorCode(a.MajorList[i]);
			}
		}
	}
}

void CheckProfileStatus(ListProfileManagement& Q) {
	string h;
	cin.ignore();
	cout << "\nType your desired profile code to find: "; getline(cin, h);

	NodeProfileManagement* p;
	p = FindProfileCodeByK(Q, h);

	if (p == NULL)
		cout << "\nThis profile code is not valid!\n";
	else
		for (p = Q.head; p != NULL; p = p->next) {
			if (p->info.Student.sProfileCode == h)
			{
				for (int i = 0; i < p->info.Student.iMJAmount; i++) {
					if (strcmp(p->info.Student.MajorSign[i], ("IT1")) == 0
						|| strcmp(p->info.Student.MajorSign[i], ("IT2")) == 0
						|| strcmp(p->info.Student.MajorSign[i], ("IT3")) == 0) {
						CheckStatus(FIT, p->info.Student.fOverallPoint, p->info.Student.MajorSign[i]);
					}
					if (strcmp(p->info.Student.MajorSign[i], ("OL1")) == 0
						|| strcmp(p->info.Student.MajorSign[i], ("OL2")) == 0
						|| strcmp(p->info.Student.MajorSign[i], ("OL3")) == 0) {
						CheckStatus(FOL, p->info.Student.fOverallPoint, p->info.Student.MajorSign[i]);
					}
					if (strcmp(p->info.Student.MajorSign[i], ("JC1")) == 0
						|| strcmp(p->info.Student.MajorSign[i], ("JC2")) == 0
						|| strcmp(p->info.Student.MajorSign[i], ("JC3")) == 0) {
						CheckStatus(FJC, p->info.Student.fOverallPoint, p->info.Student.MajorSign[i]);
					}
				}
			}
		}
}


void MenuTitle()
{
	std::cout << "============= HANOI CLOSE UNIVERSITY =============\n";
	std::cout << "|| 1. Input Profiles                            ||\n";
	std::cout << "|| 2. Show Profiles                             ||\n";
	std::cout << "|| 3. Show Majors And Faculty Info              ||\n";
	std::cout << "|| 4. Sort Profile By Descending OverallPoint   ||\n";
	std::cout << "|| 5. Sort Profile By Ascending OverallPoint    ||\n";
	std::cout << "|| 6. Look For Profile By ProfileCode           ||\n";
	std::cout << "|| 7. Delete First Profile                      ||\n";
	std::cout << "|| 8. Show Student With Max OverallPoint        ||\n";
	std::cout << "|| 9. Show Student With Min OverallPoint        ||\n";
	std::cout << "|| 10. Save Profile To File                     ||\n";
	std::cout << "|| 11. Read Profile From File                   ||\n";
	std::cout << "|| 12. Show Major(s) Signed Up                  ||\n";
	std::cout << "|| 13. Sort Profile By Ascending Name           ||\n";
	std::cout << "|| 14. Sort Profile By Descending Name          ||\n";
	std::cout << "|| 15. Check Profile Status By Profile Code     ||\n";
	std::cout << "|| 0. EXIT                                      ||\n";
	std::cout << "==================================================\n";
}
int MenuChoice()
{
	int m = 0;
	std::cout << "\nType your choice: ";
	std::cin >> m;
	if (m > 0 || m < 15)
	{
		return m;
	}
	else
	{
		return MenuChoice();
	}
}
void MenuExecutor()
{
	int number = MenuChoice();
	switch (number) {
	case 1:
	{	InputListProfile(QLHSTS);
		break;
	}
	case 2:
	{	ShowListProfile(QLHSTS);
		break;
	}
	case 3:
	{	ShowFacultyAndMajor();
		break;
	}
	case 4:
	{	SortDescendOP(QLHSTS);
		break;
	}
	case 5: {
		SortAscendOP(QLHSTS);
		break;
	}
	case 6:
	{	FindProfileCodeByK(QLHSTS);
		break;
	}
	case 7:
	{	RemoveHead(QLHSTS);
		break;
	}
	case 8:
	{	ShowMinPoint(QLHSTS);
		break;
	}
	case 9:
	{	FindMaxPointProfile(QLHSTS);
		break;
	}
	case 10:
	{	SaveFile(QLHSTS);
		break;
	}
	case 11:{
		ReadFile(QLHSTS);
		break;
	}
	case 12: {
		ShowListMajorSignedUp(QLHSTS);
		break;
	}
	case 13: {
		SortProfilesByAscendByName(QLHSTS);
		break;
	}
	case 14: {
		SortProfilesByDescendByName(QLHSTS);
		break;
	}
	case 15: {
		CheckProfileStatus(QLHSTS);
		break;
	}
	case 16: {
		break;
	}
	case 17: {
		break;
	}
	case 0:{
		exit(0);
		break;
	}
	default: {
		cout << "\nYour choice is not valid...";
		break;
	}
	}
}

void MenuManagement() {
	while (true)
	{
		MenuTitle();
		MenuExecutor();
		std::cout << "\n\n";
		system("pause");
		system("cls");
	}
}

int main() {
	ProfileManagementIniatiator(QLHSTS);
	MenuManagement();
	return 0;
}

