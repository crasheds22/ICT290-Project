//  PlainNode.h
//  Header file for the PlainNode class
/**  Stores details for each plain.  Each node is stored in each link of the Plain Linked List

     @author Shay Leary
*/

#ifndef PLAINNODE_H
#define PLAINNODE_H

//--------------------------------------------------------------------------------------

#include <iostream>
#include <math.h>
#include <gl/glut.h>

class PlainNode
{

public:
	///Constructor
	PlainNode () {Clear();}
    virtual ~PlainNode () {Clear();}

	//----------------------------------------------------------------------------------

	void  Clear   ();

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------
	/// Get Type
	GLdouble GetType () {return m_type;}
	/// Get X start
	GLdouble GetXstart () {return m_xPlainStart;}
	/// Get X end
	GLdouble GetXend () {return m_xPlainEnd;}
	/// Get Y start
	GLdouble GetYstart () {return m_yPlainStart;}
	/// Get Y end
	GLdouble GetYend () {return m_yPlainEnd;}
	/// Get Z start
	GLdouble GetZstart () {return m_zPlainStart;}
	/// Get Z end
	GLdouble GetZend () {return m_zPlainEnd;}

    /// Return the address of the link to the next node in the list
    PlainNode *GetNext () const {return m_next;}

	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------
	/// Set attribute values
	void SetData(const int tempType,
				 const GLdouble tempXs, const GLdouble tempXe,
				 const GLdouble tempYs, const GLdouble tempYe,
				 const GLdouble tempZs, const GLdouble tempZe);

    /// Set the address of the link to the next node in the list
    void SetNext (PlainNode *next) {m_next = next;}

private:
    /// The address of the next node in the list
    PlainNode *m_next;

	/// Stores type of plain: (0: flat plane), (1: incline from z to y), (2: incline from x to y)
	GLdouble m_type;
	

	/// stores start and end co-ordinates of plane on x
	GLdouble m_xPlainStart, m_xPlainEnd;
	/// stores start and end co-ordinates of plane on y
	GLdouble m_yPlainStart, m_yPlainEnd;
	/// stores start and end co-ordinates of plane on z
	GLdouble m_zPlainStart, m_zPlainEnd;

	//----------------------------------------------------------------------------------

    // Privatised assignment operator
    PlainNode (const PlainNode &newNode) {};
	// Privatised copy constructor
	PlainNode &operator = (const PlainNode &newNode) {};
};

#endif

//--------------------------------------------------------------------------------------