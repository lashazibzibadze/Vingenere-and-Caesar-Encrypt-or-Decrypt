/* 
Author: Lasha Zibzibadze
Course: CSCI-135
Instructor: Genady Maryash

Viginere and Caesar Encrypt - Decrypt
*/
#include <string>

#include <iostream>
using namespace std;

char shiftChar(char c, int rshift){
    if(!(isalpha(c))){
        return c;
    }
    
    if(c>= 'a' && c <= 'z'){
        return 'a' + ((c - 'a' +rshift) % 26);

    }
    else{

        return 'A' + ((c - 'A' + rshift) % 26);
    }
    


}

string encryptCaesar(string plaintext, int rshift){
    // string encryption= "";
    // int shifter;
    char ch;
    for(int i=0; i< plaintext.size(); i++){
        ch= plaintext[i];
        if(ch >= 'a' && ch <= 'z'){
            // ch= ch+rshift;
            // if(ch> 'z'){
            //     ch= ch - 'z' + 'a' -1;
            // }
            // encryption= encryption+ ch;
            plaintext[i]= shiftChar(plaintext[i], rshift);
        }
        else if(ch >= 'A' && ch <= 'Z'){
            plaintext[i]= shiftChar(plaintext[i], rshift);
            // ch= ch+ rshift;
            // if(ch> 'Z'){
            //     ch= ch = 'Z' + 'A' -1;
            // }
            // encryption= encryption+ch;
        }

    }


    return plaintext;
}

string encryptVigenere(string plaintext, string keyword){
    char c;
    string new_string;
    int index= 0;
    int key;

    for(int k=0; k< plaintext.size(); k++){
        c= plaintext[k];
        if(c >= 'a' && c <= 'z'){
            key= keyword[index]- 'a';
            index= (index+1)% keyword.size();
            c= 'a' + (c - 'a' + key + 26) % 26;
        }
        // if((c >='a') || (c <= 'z')
        if(c >= 'A' && c <= 'Z'){
            key= keyword[index] - 'a';
            index= (index+1)%keyword.size();
            c= 'A' + (c - 'A' + key + 26) % 26;
        }

        new_string= new_string+ c;

    }

    return new_string;


}

string decryptCaesar(string ciphertext,int rshift){
    char c;
    for(int k=0; ciphertext[k] != '\0'; k++){
        c= ciphertext[k];
        if(c >= 'a' && c <= 'z'){
            c= c - rshift;
            if(c < 'a'){
                c= c+ 'z'- 'a' +1;
            }

            ciphertext[k]= c;
        
        }

        if(c >= 'A' && c <= 'Z'){
            c= c - rshift;
            if(c < 'A'){
                c= c+ 'Z'- 'A' +1;
            }

            ciphertext[k]= c;




        }




    }
    return ciphertext;




}


string decryptVigenere(string ciphertext, string keyword){
    string new_word= "";
    char ch;
    int index=0;
    int key;
    int size= keyword.size();
    for (int i=0; i< ciphertext.size(); i++){
        ch= ciphertext[i];

        if(ch >= 'A' && ch <='Z'){
            key= keyword[index] - 'a';
            index= (index+1) % size;
            ch= ('A' + (ch - 'A' - key + 26) %26);
        }
        if(ch >= 'a' && ch <= 'z'){
            key= keyword[index] - 'a';
            index= (index+1) % size;
            ch= ('a' + (ch - 'a' - key + 26) %26);

        }
        new_word= new_word+ ch;

    }
    return new_word;





}
int main(){
    string text;
    string key;
    int shift;
    cout<< "Enter Plain Text: ";
    getline(cin, text);
    cout<<"Caesar"<<endl;
    cout<<"Enter Shift: ";
    cin>>shift;
    cout<<"Ciphertext: "<< encryptCaesar(text, shift)<<endl;
    string Encrypted= encryptCaesar(text, shift);
    cout<<"Decrypted: "<< decryptCaesar(Encrypted, shift)<<endl;

    cout<<"Vigenere"<<endl;
    cout<<"Enter keyword: ";
    cin>> key;
    cout<<"Ciphertext: "<< encryptVigenere(text,key)<<endl;
    string Eecrypted_v=encryptVigenere(text,key);
    cout<<"Decrypted: "<< decryptVigenere(Eecrypted_v, key)<<endl;









    return 0;



}