#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <limits>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
/// Morse
string letters="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
string morse[36]={".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..",
    "-----", ".----", "..---", "...--", "....-",
    ".....", "-....", "--...", "---..", "----."
    };
/// Nato
string nato[26]={
    "Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India", "Juliett", "Kilo",
    "Lima", "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tango", "Uniform", "Victor",
    "Whiskey", "X-ray", "Yankee", "Zulu"
    };
    // Text-Morse
string textToMorse(string text) {
   string result="";
   for (int i=0; i<text.size(); i++){
        char c=toupper(text[i]);
        if (c==' ') {
            result+="/ ";
        }
        else {
            size_t pos=letters.find(c);
            if (pos !=string::npos)
            result += morse[pos] + " ";
        } 
    }
    return result;
    }
    //Morse-text
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
//Caesar Cipher
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
// Atbash Cipher
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
// Text-ASCII
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
//ASCII- text
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
        return"| Enter at least 1 ASCII number"; 
    return result;
}
// A1Z26 encode
string letterToNumber(string txt){
    string code="";
    bool first=true;
    for (int i=0; i<txt.length(); i++){
        char c=toupper(txt[i]);
    if (c>= 'A' && c<='Z'){
        if (!first)
            code+=" ";
        code+=to_string(c-'A'+1);
        first=false;
    }
    else if (c==' ' && !first){
        code+=" / ";
        first=true;
        }
    }
    return code;
}
// A1Z26 decode
string numberToLetter(string code){
    string txt="";
    string token;
    stringstream ss(code);
    while (ss>>token){
        if(token=="/")
        txt+=" ";
        else{
            stringstream nStr(token);
            int num;
            char xtr;
            if(!(nStr>>num) || (nStr>>xtr) || num<1 || num>26)
                return "| Invalid code!";
            txt+=char('A'+num-1);
        }
    }
    if (txt.empty())
        return "| Enter at least one number!";
    return txt;
}
// NATO encode
string txtToNato(string txt){
    string result="";
    for(int i=0; i<txt.length(); i++){
        char c=toupper(txt[i]);
        if (c>='A' && c<='Z')
            result+=nato[c-'A']+" ";
        else if (c==' ')
        result+="/ ";
    }
    return result;
}
// NATO decode
string natoToTxt(string code){
    string result="";
    string wd="";
    stringstream ss(code);
    while (ss>>wd){
        if (wd=="/"){
        result+=" ";
        continue;
        }
        for(int i=0; i<wd.length(); i++)
            wd[i]=toupper(wd[i]);
        for (int i=0; i<26; i++){
            string natowd=nato[i];
        for (int a=0; a<natowd.length(); a++){
            natowd[a]=toupper(natowd[a]);
        }
        if (wd==natowd){
            result+=char('A'+i);
            break;
            }
        }
    }
    return result;
}
// Vigenere Cipher
string vig(string txt, string k, bool decd){
    string result="";
    int index=0;
    for (int i=0; i<txt.length(); i++){
        char c= toupper(txt[i]);
        if(c>='A' && c<='Z'){
            int l=c-'A';
            int sft=toupper(k[index%k.length()])-'A';
        
        if (decd)
            sft=-sft;
        char conv=(l+sft+26)%26+'A';
        result+=conv;
        index++;
        }
        else
            result+=c;
    }
    return result;
}
// Message history
template <typename T>
bool rd (T &out){
    bool ok=static_cast<bool>(cin>>out);
    if (!ok) cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return ok;
}
struct hist{
    string type;
    string og;
    string result;
};
vector <hist> history;
void addHist(string type, string og, string result){
    hist entry;
    entry.type=type;
    entry.og=og;
    entry.result=result;
    history.push_back(entry);
}
void shwHist (){
    cout<<"===== MESSAGE HISTORY =====\n";
    if (history.empty()){
        cout<<"| No conversions yet.\n";
        return;
    }
    for (int i=0; i<history.size(); i++){
        cout<<"\n["<<i+1<<"] "<<history[i].type<<endl;
        cout<<"Original: "<<history[i].og<<endl;
        cout<<"Result: "<<history[i].result<<endl;
        cout<<"---------------------------------"<<endl;
    }
}
void clrHist(){
    history.clear();
    cout<<"History cleared successfully!\n";
}
//Decoder challenge
void chal(){
    string words [5]={
        "SECRET", "SIGNAL", "AGENT", "MISSION", "DECODE"
    };
    int score;
    int choice, op;
    string ansr;
    string encoded;
    string og;
    cout<<"| Decode 5 messages!\n\n";
    do{
    score=0;
    for (int i=0; i<5; i++){
        og=words[rand()%5];
        choice=rand()%3;
        if (choice==0){
            cout<<"| Cipher: Caesar\n";
            encoded=cCipher(og, 3);
        }
        else if (choice==1){
            cout<<"| Cipher: Atbash\n";
            encoded=aCipher(og);
        }
        else{
            cout<<"| A1Z26\n";
            encoded=letterToNumber(og);
        }
        cout<<"| Message: "<<encoded<<endl;
        cout<<"| Your Answer: ";cin>>ansr;
        for (int a=0; a<ansr.length(); a++){
            ansr[a]=toupper(ansr[a]);
        }
        if (ansr==og){
            cout<<"| Correct! +1 point\n";
            score++;
        }
        else{
            cout<<"| Wrong answer!\n";
            cout<<"| The answer was: "<<og<<endl;
        }
        cout<<"| Score: "<<score<<"/"<<i+1<<"\n\n";
    }
    cout<<"=====CHALLENGE COMPLETE=====\n";
    cout<<"| Final score: "<<score<<"/5"<<endl;
    if (score==5){
        cout<<"| Rank:\n";
        cout<<"===MASTER===\n";
    }
    else if (score>=3){
        cout<<"| Rank:\n";
        cout<<"===AGENT===\n";
    }
    else{
        cout<<"| Rank:\n";
        cout<<"===TRAINEE===\n";
    }
    cout<<"\n| [1] Play again\n";
    cout<<"| [0] Return to main menu\n";
    cout<<"| Your choice: ";
    if (!rd(op)){
        op=-1;
    }
    }while (op==1);
}
int main (){
    srand(time(0));
    int choice, ft, value, rem, sft;
    long long decimal=0, dec;
    char digit;
    bool valid=true;
    string inp, binary="", hex="", txt, code, k, result;
    ///Main menu
    while (true){
    cout<<"| | | | | | | | | * * * * * * * * * * | | | | | | | | |"<<endl;
    cout<<"======================================================="<<endl;
    cout<<"| * * * * * * * * * * S I G N A L * * * * * * * * * * |"<<endl;
    cout<<"|                 DECODING & ENCODING                 |"<<endl;
    cout<<"|                       BUREAU                        |"<<endl;
    cout<<"|----------------------Est. 1924----------------------|"<<endl;
    cout<<"======================================================="<<endl;
    cout<<"| | | | | | | | | * * * * * * * * * * | | | | | | | | |"<<endl;
    cout<<"|"<<endl;
    cout<<"=============== Choose a type of message =============="<<endl;
    cout<<"| [1] MORSE CODE"<<endl;
    cout<<"| [2] NUMBER SYSTEMS"<<endl;
    cout<<"| [3] CLASSICAL CIPHERS"<<endl;
    cout<<"| [4] ASCII"<<endl;
    cout<<"| [5] A1Z26 (NUMBER TO LETTER)"<<endl;
    cout<<"| [6] NATO PHONETIC ALPHABET"<<endl;
    cout<<"| [7] MESSAGE HISTORY"<<endl;
    cout<<"| [8] CHALLENGE MODE"<<endl;
    cout<<"| [0] EXIT"<<endl;
    cout<<"| Enter your choice: ";
    if (!(cin>>choice)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"\n| Invalid input!\n";
        continue;
    }
    if (choice<0 || choice>8){
        cout<<"\n| Invalid option!\n";
        continue;
    }
    // Morse menu
    if (choice==1){
        while (true){
        cout<<"==============================\n";
        cout<<"|---------MORSE CODE---------|\n";
        cout<<"==============================\n";
        cout<<"|\n";
        cout<<"----- Do you want to convert: ------\n";
        cout<<"| [1] From morse code to text\n";
        cout<<"| [2] From text to morse code\n";
        cout<<"| [0] Back to main menu\n";
        cout<<"| Enter your choice: ";
        if (!rd(ft)){
            cout<<"\n| Invalid input!\n";
            continue;
        }
            if (ft==0)
                break;
            if (ft<1 || ft>2) {
                cout << "\n| Invalid option!\n";
                continue;
                    }
             ///Morse code decode
            if (ft==1)
            {cout<<"===== MORSE TO TEXT =====\n";
                cout<<"| Enter the morse code (spaces between letters, / between words): ";
                getline(cin, inp);
                result=morseToText(inp);
                cout<<"| In text: "<<result<<endl;
                addHist ("Morse code-Decode", inp, result);
            }
            // Morse code encode
            else if (ft==2)
            {cout<<"===== TEXT TO MORSE =====\n";
                cout<<"| Enter the text: ";
                getline (cin, inp);
                result=textToMorse(inp);
                cout<<"| In morse code: "<<result<<endl;
                addHist ("Morse code-Encode", inp, result);
            }
        }
    }
    // Number systems menu
    else if (choice==2){
        while (true){
        cout<<"============================\n";
        cout<<"|------NUMBER SYSTEMS------|\n";
        cout<<"============================\n";
        cout<<"|\n";
        cout<<"----- Do you want to convert: -----\n";
        cout<<"| [1] From decimal to hexadecimal\n";
        cout<<"| [2] From hexadecimal to decimal\n";
        cout<<"| [3] From decimal to binary\n";
        cout<<"| [4] From binary to decimal\n";
        cout<<"| [0] Back to main menu\n";
        cout<<"| Enter your choice: ";
        if (!rd(ft)){
            cout<<"\n| Invalid input!\n";
            continue;
        }
        if (ft==0)
            break;
        if (ft<1 || ft>4) {
            cout << "\n| Invalid option!\n";
            continue;
                }
        ///Hexadecimal encode
        if (ft==1){
            string digits="0123456789ABCDEF";
            hex="";
            cout<<"| Enter the number: ";
            if (!rd(decimal)) {
                cout<<"| Invalid number!\n";
                continue;
                }cout<<endl;
            while (decimal<0){
                cout<<"| Enter a positive number!\n";
                if (!rd(decimal)) {
                cout<<"| Invalid number!\n";
                continue;
                }
            }
            dec=decimal;
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
            addHist ("Hexadecimal-Encode", to_string(dec), hex);
        }
        //Hexadecimal decode
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
        if (valid){
            cout<<"| Decimal: "<<decimal<<endl;
            addHist ("Hexadecimal-Decode", hex, to_string(decimal));
        }
        else 
            cout<<"| Invalid hexadecimal number!\n";
        }
        // Binary encode
        else if (ft==3) {
            cout<<"| Enter the number: ";
            if (!rd(decimal)) {
                cout<<"| Invalid number!\n";
                continue;
                }
            cout<<endl;
            binary="";
            while (decimal<0){
                cout<<"| Enter a positive number!\n";
                if (!rd(decimal)) {
                cout<<"| Invalid number!\n";
                continue;
                }
            }
            dec=decimal;
            if (decimal==0)
                binary="0";
            else {
                while (decimal>0){
                    binary=char('0'+decimal%2)+binary;
                    decimal/=2;
                }
            }
            cout<<"| Binary: "<<binary<<endl;
            addHist ("Binary-Encode", to_string(dec), binary);
        }
        // Binary decode
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
        if (valid){
            cout<<"| Decimal: "<<decimal<<endl;
            addHist ("Binary-Decode", binary, to_string(decimal));
        }
        else
            cout<<"| Invalid binary number!\n";
                }
            }
        }
        // Ciphers menu
        else if (choice==3){
            while (true){
            cout<<"============================="<<endl;
            cout<<"|-----CLASSICAL CIPHERS-----|"<<endl;
            cout<<"============================="<<endl;
            cout<<"|\n";
            cout<<"----- Choose an option: -----\n";
            cout<<"| [1] Caesar Cipher decode\n";
            cout<<"| [2] Caesar Cipher encode\n";
            cout<<"| [3] Atbash Cipher\n";
            cout<<"| [4] Vigenere Cipher encode\n";
            cout<<"| [5] Vigenere Cipher decode\n";
            cout<<"| [6] Instructions/What are Classical Ciphers?\n";
            cout<<"| [0] Back to main menu\n";
            cout<<"| Enter your choice: ";
            if (!rd(ft)){
                cout<<"\n| Invalid input!\n";
                continue;
            }
            if (ft==0)
            break;
            if (ft<1 || ft>6) {
                cout << "| Invalid option!\n";
                continue;
                    }
            // Caesar cipher decode
            if (ft==1){
                cout<<"=====CAESAR CIPHER=====\n";
                cout<<"| Enter your message: ";
                getline(cin, inp);cout<<endl;
                cout<<"| Enter the shift (0-25): ";
                while (!rd(sft) || sft<0 || sft>25)
                    cout<<"| Invalid shift! Try again: "<<endl;
                sft=-sft;
                sft=((sft%26)+26)%26;
                result=cCipher(inp, sft);
                cout<<"Decoded message: "<<result<<endl;
                addHist ("Caesar Cipher-Decode", inp, result);
            }
            // Caesar Cipher encode
            else if (ft==2){
                cout<<"=====CAESAR CIPHER=====\n";
                cout<<"| Enter your message: ";
                getline(cin, inp);cout<<endl;
                cout<<"| Enter the shift (0-25): ";
                while (!rd(sft) || sft<0 || sft>25)
                    cout<<"| Invalid shift! Try again: "<<endl;
                sft=((sft%26)+26)%26;
                result=cCipher(inp, sft);
                cout<<"| Encoded message: "<<result<<endl;
                addHist ("Caesar Cipher-Encode", inp, result);
            }
            // Atbash Cipher encode/decode
            else if (ft==3){
                cout<<"=====ATBASH CIPHER=====\n";
                cout<<"| Enter your message: ";
                getline(cin, inp);cout<<endl;
                result=aCipher(inp);
                cout<<"| Encoded/Decoded message: "<<result<<endl;
                addHist ("Atbash Cipher-Encode/Decode", inp, result);
            }
            //Vigenere cipher
            else if (ft==4 || ft==5){
                cout<<"=====VIGENERE CIPHER=====\n";
                cout<<"| Enter your text: ";
                getline(cin, inp);cout<<endl;
                cout<<"| Enter the keyword: ";
                getline(cin, k);cout<<endl;
                bool val=true;
                for(char c:k){
                    if (!isalpha(c)) {
                        val=false;
                        break;
                    }
                }
                if (k.empty() || !val){
                    cout<<"| Invalid keyword! Use letters A-Z only!\n";
                    continue;
                }
                //Vigenere Cipher encode
                if(ft==4){
                    result=vig(inp, k, false);
                    cout<<"| Encoded message: "<<result<<endl;
                    addHist ("Vigenere-Encode", inp, result);
                    }
                // Vigenere Cipher decode
                else if (ft==5){
                    result=vig(inp, k, true);
                    cout<<"| Decoded message: "<<result<<endl;
                    addHist ("Vigenere-Decode", inp, result);
                }
            }
            // Cipher manual
            else if (ft==6){
                cout<<"=====MANUAL=====\n";
                cout<<"| WHAT IS A CIPHER?\n| A cipher changes a message into a coded form.\n| It can be used to hide a message from casual readers\n.";
                cout<<endl;
                cout<<"| 1.CAESAR CIPHER\n| Each letter is shifted through the alphabet.\n| Example: HELLO with a shift of 3 becomes KHOOR.\n| You can choose the value of the shift.\n";
                cout<<endl;
                cout<<"| 2.ATBASH CIPHER\n| The alphabet is reversed: A becomes Z, B becomes Y.\n| Example: HELLO becomes SVOOL.\n";
                cout<<endl;
                cout<<"| 3.VIGENERE CIPHER\n| Each letter is shifted according to a repeating keyword based on a chart.\n| Example: HELLO with the keyword KEY becomes RIJVS.\n";
            }
            cout << "\n| Press Enter to return to the menu";
        cin.get();
        }
    }
        // ASCII menu
        else if(choice==4){
            while (true){
            cout<<"=========================\n";
            cout<<"|---------ASCII---------|\n";
            cout<<"=========================\n";
            cout<<"|\n";
            cout<<"----- Choose an option: -----\n";
            cout<<"| [1] Text to ASCII\n";
            cout<<"| [2] ASCII to text\n";
            cout<<"| [0] Back to main menu\n";
            cout<<"| Enter your choice: ";
            if(!rd(ft)){
                cout<<"\n| Invalid input!\n";
                continue;
            }
            if (ft==0)
            break;
            if (ft<0 || ft>2){
                cout<<"| Invalid option!\n";
                continue;
                }
            // ASCII encode
            if (ft==1){
                cout<<"===== TEXT TO ASCII =====\n";
                cout<<"| Enter your message: ";
                getline(cin, inp);cout<<endl;
                result=txtToAscii(inp);
                cout<<"| Encoded message: "<<result<<endl;
                addHist ("ASCII-Encode", inp, result);
                cout<<"| Press enter to continue ";
                    cin.get();
            }
            // ASCII decode
            else if (ft==2){
                cout<<"===== ASCII TO TEXT =====\n";
                cout<<"| Enter the ASCII numbers: ";
                getline(cin, inp);cout<<endl;
                result=asciiToTxt(inp);
                cout<<" Decoded message: "<<result<<endl;
                if (!result.empty() && result[0] !='|')
                addHist ("ASCII-Decode", inp, result);
                cout<<"| Press enter to continue ";
                    cin.get();
            }
        }
    }
    //A1Z26 menu
    else if (choice==5){
        while (true){
        cout<<"===============================\n";
        cout<<"|---A1Z26(NUMBER TO LETTER)---|\n";
        cout<<"===============================\n";
        cout<<"|\n";
        cout<<"----- Choose an option: -----\n";
        cout<<"| [1] Letter to number\n";
        cout<<"| [2] Number to letter\n";
        cout<<"| [3] Manual\n";
        cout<<"| [0] Back to main menu\n";
        cout<<"| Enter your choice: ";
        if (!rd(ft)){
            cout<<"\n| Invalid input!\n";
            continue;
        }
        if (ft==0)
        break;
        if (ft<1 || ft>3) {
            cout << "\n| Invalid option!\n";
            continue;
            }
        // A1Z26 encode
        if (ft==1){
            cout<<"===== LETTER TO NUMBER =====\n";
            cout<<"| Enter text: ";
            getline(cin, inp);
            result=letterToNumber(inp);
            cout<<"| Encoded: "<<result<<endl;
            addHist ("A1Z26-Encode", inp, result);
        }
        //A1Z26 decode
        else if (ft==2){
            cout<<"===== NUMBER TO LETTER =====\n";
            cout<<"| Enter the numbers: ";
            getline(cin, inp);
            result=numberToLetter(inp);
            cout<<"| Decoded: "<<result<<endl;
            if(!result.empty() && result[0] !='|')
            addHist ("A1Z26-Decode", inp, result);
        }
        // A1Z26 manual
        else if (ft==3){
            cout<<"===== MANUAL =====\n";
            cout<<"|A1Z26 replaces each letter with its position in the alphabet (A = 1, B = 2, ..., Z = 26).\n";
            cout<<"|Encode: Replace letters with numbers. CAT-3 1 20\n";
            cout<<"|Decode: Replace numbers with letters. 3 1 20-CAT\n| Use spaces between numbers and / between words.\n";
        }
        cout << "\n| Press Enter to return to the menu";
        cin.get();
    }
}
    // NATO menu
    else if (choice==6){
        while (true){
        cout<<"========================\n";
        cout<<"|---------NATO---------|\n";
        cout<<"========================\n";
        cout<<"|\n";
        cout<<"----- Choose an option: -----\n";
        cout<<"| [1] Text to NATO\n";
        cout<<"| [2] NATO to text\n";
        cout<<"| [3] Manual\n";
        cout<<"| [0] Back to main menu\n";
        cout<<"| Enter your choice: ";
        if (!(cin>>ft)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"| Invalid input!\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if (ft==0)
        break;
        if (ft<0 || ft>3){
            cout<<"| Invalid option!\n";
            continue;
            }
        // NATO encode
        if (ft==1){
            cout<<"===== TEXT TO NATO =====\n";
            cout<<"| Enter text: ";
            getline(cin,txt);
            result=txtToNato(txt);
            cout<<"| In NATO: "<<result<<endl;
            addHist ("NATO-Encode", txt, result);
        }
        // NATO decode
        else if (ft==2){
            cout<<"===== NATO TO TEXT =====\n";
            cout<<"| Enter NATO (Use / between words): ";
            getline(cin, code);
            result=natoToTxt(code);
            cout<<"| In text: "<<result<<endl;
            addHist ("NATO-Decode", code, result);
            }
        // NATO manual
        else if (ft==3){
            cout<<"=====MANUAL=====\n";
            cout<<"| The NATO Phonetic Alphabet converts letters into predefined words to make messages easier to understand and communicate.\n";
            cout<<"| - Text to NATO: Enter a normal message to convert each letter into its NATO word (HELLO-Hotel Echo Lima Lima Oscar).\n";
            cout<<"| - NATO to Text: Enter NATO words separated by spaces to decode them back into letters.\n";
            cout<<"| - Use / to separate words in a message.\n";
            cout<<"| - Only letters A-Z and spaces are supported. Numbers and punctuation are ignored.\n";
            }
            cout << "\n| Press Enter to return to the menu";
        cin.get();
        }
    }
    // Message history menu
    else if (choice==7){
        while (true){
        cout<<"===============================\n";
        cout<<"|-------MESSAGE HISTORY-------|\n";
        cout<<"===============================\n";
        cout<<"|\n";
        cout<<"----- Choose an option: -----\n";
        cout<<"| [1] View history\n";
        cout<<"| [2] Clear history\n";
        cout<<"| [0] Back to main menu\n";
        cout<<"| Enter your choice: ";
        if (!rd(ft)){
            cout<<"\n| Invalid input!\n";
            continue;
        }
        if (ft==0)
        break;
        if (ft<0 || ft>2){
            cout<<"\n| Invalid option!\n";
            continue;
        }
        if (ft==1){
            shwHist();
        }
        // Clear message history
        else if (ft==2){
            clrHist();
        }
        }
    }
    // Decoder challenge minigame
    else if (choice==8){
        cout<<"=================================\n";
        cout<<"|        CHALLENGE MODE         |\n";
        cout<<"=================================\n";
        chal();
    }
    // Exit message
    else if (choice==0){
        cout<<"| Transmission ended. Goodbye!";
        return 0;
        }
    }
    return 0;
}