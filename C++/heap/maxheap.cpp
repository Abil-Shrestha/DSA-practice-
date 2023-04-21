//maxheap
#include <iostream>
#include <vector>
using namespace std;


//maxheap class
class maxheap {
    private:
        vector<int> heap;
        int size;
        int left(int i) { return 2 * i + 1; }
        int right(int i) { return 2 * i + 2; }
        int parent(int i) { return (i - 1) / 2; }
        void heapify(int i) {
            int l = left(i);
            int r = right(i);
            int largest = i;
            if (l < size && heap[l] > heap[i]) {
                largest = l;
            }
            if (r < size && heap[r] > heap[largest]) {
                largest = r;
            }
            if (largest != i) {
                swap(heap[i], heap[largest]);
                heapify(largest);
            }
        }
    public:
        maxheap(vector<int> arr) {
            heap = arr;
            size = arr.size();
            for (int i = size / 2 - 1; i >= 0; i--) {
                heapify(i);
            }
        }
        int top() { return heap[0]; }
        void pop() {
            swap(heap[0], heap[size - 1]);
            size--;
            heapify(0);
        }
        void push(int val) {
            heap.push_back(val);
            size++;
            int i = size - 1;
            while (i != 0 && heap[parent(i)] < heap[i]) {
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }
        void print() {
            for (int i = 0; i < size; i++) {
                cout << heap[i] << " ";
            }
            cout << endl;
        }
};