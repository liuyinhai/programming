#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == NULL || head->next == NULL) return head;
        ListNode* result = head->next, *now = head, *tmp, *backward = result;
        while (true)
        {
            if (now == NULL || now->next == NULL)
            {
                break;
            }
            if (backward != result)
                backward->next = now->next;
            tmp = now->next;
            now->next = tmp->next;
            tmp->next = now;
            backward = now;            
            now = now->next;
        }
        return result;
    }
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

int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);    
    node1->next = node2;
    node2->next = node3;
    // node3->next = node4;
    PrintList(node1);
    Solution solution;
    ListNode* now = solution.swapPairs(node1);
    PrintList(now);
    return 0;
}
