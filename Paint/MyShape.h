#pragma once
class MyShape : public CObject
{
public:
	DECLARE_SERIAL(MyShape)
	MyShape(void);
	virtual ~MyShape(void);

	//setters
	void setStart(CPoint p) { start = p; }				// Set StartMousePoint
	void setEnd(CPoint p) { end = p; }					// Set EndMousePoint	
	void setBg(COLORREF c) { bgColor = c; }				// Set Color of Shape

	//getters
	CPoint getStart() const { return start; }			// Get StartMousePoint
	CPoint getEnd() const { return end; }				// Get EndMousePoint
	COLORREF getBg() const { return bgColor; }			// Get Color of Shape
	
	virtual void draw(CDC *dc);							// Shape Drawing 
	virtual void innerDraw(CDC *dc) {}
	void Serialize(CArchive& archive);					// Save & Open

	virtual bool inHit(CPoint point);					// Check if the mouse click on a shape, or not
	void move(CPoint point);							// Move Shape as Mouse pointer
protected:
	CPoint start, end;									// Position of Start and End point
	COLORREF bgColor;									// Color of Shape
};
