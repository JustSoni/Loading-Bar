#include <iostream>
#include <thread>

using namespace std;

void DisplayBar(char startChar, char endChar, bool percentageShown, char fillerChar, char emptyChar, int lenghtOfBar, int timeOfExecution, double startProgress)
{
	int lenght = lenghtOfBar;
	char bar[150];//The maximum lenght can be x-2. 2 because of the enclosing characters. X=150 here.
	int time = timeOfExecution * 10;// Multiplies the input.
	int i = 0;

	int des = 48, ed = 48;

	double currrentProgress = startProgress * 10;

	int perc = currrentProgress;//The percentage starts from [0 to 1]
	bar[0] = startChar;
	bar[lenght + 1] = endChar;

	bar[0] = startChar;

	for (int i = 1; i <= lenght; i++)
	{
		bar[i] = emptyChar;//Fills the array with empty chars
	}

	for (int i = 1; i <= lenght * currrentProgress / 100; i++)
	{
		bar[i] = fillerChar;//Fill the array up untill [x;1]
	}

	for (int i = 1; i <= lenght; i++)
	{
		cout << bar[i];// Prints out the array once at the beginning
	}

	bar[lenght + 1] = endChar;

	system("CLS");

	bar[0] = startChar;
	for (i = startProgress*100; perc < 100; perc++)
	{
		i++;

		bar[i / (100 / lenght)] = fillerChar;//Some maths to do the job of filling the bar.
		bar[0] = startChar;

		des = 48 + perc / 10;//48 is ASCII... of 0;
		ed = 48 + perc % 10;
		if (percentageShown)
		{
			bar[(lenght - 1) / 2 - 1] = des;
			bar[(lenght - 1) / 2] = ed;
			bar[(lenght - 1) / 2 + 1] = '%';
		}

		for (int i = 0; i <= lenght + 1; i++)
		{
			cout << bar[i];//Prints out the bar filled up until some point.
		}
		cout << "\n";
		{
			system("CLS");
		}
		this_thread::sleep_for(std::chrono::milliseconds(time));
	}

	if (percentageShown)//If you wrote 1 in the beginning the percentages will be shown and vice versa with 0
	{
		bar[(lenght - 1) / 2 - 2] = 49;
		bar[(lenght - 1) / 2 - 1] = 48;
		bar[(lenght - 1) / 2] = 48;
	}
	//
	cout << "Perc:" << perc << endl;
	for (int i = 0; i <= lenght + 1; i++)
	{
		cout << bar[i];//Prints out the filled bar
	}
}

int main() // Example of input [ ] 1 = - 100 10
{
	char startChar = '[';
	char endChar = ']';
	bool percentageShown = 49;
	char fillerChar = '=';
	char emptyChar = '-';
	int lenghtOfBar = 100;//You may change it.
	int timeOfExecution = 0;
	double startProgress = 0;//[0;1] You may change it.
	//These are default values.

	cout << "Do you want the percentages to be shown? 1- Yes, 0- No: ";
	cin >> percentageShown;
	cout << "The bar need minimum of around 8 seconds to load! You can add a few seconds of time to that: ";// System("CLS") takes a bit of time to execute and that's why it loads slow.
	cin >> timeOfExecution;

	DisplayBar(startChar, endChar, percentageShown, fillerChar, emptyChar, lenghtOfBar, timeOfExecution, startProgress);
	return 0;
}