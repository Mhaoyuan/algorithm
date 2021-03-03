#include<iostream>
#include"../stack/stack.h"
#include"../queue/queue.h"

int main() {
    algo::StackList<int> stack = algo::StackList<int>();
    algo::QueueList<int> queue = algo::QueueList<int>(); 
    for(int i = 0; i < 10; i++) {
        queue.Enqueue(i);
    }
    while(!queue.IsEmpty()){
        stack.Push(queue.Dequeue());
    }
    while(!stack.IsEmpty()){
        queue.Enqueue(stack.Pop());
    }
    queue.Show();
}