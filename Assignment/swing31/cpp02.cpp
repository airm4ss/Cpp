#include <iostream>
using namespace std;

int main()
{
	int seat[10][6] = { { },{ },{ } };
	int choice, seat_r, seat_l;

	do
	{
		cout << "����� �¼��� �����Ͻðڽ��ϱ�?(0�̳� 1����)  ";
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
			cout << "\n�� ��, �� �� �¼��� �����Ͻðڽ��ϱ�?";
			cin >> seat_r;
			cin >> seat_l;

			if (seat[seat_r - 1][seat_l - 1] == 0)
			{
				seat[seat_r - 1][seat_l - 1] = 1;

				cout << "����Ǿ����ϴ�.\n" << endl;
			}
			else if (seat[seat_r - 1][seat_l - 1])
			{
				cout << "�̹� ����� �ڸ��Դϴ�." << endl;
			}
		}
	} while (choice == 1);

	if (choice == 0)
		cout << "�¼� ���� ����" << endl;

}