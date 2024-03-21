import sys

class MaxHeap:
  def __init__(self, size) -> None:
    self.size = 0
    self.heap = [0 for _ in range(size)]
  
  def setArr(self, arr):
    if len(self.heap) >= len(arr):
      self.heap = arr.copy()
      self.size = len(arr)
      return True
    else:
      return False
    
  def isEmpty(self):
    return True if self.size == 0 else False
  
  def isFull(self):
    return True if self.size == len(self.heap) else False
  
  def getSize(self):
    return self.size
  
  def __biggerChild(self, idx):
    if idx * 2 > self.size - 3:
      return idx * 2 + 1
    else:
      return idx * 2 + 1 if (self.heap[idx * 2 + 1] > self.heap[idx * 2 + 2]) else idx * 2 + 2
  
  def siftDown(self, idx):
    x = idx
    while(x < self.size // 2):
      x = self.__biggerChild(idx)
      if self.heap[idx] < self.heap[x]:
        self.heap[idx], self.heap[x] = self.heap[x], self.heap[idx]
      else:
        break
      idx = x
  
  def heapify(self):
    for i in range(self.size//2 - 1, -1, -1):
      self.siftDown(i)

  def getMax(self):
    return self.heap[0]
  
  def deleteMax(self):
    if not self.isEmpty():
      temp = self.heap[0]
      self.heap[0] = self.heap[self.size - 1]
      self.heap[self.size - 1] = 0
      self.size -= 1
      self.siftDown(0)
      return temp
    else:
      return -1


'''heap = MaxHeap(10)
heap.setArr([1,9,4,7,2,3,0,8,5,6])
print(heap.heap)
print(heap.isFull())
heap.heapify()
print(heap.getMax())
print(heap.deleteMax())
print(heap.getSize())'''