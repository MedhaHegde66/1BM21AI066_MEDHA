#include <iostream>
#include <vector>
#include <string>

const int ALPHABET_SIZE = 256;

std::vector<int> calculateShiftTable(const std::string& pattern) {
    std::vector<int> shiftTable(ALPHABET_SIZE, pattern.size());

    for (int i = 0; i < pattern.size() - 1; ++i) {
        shiftTable[pattern[i]] = pattern.size() - 1 - i;
    }

    return shiftTable;
}

int horspoolSearch(const std::string& text, const std::string& pattern) {
    int textSize = text.size();
    int patternSize = pattern.size();

    if (textSize < patternSize) {
        return -1; // Pattern can't be present in a smaller text
    }

    std::vector<int> shiftTable = calculateShiftTable(pattern);
    int i = patternSize - 1; // Index for text
    int j = patternSize - 1; // Index for pattern

    while (i < textSize) {
        if (text[i] == pattern[j]) {
            if (j == 0) {
                return i; // Pattern found
            }
            --i;
            --j;
        } else {
            i += shiftTable[text[i]];
            j = patternSize - 1;
        }
    }

    return -1; // Pattern not found
}

int main() {
    std::string text = "This is a sample text for testing the Horspool algorithm.";
    std::string pattern = "algorithm";

    int result = horspoolSearch(text, pattern);

    if (result != -1) {
        std::cout << "Pattern found at index " << result << std::endl;
    } else {
        std::cout << "Pattern not found in the text." << std::endl;
    }

    return 0;
}
