// 백준 문제 : 가운데를 말해요

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <cmath>

#define HEAP_SIZE 100000

using namespace std;

int heap[HEAP_SIZE];

// heap count is representing that the number of indices and the end index number of a heap DS.
int heap_count = 0; 

void swap(int * a, int * b) {
	int temp = *a; 
	*a = *b; 
	*b = temp;
}

void push(int data) {

	heap[++heap_count] = data;

	int child = heap_count;
	int parent = child / 2;
	while (child > 1 && heap[parent] < heap[child]) {
		swap(&heap[parent], &heap[child]);
		child = parent;
		parent = child / 2;
	}

}

int pop() {

        // returning the first element of a heap DS.
	int result = heap[1];

	swap(&heap[1], &heap[heap_count]);
	heap_count--;

	// Reconstructing tree structure after popping a root node.
	int parent = 1;
	int child = parent * 2;
	if (child + 1 <= heap_count) {
		child = (heap[child] > heap[child + 1]) ? child : child + 1;
	}

	while (child <= heap_count && heap[parent] < heap[child]) {
		swap(&heap[parent], &heap[child]);

		parent = child;
		child = child * 2;
		if (child + 1 <= heap_count) {
			child = (heap[child] > heap[child + 1]) ? child : child + 1;
		}
	}
	return result;
}

int main(){
    int N;
    cin >> N;

    // priority_queue<int> pq;
    // vector<int> storage;
    int result[N]; 
    for(int i=0;i<N;i++){
        int element;
        cin >> element;
        push(element);
        // cout << heap_count << endl;
        
        
        // cout << pq.size() << "/" << storage.size() << endl;
        // int pSize = floor(pq.size()/2);
        // for(int j=0;j<pSize;j++){
        //     storage.push_back(pq.top());
        //     pq.pop();
        // }
        // // cout << pq.size() << "/" << storage.size() << endl; 
        // result[i] = pq.top();
        // int sSize = storage.size();
        // for(int j=0;j<sSize;j++){
        //     pq.push(storage.front());
        //     storage.pop_back();
        // }
        // cout << pq.size() << "/" << storage.size() << endl;
        // for(int j=0;j<pq.size();j++){
        //     cout << pq.top() << " ";
        //     storage.push_back(pq.top());
        //     pq.pop();
            
        // } 
        // for(int j=0;j<storage.size();j++){
        //     pq.push(storage.front());
        //     storage.pop_back();
        // }   
        // cout <<endl;    
    }

    for(int i=0;i<N;i++){
        cout << result[i] << endl;
    }
}