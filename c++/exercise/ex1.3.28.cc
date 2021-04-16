#include"../list/mylist.h"
#include<string>
#include<memory>

using namespace algo;

int main(){
    MyList<int> l1;
    for(int i = 0; i < 100000; i++){
        //std::cout<< "push" << std::endl;
        l1.add_tail(i);
    }
    std::cout << l1.recursion_max() <<std::endl;
    
    
    
}