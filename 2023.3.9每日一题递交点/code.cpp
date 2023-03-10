#include <bits/stdc++.h>
using namespace std;
int search(char* input, int i,int length)//针对完全对称的字符串使用的检索函数
{
	int counter = 2;
	for (int j = 1; i - j >= 0 && i + 1 + j < length; j++)
	{
		if (input[i - j] == input[i + 1 + j])
		{
			counter += 2;
			continue;
		}
		else
			break;
	}
	return counter;
}
int search_2(char* input, int i, int length)//针对中心对称的字符串使用的检索函数
{
	int counter = 3;
	for (int j = 2; i - j >= 0 && i + j < length; j++)
	{
		if (input[i - j] == input[i + j])
		{
			counter += 2;
			continue;
		}
		else
			break;
	}
	return counter;
}
int main()
{
	char input[300]{};
	char a, b;//两个工具字符变量,用于检索字符串
	cin.getline(input,100);
	string input_sub = input;
	int length = input_sub.size();
	int ct = 0, temp_i = 0, str_type;
	for (int i = 0; i < length; i++)
	{
		a = input[i];
		b = input[i + 1];
		if (a == b)//第一种情况,两个相同的字符靠在一块,完全对称
		{
			if (search(input, i, length) > ct)
			{
				ct = search(input, i, length);
				temp_i = i;
				str_type = 0;
			}
		}
		else
			if (a == input[i + 2])//第二种情况,两个相同的字符中间隔了一个字符,中心对称
			{
				if (search_2(input, i + 1, length) > ct)
				{
					ct = search_2(input, i + 1, length);
					temp_i = i + 1;
					str_type = 1;
				}
			}
		//两种情况不同处理方式也不同
	}
	int start_position;
	if (0 == ct)
	{
		cout << "nothing." << endl;
		return 0;
	}
	else
	{
		if (0 == str_type)
		{
			start_position = temp_i - (ct / 2) + 1;
		}
		else
		{
			start_position = temp_i - (ct / 2);
		}
	}
	for (int j=0; ct >= 1; ct--)
	{
		cout << input[start_position + j];
		j++;
	}
	cout << endl;
	system("pause");
	return 0;
}