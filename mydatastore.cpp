#include "mydatastore.h"

MyDataStore::~MyDataStore() {
	std::vector<Product*>::iterator it_1;
  for (it_1 = products.begin(); it_1 != products.end(); ++it_1) {
    delete *it_1;
  }
	std::vector<User*>::iterator it_2;
  for (it_2 = users.begin(); it_2 != users.end(); ++it_2) {
    delete *it_2;
  }
}

//Adds a product to the data store
void MyDataStore::addProduct(Product* p) {
  products.push_back(p);
}

//Adds a user to the data store
void MyDataStore::addUser(User* u) {
  int pos = users.size();
  std::vector<Product*> temp_vec;
  users.push_back(u);
  users_map[users[pos]] = temp_vec;
}

/**
* Performs a search of products whose keywords match the given "terms"
*  type 0 = AND search (intersection of results for each term) while
*  type 1 = OR search (union of results for each term)
*/
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
  std::vector<Product*> result;
  std::set<Product*>::iterator it;
  int term_size = terms.size();
  std::vector<std::set<Product*>> keyword_vec = find_all(terms);
  std::set<Product*> temp_set = keyword_vec[0];
  if (type == 0) {
    for (int i = 1; i < term_size; i++) {
      temp_set = setIntersection(temp_set, keyword_vec[i]);
    }
    for (it = temp_set.begin(); it!=temp_set.end(); ++it) {
      result.push_back(*it);
    }
  }
  else if (type == 1) {
    for (int i = 1; i < term_size; i++) {
      temp_set = setUnion(temp_set, keyword_vec[i]);
    }
    for (auto it = temp_set.begin(); it!=temp_set.end(); ++it) {
      result.push_back(*it);
    }
  }
  return result;
}

//all keywords from terms
std::vector<std::set<Product*>> MyDataStore::find_all(std::vector<std::string>& terms) {
  std::vector<std::set<Product*>> result(terms.size(),std::set<Product*>{});
  std::set<std::string>::iterator it_a;
  std::set<std::string>::iterator it_b;
  std::set<std::string> temp_stringset_1;
  std::set<std::string> temp_stringset_2;
  std::string temp_string_1;
  std::string temp_string_2;
  for(int i = 0; i < int(products.size()); i++)
  {
    temp_stringset_1 = products[i]->keywords();
    for(it_a = temp_stringset_1.begin(); it_a!=temp_stringset_1.end(); ++it_a) {
      temp_string_1 = *it_a;
      std::set<std::string> temp_stringset_2 = parseStringToWords(temp_string_1);
      for(it_b = temp_stringset_2.begin(); it_b != temp_stringset_2.end(); ++it_b) {
        std::string temp_string_2 = *it_b;
        temp_string_2 = convToLower(temp_string_2);
        for(int j = 0; j < int(terms.size()); j++) {
          if(terms[j] == temp_string_2) {
            result[j].insert(products[i]);
          }
        }
      }
    }
  }
  return result;
}

/**
* Reproduce the database file from the current Products and User values
*/
void MyDataStore::dump(std::ostream& ofile) {
  ofile << "<products>" << std::endl;
  //product_category, price, quantity, category-specific-info
  int n = products.size();
  for (int i=0; i<n; i++) {
    products[i]->dump(ofile);
  }
  ofile << "</products>" << std::endl;
  ofile << "<users>" << std::endl;
  //username credit_amount type
  n = users.size();
  for (int i=0; i<n; i++) {
    users[i]->dump(ofile);
  }
  ofile << "</users>" << std::endl;
}

//ADD username search_hit_number
void MyDataStore::addCart(std::string name, int n, const std::vector<Product*>& hits) {
  int num = users.size();
  int i = 0;
  bool valid = false;
  User* temp_user;
  std::string temp_name;
  while (!valid && i<num-1) {
    temp_name = users[i]->getName();
    if (name == temp_name) {
      temp_user = users[i];
      valid = true;
    }
    i += 1;
  }
  if (!valid) {
    std::cout << "Invalid request" << std::endl;
  }
  else if (n<=0 || n>(int(hits.size())+1)) {
    std::cout << "Invalid request" << std::endl;
  }
  else {
    users_map[temp_user].push_back(hits[n-1]);
  }
}

//VIEWCART username
void MyDataStore::viewCart(std::string name) {
  int num = users.size();
  int i = 0;
  bool valid = false;
  User* temp_user;
  std::string temp_name;
  while (!valid && i<num-1) {
    temp_name = users[i]->getName();
    if (name == temp_name) {
      temp_user = users[i];
      valid = true;
    }
    i += 1;
  }
  if (!valid) {
    std::cout << "Invalid request" << std::endl;
  }
  else {
    //viewCart
    int cart_size = users_map[temp_user].size();
    for (int j=0; j<cart_size; j++) {
      users_map[temp_user][j]->dump(std::cout);
    }
  }
}

//BUYCART username 
void MyDataStore::buyCart(std::string name) {
  int num = users.size();
  int i = 0;
  bool valid = false;
  User* temp_user;
  std::string temp_name;
  while (!valid && i<num-1) {
    temp_name = users[i]->getName();
    if (name == temp_name) {
      temp_user = users[i];
      valid = true;
    }
    i += 1;
  }
  if (!valid) {
    std::cout << "Invalid request" << std::endl;
  }
  else {
    //buyCart
    int cart_size = users_map[temp_user].size();
    double temp_price;
    double temp_balance;
    std::vector<int> bought;
    for (int j=0; j<cart_size; j++) {
      temp_price = users_map[temp_user][j]->getPrice();
      temp_balance = temp_user->getBalance();
      if (users_map[temp_user][j]->getQty()>0) {
        if (temp_price <= temp_balance) {
          temp_user->deductAmount(temp_price);
          users_map[temp_user][j]->subtractQty(1);
          bought.push_back(j);
        }
      }
    }
    //remove from cart
    for (int j=bought.size()-1; j>=0; j--) {
      users_map[temp_user].erase(users_map[temp_user].begin()+bought[j]);
    }
  }
}
