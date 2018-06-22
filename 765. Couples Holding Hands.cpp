/*
//最多换n次肯定ok，把每个人按序号就坐（滑稽）
没啥头绪时，一个很好的办法是假设不要求写代码，先动手解决问题
search后得知Greedy即可，but why?
建模成图论（学完 Graph theory 的好处，遇到能建模成图论的问题会绕有自信）
人数是偶数，两两切分，形成n个节点，有配偶关系连一条线
已配对点便是孤立点，剩下m个点和m条线，一定是一个或多个环//m个点每点度为2，每边带走2个度，所以边数为m；每点度都为2，所以一定是环
对于size为x的环，我们只需要x-1次swap可以让这个环上的节点全部valid//数归？

Thoughts：
一个O(n^2)的解法，为什么测试用例只有[4, 60]？
如果对应关系不是0-1，2-3，该怎么设计universal的算法？
*/
//Here is a trick: 1^1=0 0^1=1 so 6^1=7 7^1=6
class Solution {
public:
	int minSwapsCouples(vector<int>& row) {
		int n = row.size(), result = 0;
		for (int i = 0; i < n; i += 2) {
			//int TheCouple = (row[i] % 2 == 0) ? row[i] + 1 : row[i] - 1;//[Without the trick]
			int TheCouple = row[i] ^ 1;//would be used 3 times, save time
			if (row[i + 1] == TheCouple)
				continue;
			else {
				for (int j = i + 1; j < n; ++j)// start from i+1
					if (row[j] == TheCouple) { // no need swap
						row[j] = row[i + 1];
						row[i + 1] = TheCouple;
						result++;//just after that if
						break;// there must be only one
					}
			}
		}
		return result;
	}
};
