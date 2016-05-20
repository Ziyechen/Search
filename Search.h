#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

//在一个二维数组中，每一行、每一列都是递增的顺序排序，
//写一个函数在数组中查找一个整数是否存在

bool Find(int *arr, int rows, int cols, int x)
{
	assert(arr);

	int row = 0;
	int col = cols - 1;

	//同时查找一行和一列
	while (row < rows && col >= 0)
	{
		//从右上角开始找
		if (arr[row *cols + col] == x)
		{
			return true;
		}

		//如果该元素大于x，则剔除该列
		else if (arr[row * cols + col] > x)
		{
			col--;
		}

		//如果该元素小于x，则剔除该行
		else
		{
			row++;
		}
	}

	return false;
}

void test()
{
	int a[4][4] = { { 1, 2, 8, 9 },
	{ 2, 4, 9, 12 },
	{ 4, 7, 10, 13 },
	{ 6, 8, 13, 15 } };

	cout << Find((int*)a, 4, 4, 5) << endl;
	cout << Find((int*)a, 4, 4, 7) << endl;
}
