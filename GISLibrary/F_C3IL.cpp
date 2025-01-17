#include "stdafx.h"
#include "F_C3IL.h"
#include "C3IL.h"
#include "ISO8211Fuc.h"
#include "NonPrintableCharacter.h"

F_C3IL::F_C3IL()
{

}

F_C3IL::~F_C3IL()
{
	for (auto itor = m_arr.begin(); itor != m_arr.end(); itor++)
		delete *itor;
}

void F_C3IL::ReadField(BYTE *&buf)
{
	m_vcid = *(buf++);
	while (*buf != 0x1E)
	{
		C3IL *cont = new C3IL();
		cont->m_ycoo = buf2int(buf, 4);
		cont->m_xcoo = buf2int(buf, 4);
		cont->m_zcoo = buf2int(buf, 4);
		m_arr.push_back(cont);
	}
}

void F_C3IL::ReadField(BYTE *&buf, int loopCnt)
{
	m_vcid = *(buf++);
	for (int i = 0; i < loopCnt; i++)
	{
		C3IL *cont = new C3IL();
		cont->m_ycoo = buf2int(buf, 4);
		cont->m_xcoo = buf2int(buf, 4);
		cont->m_zcoo = buf2int(buf, 4);
		m_arr.push_back(cont);
	}
}

bool F_C3IL::WriteField(CFile* file)
{
	file->Write(&m_vcid, 1);

	for (auto i = m_arr.begin(); i != m_arr.end(); i++)
	{
		file->Write(&(*i)->m_ycoo, 4);
		file->Write(&(*i)->m_xcoo, 4);
		file->Write(&(*i)->m_zcoo, 4);
	}

	file->Write(&NonPrintableCharacter::fieldTerminator, 1);

	return true;
}


int F_C3IL::GetFieldLength()
{
	unsigned len = 0;
	len++;
	for (auto itor = m_arr.begin(); itor != m_arr.end(); itor++)
	{
		len += C3IL::GetSize();
	}
	return ++len;
}