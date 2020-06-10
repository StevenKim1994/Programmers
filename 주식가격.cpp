#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
	vector<int> answer;
	stack < pair<int, int>> myStack;
	answer.push_back(0);
	
	for(int i=prices.size()-2; i>=0;i--)
	{
		int day = 0;

		while(!myStack.empty() && myStack.top().first >= prices[i])
		{
			day += myStack.top().second;
			myStack.pop();
		}

		answer.push_back(day + 1);
		myStack.push(make_pair (prices[i], day + 1));
		
	}
	
	reverse(answer.begin(), answer.end());

	return answer;

}

// 1 2 3 2 3

// 4 3 1 1 0

int main()
{
	int num;
	int data;
	vector<int> input_vec;
	cin >> num;

	for(int i = 0; i< num; i++)
	{
		cin >> data;
		input_vec.push_back(data);
	}


	input_vec = solution(input_vec);

	for(int i = 0; i<input_vec.size();i++)
	{
		cout << input_vec[i] << endl;
	}

	return 0;
}