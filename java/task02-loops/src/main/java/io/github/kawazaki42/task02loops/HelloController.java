/**
 * @file
 * Работа с графическими компонентами (Controller по MVC)
 * @author Николай Ковалев
 */

package io.github.kawazaki42.task02loops;

// Позволяет JavaFX соотнести поле с компонентом в FXML-файле
import javafx.fxml.FXML;
// Надпись
import javafx.scene.control.Label;

/// Класс для работы с графическими компонентами
public class HelloController {
    @FXML
    private Label welcomeText;

    @FXML
    protected void onHelloButtonClick() {
        welcomeText.setText("Welcome to JavaFX Application!");
    }
}
