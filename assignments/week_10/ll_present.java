import java.util.*;

class ll_present {

    public static boolean check(Node temp1, Node temp2) {

        while (temp1 != null && temp2 != null) {

            if (temp1.data != temp2.data) {
                return false;
            }

            temp1 = temp1.next;
            temp2 = temp2.next;
        }

        
        return temp1 == null;
    }

    public static boolean isSubList(Node list1, Node list2) {

        if (list1 == null) {
            return true;
        }

        Node temp = list2;

        while (temp != null) {

         
            if (temp.data == list1.data) {

                if (check(list1, temp)) {
                    return true;
                }
            }

            temp = temp.next;
        }

        return false;
    }
}

