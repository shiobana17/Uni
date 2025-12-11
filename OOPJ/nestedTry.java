// Program to demonstrate nested try-catch blocks
public class nestedTry {
    public static void main(String[] args) {
        try {
            System.out.println("Outer try block");
            try {
                System.out.println("Inner try block 1");
                int a = 10 / 0; // This will cause ArithmeticException
            } catch (ArithmeticException e) {
                System.out.println("Caught ArithmeticException in inner try block 1: " + e.getMessage());
            }
            
            try {
                System.out.println("Inner try block 2");
                String str = null;
                System.out.println(str.length()); // This will cause NullPointerException
            } catch (NullPointerException e) {
                System.out.println("Caught NullPointerException in inner try block 2: " + e.getMessage());
            }
        } catch (Exception e) {
            System.out.println("Caught Exception in outer try block: " + e.getMessage());
        }
    }
}
