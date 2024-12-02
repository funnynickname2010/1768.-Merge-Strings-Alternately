#include <string>
#include <utility>
#include <iostream>

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {

        std::string result = "";
        std::string buffer = "";
        size_t count1 = 0, count2 = 0, j = 0;
        
        /*Cycle for both words*/
        while ((count1 <= std::min(word1.size(), word2.size())) && 
            (count2 <= std::min(word1.size(), word2.size()))) {

            if (j % 2 == 0) {
                buffer = word1.at(count1);
                count1++;
            }
            else {
                buffer = word2.at(count2);
                count2++;
            }

            j++;
            result.append(buffer);
        }

        /*Cycle for when one word is over*/
        size_t i = 0;
        while (i < ((std::max(word1.size(), word2.size()))
            - (std::min(word1.size(), word2.size())) + 1)) {

            if (word2.size() == (std::max(word1.size(), word2.size()))) {
                buffer = word2.at(count1);
                count1++;
            }
            else {
                buffer = word1.at(count2);
                count2++;
            }

            result.append(buffer);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    std::string word1 = "abc";
    std::string word2 = "123";

    std::cout << sol.mergeAlternately(word1, word2);
}