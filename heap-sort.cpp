#include <vector>
#include <string>
#include <iostream>

using namespace std;

void max_heapify(vector<int>& list, int position) {
    int left = position * 2;
    int right = position * 2 + 1;
    int largest = position;
    if (left <= list.size()) {
        if (list[left - 1] > list[largest - 1]) {
            largest = left;
        }
    }
    if (right <= list.size()) {
        if (list[right - 1] > list[largest - 1]) {
            largest = right;
        }
    }
    if (largest != position) {
        int temp = list[position - 1];
        list[position -1] = list[largest - 1];
        list[largest - 1] = temp;
        max_heapify(list, largest);
    }
    
}

void build_max_heap(vector<int>& list) {
    for (int i = list.size() / 2; i >= 1; i--) {
        max_heapify(list, i);
    }
}

void heap_sort() {

    vector<int> list = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    vector<int> sorted = vector<int>(list.size());
    build_max_heap(list);
    for (int i = list.size(); i >= 2; i--) {
        sorted[i - 1] = list[0];
        list.erase(list.begin());
        max_heapify(list, 1);
    }

    for (int item : sorted) {
        cout << item << ", ";
    }
}

int main() {
    heap_sort();
}