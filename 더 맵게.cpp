
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
	priority_queue<int, vector<int>,greater<int> > solution_heap; // greater 하는 이유는 기본이 less라 큰수부터 큐에서 나오기 때문에...
	int answer = 0;
	int A, B, C;
	for(int i =0; i<scoville.size(); i++)
		solution_heap.push(scoville[i]);

	while(!solution_heap.empty())
	{
		if (solution_heap.top() < K)
		{
			if(solution_heap.size() == 1)
			{
				if(solution_heap.top() < K)
				{
					answer = -1;
					return answer;
				}
			}
			B = solution_heap.top();
			solution_heap.pop();
			C = solution_heap.top() * 2;
			solution_heap.pop();
			A = B + C;
			answer++;

			solution_heap.push(A);
		}
		else
		{
			break;
		}
	}

	return answer;
}

int main()
{
	vector<int> scoville;
	int scoville_num;
	int input;
	int K;
	
	cin >> scoville_num;
	
	for(int i = 0; i < scoville_num; i++)
	{
		cin >> input;
		scoville.push_back(input);
	}

	cin >> K;

	cout << solution(scoville, K) << endl;

	return 0;
}