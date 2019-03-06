// 利用map，记录nums1的元素与频率，遍历nums2，找到相同元素就存储在result中并让频率--
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        for (int i = 0; i < nums1.size(); ++i)
            m[nums1[i]] += 1;
        vector<int> res;
        for (int i = 0; i < nums2.size(); ++i)
            if (m[nums2[i]] > 0) {
                res.push_back(nums2[i]);
                m[nums2[i]]--;
            }

        return res;
    }
};

