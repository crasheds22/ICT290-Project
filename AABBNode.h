#ifndef AABBNODE_H
#define AABBNODE_H

//--------------------------------------------------------------------------------------

#include <vector>
#include <gl/glut.h>

//--------------------------------------------------------------------------------------

/** @class AABBNode
*	@brief
*
*	Stores details for each bounding box used for collsion detection. 
*	Each node is stored in each link of the AABB Linked List
*
*	@author Shay Leary 
*	@version 1
*	@ date March 2005
*/

class AABBNode
{
public:
	/** @brief constructor
	 *
	 * Makes m_next point to null
	 */
	AABBNode () {Clear();}

	/** @brief destructor
	 */
    virtual ~AABBNode () {Clear();}

	//----------------------------------------------------------------------------------

	/** @brief makes m_next point to null
	 */
	void  Clear();

	//----------------------------------------------------------------------------------
	
	/** @brief Returns max x value
	 */
	GLdouble GetMaxX () {return m_BBox.max.x;}
	
	/** @brief Returns min x value
	*/
	GLdouble GetMinX () {return m_BBox.min.x;}
	
	/** @brief Returns max y value
	*/
	GLdouble GetMaxY () {return m_BBox.max.y;}
	
	/** @brief Returns min y value
	*/
	GLdouble GetMinY () {return m_BBox.min.y;}
	
	/** @brief Returns max z value
	*/
	GLdouble GetMaxZ () {return m_BBox.max.z;}
	
	/** @brief Returns min z value
	*/
	GLdouble GetMinZ () {return m_BBox.min.z;}

    /** @brief Return the address of the link to the next node in the list
	*/
    AABBNode *GetNext () const {return m_next;}

	//----------------------------------------------------------------------------------
	
	/** @brief Sets the coordinates
	*
	*	@param GLdouble
	*	@param GLdouble
	*	@param GLdouble
	*	@param GLdouble
	*	@param GLdouble
	*	@param GLdouble
	*/
	void SetData(const GLdouble maxX, const GLdouble minX,
				 const GLdouble maxY, const GLdouble minY,
				 const GLdouble maxZ, const GLdouble minZ);

    /** @brief Set the address of the link to the next node in the list 
	*
	*	@param AABBNode *
	*/
    void SetNext (AABBNode *next) {m_next = next;}

private:
    /*!< The address of the next node in the list */
    AABBNode *m_next;

	/** @struct XYZ
	 *	@brief stores x,y,z co-ordinates 
	 */
	struct XYZ 
	{ 
		/*!< The x, y and z coordinate*/
		GLdouble x, y, z; 
	}; 

	/**	@struct BoundingBox
	 *	@brief stores max and min values of co-ordinates 
	 */
	struct BoundingBox 
	{ 
		/*!< XYZ max value */
		XYZ max; 
		/*!< XYZ min value */
		XYZ min; 
	}; 

	/*<! stores above info */
	BoundingBox m_BBox;

	//----------------------------------------------------------------------------------

    /** @brief copy constructor 
	*/
    AABBNode (const AABBNode &newNode) {};

	/** @brief assignment operator 
	*/
    AABBNode &operator = (const AABBNode &newNode) {};
};

#endif
