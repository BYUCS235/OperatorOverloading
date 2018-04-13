# OperatorOverloading
In order to use your HashMap class, we will need to be able to put things into the map and take things out. One version of the maps lab created a map from a string to a vector of strings.  This version used the following syntax to access the map:
```c++
  map<string, vector<string>> wordmap;
  string state = "";
  for(list<string>::iterator it=lst.begin(); it !=lst.end(); it++) {
    wordmap[state].push_back(*it);
    state = *it;
  }
  
  srand(time(NULL)); // this line initializes the random number generated
                     // so you dont get the same thing every time
  state = "";
  for (int i = 0; i < 100; i++) {
    int ind = rand() % wordmap[state].size();
    cout << wordmap[state][ind] << " ";
    state = wordmap[state][ind];
  }
  cout << endl;
```
So, we need a way of introducing the square bracket syntax into our HashMap class.  For this exercise, we are going to create a class that does not use a hash, but keeps the keys in one vector and the values in another vector.  We will show you how to perform operator overloading in this implementation in hopes that it will help you in your final implementation.
