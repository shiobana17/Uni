// Program to demonstrate Thread by implementing Runnable interface
public class threadInterface implements Runnable {
    @Override
    public void run() {
        System.out.println("Thread is running...");
    }

    public static void main(String args[]) {
        Thread t1 = new Thread(new threadInterface());
        t1.start();
    }
    
}
