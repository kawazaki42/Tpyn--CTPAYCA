/**
 * @file
 * Логика программы (Model по MVC)
 * @author Николай Ковалев
 */

// Имя пакета программы
package io.github.kawazaki42.task01arith;

// Встроенный класс с математическими методами и константами
import java.lang.Math;


/**
 * Класс с функциями (статическими методами),
 * которые вычисляют ответ на задачу (по данным формулам)
 */
public class Model {
    /**
     * Вычислить величину `a` по формуле.
     * @param x входное значение `x` согласно условиям задачи
     * @param y входное значение `y` согласно условиям задачи
     * @return значение `a`
     */
    public static double calcA(double x, double y) {
        double result;
        result = 2 * Math.cos(x - Math.PI/6.0);
        result /= 0.5 + Math.pow(Math.sin(y), 2);

        return result;
    }

    /**
     * Вычислить величину `b` по формуле.
     * @param z входное значение `z` согласно условиям задачи
     * @return значение `b`
     */
    public static double calcB(double z) {
        double result;
        result = z*z;
        result /= 3 + z*z/5;
        result += 1;

        return result;
    }
}
