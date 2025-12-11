// Program to demonstrate abstract class
abstract class Animal {
    abstract void show();
}
class Wolf extends Animal {
    @Override
    void show() {
        System.out.println("Wolf object created");
    }
}
public class abstractClass {
    public static void main(String[] args) {
        Animal obj = new Wolf();
        obj.show();
    }
}
