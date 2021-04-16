#include"../list/mylist.h"

using namespace algo;

int main(){
    MyList<int> l1;
    for(int i = 0; i < 10; i++){
        //std::cout<< "push" << std::endl;
        l1.add_tail(i);
    }
    l1.Display();
    //std::cout << l1.delete_front() << std::endl;
    //std::cout << l1.delete_front() << std::endl;
    std::cout << l1.Size() << std::endl;
    std::cout << l1.delete_k(10) << std::endl;
    std::cout << l1.delete_k(9) << std::endl;
    std::cout << l1.delete_k(1) << std::endl;
    std::cout << l1.delete_k(2) << std::endl;
    std::cout << l1.delete_k(4) << std::endl;
    l1.Display();
    //std::cout << l1.delete_k(1) << std::endl;


}