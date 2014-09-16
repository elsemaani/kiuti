#include <iostream>

using namespace std;

int main(int ArgC, char *ArgV[])
{
    int argC = ArgC;
    char *ArgV1 = ArgV[2];
    cout << ArgV1;
    cout << " - Hello World!" << endl;
    return 0;
}

