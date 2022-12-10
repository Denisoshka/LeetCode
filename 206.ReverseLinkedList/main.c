#include "stdio.h"

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  struct ListNode *Next = head->next, *Prev = NULL;

  for (; Next != NULL; Next = Next->next) {
    head->next = Prev;
    Prev = head;
    head = Next;
  }
  head->next = Prev;

  return head;
}
