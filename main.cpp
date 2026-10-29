#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <limits>
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
string cCipher (string txt, int sft){
    string result="";
    for (int i=0; i<txt.length(); i++) {
        char c=toupper(txt[i]);
        if (c>='A' && c<='Z'){
        c=(c-'A'+sft+26)%26+'A';
        }
        result+=c;
    }
    return result;
}
string aCipher (string txt){
    string result="";
    for (int i=0; i<txt.length(); i++){
        char c=toupper(txt[i]);
        if(c>='A' && c<='Z'){
            c='Z'-(c-'A');
        }
        result+=c;
    }
    return result;
}
string txtToAscii (string txt){
    string result="";
    for(int i=0; i<txt.length(); i++){
    result+=to_string((int)(unsigned char)txt[i]);
    if(i<txt.length()-1){
        result+=" ";
        }
    }
    return result;
}
string asciiToTxt (string code){
    istringstream inp (code);
    string result="";
    int cd;
    while (inp>>cd){
        if(cd<0 || cd>127)
            return"| ASCII values must be between 0-127!";
        result += (char)cd;
    }
        if(!inp.eof())
            return"| The numbers must be separated with spaces";
        if(result.empty())
        return" |Enter at least 1 ASCII number"; 
    return result;
}

int main (){
    int choice, ft, decimal=0, value, rem, sft;
    char digit;
    bool valid=true;
    string inp, binary="", hex="";
    while (true){
    cout<<"=========================================="<<endl;
    cout<<"| * * * * * * * * SIGNAL * * * * * * * * |"<<endl;
    cout<<"|           DECODING & ENCODING          |"<<endl;
    cout<<"|                 BUREAU                 |"<<endl;
    cout<<"|----------------Est. 1924---------------|"<<endl;
    cout<<"=========================================="<<endl;
    cout<<"|"<<endl;
    cout<<"=========Choose a type of message========="<<endl;
    cout<<"| [1] MORSE CODE"<<endl;
    cout<<"| [2] NUMBER SYSTEMS"<<endl;
    cout<<"| [3] CLASSICAL CIPHERS"<<endl;
    cout<<"| [4] ASCII"<<endl;
    cout<<"| [0] EXIT"<<endl;
    cout<<"| Enter your choice: ";cin>>choice;cout<<endl;
    while (choice<0 || choice>4){
        cout<<"Invalid option!\n";
        cin>>choice;
    }
    if (choice==1){
        while (true){
        cout<<"===========================\n";
        cout<<"          MORSE CODE\n";
        cout<<"===========================\n";
        cout<<"|\n";
        cout<<"| Do you want to convert:\n";
        cout<<"| [1] From morse code to text\n";
        cout<<"| [2] From text to morse code\n";
        cout<<"| [0] Back to main menu\n";
        cout<<"| Enter your choice: ";cin>>ft;cout<<endl;
        cin.ignore(1000, '\n');
            if (ft==0)
                break;
            if (ft<1 || ft>2) {
                cout << "Invalid option!\n";
                continue;
                    }
            if (ft==1)
            {cout<<"| Enter the morse code (spaces between letters, / between words): ";
                getline(cin, inp);
                cout<<"| In text: "<<morseToText(inp)<<endl;
            }
            else if (ft==2)
            {cout<<"Enter the text: ";
                getline (cin, inp);
                cout<<"| In morse code: "<<textToMorse(inp)<<endl;
            }
        }
    }
    else if (choice==2){
        while (true){
        cout<<"===========================\n";
        cout<<"       NUMBER SYSTEMS"<<endl;
        cout<<"===========================\n";
        cout<<"|\n";
        cout<<"| Do you want to convert:\n";
        cout<<"| [1] From decimal to hexadecimal\n";
        cout<<"| [2] From hexadecimal to decimal\n";
        cout<<"| [3] From decimal to binary\n";
        cout<<"| [4] From binary to decimal\n";
        cout<<"| [0] Back to main menu\n";
        cout<<"| Enter your choice: ";cin>>ft;cout<<endl;
        cin.ignore(1000, '\n');
        if (ft==0)
            break;
        if (ft<1 || ft>4) {
            cout << "Invalid option!\n";
            continue;
                }
        if (ft==1){
            string digits="0123456789ABCDEF";
            hex="";
            cout<<"| Enter the number: ";cin>>decimal;cout<<endl;
            while (decimal<0){
                cout<<"| Enter a positive number!\n";
                cin>>decimal;
            }
            if (decimal==0)
                hex="0";
            else{
                while (decimal>0){
                    rem=decimal%16;
                    hex=digits[rem]+hex;
                    decimal/=16;
                }
            }
            cout<<"| Hexadecimal: "<<hex<<endl;
        }
    
        else if (ft==2) {
            decimal=0;
            valid=true;
            cout<<"| Enter the hexadecimal number: ";cin>>hex;cout<<endl;
            for(int i=0; i<hex.length(); i++){
                digit=hex[i];
                if (digit>='0' && digit<='9')
                value=digit-'0';
                else if (digit>='A' && digit<='F')
                value=digit-'A'+10;
                else if (digit>='a' && digit<='f')
                value=digit-'a'+10;
                else{
                    valid=false;
                    break;
                }
                decimal=decimal*16+value;
            }
        if (valid)
            cout<<"| Decimal: "<<decimal<<endl;
        else 
            cout<<"| Invalid hexadecimal number!\n";
        }
        else if (ft==3) {
            cout<<"| Enter the number: ";cin>>decimal;cout<<endl;
            binary="";
            while (decimal<0){
                cout<<"| Enter a positive number!\n";
                cin>>decimal;
            }
            if (decimal==0)
                binary="0";
            else {
                while (decimal>0){
                    binary=char('0'+decimal%2)+binary;
                    decimal/=2;
                }
            }
            cout<<"| Binary: "<<binary<<endl;
        }
        else if (ft==4) {
            decimal=0;
            valid=true;
            cout<<"| Enter the binary number: ";cin>>binary;cout<<endl;
            for (int i=0; i<binary.length(); i++){
                if (binary[i] != '0' && binary[i] != '1') {
                    valid=false;
                    break;
                }
            decimal=decimal*2+(binary[i]-'0');
        }
        if (valid)
            cout<<"| Decimal: "<<decimal<<endl;
        else 
            cout<<"| Invalid binary number!\n";
                }
            }
        }
        else if (choice==3){
            while (true){
            cout<<"==========================="<<endl;
            cout<<"      CLASSICAL CIPHERS"<<endl;
            cout<<"==========================="<<endl;
            cout<<"|\n";
            cout<<"| Choose an option:\n";
            cout<<"| [1] Caesar Cipher decode\n";
            cout<<"| [2] Caesar Cipher encode\n";
            cout<<"| [3] Atbash Cipher\n";
            cout<<"| [4] Instructions/What are Classical Ciphers?\n";
            cout<<"| [0] Back to main menu\n";
            cout<<"| Enter your choice: ";cin>>ft;cout<<endl;
            cin.ignore(1000, '\n');
            if (ft==0)
            break;
            if (ft<1 || ft>4) {
                cout << "Invalid option!\n";
                continue;
                    }
            if (ft==1){
                cout<<"| Enter your message: ";
                getline(cin, inp);cout<<endl;
                cout<<"| Enter the shift (0-25): ";cin>>sft;cout<<endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                while (sft<0 || sft>25){
                    cout<<"| Invalid shift!\n";
                    cin>>sft;
                }
                sft=-sft;
                sft=((sft%26)+26)%26;
                cout<<"Decoded message: "<<cCipher(inp, sft)<<endl;
            }
            else if (ft==2){
                cout<<"| Enter your message: ";
                getline(cin, inp);cout<<endl;
                cout<<"| Enter the shift (0-25): ";cin>>sft;cout<<endl;
                while (sft<0 || sft>25) {
                    cout << "Invalid option!\n";
                    cin>>sft;
                }
                cin.ignore(1000, '\n');
                sft=((sft%26)+26)%26;
                cout<<"| Encoded message: "<<cCipher(inp, sft)<<endl;
            }
            else if (ft==3){
                cout<<"| Enter your message: ";
                getline(cin, inp);cout<<endl;
                cout<<"Encoded/Decoded message: "<<aCipher(inp)<<endl;
            }
            else if (ft==4){
                cout<<"=====MANUAL=====\n";
                cout<<"| WHAT IS A CIPHER?\n| A cipher changes a message into a coded form.\n| It can be used to hide a message from casual readers\n.";
                cout<<endl;
                cout<<"| 1.CAESAR CIPHER\n| Each letter is shifted through the alphabet.\n| Example: HELLO with a shift of 3 becomes KHOOR.\n| You can choose the value of the shift.\n";
                cout<<endl;
                cout<<"| 2.ATBASH CIPHER\n| The alphabet is reversed: A becomes Z, B becomes Y.\n| Example: HELLO becomes SVOOL.\n";
            }
            cout << "\n| Press Enter to return to the menu";
        cin.get();
        }
    }
        else if(choice==4){
            while (true){
            cout<<"=========================\n";
            cout<<"         ASCII\n";
            cout<<"=========================\n";
            cout<<"|\n";
            cout<<"| Choose an option: \n";
            cout<<"| [1] Text to ASCII\n";
            cout<<"| [2] ASCII to text\n";
            cout<<"| [0] Back to main menu\n";
            cout<<"| Enter your choice: ";cin>>ft;cout<<endl;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            if (ft==0)
            break;
            if (ft<0 || ft>2){
                cout<<"Invalid option!\n";
                continue;
                }
            if (ft==1){
                cout<<"| Enter your message: ";
                getline(cin, inp);cout<<endl;
                cout<<"| Encoded message: "<<txtToAscii(inp)<<endl;
                cout<<"| Press enter to continue ";
                    cin.get();
            }
            else if (ft==2){
                cout<<"| Enter the ASCII numbers: ";
                getline(cin, inp);cout<<endl;
                cout<<" Decoded message: "<<asciiToTxt(inp)<<endl;
                cout<<"| Press enter to continue ";
                    cin.get();
            }
        }
    }
        else if (choice==0){
            cout<<"| Transmission ended. Goodbye!";
        return 0;
        }
}
    return 0;
}