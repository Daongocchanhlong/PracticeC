#include <iostream>
#include <math.h>
#include <string>
#include <thread>
#include <Windows.h>
using namespace std;

int counttime = 0;
int countquesion = 0;
void waittime()
{
	while (countquesion != 10)
	{
		counttime = counttime + 1;
		Sleep(1000);
	}
}

int main()
{
	string name;
	char choosetf;
	char choosecb;
	int point = 0;
	do
	{
		cout << "welcome to play quickmath\n";
		cout << "please enter your name:"; 
		getline(cin, name);
		thread threadtime(waittime);
		for (int i = 0; i < 10; i++)
		{
			countquesion = i;
			int numbera = rand() % 10 + 1;
			int numberb = rand() % 10 + 1;

			int result = rand() % 2;
			if (result == 0)
			{
				cout << "quesiong " << i + 1 << " : " << numbera << " + " << numberb << " = " << numbera + numberb << " ?";
				cout << "\nplease choose True or false (t/f) : "; cin >> choosetf;
				if (choosetf == 't') point++;

			}
			else
			{
				cout << "quesiong " << i + 1 << " : " << numbera << " + " << numberb << " = " << rand() % 20 + 2 << " ?";
				cout << "\nplease choose True or false (t/f) : "; cin >> choosetf;
				if (choosetf == 'f') point++;
			}
			system("cls");
		}
		cout << "player " << name << " has " << point << " correct question\n for "<< counttime ;
		threadtime.join();
		cout << "Do you want to continue ! (y/n) : "; cin >> choosecb;
	} while (choosecb != 'n');
	system("pause");
	return 0;

}