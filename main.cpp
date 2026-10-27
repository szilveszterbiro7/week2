#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string letters="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
string morse[36]={".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..",
    "-----", ".----", "..---", "...--", "....-",
    ".....", "-....", "--...", "---..", "----."
    };
string textToMorse(string text) {
   string result="";
   for (int i=0; i<text.size(); i++){
        char c=toupper(text[i]);
        if (c==' ') {
            result+="/ ";
        }
        else {
            int pos=letters.find(c);
            if (pos !=-1)
            result += morse[pos] + " ";
        } 
    }
    return result;
    }
string morseToText(string m) {
    string result="";
    string code="";
    m+=' ';
    for (int i=0; i<m.size(); i++){
        if (m[i]!=' ') {
            code+=m[i];
        }
        else if (code !=""){
            if (code=="/"){
                result+=' ';
        }
        else{
            char found='?';
            for (int j=0; j<36; j++){
                if (code==morse[j]){
                    found=letters[j];
                }
            }
            result+=found;
        }
        code="";
        }
    }
        return result;
}
int main (){
    int choice, ft;
    string input;
    cout<<"==============DECODER/ENCODER=============="<<endl;
    cout<<"|"<<endl;
    cout<<"=====Choose your type of message====="<<endl;
    cout<<"| [1] Morse code"<<endl;
    cout<<"| [2] Binary/Hexadecimal"<<endl;
    cout<<"| Enter your choice: ";cin>>choice;cout<<endl;
    if (choice==1)
        {cout<<"===MORSE CODE DECODER/ENCODER===\n";
        cout<<"| Do you want to convert:\n";
        cout<<"| [1] From morse code to text\n";
        cout<<"| [2] From text to morse code\n";
        cout<<"| Enter your choice: ";cin>>ft;cout<<endl;
            cin.ignore();
            if (ft==1)
            {cout<<"| Enter the morse code (spaces between letters, / between words): ";
                getline(cin, input);
                cout<<"| In text: "<<morseToText(input)<<endl;
            }
            else if (ft==2)
            {cout<<"Enter the text: ";
                getline (cin, input);
                cout<<"| In morse code: "<<textToMorse(input)<<endl;
            }
        }
    else if (choice==2)
        cout<<"Not made yet"<<endl;
    return 0;
}