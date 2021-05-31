#include"../list/mylist.h"
#include<string>
#include<memory>

using namespace algo;

int main(){
    MyList<int> l1;
    for(int i = 0; i < 10; i++){
        //std::cout<< "push" << std::endl;
        l1.add_tail(i);
    }
    std::cout << l1.max() <<std::endl;
    
    
    
}