#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string arrangement)
{
	int answer = 0;
	stack<char> myStack;

	for (int i = 0; i< arrangement.length(); i++)
	{
		if (arrangement[i] == '(')
		{
			myStack.push('(');
		}
		else
		{
			myStack.pop();
			if (arrangement[i - 1] == '(')
			{
				answer += myStack.size();
			}
			else
			{
				answer++;
			}
		}
	}
	return answer;
}

int main()
{
	string input;

	cin >> input;

	cout << solution(input);



	return 0;
}

/*
() ( ( ( () () ) ( () ) () ) ) ( () ) -> 17

3 3 2 3 2 2 1 0 1 0

3 6 7 10 11 13 14 15 16 17

( () () ( ( () ) ) ) ->8

1 1 1 2 3 3 2 1 0

0 1 2 2 2 5 6 7 8


*/