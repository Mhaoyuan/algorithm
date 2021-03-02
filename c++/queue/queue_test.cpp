#include<iostream>
#include"queue.h"

int main(){
    algo::Queue<int> q = algo::Queue<int>(2);
    for (int i = 0; i < 20; i++){
        q.Enqueue(i);
        int item = q.Dequeue();
      //  q.Show();
    }
    
    for (int i = 0; i < 10; i++){
        q.Enqueue(i);
        q.Show();
    }
    q.Show();
    std::cout << "queue implement by list" << std::endl;
    {
        algo::QueueList<int> ql = algo::QueueList<int>();
        for(int i = 0; i < 10; i++){
            ql.Enqueue(i);
        }
        for (int i = 0; i<5; i++){
            int item = ql.Dequeue();
        }
        ql.Show();

        
    }
}

