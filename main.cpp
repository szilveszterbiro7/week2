#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;
string morseDecode (const string&morse) {
    static const unordered_map<string, char>table= {
        {".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'},  {".", 'E'}, {"..-.", 'F'}, {"--.", 'G'}, {"....", 'H'}, {"..", 'I'}, {".---", 'J'}, {"-.-", 'K'},  {".-..", 'L'}, {"--", 'M'},   {"-.", 'N'},   {"---", 'O'}, {".--.", 'P'}, {"--.-", 'Q'}, {".-.", 'R'},  {"...", 'S'},  {"-", 'T'}, {"..-", 'U'},  {"...-", 'V'}, {".--", 'W'},  {"-..-", 'X'}, {"-.--", 'Y'}, {"--..", 'Z'} 
    };
    string result;
    istringstream stream(morse);
    string token;
    while (stream>>token){
        if (token=="/"){
            result += " ";
        }
    else{
        auto it=table.find(token);
        result += (it !=table.end()) ? it->second : '?';
        }
    }
    return result;
}

int main (){
    int choice, ft;
    string input;
    cout<<"==============DECODER=============="<<endl;
    cout<<"|"<<endl;
    cout<<"====Choose your type of message===="<<endl;
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
                cout<<"| In text: "<<morseDecode(input)<<endl;
            }
        }
    else if (choice==2)
        cout<<"sigma"<<endl;
    return 0;
}