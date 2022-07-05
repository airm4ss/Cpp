#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class GameCharacter {  //Character Ŭ���� ����
private:
	char* name;
	int age;
	char* job;
public:
	GameCharacter(const char* name, int age, const char* job);  //������ ����
	GameCharacter(const GameCharacter& character);  //���� ������ ����

	~GameCharacter();  //�Ҹ��� ����
	void show() {  //ĳ���� ����ϱ�
		cout << "******ĳ���� ����*******" << endl;
		cout << "ĳ���� �̸�: " << name << endl;
		cout << "ĳ���� ����: " << age << endl;
		cout << "ĳ���� ����: " << job << endl << endl;
	}
};

GameCharacter::GameCharacter(const char* name, int age, const char* job) {  //������ ����
	int len_n = strlen(name);
	this->name = new char[len_n + 1];
	strcpy(this->name, name);

	this->age = age;

	int len_j = strlen(job);
	this->job = new char[len_j + 1];
	strcpy(this->job, job);
}

GameCharacter::GameCharacter(const GameCharacter& c) {  //���� ���� ������ ����
	this->name = c.name;
	int len_n = strlen(c.name);
	this->name=new char[len_n+1];
	strcpy(this->name, c.name);

	this->age = c.age;

	this->job = c.job;
	int len_j = strlen(c.job);
	this->job=new char[len_j+1];
	strcpy(this->job, c.job);
}

GameCharacter::~GameCharacter() {  //�Ҹ��� ����
	delete[]name, job;
}

int main()
{
	char i_name[30], i_job[30];
	int i_age;
	char name2[30], job2[30];
	int age2;
	while (1) {    //while(1)�� ���ѷ����� ����ؼ� �Է°��� 5(����)�� �ƴ� �̻� ���� �ݺ�
		cout << endl << "========ĳ���� ����========" << endl;
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
			cin >> i_name >> i_age >> i_job; //cin�� �������� ���� ����
			cout << "ĳ���Ͱ� �����Ǿ����ϴ�." << endl;
			GameCharacter person(i_name, i_age, i_job); //person ��ü-�Ϲ� ������ ȣ��
		}
		if (input == 2)
		{
			cout << "ĳ���Ͱ� ����Ǿ����ϴ�." << endl;
			GameCharacter copy(person); //copy ��ü-���� ������ ȣ��
		}
		if (input == 3)
		{
			person.show();
			copy.show();
		}
		if (input == 4)
		{
			cout << "�����ϰ� ���� ĳ���͸� �����ϼ���.(1 or 2): ";
			int num;
			cin >> num;

			if (num == 1) {
				cout << "�����ϰ� ���� �̸�, ����, ������ �Է����ּ���." << endl;
				cout << "--> ";
				cin >> name2 >> age2 >>job2;
				strcpy(person.name, name2);
				person.age = age2;
				strcpy(person.job,job2);
				cout << "���������� �����Ǿ����ϴ�." << endl;
			}
			if (num == 2) {
				cout << "�����ϰ� ���� �̸�, ����, ������ �Է����ּ���." << endl;
				cout << "--> ";
				cin >> name2 >> age2 >> job2;
				strcpy(copy.name, name2);
				copy.age = age2;
				strcpy(copy.job, job2);
				cout << "���������� �����Ǿ����ϴ�." << endl;
			}

		}
		if (input == 5)  //����
		{
			cout << "����Ǿ����ϴ�." << endl;
			break;
		}
	}

	return 0;
}