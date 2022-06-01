#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol153;

/*
Input: [3,4,5,1,2]
Output: 1
*/

tuple<vector<int>, int>
testFixture1()
{
  auto input = vector<int>{3, 4, 5, 1, 2};
  return make_tuple(input, 1);
}

/*
Input: [4,5,6,7,0,1,2]
Output: 0
*/

tuple<vector<int>, int>
testFixture2()
{
  auto input = vector<int>{4, 5, 6, 7, 0, 1, 2};
  return make_tuple(input, 0);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << get<1>(f) << endl;
  Solution sol;
  cout << sol.findMin(get<0>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see: " << get<1>(f) << endl;
  Solution sol;
  cout << sol.findMin(get<0>(f)) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}