#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
	vector<int> mul_value;
	int mul_answer = 0;
	int answer = 0;
	unordered_map<string, int> result;

	for(const auto &clothe : clothes)
		result[clothe[1]]++;

	for (const auto &value : result)
		mul_value.push_back(value.second+1);


	mul_answer = mul_value[0];

	for(int i = 1; i<mul_value.size(); i++)
		mul_answer = mul_answer * mul_value[i];

	answer = mul_answer - 1;
	
	return answer;
}

int main()
{
	vector<vector<string>> input_vector;
	vector<string> temp_vector;
	string input_temp;
	
	int clothe_num;
	cin >> clothe_num;

	for(int i = 0 ; i < clothe_num ; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			cin >> input_temp;
			temp_vector.push_back(input_temp);
		}

		input_vector.push_back(temp_vector);
		temp_vector.clear();
	}

	cout << solution(input_vector) << endl;

	
	return 0;
}