// Program to demonstrate call by reference
public class callByReference {
    public int x = 20;
    void modify(callByReference p) {
        p.x = p.x + 10;
        System.out.println("Inside modify method: (" + p.x +")");
    }
    public static void main(String[] args) {
        callByReference obj = new callByReference();
        System.out.println("Before modify method: (" + obj.x +")");
        obj.modify(obj);
        System.out.println("After modify method: (" + obj.x +")");
    }
}
