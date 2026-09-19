class intersection{
    public Node findIntersection(Node head1, Node head2) {
        Node result = new Node(0);
        Node temp1 = head1;
        Node temp2 = head2;
        Node ans = result;
        while (temp1 != null && temp2 != null) {
            if (temp1 != null && temp2 != null && temp1.data == temp2.data) {
                ans.next = new Node(temp1.data);
                ans = ans.next;
                temp1 = temp1.next;
                temp2 = temp2.next;
            }
                       if (temp1 != null && temp2 != null && temp1.data == temp2.data) {


            while ( temp1 != null && temp2 != null && temp1.data < temp2.data) {
                temp1 = temp1.next;
            }
            while ( temp1 != null && temp2 != null && temp1.data > temp2.data) {
                temp2 = temp2.next;
            }
            
            
        }
        return result.next;
    }
}
