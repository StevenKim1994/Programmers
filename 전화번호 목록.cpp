#include <string>
#include <vector>
#include <map>

#include <iostream>

using namespace std;

bool solution(vector<string> phone_book)
{
	map<string, string> d;

	for (const auto& phone : phone_book)
	{

		for (const auto& set : d)
		{
			string key = set.first;
			
			if (key.find(phone) == 0 || phone.find(key) == 0)
			{
				return false;
			}
		}

		d[phone] = phone;
	}

	return true;
}



//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//bool solution(vector<string> phoneBook) {
//    bool answer = true;
//
//    sort(phoneBook.begin(), phoneBook.end());
//
//    for (int i = 0; i < phoneBook.size() - 1; i++)
//    {
//        if (phoneBook[i] == phoneBook[i + 1].substr(0, phoneBook[i].size()))
//        {
//            answer = false;
//            break;
//        }
//    }
//
//    return answer;
//}

int main() {
	vector<string> phone_book = { "23","1235" };
	auto result = solution(phone_book);
	cout << result << endl;
	return 0;
}