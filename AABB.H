#ifndef AABB_H
#define AABB_H

//--------------------------------------------------------------------------------------

#include <iostream>
#include <math.h>
#include <gl/glut.h>

//--------------------------------------------------------------------------------------

/** @class AABB.h
 *	@brief Dynamic array for bounding box coordinates
 *
 *	Dynamic Array used to store the co-ordinates of the bounding boxes used for collsion detection. 
 *	The array is only used initially before being copied into AABB Linked Lists.
 *	The array is then terminated.
 *	I created this class originally before using linked lists to store the BB info. But decided
 *	to keep it has the stored data can be easily copied across into different linked lists
 *	in any prefered order. (i.e. the data is copied into across into linked lists for different
 *	quadrants)
 *	
 *	@author Shay Leary
 *	@version 01
 *	@date 2005
 *
 *	@author Aaron Thomson, Mathew De Vene
 *	@version 01.1: Added detailed comments
 *	@date 2017
 */

class AABB
{
private:
	/** @struct XYZ
		@brief Stores co-ordinate values

		@author Shay Leary
		@version 01
		@date 2005
	 */
	struct XYZ 
	{ 
		GLdouble x, y, z; 
	}; 

	/** @struct BoundingBox
		@brief Stores maxium and minimum values of a box

		@author Shay Leary
		@version 01
		@date 2005
	 */
	struct BoundingBox 
	{ 
		XYZ max; 
		XYZ min; 
	}; 

	/*!< dynamic array to store info */
	BoundingBox *m_BBox;

	/*!< number of BB created (i.e. array size) */
	int m_NoOfBoxes;

	/*!< deletes arrays and clears memory */
	void ClearBB (BoundingBox* &tempArray);

	//----------------------------------------------------------------------------------

    /** @brief Privatised copy constructor 
		
		@param conast AABB &
     */
	AABB(const AABB &aabb) { };

    /** @brief Privatised assignment operator 
		
		@param const AABB &
	 */
	AABB &operator = (const AABB &aabb) { };

public:
	/** @brief Default constuctor
	 */
	AABB() { };

	/** @brief Virtual destructor
	 */
	virtual ~AABB() { ClearBB(m_BBox); };
	
	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------
	/** @brief Set max X

		For a bounding box, set the maximum x value

		@param const int &
		@param const GLdouble &
	 */
	void SetMaxX(const int & tempIndex, const GLdouble &tempX) {m_BBox[tempIndex].max.x = tempX; }
	
	/** @brief Set min X

		For a bounding box, set the minimum x value

		@param const int &
		@param const GLdouble &
	 */
	void SetMinX(const int & tempIndex, const GLdouble &tempX) {m_BBox[tempIndex].min.x = tempX; }
	/** @brief Set max Y

		For a bounding box, set the maximum y value

		@param const int &
		@param const GLdouble &
	 */
	void SetMaxY(const int & tempIndex, const GLdouble &tempY) {m_BBox[tempIndex].max.y = tempY;}
	/** @brief Set min Y

		For a bounding box, set the minimum y value

		@param const int &
		@param const GLdouble &	 
	 */
	void SetMinY(const int & tempIndex, const GLdouble &tempY) {m_BBox[tempIndex].min.y = tempY;}
	/** @brief Set max Z

		For a bounding box, set the maximum z value

		@param const int &
		@param const GLdouble &
	 */
	void SetMaxZ(const int & tempIndex, const GLdouble &tempZ) {m_BBox[tempIndex].max.z = tempZ;}
	/** @brief Set min Z

		For a bounding box, set the minimum z value

		@param const int &
		@param const GLdouble &
	 */
	void SetMinZ(const int & tempIndex, const GLdouble &tempZ) {m_BBox[tempIndex].min.z = tempZ;}
	/** @brief Sets the number of bounding boxes

		@param const int &
	 */
	void SetNoBoundingBoxes(const int & tempSize);

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------
	/** @brief Returns max x
		
		For a bounding box, return the max x value

		@param const int &
	 */
	GLdouble GetMaxX (const int & tempIndex) {return m_BBox[tempIndex].max.x;}
	
	/** @brief Returns min x

		For a bounding box, return the min x value

		@param const int &
	 */
	GLdouble GetMinX (const int & tempIndex) {return m_BBox[tempIndex].min.x;}
	
	/** @brief Returns max y

		For a bounding box, return the max y value

		@param const int &
	 */
	GLdouble GetMaxY (const int & tempIndex) {return m_BBox[tempIndex].max.y;}
	
	/** @brief Returns min y

		For a bounding box, return the min y value

		@param const int &
	 */
	GLdouble GetMinY (const int & tempIndex) {return m_BBox[tempIndex].min.y;}
	
	/** @brief Returns max z

		For a bounding box, return the max z value

		@param const int &
	 */
	GLdouble GetMaxZ (const int & tempIndex) {return m_BBox[tempIndex].max.z;}
	
	/** @brief Returns min z

		For a bounding box, return the min z value

		@param const int &
	 */
	GLdouble GetMinZ (const int & tempIndex) {return m_BBox[tempIndex].min.z;}
	
	/** @brief Returns the number of boxes
	 */
	int GetNoBoundingBoxes () {return m_NoOfBoxes;}
};

#endif
