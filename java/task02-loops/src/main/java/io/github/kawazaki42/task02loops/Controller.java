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
    /// Поле отчета
    public TextArea reportArea;
    /// Поле ввода N (кол-ва слагаемых)
    public TextField textInputN;
    /// Поле ввода X (аргумента синуса)
    public TextField textInputX;
    /// Подпись с ответом
    public Label labelResult;

    /// Обработать нажатие кнопки "Вычислить"
    /// @param ignoredActionEvent событие нажатия (не используется)
    public void onCalcButtonClick(ActionEvent ignoredActionEvent) {
        // Кол-во слагаемых
        int n = Integer.parseUnsignedInt( textInputN.getText() );
        // Аргумент синуса
        double x = Double.parseDouble( textInputX.getText() );

        double result = Model.calc(n, x);

        // Вывести результат в надпись (Label)
        labelResult.setText( String.format("result = %.2f", result) );

        // Текст отчета
        String report = "";
        report += String.format("x = %f%n", x);
        report += String.format("n = %d%n", n);
        report += String.format("result = %f%n%n", result);

        // Вывести отчет в конец поля (без перезаписи)
        reportArea.appendText(report);
    }
}
