#include<iostream>
#include"../stack/stack.h"

int main(){
    algo::StackList<int> sl = algo::StackList<int>();
    int N = 100;
    while(N > 0){
        sl.Push(N % 2);
        N = N / 2;
    }
    sl.Show();
}