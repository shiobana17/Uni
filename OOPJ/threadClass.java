// Program to demonstrate Thread by extending Thread class
public class threadClass extends Thread{
    public void run(){
        System.out.println("Thread is running...");
    }

    public static void main(String args[]){
        threadClass t1 = new threadClass();
        t1.start();
    }
}
