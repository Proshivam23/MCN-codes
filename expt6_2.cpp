#include <iostream>
#include <string>

using namespace std;

// Function to perform XOR operation between two binary strings
string xor1(string a, string b) {
    string result = "";
    int n = b.length();
    for (int i = 1; i < n; i++) {
        result += (a[i] == b[i]) ? "0" : "1";
    }
    return result;
}

// Function to perform modulo-2 division
string mod2div(string dividend, string divisor) {
    int pick = divisor.length();
    string tmp = dividend.substr(0, pick);
    int n = dividend.length();

    while (pick < n) {
        if (tmp[0] == '1') {
            tmp = xor1(divisor, tmp) + dividend[pick];
        } else {
            tmp = xor1(string(pick, '0'), tmp) + dividend[pick];
        }
        pick += 1;
    }

    if (tmp[0] == '1') {
        tmp = xor1(divisor, tmp);
    } else {
        tmp = xor1(string(pick, '0'), tmp);
    }

    return tmp;
}

// Function to encode data using the provided key
void encodeData(string data, string key) {
    int l_key = key.length();
    string appended_data = data + string(l_key - 1, '0');
    string remainder = mod2div(appended_data, key);
    string codeword = data + remainder;
    cout << "Remainder: " << remainder << "\n";
    cout << "Encoded Data (Data + Remainder): " << codeword << "\n";
}

// Function to simulate the receiver side and check for errors
void receiver(string data, string key) {
    string currxor = mod2div(data.substr(0, key.size()), key);
    int curr = key.size();

    while (curr != data.size()) {
        if (currxor.size() != key.size()) {
            currxor.push_back(data[curr++]);
        } else {
            currxor = mod2div(currxor, key);
        }
    }

    if (currxor.size() == key.size()) {
        currxor = mod2div(currxor, key);
    }

    if (currxor.find('1') != string::npos) {
        cout << "There is some error in data" << endl;
    } else {
        cout << "Correct message received" << endl;
    }
}

int main() {
    string data, key;
    cout << "Sender side\n";
    cout << "Enter the Data: ";
    cin >> data;
    cout << "Enter the Generator: ";
    cin >> key;

    encodeData(data, key);

    cout << "\nReceiver side\n";
    string transmitted_data = data + mod2div(data + string(key.size() - 1, '0'), key);
    receiver(transmitted_data, key);

    return 0;
}
