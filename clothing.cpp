#include "clothing.h"
#include <sstream>

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string Size, const std::string Brand) :
    Clothing::Product(category, name, price, qty),
		Size_(Size),
		Brand_(Brand)
{
	
}

Clothing::~Clothing()
{

}

std::set<std::string> Clothing::keywords() const
{
  std::set<std::string> key_set;
  //returns the appropriate keywords to index the product
  key_set.insert(Size_);
  key_set.insert(Brand_);
  key_set.insert(name_);
  return key_set;
}

std::string Clothing::displayString() const
{
	//to create a string that contains the product info
  std::stringstream book_str;
  book_str << name_ << "\nSize: " << Size_;
  book_str << "\nBrand: " << Brand_;
  book_str << "\n" << price_ << " " << qty_ << " left.";
	return book_str.str();
}

void Clothing::dump(std::ostream& os) const
{
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << Size_ << "\n" << Brand_ << std::endl;
}