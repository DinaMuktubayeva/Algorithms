// Our main task is to determine the locations of the nodes whose
// values are to be swapped. This can be done by traversing the list
// using two pointers - fast and slow, with a certain distance between
// them.

// Algorithm
// 1. Put slow at head, and put fast k-1 nodes after slow.
// 2. first = fast.
// 3. If fast isn't already at the last node, move slow and fast one node further until fast.next == null
// 4. second = slow
// 5. Swap the values of first and second

class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode swapNodes(ListNode head, int k) {
        ListNode fast = head;
        ListNode slow = head;
        ListNode first = head, second = head;

        // Put fast (k-1) nodes after slow
        for (int i = 0; i < k - 1; ++i)
            fast = fast.next;

        // Save the node for swapping
        first = fast;

        // Move until the end of the list
        while (fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }

        // Save the second node for swapping Note that the pointer
        // second isn't necessary: we could use slow for swapping as
        // well However, having second improves readability
        second = slow;

        // Swap values
        int temp = first.val;
        first.val = second.val;
        second.val = temp;

        return head;
    }
}

public class Test {
    public static void main(String[] args) {
        ListNode fourth = new ListNode(4);
        ListNode third = new ListNode(3, fourth);
        ListNode second = new ListNode(2, third);
        ListNode first = new ListNode(1, second);
        ListNode head = new ListNode(0, first);

        System.out.print("Before swapping: ");
        print(head);
        System.out.println();

        Solution sol = new Solution();
        head = sol.swapNodes(head, 2);

        System.out.print("After swapping: ");
        print(head);
    }

    public static void print(ListNode head) {
        while (head != null) {
            System.out.print(head.val + " ");

            head = head.next;
        }
    }
}