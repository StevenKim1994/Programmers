#include <iostream>
#include <queue>
#include <string>

using namespace std;

string matrix[100][100];
void rotateFunc(int start, int end, int rotate) {
	if (end - start < 2)
		return;
	queue<string> buffer;
	int R;

	if (rotate > 0)		// 여기서 방향결정함 무조건 왼쪽으로 돌지만 불필요한 회전은 제외함
	{
		R = (4 * ((end - start) - 1)) - (rotate % (4 * ((end - start) - 1)));		
	}
	else
	{
		R = (rotate % (4 * ((end - start) - 1))) * -1;						
	}
	cout <<"회전수 : " << R << endl;
	
	for (int i = start; i < end - 1; i++)		
		buffer.push(matrix[start][i]);
	for (int i = start; i < end - 1; i++)		
		buffer.push(matrix[i][end - 1]);
	for (int i = end - 1; i > start; i--)		
		buffer.push(matrix[end - 1][i]);
	for (int i = end - 1; i > start; i--)		
		buffer.push(matrix[i][start]);

	while (R > 0) 
	{
		buffer.push(buffer.front());
		buffer.pop();
		R--;
	}

	for (int i = start; i < end- 1; i++)
		{ matrix[start][i] = buffer.front(); buffer.pop(); }
	for (int i = start; i < end - 1; i++) 
		{ matrix[i][end - 1] = buffer.front(); buffer.pop(); }
	for (int i = end - 1; i > start; i--)
		{ matrix[end - 1][i] = buffer.front(); buffer.pop(); }
	for (int i = end - 1; i > start; i--) 
		{ matrix[i][start] = buffer.front(); buffer.pop(); }

	return rotateFunc(start + 1, end - 1, -rotate);
}
int main() {
	int N, rotate;

	

	cin >> N >> rotate;

	for(int i = 0; i<N; i++)
	{
		for(int j = 0 ; j < N; j++)
		{
			cin >> matrix[i][j];
		}
	}

	rotateFunc(0, N, rotate);
	
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}