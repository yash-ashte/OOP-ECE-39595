#include <iostream>
#include <vector>
#include <string>
#include <list>

using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::string;

bool IsOdd(int i){
  int remain = i%2;
  if(remain)
    return true;
  else
    return false;
}

bool IsEven(int i){
  int remain = i%2;
  if(remain)
    return false;
  else
    return true;
}

bool IsGreater5(int i){
  if(i > 5)
    return true;
  else
    return false;
}

bool StrMatch(string i){
  if(i == "Tue")
    return true;
  else
    return false;
}

class GreaterThan {
    private:
        int threshold;
    public:
        explicit GreaterThan(int threshold) {}
        bool operator()(int x){
            return x > threshold;
        }

};

// Step 1 TODO: Implement MatchCond for step 1 here

void MatchCond(bool (*pred)(int)){
    for (int i = 1; i <= 10; i++)
    {
        if (pred(i))
        {
           std::cout << i << " ";
        }
        
    }
    std::cout << std::endl;
    
}

// Step 2 TODO: Implement find_if for step 2 here
template <typename iter>
iter find_if(iter start, iter end, bool (*pred)(int)){
    while (start != end)
    {
        if (pred(*start))
        {
            return start;
        }
        ++start;
        
    }
    return start;
}

// Step 3 TODO: Implement find_if for step 3 here
template <typename iter, typename T>
iter find_if(iter start, iter end, bool (*pred)(T)){
    while (start != end)
    {
        if (pred(*start))
        {
            return start;
        }
        ++start;
        
    }
    return start;
}

template<typename Iter>
void matchResult(Iter match, Iter end){
  if(match != end){
    cout << "First Match: " << *match << endl;
  }
  else{
    cout << "No Match: " << endl;
  }
}

int main() {

  // Step 1 TODO: invoke MatchCond on isOdd, isEven, and isGreater5
  MatchCond(IsOdd);
  MatchCond(IsEven);
  MatchCond(IsGreater5);

  // If Step 2 done correctly the following code from lines 63-90 will compile and run successfully
  vector<int> vec = {2,14,7,9,16,3};
  list<int> lst = {1,7,3,9,5};

  vector<int>::iterator p;
  p = find_if(vec.begin(), vec.end(),IsOdd);
  cout << "Vec:IsOdd: ";
  matchResult(p,vec.end());

  p = find_if(vec.begin(), vec.end(),IsEven);
  cout << "Vec:IsEven: ";
  matchResult(p,vec.end());

  p = find_if(vec.begin(), vec.end(),IsGreater5);
  cout << "Vec:IsGreater5: ";
  matchResult(p,vec.end());

  list<int>::iterator q;
  q = find_if(lst.begin(), lst.end(),IsOdd);
  cout << "List:IsOdd: ";
  matchResult(q,lst.end());

  q = find_if(lst.begin(), lst.end(),IsEven);
  cout << "List:IsEven: ";
  matchResult(q,lst.end());

  q = find_if(lst.begin(), lst.end(),IsGreater5);
  cout << "List:IsGreater5: ";
  matchResult(q,lst.end());

  // If Step 3 done correctly the following code will compile and run successfully
  vector<string> vecstr = {"Mon","Tue","Wed"};
  vector<string>::iterator strIter;
  strIter = find_if(vecstr.begin(), vecstr.end(),StrMatch);
  cout << "Vector:String:StrMatch ";
  matchResult(strIter,vecstr.end());

  list<string> liststr = {"Mon","Wed","Fri"};
  list<string>::iterator listStrIter;
  listStrIter = find_if(liststr.begin(), liststr.end(),StrMatch);
  cout << "List:String:StrMatch ";
  matchResult(listStrIter,liststr.end());

}