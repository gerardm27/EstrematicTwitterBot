#include "converter.h"

int main(int argc, char* argv[])
{
    
    vector<string> text;
    text.clear();
    char currLetter = 'A';
    string currWord;
    bool finished = false;
    while (not finished && cin >> currWord) {
        
        currLetter = currWord.back();
        if (currLetter == '.' || currLetter == '!' || currLetter == '?') {
            finished = true;
            currWord.pop_back();
        }
        string aux = converter::estrematize(currWord);
        
        text.push_back(aux);        
    }
        
    //Escribir por pantalla el texto que tenemos
    for (int i = 0; i < text.size(); ++i) {
        if (i == text.size() - 1) cout << text[i];
        else cout << text[i] << " ";
    }
    cout << endl << endl << endl << endl << endl << endl;
    return 0;
}
