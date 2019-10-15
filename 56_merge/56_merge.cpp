// 56_merge.cpp : 定义控制台应用程序的入口点。
//
/*
给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool ma(vector<int>& l1, vector<int>&l2)
{
	return l1[0] < l2[0];
}
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), ma);
		for (auto item : intervals)
		{
			for (auto it : item)
			{
				cout << it << " ";
			}
			cout << endl;
		}
		vector<vector<int>> res;
		for (int i=0;i<intervals.size();)
		{
			int j = i+1;
			vector<int> ans;
			int start = intervals[i][0];
			int end = intervals[i][1];
			while (1)
			{
				while (j<intervals.size()&&end >= intervals[j][1])
				{
					j++;
				}
				if (j<intervals.size()&&end >= intervals[j][0])
				{
					end = intervals[j][1];
					j++;
				}
				else
				{
					ans.push_back(start);
					ans.push_back(end);
					res.push_back(ans);
					break;
				}
			}
			i = j;
		}
		return res;
	}
};

int main()
{
	Solution s;

	vector<vector<int>> nums = {
		{1, 4},
		{0, 2},
		{3, 5},
		{15, 18} };
	vector<vector<int>> res = s.merge(nums);
	for (auto item:res)
	{
		for (auto it:item)
		{
			cout << it << " ";
		}
		cout << endl;
	}
    return 0;
}

