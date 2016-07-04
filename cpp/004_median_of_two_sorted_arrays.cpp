#include <vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int sum = 0, curr = 0;
		int sz = nums1.size() + nums2.size();
		bool odd = sz & 1;
		int anchor = (sz + 1) >> 1;
		size_t i = 0, j = 0, index = 0;
		while (i < nums1.size() || j < nums2.size()) {
			index++;
			if (i >= nums1.size()) {
				curr = nums2[j++];
			} else if (j >= nums2.size()) {
				curr = nums1[i++];
			} else {
				if (nums1[i] < nums2[j]) {
					curr = nums1[i++];
				} else {
					curr = nums2[j++];
				}
			}
			if (index == anchor) {
				if (odd) {
					return curr;
				} else {
					sum += curr;
					continue;
				}
			} else if (index == anchor+1) {
				sum += curr;
				return sum / 2.0;
			}
		}
		return 0.0;
	}
};

int main() {
	return 0;
}
