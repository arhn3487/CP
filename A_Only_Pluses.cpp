#include <iostream>
#include <algorithm>

using namespace std;

int maxProductAfterIncrements(int a, int b, int c)
{
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        
        int increments = 5;
        int nums[3];
        cin>>nums[0]>>nums[1]>>nums[2];
        sort(nums, nums + 3);

        while (increments > 0)
        {
            if (nums[0] <= nums[1] && nums[0] <= nums[2])
            {
                nums[0]++;
            }
            else if (nums[1] <= nums[0] && nums[1] <= nums[2])
            {
                nums[1]++;
            }
            else
            {
                nums[2]++;
            }
            increments--;
        }
        cout<< nums[0] * nums[1] * nums[2]<<endl;
    }
    
}
