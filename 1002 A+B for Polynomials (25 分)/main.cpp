#include <iostream>
#include <functional>
#include <map>
using namespace std;
int main()
{
	map<int, double, greater<int>> polynomials;
	map<int, double>::iterator it;
	int k, n;
	double an;
	for (int i = 0; i < 2; i++)
	{
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> n >> an;
			if (polynomials.count(n))
				polynomials[n] += an;
			else polynomials[n] = an;
			if (polynomials[n] == 0.0)
				polynomials.erase(n);
		}
	}
	cout << polynomials.size();
	for (it = polynomials.begin(); it != polynomials.end(); it++)
		printf(" %d %.1f", it->first, it->second);
	return 0;
}
