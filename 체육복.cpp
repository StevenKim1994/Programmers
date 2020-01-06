#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) // 3 7 8 10 미통.. 왜지
{
	int answer = 0;
	vector<int> student(n+2,1); // n+2를 하는 이유는 0과 n번째 인덱스를 추가함으로써 처리를 쉽게 하기 위함임.
	student[0] = student[n + 1] = 0; // 0과 n번째 0으로 초기화
	for(int i = 0; i < reserve.size(); i++)
		student[reserve[i]]++; // 여벌 체육복 처리

	for (int i = 0; i < lost.size(); i++)
		student[lost[i]]--; // 도난당한 체육복 처리
	
	for(int i = 1; i<student.size()-1; i++)
	{
		if(student[i] >= 2) // i번째 학생이 체육복이 2벌이상 소지하고 있으면
		{
			if(i-1 != 0) // 0번째 제외
			{
				student[i - 1]++;
				student[i]--;
			}
		}
	}

	for(int i = 1; i<student.size()-1; i++)
	{
		if (student[i] >= 1)
			answer++;
	}

	return answer;
}

int main()
{
	int n;
	int lost_num;
	int reserve_num;
	int input;
	vector<int> lost;
	vector<int> reserve;
	cin >> n;

	cin >> lost_num;
	for(int i = 0; i < lost_num ; i++)
	{
		cin >> input;
		lost.push_back(input);
	}

	cin >> reserve_num;
	
	for(int i = 0 ; i< reserve_num; i++)
	{
		cin >> input;
		reserve.push_back(input);
	}

	cout << solution(n, lost, reserve);

	return 0;
}