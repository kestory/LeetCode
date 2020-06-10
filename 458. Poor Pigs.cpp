https://www.zhihu.com/question/60227816/answer/1275395545

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log(buckets)/log((minutesToTest / minutesToDie) + 1));
    }
};
