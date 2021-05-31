#include"../list/mylist.h"
#include<string>
#include<memory>

using namespace algo;

int main(){
    MyList<std::string> l1;
    for(int i = 0; i < 10; i++){
        //std::cout<< "push" << std::endl;
        l1.add_tail(std::to_string(i));
    }
    l1.Display();
    std::cout << l1.find("-2") << std::endl;
    Node<std::string> *node1 = new Node<std::string>();
    node1->Set("11");
    Node<std::string> *node2 = new Node<std::string>();
    node2->Set("12");
    l1.insertAfter(*node1, *node2);
    l1.Display();
    
    
    
}