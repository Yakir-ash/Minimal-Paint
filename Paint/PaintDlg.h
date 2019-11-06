
// PaintDlg.h : header file
//

#pragma once

#include "MyShape.h"
#include "MyEllipse.h"
#include "MyRectangle.h"
#include "MyCircle.h"
#include <vector>

using namespace std;

// CPaintDlg dialog
class CPaintDlg : public CDialogEx
{
// Construction
public:
	CPaintDlg(CWnd* pParent = NULL);							// standard constructor

// Dialog Data
	enum { IDD = IDD_PAINT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);			// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// Mouse Events
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

	//shape events
	afx_msg void OnBnClickedRadio1();					// Selected Circle Shape
	afx_msg void OnBnClickedRadio2();					// Selected Rectangle Shape
	afx_msg void OnBnClickedRadio3();					// Selected Ellipse Shape

	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

	CSliderCtrl m_red;								// Slider for R-Color
	CSliderCtrl m_green;							// Slider for G-Color
	CSliderCtrl m_blue;								// Slider for B-Color



private:
	int shapeType;												// Shape Type => Circle, Rectangle or Ellipse
	virtual void OnOK();										// Save Event
	bool isPressed;												// Flag for Mouse pressed
	CPoint start;												// Start Position of Mouse 
	CPoint end;													// End Position of Mouse
	CTypedPtrArray<CObArray, MyShape*> myShapes;				// Shape List

	int nCurShape;												// Current Shape for Drawing
	int nSelected;												// Selectected Shape for Moving
	bool bDrawing;												// Flag for Drawing , true=> Drawing Status, false=> Moving Status
	
public:
	afx_msg void OnBnClickedButton1();							// Undo Event
	afx_msg void OnBnClickedButton2();							// Redo Event
	afx_msg void OnBnClickedCancel();							// Exit Event
	afx_msg void OnBnClickedButton3();							// Move Event
	afx_msg void OnBnClickedLoadb();                            // Load Event
	afx_msg void OnBnClickedNewb();								// New Event
};
