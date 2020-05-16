/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
*/

/*
Solution 

 Maintain two heads
 1. for odd numbered nodes  -> oddHead = initialized to head   i.e. First node
 2. for even numbered nodes -> evenHead = initialized to head->next  i.e Second node
 
 Maintain two more pointers for the last node in each list => currOdd and currEven
 Initialize a temporary pointer to 3rd node
 
 *curr = 3rd node in the list
 
 Traverse the list while curr in not NULL i.e. end of list
  1. Add curr on odd list and Move curr to next
 2. Add curr to even list and Move curr to next

When we come out of while looop

We have two segregated of odd numbered nodes and even numbered nodes.

Append the even list at the end of odd list.
Set the next of even list to NULL
  
  
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head ||!head->next || !head->next->next)
            return head;
        
        ListNode* oddHead = head,*evenHead = head->next;
        ListNode* currOdd = oddHead, *currEven = evenHead;
        
        ListNode* curr = currEven->next;
        
        while(curr)
        {
            currOdd->next = curr;
            currOdd = currOdd->next;
            curr = curr->next;
            if(curr)
            {
                currEven->next = curr;
                currEven = currEven->next;
                curr = curr->next;
            }
            else
            {
                //currEven->next = curr;
                break;
            }
        }
        currEven->next = NULL;
        currOdd->next = evenHead;
        return oddHead;
    }
};
