#include <iostream>
#include <string>
using namespace std;

int b_size;

string binary_add(string a, string b) {
    int carry = 0;
    string result = "";
    for (int i = b_size - 1; i >= 0; --i) {
        int bit_a = a[i] - '0';
        int bit_b = b[i] - '0';
        int sum = bit_a + bit_b + carry;
        result = to_string(sum % 2) + result;
        carry = sum / 2;
    }
    // Handling overflow
    if (carry) {
        result = binary_add(result, string(b_size - 1, '0') + "1");
    }
    return result;
}

string complement(string s) {
    for (char &c : s) {
        c = (c == '0') ? '1' : '0';
    }
    return s;
}

string compute_checksum(string data) {
    string checksum = data.substr(0, b_size);
    for (int i = b_size; i < data.size(); i += b_size) {
        string block = data.substr(i, b_size);
        checksum = binary_add(checksum, block);
    }
    return complement(checksum);
}

int main() {
    int choice;
    string data;

    while (true) {
        cout << "\nChecksum\n1. Sender Side\n2. Receiver Side\n3. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Enter data stream: ";
                cin >> data;
                cout << "Enter block size: ";
                cin >> b_size;

                // Calculate checksum
                string checksum = compute_checksum(data);
                cout << "The checksum is: " << checksum << "\n";

                // Append the checksum to the data
                data += checksum;
                cout << "The data with checksum is: " << data << "\n";
                break;
            }
            case 2: {
                cout << "Enter data stream: ";
                cin >> data;
                cout << "Enter block size: ";
                cin >> b_size;

                // Separate checksum from data
                string received_checksum = data.substr(data.size() - b_size, b_size);
                data = data.substr(0, data.size() - b_size);

                // Verify checksum
                string calculated_checksum = compute_checksum(data + received_checksum);
                if (calculated_checksum == string(b_size, '0')) {
                    cout << "No error present\n";
                } else {
                    cout << "Error present in code\n";
                }
                break;
            }
            case 3:
                return 0;
            default:
                cout << "Enter a valid choice\n";
        }
    }
}
