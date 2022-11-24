#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class GameCharacter {  //Character 클래스 선언
private:
	char* name;
	int age;
	char* job;
public:
	GameCharacter(const char* name, int age, const char* job);  //생성자 선언
	GameCharacter(const GameCharacter& character);  //복사 생성자 선언

	~GameCharacter();  //소멸자 선언
	void show() {  //캐릭터 출력하기
		cout << "******캐릭터 정보*******" << endl;
		cout << "캐릭터 이름: " << name << endl;
		cout << "캐릭터 나이: " << age << endl;
		cout << "캐릭터 직업: " << job << endl << endl;
	}
};

GameCharacter::GameCharacter(const char* name, int age, const char* job) {  //생성자 구현
	int len_n = strlen(name);
	this->name = new char[len_n + 1];
	strcpy(this->name, name);

	this->age = age;

	int len_j = strlen(job);
	this->job = new char[len_j + 1];
	strcpy(this->job, job);
}

GameCharacter::GameCharacter(const GameCharacter& c) {  //깊은 복사 생성자 구현
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

GameCharacter::~GameCharacter() {  //소멸자 구현
	delete[]name, job;
}

int main()
{
	char i_name[30], i_job[30];
	int i_age;
	char name2[30], job2[30];
	int age2;
	while (1) {    //while(1)로 무한루프를 사용해서 입력값이 5(종료)가 아닌 이상 무한 반복
		cout << endl << "========캐릭터 관리========" << endl;
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
			cin >> i_name >> i_age >> i_job; //cin은 공백으로 문자 구분
			cout << "캐릭터가 생성되었습니다." << endl;
			GameCharacter person(i_name, i_age, i_job); //person 객체-일반 생성자 호출
		}
		if (input == 2)
		{
			cout << "캐릭터가 복사되었습니다." << endl;
			GameCharacter copy(person); //copy 객체-복사 생성자 호출
		}
		if (input == 3)
		{
			person.show();
			copy.show();
		}
		if (input == 4)
		{
			cout << "수정하고 싶은 캐릭터를 선택하세요.(1 or 2): ";
			int num;
			cin >> num;

			if (num == 1) {
				cout << "설정하고 싶은 이름, 나이, 직업을 입력해주세요." << endl;
				cout << "--> ";
				cin >> name2 >> age2 >>job2;
				strcpy(person.name, name2);
				person.age = age2;
				strcpy(person.job,job2);
				cout << "정상적으로 수정되었습니다." << endl;
			}
			if (num == 2) {
				cout << "설정하고 싶은 이름, 나이, 직업을 입력해주세요." << endl;
				cout << "--> ";
				cin >> name2 >> age2 >> job2;
				strcpy(copy.name, name2);
				copy.age = age2;
				strcpy(copy.job, job2);
				cout << "정상적으로 수정되었습니다." << endl;
			}

		}
		if (input == 5)  //종료
		{
			cout << "종료되었습니다." << endl;
			break;
		}
	}

	return 0;
}
