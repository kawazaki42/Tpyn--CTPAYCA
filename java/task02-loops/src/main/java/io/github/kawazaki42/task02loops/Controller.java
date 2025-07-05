/**
 * @file
 * Работа с графическими компонентами (Controller по MVC)
 * @author Николай Ковалев
 */

package io.github.kawazaki42.task02loops;

// Событие (не используется)
import javafx.event.ActionEvent;
// Позволяет JavaFX соотнести поле с компонентом в FXML-файле
import javafx.fxml.FXML;
// Надпись
import javafx.scene.control.Label;
// Многострочное поле ввода
import javafx.scene.control.TextArea;
// Однострочное поле ввода
import javafx.scene.control.TextField;


/// Класс для работы с графическими компонентами
public class Controller {
    public TextArea reportArea;
    public TextField textInputN;
    public TextField textInputX;
    public Label labelResult;

    public void onCalcButtonClick(ActionEvent ignoredActionEvent) {
        int n = Integer.parseUnsignedInt( textInputN.getText() );
        double x = Double.parseDouble( textInputX.getText() );

        double result = Model.calc(n, x);

        labelResult.setText( String.format("result = %.2f", result) );

        String report = "";
        report += String.format("x = %f%n", x);
        report += String.format("n = %d%n", n);
        report += String.format("result = %f%n%n", result);

        reportArea.appendText(report);
    }
}
