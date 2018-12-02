// sub-process.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <algorithm>

void test_fun()
{
	int nSize = 1024 * 1920 * 3;
	char *p1 = (char*)malloc(nSize);
	memset(p1, 1, nSize);
	char *p2 = (char*)malloc(nSize);
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 1; j < 256; ++j)
		{
			//double tmp = atan(double(i) / double(j));
			//std::cout << "hello" << std::endl;
			//tmp = asin(double(i) / double(j));
			//tmp = exp(double(i) / j);
			
		}
		memcpy(p1, p2, nSize);
		
	}

}

int main(int argc, char *argv[])
{
	if (1 == argc)
	{
		printf("参数个数不正确\n");
		return 0;
	}
	int nCount = atoi(argv[1]);
	printf("nCount=%d\n",nCount);
	DWORD dwEnd, dwStart = GetTickCount();
	for (int i = 0; i < nCount; ++i)
	{
		test_fun();
		Sleep(5);
	}
	dwEnd = GetTickCount() - dwStart;
	printf("time=%d\n", dwEnd);
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
