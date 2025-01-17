#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::string;

// Predicate functions
bool IsOdd(int i){
  return i % 2 != 0;
}

bool IsEven(int i){
  return i % 2 == 0;
}

bool IsGreater5(int i){
  return i > 5;
}

bool StrMatch(const string &i){
  return i == "Tue";
}

// Step 1: Implement MatchCond
void MatchCond(bool (*predicate)(int)) {
  for (int i = 1; i <= 10; ++i) {
    if (predicate(i)) {
      cout << i << " ";
    }
  }
  cout << endl;
}

// Step 2: Implement find_if for integers
template<typename Iter, typename Predicate>
Iter find_if(Iter start, Iter end, Predicate predicate) {
  for (Iter it = start; it != end; ++it) {
    if (predicate(*it)) {
      return it;
    }
  }
  return end;
}

// Helper function to display match results
template<typename Iter>
void matchResult(Iter match, Iter end){
  if(match != end){
    cout << "First Match: " << *match << endl;
  }
  else{
    cout << "No Match" << endl;
  }
}

class GreaterThan {
public:
    explicit GreaterThan(int threshold) : threshold_(threshold) {}

    bool operator()(int x) const {
        return x > threshold_;
    }

private:
    int threshold_;
};


int main() {
  // Step 1: Invoke MatchCond on IsOdd, IsEven, and IsGreater5
  cout << "MatchCond with IsOdd: ";
  MatchCond(IsOdd);

  cout << "MatchCond with IsEven: ";
  MatchCond(IsEven);

  cout << "MatchCond with IsGreater5: ";
  MatchCond(IsGreater5);

  // Step 2: Test find_if with integers
  vector<int> vec = {2, 14, 7, 9, 16, 3};
  list<int> lst = {1, 7, 3, 9, 5};

  auto p = find_if(vec.begin(), vec.end(), IsOdd);
  cout << "Vec:IsOdd: ";
  matchResult(p, vec.end());

  p = find_if(vec.begin(), vec.end(), IsEven);
  cout << "Vec:IsEven: ";
  matchResult(p, vec.end());

  p = find_if(vec.begin(), vec.end(), IsGreater5);
  cout << "Vec:IsGreater5: ";
  matchResult(p, vec.end());

  auto q = find_if(lst.begin(), lst.end(), IsOdd);
  cout << "List:IsOdd: ";
  matchResult(q, lst.end());

  q = find_if(lst.begin(), lst.end(), IsEven);
  cout << "List:IsEven: ";
  matchResult(q, lst.end());

  q = find_if(lst.begin(), lst.end(), IsGreater5);
  cout << "List:IsGreater5: ";
  matchResult(q, lst.end());

  // Step 3: Test find_if with strings
  vector<string> vecstr = {"Mon", "Tue", "Wed"};
  auto strIter = find_if(vecstr.begin(), vecstr.end(), StrMatch);
  cout << "Vector:String:StrMatch ";
  matchResult(strIter, vecstr.end());

  list<string> liststr = {"Mon", "Wed", "Fri"};
  auto listStrIter = find_if(liststr.begin(), liststr.end(), StrMatch);
  cout << "List:String:StrMatch ";
  matchResult(listStrIter, liststr.end());

  GreaterThan g10(10);
  cout << "GreaterThan(10) with 12: " << (g10(12) ? "True" : "False") << endl;
  cout << "GreaterThan(10) with 8: " << (g10(8) ? "True" : "False") << endl;

  return 0;
}
