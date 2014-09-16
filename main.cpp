#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>

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

int countWords(const char* line, const char *word, bool isCase){
    std::locale loc;
    int count = 0;
    char *ptrLine = (char*)line;

    // Read line chars and compare them with the target text
    int wLength = (int) strlen(word);
    // The function strstr looks for any matches of the ArgV1 and returns the
    // text starting from matching string.
    char *ptrText = ptrLine;// strstr(ptrLine, word);
    if (ptrText) {
        int tLength = (int) strlen(ptrText);
        for(int i = 0; i < tLength; i++){
            // Evaluates if chars match with target text
            bool match = true;
            for(int j = 0; j < wLength; j++){
                // Check if comparison is made with case sensitive.
                if (isCase) {
                    if (ptrText[i] != word[j]){
                        match = false;
                        break;
                    }
                } else {
                    if (std::tolower(ptrText[i], loc) != std::tolower(word[j], loc)){
                        match = false;
                        break;
                    }
                }
                i++;
            }
            if (match){
                cout << ptrText[i];
                count++;
            }
        }
    }
    return count;
}

int countTargets(const char *line, const char *target)
{
    int count = 0;
    char *lin= (char*)line;
    int tsize = strlen(target);
    char *p = NULL;
    while (p = strstr(lin, target))
    {
        lin = p + tsize;
        count++;
    }
    return count;
}

int main(int argc, char *argv[])
{
    char *argV1 = argv[2];
    char *argV2 = argv[3];

    cout << "Word to search: "<< argV1 << endl;
    vector<string> vec_lines;
    // Count search 1, is not 100% efficient.
    int count = 0;
    for (string line; std::getline(std::cin, line);) {
        vec_lines.push_back(line);

        // splits in the vector of strings
        const char* p = line.c_str();
        char* q = const_cast<char*>(p);
        splitstring str_line = q;
        vector<string> vec_line = str_line.split(' ');
        for (int k = 0; k < vec_line.size(); k++){

            if(vec_line[k] == argV1)
                count++;
        }
    }
    std::cout << "(1) Words count: " << count << std::endl;

    // Count search 1
    count = 0;
    //vec_lines.push_back("This a NULL null word WORD of NULL that live in NULL-NUL!!");

    char *caseArg = "-c";
    bool isCase = true;
    if (argV2 && *argV2 == *caseArg) {
        isCase = false;
    }
    for (int i = 0; i < vec_lines.size(); i++) {
        //cout << "(2) Line text: "<< vec_lines[i] << std::endl;
        count += countWords(vec_lines[i].c_str(), argV1, isCase);
    }


    std::cout << "(2) Words count: " << count << std::endl;


    return 0;
    // Counter -t "text" < ../kiuti/FindMe.txt
}

