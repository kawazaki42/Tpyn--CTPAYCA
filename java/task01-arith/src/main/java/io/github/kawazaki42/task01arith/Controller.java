/**
 * @file
 * Работа с графическими компонентами (Controller по MVC)
 * @author Николай Ковалев
 */

package io.github.kawazaki42.task01arith;


// Стандартные импорты для JavaFX
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

/**
 * Класс контороллера.
 */
public class Controller {
    /// Подпись с вычисленным значением `a`
    @FXML  // Позволяет JavaFX соотнести поле с компонентом в FXML-файле
    private Label labelAnswerA;

    /// Подпись с вычисленным значением `b`
    @FXML
    private Label labelAnswerB;

    /// Поле ввода для `x`
    @FXML
    private TextField textInputX;

    /// Поле ввода для `y`
    @FXML
    private TextField textInputY;

    /// Поле ввода для `z`
    @FXML
    private TextField textInputZ;

    /// Многострочное поле для отчета
    public TextArea reportArea;

    /// Обработчик события - нажатия на кнопку "Вычислить"
    @FXML
    protected void onCalcButtonClick() {
        /// Входные значения
        double x, y, z;
        x = Double.parseDouble( textInputX.getText() );
        y = Double.parseDouble( textInputY.getText() );
        z = Double.parseDouble( textInputZ.getText() );

        /// Ответ на задачу
        double a, b;
        a = Model.calcA(x, y);
        b = Model.calcB(z);

        /// Ответы на задачу в виде строк
        String aStr, bStr;
        aStr = String.format( "%.2f", a );
        bStr = String.format( "%.2f", b );

        labelAnswerA.setText("a = " + aStr);
        labelAnswerB.setText("b = " + bStr);

        String report = String.format(
                "x = %f%n" +
                "y = %f%n" +
                "z = %f%n%n" +
                "a = %f%n" +
                "b = %f%n%n",
                x, y, z, a, b
        );

        reportArea.appendText( report );
    }
}