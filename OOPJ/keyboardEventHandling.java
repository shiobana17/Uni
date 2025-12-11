// Program to demonstrate Keyboard Event Handling
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class keyboardEventHandling implements KeyListener {
    JFrame frame;
    JLabel label;

    public keyboardEventHandling() {
        frame = new JFrame("Keyboard Event Handling Example");
        label = new JLabel("Press any key", SwingConstants.CENTER);
        label.setFont(new Font("Arial", Font.PLAIN, 24));
        frame.add(label);
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.addKeyListener(this);
        frame.setVisible(true);
    }

    @Override
    public void keyTyped(KeyEvent e) {
        label.setText("Key Typed: " + e.getKeyChar());
    }

    @Override
    public void keyPressed(KeyEvent e) {
        label.setText("Key Pressed: " + KeyEvent.getKeyText(e.getKeyCode()));
    }

    @Override
    public void keyReleased(KeyEvent e) {
        label.setText("Key Released: " + KeyEvent.getKeyText(e.getKeyCode()));
    }

    public static void main(String[] args) {
        new keyboardEventHandling();
    }
    
}
