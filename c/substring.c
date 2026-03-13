#include <string.h>
#include <math.h>

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int maxLength = 0;
    int lastSeen[128];
    for (int i = 0; i < 128; i++) {
        lastSeen[i] = -1;
    }

    int left = 0;
    for (int right = 0; right < n; right++) {
        char current = s[right];
        if (lastSeen[current] >= left) {
            left = lastSeen[current] + 1;
        }
        lastSeen[current] = right;
        int currentWindowSize = right - left + 1;
        if (currentWindowSize > maxLength) {
            maxLength = currentWindowSize;
        }
    }
    
    return maxLength;
}
