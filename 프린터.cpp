#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <deque>
using namespace std;

struct myData
{
	int index;
	int value;
};

struct compare 
{
	bool operator()(myData a, myData b)
	{
		return a.value < b.value;
	}
};

int solution(vector<int> priorities, int location)
{
	int answer = 0;
	int size = priorities.size();
	priority_queue<myData, vector<myData>, compare> maxHeap;
	deque<myData> wait_list;
	
	for (int i = 0; i < priorities.size(); i++)
	{
		myData data;
		data.index = i;
		data.value = priorities[i];
		maxHeap.push(data);
	}

	for (int i = 0; i < size; i++)
	{
		if (wait_list.size() == 0)
		{
			wait_list.push_back(maxHeap.top());
			maxHeap.pop();
		}

		else // 대기열에 하나 이상이라도 있을때
		{
			for (int j = 0; j < wait_list.size(); i++)
			{
				if (maxHeap.top().value <= wait_list[j].value)
				{
					myData temp = wait_list[j];
					wait_list.push_back(maxHeap.top());
					maxHeap.pop();
				}
				else
				{
					wait_list.push_front(maxHeap.top());
					maxHeap.pop();
				}
			}
		}
	}

	return answer;
}

int main()
{
	int printNum;
	vector<int> priorities;
	int location;
	int inputData;

	cin >> printNum;

	for (int i = 0; i < printNum; i++)
	{
		cin >> inputData;
		priorities.push_back(inputData);
	}

	cin >> location;

	cout << solution(priorities, location) << endl;

	return 0;
}