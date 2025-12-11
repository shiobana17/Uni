// Program to demonstrate call by value
public class callByValue {
    void modify(int num) {
        num = num + 10;
        System.out.println("Inside modify method: " + num);
    }

    public static void main(String[] args) {
        callByValue obj = new callByValue();
        int number = 20;
        System.out.println("Before modify method: " + number);
        obj.modify(number);
        System.out.println("After modify method: " + number);
    }
}
