import stack.ArrayStack;

public class Main {
    public static void main(String[] args) {
       try {
            ArrayStack<Integer> stack = new ArrayStack<>(5);
            stack.push(3);
            System.out.println(stack.peek());
        } catch (Exception e) {
            System.out.println("Erro: " + e.getMessage());
        }
    }
}
