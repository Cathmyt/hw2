#include "book.h"
#include <sstream>

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string ISBN, const std::string Author) :
	Book::Product(category, name, price, qty),
  ISBN_(ISBN),
  Author_(Author)
{

}

Book::~Book()
{

}

std::set<std::string> Book::keywords() const
{
  std::set<std::string> key_set;
  //returns the appropriate keywords to index the product
  key_set.insert(Author_);
  key_set.insert(ISBN_);
  key_set.insert(name_);
  return key_set;
}

std::string Book::displayString() const
{
	//to create a string that contains the product info
  std::stringstream book_str;
  book_str << name_ << "\nAuthor: " << Author_;
  book_str << " ISBN: " << ISBN_;
  book_str << "\n" << price_ << " " << qty_ << " left.";
	return book_str.str(); 
}

void Book::dump(std::ostream& os) const
{
  Product::dump(os);
	os << ISBN_ << "\n" << Author_ << "\n";
}