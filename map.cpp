#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int CONSIZE=10;
template <class Name, class Value>
class HashMap {
	private:
	struct node {
		pair<Name, Value> context;
		node *next;
	};
	
	node *context_array[CONSIZE];
	
	public:
	HashMap() {
		for(int i = 0; i < CONSIZE; i++) {
			context_array[i] = NULL;
		}
	}
	Value &operator[](Name opname) {
		return at(opname);
	}
	
	Value &at(Name name) {
		int hashval = 0; // Compute the hash value for this name, for now assume it is 0
		node *ptr = context_array[hashval];
		while(ptr != NULL) {
			cout <<"comparing "<<name<<" first "<<ptr->context.first<<endl;
			if(name == ptr->context.first) { // We found it
				break;
			} else {
			  cout << "ptr"<< ptr<<"next "<< ptr->next<<endl;
			  ptr = ptr->next;
			}
		}
		if(ptr == NULL) { // We need to create a new node, put it on the front of the list
			ptr = new node;
			cout << "new node "<< static_cast<void*>(&(ptr->context.second))<<endl;
			ptr->next = context_array[hashval];
			context_array[hashval] = ptr;
			ptr->context.first = name;
		}
		cout << "return "<< static_cast<void*>(&(ptr->context.second))<<endl;
		return(ptr->context.second);
	}
};
int main()
{
	
	HashMap <string, vector<string>> foo;
    vector <string> &rval = foo.at("Hello");
    cout << "Vector at "<<&rval<<" Size of vector "<<rval.size()<<endl;
    rval.push_back("Goodbye");
    cout << "Vector at "<<&rval<<" Size of vector "<<rval.size()<<endl;
    rval = foo.at("Hello");
    cout << "Vector at "<<&rval<<" Size of vector "<<rval.size()<<endl;
    foo["Hello"].push_back("Again");
    rval = foo.at("Hello");
    cout << "Vector at "<<&rval<<" Size of vector "<<rval.size()<<endl;
}
