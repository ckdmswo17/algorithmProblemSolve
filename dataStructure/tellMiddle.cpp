// 백준 문제 : 가운데를 말해요 / 분명히 다맞는거 같은데 시간초과가 뜰때는 cin 버퍼 초기화와 \n 사용을 해보자!

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

// #define HEAP_SIZE 100000

using namespace std;

// int maxHeap[HEAP_SIZE];
// int minHeap[HEAP_SIZE];

// // heap count is representing that the number of indices and the end index number of a heap DS.
// int minHeap_count = 0; 
// int maxHeap_count = 0; 

// void swap(int * a, int * b) {
// 	int temp = *a; 
// 	*a = *b; 
// 	*b = temp;
// }

// void minPush(int data) {

// 	minHeap[++minHeap_count] = data;

// 	int child = minHeap_count;
// 	int parent = child / 2;
// 	while (child > 1 && minHeap[parent] > minHeap[child]) {
// 		swap(&minHeap[parent], &minHeap[child]);
// 		child = parent;
// 		parent = child / 2;
// 	}

// }

// int minTop() {

//         // returning the first element of a minHeap DS.
// 	int result = minHeap[1];

// 	// swap(&minHeap[1], &minHeap[minHeap_count]);
// 	// minHeap_count--;

// 	// // Reconstructing tree structure after popping a root node.
// 	// int parent = 1;
// 	// int child = parent * 2;
// 	// if (child + 1 <= minHeap_count) {
// 	// 	child = (minHeap[child] < minHeap[child + 1]) ? child : child + 1;
// 	// }

// 	// while (child <= minHeap_count && minHeap[parent] > minHeap[child]) {
// 	// 	swap(&minHeap[parent], &minHeap[child]);

// 	// 	parent = child;
// 	// 	child = child * 2;
// 	// 	if (child + 1 <= minHeap_count) {
// 	// 		child = (minHeap[child] < minHeap[child + 1]) ? child : child + 1;
// 	// 	}
// 	// }
//     // minHeap_count++;
// 	return result;
// }

// void maxPush(int data) {

// 	maxHeap[++maxHeap_count] = data;

// 	int child = maxHeap_count;
// 	int parent = child / 2;
// 	while (child > 1 && maxHeap[parent] < maxHeap[child]) {
// 		swap(&maxHeap[parent], &maxHeap[child]);
// 		child = parent;
// 		parent = child / 2;
// 	}

// }

// int maxTop() {

//         // returning the first element of a maxHeap DS.
// 	int result = maxHeap[1];

// 	// swap(&maxHeap[1], &maxHeap[maxHeap_count]);
// 	// maxHeap_count--;

// 	// // Reconstructing tree structure after popping a root node.
// 	// int parent = 1;
// 	// int child = parent * 2;
// 	// if (child + 1 <= maxHeap_count) {
// 	// 	child = (maxHeap[child] > maxHeap[child + 1]) ? child : child + 1;
// 	// }

// 	// while (child <= maxHeap_count && maxHeap[parent] < maxHeap[child]) {
// 	// 	swap(&maxHeap[parent], &maxHeap[child]);

// 	// 	parent = child;
// 	// 	child = child * 2;
// 	// 	if (child + 1 <= maxHeap_count) {
// 	// 		child = (maxHeap[child] > maxHeap[child + 1]) ? child : child + 1;
// 	// 	}
// 	// }
//     // maxHeap_count++;
// 	return result;
// }

int main(){ // 위는 minHeap, 아래는 maxHeap인데 위에 큰거 다넣고 아래엔 작은거 다넣는 모래시계 구조 생각하면 편함
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    
    // vector<int> result(N,0);

    // for(int i=0;i<N;i++){
    //     int element;
    //     cin >> element;
    //     if(i%2 == 0){
    //         maxPush(element);
    //     } else {
    //         minPush(element);
    //     }

    //     if(maxHeap[1] )
    //     swap(maxHeap[1],minHeap[1]);

    //     for(int j=1;j<=maxHeap_count;j++){
    //         cout << maxHeap[j] << " ";
    //     }
    //     cout << endl;
    //     for(int j=1;j<=minHeap_count;j++){
    //         cout << minHeap[j] << " ";
    //     }
    //     cout << endl;

    //     result[i] = maxTop();
        // result[i] = maxHeap[1];
    // }

    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int>> min;

    for(int i =0;i<N;i++){
        int element;
        cin >> element;
        if(i % 2 == 0){
            max.push(element);
        } else {
            min.push(element);
        }

        int maxTop = max.top();
        if(i != 0){
            int minTop = min.top();
            if(maxTop > minTop){
                max.pop();
                min.pop();
                max.push(minTop);
                min.push(maxTop);
            }
        }
        cout << max.top() << "\n";
        // result[i] = max.top();
    }

    // for(int i=0;i<N;i++){
    //     cout << result[i]<< endl;
    // }
}