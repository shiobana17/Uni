// Program to demonstrate rethrowing exceptions
public class Rethrow {
    static void methodA() {
        try {
            int data = 50 / 0; // This will cause ArithmeticException
        } catch (ArithmeticException e) {
            System.out.println("Exception caught in methodA: " + e.getMessage());
            throw e; // Rethrowing the exception
        }
    }
    public static void main(String[] args) {
        try {
            methodA();
        } catch (ArithmeticException e) {
            System.out.println("Exception rethrown to main: " + e.getMessage());
        }
    }
}
