#include"../list/mylist.h"
#include<string>
#include<memory>

using namespace algo;

int main(){
    MyList<std::string> l1;
    for(int i = 0; i < 2; i++){
        //std::cout<< "push" << std::endl;
        l1.add_tail(std::to_string(1));
        l1.add_tail(std::to_string(2));
    }
    l1.Display();
    //l1.remove("1");
    l1.remove("2");
    //l1.remove("2");
    l1.add_tail("3");
    l1.Display();
    
    
    
}