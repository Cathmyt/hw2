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
	typename std::set<T>::iterator it_1;
	typename std::set<T>::iterator it_2;
	std::set<T> inter_set;
	it_1 = s1.begin();
	it_2 = s2.begin();
	while (it_1!=s1.end() && it_2!=s2.end()) {
		if (*it_1==*it_2) {
			inter_set.insert(*it_1);
			++it_1;
			++it_2;
		}
		else if (*it_1 < *it_2) {
			++it_1;
		}
		else if (*it_1 > *it_2){
			++it_2;
		}
		return inter_set;
	}
}

template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
	typename std::set<T>::iterator it_1;
	typename std::set<T>::iterator it_2;
	std::set<T> union_set;
	it_1 = s1.begin();
	it_2 = s2.begin();
	while (it_1!=s1.end() || it_2!=s2.end()) {
		if (it_1!=s1.end() && it_2!=s2.end()) {
			union_set.insert(*it_1);
			++it_1;
			union_set.insert(*it_2);
			++it_2;
		}
		else if (it_1!=s1.end()) {
			union_set.insert(*it_1);
			++it_1;
		}
		else if (it_2!=s2.end()){
			union_set.insert(*it_2);
			++it_2;
		}
		return union_set;
	}



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
