// Program to create a Calculator GUI using GridLayout
import java.awt.*;
import javax.swing.*;
public class calculatorGridLayout {
    calculatorGridLayout() {
        JFrame frame = new JFrame("Calculator");
        frame.setSize(300, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(5, 4, 5, 5));

        String[] buttons = {
            "7", "8", "9", "/",
            "4", "5", "6", "*",
            "1", "2", "3", "-",
            "0", ".", "=", "+",
            "C"
        };

        for (String text : buttons) {
            JButton button = new JButton(text);
            frame.add(button);
        }

        frame.setVisible(true);
    }
    public static void main(String[] args) {
        new calculatorGridLayout();
    }
}
