#include <iostream>
#include <string>
using namespace std;
int main()
{
	int a, b;
	string sum;
	cin >> a >> b;
	bool notNegative = a + b >= 0 ? true : false;
	sum = to_string(a + b >= 0 ? a + b : -(a + b));
	int len = sum.length();
	int cnt = len / 3;
	if (!(sum.length() % 3)) --cnt;
	for (int i = 0; i < cnt; i++)
		sum.insert(len - (i + 1) * 3, ",");
	if (!notNegative) sum.insert(0, "-");
	cout << sum;
	return 0;
}
