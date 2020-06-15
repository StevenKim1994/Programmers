#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s)
{
	vector<int> answer;
	bool in = false;
	for(int i = 1; i<s.length()-1; i++) // 0 과 length()의 값은 { } 이므로 제외
	{
		if (s[i] == '{') in = true;
		else if (s[i] == '}') in = false;

		if(in == true)
		{
			answer.push_back(atoi(s.c_str()));
		}
		
		
	}

	return answer;
}

int main()
{
	string str;

	cin >> str;

	vector<int> result = solution(str);

	cout << "[";
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i];

		if (i == result.size() - 1)
			cout << ", ";
	}


	cout << "]" << endl;
	
	return 0;
}