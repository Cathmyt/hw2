#include "util.h"
#include "datastore.h"
#include <map>

class MyDataStore : public DataStore {
	public:
		MyDataStore();
		~MyDataStore();
    //Adds a product to the data store
		void addProduct(Product* p);
    //Adds a user to the data store
		void addUser(User* u);
    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
		std::vector<std::set<Product*>> find_all(std::vector<std::string>& terms);
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
    /**
     * Reproduce the database file from the current Products and User values
     */
    void dump(std::ostream& ofile);
		//ADD username search_hit_number
		void addCart(std::string name, int n, const std::vector<Product*>& hits);
		//VIEWCART username
		void viewCart(std::string name);
		//BUYCART username 
		void buyCart(std::string name);
		
	private:
		std::map<User*, std::vector<Product*>> users_map;
		std::vector<User*> users;
		std::vector<Product*> products;
};