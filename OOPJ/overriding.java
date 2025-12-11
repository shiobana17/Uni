// Program to demonstrate method overriding
class Parent {
    void show() {
        System.out.println("Parent object created");
    }
}
class Child extends Parent {
    @Override
    void show() {
        System.out.println("Child object created");
    }
}
public class overriding {
    public static void main(String[] args) {
        Parent obj1 = new Parent();
        obj1.show();

        Parent obj2 = new Child();
        obj2.show();
    }
}
