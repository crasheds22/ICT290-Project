#ifndef AABBLINKED_LIST_H
#define AABBLINKED_LIST_H

//--------------------------------------------------------------------------------------

#include "AABBNode.h"
#include <gl/glut.h>

//--------------------------------------------------------------------------------------

/** @class AABBLinkedList
 *	@brief Linked list stores AABBNode
 *
 *	Header file for the AABBLinkedList class
 *	Linked List used to store nodes (AABBNode) which contain the co-ordinates of the 
 *	boundings boxes which are used for the collsion detection.
 *	The program splits the world into four quadrants and creates a linked list to
 *  store the bounding box details for each
 *
 *	@author Shay Leary
 *	@version 1
 *	@date March 2005
 */

//--------------------------------------------------------------------------------------

class AABBLinkedList
{
public:
	/* @brief constructor 
	 *
	 * creates pointer to first node 
	 */
	AABBLinkedList() {m_first = new AABBNode;}

	/** @brief destructor
	 */
	virtual ~AABBLinkedList() {Clear();}

	//----------------------------------------------------------------------------------

	/* @brief clears linked list and frees memory 
	 */
	void Clear();

	/**	@brief add a node to the start of the linked list 
	 *
	 *	@param GLdouble
	 *	@param GLdouble
	 *	@param GLdouble
	 *	@param GLdouble
	 *	@param GLdouble
	 *	@param GLdouble
	 */
	bool AddToStart (GLdouble maxX, GLdouble minX, GLdouble maxY, GLdouble minY, GLdouble maxZ, GLdouble minZ);
	
	/**	@brief set the values of the node data 
	 *
	 *	@param const int&
	 *	@param GLdouble
	 *	@param GLdouble
	 *	@param GLdouble
	 *	@param GLdouble
	 *	@param GLdouble
	 *	@param GLdouble
	 */
	void SetData(const int &ptrCount, const GLdouble maxX, const GLdouble minX,
				 const GLdouble maxY, const GLdouble minY, const GLdouble maxZ, const GLdouble minZ);

	/** @brief Returns max x value
	 *
	 *	From an index number, returns a maximum x value from the list
	 *
	 *	@param int
	 */
	GLdouble GetMaxX (int ptrCount);

	/** @brief Returns min x value
	*
	*	From an index number, returns a mainimum x value from the list
	*
	*	@param int
	*/
	GLdouble GetMinX (int ptrCount);

	/** @brief Returns max y value
	*
	*	From an index number, returns a maximum y value from the list
	*
	*	@param int
	*/
	GLdouble GetMaxY (int ptrCount);

	/** @brief Returns min y value
	*
	*	From an index number, returns a mainimum y value from the list
	*
	*	@param int
	*/
	GLdouble GetMinY (int ptrCount);

	/** @brief Returns max z value
	*
	*	From an index number, returns a maximum z value from the list
	*
	*	@param int
	*/
	GLdouble GetMaxZ (int ptrCount);

	/** @brief Returns min z value
	*
	*	From an index number, returns a mainimum z value from the list
	*
	*	@param int
	*/
	GLdouble GetMinZ (int ptrCount);
	
	/** @brief Return size of list 
	 */
	int GetListSize ();
	
	/** @brief Return the address of the link to the next node in the list 
	*/
    AABBNode *GetNext () const { return m_first->GetNext(); }

	/** @brief Return the address of the link to the first node in the list 
	*/
	AABBNode *GetFirst() const { return m_first; }

//--------------------------------------------------------------------------------------

private:
	/*!< pointer to first node in list */
	AABBNode *m_first;

	/** @brief used to clear memory 
	*/
	void Delete (AABBNode *before);

	/** @brief copy constructor 
	*/
	AABBLinkedList (const AABBLinkedList &ll) {};

	/** @brief assignment operator
	*/
	AABBLinkedList &operator = (const AABBLinkedList &ll) {};
};

#endif
//--------------------------------------------------------------------------------------