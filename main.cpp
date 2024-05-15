#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

// Определяем функцию, минимум которой мы хотим найти
double function(double x, double y) {
    
    return 2*pow(x, 2) + 4*x*y+8*pow(y, 2)+100;
}
void findMinimum(int iterations, double& min_value, double& min_x, double& min_y) {
    min_value = INFINITY; // Инициализируем min_value очень большим числом
    for (int i = 0; i < iterations; ++i) {
        // Генерируем случайные значения для x и y
        double x = static_cast<double>(rand()) / RAND_MAX * 2.0 - 1.0;
        double y = static_cast<double>(rand()) / RAND_MAX * 2.0 - 1.0;

        x *= RAND_MAX; // Расширяем диапазон x
        y *= RAND_MAX; // Расширяем диапазон y

        // Вычисляем значение функции в случайной точке (x, y)
        double f_value = function(x, y);

        // Обновляем min_value и координаты точки минимума, если текущее значение f_value меньше, чем найденный ранее минимум
        if (f_value < min_value) {
            min_value = f_value;
            min_x = x;
            min_y = y;
        }
    }
    // Выводим найденное минимальное значение функции и координаты точки минимума
    std::cout << "Найденное минимальное значение функции: " << min_value << std::endl;
    std::cout << "Координаты точки минимума: (" << min_x << ", " << min_y << ")" << std::endl;

}
void findMinimumOgr(int iterations, double x_mi, double x_ma, double y_mi, double y_ma) {
    double x_min = x_mi; // Нижняя граница для x
    double x_max = x_ma;  // Верхняя граница для x
    double y_min = y_mi; // Нижняя граница для y
    double y_max = y_ma;  // Верхняя граница для y

    //int iterations = 1000000; // Количество итераций для симуляции методом Монте-Карло
    double min_value = INFINITY; // Инициализируем min_value очень большим числом
    double min_x, min_y; // Координаты точки минимума
    double x, y, f_value;

    for (int i = 0; i < iterations; ++i) {
        // Генерируем случайные значения для x и y в заданных границах
        x = x_min + static_cast<double>(rand()) / RAND_MAX * (x_max - x_min);
        y = y_min + static_cast<double>(rand()) / RAND_MAX * (y_max - y_min);

        // Вычисляем значение функции в случайной точке (x, y)
        f_value = function(x, y);

        // Выводим информацию о текущей итерации
       // std::cout << "Итерация " << i + 1 << ": x = " << x << ", y = " << y << ", f(x, y) = " << f_value << std::endl;

        // Обновляем min_value и координаты точки минимума, если текущее значение f_value меньше, чем найденный ранее минимум
        if (f_value < min_value) {
            min_value = f_value;
            min_x = x;
            min_y = y;
        }
    }

    // Выводим оценку минимального значения функции и координаты точки минимума
    std::cout << "Оценка минимального значения функции: " << min_value << std::endl;
    std::cout << "Координаты точки минимума: (" << min_x << ", " << min_y << ")" << std::endl;

}
int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0)); // Инициализируем генератор случайных чисел

    int iterations1 = 1000000;
    double x_mi = -10;
    double x_ma = 10;
    double y_mi = -10;
    double y_ma = 10;


    int iterations2 = 10000000; // Количество итераций для симуляции методом Монте-Карло
    double min_value2, min_x2, min_y2;
    findMinimumOgr(iterations1, x_mi,x_ma,y_mi,y_ma); // Вызываем функцию поиска минимума с ограничением по точкам  
    findMinimum(iterations2, min_value2, min_x2, min_y2); // Вызываем функцию поиска минимума без ограничейний по точкам 

   
    return 0;
}