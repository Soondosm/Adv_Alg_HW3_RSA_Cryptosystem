#include <iostream> 
#include <unordered_map>
#include<math.h> 
#include <locale> 
#include <string>

using namespace std; 
// find gcd
int gcd(int a, int b) {
   int t;
   while(1) {
      t= a%b;
      if(t==0)
      return b;
      a = b;
      b= t;
   }
}

int * getArray(string M, unordered_map<char, int> BEARCATII) { // returns array of base 27 ints
    static int array [sizeof(M)];
    for (int i = 0; i < sizeof(M); i++) {
        char element = M[i];
        array[i] = BEARCATII[element];  
        }
    return array;
}

/**
 * Converts base 27 sequence of "TEST" string into a single decimal.
 * @param int array. Array of base 27 ints obtained from converting string into
 * base27. */
int getDecimal(int array[]) {
    int result = 0;
    int power = 0;
    for(int i = sizeof(*array)-1; i >= 0; i--) {
        result = result + (array[i] * pow(27, power));
        // the below line is edited-out code for only debugging purposes.
        // cout << "POWER" << power << " ARRAY ELEMENT" << array[i] << " INDEX" << i << " CURRENTRESULT" << result << '\n';
        power++; 
    }
    return result;
}

string runDecrypt(unsigned long long int message, unordered_map<char, int> BEARCATII) {
    int result = 0;
    int power = 0;
    int size = sqrt(sqrt(message));
    int decryptArray[size];
    string strM = ""; // string message
    // for(int i = sizeof(*array)-1; i >= 0; i--) {
    //     result = result + (array[i] * pow(27, power));
    //     power++; 
    // }
    return strM;
}

int main() 
    { 
    // key = char type, and mapped value = double type 
    unordered_map<char, int> BEARCATII; 

    // inserting values by using [] operator 
    BEARCATII[' '] = 0; BEARCATII['a'] = 1; BEARCATII['b'] = 2; 
    BEARCATII['c'] = 3; BEARCATII['d'] = 4; BEARCATII['e'] = 5; 
    BEARCATII['f'] = 6; BEARCATII['g'] = 7; BEARCATII['h'] = 8; 
    BEARCATII['i'] = 9;  BEARCATII['j'] = 10; BEARCATII['k'] = 11; 
    BEARCATII['l'] = 12; BEARCATII['m'] = 13; BEARCATII['n'] = 14; 
    BEARCATII['o'] = 15; BEARCATII['p'] = 16; BEARCATII['q'] = 17; 
    BEARCATII['r'] = 18; BEARCATII['s'] = 19; BEARCATII['t'] = 20; 
    BEARCATII['u'] = 21; BEARCATII['v'] = 22; BEARCATII['w'] = 23; 
    BEARCATII['x'] = 24; BEARCATII['y'] = 25; BEARCATII['z'] = 26; 
    string M = "TEST";

    //2 random prime numbers
    double p = 13;
    double q = 11;
    double n=p*q;//calculate n
    double track;
    double phi= (p-1)*(q-1);//calculate phi

    cout << "Please enter a string to be encrypted and decryped:";
    cin >> M;
    transform(M.begin(), M.end(), M.begin(), ::tolower);
    cout << "You have entered:" << M << '\n';
    cin.clear();
    int * stringArray = getArray(M, BEARCATII);
    unsigned long long int stringDecimal = getDecimal(stringArray); // decimalized string
    cout << "The base 27 decimal is: " << stringDecimal << '\n';
    //e = public key
    double e;
    cout << "Type a positive integer for public key 'e': "; // Type a number and press enter
    cin >> e; // Get user input from the keyboard
    //for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
    while(e<phi) {
        track = gcd(e,phi);
        if(track==1)
            break;
        else
            cout << "That public key is not coprime. Please enter another: ";
            cin.clear();
            cin >> e;
    }
     cout << "Your public key 'e' is: " << e; // Display the input value 

    //private key
    //d stands for decrypt
    //choosing d such that it satisfies d*e = 1 mod phi
    double d1=1/e;
    double decrypter=fmod(d1,phi);
    unsigned long long int C = pow(stringDecimal,e); //encrypt the message
    double P = pow(C,decrypter);
    C=fmod(C,n);
    P=fmod(P,n); // decrypted message
    

    return 0;
}