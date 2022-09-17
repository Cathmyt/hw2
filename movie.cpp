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
  key_set.insert(Genre_);
  key_set.insert(Rating_);
  key_set.insert(name_);
  return key_set;
}

std::string Movie::displayString() const
{
	//to create a string that contains the product info
  std::stringstream book_str;
  book_str << name_ << "\nGenre: " << Genre_;
  book_str << "\nRating: " << Rating_;
  book_str << "\n" << price_ << " " << qty_ << " left.";
	return book_str.str();
}

void Movie::dump(std::ostream& os) const
{
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << Genre_ << "\n" << Rating_ << std::endl;
}