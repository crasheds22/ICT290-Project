#ifndef AABBLINKED_LIST_H
#define AABBLINKED_LIST_H

//--------------------------------------------------------------------------------------

#include "AABBNode.h"
#include <gl/glut.h>

//--------------------------------------------------------------------------------------

/** @class AABBLinkedList.h
	@brief Linked list stores AABBNodes

	Linked List used to store nodes (AABBNode) which contain the co-ordinates of the
	boundings boxes which are used for the collsion detection.
	The program splits the world into four quadrants and creates a linked list to
	store the bounding box details for each

	@author Shay Leary
	@verion 01
	@date 2005

	@author Aaron Thomson, Mathew de Vene
	@ version 1.1 Added comments
	@date 2017
*/

class AABBLinkedList
{
public:
	/** @brief Constructor
	 */
	AABBLinkedList() {m_first = new AABBNode;}
	
	/** @brief Virtual destructor
	 */
	virtual ~AABBLinkedList() {Clear();}

	//----------------------------------------------------------------------------------

	/** @brief Clears memory
	 */
	void Clear();

	/** @brief 
	 */
	bool AddToStart (GLdouble maxX, GLdouble minX, GLdouble maxY,
				     GLdouble minY, GLdouble maxZ, GLdouble minZ);
	
	/** @brief
	 */
	void SetData(const int &ptrCount,
				 const GLdouble maxX, const GLdouble minX,
				 const GLdouble maxY, const GLdouble minY,
				 const GLdouble maxZ, const GLdouble minZ);

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------
	/** @brief Returns max x value
	 *
	 *	
	 */
	GLdouble GetMaxX (int ptrCount);
	///Getter for for MinX
	GLdouble GetMinX (int ptrCount);
	///Getter for MaxY
	GLdouble GetMaxY (int ptrCount);
	///Getter for Min Y
	GLdouble GetMinY (int ptrCount);
	///Getter for Max Z
	GLdouble GetMaxZ (int ptrCount);
	///Getter for Min Z
	GLdouble GetMinZ (int ptrCount);
	
	// Return size of list
	int GetListSize ();
	
	// Return the address of the link to the next node in the list
    AABBNode *GetNext () const {return m_first->GetNext();}
	// Return the address of the link to the first node in the list
	AABBNode *GetFirst() const {return m_first;}

//--------------------------------------------------------------------------------------

private:
	/// pointer to first node in list
	AABBNode *m_first;

	/// used to clear memory
	void Delete (AABBNode *before);

	/// Privatised copy constructor
	AABBLinkedList (const AABBLinkedList &ll) {};
	/// Privatised assignmen operator
	AABBLinkedList &operator = (const AABBLinkedList &ll) {};
};

#endif

//--------------------------------------------------------------------------------------