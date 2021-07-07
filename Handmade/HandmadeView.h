#pragma once

/*===================================================================#
| 'HandmadeView' source files last updated on 7 July 2021            |
#===================================================================*/

#include <memory>
#include <vector>
#include <glm.hpp>
#include "FreeCamera.h"
#include "Grid.h"
#include "Quad.h"

class CHandmadeView : public CView
{

protected: // create from serialization only

	CHandmadeView() noexcept;
	virtual ~CHandmadeView();
	DECLARE_DYNCREATE(CHandmadeView)

public:

	CHandmadeDoc* GetDocument() const;

	virtual void OnDraw(CDC* pDC);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:

	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

public:

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	DECLARE_MESSAGE_MAP()
	afx_msg void OnSize(UINT nType, int cx, int cy);

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();

	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);

	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);


private:

	bool m_isScreenInitialized;

	bool m_isLeftButtonDown;
	bool m_isRightButtonDown;
	bool m_isMiddleButtonDown;

	int m_mouseWheelMotion;
	glm::ivec2 m_mouseMotion;
	glm::ivec2 m_mousePosition;

	std::unique_ptr<Quad> m_quad;
	std::unique_ptr<Grid> m_grid;

	std::unique_ptr<FreeCamera> m_mainCamera;

	std::vector<std::unique_ptr<Object>> m_objects;
};

#ifndef _DEBUG  // debug version in HandmadeView.cpp
inline CHandmadeDoc* CHandmadeView::GetDocument() const
{
	return reinterpret_cast<CHandmadeDoc*>(m_pDocument);
}
#endif