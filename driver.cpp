#include<iostream>
#include<ctime>
#include<cmath>
#include<cstdlib>

using namespace std;

const string ones[20] = {"zero", "one", "two", "three", "four", "five",
						 "six", "seven", "eight", "nine", "ten",
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

	int num = 0 + rand();
//	int num = 13005;
	cout << num << endl;

	if(num == 0)
		cout << ones[0] << endl;
	else
	{
		start:
		while(num > 0)
		{
			int length = 0;
			int temp = num;

			while(temp > 0)
			{
				temp /= 10;
				length++;
			}

			if((length == 1) || ((length == 2) && (num < 20)))
			{
				numToText = numToText + ones[num] + " ";
				num -= num;
			} else if((length == 2) && (num >= 20))
			{
				numToText = numToText + tens[place(num, length)] + " ";
				num -= (place(num, length) * pow(10, length-1));
			} else
			{

				switch(length % 3)
				{
				case 2:
					if(place(num, length) == 1)
					{
						int number = num / pow(10, length-2);
						numToText = numToText + ones[number] + " ";
						num -= number * pow(10, length-2);
						break;
					} else {
						numToText = numToText + tens[place(num, length)] + " ";
						num -= (place(num, length) * pow(10, length-1));
						goto start;
					}
				case 1:
					numToText = numToText + ones[place(num, length)] + " ";
					num -= (place(num, length) * pow(10, length-1));
					break;
				default:
					numToText = numToText + ones[place(num, length)] + " hundred ";
					num -= (place(num, length) * pow(10, length-1));
					goto start;
				}


				int ending = 0,
					places = length;
				while(places > 0)
				{
					places -= 3;
					ending++;
				}

				numToText = numToText + endings[ending] + " ";
			}
		}
	}
	cout << numToText << endl;


	return 0;
}

int place(int number, int length)
{

	int place = number / pow(10, length-1);

	return place;
}
