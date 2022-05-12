#include "pch.h"
#include "Validation.h"

void validation(int & num, int left, int right)
{
	using namespace std;
	bool flag = false;
	do {
		try {
			flag = false;
			cin >> num;
			if (num<left || num>right) throw out_of_range("Input is out of range. Try again");
			
		}
		catch (out_of_range e) {
			flag = true;
			cout << e.what() << endl;
		}
		cin.ignore(32768, '\n');
	} while (flag);
}
