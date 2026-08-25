import java.util.*;

public class balance {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String str = sc.nextLine();

        Stack<Character> st = new Stack<>();

        for (char ch : str.toCharArray()) {

            // Opening brackets
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }

            // Closing brackets
            else if (ch == ')' || ch == ']' || ch == '}') {

                if (st.isEmpty()) {
                    System.out.println(false);
                    return;
                }

                char top = st.pop();

                if ((ch == ')' && top != '(') ||
                    (ch == ']' && top != '[') ||
                    (ch == '}' && top != '{')) {
                    System.out.println(false);
                    return;
                }
            }
        }

        System.out.println(st.isEmpty());
    }
}

