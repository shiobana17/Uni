// Program to demonstrate different types of inheritance

// 1. Single Inheritance
class Animal {
    void eat() { System.out.println("Eating"); }
}
class Dog extends Animal { }

// 2. Multilevel Inheritance
class Vehicle {
    void start() { System.out.println("Starting"); }
}
class Car extends Vehicle { }
class SportsCar extends Car { }

// 3. Hierarchical Inheritance
class Shape {
    void draw() { System.out.println("Drawing"); }
}
class Circle extends Shape { }
class Rectangle extends Shape { }

// 4. Multiple Inheritance (using interfaces)
interface Flyable {
    void fly();
}
interface Swimmable {
    void swim();
}
class Duck implements Flyable, Swimmable {
    public void fly() { System.out.println("Flying"); }
    public void swim() { System.out.println("Swimming"); }
}

// 5. Hybrid Inheritance
class Device {
    void power() { System.out.println("Powered on"); }
}
interface Connectable {
    void connect();
}
class Phone extends Device implements Connectable {
    public void connect() { System.out.println("Connected"); }
}
class Tablet extends Device implements Connectable {
    public void connect() { System.out.println("Connected"); }
}

public class inheritance {
    public static void main(String[] args) {
        System.out.println("1. Single:");
        new Dog().eat();
        
        System.out.println("2. Multilevel:");
        new SportsCar().start();
        
        System.out.println("3. Hierarchical:");
        new Circle().draw();
        new Rectangle().draw();
        
        System.out.println("4. Multiple:");
        Duck d = new Duck();
        d.fly();
        d.swim();
        
        System.out.println("5. Hybrid:");
        Phone p = new Phone();
        p.power();
        p.connect();
    }
}