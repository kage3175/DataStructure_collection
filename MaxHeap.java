
public class MaxHeap{
  private int size = 0;
  private int heap[];
  private int full_size = 0;

  //siftDown, biggerchild, swap
  //, deleteMax, , , , , printHeap, setArr, heapify

  public MaxHeap(int size_){
    size = 0;
    full_size = size_;
    heap = new int[size_];
  }
  private void swap(int idx1, int idx2){
    if(idx1 >= size || idx2 >= size) return;
    int temp = heap[idx1];
    heap[idx1] = heap[idx2];
    heap[idx2] = temp;
  }
  private void siftDown(int idx){
    int x = idx;
    int size_2 = size / 2;
    while(x < size_2){
      x = biggerChild(idx);
      if(x == -1) return;
      if(heap[idx] < heap[x]){
        swap(idx, x);
      }
      else break;
      idx = x;
    }
    return;
  }
  private int biggerChild(int parent){
    if(parent * 2 > size - 2) return -1;
    else if(parent * 2 > size - 3) return parent * 2 + 1;
    else{
      return (heap[parent * 2 + 1] > heap[parent * 2 + 2]) ? (parent * 2 + 1) : (parent * 2 + 2);
    }
  }
  public void heapify(){
    if(isEmpty()) return;
    for(int i = size / 2 - 1; i >= 0; i--){
      siftDown(i);
    }
    return;
  }


  public int getMax(){
    return heap[0];
  }
  public int getSize(){
    return size;
  }
  public boolean isEmpty(){
    return (size <= 0) ? (true) : (false);
  }
  public boolean isFull(){
    return (size >= full_size) ? (true) : (false);
  }
  public void printHeap(){
    System.out.print("{");
    for(int i = 0; i< size; i++){
      System.out.print(heap[i] + ", ");
    }
    System.out.println("}");
  }
  public void setArr(int[] arr){
    if(arr.length > full_size){return;}
    size = arr.length;
    for(int i = 0; i < arr.length; i++){
      heap[i] = arr[i];
    }
  }
  public int deleteMax(){
    if(isEmpty()) return -1;
    int temp = heap[0];
    heap[0] = heap[--size];
    heap[size] = 0;
    siftDown(0);
    return temp;
  }

  public static void main(String[] args){
    MaxHeap heap = new MaxHeap(10);
    int arr[] = {7,2,5,0,1,9,8,3,6,4};
    System.out.println(arr);
    heap.setArr(arr);
    heap.printHeap();
    heap.heapify();
    heap.printHeap();
    System.out.println(heap.getMax());
    System.out.println(heap.deleteMax());
    heap.printHeap();
  }

}