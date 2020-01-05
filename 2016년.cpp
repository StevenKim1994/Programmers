#include <iostream>
#include <string>

using namespace std;
// 1.1 은 월요일
string solution(int a, int b) // 1: 31	2: 29	3: 31	4: 	30	5: 30	6: 30	7: 31	8: 31	9: 30	10: 31	11: 30	12: 31
{
	string answer = "";
	int total_day = 0;

	for(int i = 0; i<=a; i++)
	{
		switch(i)
		{
		case 1:
			break;
		case 2:
			total_day += 31;
			break;
		case 3:
			total_day += 29;
			break;
		case 4:
			total_day += 31;
			break;
		case 5:
			total_day += 30;
			break;
		case 6:
			total_day += 31;
			break;
		case 7:
			total_day += 30;
			break;
		case 8:
			total_day += 31;
			break;
		case 9:
			total_day += 31;
			break;
		case 10:
			total_day += 30;
			break;
		case 11:
			total_day += 31;
			break;
		case 12:
			total_day += 30;
			break;
		}
	}

	total_day += b-1;
	total_day = total_day % 7;

	switch(total_day)
	{
	case 0:
		answer = "FRI";
		break;
	case 1:
		answer = "SAT";
		break;
	case 2:
		answer = "SUN";
		break;
	case 3:
		answer = "MON";
		break;
	case 4:
		answer = "TUE";
		break;
	case 5:
		answer = "WED";
		break;
	case 6:
		answer = "THU";
	}

	return answer;
}

int main()
{
	int a, b;

	cin >> a >> b;

	cout << solution(a, b);

	return 0;
}