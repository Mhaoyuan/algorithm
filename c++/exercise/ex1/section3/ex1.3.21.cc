#include"../list/mylist.h"
#include<string>

using namespace algo;

int main(){
    MyList<std::string> l1;
    for(int i = 0; i < 10; i++){
        //std::cout<< "push" << std::endl;
        l1.add_tail(std::to_string(i));
    }
    l1.Display();
    std::cout << l1.find("-2") << std::endl;
}