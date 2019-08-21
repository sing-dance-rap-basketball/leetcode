//886 回文素数
//执行用时 :48 ms , 在所有 C++ 提交中击败了42.98%的用户
//内存消耗 :8.4 MB, 在所有 C++ 提交中击败了76.47%的用户
class Solution {
public:
	int isPalindrome(string s)
	{
		int d = s.length() / 2;
		int iter = 0;
		int isPal = 1;
//int l = s.length;
		for (iter = 0; iter <= d; iter++)
		{
			if (s[iter] == s[s.length() - iter-1])
				continue;
			else
			{
				isPal = 0;
				break; 
			}
		}
		return isPal;
	}
	int isPrime(int N)
	{
		int R = int(sqrt(N));
		int isPri = 1;
		for (int root = 3; root <=R;root++)
		if (N%root == 0)
		{
			isPri = 0;
			break;
		}
		//cout << isPri;
		return isPri;
	}
	int primePalindrome(int N) {
		int num = N;
		if (N == 1 || N == 2)
			return 2;
		string str_num = to_string(N);
		if ((str_num.back() - 48) % 2 == 0)
		{
			num++;
		}
		while (true)
		{
			string str_num = to_string(num);
			//cout << str_num << endl;
			//cout << str_num.back() - 48 << endl;
			
			if (str_num.length() % 2 == 0 && str_num.length()>3)
			{
				num =int(pow(10,str_num.length()))+1;
				continue;
			}
			
			if ((isPalindrome(str_num) && isPrime(num)))
					break;
			else
			{
				num=num+2; 
				continue;
			}//cout << num<<endl;
		}
		//(isPalindrome(to_string(num)) && isPrime(num))==false
			//string num_str = to_string(N);
		return num;
	}
};
