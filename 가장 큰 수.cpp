#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
	return a + b < b + a ? true : false;
}

string solution(vector<int> numbers)
{
	string answer = "";
	string int_stringtemp;
	vector<int> sorting_numbers;
	vector<string> int_stringtemps;
	for(int i =0; i< numbers.size(); i++)
	{
		int_stringtemp = to_string(numbers[i]);
		int_stringtemps.push_back(int_stringtemp);
	}

	sort(int_stringtemps.begin(), int_stringtemps.end(), compare);

	
	for(int i = int_stringtemps.size()-1 ; i >= 0; i--)
	{
		answer += int_stringtemps[i];
	}

	bool isZero = true;
	for(int i = 0; i < answer.length(); i++)
	{
		if (answer[i] != '0')
		{
			isZero = false;
			break;
		}
		
	}

	if (isZero == true)
		answer = "0";
	
	return answer;
}

int main()
{
	vector<int>numberlist;
	int input;
	int numbers;
	cin >> numbers;

	for(int i = 0; i < numbers; i++)
	{
		cin >> input;
		numberlist.push_back(input);
	}

    cout << solution(numberlist);

	return 0;
}