#include <iostream>

using namespace std;

int main(int ArgC, char *ArgV[])
{
    int argC = ArgC;
    char *ArgV1 = ArgV[2];
    char *argV2 = ArgV[3];
    cout << ArgV1;
    int count = 0;
    for (string line; std::getline(std::cin, line);) {
            std::cout << line << std::endl;
            count++;
        }
    std::cout << " Words count: " << count << std::endl;
    return 0;
    // Counter -t "text" < ../kiuti/FindMe.txt
}

