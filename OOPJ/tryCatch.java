// Program to demonstrate try-catch for exception handling
public class tryCatch {
    public static void main(String[] args) {
        try {
            int a = 10/0;
            System.out.println("Result: " + a);
        } catch (ArithmeticException e) {
            System.out.println("Error: Division by zero is not allowed.");
        }
    }
}
