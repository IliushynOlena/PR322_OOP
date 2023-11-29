#include <iostream>
#include <map>
#include <list>
#include <string>
#include <fstream>
using namespace std;

/*
 string - list<string>
 "run" - "bigtu","zapustutu","keruvatu"


*/
class Dictionary
{
private:
    string name;
    map<string, list<string>> words;//default c-tor Root= nullptr
public:
    Dictionary(string name): name(name) {}
    void Print()const
    {
        cout << "Dictionary " << name << endl;
        for (auto pair : words)
        {
            cout << pair.first << " - ";
            for (string t  : pair.second)
            {
                cout << t << " , ";
            }
            cout << endl;            
        }
    }
    void InsertWord(string word, initializer_list<string> translate)
    {
        words.insert(make_pair(word, list<string>(translate)));
    }
    void AddTranslation(string word, string translate)
    {
        words[word].push_back(translate);
    }
    bool IsExist(string word)
    {
        return words.find(word) != words.end();
    }
    friend ostream& operator << (ostream& out, const Dictionary& d);
    friend istream& operator >> (istream& in, Dictionary& d);
};
ostream& operator << (ostream& out, const Dictionary& d)
{
    out << d.name << endl;
    for (auto pair : d.words)
    {
        out << pair.first << endl;
        for (string t : pair.second)
        {
            out << t << endl;
        }
        out <<"|" << endl;
    }
    return out;
}
istream& operator >> (istream& in, Dictionary& d)
{
    string end = "|";
    //in >> d.name;
    getline(in, d.name);
    while (!in.eof())
    {
        string word;
        getline(in, word);
        if (word.empty())break;
        list<string> list;
        string translate = end;

        do
        {
            getline(in, translate);
            if(translate != end)
                list.push_back(translate);

        } while (translate != end);
        d.words.insert(make_pair(word, list));
    }
 
    return in;
}

int main()
{
    //Dictionary dict("English-Ukrainian");
    //dict.InsertWord("run", { "bigtu","zapustutu","keruvatu" });
    //dict.InsertWord("make",  {"robutu","vurib","forma"} );
    //dict.InsertWord("mind", { "dumka","rozum","gluzd" });
    //dict.InsertWord("bad", { "podano","amoralnuy","zipsovanuy","brudkuy" });

    //dict.Print();

    //string input = "";
    //cout << "Enter word to add translate : ";
    //getline(cin, input);
    //// cin.ignore();

    //if (!dict.IsExist(input))
    //    cout << "Word not found!" << endl;
    //else
    //{
    //    string translate = "";
    //    do
    //    {
    //        cout << "Enter translate : ";
    //        getline(cin, translate);
    //        if(!translate.empty())
    //            dict.AddTranslation(input, translate);

    //    } while (!translate.empty());
    //}
    //dict.Print();

    //ofstream out("Dictionary.txt");
    //out << dict;
    //out.close();
    Dictionary read("");
    ifstream in("Dictionary.txt");
    in >> read;
    in.close();

    read.Print();

    /*
    map<string, list<string>> dic;

    string word = "run";
    list<string> meanings = list<string>({ "bigtu","zapustutu","keruvatu" });
    dic.insert(make_pair(word, meanings));
    dic.insert(make_pair("make", list<string>({"robutu","vurib","forma"})));
    dic.insert(make_pair("mind", list<string>({"dumka","rozum","gluzd"})));
    dic.insert(make_pair("ride", list<string>({"yizdutu","katania","oblava"})));
    dic.insert(make_pair("bad", list<string>({"podano","amoralnuy","zipsovanuy","brudkuy"})));

   
    for (string str : dic["mind"])
    {
        cout << str << " ";
    }
    cout << endl;


    string input = "";
    cout << "Enter word to add translate : "; 
    getline(cin, input); 
   // cin.ignore();

    if (dic.find(input) == dic.end())
        cout << "Word not found!" << endl;
    else
    {
        string translate = "";
        do
        {
            cout << "Enter translate : ";
            getline(cin, translate);

            dic[input].push_back(translate);

        } while (!translate.empty());
    }

    for (string str : dic[input])
    {
        cout << str << " ";
    }
    cout << endl;
    */

    
}

