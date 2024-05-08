#include<iostream>
using namespace std;

class hp {
    int heap[20], heap1[20], n1, i;
public:
    hp(){
        heap[0] = heap1[0] = 0;
    } 
    void getdata();
    void maxhp(int heap[], int);
    void minhp(int heap1[], int);
    void minmax();
};

void hp::getdata() {
    cout << "\n enter the no. of students: ";
    cin >> n1;
    cout << "\n enter the marks: ";
    for(i = 0; i < n1; i++) {
        cin >> heap[i + 1];
        heap1[i + 1] = heap[i + 1];
        maxhp(heap, i + 1);
        minhp(heap1, i + 1);
    }
}

void hp::maxhp(int heap[], int i) {
    int temp;
    while(i > 1 && heap[i] > heap[i/2]) {
       temp = heap[i];
       heap[i] = heap[i/2];
       heap[i/2] = temp;
       i = i/2;
    }
}

void hp::minhp(int heap1[], int i) {
    int temp1;
    while(i > 1 && heap1[i] < heap1[i/2]) {
       temp1 = heap1[i];
       heap1[i] = heap1[i/2];
       heap1[i/2] = temp1;
       i = i/2;
    }
}

void hp::minmax() {
   cout << "\n max marks: " << heap[1] << endl;
//    for(i = 1; i <= n1; i++) {
//         cout << heap[i] << endl;                 //show max heap
//     }
   cout << "\n min marks: " << heap1[1] << endl;
//    for(i = 1; i <= n1; i++) {
//         cout << heap1[i] << endl;                //show min heap
//     }
}

int main() {  
    hp h;
    h.getdata();
    h.minmax();
    return 0;
}
