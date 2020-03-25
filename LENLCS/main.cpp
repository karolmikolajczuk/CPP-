#include <iostream>
#include <string>
#include <cstring>


inline int maximum(int a, int b) { return (a > b)? a : b; }
/*
int LCS(const std::string& word1, const std::string& word2, const int& word1Len, const int& word2Len)
{
    if (word1Len == 0 || word2Len == 0) return 0; // there is no (no more) CS
    if (word1[word1Len-1] == word2[word2Len-1]) return 1 + LCS(word1, word2, word1Len-1, word2Len-1); // is common, check next
    else return maximum(LCS(word1, word2, word1Len-1, word2Len), LCS(word1, word2, word1Len, word2Len-1));
}
*/
int LCS(const std::string& word1, const std::string& word2, const int& lenW1, const int& lenW2, int lcs_arr[][1000])
{
    if (!lenW1 || !lenW2) return 0; // word1/word2 already ended
    if (lcs_arr[lenW1-1][lenW2-1] != -1) return lcs_arr[lenW1-1][lenW2-1]; // computed this already

    // are the same elements
    if (word1[lenW1-1] == word2[lenW2-1])
    {
        lcs_arr[lenW1-1][lenW2-1] = 1 + LCS(word1, word2, lenW1-1, lenW2-1, lcs_arr);

        return lcs_arr[lenW1-1][lenW2-1];
    }
    else
    {
        lcs_arr[lenW1-1][lenW2-1] = maximum(LCS(word1, word2, lenW1, lenW2-1, lcs_arr),
                                            LCS(word1, word2, lenW1-1, lenW2-1, lcs_arr));

        return lcs_arr[lenW1-1][lenW2-1];
    }
}

int main()
{
    unsigned short numOfTestCases;
    std::cin >> numOfTestCases;

    while(numOfTestCases--)
    {
        unsigned short word1Length, word2Length;
        std::string word1, word2;
        std::cin >> word1Length >> word1 >> word2Length >> word2;

        int arr[word1Length][1000];
        memset(arr, -1, sizeof(arr));

        std::cout << LCS(word1, word2, word1Length, word2Length, arr) << "\n";
        //std::cout << LCS(word1, word2, word1Length, word2Length) << "\n";
    }
}
