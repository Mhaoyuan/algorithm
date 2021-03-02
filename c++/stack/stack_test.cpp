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

    {
    algo::StackList<int> sl = algo::StackList<int>();
    for (int i = 0;i < 9; i++){
    sl.Push(i);
    //s.Show();
    }
    int item = sl.Pop();
    std::cout << "item pop:" << item << std::endl;
    int itempeek = sl.Peek();
    sl.Show();
    std::cout << "item peek:" << itempeek << std::endl;
    }


}
