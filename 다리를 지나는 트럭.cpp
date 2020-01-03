#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	int truck_num = truck_weights.size();
	int answer = 0; // 다리를 건너는데 총 걸리는 시간의 합
	int now_weight = 0; // 현재 다리위에 가해진 무게의 합
	int now_truck = 0; // 현재 다리위에 건너고 있는 트럭의 대수
	
	while (truck_weights.size() != 0) // 현재대기 중인 트럭이 0이 아니면 반복
	{
		while(now_weight < weight) // 현재 다리 위에 가해진 무게가 한도 미만이면 반복
		{
			answer++; // 다리 올라갈 수 있을 때 트럭들 1초 걸림
			now_weight += truck_weights.front(); // 맨앞에 대기중에 트럭의 무게 가중
			truck_weights.erase(truck_weights.begin()); // 맨앞에 대기중인 트럭이 다리에 올랐으니 맨앞 제거
			now_truck++;
			if (truck_weights.size() == 0)
				break;
		}
		
		// 다리 위에 더이상 가해질 수 없는 무게가 된다면 밑의 구문 실행
		answer = answer + bridge_length; // 1초당 거리1씩 움직일 수 있으니 다리이 만큼 더함
		now_weight = 0; // 다 건넜으니 현재 다리 무게 가중치 0 초기화
		
		now_truck = 0; // 다 건넜으니 현재 다리위 트럭 0대로 초기화

	}
	

	return answer;
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