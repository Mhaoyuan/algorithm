#include<iostream>

#include"mylist.h"


using namespace algo;

int main(){
    MyList<int> l;
    MyList<int> l3;
    MyList<int> l5;
    for(int i = 0; i < 10; i++){
        //std::cout<< "push" << std::endl;
        l.add_tail(i);
    }
    for(int i = 0; i < 50; i++){
        //std::cout<< "push" << std::endl;
        l3.add_tail(i);
    }
    l.Display();
    l3.Display();
    //MyList<int>l2 = l;
    //l2.Display();
    l = l3;
    l.Display();
    MyList<int> l4  = std::move(l3);
    l4.Display();
    l5 = l;
    l5.Display();


}

