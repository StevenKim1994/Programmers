#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
	unordered_map<string, int> d;

	for(int i =0 ; i < participant.size(); i++)
	{
		if (d[participant[i]] == 0)
			d[participant[i]] = 1;

		else
			d[participant[i]]++;
	}

	for(int i = 0; i< completion.size(); i++)
	{
		if (d[completion[i]] > 0)
		{
			d[completion[i]]--;

			if (d[completion[i]] == 0)
				d.erase(d.find(completion[i]));	
		}
	}

	return d.begin()->first;
}


int main()
{
	
	int num;
	string input;
	vector<string> p_inputs;
	vector<string> c_inputs;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> input;
		p_inputs.push_back(input);
	}

	cin >> num;


	for(int i = 0; i <num;i++)
	{
		cin >> input;
		c_inputs.push_back(input);
	}
	
	cout << solution(p_inputs, c_inputs);

	return 0;
}