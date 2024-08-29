
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream poemFile("C:/Users/wheel/Desktop/poem/Template/poem.txt");

    int numLines = 0;
    string line;
    while (getline(poemFile, line)) {
        ++numLines;
    }

    poemFile.close();

    ifstream poemFile2("C:/Users/wheel/Desktop/poem/Template/poem.txt");

    string* poemLines = new string[numLines];

    for (int i = 0; i < numLines; ++i) {
        getline(poemFile2, poemLines[i]);
    }

    poemFile2.close();

    for (int i = 0; i < numLines; ++i) {
        cout << *(poemLines + i) << "\n";
    }


    return 0;
}