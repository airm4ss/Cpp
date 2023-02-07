#include <iostream>
using namespace std;

int main()
{
	int seat[10][6] = { { },{ },{ } };
	int choice, seat_r, seat_l;

	do
	{
		cout << "비행기 좌석을 예매하시겠습니까?(0이나 1선택)  ";
		cin >> choice;

		if (choice == 1)
		{
			cout << "1 2 3	4 5 6" << endl;
			cout << "---------------------" << endl;

			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					cout << seat[i][j] << " ";
					if (j == 2) {
						cout << "	";
					}
				}
				cout << endl;
			}
			cout << "\n몇 행, 몇 열 좌석을 예약하시겠습니까?";
			cin >> seat_r;
			cin >> seat_l;

			if (seat[seat_r - 1][seat_l - 1] == 0)
			{
				seat[seat_r - 1][seat_l - 1] = 1;

				cout << "예약되었습니다.\n" << endl;
			}
			else if (seat[seat_r - 1][seat_l - 1])
			{
				cout << "이미 예약된 자리입니다." << endl;
			}
		}
	} while (choice == 1);

	if (choice == 0)
		cout << "좌석 예약 종료" << endl;

}