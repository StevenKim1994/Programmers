#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

vector<int> solution(vector<int> answers)
{
	vector<int> answer;
	vector<pair<int, int>> rank;
	int one = 0, two = 0, three = 0;
	int two_count = 1;
	int three_count = 0;
	int three_check = 0;

	priority_queue<pair<int, int>> max_heap;
	// one : 찍는 방식 1 2 3 4 5 ...
	// two : 찍는 방식 홀수번째 수는 무조건 2 짝수에서 1 3 4 5 순으로 ...
	// three : 찍는 방식 3 3 1 1 2 2 4 4 5 5 ...
	for (int i = 0; i < answers.size(); i++)
	{
		if (i >= 4) // one의 처리
		{
			if(answers[i] == (i%5)+1)
				one++;
		}
		else
		{
			if (answers[i] == i + 1)
				one++;
		}
		
		if ((i + 1) % 2 == 1) // two 의 처리 홀수번째 수일때 2이면 ++
		{
			if (answers[i] == 2)
			{
				two++;
			}
		}
		else // two의 처리 짝수일때 1 - > 3 - > 4 - > 5 순으로 체크
		{
			if (two_count == 1)
			{
				if (answers[i] == two_count)
				{
					two++;
				}
			}
			else if (two_count == 3)
			{
				if (answers[i] == two_count)
				{
					two++;
				}
			}
			else if (two_count == 4)
			{
				if (answers[i] == two_count)
				{
					two++;
				}
			}
			else if (two_count == 5)
			{
				if (answers[i] == two_count)
				{
					two++;
				}
			}

			two_count++;

			if (two_count == 2)
				two_count = 3;

			if (two_count == 6)
				two_count = 1;

		}

		if (three_count == 0) // three의 처리 
		{
			if (three_check != 2)
			{
				if (answers[i] == 3)
				{
					three++;

				}
			}

			three_check++;

			if (three_check == 2)
			{
				three_count++;
				three_check = 0;
			}
		}
		else if (three_count == 1)
		{
			if (three_check != 2)
			{
				if (answers[i] == 1)
				{
					three++;
				}
			}

			three_check++;

			if (three_check == 2)
			{
				three_count++;
				three_check = 0;
			}
		}

		else if (three_count == 2)
		{
			if (three_check != 2)
			{
				if (answers[i] == 2)
				{
					three++;
				}
			}

			three_check++;

			if (three_check == 2)
			{
				three_count++;
				three_check = 0;
			}
		}

		else if (three_count == 3)
		{
			if (three_check != 2)
			{
				if (answers[i] == 4)
				{
					three++;
				}
			}

			three_check++;

			if (three_check == 2)
			{
				three_count++;
				three_check = 0;
			}
		}

		else if (three_count == 4)
		{
			if (three_check != 2)
			{
				if (answers[i] == 5)
				{
					three++;
				}
			}

			three_check++;

			if (three_check == 2)
			{
				three_count++;
				three_check = 0;

				if (three_count == 5)
				{
					three_count = 0;
				}
			}


		}


	}

	max_heap.push(make_pair(one, 1));
	max_heap.push(make_pair(two, 2));
	max_heap.push(make_pair(three, 3));

	for (int i = 0; i < 3; i++)
	{
		if (rank.empty() == true)
		{
			rank.push_back(max_heap.top());
			max_heap.pop();
		}

		if (max_heap.size() >= 1)
		{
			if (rank.front().first <= max_heap.top().first)
			{
				rank.push_back(max_heap.top());
				max_heap.pop();
			}
		}
	}

	if (rank.size() >= 2)
		sort(rank.begin(), rank.end());

	for (const auto& i : rank)
		answer.push_back(i.second);

	return answer;
}

int main()
{
	int max;
	int input;
	vector<int> in_answers;
	vector<int> result;
	cin >> max;

	for (int i = 0; i < max; i++)
	{
		cin >> input;
		in_answers.push_back(input);
	}

	result = solution(in_answers);

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;


	return 0;
}