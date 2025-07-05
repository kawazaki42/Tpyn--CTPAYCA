/**
 * @file
 * Логика программы (Model по MVC).
 * @author Николай Ковалев
 * @details
 *     (84) Даны натуральное n, действительное х. Вычислить:
 *       А) sin(х) + sin(х)^2 + ... + sin(х)^n;
 */

package io.github.kawazaki42.task02loops;


/// Логика программы
public class Model {
    /// Вычислить ответ по формуле из задачи
    /// @param n кол-во слагаемых
    /// @param x аргумент синуса
    /// @return сумма из формулы
    public static double calc(int n, double x) {
        // sin(x) не меняется, заранее вычислим его
        double sinX = Math.sin(x);

        // sin(x)^i, где 1 <= i <= n
        // Чтобы не вычислять Math.pow(sinX, i)
        double sinXpowN = sinX;
        double sum = 0.0d;
        for(int i = 1; i <= n; i++) {
            sum += sinXpowN;
            sinXpowN *= sinX;
        }

        return sum;
    }
}
