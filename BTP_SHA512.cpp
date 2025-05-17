#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll M = 1000000000+7;
ll Z = 998244353;

 
ll binpow(ll a,ll b){
    ll res = 1;
    while (b){
        if (b&1) res = (res*a)%M;
        a = (a*a)%M;
        b>>=1;
    }
    return res;
}

void decToBinary(ll n,ll size)
{
    ll binaryNum[32];

for(ll i=0;i<32;i++)
    binaryNum[i]=0;
    ll i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (ll j = size-1; j >= 0; j--)
        cout << binaryNum[j];
}


int fact(int n){
    if(n==0)
        return 1;
    return n*fact(n-1);
}

string TextToBinaryString(string words) {
    string binaryString = "";
    for (char& _char : words) {
        binaryString +=bitset<8>(_char).to_string();
    }
    return binaryString;
}

int num_padding(string message){
    int message_length = message.length();
    int val = message_length%1024;
    if(val<=896){
        return 896-val;
    }
    else{
        return 1920-val;
    }
}

string int_to_128bin(int num){
    bitset<128> binary(num);
    string s = binary.to_string();
    return s;
}

string padding(string message, int padding_required, int message_length){
    string end = int_to_128bin(message_length);
    if(padding_required==0){
        message+=end;
        return message;
    }
    else{
    message+="1";
    for(int i=0;i<padding_required-1;i++){
        message+="0";
    }
    message+=end;
    return message;
        }
}

string rotr(string word, int n){
    int len = word.length();
    n = n%len;
    string right_end = word.substr(len-n);
    word = right_end+word;
    word = word.substr(0,len);
    return word;
}

string shr(string word, int n){
    int len = word.length();
    string left_end = word.substr(0,len-n);
    for(int i=0;i<n;i++){
        left_end="0"+left_end;
    }
    return left_end;
}

string bin_xor(string a, string b){
    string result="";
    for(int i=0;i<a.length();i++){
        if(a[i]==b[i]){
            result+="0";
        }
        else{
            result+="1";
        }
    }
    return result;
}

string bin_not(string a){
    string result="";
    for(int i=0;i<a.length();i++){
        if(a[i]=='0'){
            result+="1";
        }
        else{
            result+="0";
        }
    }
    return result;
}

string bin_and(string a, string b){
    string result="";
    for(int i=0;i<a.length();i++){
        if(a[i]=='1'&&b[i]=='1'){
            result+="1";
        }
        else{
            result+="0";
        }
    }
    return result;
}

string sigma0(string word){
    string s1= rotr(word,1);
    string s2 = rotr(word,8);
    string s3 = shr(word,7);
    string s12 = bin_xor(s1,s2);
    string final = bin_xor(s12,s3);
    return final;
}

string sigma1(string word){
    string s1= rotr(word,19);
    string s2 = rotr(word,61);
    string s3 = shr(word,6);
    string s12 = bin_xor(s1,s2);
    string final = bin_xor(s12,s3);
    return final;
}

string addBinaryMod2_64(string bin1, string bin2) {
    uint64_t num1 = stoull(bin1, nullptr, 2);
    uint64_t num2 = stoull(bin2, nullptr, 2);

    uint64_t sum = num1 + num2;

    return bitset<64>(sum).to_string();
}

string ch(string e, string f, string g){
    string s1= bin_and(e,f);
    string s2 = bin_not(e);
    string s3 = bin_and(s2,g);
    string final = bin_xor(s1,s3);
    return final;
}

string sum1(string s){
    string s1 = rotr(s,14);
    string s2 = rotr(s,18);
    string s3 = rotr(s,41);
    string s4 = bin_xor(s1,s2);
    string final = bin_xor(s3,s4);
    return final;
}

string maj(string a, string b, string c){
    string s1 = bin_and(a,b);
    string s2 = bin_and(a,c);
    string s3 = bin_and(b,c);
    string s4 = bin_xor(s1,s2);
    string final = bin_xor(s3,s4);
    return final;
}

string sum0(string s){
    string s1 = rotr(s,28);
    string s2 = rotr(s,34);
    string s3 = rotr(s,39);
    string s4 = bin_xor(s1,s2);
    string final = bin_xor(s3,s4);
    return final;
}

int main(){
    vector<string> k={"0100001010001010001011111001100011010111001010001010111000100010","0111000100110111010001001001000100100011111011110110010111001101",
                      "1011010111000000111110111100111111101100010011010011101100101111","1110100110110101110110111010010110000001100010011101101110111100",
                      "0011100101010110110000100101101111110011010010001011010100111000","0101100111110001000100011111000110110110000001011101000000011001",
                      "1001001000111111100000101010010010101111000110010100111110011011","1010101100011100010111101101010111011010011011011000000100011000",
                      "1101100000000111101010101001100010100011000000110000001001000010","0001001010000011010110110000000101000101011100000110111110111110",
                      "0010010000110001100001011011111001001110111001001011001010001100","0101010100001100011111011100001111010101111111111011010011100010",
                      "0111001010111110010111010111010011110010011110111000100101101111","1000000011011110101100011111111000111011000101101001011010110001",
                      "1001101111011100000001101010011100100101110001110001001000110101","1100000110011011111100010111010011001111011010010010011010010100",
                      "1110010010011011011010011100000110011110111100010100101011010010","1110111110111110010001111000011000111000010011110010010111100011",
                      "0000111111000001100111011100011010001011100011001101010110110101","0010010000001100101000011100110001110111101011001001110001100101",
                      "0010110111101001001011000110111101011001001010110000001001110101","0100101001110100100001001010101001101110101001101110010010000011",
                      "0101110010110000101010011101110010111101010000011111101111010100","0111011011111001100010001101101010000011000100010101001110110101",
                      "1001100000111110010100010101001011101110011001101101111110101011","1010100000110001110001100110110100101101101101000011001000010000",
                      "1011000000000011001001111100100010011000111110110010000100111111","1011111101011001011111111100011110111110111011110000111011100100",
                      "1100011011100000000010111111001100111101101010001000111111000010","1101010110100111100100010100011110010011000010101010011100100101",
                      "0000011011001010011000110101000111100000000000111000001001101111","0001010000101001001010010110011100001010000011100110111001110000",
                      "0010011110110111000010101000010101000110110100100010111111111100","0010111000011011001000010011100001011100001001101100100100100110",
                      "0100110100101100011011011111110001011010110001000010101011101101","0101001100111000000011010001001110011101100101011011001111011111",
                      "0110010100001010011100110101010010001011101011110110001111011110","0111011001101010000010101011101100111100011101111011001010101000",
                      "1000000111000010110010010010111001000111111011011010111011100110","1001001001110010001011001000010100010100100000100011010100111011",
                      "1010001010111111111010001010000101001100111100010000001101100100","1010100000011010011001100100101110111100010000100011000000000001",
                      "1100001001001011100010110111000011010000111110001001011110010001","1100011101101100010100011010001100000110010101001011111000110000",
                      "1101000110010010111010000001100111010110111011110101001000011000","1101011010011001000001100010010001010101011001011010100100010000",
                      "1111010000001110001101011000010101010111011100010010000000101010","0001000001101010101000000111000000110010101110111101000110111000",
                      "0001100110100100110000010001011010111000110100101101000011001000","0001111000110111011011000000100001010001010000011010101101010011",
                      "0010011101001000011101110100110011011111100011101110101110011001","0011010010110000101111001011010111100001100110110100100010101000",
                      "0011100100011100000011001011001111000101110010010101101001100011","0100111011011000101010100100101011100011010000011000101011001011",
                      "0101101110011100110010100100111101110111011000111110001101110011","0110100000101110011011111111001111010110101100101011100010100011",
                      "0111010010001111100000101110111001011101111011111011001011111100","0111100010100101011000110110111101000011000101110010111101100000",
                      "1000010011001000011110000001010010100001111100001010101101110010","1000110011000111000000100000100000011010011001000011100111101100",
                      "1001000010111110111111111111101000100011011000110001111000101000","1010010001010000011011001110101111011110100000101011110111101001",
                      "1011111011111001101000111111011110110010110001100111100100010101","1100011001110001011110001111001011100011011100100101001100101011",
                      "1100101000100111001111101100111011101010001001100110000110011100","1101000110000110101110001100011100100001110000001100001000000111",
                      "1110101011011010011111011101011011001101111000001110101100011110","1111010101111101010011110111111111101110011011101101000101111000",
                      "0000011011110000011001111010101001110010000101110110111110111010","0000101001100011011111011100010110100010110010001001100010100110",
                      "0001000100111111100110000000010010111110111110010000110110101110","0001101101110001000010110011010100010011000111000100011100011011",
                      "0010100011011011011101111111010100100011000001000111110110000100","0011001011001010101010110111101101000000110001110010010010010011",
                      "0011110010011110101111100000101000010101110010011011111010111100","0100001100011101011001111100010010011100000100000000110101001100",
                      "0100110011000101110101001011111011001011001111100100001010110110","0101100101111111001010011001110011111100011001010111111000101010",
                      "0101111111001011011011111010101100111010110101101111101011101100","0110110001000100000110011000110001001010010001110101100000010111"};


   string testText;
    cout << "Enter the text to be hashed: ";
    getline(cin, testText);
    cout << "Test text: " << testText << "\n";
    string message = TextToBinaryString(testText);
    int padding_required = num_padding(message);
    int message_length = message.length();
    string padded_message = padding(message, padding_required, message_length);
    //cout<<message<<"\n";
    //cout<<padded_message<<"\n";

    int padded_message_length = padded_message.length();

    //cout << "Convert text to binary: " << binarystring << "!\n";
    vector<string> blocks;
    int num_blocks = (padded_message_length/1024);
    //cout<<padded_message_length<<"\n";
    int blehh=0;
    for(int i=0;i<num_blocks-1;i++){
        string temp_block = padded_message.substr(blehh,1024);
        blocks.push_back(temp_block);
        blehh+=1024;
    }
    string final_block = padded_message.substr(blehh);
    blocks.push_back(final_block);
    //cout<<num_blocks<<"\n";
    //cout<<blehh<<"\n";
    string a = "0110101000001001111001100110011111110011101111001100100100001000";
    string b = "1011101101100111101011101000010110000100110010101010011100111011";
    string c = "0011110001101110111100110111001011111110100101001111100000101011";
    string d = "1010010101001111111101010011101001011111000111010011011011110001";
    string e = "0101000100001110010100100111111110101101111001101000001011010001";
    string f = "1001101100000101011010001000110000101011001111100110110000011111";
    string g = "0001111110000011110110011010101111111011010000011011110101101011";
    string h = "0101101111100000110011010001100100010011011111100010000101111001";
    vector<string> initialization_vec = {a,b,c,d,e,f,g,h};

    //MODULE STARTS FROM HERE ********************************* AND LOOP ON BLOVKS TOO

    for(int i=0;i<blocks.size();i++){
        vector<string> initialization_vec2 = initialization_vec;
        string block = blocks[i];
        //EXTRACT 80 WORDS FROM BLOCK
        vector<string> words;
        for(int j=0;j<1024;j+=64){
            string word_tmp = block.substr(j,64);
            words.push_back(word_tmp);
        }
        //cout<<words.size()<<"\n";
        for(int j=16;j<80;j++){
            string s1 = words[j-2];
            string s2 = words[j-7];
            string s3 = words[j-15];
            string s4 = words[j-16];
            string s1a = sigma1(s1);
            string s3a = sigma0(s3);
            string s24 = addBinaryMod2_64(s2,s4);
            string s13 = addBinaryMod2_64(s1a,s3a);
            string final_word = addBinaryMod2_64(s24,s13);
            words.push_back(final_word);
        }
        //cout<<words.size()<<"\n";
        //AFTER CREATING WORDS OUR MODULE F IS PUT IN PLACE
        //LOOP FOR ROUNDS IS PUT IN PLACE HERE
        //cout<<k[0]<<"\n";
        for(int round=0;round<80;round++){
            string s1 = ch(initialization_vec2[4],initialization_vec2[5],initialization_vec2[6]);
            string s2 = sum1(initialization_vec2[4]);
            string s3 = initialization_vec2[7];
            string s4 = words[round];
            string s5 = k[round];
            string s6 = addBinaryMod2_64(s1,s2);
            string s7 = addBinaryMod2_64(s3,s4);
            string s8 = addBinaryMod2_64(s6,s7);
            string T1 = addBinaryMod2_64(s8,s5);
            string s9 =  sum0(initialization_vec2[0]);
            string s10 = maj(initialization_vec2[0],initialization_vec2[1],initialization_vec2[2]);
            string T2 = addBinaryMod2_64(s9,s10);
            string a1 = addBinaryMod2_64(T1,T2);
            string b1 = initialization_vec2[0];
            string c1 = initialization_vec2[1];
            string d1 = initialization_vec2[2];
            string e1 = addBinaryMod2_64(initialization_vec2[3],T1);
            string f1 = initialization_vec2[4];
            string g1 = initialization_vec2[5];
            string h1 = initialization_vec2[6];
            initialization_vec2 = {a1,b1,c1,d1,e1,f1,g1,h1};
        }
        vector<string> tmp;
        tmp.push_back(addBinaryMod2_64(initialization_vec[0],initialization_vec2[0]));
        tmp.push_back(addBinaryMod2_64(initialization_vec[1],initialization_vec2[1]));
        tmp.push_back(addBinaryMod2_64(initialization_vec[2],initialization_vec2[2]));
        tmp.push_back(addBinaryMod2_64(initialization_vec[3],initialization_vec2[3]));
        tmp.push_back(addBinaryMod2_64(initialization_vec[4],initialization_vec2[4]));
        tmp.push_back(addBinaryMod2_64(initialization_vec[5],initialization_vec2[5]));
        tmp.push_back(addBinaryMod2_64(initialization_vec[6],initialization_vec2[6]));
        tmp.push_back(addBinaryMod2_64(initialization_vec[7],initialization_vec2[7]));
        initialization_vec = tmp;
    }
//FINAL MESSAGE DIGEST IS IN INTIALIZATION VECTOR, VARIABLE IN 8 ELEMENTS, 64 BITS EACH, TOTAL 512 BITS
    string final_message_digest ="";
    for(int i=0;i<8;i++){
        final_message_digest+=initialization_vec[i];
    }
    cout<<final_message_digest<<"\n";


}

