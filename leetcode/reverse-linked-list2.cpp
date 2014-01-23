#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void PrintList(ListNode* head)
{
    while (head != NULL)
    {
        cout<<head->val<<"\t";
        head = head->next;
    }
    cout<<endl;
}

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == NULL || m >= n ) return head;
        ListNode* now = head, *backward = head, *forward = head, *left = head, *right = head;
        for (int i = 1; i < m - 1; i++)
        {
            now = now->next;
            if (now == NULL) return head;
        }
        if (m != 1)
        {
            backward = now;
            now = now->next;
        }
        left = now;
        right = now;
        if (now == NULL) return head;
        now = now->next;
        for (int i = m; i < n; i++)
        {
            if (now == NULL)
            {
                if (m != 1)
                    backward->next = left;
                else
                    head = left;
                right->next = NULL;
                return head;
            }
            forward = now->next;
            now->next = left;
            left = now;
            now = forward;
        }
        if (m != 1)
            backward->next = left;
        else
            head = left;
        right->next = forward;
        return head;
    }    
};


int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    PrintList(node1);
    Solution solution;
    ListNode* now = solution.reverseBetween(node1, 1, 3);
    PrintList(now);
    return 0;
}
