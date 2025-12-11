// Program to demonstrate interface
interface A {
    void show();
}
public class interfaceDemo implements A {
    @Override
    public void show() {
        System.out.println("Interface method implemented");
    }
    public static void main(String[] args) {
        interfaceDemo obj = new interfaceDemo();
        obj.show();
    }
}
