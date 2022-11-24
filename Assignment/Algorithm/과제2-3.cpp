#include <iostream>
using namespace std;

int main() {
	int C[5][5];  //2차원 배열 C
	int N = 0, S = -1, i = 2, j = 2, k = 1;  //초깃값 설정
	//N: 배열 원소에 채우는 자연수로서 1부터 25까지 변하는 변수
	//i: 배열 행 변수, j: 배열 열 변수
	//S: 행과 열의 증감용 변수
	//K: 배열에 숫자를 배정하는 수행 횟수에 대한 변수

	while (true) {  //무한반복
		for (int p = 0; p < k; p++) {
			N += 1;
			C[i][j] = N;
			i += S;  //S에 따른 행 증감
		}
		S = -S;
		if (k == 5) break;  //k=5일 경우 무한반복문을 탈출
		for (int p = 0; p < k; p++) {
			N += 1;
			C[i][j] = N;
			j += S;  //S에 따른 열 증감
		}
		k += 1; //k 1증가
	}

	for (int i = 0; i < 5; i++) {  //배열C 출력
		for (int j = 0; j < 5; j++)
			cout <<"  "<< C[i][j];
		cout << endl;
	}
}
