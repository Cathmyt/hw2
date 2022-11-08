#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
	typename std::set<T>::iterator it;
	std::set<T> inter_set;
	for (it = s1.begin(); it != s1.end(); ++it) {
    if (s2.find(*it) != s2.end()) {
			inter_set.insert(*it);
    }
  }
  return inter_set;
}

template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
	typename std::set<T>::iterator it_1;
	typename std::set<T>::iterator it_2;
	std::set<T> union_set;
	for (it_1=s1.begin(); it_1!=s1.end(); ++it_1){
		union_set.insert(*it_1);
	}
	for(it_2=s2.begin(); it_2!=s2.end(); ++it_2){
		union_set.insert(*it_2);
	}
	return union_set;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
