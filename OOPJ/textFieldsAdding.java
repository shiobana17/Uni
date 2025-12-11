// Program to demonstrate adding two text fields in Java Swing
import javax.swing.*;
import java.awt.event.*;
public class textFieldsAdding implements ActionListener {
    JFrame frame;
    JTextField textField1, textField2;
    JButton addButton;

    public textFieldsAdding() {
        frame = new JFrame("Add Two Numbers");
        textField1 = new JTextField();
        textField1.setBounds(50, 50, 150, 20);
        textField2 = new JTextField();
        textField2.setBounds(50, 100, 150, 20);
        JLabel resultField = new JLabel();
        resultField.setBounds(50, 150, 150, 20);
        addButton = new JButton("Add");
        addButton.setBounds(50, 200, 80, 30);
        addButton.addActionListener(this);

        frame.add(textField1);
        frame.add(textField2);
        frame.add(resultField);
        frame.add(addButton);
        frame.setSize(300, 300);
        frame.setLayout(null);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent e) {
        try {
            int num1 = Integer.parseInt(textField1.getText());
            int num2 = Integer.parseInt(textField2.getText());
            int sum = num1 + num2;
            JOptionPane.showMessageDialog(frame, "Sum: " + sum);
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(frame, "Please enter valid integers.");
        }
    }

    public static void main(String[] args) {
        new textFieldsAdding();
    }
}
