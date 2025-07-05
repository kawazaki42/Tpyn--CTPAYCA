/**
 * @file
 * Класс JavaFX-приложения.
 * @author Николай Ковалев
 */

package io.github.kawazaki42.task02loops;

// Стандартные импорты для JavaFX
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

// Исключение (ошибка) ввода-вывода
import java.io.IOException;


/// Класс JavaFX-приложения
public class LoopExampleApplication extends Application {
    /// Запустить JavaFX-приложение.
    /// @param stage окно приложения
    @Override  // Переопределение метода родительского класса
    public void start(Stage stage) throws IOException {
        // Загрузчик ресурсов - форма из FXML-файла
        FXMLLoader fxmlLoader = new FXMLLoader(
            LoopExampleApplication.class.getResource("form.fxml")
        );
        // Загрузить форму на окно и отобразить
        Scene scene = new Scene(fxmlLoader.load(), 320, 240);
        stage.setTitle("Hello!");
        stage.setScene(scene);
        stage.show();
    }
}
