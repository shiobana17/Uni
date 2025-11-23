public class Kumbha extends Thread {
    private String name;

    public Kumbha(String name) {
        this.name = name;
    }

    @Override
    public void run() {
        System.out.println(name + " is running.");
        try {
            Thread.sleep(1000); // Simulate some work with sleep
        } catch (InterruptedException e) {
            System.out.println(name + " was interrupted.");
        }finally {
        System.out.println(name + " has finished running.");
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Kumbha thread1 = new Kumbha("Kumbha-1");
        Kumbha thread2 = new Kumbha("Kumbha-2");

        thread1.start();
        thread2.start();
    }
}