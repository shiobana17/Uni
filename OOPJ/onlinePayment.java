// Program to simulate simple online payment using overloading and overriding
class Payment {
    void pay(double amount) {
        System.out.println("Paid amount: " + amount);
    }
    //Overloading
    void pay(String currency, double amount) {
        System.out.println("Paid amount: " + amount + " " + currency);
    }
}

class UPI extends Payment{
    @Override
    void pay(double amount) {
        System.out.println("Paid via UPI: " + amount);
    }
    
}
public class onlinePayment {
    public static void main(String[] args) {
        Payment payment = new Payment();
        UPI upiPayment = new UPI();
        payment.pay(1000);
        payment.pay("INR", 1500);
        upiPayment.pay(2000);
    }
}
