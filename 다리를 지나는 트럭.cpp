#include <iostream>
#include <vector>
#include <queue>

using namespace std;



int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	queue<int> on_bridge;
	int now_weight = 0;
	int answer = 0;
	for(int i = 0; i <truck_weights.size(); i++)
	{
		int now_truck = truck_weights[i];

		while(true)
		{
			if(on_bridge.empty())
			{
				answer++;
				on_bridge.push(now_truck);
				now_weight += now_truck;
				break;
			}
			else if(on_bridge.size() == bridge_length)
			{
				now_weight -= on_bridge.front();
				on_bridge.pop();
			}
			else
			{
				if(weight < (now_weight+ now_truck))
				{
					on_bridge.push(0);
					answer++;
				}
				else
				{
					on_bridge.push(now_truck);
					now_weight += now_truck;
					answer++;
					break;
				}
			}
		}
	}
	
	return answer + bridge_length;
}


int main()
{
	int bridge_length;
	int weight;
	vector<int> truck_weights;
	int truck_num;
	int input_buffer;

	cin >> bridge_length;
	cin >> weight;
	cin >> truck_num;

	for (int i = 0; i < truck_num; i++)
	{
		cin >> input_buffer;
		truck_weights.push_back(input_buffer);
	}

	cout << solution(bridge_length, weight, truck_weights);

	return 0;
}