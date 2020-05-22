#include <iostream>
#include "Queue.h"
using namespace std;

void menu() {
	cout << "������� a [�����], ���� ������ �������� ������� � �������\n";
	cout << "������� d, ���� ������ ������� ������� �� �������\n";
	cout << "������� p, ���� ������ ������� �������\n";
	cout << "������� f, ���� ������ ���������� ������ �������� �������\n";
	cout << "������� e, ���� ������ �����\n";
}

int main() {
	setlocale(LC_ALL, "Russian");
	Queue<int> q;
	menu();
	char c;
	Queue<int> t;
	cin >> c;
	while (c != 'e') {
		switch (c)
		{
		case 'a':
			int e;
			cin >> e;
			q.push(e);
			break;
		case 'd':
			if (q.isEmpty()) {
				cout << "Queue is empty\n";
			}
			else {
				q.pop();
			}
			break;
		case 'f':
			if (q.isEmpty()) {
				cout << "Queue is empty\n";
			}
			else {
				cout << q.top() << endl;
			}
			break;
		case 'p':
			q.print();
			cout << endl;
			break;
		case 'e':
			return 0;
			break;
		default:
			cout << "error";
			break;
		}
		cin >> c;
	}

}