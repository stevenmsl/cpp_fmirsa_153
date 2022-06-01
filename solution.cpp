#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol153;
using namespace std;

/*takeaways
  - we need to take advantage of the fact that the array has been
    sorted so we can achieve the time complexity of O(logN) instead
    of O(N)
  - the key is to spot the location that is out of order using
    the approach simliar to binary search
    - [4,5,6,7,0,1,2]
      - we know it's out of order at nums[3] and nums[4]
      - you divide the array equally to find this location in O(logN) time
    - how do you know an array is sorted quickly? nums[0] < nums[n-1]
      [0,1,2,3,4,5,6,7]
      - rotate to the right you got [7,0,1,2,3,4,5,6], the biggest
        number will be in nums[0] so nums[0] > nums[n-1]
      - rotate to the left you got [1,2,3,4,5,6,7,0], the smallest
        number will be in nums[n-1] so nums[0] > nums[n-1]
*/

/* return the min element in the array */
int Solution::_findMin(const vector<int> &nums, int l, int r)
{
  /* if there is only one element, l will be the same as r
     - there is no need to determine if the array is sorted or not
       before finding the min element as a  min operation will suffice
  */
  if (l == r || l + 1 == r)
    return min(nums[l], nums[r]);

  /* it's sorted; return the very first element */
  if (nums[l] < nums[r])
    return nums[l];

  /* divide the array into two */
  auto mid = l + (r - l) / 2;

  return min(_findMin(nums, l, mid), _findMin(nums, mid + 1, r));
}

int Solution::findMin(vector<int> &nums)
{
  int n = nums.size();
  return _findMin(nums, 0, n - 1);
}