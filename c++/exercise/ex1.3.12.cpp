#include<iostream>
#include "../stack/stack.h"

int main(){
    algo::Stack<int> s;
    for (int i = 0; i < 10; i++){
        s.Push(i);
    }
    algo::Stack<int> s2(s);
    s2.Show();
    algo::Stack<int> s3;
    s3 = s;
    s3.Show();
    algo::Stack<int> s4(std::move(s3));
    s4.Show();
    algo::Stack<int> s5;
    s5 = std::move(s4);
    s5.Show();
}