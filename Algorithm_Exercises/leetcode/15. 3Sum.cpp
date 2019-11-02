//Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0 ? Find all unique triplets in the array which gives the sum of zero.
//
//Note :
//
//	The solution set must not contain duplicate triplets.
//
//	Example :
//
//	Given array nums = [-1, 0, 1, 2, -1, -4],
//
//	A solution set is :
//[
//	[-1, 0, 1],
//	[-1, -1, 2]
//]

#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
using std::string;
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> result;
	std::sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size();i++)
	{
		int left = i+1;
		int right = nums.size() - 1;
		//�������λ���ظ�������
		while (i + 1 < nums.size())
		{
			if (nums[i + 1] == nums[i])
				i++;
			else
				break;
		}
		while (left < right)
		{
			int one = nums[left];
			int two = nums[right];
			int three = nums[i];
			int r = one + two + three;
			if (r== 0)
			{
				result.push_back({ one,two,three });
				//�����ظ������֣�����ѭ������
				while (left + 1 < nums.size())
				{
					if (nums[left + 1] == nums[left])
						left++;
					else
						break;
				}
				while (right - 1 >= 0)
				{
					if (nums[right - 1] == nums[right])
						right--;
					else
						break;
				}
			}
			//����ܺʹ���0��˵����Ҫ����������ֵ����֮����������ֵ��
			if (r > 0)
				right--;
			else if (r < 0)
				left++;
			else {
				left++;
				right--;
			}
		}
	}
	return result;
}

int main()
{
	auto v = vector<int>{ -4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0 };
	for (auto a : threeSum(v))
	{
		for (int c : a)
		{
			std::cout << c << " ";
		}
		std::cout << std::endl;
	}
}