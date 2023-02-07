#include <iostream>
using namespace std;

void join(string *name, string *ID,int *PW)  //회원가입
{
	cout << "이름을 입력하세요: ";
	cin >> *name;
	cout << "아이디 입력하세요: ";
	cin >> *ID;
	cout << "비밀번호를 입력하세요(숫자만): ";
	cin >> *PW;
	cout << "회원가입이 완료되었습니다.\n\n";
}

void login(string*name, string* ID, int* PW, int *check)  //로그인
{
	cout << "아이디: ";
	string id;
	cin >> id;

	cout << "비밀번호: ";
	int pw;
	cin >> pw;

	if (*ID == id && *PW == pw) {
		cout << "=== 로그인 성공 ===\n\n";
		cout << *name << "님 환영합니다.\n\n";
		*check = 1;
	}
	else {
		cout << "아이디 혹은 비밀번호가 틀렸습니다.\n\n";
	}

}

void total(int* b, int* sum) //모든 은행 계좌 금액의 총합
{
	*sum = 0;
	for (int i = 0; i < 4; i++)
	{
		*sum += b[i];
	}
}

void myaccounts(string* bn, int* b) //함수 실행 시 은행 계좌 별 금액 출력
{
	cout << "--------------- 은행 별 계좌정보 ----------------" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "  " << bn[i] << "    |  ";
	}
	cout << "\n";
	for (int i = 0; i < 4; i++)
	{
		cout << "  " << b[i] << "    |  ";
	}
	cout << "\n";
	cout << "-------------------------------------------------" << endl;
}

void print(int *check) {
	if (*check == 1) {
		string bank_name[4] = { "하나", "우리", "신한", "국민" };
		int bank[4] = { 5000,4000,0,10 };
		int total_money;

		cout << "*************** SWING 자산관리 서비스 *****************" << endl;
		myaccounts(bank_name, bank);
		total(bank, &total_money);
		cout << "\n현재 SWING 자산관리 서비스에 등록된 회원님의 총 자산은 " << total_money << "원 입니다." << endl;
		cout << "*******************************************************\n" << endl;
	}
	else {
		cout << "[ 로그인을 하세요!! ]\n\n";
	}
}

int main()
{
	int input, PW, check=0;
	string ID, name;

	while (true) {
		cout << "1. 회원가입\n";
		cout << "2. 로그인\n";
		cout << "3. 총 자산 출력\n";
		cout << "4. 종료\n";

		cout << "번호를 입력하세요: ";
		cin >> input;
		cout << "\n";
		if (input == 1) { //회원가입
			join(&name, &ID, &PW);
		}
		if (input == 2) { //로그인
			login(&name, &ID, &PW, &check);
		}
		if (input == 3) { //총 자산 출력
			print(&check);
		}
		if (input == 4) { //종료
			break;
		}
	}
}