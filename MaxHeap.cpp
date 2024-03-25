#include <iostream>
#include <cassert>
using namespace std;

class MaxHeap{
  private:
    int size;
    int *heap;
    void siftDown(int idx); //done
    int biggerChild(int idx); //done
    void swap(int idx1, int idx2); //done
  public:
    MaxHeap(int size_){
      size = size_;
      heap = new int[size];
    }
    int getMax(); // done
    int deleteMax(); //done
    void setArr(int arr[], int length); //done
    void heapify(); //done
    bool isEmpty(); //done
    int getSize(); //done
    bool isFull(); //done
    void printHeap(); //done
};

int MaxHeap::getMax(){
  return heap[0];
}

int MaxHeap::getSize(){
  return size;
}

bool MaxHeap::isFull(){
  return (size == sizeof(heap) / sizeof(int));
}

bool MaxHeap::isEmpty(){
  return (size == 0);
}

void MaxHeap::setArr(int arr[], int length){
  assert(length <= size);
  for(int i = 0; i < length; i++){
    heap[i] = arr[i];
  }
  size = length;
}

void MaxHeap::siftDown(int idx){
  int x = idx;
  while(x < size / 2){
    x = biggerChild(idx);
    if (heap[idx] < heap[x]){
      swap(idx, x);
    }
    else{break;}
    idx = x;
  }
}

void MaxHeap::swap(int idx1, int idx2){
  if(idx1 > size - 1 || idx2 > size - 1){return;}
  else{
    int temp = heap[idx1];
    heap[idx1] = heap[idx2];
    heap[idx2] = temp;
  }
}

int MaxHeap::biggerChild(int idx){
  if(idx * 2 > size - 2){return -1;}
  if(idx * 2 > size - 3){
    return idx * 2 + 1;
  }
  else{
    return (heap[idx*2 + 1] > heap[idx * 2 + 2]) ? (idx * 2 + 1) : (idx * 2 + 2);
  }
}

int MaxHeap::deleteMax(){
  if(isEmpty()) return -1;
  else{
    int temp = heap[0];
    heap[0] = heap[--size];
    heap[size] = 0;
    siftDown(0);
    return temp;
  }
}

void MaxHeap::heapify(){
  if(isEmpty()){return;}
  else{
    for(int i = size / 2 - 1; i >= 0; i--){
      siftDown(i);
    }
    return;
  }
}

void MaxHeap::printHeap(){
  cout << "{";
  for(int i = 0;i < size; i++){
    cout << heap[i] << ", ";
  }
  cout << "}" << endl;;
}

int main(){
  MaxHeap* heap = new MaxHeap(10);
  int arr[10] = {0,5,7,1,9,3,2,8,4,6};
  heap->setArr(arr, (sizeof(arr) / sizeof(int)));
  heap->heapify();
  heap->printHeap();
  cout << heap->getMax() << heap -> getSize() << endl;
  cout << heap -> deleteMax() << endl;
  heap->printHeap();
  cout << heap->getSize() << endl;
  return 0;
}