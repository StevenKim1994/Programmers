#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball)
{
	int answer = 0;
	bool checked[1000]; // 1~999
	checked[0] = true; // 000 은 선택할 수 없으니 무조건 선택되엇다고 설정해둠.

	for(int i = 0; i < baseball.size(); i++)
	{
		baseball[i][0]; // 0: 세자리수 , 1: 스트라이크의 수, 2: 볼의 수
	}
	return answer;
}

int main()
{
	int n;
	vector<int> query;
	vector<vector<int>> querys;
	int input;

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> input;
		query.push_back(input); // 질문한 세자리수
		cin >> input;
		query.push_back(input); // 스트라이크 수
		cin >> input;
		query.push_back(input); // 볼의 수

		querys.push_back(query); // 질문 모음 추가
		
	}

	cout << solution(querys);
	
	return 0;
}