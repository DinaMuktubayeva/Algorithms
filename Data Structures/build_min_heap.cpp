#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;

class HeapBuilder {
 private:
  vector<int> data_;

  void PrintResult() const {
    for (size_t i = 0; i < data_.size(); ++i) {
      cout << data_[i] << " ";
    }
    cout << "\n";
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  int parent(int i) {
    return (i-1) / 2;
  }

  int leftChild(int i) {
    return 2 * i + 1;
  }

  int rightChild(int i) {
    return 2 * i + 2;
  }

  void siftDown(int i) {
    int mindex = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left < data_.size() && data_[left] < data_[mindex])
      mindex = left;

    if (right < data_.size() && data_[right] < data_[mindex])
      mindex = right;

    if (i != mindex) {
      swap(data_[i], data_[mindex]);
      siftDown(mindex);
    }
  }

  void BuildHeap() {
    int n = data_.size();
    for (int i = n / 2 - 1; i >= 0; i--){
      siftDown(i);
    }
  }

 public:
  void Solve() {
    ReadData();
    BuildHeap();
    PrintResult();
  }
};

int main() {
  //std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}