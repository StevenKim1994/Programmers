#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
	string answer;

	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	completion.push_back("000"); // trash value;
	for(int i = 0; i < completion.size(); i++)
	{
		if(participant[i] != completion[i])
		{
			answer = participant[i];
			break;
		}
			
	}
	return answer;
}

int main()
{
	string input_string;
	vector<string> participant;
	vector<string> completion;

	while (true)
	{
		cin >> input_string;

		if (input_string == "exit")
			break;
		
		participant.push_back(input_string);
	}

	while(true)
	{
		cin >> input_string;

		if (input_string == "exit")
			break;

		completion.push_back(input_string);
	}

	cout << solution(participant, completion);
	
	return 0;
}