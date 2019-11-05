#  1002. A+B for Polynomials (25 分)

- 题目描述

  > This time, you are supposed to find *A*+*B* where *A* and *B* are two polynomials.
  >
  > ### Input Specification:
  >
  > Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:
  >
  > *K* *N*1 *a**N*1 *N*2 *a**N*2 ... *N**K* *a**N**K*
  >
  > where *K* is the number of nonzero terms in the polynomial, *N**i* and *a**N**i* (*i*=1,2,⋯,*K*) are the exponents and coefficients, respectively. It is given that 1≤*K*≤10，0≤*N**K*<⋯<*N*2<*N*1≤1000.
  >
  > ### Output Specification:
  >
  > For each test case you should output the sum of *A* and *B* in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.
  >
  > ### Sample Input:
  >
  > ```in
  > 2 1 2.4 0 3.2
  > 2 2 1.5 1 0.5
  > ```
  >
  > ### Sample Output:
  >
  > ```out
  > 3 2 1.5 1 2.9 0 3.2
  > ```

- 题目大意

  *两行输入，每行以数字K开始，表面此多项式由多少个单项式组成，再输入K组数据，每组数据按指数，系数的形式以指数递减的形式给出，计算这两行表达式对应的多项式的和，注意和的输出格式需要和输入一样，即第一个字符表明此多项式中包含的单项式的个数，并按指数递减形式输出。*

- 解题思路

  1. 指数不变系数相加减，故可用map保存指数-系数对
  2. 当系数为0时，此项自动舍去

- AC代码

  ```cpp
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
  ```
  
