#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include <tuple>
using namespace std;

/*
 * 속한 노래가 많이 재생된 장르부터 먼저 수록
 * 장르 내에서 많이 재생된 노래를 먼저 수록
 * 장르 내에서 재생 횟수가 같은 노래 중에서는 고유번호가 낮은 노래먼저 수록
 */

bool compare(pair<string,int> a, pair<string,int> b)
{
	return a.second < b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
	vector<int> result;
	int size = genres.size();
	
	unordered_map<string, int> myMap;
	vector<pair<string,int>> vec;
	
	// 재생된 장르 누적시키기 많이 재생된 장르를 찾기 위함
	for(int i = 0; i<size; i++)
	{
		myMap[genres.at(i)] += plays.at(i);
	}

	for(auto pair:myMap)
	{
		vec.push_back(make_pair(pair.first, pair.second));
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++)
		cout << vec.at(i).first << vec.at(i).second << endl;

	// 많이 재생된 장르는 찾음 이제 여기서 장르중에서 재생크기 큰거 순으로 result에 push_back 시키자!

	
	return result;
}

int main()
{
	vector<string> genres;
	vector<int> plays;
	vector<int> result;
	int num, input_plays;
	string input_genres;
	
	cin >> num;

	for(int i = 0;i<num; i++)
	{
		cin >> input_genres;
		cin >> input_plays;

		genres.push_back(input_genres);
		plays.push_back(input_plays);
	}


	result = solution(genres, plays);
	
	for(int i = 0; i<result.size(); i++)
	{
		cout << result[i] << endl;
	}


	return 0;
}