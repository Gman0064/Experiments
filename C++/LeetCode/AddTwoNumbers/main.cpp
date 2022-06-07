#include <iostream>
#include <vector>
#include <math.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* lr = new ListNode(0);

    int l1_sum = 0;
    int l2_sum = 0;
    std::vector<int> l1_nums = {};
    std::vector<int> l2_nums = {};

    ListNode* node = l1;
    while (node != nullptr) {
        l1_nums.push_back(node->val);
        node = node->next;
    }

    node = l2;
    while (node != nullptr) {
        l2_nums.push_back(node->val);
        node = node->next;
    }

    for (int i = (l1_nums.size() - 1); i >= 0; i--) {
        l1_sum += (l1_nums[i] * (pow(10, i)));
    }

    for (int i = (l2_nums.size() - 1); i >= 0; i--) {
        l2_sum += (l2_nums[i] * (pow(10, i)));
    }

    int final_sum = l1_sum + l2_sum;

    node = lr;
    lr->val = (final_sum % 10);
    final_sum /= 10;

    while (final_sum > 0)
    {
        ListNode* new_node = new ListNode(final_sum % 10);
        node->next = new_node;
        node = node->next;
        final_sum /= 10;
    }

    return lr;
}

int main() {
    ListNode* l1 = new ListNode(2);
    ListNode* l1_1 = new ListNode(4);
    ListNode* l1_2 = new ListNode(3);

    l1->next = l1_1;
    l1_1->next = l1_2;

    ListNode* l2 = new ListNode(5);
    ListNode* l2_1 = new ListNode(6);
    ListNode* l2_2 = new ListNode(4);

    l2->next = l2_1;
    l2_1->next = l2_2;

    addTwoNumbers(l1, l2);

    return 0;
}
