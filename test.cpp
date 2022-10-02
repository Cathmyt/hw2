#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "product.h"
#include "db_parser.h"
#include "product_parser.h"
#include "util.h"
#include "mydatastore.h"

using namespace std;

//util.cpp
int main(int argc, char* argv[]) {
	if(argc < 2) {
        cerr << "Please specify a database file" << endl;
        return 1;
    }
	std::set<std::string>::iterator it;
	string rawWords = "Great Men and Women of Troy";
	std::set<std::string> try_set = parseStringToWords(rawWords);
	for (it=try_set.begin(); it!=try_set.end(); ++it) {
			cout << *it << endl;
	}
	return 0;
}
