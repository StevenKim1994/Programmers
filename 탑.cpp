#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> heights)
{
	bool checking;
	vector<int> answer;

	for (int top = heights.size() - 1; top >= 0; top--)
	{
		checking = false;

		for (int repeat = top-1; repeat >= 0; repeat--)
		{
			if (heights[repeat] > heights[top]) // 자신 탑의 높이보다 큰 탑을 만나면
			{
				answer.push_back(repeat + 1); // 인덱스는 0부터 시작하지만 여기선 1부터 새니 +1
				checking = true;
				break;
			}
			
		}
		
		if (checking == false) // 마지막까지도 자신의 탑 높이보다 높은 탑을 찾지 못한다면 0
			answer.push_back(0);
	}

	reverse(answer.begin(), answer.end());// 원소의 순서를 뒤집어줌 왜냐 뒤쪽 인덱스부터 시작했기 때문임.

	return answer;
}


int main()
{
	vector<int> input;
	vector<int> answer;
	int size;
	int number;
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		cin >> number;
		input.push_back(number);
	}

	answer = solution(input);

	for (int i = 0; i< answer.size(); i++)
		cout << answer[i] << endl;


	return 0;
}