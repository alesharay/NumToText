#include<iostream>
#include<ctime>
#include<cmath>

using namespace std;

const string ones[19] = {"zero", "one", "two", "three", "four", "five",
						 "six", "seven", "eight", "nine" "ten",
						 "eleven", "twelve", "thirteen", "fourteen", "fifteen",
						 "sixteen", "seventeen", "eighteen", "nineteen"},
			 tens[10] = {"", "", "twenty", "thirty", "forty", "fifty",
					   "sixty", "seventy", "eighty", "ninety"},
			 endings[6] = {"", "hundred", "thousand", "million", "billion", "trillion"};
	string numToText = "";

int place(int, int);

int main()
{
	srand(time(NULL));

//	int num = 0 + rand() % 999999999999;
	int num = 4867268;
	cout << num << endl;

	if(num == 0)
		cout << ones[0] << endl;
	else
	{
		while(num > 0)
		{
			int length = 0;
			int temp = num;

			while(temp > 0)
			{
				temp /= 10;
				length++;
			}
			cout << "length: " << length << endl;

			if((length == 1) || ((length == 2) && (num < 20)))
			{
				ones:
				numToText = numToText + ones[place(num, length)] + " ";
				cout << numToText << endl;
				num -= (place(num, length) * pow(10, length-1));
			} else if((length == 2) && (num >= 20))
			{
				numToText = numToText + tens[place(num, length)] + " ";
				cout << numToText << endl;
				num -= (place(num, length) * pow(10, length-1));
			} else
			{
				int ending = 0,
					places = length;
				while(places > 0)
				{
					places -= 3;
					ending++;
				}
				cout << "ending: " << ending << endl;



				numToText = numToText + endings[ending] + " ";
				cout << numToText << endl;

				num -= (place(num, length) * pow(10, length-1));
			}
		}
	}

	return 0;
}

int place(int number, int length)
{

	int place = number / pow(10, length-1);

	return place;
}
