// Program to demonstrate traffic lights in Java Swing using buttons
import javax.swing.*;
import java.awt.event.*;

public class trafficLights implements ActionListener {
    JFrame frame;
    JButton redButton, yellowButton, greenButton;
    JLabel lightLabel;

    public trafficLights() {
        frame = new JFrame("Traffic Lights");
        redButton = new JButton("Red");
        redButton.setBounds(50, 50, 100, 30);
        yellowButton = new JButton("Yellow");
        yellowButton.setBounds(50, 100, 100, 30);
        greenButton = new JButton("Green");
        greenButton.setBounds(50, 150, 100, 30);
        lightLabel = new JLabel("Light is OFF");
        lightLabel.setBounds(50, 200, 200, 30);

        redButton.addActionListener(this);
        yellowButton.addActionListener(this);
        greenButton.addActionListener(this);

        frame.add(redButton);
        frame.add(yellowButton);
        frame.add(greenButton);
        frame.add(lightLabel);
        frame.setSize(300, 300);
        frame.setLayout(null);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == redButton) {
            lightLabel.setText("STOP");
            lightLabel.setForeground(java.awt.Color.RED);
        } else if (e.getSource() == yellowButton) {
            lightLabel.setText("READY");
            lightLabel.setForeground(java.awt.Color.YELLOW);
        } else if (e.getSource() == greenButton) {
            lightLabel.setText("GO");
            lightLabel.setForeground(java.awt.Color.GREEN);
        }
    }

    public static void main(String[] args) {
        new trafficLights();
    }
    
}
