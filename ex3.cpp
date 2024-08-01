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