// Program to demonstrate the use of final keyword
public class finalKeyword {
    public static void main(String[] args) {
        final int MAX_VALUE = 100;
        System.out.println("The maximum value is: " + MAX_VALUE);
        
        // Uncommenting the following line will cause a compilation error
        // MAX_VALUE = 200; // Error: cannot assign a value to final variable MAX_VALUE
    }
}
