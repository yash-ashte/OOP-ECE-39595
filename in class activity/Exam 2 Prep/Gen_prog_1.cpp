#include <iostream>
#include <list>
#include <vector>

using std::vector;
using std::list;
using std::cout;
using std::endl;

typedef vector<int>::iterator vecIter; // use this iterator typedef if you want
typedef list<int>::iterator listIter;  // use this iterator typedef if you want


// Step 1: implement sumvec function here
int sumvec(vecIter start, vecIter end) {
    int sum = 0;
    while (start != end)
    {
        sum += *start;
        ++start;
    }
    return sum;
}


// Step 2: implement sumlist function here
int sumlist(listIter start, listIter end) {
    int sum = 0;
    while (start != end)
    {
        sum += *start;
        ++start;
    }
    return sum;
}

// Step 3: implement sumgeneric function here
template <typename iter>
int sumgeneric(iter start, iter end) {
    int sum = 0;
    while (start != end)
    {
        sum += *start;
        ++start;
    }
    return sum;
}

// Step 4: implement accumulate function here
template <typename iter, typename paramType>
paramType accumulate(iter start, iter end, paramType def) {
    
    while (start != end)
    {
        def += *start;
        ++start;
    }
    return def;
}

// Make main compile and run correctly by implementing the aforementioned functions
// in Steps 1-4
// Output should be the following if succesful:
// 83 
// 40 
// VectorSum: 83 List Sum: 40
// VectorSum: 83 List Sum: 40
// VectorDoubleSum (0.0): 7.5 VectorDoubleSum (0): 6
// Vector String: How are you doing?
int main(){

  vector<int> vec {16,23,11,14,19};
  list<int> li  {11,14,8,7};

  int res=sumvec(vec.begin(),vec.end());
  cout << res << " " << endl;

  int res1=sumlist(li.begin(),li.end());
  cout << res1 << " " << endl;

  int res2=sumgeneric(vec.begin(),vec.end());
  int res3=sumgeneric(li.begin(),li.end());
  cout << "VectorSum: " << res2 << " List Sum: " << res3 << endl ;

  int res4=accumulate(vec.begin(),vec.end(),0);
  int res5=accumulate(li.begin(),li.end(),0);
  cout << "VectorSum: " << res4 << " List Sum: " << res5 << endl ;

  vector<double> vecD {1.5,2.8,3.2};
  list<double> liD  {1.1, 2.7, 3.9};

  std::string emptyString;
  vector<std::string> vecStr{ "How ", "are ", "you ", "doing? "};
  
  double res6=accumulate(vecD.begin(),vecD.end(),0.0); // Infers as a sum of doubles
  double res7=accumulate(vecD.begin(),vecD.end(),0);   // Infers as a sum of ints
  std::string res8=accumulate(vecStr.begin(),vecStr.end(),emptyString);

  cout << "VectorDoubleSum (0.0): " << res6 << " VectorDoubleSum (0): " << res7 << endl ;
  cout << "Vector String: " << res8;

}