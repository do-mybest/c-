// thread-process.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <algorithm>
#include <vector>
#include <string>

#define NUM 5
#define COUNT 20

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

std::wstring CharToWchar(const char* c, size_t m_encode = CP_ACP)
{
	std::wstring str;
	int len = MultiByteToWideChar(m_encode, 0, c, strlen(c), NULL, 0);
	wchar_t*	m_wchar = new wchar_t[len + 1];
	MultiByteToWideChar(m_encode, 0, c, strlen(c), m_wchar, len);
	m_wchar[len] = '\0';
	str = m_wchar;
	delete m_wchar;
	return str;
}

void test_process()
{
	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;
	std::vector<HANDLE> vHandle;
	char param[100] = { 0 };
	_itoa_s(COUNT, param,10);
	char path[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, path);
	std::string strSubProcess = std::string(path) + "\\sub-process.exe";
	std::string strCmd = " " + std::string(param);
	for (int i = 0; i < NUM; ++i)
	{
		BOOL bRet=::CreateProcess(strSubProcess.c_str(),(char*)strCmd.c_str(), NULL, NULL, FALSE, NULL, NULL, NULL, &si, &pi);
		if (bRet)
		{
			vHandle.push_back(pi.hProcess);
		}
		else
		{
			DWORD error=GetLastError();
			printf("error=%d\n",error);
		}
		
	}
	

	WaitForMultipleObjects(NUM, &vHandle[0],true, INFINITE);
}

DWORD WINAPI ThreadFun(LPVOID p)
{
	DWORD dwEnd, dwStart = GetTickCount();
	for (int i = 0; i < COUNT; ++i)
	{
		test_fun();
		Sleep(5);
	}
	dwEnd = GetTickCount() - dwStart;
	std::cout << "线程消耗时间:" << dwEnd<<std::endl;

	return 0;
}

void test_thread()
{
	std::vector<HANDLE> vHandle;
	for (int i = 0; i < NUM; ++i)
	{
		DWORD  threadId;
		HANDLE hThread;
		hThread = CreateThread(NULL, 0, ThreadFun, 0, 0, &threadId); // 创建线程
		if(hThread)
		{
			vHandle.push_back(hThread);
		}
	}
	WaitForMultipleObjects(NUM, &vHandle[0], true, INFINITE);
}
int main()
{
	DWORD dwEnd, dwStart = GetTickCount();
	//test_process();
	test_thread();
	dwEnd = GetTickCount() - dwStart;

	std::cout << "消耗时间:" << dwEnd;
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
