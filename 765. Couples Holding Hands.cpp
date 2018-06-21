/*
//最多换n次肯定ok，把每个人按序号就坐（滑稽）
没啥头绪时，一个很好的办法是假设不要求写代码，先动手解决问题
search后得知Greedy即可，but why?
建模成图论（学完 Graph theory 的好处，遇到能建模成图论的问题会绕有自信）
人数是偶数，两两切分，形成n个节点，有配偶关系连一条线
已配对点便是孤立点，剩下m个点和m条线，一定是一个或多个环
对于size为x的环，我们只需要x-1次swap可以让这个环上的节点全部valid//数归？
*/
//Here is a trick: 1^1=0 0^1=1 so 6^1=7 7^1=6
class Solution {
public:
	int minSwapsCouples(vector<int>& row) {
		int n = row.size(), result = 0;
		for (int i = 0; i < n; i += 2) {
			if (row[i + 1] == (row[i] ^ 1))// ^ has lower precedence than ==
				continue;
			else {
				for (int j = i + 1; j < n; ++j)// start from i+1
					if (row[j] == (row[i] ^ 1)) { // no need swap
						row[j] = row[i + 1];
						row[i + 1] = row[i] ^ 1;
						result++;//just after that if
						break;// there must be only one
					}
			}
		}
		return result;
	}
};

// Without the trick
class Solution {
public:
	int minSwapsCouples(vector<int>& row) {
		int n = row.size(), result = 0;
		for (int i = 0; i < n; i += 2) {
			if (row[i + 1] == GetCouple(row[i]))// It's GetCouple(row[i]), not GetCouple(i)
				continue;
			else {
				for (int j = i + 1; j < n; ++j)
					if (row[j] == GetCouple(row[i])) {
						row[j] = row[i + 1];
						row[i + 1] = GetCouple(row[i]);
						result++;
						break;
					}
			}
		}
		return result;
	}
private:
	int GetCouple(int n) {
		if (n % 2 == 0)
			return n + 1;
		else
			return n - 1;
	}
};
