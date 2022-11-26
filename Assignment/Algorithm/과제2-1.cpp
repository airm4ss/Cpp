#include <iostream>
using namespace std;

int main() {
	int A[5][5];  //2차원 배열 A
	int N = 1, M = 5, V = 0;  //M은 배열 대각선 갯수의 중간값

	//V+=1 순서도에서는 이 위치에 삽입되어야 하지만 C++은 순서도와 다르게 배열 행, 열 번호가 0부터 시작하기 때문에 아래 위치에 삽입
	for (int i = 0; i < M; i++) {
		for (int j = i; j >= 0; j--) {
			int C = j;
			int R = V - j;
			A[C][R] = N;
			N += 1;
		}
		V += 1;
	}

	//V+=1 순서도에서는 이 위치에 삽입되어야 하지만 C++은 순서도와 다르게 배열 행, 열 번호가 0부터 시작하기 때문에 아래 위치에 삽입
	for (int i = 1; i < M; i++) {
		for (int j = 4; j >= i; j--) {
			int C = j;
			int R = V - j;
			A[C][R] = N;
			N += 1;
		}
		V += 1;
	}

	for (int i = 0; i < 5; i++) {  //배열A 출력
		for (int j = 0; j < 5; j++)
			cout << A[i][j] << "\t";
		cout << endl;
	}
}
