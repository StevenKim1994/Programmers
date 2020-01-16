#include <iostream>
#include <string>
#include <stack>

using namespace std;

string solution(string number, int k)
{
	
	int count = 0;

	string answer = "";
	stack<char>ready;
	stack<char>reverse;

	for(int i=0; i<number.length(); i++)
	{
		if(count == k)
		{
			break;
		}
		if(ready.empty() == true)
		{
			ready.push(number[i]);
		}

		else
		{
			if(number[i] <= ready.top())
			{
				ready.push(number[i]);
			}
			else
			{
				while(true) 
				{
					if(ready.size() == 0)
					{
						ready.push(number[i]);
						break;
					}
					
					if (count != k)
					{
						if (ready.top() >= number[i])
						{
							ready.push(number[i]);
							break;
						}
						else
						{
							ready.pop();
							count++;
						}
					}
					else
					{
						int temp = i;
						for(temp; temp<number.length(); temp++)
						{
							ready.push(number[temp]);
						}
						break;
					}
				}
				
				
			}
		}
	}
	if (count != k)
	{
		for(int i=count; i<k; i++)
			ready.pop();
	}
	
	int size = ready.size();

	for(int i = 0; i < size; i++)
	{
		reverse.push(ready.top());
		ready.pop();
	}

	for(int i = 0 ; i <size; i++)
	{
		answer += reverse.top();
		reverse.pop();
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