#include<iostream>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {};
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (head == NULL) return NULL;
        
        RandomListNode *now = head, *copy;
        while (now != NULL)
        {
            copy = new RandomListNode(now->label);
            copy->next = now->next;
            now->next = copy;
            now = copy->next;
        }
        now = head;
        while (now != NULL)
        {
            if (now->random != NULL)
                now->next->random = now->random->next;
            now = now->next->next;
        }
        now = head, copy = head->next;
        RandomListNode *result = head->next;
        while (now != NULL)
        {
            now->next = copy->next;
            if (now->next == NULL)
            {
                copy->next = NULL;
                break;
            }
            else
                copy->next = now->next->next;
            now = now->next;
            copy = now->next;
        }
        return result;
    }
};

void PrintList(RandomListNode *head)
{
    for (RandomListNode* now = head; now != NULL; now = now->next)
    {
        cout<<"label: "<<now->label<<"\tlabel of random: ";
        if (now->random == NULL)
            cout<<"NULL";
        else
            cout<<now->random->label;
        cout<<endl;
    }
}

int main()
{
    Solution solution;
    RandomListNode *head = new RandomListNode(1);
    head->next = NULL;
    head->random = NULL;
    PrintList(head);
    RandomListNode *copy = solution.copyRandomList(head);
    cout<<endl;
    PrintList(copy);
    return 0;
}
