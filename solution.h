
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <stack>

using namespace std;
namespace sol153
{

  class Solution
  {
  private:
    int _findMin(const vector<int> &nums, int l, int r);

  public:
    int findMin(vector<int> &nums);
  };
}
#endif