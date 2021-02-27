#include<iostream>
#include"stack.h"
int main(){
    algo::Stack<int> s = algo::Stack<int>(20);
    for (int i = 0;i < 9; i++){
        s.Push(i);
        s.Show();
    }
    std::cout << "Peek:" << s.Peek() << std::endl;
    s.Pop();
    std::cout << "Peek:" << s.Peek() << std::endl;
    s.Show();
}
