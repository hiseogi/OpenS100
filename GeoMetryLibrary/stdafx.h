// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
#endif

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // Internet Explorer 4 ���� ��Ʈ�ѿ� ���� MFC �����Դϴ�.
#endif

#include <map>
#include <gdiPlus.h>
#pragma comment(lib, "gdiplus")
using namespace Gdiplus;

#include "..\\extlibs\\Clipper\\include\\clipper.hpp"

#ifndef _TEXTWHITEBACK	
	//#define _TEXTWHITEBACK	
#endif

#import <msxml4.dll>
#include "msxml.h"