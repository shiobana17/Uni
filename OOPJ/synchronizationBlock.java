// Program to demonstrate synchronization block for threads
class Counter {
    private int count = 0;

    public void increment() {
        // Synchronization block to ensure thread safety
        synchronized (this) {
            count++;
        }
    }

    public int getCount() {
        return count;
    }
}
public class synchronizationBlock extends Thread {
    private Counter counter;

    public synchronizationBlock(Counter counter) {
        this.counter = counter;
    }

    public void run() {
        for (int i = 0; i < 10; i++) {
            counter.increment();
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Counter counter = new Counter();
        synchronizationBlock t1 = new synchronizationBlock(counter);
        synchronizationBlock t2 = new synchronizationBlock(counter);

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        System.out.println("Final count: " + counter.getCount());
    }
    
}
