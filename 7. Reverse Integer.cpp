#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		int re = 0;
		while (x != 0) {
			if (abs(re) > INT_MAX / 10) return 0;
			re = re * 10 + x % 10;
			x /= 10;
		}
		return re;

	}
};
class Solution_s {
public:
	int reverse(int x) {
		string s = to_string(x);
		int re = 0;
		while (x % 10 == 0 && x != 0)
			x /= 10;
		if (abs(x) > INT_MAX / 10) return 0;
		if (x > 0)
			std::reverse(s.begin(), s.end());
		else
			std::reverse(s.begin() + 1, s.end());

		re = stoi(s);
		return re;
	}
};
int main()
{
//	 Solution s;
	Solution_s s;
	cout << s.reverse(123) << endl;
	cout << s.reverse(0) << endl;
	cout << s.reverse(-123) << endl;
	cout << s.reverse(120) << endl;
	cout << s.reverse(-120) << endl;

	assert(s.reverse(1) == 1);
	assert(s.reverse(0) == 0);
	assert(s.reverse(123) == 321);
	assert(s.reverse(120) == 21);
	assert(s.reverse(-123) == -321);
	assert(s.reverse(1207) == 7021);
	assert(s.reverse(INT_MAX) == 0);
	assert(s.reverse(INT_MIN) == 0);
	// [−2^31,  2^31 − 1]
	return 0;
}
