/**
 * @file
 * Главная часть программы.
 * @author Николай Ковалев
 */

package io.github.kawazaki42.task01arith;

// Стандартные импорты для JavaFX
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

/// Исключение (ошибка) ввода-вывода
import java.io.IOException;


/// Главный класс программы.
/// Наследует от javafx.application.Application
public class ArithExampleApplication extends Application {
    /// Запустить JavaFX-приложение.
    /// @param stage окно приложения
    @Override  // Переопределение метода родительского класса
    public void start(Stage stage) throws IOException {
        /// Загрузчик ресурсов - форма из FXML-файла
        FXMLLoader fxmlLoader = new FXMLLoader(
                ArithExampleApplication.class.getResource("view.fxml")
        );
        // Загрузить форму на окно
        Scene scene = new Scene(fxmlLoader.load(), 320, 240);
        stage.setTitle("Задача 1 - арифметика");
        stage.setScene(scene);
        stage.show();
    }

    /// Главная процедура (метод) программы.
    /// Позволяет запустить JavaFX-приложение по обычному интерфейсу Java.
    /// @param args параметры (аргументы) командной строки.
    ///             Игнорируются. Необходимы для правильного объявления `main`
    public static void main(String[] args) {
        // Application.launch - запустить приложение по правилам JavaFX
        launch();
    }
}