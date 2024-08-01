#include <iostream>
#include <fstream>
#include <vector>


int binarySearch(int* mas, int n, int target) {
    int left = 0;          // ����� ������� �������
    int right = n - 1;     // ������ ������� �������

    while (left <= right) {
        int mid = left + (right - left) / 2;  // ������� ��������

        if (mas[mid] == target) {
            return mid;  // ������� ������, ���������� ��� ������
        }
        else if (mas[mid] < target) {
            left = mid + 1;  // ������� ������� ������ ��������
        }
        else {
            right = mid - 1;  // ������� ������� ����� ��������
        }
    }

    return -1;  // ������� �� ������
}


//int main() {
//    int mas[] = { 1, 3, 5, 7, 9, 11, 13, 15 };
//    int n = sizeof(mas) / sizeof(mas[0]); // ������ �������
//    int target = 7;  // ������� �������
//
//    int result = binarySearch(mas, n, target);
//
//    if (result != -1) {
//        std::cout << "������� " << target << " ������ � ������� �� ������� " << result << std::endl;
//    }
//    else {
//        std::cout << "������� " << target << " �� ������ � �������." << std::endl;
//    }
//
//    return 0;
//}