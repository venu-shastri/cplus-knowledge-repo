#include <string>
#include <vector>
#include <utility>
using namespace std;
class KeyPair{
    private:
    string key,value;
    public:
    KeyPair(string keyArg,string valueArg):key{keyArg},value{valueArg}
    string getValue(){ return this->value;}
    string getkey(){return this->key}
};
class Dictionary{
    private:
    vector<KeyPair> items;
    public:
    void add(string key,string value){
        KeyPair item(key,value);
        items.push_back(std::move(item));
    }
    void dumpDictionary(){
        for(int i=0;i<items.size();i++){
        std:cout<<this->items[i].getkey()<<"-"<<this->items[i].getValue()<<std::endl;
        }
    }
    string getValue(string key){
        //add your implementation here
        return "";
    }
}
int main(){
    Dictionary mapObj;
    mapObj.add("blr","Bangaluru");
    mapObj.add("chn","Chennai");
    mapObj.add("hyd","Hyderabad");
    mapObj.dumpdictionary();
    std::cout<<mapObj.getValue("blr")<<std:endl;
    

}
