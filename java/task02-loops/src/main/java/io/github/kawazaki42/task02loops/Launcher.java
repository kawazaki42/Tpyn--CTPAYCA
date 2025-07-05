/**
 * @file
 * Главный класс Java-программы.
 * @author Николай Ковалев
 */

package io.github.kawazaki42.task02loops;

// Класс приложения JavaFX
import javafx.application.Application;

/// Класс для запуска приложения
public class Launcher {
    /// Главная процедура (метод) Java-программы
    /// @param args аргументы (параметры) командной строки
    public static void main(String[] args) {
        // Запустить JavaFX-приложение
        Application.launch(LoopExampleApplication.class, args);
    }
}
