class Solution {
    public boolean isValid(String s) {
        // Create a manual stack using a char array
        char[] stack = new char[s.length()];
        int top = -1;

        for (char ch : s.toCharArray()) {
            // 1. If it's an opening bracket, push it to our array stack
            if (ch == '(' || ch == '{' || ch == '[') {
                stack[++top] = ch;
            } 
            // 2. If it's a closing bracket
            else {
                // If stack is empty or top doesn't match, it's invalid
                if (top == -1) return false;
                
                char lastOpening = stack[top--];
                if (ch == ')' && lastOpening != '(') return false;
                if (ch == '}' && lastOpening != '{') return false;
                if (ch == ']' && lastOpening != '[') return false;
            }
        }
        
        // 3. If top is -1, all brackets were matched and popped
        return top == -1;
    }
}