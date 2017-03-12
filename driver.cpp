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

int main()
{
	srand(time(NULL));



int hunPlace(int, int);

//	int num = 0 + rand() % 999999999999;
	int num = 4592;
	cout << num << endl;

	if(num == 0)
		cout << ones[0] << endl;
	else{
		while(num > 0){
			int length = 0;
			int temp = num;

			while(temp > 0)
			{
				temp /= 10;
				length++;
			}

			int ending,
				places = length;
			while(places > 0)
			{
				places -= 3;
				ending++;
			}




			numToText += endings[ending];
			ending--;
		}
	}

	return 0;
}

int hunPlace(int number, int length)
{
	int hundreds = number / pow(10, length-1);
	cout << hundreds << endl;

	numToText += ones[hundreds];
	number -= (hundreds * pow(10, length-1));

	return number;
}

