#include <iostream>
using namespace std;

void join(string *name, string *ID,int *PW)  //ȸ������
{
	cout << "�̸��� �Է��ϼ���: ";
	cin >> *name;
	cout << "���̵� �Է��ϼ���: ";
	cin >> *ID;
	cout << "��й�ȣ�� �Է��ϼ���(���ڸ�): ";
	cin >> *PW;
	cout << "ȸ�������� �Ϸ�Ǿ����ϴ�.\n\n";
}

void login(string*name, string* ID, int* PW, int *check)  //�α���
{
	cout << "���̵�: ";
	string id;
	cin >> id;

	cout << "��й�ȣ: ";
	int pw;
	cin >> pw;

	if (*ID == id && *PW == pw) {
		cout << "=== �α��� ���� ===\n\n";
		cout << *name << "�� ȯ���մϴ�.\n\n";
		*check = 1;
	}
	else {
		cout << "���̵� Ȥ�� ��й�ȣ�� Ʋ�Ƚ��ϴ�.\n\n";
	}

}

void total(int* b, int* sum) //��� ���� ���� �ݾ��� ����
{
	*sum = 0;
	for (int i = 0; i < 4; i++)
	{
		*sum += b[i];
	}
}

void myaccounts(string* bn, int* b) //�Լ� ���� �� ���� ���� �� �ݾ� ���
{
	cout << "--------------- ���� �� �������� ----------------" << endl;
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
		string bank_name[4] = { "�ϳ�", "�츮", "����", "����" };
		int bank[4] = { 5000,4000,0,10 };
		int total_money;

		cout << "*************** SWING �ڻ���� ���� *****************" << endl;
		myaccounts(bank_name, bank);
		total(bank, &total_money);
		cout << "\n���� SWING �ڻ���� ���񽺿� ��ϵ� ȸ������ �� �ڻ��� " << total_money << "�� �Դϴ�." << endl;
		cout << "*******************************************************\n" << endl;
	}
	else {
		cout << "[ �α����� �ϼ���!! ]\n\n";
	}
}

int main()
{
	int input, PW, check=0;
	string ID, name;

	while (true) {
		cout << "1. ȸ������\n";
		cout << "2. �α���\n";
		cout << "3. �� �ڻ� ���\n";
		cout << "4. ����\n";

		cout << "��ȣ�� �Է��ϼ���: ";
		cin >> input;
		cout << "\n";
		if (input == 1) { //ȸ������
			join(&name, &ID, &PW);
		}
		if (input == 2) { //�α���
			login(&name, &ID, &PW, &check);
		}
		if (input == 3) { //�� �ڻ� ���
			print(&check);
		}
		if (input == 4) { //����
			break;
		}
	}
}