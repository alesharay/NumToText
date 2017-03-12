#include<iostream>
#include<ctime>

using namespace std;

int main()
{
	srand(time(NULL));

	const string ones[19] = {"zero", "one", "two", "three", "four", "five",
							 "six", "seven", "eight", "nine" "ten",
							 "eleven", "twelve", "thirteen", "fourteen", "fifteen",
							 "sixteen", "seventeen", "eighteen", "nineteen"},
				 tens[10] = {"", "", "twenty", "thirty", "forty", "fifty",
						   "sixty", "seventy", "eighty", "ninety"},
				 endings[5] = {"hundred", "thousand", "million", "billion", "trillion"};
		string numToText = "";

	int num = 0 + rand() % 999999999999;

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

			int ending;
//				places = length;
			while(length > 0)
			{
				length -= 3;
				ending++;
			}



			numToText += endings[ending];
			ending--;
		}
	}

	return 0;
}

