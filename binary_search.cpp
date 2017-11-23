#include <iostream>


int BinarySearch(int* a, int size, int v)
{
  int r = size - 1;
  int m;
  for(int i = 0; r < size; i <= r) {
    m = (i + r)/2;
    if(a[m] == v) {
      return m;
    }
    if(a[m] < v) {
      i = m + 1;
    }
    if(a[m] > v) {
      r = m - 1;
    }
  }
 return -1;
}

int main() {
  int a[] = {1,2,3,4,5,6,7};
  std::cout << BinarySearch(a, 8, 4);
  return 0;
}