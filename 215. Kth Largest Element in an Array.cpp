class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() - k];//逆序为k-1
	}
};
//O(NlogN + k)
//=======max_heap&&priority_queue&&multiset=======//
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int result;
		make_heap(nums.begin(), nums.end());
		for (int i = 0; i < k; ++i) {
			result = nums.front();
			pop_heap(nums.begin(), nums.end());
			nums.pop_back();
		}
		return result;//直接返回nums.front()会少一名
	}
};

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int>pq(nums.begin(), nums.end());
		for (int i = 0; i < k - 1; i++)
			pq.pop();
		return pq.top();
	}
};

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		multiset<int> mset(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - k; ++i)
			mset.erase(mset.begin());
		return *mset.begin();
	}
};
//=======max_heap&&priority_queue&&multiset=======//
