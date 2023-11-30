#include <iostream>
#include <vector>
#include "heap_h.h"

using namespace std;

int main() {

    vector<int> numbers {8, 3, 2, 9, 4, 6};

    heapSort(numbers);
    return 0;
}
