//leetcode22，删除数组元素
int removeElement(int* nums, int numsSize, int val){
	int* src = nums;
	int* dest = nums;
	while (numsSize--)
	{
		if (*src != val)
		{
			*dest++ = *src++;
		}
		else
			src++;
	}
	return dest - nums;
}

//leetcode88,合并数组 
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int end = m + n - 1;
	int end1 = m - 1;
	int end2 = n - 1;
	while (end1 >= 0 && end2 >= 0)
	{
		if (nums1[end1]>nums2[end2])
		{
			nums1[end] = nums1[end1];
			end1--;
		}
		else
		{
			nums1[end] = nums2[end2];
			end2--;
		}
		end--;
	}
	while (end2 >= 0)
	{
		nums1[end] = nums2[end2];
		end2--;
		end--;
	}
}