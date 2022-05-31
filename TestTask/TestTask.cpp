#include <iostream>
#include "DictionaryImpl.h"
#include <map>

using namespace std;

int main()
{
    DictionaryImpl<const char*, int> dict;
    string key = "111";
    dict.set("111", 10);
    cout << dict.get("111");
    try {
        cout << dict.get("142") << endl;
    }
    catch (NotFoundException<const char*> e)
    {
        cout << e.get_key();
    }

    map<string, int> maq;
    maq["qvn"] = 8;
    auto it = maq.find("qww");
    if (it != maq.end())
        cout << it->second;
}