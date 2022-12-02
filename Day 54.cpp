// Code 1 - Reverse Linked List

// Recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       if(!head or !head->next) return head;
        ListNode* newHead = reverseList(head->next);
        
        ListNode* temp = head->next;
        temp->next = head;
        head->next = nullptr;
        
        return newHead;
    }
};

// Iterative


// Code 2 - Remove Nth Node From End of List

  class Solution {
  public:
      ListNode* removeNthFromEnd(ListNode* head, int n) {
          auto slow = head, fast = slow;
          while(n--) fast = fast->next;
          if(!fast) return head->next;
          while(fast && fast->next) {
              slow = slow->next;
              fast = fast->next;
          } slow->next = slow->next->next;
          return head;
      }
  };

// Code 3 - Delete the Middle Node of a Linked List

  class Solution {
    public ListNode deleteMiddle(ListNode head) {
        if(head.next == null) return head.next;
        ListNode slow = head;
        ListNode fast = head.next;
        if(fast.next == null) {
            head.next = head.next.next;
            return head;
        }
        while(fast != null && fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        slow.next = slow.next.next;
        return head;
    }
}