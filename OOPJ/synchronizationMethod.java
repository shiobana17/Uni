// Program to demonstrate synchronization method for threads
class Counter {
    private int count = 0;

    // Synchronized method to ensure thread safety
    public synchronized void increment() {
        count++;
    }

    public int getCount() {
        return count;
    }
}
public class synchronizationMethod extends Thread {
    private Counter counter;

    public synchronizationMethod(Counter counter) {
        this.counter = counter;
    }

    public void run() {
        for (int i = 0; i < 10; i++) {
            counter.increment();
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Counter counter = new Counter();
        synchronizationMethod t1 = new synchronizationMethod(counter);
        synchronizationMethod t2 = new synchronizationMethod(counter);

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        System.out.println("Final count: " + counter.getCount());
    }
    
}
