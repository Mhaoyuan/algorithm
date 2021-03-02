#include<iostream>
#include"queue.h"

int main(){
    algo::Queue<int> q = algo::Queue<int>(2);
    for (int i = 0; i < 80; i++){
        q.Enqueue(i);
        int item = q.Dequeue();
      //  q.Show();
    }
    
    for (int i = 0; i < 10; i++){
        q.Enqueue(i);
        q.Show();
    }
    
    q.Show();
}

