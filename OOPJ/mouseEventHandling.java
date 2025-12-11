// Program to demonstrate Mouse Event Handling
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class mouseEventHandling implements MouseListener {
    JFrame frame;
    JLabel label;

    public mouseEventHandling() {
        frame = new JFrame("Mouse Event Handling Example");
        label = new JLabel("Click anywhere in the window", SwingConstants.CENTER);
        label.setFont(new Font("Arial", Font.PLAIN, 24));
        frame.add(label);
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.addMouseListener(this);
        frame.setVisible(true);
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        label.setText("Mouse Clicked at (" + e.getX() + ", " + e.getY() + ")");
    }

    @Override
    public void mousePressed(MouseEvent e) {
        label.setText("Mouse Pressed at (" + e.getX() + ", " + e.getY() + ")");
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        label.setText("Mouse Released at (" + e.getX() + ", " + e.getY() + ")");
    }

    @Override
    public void mouseEntered(MouseEvent e) {
        label.setText("Mouse Entered the window");
    }

    @Override
    public void mouseExited(MouseEvent e) {
        label.setText("Mouse Exited the window");
    }

    public static void main(String[] args) {
        new mouseEventHandling();
    }
}
