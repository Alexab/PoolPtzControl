#pragma once
#ifndef JOBJECT_H
#define JOBJECT_H
#include <iostream>


#ifdef __APPLE__
#include <TargetConditionals.h>
#endif

#if (defined(TARGET_OS_IOS)|| defined(TARGET_OS_IPHONE))
#define OS_IOS
#define OS_MAC_OR_IOS
#endif

#if (defined(TARGET_OS_MAC)|| defined(TARGET_OS_IPHONE))
#define OS_MAC
#define OS_MAC_OR_IOS
#endif

#if (defined(WIN32)||defined(_WIN32) ||defined(__WIN32__)||defined(__NT__)||defined(_WIN64))
#define OS_WINDOWS
#else
#define OS_LINUX
#endif


#if defined(OS_LINUX) || defined(OS_IOS) || defined(OS_MAC) || defined(_LIB)
#define XJSON_API
#define XJSON_TEMPLATE
#define CALLBACK
#else
#ifdef XJSON_EXPORTS
#define XJSON_API __declspec(dllexport)
#define XJSON_TEMPLATE __declspec(dllexport)
#else
#define XJSON_API __declspec(dllimport)
#define XJSON_TEMPLATE
#endif
#define CALLBACK __stdcall
#endif

#define NS_NETSDK_CFG_BEGIN namespace XSDK_CFG{
#define NS_NETSDK_CFG_END }
#define USE_NS_NETSDK_CFG using namespace XSDK_CFG;

typedef void* PJSON_DATA;
typedef void* PJSON_STRING;

/// <summary>
/// 自实现简单动态数组
/// 原因：使用std:vector或list或array等在不同的SDK编译版本间使用会有兼容问题
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
class XJSON_TEMPLATE CJList
{
public:
	CJList<T>()
		:_pDatas(NULL)
		, _nNextIndex(0)
		, _nSize(0)
		, _nBufferSize(0)
	{
	}

	~CJList<T>()
	{
		clear();
	}

	T* operator[](const int& i)
	{
		T*& pItem = point(i);
		if (!pItem)
		{
			pItem = new T();
		}
		return pItem;
	}

	int size() { return _nSize; }

	int clear()
	{
		if (_pDatas)
		{
			for (int i = 0; i < _nSize; i++)
			{
				T*& pItem = point(i);
				if (pItem)
				{
					delete pItem;
					pItem = NULL;
				}
			}
			free(_pDatas);
			_pDatas = NULL;
			_nSize = 0;
			_nBufferSize = 0;
			_nNextIndex = 0;
		}
		return 0;
	}

	int set_size(int nSize)
	{
		if (nSize <= _nBufferSize)
		{
			return 0;
		}

		if (_pDatas)
		{
			_pDatas = (T**)realloc(_pDatas, sizeof(T*) * nSize);
			memset((char*)_pDatas + sizeof(T*) * _nBufferSize, 0, sizeof(T*) * (nSize - _nBufferSize));
		}
		else
		{
			_pDatas = (T**)malloc(sizeof(T*) * nSize);
			memset((char*)_pDatas, 0, sizeof(T*) * nSize);
		}
		_nBufferSize = nSize;
		return 0;
	}

	T*& point(const int& i)
	{
		// 超过存储时，先新创建存储空间
		if (i >= _nBufferSize)
		{
			_nSize = i + 1;

			// 预开辟4个空间，防止频繁realloc
			set_size(i + 4);
		}

		if (i >= _nSize)
		{
			_nSize = i + 1;
		}

		return _pDatas[i];
	}

private:
	int _nNextIndex;
	T** _pDatas;
	int _nSize;
	int _nBufferSize;
};

class JObject;
class XJSON_API CJObjectList
{
public:
	CJObjectList();
	~CJObjectList();
	JObject* operator[](const int& i);
	int size();
	int clear();
	int push_back(JObject* pValue);
	int set_size(int nSize);
	JObject*& point(const int& i);

private:
	int _nNextIndex;
	JObject** _pDatas;
	int _nSize;
	int _nBufferSize;
};

class XJSON_API JObject
{
public:
	JObject(JObject* pParent = NULL, const char* szName = "");
	virtual ~JObject(void);

public:
	virtual int Parse(const char* szJson);
	virtual int Parse(PJSON_DATA pParent, int index = -1);
	virtual const char* ToString();
	virtual const char* Name();
	virtual void SetName(const char* nm);

	virtual int ToInt();
	virtual bool ToBool();
	virtual int SetValue(const char* szValue);
	virtual int SetValue(bool bValue);
	virtual int SetValue(int nValue);
	virtual JObject* NewChild();

	virtual int AddChild(JObject* pNew);
	virtual int DelChild(const char* szName);
	virtual char* GetChannelName(int nChannelNo, const char* szStrName, char* pOutChannelName);
	virtual int GetBoolOfObjs(const char* szKeys, int nDefValue = 0);

	void JSON_SetParent(PJSON_DATA pParent);
	int JSON_AddToArray(JObject* pChild);
	int JSON_DelFromArray(int nIndex);

	virtual int InitArraySize(int nArraySize);
	virtual JObject* GetArrayItem(int nIndex);
	virtual int PushChildItem(JObject* pItem);

private:
	//不支持拷贝&拷贝构造函数
	const JObject& operator =(const JObject& object)
	{
		return object;
	}
	JObject(const JObject& object)
	{
	}

protected:
	virtual void Clear();

protected:
	char* name;
	PJSON_DATA _pJSData;
	PJSON_DATA _pRoot;
	CJObjectList* _pChilds;
	PJSON_STRING _sJsonReslt;
};


class XJSON_API JIntObj : public JObject
{
public:
	JIntObj(JObject* pParent = NULL, const char* szName = "");
	virtual ~JIntObj(void);

public:
	int Value();
	virtual void operator=(const int nValue);
};

class XJSON_API JDoubleObj : public JObject
{
public:
	JDoubleObj(JObject *pParent = NULL, const char *szName = "");
	virtual ~JDoubleObj(void);

public:
	double Value();
	virtual void operator=(const double nValue);
};

class XJSON_API JStrObj : public JObject
{
public:
	JStrObj(JObject *pParent = NULL, const char *szName = "");
	virtual ~JStrObj(void);

public:
	const char *Value();
	virtual void operator=(const char *szValue);

protected:
	void *_sValue;
};

class XJSON_API JIntHex : public JStrObj
{
public:
	JIntHex(JObject *pParent = NULL, const char *szName = "");
	virtual ~JIntHex(void);
	int SetValue(bool bValue);
	int SetValue(int nValue);
	int ToInt();

public:
	int Value();
	virtual void operator=(int);
};

class XJSON_API JBoolObj : public JObject
{
public:
	JBoolObj(JObject *pParent = NULL, const char *szName = "");
	virtual ~JBoolObj(void);

public:
	bool Value();
	virtual void operator=(const bool bValue);
};

template <class T>
class XJSON_TEMPLATE JObjArray : public JObject
{
public:
	JObjArray(JObject* pParent = NULL, const char* szName = "") :
		JObject(pParent, szName)
	{
	};
	virtual ~JObjArray(void) { Clear(); };

private:
	//不支持拷贝&拷贝构造函数
	const JObjArray& operator =(const JObjArray& object)
	{
		return object;
	}
	JObjArray(const JObjArray& object)
	{
	}

public:
	T& operator[] (const int index)
	{
		return *_arrayItems[index];
	}

	virtual int InitArraySize(int nArraySize)
	{
		_arrayItems.set_size(nArraySize);
		return 0;
	}

	virtual JObject* GetArrayItem(int nIndex)
	{
		return _arrayItems[nIndex];
	}

	int Size()
	{
		return (int)_arrayItems.size();
	}

protected:
	void Clear()
	{
		_arrayItems.clear();
		if (_pChilds)
		{
			_pChilds->clear();
		}
		JObject::Clear();
	}

protected:
	CJList<T> _arrayItems;
};


template <class T>
class XJSON_TEMPLATE JObjArrayObject : public JObject
{
public:
	JObjArrayObject(JObject* pParent = NULL, const char* szName = "") :
		JObject(NULL, ""),
		objs(this, szName)
	{
	}
	virtual ~JObjArrayObject(void)
	{
	}

private:
	//不支持拷贝&拷贝构造函数
	const JObjArrayObject& operator =(const JObjArrayObject& object)
	{
		return object;
	}
	JObjArrayObject(const JObjArrayObject& object)
	{
	}

public:
	JObjArray<T> objs;
};

#endif //JOBJECT_H
