#include <string>
#include <iostream>

using namespace std;

string solution(string s)
{
	string answer = "";

	if((s.length() % 2 ) == 0) // Â¦¼ö¶ó¸é
	{
		answer = s[s.length() / 2 -1];
		answer += s[s.length() / 2];
	}
	else // È¦¼ö¶ó¸é
	{
		answer = s[s.length() / 2];
	}
	
	return answer;
}

int main()
{
	string s;
	cin >> s;
	
	s = solution(s);

	cout << s;

	return 0;
}