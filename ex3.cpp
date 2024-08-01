#include <iostream>
#include <fstream>
#include <vector>


int binarySearch(int* mas, int n, int target) {
    int left = 0;          // Левая граница массива
    int right = n - 1;     // Правая граница массива

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Находим середину

        if (mas[mid] == target) {
            return mid;  // Элемент найден, возвращаем его индекс
        }
        else if (mas[mid] < target) {
            left = mid + 1;  // Искомый элемент правее середины
        }
        else {
            right = mid - 1;  // Искомый элемент левее середины
        }
    }

    return -1;  // Элемент не найден
}