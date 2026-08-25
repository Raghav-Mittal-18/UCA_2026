import java.util.*;

public class postfix {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String str = sc.nextLine();

        Stack<Integer> st = new Stack<>();

        for (int i = 0; i < str.length(); i++) {

            char ch = str.charAt(i);

            if (ch == ' ') {
                continue;
            }

            if (Character.isDigit(ch)) {
                st.push(ch - '0');
            }
            else {
                int b = st.pop();
                int a = st.pop();

                if (ch == '+')
                    st.push(a + b);

                else if (ch == '-')
                    st.push(a - b);

                else if (ch == '*')
                    st.push(a * b);

                else if (ch == '/')
                    st.push(a / b);
            }
        }

        System.out.println(st.pop());
    }
}

