#include <iostream>
#include <string>
#include <vector>

using namespace std;

class splitstring : public string {
    vector<string> flds;
public:
    splitstring(char *s) : string(s) { }
    vector<string>& split(char delim, int rep=0);
};

// split: receives a char delimiter; returns a vector of strings
// By default ignores repeated delimiters, unless argument rep == 1.
vector<string>& splitstring::split(char delim, int rep) {
    if (!flds.empty()) flds.clear();  // empty vector if necessary
    string work = data();
    string buf = "";
    int i = 0;
    while (i < work.length()) {
        if (work[i] != delim)
            buf += work[i];
        else if (rep == 1) {
            flds.push_back(buf);
            buf = "";
        } else if (buf.length() > 0) {
            flds.push_back(buf);
            buf = "";
        }
        i++;
    }
    if (!buf.empty())
        flds.push_back(buf);
    return flds;
}

int main(int ArgC, char *ArgV[])
{
    int argC = ArgC;
    char *ArgV1 = ArgV[2];
    char *argV2 = ArgV[3];
    cout << ArgV1<< endl;
    int count = 0;
    for (string line; std::getline(std::cin, line);) {
        // splits in the vector of strings
        const char* p = line.c_str();
        char* q = const_cast<char*>(p);
        splitstring str_line = q;
        vector<string> vec_line = str_line.split(' ');
        for (int k = 0; k < vec_line.size(); k++)
        {
            if(vec_line[k] == ArgV1)
                count++;
        }
    }
    std::cout << " Words count: " << count << std::endl;
    return 0;
    // Counter -t "text" < ../kiuti/FindMe.txt
}

