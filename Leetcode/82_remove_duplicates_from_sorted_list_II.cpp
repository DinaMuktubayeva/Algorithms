#include <iostream>

// Given the head of a sorted linked list, delete all nodes that have
// duplicate numbers, leaving only distinct numbers from the original
// list. Return the linked list sorted as well.

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1. Create a pseudohead node pointing to the beginning of the
// linked list for the case the first node has to be removed
// 2. Using head as the pointer to the node we are currently processing,
// we will "jump over" duplicates as we traverse over the list
ListNode *deleteDuplicates(ListNode *head)
{
  if (!head)
    return head;

  // lastNode is the last node before the sublist of duplicates
  ListNode *pseudoHead = new ListNode(0, head);
  ListNode *lastNode = pseudoHead;

  while (head)
  {
    // if this is a beginning of a duplicates sublist
    if (head->next && head->val == head->next->val)
    {
      // "jumping over" the duplicates
      while (head->next && head->val == head->next->val)
      {
        // ListNode *temp = head;
        head = head->next;
        // delete (temp);
      }

      // ListNode *temp = head;
      // head = head->next;
      // delete (temp);
      lastNode->next = head->next;
    }
    else
    {
      lastNode = lastNode->next;
    }

    head = head->next;
  }

  return pseudoHead->next;
}

int main(int argc, char const *argv[])
{
  ListNode fourth(3);
  ListNode third(2, &fourth);
  ListNode second(2, &third);
  ListNode first(1, &second);
  ListNode *head = &first;

  while (head)
  {
    std::cout << head->val << " ";
    head = head->next;
  }

  std::cout << std::endl;
  head = deleteDuplicates(head);

  while (head)
  {
    std::cout << head->val << " ";
    head = head->next;
  }

  return 0;
}