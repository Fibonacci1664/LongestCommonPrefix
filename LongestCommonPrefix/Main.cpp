#include<iostream>
#include <vector>
#include<algorithm>

std::string longestCommonPrefix(std::vector<std::string>& strs)
{
    // If there is only one element in the vector, then this is the LCP, so return that
    if (strs.size() == 1)
    {
        return strs[0];
    }

    // Otherwise, do this
    // Put into alphabetical order
    std::sort(strs.begin(), strs.end());

    // Make first word the longest prefix
    std::string firstWord = strs[0];
    std::string lastWord = strs[strs.size() - 1];
    std::string result = "";
    int loopLimit = 0;
    
    // Make sure we're not looping more times than letters available
    if (firstWord.size() >= lastWord.size())
    {
        loopLimit = lastWord.size();
    }
    else
    {
        loopLimit = firstWord.size();
    }

    for (int j = 0; j < loopLimit; ++j)
    {
        if (firstWord[j] != lastWord[j])
        {
            break;
        }
        else
        {
            result += firstWord[j];
        }
    }

    return result;
}

int main()
{
    // TEST CASES
    //std::vector<std::string> inputVec = { "flower", "flow", "flight" };
    //std::vector<std::string> inputVec = { "reflower", "flow", "flight" };
    //std::vector<std::string> inputVec = { "flower", "flower", "flower", "flower" };
    //std::vector<std::string> inputVec = { "cir", "car" };
    std::vector<std::string> inputVec = { "abab", "aba", "abc" };

    std::string outputResult = longestCommonPrefix(inputVec);

    std::cout << outputResult << '\n';

	return 0;
}