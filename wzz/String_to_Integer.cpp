/*
Runtime: 4 ms, faster than 88.85% of C++ online submissions for String to Integer (atoi).
Memory Usage: 9 MB, less than 5.01% of C++ online submissions for String to Integer (atoi).
*/
class Solution {
public:
	int myAtoi(string str) {
		string max = "2147483647";
		string min = "2147483648";
		double max_num = 2147483647;
		double  min_num = 2147483648;
		list<char> num;
		int flag = 0;
		int flag_positive = 1;
		for (char c : str)
		{
			if (flag == 0)
			{
				if (c == ' ')
					continue;
				else if ((!(c >= '0' && c <= '9')) && c != '-'&& c != '+')
				{
					flag = -1;
					break;
				}
				else if (c == '-')
				{
					flag = 1;
					flag_positive = -1;

					continue;
				}
				else if (c == '+')
				{
					flag = 1;
					flag_positive = 1;

					continue;
				}
				else if (c >= '0' && c <= '9')
				{
					flag = 1;
					num.push_back(c);
					continue;
				}
			}

			else if (flag == 1 && c >= '0' && c <= '9')
				num.push_back(c);

			else if (flag == 1 && !(c >= '0' && c <= '9'))
			{
				if (num.size() == 0)
				{
					flag = -1;
					break;
				}
				else
					break;
			}
		}
		double return_s = 0;
		list<char>::iterator it; //声明一个迭代器

		for (it = num.begin(); it != num.end(); it++)
			//cout << *it;
			return_s = return_s * 10 + (*it - '0');
		if (flag == -1)
			return 0;
		if (return_s > max_num&&flag_positive == 1)
			return max_num;
		if (return_s > min_num && flag_positive == -1)
			return flag_positive*min_num;
		return flag_positive*return_s;
	}
};
