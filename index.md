# PAT (Advanced Level)

[TOC]

## 1001. A+B Format

- 题目描述

  > Calculate *a*+*b* and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).
  >
  > ### Input Specification:
  >
  > Each input file contains one test case. Each case contains a pair of integers *a* and *b* where −10^6 ≤ *a*, *b* ≤ 10^6. The numbers are separated by a space.
  >
  > ### Output Specification:
  >
  > For each test case, you should output the sum of *a* and *b* in one line. The sum must be written in the standard format.
  >
  > ### Sample Input:
  >
  > ```in
  > -1000000 9
  > ```
  >
  > ### Sample Output:
  >
  > ```out
  > -999,991
  > ```

- 题目大意

  *给出两个指定范围的整数，计算和，和的表示带千位分隔符*

- 解题思路

  1. a和b的范围已经确定，故可以用int保存
  2. 千位分隔符**从低位到高位**，**每三位**之间插入一个逗号分隔，注意**最高位前没有逗号**，因此计算出和的字符串的长度就可以**确定逗号的个数**，之后使用for循环插入逗号即可
  3. 在b的基础上因为负号不能参与长度计算，所以保存的是**a和b的和的绝对值**，结束插入逗号之后在通过和的正负性决定是否插入负号即可。可用一个bool变量保存逻辑值

- AC代码

  ```cpp
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
  ```

  
