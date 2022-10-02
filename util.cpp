#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    std::set<std::string> Words_set;
    std::string s;
    int len = 0;
		int curr = 0;
		rawWords = trim(rawWords);
    for (unsigned int i=0; i<rawWords.size(); i++) {
        if (ispunct(rawWords[i])==false && isspace(rawWords[i])==false) {
					len++;
				}
				else if (i == (rawWords.size()-1)) {
					if (len>=1) {
						s = rawWords.substr(curr, len+1);
						Words_set.insert(s);
					}
				}
				else {
					if (len>=2) {
						s = rawWords.substr(curr, len);
						Words_set.insert(s);
						len = 0;
					}
					else {
						len = 0;
					}
					curr = i + 1;
				}
    }
    return Words_set;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
