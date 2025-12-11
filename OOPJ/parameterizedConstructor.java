// Program to demonstrate parameterized constructor
public class parameterizedConstructor {
    parameterizedConstructor(String name) {
        System.out.println("Hello, " + name);
    }
    public static void main(String[] args) {
        parameterizedConstructor obj = new parameterizedConstructor("Alice");
    }
}
