#include "stdafx.h"
#pragma once
#define EXPORT __declspec (dllexport)
#ifndef __DLL_H
#define __DLL_H
#ifdef __cplusplus
extern "C"
{
#endif
	EXPORT int  Function();
	class  MyClass
	{
	public:
		MyClass();
		static EXPORT int FunctionFromClass();
		~MyClass();
	};
	EXPORT int fun();
#ifdef __cplusplus
}
#endif
#endif