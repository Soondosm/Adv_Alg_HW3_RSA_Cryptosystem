#include <iostream> 
#include <unordered_map>
#include <math.h> 
#include <locale> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 


// IMPORTED FUNCTIONS:

// FUNCTION OBTAINED FROM:
// https://www.geeksforgeeks.org/sum-two-large-numbers/
// Function for finding sum of larger numbers 
string findSum(string str1, string str2) { 
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
    // Take an empty string for storing result 
    string str = ""; 
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
    // Reverse both of strings 
    std::reverse(str1.begin(), str1.end()); 
    std::reverse(str2.begin(), str2.end()); 
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        // Calculate carry for next step 
        carry = sum/10; 
    } 
    // Add remaining digits of larger number 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
    // std::reverse resultant string 
    std::reverse(str.begin(), str.end()); 
    return str; 
} 

// FUNCTION OBTAINED FROM:
// https://www.geeksforgeeks.org/divide-large-number-represented-string/
// A function to perform division of large numbers 
string longDivision(string number, int divisor) 
{ 
    // As result can be very large store it in string 
    string ans; 
    // Find prefix of number that is larger 
    // than divisor. 
    int idx = 0; 
    int temp = number[idx] - '0'; 
    while (temp < divisor) 
        temp = temp * 10 + (number[++idx] - '0'); 
    // Repeatedly divide divisor with temp. After 
    // every division, update temp to include one 
    // more digit. 
    while (number.size() > idx) { 
        // Store result in answer i.e. temp / divisor 
        ans += (temp / divisor) + '0'; 
  
        // Take next digit of number 
        temp = (temp % divisor) * 10 + number[++idx] - '0'; 
    } 
  
    // If divisor is greater than number 
    if (ans.length() == 0) 
        return "0"; 
  
    // else return ans 
    return ans; 
} 


// THIS FUNCTION IS PULLED FROM:
// https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/
// Multiplies str1 and str2, and prints result. 
string multiply(string num1, string num2) { 
    int len1 = num1.size(); 
    int len2 = num2.size(); 
    if (len1 == 0 || len2 == 0) 
    return "0"; 
    // std::cout << num1 << "   .....   " << num2 << "\n"<<"\n";
    // will keep the result number in vector 
    // in std::reverse order 
    vector<int> result(len1 + len2, 0); 
    // Below two indexes are used to find positions 
    // in result.  
    int i_n1 = 0;  
    int i_n2 = 0;   
    // Go from right to left in num1 
    for (int i=len1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
        // To shift position to left after every 
        // multiplication of a digit in num2 
        i_n2 = 0;  
        // Go from right to left in num2              
        for (int j=len2-1; j>=0; j--) 
        { 
            // Take current digit of second number 
            int n2 = num2[j] - '0'; 
            // Multiply with current digit of first number 
            // and add result to previously stored result 
            // at current position.  
            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
            // Carry for next iteration 
            carry = sum/10;
            if(carry < 0 || sum < 0) carry = 0;
            // Store result 
            result[i_n1 + i_n2] = sum % 10; 
            i_n2++; 
        } 
        // store carry in next cell 
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
        // To shift position to left after every 
        // multiplication of a digit in num1. 
        i_n1++; 
    } 
    // ignore '0's from the right 
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
    // If all were '0's - means either both or 
    // one of num1 or num2 were '0' 
    if (i == -1) 
    return "0"; 
    // generate the result string 
    string s = ""; 
    while (i >= 0) 
        s += to_string(result[i--]); 
    return s; 
} 


// -----------------------------END IMPORTED FUNCTIONS---------------------



bool miller_rabin(int a, int nk, int n) {
	if (n < 1) {
		return false;
	}
	else if ((pow(a, nk) != -1) || (pow(a, nk) != 1)) {
		return false;
	}
	else if ((pow(a, nk) == 1) && fmod(nk,2) == 0) {
		return miller_rabin(a, nk / 2, n);
	}
	else return true;
}


bool primality_test(int n) {    // this algorithm works for n>3
	int a = 0;
	while (a < 2 || (fmod(a, n) == 0 && n > 4)) {
		a = rand() % (n-2);
	}
	if (n < 2 || n%2 ==0 || fmod(pow(a, (n - 1)), n) != 1) {
		return false;
	}
	else if (fmod(n, 2) == 0) {
		return miller_rabin(a, (n - 1)/2, n);
	}
	else return true;
}

pair<unsigned long long int, unsigned long long int> create_two_large_primes() {
    pair<unsigned long long int, unsigned long long int> primes;
    unsigned long long int max = 99;
    bool pPrime = false;
    bool qPrime = false;
    while(pPrime == false) {
        primes.first = rand() % max;
        pPrime = primality_test(primes.first);
        srand(time(NULL));
    }
    while(qPrime == false) {
        primes.second = rand() % max;
        qPrime = primality_test(primes.second);
        cout << qPrime;
        srand(time(NULL));
    }
    return primes;
}

unsigned long long int performRabin() {
    pair<unsigned long long int, unsigned long long int> primes;
    primes = create_two_large_primes();
    unsigned long long int p = primes.first;
    unsigned long long int q = primes.second;
    cout << primes.first << " " << primes.second;
    return p, q;
}





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

int * getArray(string M, unordered_map<char, int> BEARCATII, int size) { // returns array of base 27 ints
    int array [size];
    for (int i = 0; i < M.size(); i++) {
        char element = M[i];
        array[i] = BEARCATII[element];
        }
    return array;
}

/**
 * Converts base 27 sequence of "TEST" string into a single decimal.
 * @param int array. Array of base 27 ints obtained from converting string into
 * base27. */
string getDecimal(int array[], int size) {
    string result = "0";
    int power = 0;
    for(int i = size-1; i >= 0; i--) {
        int powerIter = power;
        string powered = "27";
        //int arrayItem = array[i]; string element = to_string(arrayItem);
        string element = to_string(array[i]);
        while(powerIter > 1) {
           powered = multiply(powered, to_string(27));
           powerIter--;
        }
        if(power == 1) {
            //powered = multiply(powered, to_string(array[i]));
            element = multiply(to_string(array[i]), "27");
        }  else if(power > 1) {
            element = multiply(to_string(array[i]), powered);
        }
        result = findSum(result, element);
        element = "0";
        power++;
    }
    return result;
}

string runDecrypt(string message, unordered_map<unsigned long long int, char> IITACREAB) {
    int power = 0;
    int size = message.size();
    unsigned long long int decryptArray[size-1];
    string strM; // string message
    int index = 0;
    while(message != "0") {
        string divided = longDivision(message, 27);
        decryptArray[index] = stoull(message) % 27;
        message = divided;
        index++;
    }
    int stringI = 0; // index for character position for our string output
    for(index; index >= 0; index--) {
        int base27 = decryptArray[index-1];
        strM += IITACREAB[base27];
        stringI++;
        // the below line is edited-out code for only debugging purposes.
        // std::cout << "POWER" << power << " ARRAY ELEMENT" << array[i] << " INDEX" << i << " CURRENTRESULT" << result << '\n';
    }
    return strM;
}



int main() 
    { 
    // key = char type, and mapped value = double type 
    unordered_map<char, int> BEARCATII;
    unordered_map<unsigned long long int, char> IITACREAB; // just like the prev hashmap, but backwards (ints are keys, charas are vals) 

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

    IITACREAB[0] = ' '; IITACREAB[1] = 'a'; IITACREAB[2] = 'b'; 
    IITACREAB[3] = 'c'; IITACREAB[4] = 'd'; IITACREAB[5] = 'e'; 
    IITACREAB[6] = 'f'; IITACREAB[7] = 'g'; IITACREAB[8] = 'h'; 
    IITACREAB[9] = 'i';  IITACREAB[10] = 'j'; IITACREAB[11] = 'k'; 
    IITACREAB[12] = 'l'; IITACREAB[13] = 'm'; IITACREAB[14] = 'n'; 
    IITACREAB[15] = 'o'; IITACREAB[16] = 'p'; IITACREAB[17] = 'q'; 
    IITACREAB[18] = 'r'; IITACREAB[19] = 's'; IITACREAB[20] = 't'; 
    IITACREAB[21] = 'u'; IITACREAB[22] = 'v'; IITACREAB[23] = 'w'; 
    IITACREAB[24] = 'x'; IITACREAB[25] = 'y'; IITACREAB[26] = 'z'; 
    string M;

    //2 random prime numbers
    //
    // double p = 13;  // HERE IS WHERE THE FUNCTION TO GENERATEPRIME
    // double q = 11;  // AND MILLER RABIN NEED TO BE CALLED, (MODIFY)
    unsigned long long int p, q = performRabin();
    ///
    double n=p*q;//calculate n
    double track;
    double phi= (p-1)*(q-1);//calculate phi

    std::cout << "Please enter a string to be encrypted and decryped:";
    getline(cin, M);
    //std::cin >> M;
    transform(M.begin(), M.end(), M.begin(), ::tolower);
    std::cout << "You have entered:" << M << " of size " << M.size() << '\n';
    cin.clear();
    
    // loop to place base 27 letters into number array
    const int size = M.size(); // size of string
    int stringArray [size];
    for (int i = 0; i < size; i++) {
        char element = M[i];
        stringArray[i] = BEARCATII[element];
        }

    string stringDecimal = getDecimal(stringArray, size); // decimalized string
    std::cout << "The base 27 decimal is: " << stringDecimal << '\n';
    //e = public key
    long double e;
    std::cout << "Type a positive integer for public key 'e': "; // Type a number and press enter
    cin >> e; // Get user input from the keyboard
    //for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
    while(e<phi) {
        track = gcd(e,phi);
        if(track==1)
            break;
        else
            std::cout << "That public key is not coprime with phi value " << phi << ". Please enter another: ";
            cin.clear();
            cin >> e;
    }
     std::cout << "Your public key 'e' is: " << e << '\n'; // Display the input value 

    //M = string received by user, M == P
    //e = public key
    //p = prime number
    //q = prime number
    //n = pq
    //C = encrypted message
    //P = decrypted message, P == M
    //choose a d such that it satisfies d*e = 1 mod phi
    double d1=1.00/e;
    double decrypter = fmod(d1,phi);
    string C = stringDecimal;
    unsigned long long int exponent = e;
    while (exponent > 0) {
        C = multiply(C, stringDecimal); // C *= stringDecimal;
        exponent --;
    }
    std::cout << "C: " << C << '\n';  
    string stringDecrypt = to_string(decrypter); // decrypt this! (MODIFY)
    int cSize = C.size(); 
    int decSize = stringDecrypt.size(); 

    exponent = e;
    string decryptedC = C;
    while (exponent > 0) {
        decryptedC = multiply(decryptedC, stringDecrypt); 
        exponent --;
       // std::cout << "decryptedC TEST: " << decryptedC << '\n';
    }
    string P = runDecrypt(stringDecimal, IITACREAB);
    std::cout << "P: " << P << '\n';
    std::cout << "M: " << M << '\n';
    std::cout << "C: " << C << '\n';
    std::cout << "e: " << e << '\n';
    std::cout << "p: " << p << '\n';
    std::cout << "q: " << q << '\n';
    std::cout << "n: " << n << '\n';

    return 0;
}