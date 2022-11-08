#include "movie.h"
#include <sstream>

Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string Genre, const std::string Rating) :
    Movie::Product(category, name, price, qty),
		Genre_(Genre),
		Rating_(Rating)
{
	
}

Movie::~Movie()
{

}

std::set<std::string> Movie::keywords() const
{
  std::set<std::string> key_set;
  //returns the appropriate keywords to index the product
  key_set = parseStringToWords(Genre_);

	std::set<std::string> name_set;
  name_set = parseStringToWords(name_);

	key_set.insert(name_set.begin(), name_set.end());
	return key_set;
}

std::string Movie::displayString() const
{
	//to create a string that contains the product info
  std::stringstream book_str;
  book_str << name_ << "\nGenre: " << Genre_;
  book_str << " Rating: " << Rating_;
  book_str << "\n" << price_ << " " << qty_ << " left.";
	return book_str.str();
}

void Movie::dump(std::ostream& os) const
{
  Product::dump(os);
	os << Genre_ << "\n" << Rating_ << "\n"; 
}