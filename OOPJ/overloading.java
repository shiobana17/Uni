// Program to demonstrate method overloading
public class overloading {
    void display(int num) {
        System.out.println("Integer: " + num);
    }
    void display(String str) {
        System.out.println("String: " + str);
    }
    public static void main(String[] args) {
        overloading obj = new overloading();
        obj.display(10);
        obj.display("Hello");
    }
}
