#pragma once
#ifndef _XBASE_TYPES_H
#define _XBASE_TYPES_H

#define XPLAY_HANDLE int
#define XSDK_HANDLE  int
#define SDK_HANDLE  int

#ifdef __APPLE__
#include <TargetConditionals.h>
#endif

#if (defined(TARGET_OS_IOS)|| defined(TARGET_OS_IPHONE))
#define OS_IOS
#define OS_MAC_OR_IOS
#define OS_NAME "IOS"
#endif

#if (defined(TARGET_OS_MAC)|| defined(TARGET_OS_IPHONE))
#define OS_MAC
#define OS_MAC_OR_IOS
#define OS_NAME "MAC"
#endif

#if (defined(WIN32)||defined(_WIN32) ||defined(__WIN32__)||defined(__NT__)||defined(_WIN64))
#define OS_WINDOWS
#define OS_NAME "Windows"
#else
#define OS_LINUX
#define OS_NAME "Linux"
#endif

////////////Windows系统定义////////////
#ifdef OS_WINDOWS
#define UI_HANDLE	HWND
#define LP_WND_OBJ	HWND
#define WM_FUN_MSG_ID   WM_USER + 0x500

//#define _WIN32_WINNT  0x0600
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#undef WIN32_LEAN_AND_MEAN

////////////IOS && MAC系统定义////////////
#elif (defined(OS_IOS)||defined(OS_MAC))
#define UI_HANDLE int
#define LP_WND_OBJ void*

////////////Android系统定义////////////
#elif defined(OS_ANDROID)
#define UI_HANDLE int
#include <jni.h>
#include <android/log.h>
#define LP_WND_OBJ void*

////////////其它Linux等系统定义////////////
#else
#define UI_HANDLE  void*
#define LP_WND_OBJ void*
#endif

#ifndef uint64
#ifdef OS_WINDOWS
typedef unsigned __int64	uint64;
#define FORMAT_INT64 "%I64d"
#else
typedef unsigned long long	uint64;
#define FORMAT_INT64 "%lld"
#endif
#endif

#ifndef int64
#ifdef OS_WINDOWS
typedef __int64	int64;
typedef unsigned __int64	uint64;
#else
typedef long long	int64;
typedef unsigned long long	uint64;
#endif
#endif

#ifndef Bool
typedef int Bool;
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif

#endif //_XBASE_TYPES_H
