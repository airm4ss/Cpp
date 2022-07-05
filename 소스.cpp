#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Character {  //Character Ŭ���� ����
private:
	char* name;
	int age;
	char* job;
public:
	Character(const char* name, int age, const char* job);  //������ ����
	Character(const Character &character);  //���� ������ ����
	void show() {
		cout << "******ĳ���� ����*******" << endl;
		cout << "ĳ���� �̸�: " << name << endl;
		cout << "ĳ���� ����: " << age << endl;
		cout << "ĳ���� ����" << job << endl << endl; }

	~Character();
};

Character::Character(const char* name, int age, const char* job) {  //������ ����
	int len_n = strlen(name);
	this->name = new char[len_n + 1];
	strcpy(this->name, name);

	this->age = age;

	int len_j = strlen(job);
	this->job = new char[len_j + 1];
	strcpy(this->job, job);
}

Character::Character(const Character& c) {  //���� ������ ����
	name = new char[strlen(c.name) + 1];
	strcpy(name, c.name);
	
	this->age = c.age;

	job = new char[strlen(c.job) + 1];
	strcpy(job, c.job);
}
Character::~Character() {
	if (name)
		delete[]name,job;
}

int main()
{
	char i_name[30], i_job[30];
	int i_age;

	while (1) {
		cout <<endl<< "========ĳ���� ����========" << endl;
		cout << "1. ĳ���� ����" << endl;
		cout << "2. ĳ���� ����" << endl;
		cout << "3. ĳ���� ���� Ȯ��" << endl;
		cout << "4. ĳ���� ���� ����" << endl;
		cout << "5. ����" << endl;
		cout << "��ȣ�� �������ּ���: ";
		int input;
		cin >> input;

		if (input == 1)
		{
			cout << "������ ĳ������ �̸�, ����, ������ ������� �Է����ּ���.(�������� ����)" << endl;
			cout << "�������: ������ ������ �����Ӱ�!" << endl;
			cout << "--> ";
			cin >> i_name >> i_age >> i_job;
			cout << "ĳ���Ͱ� �����Ǿ����ϴ�." << endl;
		}
		if (input == 2)
		{
			Character person(i_name, i_age, i_job); //person ��ü-�Ϲ� ������ ȣ��
			Character copy(person); //copy ��ü-���� ������ ȣ��
			cout << "ĳ���Ͱ� ����Ǿ����ϴ�." << endl;
		}
		if (input == 3)
		{
			//person.show();
			//copy.show();
		}
		if (input == 4)
		{
			cout << "�����ϰ� ���� ĳ���͸� �����ϼ���.(1 or 2): ";
			int num;
			cin >>num;
			cout << "�����ϰ� ���� �̸�, ����, ������ �Է����ּ���." << endl;

			if (num == 1) {
				cout << "--> ";
				//cin >> person.n >> person.a >> person.j;
			}
			if (num == 2) {
				cout << "--> ";
				//cin >>copy.n >> copy.a >> copy.j;
			}
			cout << "���������� �����Ǿ����ϴ�." << endl;
			
		}
		if (input == 5)  //����
		{
			cout << "����Ǿ����ϴ�." << endl;
			break;
		}
	}

	return 0;
}