import java.util.*;
class reverse{
    public ListNode reverse(ListNode curr , ListNode prev) {
        if (curr == null) return prev;
        ListNode next = curr.next;
        curr.next = prev;
        prev = curr;
        return reverse(next, prev); 
    }
    public ListNode reverseList(ListNode head) {
         return reverse(head, null);
       
    }
}
