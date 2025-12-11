// Program to create a simple Banking System using Interfaces
interface Bank {
    void deposit(int amt);
    void withdraw(int amt);
}

class Banking implements Bank {
    private int balance = 0;

    @Override
    public void deposit(int amt) {
        balance += amt;
        System.out.println("Deposited: " + amt + ", New Balance: " + balance);
    }

    @Override
    public void withdraw(int amt) {
        if (amt <= balance) {
            balance -= amt;
            System.out.println("Withdrew: " + amt + ", New Balance: " + balance);
        } else {
            System.out.println("Insufficient funds for withdrawal of: " + amt);
        }
    }
    public static void main(String[] args) {
        Banking myBank = new Banking();
        myBank.deposit(500);
        myBank.withdraw(200);
        myBank.withdraw(400);
    }
}
