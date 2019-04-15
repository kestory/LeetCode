#记录当前最小值和最大差值 也是剑指Offer 63-股票的最大利润
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if (len < 2)
			return 0;
		int Min = prices[0];
		int CurrentDiff;
		int MaxDiff = prices[1] - prices[0];
		for (int i = 2; i < len; ++i)
		{
			if (prices[i - 1] < Min)
				Min = prices[i - 1];
			CurrentDiff = prices[i] - Min;
			if (CurrentDiff > MaxDiff)
				MaxDiff = CurrentDiff;

		}
		if (MaxDiff < 0)
			return 0;
		else
			return MaxDiff;
	}
};
