//  collsion.h
/**  Header file for the collision class
 

  @author Shay Leary
*/
#ifndef COLLISION_H
#define COLLISION_H

//--------------------------------------------------------------------------------------

#include "AABB.h"
#include "AABBLinkedList.h"

//--------------------------------------------------------------------------------------

class Collision
{
public:

	/// Constructor
	Collision() {}
	virtual ~Collision() {}

	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------
	// sets initial co-ordinates of bounding boxes (these set the co-ords is AABB, the array,
	// the values for the list are copied from the array using CreateLinkedList).
	/// Sets AABBMaxX
	void SetAABBMaxX(const int & tempIndex, const double &tempX) {m_AABB.SetMaxX(tempIndex, tempX);}
	/// Sets AABBMinX
	void SetAABBMinX(const int & tempIndex, const double &tempX) {m_AABB.SetMinX(tempIndex, tempX);}
	/// Sets AABBMaxY
	void SetAABBMaxY(const int & tempIndex, const double &tempY) {m_AABB.SetMaxY(tempIndex, tempY);}
	/// Sets AABBMinY
	void SetAABBMinY(const int & tempIndex, const double &tempY) {m_AABB.SetMinY(tempIndex, tempY);}
	/// Sets AABBMaxZ
	void SetAABBMaxZ(const int & tempIndex, const double &tempZ) {m_AABB.SetMaxZ(tempIndex, tempZ);}
	/// Sets AABBMinZ
	void SetAABBMinZ(const int & tempIndex, const double &tempZ) {m_AABB.SetMinZ(tempIndex, tempZ);}

	/// sets the actual world co-ordinates - X
	void SetWorldX(const double &tempX) {m_worldSizeX = tempX;}
	/// sets the actual world co-ordinates - Z
	void SetWorldZ(const double &tempZ) {m_worldSizeZ = tempZ;}

	/// set number of bounding boxes
	void SetNoBoundingBoxes(const int & tempSize) {m_AABB.SetNoBoundingBoxes(tempSize);}

	//----------------------------------------------------------------------------------
	//  Returns Methods
	//----------------------------------------------------------------------------------
	// returns co-ordinates of bounding boxes
	/// Gets AABBMaxX 
	double GetAABBMaxX (const int & tempIndex) {return m_AABB.GetMaxX (tempIndex);}
	/// Gets AABBMinX
	double GetAABBMinX (const int & tempIndex) {return m_AABB.GetMinX (tempIndex);}
	/// Gets AABBMaxY
	double GetAABBMaxY (const int & tempIndex) {return m_AABB.GetMaxY (tempIndex);}
	/// Gets AABBMinY
	double GetAABBMinY (const int & tempIndex) {return m_AABB.GetMinY (tempIndex);}
	/// Gets AABBMaxZ
	double GetAABBMaxZ (const int & tempIndex) {return m_AABB.GetMaxZ (tempIndex);}
	/// Gets AABBMinZ
	double GetAABBMinZ (const int & tempIndex) {return m_AABB.GetMinZ (tempIndex);}

	/// returns number of bounding boxes
	int GetNoBoundingBoxes() {return m_AABB.GetNoBoundingBoxes();}

	/// returns TRUE if a collsion occurred
	bool Collide (double endX, double endY, double endZ);

	/// reads the BB info from AABB (dynamic array) and creates a Linked List containing BB data
	void CreateLinkedList();

private:
	/// initially stores BB info in AABB (dynamic array) before copying to Linked List
	AABB m_AABB;

	/// lists to store bounding box info in each quadrant
	AABBLinkedList m_list[4];

	// /Stores the list size of each linked list. Set to 4 has the world is split into 4 quadrants
	int m_listSize[4];

	// stores world co-ordinates - X
	double m_worldSizeX;
	// stores world co-ordinates - Z
	double m_worldSizeZ;

	/// checks if collsion occurred (called from Collide)
	bool CheckCollision(int index, double endX, double endY, double endZ);

	//----------------------------------------------------------------------------------
	
	/// Privatised assignment operator
    Collision (const Collision &coll) {};
	/// Privatised copy constructor
    Collision &operator = (const Collision &coll) {};
};

#endif
//--------------------------------------------------------------------------------------