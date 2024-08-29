#include "std_lib_facilities.h"

int main()
{
    int sum = 0;
    int a;
    bool validInputFound = false;
    ifstream inFile;
    inFile.open("c:/Users/wheel/Desktop/findHiddenNumbers.txt");
    if(inFile.fail()){
        cout<< "The path for the txt file is not correct!" << endl;
    }

    while(true){
        inFile >> a;
        if(inFile.eof()){
            //cout << "EOF";
            break;
        }else if(inFile.fail()){
            inFile.clear();
            inFile.ignore(1, '\n');
        }else{
            validInputFound = true;

            sum = sum + a;


        }

    }
    cout << sum << endl;


    return 0;
}
