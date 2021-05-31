#include"../list/mylist.h"

using namespace algo;

int main(){
    MyList<int> l1;
    for(int i = 0; i < 10; i++){
        //std::cout<< "push" << std::endl;
        l1.add_tail(i);
    }
    l1.Display();
    std::cout << l1.delete_k(1) << std::endl;


    MyList<int> l1;
    for(int i = 0; i < 10; i++){
        //std::cout<< "push" << std::endl;
        l1.add_tail(i);
    }
    l1.Display();
    std::cout << l1.delete_tail() << std::endl;
    l1.Display();


    MyList<int> l2;
    l2.add_tail(1);
    l2.Display();
    l2.delete_tail();
    l2.Display();

    MyList<int> l3;
    l3.delete_tail();


}