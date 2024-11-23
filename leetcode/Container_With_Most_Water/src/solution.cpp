#include <vector>

class Solution
{
public:
    int maxArea(std::vector<int> &height)
    {
        int i = 0;
        int j = height.size() - 1;
        auto fArea = [](const int h_i, const int h_j, int &&dist)
        {
            return h_i < h_j ? h_i * dist : h_j * dist;
        };

        auto ans = fArea(height[i], height[j], j - i);
        int area = 0;
        while (i < j)
        {
            if (height[i] <= height[j])
            {
                ++i;
            }
            else
            {
                --j;
            }
            area = fArea(height[i], height[j], j - i);
            if (area > ans)
                ans = area;
        }

        return ans;
    }
};