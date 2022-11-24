#include <iostream>
#include <cmath>
#include<cstring>
using namespace std;

void Binary(int num, int arr[]) {
	int binary[32] = { }; //2진수 결과 값 보관용, 0으로 배열 초기화
	int O[32] = { };  //1의 보수 보관용
	int k;  //반복용
	int SIGN = 1;  //num 부호확인용

	if (num < 0) {  //num이 음수인 경우
		num = -num;  //음수 부호 생략
		SIGN = -1;
	}
	for (k = 0; num > 0; k++) {  //32비트 끝부터 문자 저장
		int M = num % 2; //나머지 저장 변수
		binary[k] = M;
		num /= 2;
	}

	if (SIGN == -1) {  //num이 음수인 경우 2의 보수 방법으로 나타냄
		for (int j = 0; j <= 31; j++) {  //1의 보수
			O[j] = 1 - binary[j];
		}

		int C = 1;  //캐리
		for (int j = 0; j <= 31; j++) {
			binary[j] = 1;
			if (O[j] == C) {
				binary[j] = 0;
			}
			C = O[j] * C;
		}
	}

	copy(binary, binary+32, arr);

	//2진수 출력
	cout << "2진수: ";
	for (int j = 31; j >= 0; j--) {
		cout << binary[j];
	}
	cout << endl;
}

void Octal(int num, int arr[]) {
	int octal[32] = {};  //8진수 결과 값 보관용, 0으로 배열 초기화
	int k;  //반복용
	int i=0, D = 0;  //i는 octal 인덱스용,, D는 2진수를 8진수로 변환하기 위한 임시값

	for (int k = 0; k < 32; k++) {
		int T1 = pow(2, k % 3);
		int T2 = arr[k] * T1;
		D += T2;

		if (((k % 3) == 2) || k==31) {
			octal[i] = D;
			D = 0;
			i++;
		}
	}

	//8진수 출력
	cout << "8진수: ";
	for (int j = i-1; j >= 0; j--) {
		cout << octal[j];
	}
	cout << endl;
}

void Hex(int num, int arr[]) {
	//문자형 배열 변수 선언, 배열 H는 H(0)부터 H(15)까지 선언한다.
	char H[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	char Hex[32] = ""; //16진수 값을 저장할 배열 Hex, 값은 0으로 초기화
	int k;  //반복용변수이면서 생성될 16진수의 자릿수를 나타내며 16진수를 저장할 배열 Hex의 원소를 지정한다.
	int i = 0, D = 0;  //i는 Hex 인덱스용, D는 2진수를 8진수로 변환하기 위한 임시값

	for (int k = 0; k < 32; k++) {
		int T1 = pow(2, k % 4);
		int T2 = arr[k] * T1;
		D += T2;

		if (((k % 4) == 3) || k==31) {
			Hex[i] = H[D];
			D = 0;
			i++;
		}
	}

	//16진수 출력
	cout << "16진수: ";
	for (int j =i-1; j >= 0; j--) {
		cout << Hex[j];
	}
	cout << endl;
}

int main() {
	int T[32] = { };  //2진수 배열 보관용

	cout << "정수 1개를 입력하시오. (ㅡ2,147,483,648부터 2,147,483,647 사이)" << endl;
	cout << "입력>> ";
	int d;
	cin >> d;
	cout << "--------------------------------------" << endl << endl;

	if (d > INT_MIN && d < INT_MAX) {
		Binary(d, T);
		Octal(d, T);
		Hex(d, T);
	}
	else {
		cout << "오류 (잘못된 입력값입니다.)" << endl;
	}
}
