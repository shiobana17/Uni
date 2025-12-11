// Program to demonstrate the use of super keyword
class Car {
    String color = "Red";
    
    void display() {
        System.out.println("Car color: " + color);
    }
}
public class superKeyword extends Car {
    String color = "Blue";
    @Override
    void display() {
        System.out.println("Car color from subclass: " + color);
        System.out.println("Car color from superclass: " + super.color);
        super.display();
    }
    
    public static void main(String[] args) {
        superKeyword myCar = new superKeyword();
        myCar.display();
    }
    
}
