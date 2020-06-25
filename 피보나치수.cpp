#include <iostream>

using namespace std;

int solution(int n)
{
	if (n == 0)
		return 0;

	if (n == 1)
		return 1;

	return solution(n - 2) + (n - 1);
}

int main()
{
	int input;
	cin >> input;

	cout << solution(input) << endl;


	return 0;
}