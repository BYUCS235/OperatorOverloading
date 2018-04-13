#include <iostream>
#include <vector>
using namespace std;
template <class Name, class Value>
class VectorMap {
  private:
	vector<Name> name_vector;
	vector <Value> value_vector;
	
  public:
	void printit() {
		for(int i = 0; i < name_vector.size(); i++) {
			cout << "name["<<i<<"]"<<name_vector[i]<<endl;
			cout << "value["<<i<<"]"<<value_vector[i]<<endl;
		}
	}
	Value &operator[](Name opname) {
		return at(opname);
	}
	Value &at(Name name) {
	    //cout << "in at() Name "<<name<<endl;
	    //cout << "NameSize "<<name_vector.size();
	    //cout << " ValueSize "<<name_vector.size();
		for(int i = 0; i < name_vector.size(); i++) {
			if(name_vector[i]==name) {
			    //cout << "in at() found "<<name<<" at "<<i<<" size "<<value_vector[i].size()<<endl;
			    //cout << "NameSize "<<name_vector.size();
			    //cout << " ValueSize "<<name_vector.size();
			    //cout << " valuevector "<< &value_vector[i]<<endl;
				return value_vector[i];
			}
		}
		// If it doesnt exist, create it.
		//cout << "in at() pushing Name "<<name<<endl;
		name_vector.push_back(name);
		Value emptyval;
		//cout << "in at() pushing Value "<<name<<endl;
		value_vector.push_back(emptyval);
		//cout << "valuevector "<<&(value_vector.back())<<endl;
		return value_vector.back();
	}
	void set(Name myName, Value myValue) {
		name_vector.push_back(myName);
		value_vector.push_back(myValue);
	}
};
