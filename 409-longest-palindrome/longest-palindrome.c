int longestPalindrome(char* s) {
    int freq[128] = {0};

    // count frequency
    for (int i = 0; s[i]; i++) {
        freq[s[i]]++;
    }

    int length = 0;
    int oddFound = 0;

    for (int i = 0; i < 128; i++) {
        if (freq[i] % 2 == 0) {
            length += freq[i];
        } else {
            length += freq[i] - 1;
            oddFound = 1;
        }
    }

    if (oddFound) length += 1;

    return length;
}