#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Character {  //Character 클래스 선언
private:
	char* name;
	int age;
	char* job;
public:
	Character(const char* name, int age, const char* job);  //생성자 선언
	Character(const Character &character);  //복사 생성자 선언
	void show() {
		cout << "******캐릭터 정보*******" << endl;
		cout << "캐릭터 이름: " << name << endl;
		cout << "캐릭터 나이: " << age << endl;
		cout << "캐릭터 직업" << job << endl << endl; }

	~Character();
};

Character::Character(const char* name, int age, const char* job) {  //생성자 구현
	int len_n = strlen(name);
	this->name = new char[len_n + 1];
	strcpy(this->name, name);

	this->age = age;

	int len_j = strlen(job);
	this->job = new char[len_j + 1];
	strcpy(this->job, job);
}

Character::Character(const Character& c) {  //복사 생성자 구현
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
		cout <<endl<< "========캐릭터 관리========" << endl;
		cout << "1. 캐릭터 생성" << endl;
		cout << "2. 캐릭터 복사" << endl;
		cout << "3. 캐릭터 정보 확인" << endl;
		cout << "4. 캐릭터 정보 수정" << endl;
		cout << "5. 종료" << endl;
		cout << "번호를 선택해주세요: ";
		int input;
		cin >> input;

		if (input == 1)
		{
			cout << "생성할 캐릭터의 이름, 나이, 직업을 순서대로 입력해주세요.(공백으로 구분)" << endl;
			cout << "참고사항: 직업의 종류는 자유롭게!" << endl;
			cout << "--> ";
			cin >> i_name >> i_age >> i_job;
			cout << "캐릭터가 생성되었습니다." << endl;
		}
		if (input == 2)
		{
			Character person(i_name, i_age, i_job); //person 객체-일반 생성자 호출
			Character copy(person); //copy 객체-복사 생성자 호출
			cout << "캐릭터가 복사되었습니다." << endl;
		}
		if (input == 3)
		{
			//person.show();
			//copy.show();
		}
		if (input == 4)
		{
			cout << "수정하고 싶은 캐릭터를 선택하세요.(1 or 2): ";
			int num;
			cin >>num;
			cout << "설정하고 싶은 이름, 나이, 직업을 입력해주세요." << endl;

			if (num == 1) {
				cout << "--> ";
				//cin >> person.n >> person.a >> person.j;
			}
			if (num == 2) {
				cout << "--> ";
				//cin >>copy.n >> copy.a >> copy.j;
			}
			cout << "정상적으로 수정되었습니다." << endl;
			
		}
		if (input == 5)  //종료
		{
			cout << "종료되었습니다." << endl;
			break;
		}
	}

	return 0;
}