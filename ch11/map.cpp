#include <map>
#include <set>
#include <string>
#include <iostream>

using namespace std;

//map
void map_func()
{
    string strIn;
    map<string, size_t> word_count;
    while(cin>>strIn){
        word_count[strIn]++;
    }

    for (const auto &w : word_count)
    {
        cout << w.first << ": " << w.second << endl;
    }  
}

//set
void set_func()
{
    string strIn;
    map<string, size_t> word_count;
    set<string> exclude = {"1"};

    while(cin>>strIn){
        if(exclude.find(strIn) == exclude.end())
            word_count[strIn]++;
    }

    for (const auto &w : word_count)
    {
        cout << w.first << ": " << w.second << endl;
    }  

}

int main(int argc, char* argv[])
{
    //map_func();
    set_func();
    // getchar();

    return 0;
}