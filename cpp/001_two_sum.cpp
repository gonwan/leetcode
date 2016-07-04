#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		map<int, int> m;
		for (vector<int>::const_iterator it = nums.begin(); it != nums.end(); ++it) {
			map<int, int>::const_iterator f = m.find(target-(*it));
			if (f == m.end()) {
				m[*it] = (it-nums.begin());
			} else {
				res.push_back(f->second);
				res.push_back(it-nums.begin());
				break;
			}
		}
		return res;
	}
};

int main() {
	return 0;
}

