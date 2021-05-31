#include <iostream>
#include <set>

using namespace std;

int main()
{
  multiset<int> myMultiset;
  myMultiset.insert(3);
  myMultiset.insert(3);
  myMultiset.insert(1);
  cout << "myMultiset:" << endl;
  for (auto x: myMultiset)
  {
    cout << x << endl;
  }
  auto minVal = *(myMultiset.begin());
  auto maxVal = *(--myMultiset.end());
  cout << "minVal" << minVal << endl; //output 1
  cout << "maxVal" << maxVal << endl; //output 3
  return 0;
}
