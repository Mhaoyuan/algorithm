#include <algorithm>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace fs = filesystem;

class Tree{
public:
    Tree(std::string path):path(path){}
    void List(){
      listfile(path,"");
      for(auto it = filevec.cbegin(); it != filevec.cend(); it++){
        std::cout << *it << std::endl;
      }
    }
private:
    std::vector<std::string> filevec;
    std::string path;
    void listfile(std::string path, std::string prefix){
      std::vector<fs::directory_entry> entries;
      for(auto const &entry : fs::directory_iterator(path)){
        entries.push_back(entry);
      }
      if(entries.size() == 0){
        return;
      }
      for(auto const &entry : entries){
        if(!entry.is_directory()){
          filevec.push_back(prefix + entry.path().filename().string());
        }else{
          
          filevec.push_back(prefix + entry.path().filename().string());
          listfile(entry.path().string(), prefix + " ");
          
        }
      }
    }
};

int main(int argc, char *argv[]) {
    /*
  Tree tree(".");
  string directory = argc == 1 ? "." : argv[1];

  cout << directory << endl;
  tree.walk(directory, "");
  tree.summary();
*/
  Tree t("/Users/mahaoyuan/Workpace/algorithm/c++/exercise/filetest");
  t.List();
  return 0;
}