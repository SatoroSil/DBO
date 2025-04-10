#pragma once

#include "TreePCPane.h"

/**
 * \ingroup ModelTool2
 * \brief Ż�� ���� Pane
 *
 * \date 2008-11-04
 * \author agebreak
 */
class CTreeVehiclePane : public CTreePCPane
{
	DECLARE_DYNCREATE(CTreeVehiclePane)

protected:
	CTreeVehiclePane();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CTreeVehiclePane();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()

public:
    static CTreeVehiclePane*    GetInstance() {return m_pInstance;}
    afx_msg void OnSetFocus(CWnd* pOldWnd);

protected:
    virtual void InitClass();

protected:
    static CTreeVehiclePane*    m_pInstance;

};


