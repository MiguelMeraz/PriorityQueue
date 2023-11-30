//
// Created by miguel meraz on 11/20/23.
//

#ifndef PRIORITYQUEUE_HEAP_H_H
#define PRIORITYQUEUE_HEAP_H_H

#include <string>
#include <vector>

template <class T>
class PriorityQueue {
public:
    void push(const T& x);
    T pop();
    const T& peek() const;
    bool isEmpty() const;
    int getLength() const;

private:
    int leftChildIndex(int index) const;
    int rightChildIndex(int index) const;
    int parentIndex(int index) const;

    // the underlying "array" that holds the heap nodes
    std::vector<T> heapArray;
};

// FІΧМЕ: calculate the left child index, given a node's index
template <class T>
int PriorityQueue<T>::leftChildIndex(int index) const {
    return (index * 2) + 1;
}

//Fixme: this is how to calculate the index of min-heap tree: Parent, right, left
//Parent: (current index - 1) // 2 (round down)
//Left child: (current index * 2) + 1
//Right child: (current index * 2) + 2

// FІΧМЕ: calculate the right child index, given a node's index
template <class T>
int PriorityQueue<T>::rightChildIndex(int index) const {
    return (index * 2) + 2;
}

// FІΧМЕ: calculate the parent index, given a node's index
template <class T>
int PriorityQueue<T>::parentIndex(int index) const {
    return (index - 1) / 2;
}

// FІΧМЕ: implement the push method to add a new node into the heap
template <class T>
void PriorityQueue<T>::push(const T& x){
    heapArray.push_back(x);
    int index = heapArray.size() - 1;
    int parent = parentIndex(index);
while( index > 0 && heapArray[index] < heapArray[parent]){
        T temp = heapArray[index];
        heapArray[index] = heapArray[parent];
        heapArray[parent] = temp;
        index = parent;
        parent = parentIndex(index);
    }
}

// FІΧМЕ: implement the remove method
// Remove the min element, and also return a copy of it
template <class T>
T PriorityQueue<T>::pop() {
    // replace the root with the bottommost, rightmost node
    // we will return the node you just "popped" at the very end of this method

    // remove the bottommost, rightmost node

    // bubble the new root down to where it needs to be

    // return a copy of the value you removed

    /*looking to see if the heap is empty*/
    if(!heapArray.empty()){

        // I want to switch the root with the last most leaf node
        T temp = heapArray[0]; //temp holds key of the zero index
        heapArray[0] = heapArray[heapArray.getLength() - 1]; // 0 index now holds last leaf
        heapArray[heapArray.getLength() - 1] = temp; // and last leaf hols what temp held
        //may want to begin my while loop

        T popKey = heapArray.at(heapArray.getLength() - 1); //variable
        heapArray.pop_back();// deleting the last leaf

        T currentIndex = heapArray[0];
        while(true){
            T currentKey = heapArray.at(0);//holds the key to the root index
            // we have to look left and right if possible
            T leftIndex = heapArray.at(heapArray.at(leftChildIndex(0)));
            if (leftIndex >= heapArray.size())
            {
                break;  // we're a leaf--stop
            }
            // if we got this far, we know we at least have a left key
            T leftKey = heapArray.at(leftIndex);
            T rightIndex = heapArray.at(heapArray.at(rightChildIndex(0))); // holding the key
            int rightKey;
            if (rightIndex < heapArray.size())
            {
                rightKey = heapArray.at(rightIndex);
            }
            // if neither child is bigger, we're done
            // (i.e., we're >= to them)
            // again, there might not be a right child
            if (leftKey >= currentKey &&
                (rightIndex >= heapArray.size() || rightKey >= currentKey))
            {
                break;
            }
            // swap with the bigger one
            if (rightIndex >= heapArray.size() || leftKey < rightKey) {
                // either the right index doesn't exist, or the left key is
                // bigger than the right
                // swap with left
                heapArray.at(currentIndex) = leftKey;
                heapArray.at(leftIndex) = currentKey;
                // our current index has changed
                currentIndex = leftIndex;
            } else {
                // swap with right
                heapArray.at(currentIndex) = rightKey;
                heapArray.at(rightIndex) = currentKey;
                // our current index has changed
                currentIndex = rightIndex;
            }
        }
        return popKey;
    }
    //if we get to this point it means heapArray is empty
    return nullptr;//implement this
}

// FІΧМЕ: implement the peek method to return a reference to the current min
template <class T>
const T& PriorityQueue<T>::peek() const{
    return heapArray.front();
}


// FІΧМЕ: implement the isEmpty method to return whether the heap is empty
template <class T>
bool PriorityQueue<T>::isEmpty() const{
    return heapArray.empty();
}


// FІΧМЕ: implement the getLength method to get the size of the heap
template <class T>
int PriorityQueue<T>::getLength() const{
    return heapArray.size();
}
// The following is not a method--you'll *use* the PriorityQueue class
// FІΧМЕ: sort the input vector (from smallest to biggest) using a
// PriorityQueue<T>
template <class T>
std::vector<T> heapSort(const std::vector<T>& v) {
    std::vector<T> result;
    PriorityQueue<T> container;
    int i = 0;
    while(i < v.size()){
        container.push(v.at(i));

        i++;
    }

    while(!container.isEmpty()){
        result.push_back(container.peek());
        container.pop();
    }
    return result;
}

#endif //PRIORITYQUEUE_HEAP_H_H
