#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k)
{
	int count = 0;
	queue<char> ready;
	stack<char> result;
	string answer = "";

	for(int i=0; i<number.length(); i++)
	{
		if (count == k)
		{
			int k = i;

			for(k; k<number.length(); k++)
			{
				ready.push(number[k]);
			}
			break;
		}
		
		if(ready.empty())
		{
			ready.push(number[i]);
		}
		else
		{
			if(number[i] <= ready.front())
			{
				if(count < k)
				{
					count++;
					continue;
				}
		
			}
			else
			{
				while(true)
				{
					if(ready.empty())
					{
						ready.push(number[i]);
						break;
					}
					else
					{
						if(ready.front() < number[i])
						{
							count++;
							ready.pop();
						}
						else
						{
							ready.push(number[i]);
							break;
						}

						if (count == k)
							break;
					}
				}
			}
		}
	}

	for(int i = 0; i<ready.size(); i++)
	{
		result.push(ready.front());
		ready.pop();
	}

	for(int i =0; i<result.size(); i++)
	{
		answer += result.top();
		result.pop();
	}
	
	return answer;
}


int main()
{
	string input;
	int num;
	cin >> input;
	cin >> num;
	cout << solution(input, num) << endl;

	return 0;
}