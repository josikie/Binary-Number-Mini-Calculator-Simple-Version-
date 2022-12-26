#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

class CalculateBinaryNumbers{
    public:

    std::vector<char> convertCharArrayToVector(char *arr, long long int length){
        std::vector<char> charArr;
        for(long long int i = 0; i < length; i++){
            charArr.push_back(arr[i]);
        }
        return charArr;
    }

    void equateLength(long long int firstLength, long long int secondLength, std::vector<char> &charArr){
        if(firstLength > secondLength){
            long long int devitation = firstLength - secondLength;
            for(long long int i = 0; i < devitation; i++){
                charArr.insert(charArr.begin(), '0');
            }
        }
    }

    string addBinaryStrings(std::vector<char> charArrA, std::vector<char> charArrB){
        std::vector<char> charAddAB;
        char temp = '0';
        for(long long int i = charArrA.size()-1; i > -1; i--){
            char number = '0';
            if(charArrA[i] == '1' && charArrB[i] == '1'){
                
                if (temp == '1' && i == 0){
                    number = '1';
                    charAddAB.push_back(number);
                    number = '1';
                    temp = '0';
                }else if (temp == '0' && i == 0){
                    number = '0';
                    charAddAB.push_back(number);
                    number = '1';
                    temp = '0';
                }else if(temp == '1'){
                    number = '1';
                    temp = '1';
                }else if(temp == '0'){
                    number = '0';
                    temp = '1';
                }
            }else if(charArrA[i] == '1' && charArrB[i] == '0'){

                if(temp == '1' && i == 0){
                    number = '0';
                    charAddAB.push_back(number);
                    number = '1';
                    temp = '0';
                }else if(temp == '0' && i == 0){
                    number = '1';
                    temp = '0';
                }else if(temp == '1'){
                    number = '0';
                    temp = '1';
                }else if(temp == '0'){
                    number = '1';
                    temp = '0';
                }
            }else if(charArrA[i] == '0' && charArrB[i] == '1'){
                if(temp == '1' && i == 0){
                    number = '0';
                    charAddAB.push_back(number);
                    number = '1';
                    temp = '0';
                }else if(temp == '0' && i == 0){
                    number = '1';
                    temp = '0';
                }else if(temp == '1'){
                    number = '0';
                    temp = '1';
                }else{
                    number = '1';
                    temp = '0';
                }
            }else if(charArrA[i] == '0' && charArrB[i] == '0'){
                if(temp == '1'){
                    number = '1';
                    temp = '0';
                }else if(temp == '0'){
                    number = '0';
                    temp = '0';
                }
            }

            charAddAB.push_back(number);
        }

        //reverse to normal, convert it to strings
        string charA = "";
        for(long long int i = charAddAB.size()-1; i > -1; i--){
            charA = charA + charAddAB[i];
        }

        return charA;
    }
    
    long long int addBinaryNumbers(std::string a, std::string b){
        // take the string lengths
        long long int lengthA = a.length();
        long long int lengthB = b.length();

        // initiate pointer char array with size corresponding to the string lengths
        char *arrA = new char[lengthA+1];
        char *arrB = new char[lengthB+1];

        // convert strings to char arrays
        strcpy_s(arrA, lengthA+1, a.c_str());
        strcpy_s(arrB, lengthB+1, b.c_str());

        // convert char arrays to vector arrays
        std::vector<char> charArrA{convertCharArrayToVector(arrA, lengthA)};
        std::vector<char> charArrB{convertCharArrayToVector(arrB, lengthB)};

        // delete memory for char arrays
        delete[] arrA;
        delete[] arrB;

        // add 0 in front if length B less than length A
        equateLength(lengthA, lengthB, charArrB);
        equateLength(lengthB, lengthA, charArrA);

        // reverse, add binary strings
        string charA = addBinaryStrings(charArrA, charArrB);

        //convert it to integer
        long long int AB = 0;
        try{
            AB = stoll(charA);
        }
        catch(std::out_of_range error){
            cout << "Index out of range. Only can calculate binary numbers with range less or equal to 18 digits. \n";
            return 0;
        }

        return AB;
    }

};

int main(){
    CalculateBinaryNumbers cbn;
    std::cout << cbn.addBinaryNumbers("111001", "11001");
}