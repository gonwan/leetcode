struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(0) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int sum = 0, carry = 0;
		ListNode *head = 0, **curr = &head;
		while (l1 || l2) {
			sum = carry;
			if (l1) {
				sum += l1->val;
				l1 = l1->next;
			}
			if (l2) {
				sum += l2->val;
				l2 = l2->next;
			}
			if (sum < 10) {
				carry = 0;
			} else {
				carry = 1;
				sum -= 10;
			}
			*curr = new ListNode(sum);
			curr = &((*curr)->next);
		}
		if (carry) {
			*curr = new ListNode(1);
		}
		return head;
	}
};

int main() {
	return 0;
}

