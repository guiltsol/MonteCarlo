#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

// ���������� �������, ������� ������� �� ����� �����
double function(double x, double y) {
    
    return 2*pow(x, 2) + 4*x*y+8*pow(y, 2)+100;
}
void findMinimum(int iterations, double& min_value, double& min_x, double& min_y) {
    min_value = INFINITY; // �������������� min_value ����� ������� ������
    for (int i = 0; i < iterations; ++i) {
        // ���������� ��������� �������� ��� x � y
        double x = static_cast<double>(rand()) / RAND_MAX * 2.0 - 1.0;
        double y = static_cast<double>(rand()) / RAND_MAX * 2.0 - 1.0;

        x *= RAND_MAX; // ��������� �������� x
        y *= RAND_MAX; // ��������� �������� y

        // ��������� �������� ������� � ��������� ����� (x, y)
        double f_value = function(x, y);

        // ��������� min_value � ���������� ����� ��������, ���� ������� �������� f_value ������, ��� ��������� ����� �������
        if (f_value < min_value) {
            min_value = f_value;
            min_x = x;
            min_y = y;
        }
    }
    // ������� ��������� ����������� �������� ������� � ���������� ����� ��������
    std::cout << "��������� ����������� �������� �������: " << min_value << std::endl;
    std::cout << "���������� ����� ��������: (" << min_x << ", " << min_y << ")" << std::endl;

}
void findMinimumOgr(int iterations, double x_mi, double x_ma, double y_mi, double y_ma) {
    double x_min = x_mi; // ������ ������� ��� x
    double x_max = x_ma;  // ������� ������� ��� x
    double y_min = y_mi; // ������ ������� ��� y
    double y_max = y_ma;  // ������� ������� ��� y

    //int iterations = 1000000; // ���������� �������� ��� ��������� ������� �����-�����
    double min_value = INFINITY; // �������������� min_value ����� ������� ������
    double min_x, min_y; // ���������� ����� ��������
    double x, y, f_value;

    for (int i = 0; i < iterations; ++i) {
        // ���������� ��������� �������� ��� x � y � �������� ��������
        x = x_min + static_cast<double>(rand()) / RAND_MAX * (x_max - x_min);
        y = y_min + static_cast<double>(rand()) / RAND_MAX * (y_max - y_min);

        // ��������� �������� ������� � ��������� ����� (x, y)
        f_value = function(x, y);

        // ������� ���������� � ������� ��������
       // std::cout << "�������� " << i + 1 << ": x = " << x << ", y = " << y << ", f(x, y) = " << f_value << std::endl;

        // ��������� min_value � ���������� ����� ��������, ���� ������� �������� f_value ������, ��� ��������� ����� �������
        if (f_value < min_value) {
            min_value = f_value;
            min_x = x;
            min_y = y;
        }
    }

    // ������� ������ ������������ �������� ������� � ���������� ����� ��������
    std::cout << "������ ������������ �������� �������: " << min_value << std::endl;
    std::cout << "���������� ����� ��������: (" << min_x << ", " << min_y << ")" << std::endl;

}
int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0)); // �������������� ��������� ��������� �����

    int iterations1 = 1000000;
    double x_mi = -10;
    double x_ma = 10;
    double y_mi = -10;
    double y_ma = 10;


    int iterations2 = 10000000; // ���������� �������� ��� ��������� ������� �����-�����
    double min_value2, min_x2, min_y2;
    findMinimumOgr(iterations1, x_mi,x_ma,y_mi,y_ma); // �������� ������� ������ �������� � ������������ �� ������  
    findMinimum(iterations2, min_value2, min_x2, min_y2); // �������� ������� ������ �������� ��� ������������ �� ������ 

   
    return 0;
}