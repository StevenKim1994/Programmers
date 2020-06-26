#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k)
{
	int answer = 0;

	if (stock >= k)
		answer = 0;

	else
	{
		for (int i = 0; i < dates.size(); i++)
		{





		}
	}
	return answer;
}


int main()
{
	int stock;
	vector<int> dates;
	int datesNum;
	vector<int> supplies;
	int suppliesNum;
	int k;
	int data;

	cin >> stock;
	cin >> datesNum;

	for (int i = 0; i < datesNum; i++)
	{
		cin >> data;
		dates.push_back(data);
	}

	cin >> suppliesNum;
	
	for (int i = 0; i < suppliesNum; i++)
	{
		cin >> data;
		supplies.push_back(data);
	}

	cin >> k;

	cout << solution(stock, dates, supplies, k);

	return 0;
}