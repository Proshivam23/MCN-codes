tring s;
    cout << "Enter string: ";
    cin >> s;

    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') // Corrected to compare with character '1' instead of integer 1
            cout << "________\t"; // Represents HIGH for character '1'
        else
            cout<<"\t";
    }
    cout<<endl;
    for (int i = 0; i < n; i++) {
        if(s[i]==1)
            cout<<"|";
        if (s[i] == '0') // Corrected to compare with character '1' instead of integer 1
            cout << "________\t"; // Represents HIGH for character '1'
        else
            cout<<"\t";
    }
    cout << endl;
