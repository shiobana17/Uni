// Program to perform basic arithmetic operations
import java.util.Scanner;
public class arithmeticOperator {
    public static void main(String[] args) {
    int a,b;
    Scanner scanner = new Scanner(System.in);
    System.out.println("Enter two numbers:");
    a = scanner.nextInt();
    b = scanner.nextInt();
    scanner.close();
    System.out.println("Addition: " + (a + b));
    System.out.println("Subtraction: " + (a - b));
    System.out.println("Multiplication: " + (a * b));
    try {
        System.out.println("Division: " + (((float)a) / b));
        } catch (ArithmeticException e) {
        System.out.println("Error: Division by zero is not allowed.");
    }
}
}
