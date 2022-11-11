// Lab 4
// Alexander Chen SUID: 4186272

#include <iostream>
using namespace std;
/*
** Min-Heap construction and basic operations
** Lab 4, CPSC 2430, Xin Zhao
*/
// define the max size for the heap array
#include <iostream>

const int HEAP_MAX_SIZE = 1000;
class MinHeap {
private:
    int heapArr[HEAP_MAX_SIZE];
    int size;
    void swap(int x, int y) {
        //Storing the value of index y in a temp variable then swapping the values.
        int temp = heapArr[x];
        heapArr[x] = heapArr[y];
        heapArr[y] = temp;

    }

    // helper method to find the difference between two index value, and
    //returns that value to be utilized for each functions conditional
    int compareTo(int a, int b){
        return heapArr[b] - heapArr[a];
    }
    void percolateUp(int index) {
        /*
         * Since it is a min heap, values that are smaller will percolate up
         * As we find the parent index with the formula
         * The last node we will be checking is the root node so the parent index
         * have to be greater or equal to 0
         * The compareTo helper method finds the difference of index value and parent index
         * If it is above 0, it would mean the parent index value is greater than the index values
         * so we would need to swap them, continue call the percolate up function, until it does not satisfy
         * the conditions
         *
        */
        int parentIndex = (index -1)/2;
        if (parentIndex >=0 && compareTo(index, parentIndex) > 0){
            swap(index,parentIndex);
            percolateUp(parentIndex);
        }

    }
    void percolateDown(int index) {
        //initiates the indexs of current min value index
        // the index of left and right child of the parent index
        int minValIndex = index;
        int leftChild =2*index +1;
        int rightChild =2*index +2;

        // checks if left or right child is the last nodes we should iterate through if the node index is not
        // above the heap size, also using the helper funciton compareTo, it will cehck
        // whether if the maxValIndex value is bigger tahn the current (left or right) child value.
        // when we found that a left or right child is  smaller than minValIndex value, than it would be above a difference of 0
        // so it would change the minValIndex to the child and swap it with the index, so it could put in the right position.
        if(leftChild < heapSize() && compareTo(leftChild, minValIndex)> 0){
            minValIndex = leftChild;
        }else if(rightChild < heapSize() && compareTo(rightChild, minValIndex) > 0){
            minValIndex = rightChild;
        }

        if(minValIndex != index){
            swap(index, minValIndex);
            percolateDown(minValIndex);
        }

    }
public:
    MinHeap() {
        size = -1;
    }

    void insert(int element) {
        /*
         * checks that the size of the heap did not exceed the limit
         * then the last leaf node will be the inserted value, and will be
         * put in correct position by percolate up
         */
        if(++size < HEAP_MAX_SIZE){
            heapArr[size] = element;
            percolateUp(size);
        }
    }
    void deleteMin() {
        /*
         * swaps the root and last leaf node
         * then removes the last index of the leaf node
         * by decreasing the size of the array
         * using percolate down to put the swapped root node
         * into correct position
         */
        swap(0,heapSize()-1);
        size--;
        percolateDown(0);

    }
    int extractMin() {
        // Since it is minheap, the first value of the
        // array (minheap) should be the min, so index 0
        return heapArr[0];
    }
    int heapSize() {
        // index starts from 0, so the actual size is the size + 1
        return size + 1;
    }
    void heapDisplay() {
        // iterates through the arraylist( minheap ) and prints out
        // the value in the heap
        for(int i = 0; i < heapSize(); i++){
            cout << heapArr[i] << " ";
        }
        cout<< endl;
    }
};
// in your main function, test your implementations. For example,
int main() {
    MinHeap mh;
    mh.insert(4);
    mh.insert(8);
    mh.insert(1);
    mh.insert(7);
    mh.insert(3);
    // display heap
    mh.heapDisplay();  // the output should be: 1, 3, 4, 8, 7
    // deleteMin
    mh.deleteMin();
    mh.heapDisplay();  // the output should be: 3, 7, 4, 8
    // extractMin
    cout << mh.extractMin() << endl;   // the output should be: 3
    // heapSize
    cout << mh.heapSize() << endl;   // the output should be: 4
    return 0;
}
