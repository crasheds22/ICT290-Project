#ifndef CAMERA_H
#define CAMERA_H

//--------------------------------------------------------------------------------------

#define PI 3.1415962654

//--------------------------------------------------------------------------------------

#include "collision.h"
#include "cameraMap.h"
#include "PlainLinkedList.h"
#include "EasySound.h"

//--------------------------------------------------------------------------------------

/** @class Camera
*	@brief Creates a camera in the world
*	
*	Allows the camera to be navigated around the world.
*	Also sets Plains, Bounding Boxes and view Maps
*
*	@author Shay Leary
*	@version 1
*	@date March 2005
*/

class Camera
{
public:
	/** @brief constructor
	*/
	Camera();

	/** @destructor
	*/
	virtual ~Camera() {es->Unload(stepSound);}

	//----------------------------------------------------------------------------------
	/** @brief sets initial value for bounding boxes (in the array AABB)
	*
	*	@return void
	*	@param const int&
	*	@param const GLdouble&
	*/
	void SetAABBMaxX(const int & tempIndex, const GLdouble &tempX) {m_colDetect.SetAABBMaxX(tempIndex, tempX);}
	
	/** @brief sets initial value for bounding boxes (in the array AABB)
	*
	*	@return void
	*	@param const int&
	*	@param const GLdouble&
	*/
	void SetAABBMinX(const int & tempIndex, const GLdouble &tempX) {m_colDetect.SetAABBMinX(tempIndex, tempX);}
	
	/** @brief sets initial value for bounding boxes (in the array AABB)
	*
	*	@return void
	*	@param const int&
	*	@param const GLdouble&
	*/
	void SetAABBMaxY(const int & tempIndex, const GLdouble &tempY) {m_colDetect.SetAABBMaxY(tempIndex, tempY);}
	
	/** @brief sets initial value for bounding boxes (in the array AABB)
	*
	*	@return void
	*	@param const int&
	*	@param const GLdouble&
	*/
	void SetAABBMinY(const int & tempIndex, const GLdouble &tempY) {m_colDetect.SetAABBMinY(tempIndex, tempY);}
	
	/** @brief sets initial value for bounding boxes (in the array AABB)
	*
	*	@return void
	*	@param const int&
	*	@param const GLdouble&
	*/
	void SetAABBMaxZ(const int & tempIndex, const GLdouble &tempZ) {m_colDetect.SetAABBMaxZ(tempIndex, tempZ);}
	
	/** @brief sets initial value for bounding boxes (in the array AABB)
	*
	*	@return void
	*	@param const int&
	*	@param const GLdouble&
	*/
	void SetAABBMinZ(const int & tempIndex, const GLdouble &tempZ) {m_colDetect.SetAABBMinZ(tempIndex, tempZ);}

	/** @brief sets rotation size
	*
	*	@return void
	*	@param const GLdouble&
	*/
	void SetRotateSpeed (const GLdouble &tempSpeed) {m_rotateSpeed = tempSpeed;}
	
	/** @brief Sets movement speed
	*
	*	@return void
	*	@param const GLdouble&
	*/
	void SetMoveSpeed (const GLdouble &tempSpeed) {m_moveSpeed = tempSpeed;}

	// COLLSION DETECTION FUNCTIONS
	/** @brief set collision detection (TRUE = on) 
	*	@param const bool&
	*	@return void
	*/
	void SetCollisionDetectionOn (const bool &tempCol) {m_CollisionDetectionOn = tempCol;}
	
	/** @brief set number of bounding boxes 
	*	@return void
	*	@param const int&
	*/
	void SetNoBoundingBoxes(const int & tempSize) {m_colDetect.SetNoBoundingBoxes(tempSize);}
	
	/** @brief set the co-ordinates of the world 
	*	@return void
	*	@param const GLdouble&
	*	@param const GLdouble&
	*/
	void SetWorldCoordinates (const GLdouble &tempX, const GLdouble &tempZ);
	
	/*	@brief Creates linked list
	*
	*	creates a linked list for each quadrant of the world and places the bounding box data in each.  
	*	Then clears and deletes AABB array. 
	*
	*	@return void
	*/
	void InitiateBoundingBoxes() {m_colDetect.CreateLinkedList();}

	/* @brief sets the co-ordinate of each plain 
	*
	*	@return void
	*	@param const int
	*	@param const GLdouble
	*	@param const GLdouble
	*	@param const GLdouble
	*	@param const GLdouble
	*	@param const GLdouble
	*	@param const GLdouble
	*/
	void SetPlains (const int tempType,
				    const GLdouble tempXs, const GLdouble tempXe,
				    const GLdouble tempYs, const GLdouble tempYe,
				    const GLdouble tempZs, const GLdouble tempZe);

	//----------------------------------------------------------------------------------
	/** @brief Returns left/right (x) coordinate
	*
	*	@return GLdouble
	*/
	GLdouble GetLR () {return m_x;}

	/** @brief Returns up/down (y) coordinate
	*
	*	@return GLdouble
	*/
	GLdouble GetUD () {return m_y;}

	/** @brief Return forward/back (z) coordinate
	*
	*	@return GLdouble
	*/
	GLdouble GetFB () {return m_z;}	

	/** @brief Returns max x from collision box index
	*
	*	@return GLdouble
	*	@param const int&
	*/
	GLdouble GetAABBMaxX (const int & tempIndex) {return m_colDetect.GetAABBMaxX (tempIndex);}
	
	/** @brief Returns min x from collision box index
	*
	*	@return GLdouble
	*	@param const int&
	*/
	GLdouble GetAABBMinX (const int & tempIndex) {return m_colDetect.GetAABBMinX (tempIndex);}
	
	/** @brief Returns max y from collision box index
	*
	*	@return GLdouble
	*	@param const int&
	*/
	GLdouble GetAABBMaxY (const int & tempIndex) {return m_colDetect.GetAABBMaxY (tempIndex);}
	
	/** @brief Returns min y from collision box index
	*
	*	@return GLdouble
	*	@param const int&
	*/
	GLdouble GetAABBMinY (const int & tempIndex) {return m_colDetect.GetAABBMinY (tempIndex);}
	
	/** @brief Returns max z from collision box index
	*
	*	@return GLdouble
	*	@param const int&
	*/
	GLdouble GetAABBMaxZ (const int & tempIndex) {return m_colDetect.GetAABBMaxZ (tempIndex);}
	
	/** @brief Returns min z from collision box index
	*
	*	@return GLdouble
	*	@param const int&
	*/
	GLdouble GetAABBMinZ (const int & tempIndex) {return m_colDetect.GetAABBMinZ (tempIndex);}
	
	/** @brief position the camera 
	*
	*	@return void
	*	@param GLdouble const &
	*	@param GLdouble const &
	*	@param GLdouble const &
	*	@param GLdouble const &
	*/
	void Position (GLdouble const & tempX,
				   GLdouble const & tempY,
				   GLdouble const & tempZ,
				   GLdouble const & tempAngle);

	/*	@brief check whether ok to move 
	*	@return void
	*/
	void CheckCamera();

	// Used to pass direction to move or rotate  (i.e. 1, -1 or 0)
	/**	@brief Moves camera front/backwards
	*	@return void
	*	@param const int&
	*/
	void DirectionFB(int const & tempMove);

	/**	@brief Moves camera left/right
	*	@return void
	*	@param const int&
	*/
	void DirectionLR(int const & tempMove);

	/** @brief Moves camera up/down
	*	@return void
	*	@param const int&
	*/
	void DirectionUD(int const & tempMove);

	/**	@brief Rotates camera left/right
	*	@return void
	*	@param GLdouble const&
	*/
	void DirectionRotateLR(GLdouble const & tempMove);

	/** @brief Rotates camera up/down
	*	@return void
	*	@pparam const int&
	*/
	void DirectionLookUD(int const & tempMove);

	/** @brief display map 
	*	@return void
	*	@param const int&
	*	@param const int&
	*	@param const GLuint&
	*/
	void DisplayMap(const int & screenWidth, const int & screenHeight, const GLuint & tempImage);

	/** @brief display welcome screen 
	*	@return void
	*	@param const int&
	*	@param const int&
	*	@param const int&
	*	@param const GLuint&
	*/
	void DisplayWelcomeScreen (const int & screenWidth, const int & screenHeight, const int & tempExit, 
		const GLuint & tempImage);

	/** @brief display no exit 
	*	@return void
	*	@param const int&
	*	@param const int&
	*	@param const GLuint&
	*/
	void DisplayNoExit (const int & screenWidth, const int & screenHeight, const GLuint & tempImage);
	
private:
	//steep incline increments
	/*!< Step incline x increment */
	GLdouble m_incrementX;
	/*!< Step incline z increment */
	GLdouble m_incrementZ;
	/*!< Number of plains */
	int m_No_Plains;
	/*!< The plain number*/
	int m_plainNo;
	/*!< Plain height */
	GLdouble m_plainHeight;

	// rotation variables
	/*!< Current rotation angle left/right */
	GLdouble m_rotateAngleLR;
	/*!< Change in rotation of left/right angle */
	GLdouble m_deltaAngleLR;
	/*!< Current rotation angle up/down */
	GLdouble m_rotateAngleUD;	
	/*!< Change in rotation of up/down angle */
	GLdouble m_deltaAngleUD;

	/*!< movement variables */
	GLdouble m_x, m_y, m_z, m_zLast, m_xLast;
	GLdouble m_lookX, m_lookY,m_lookZ;
	GLdouble m_lookXX, m_lookYY, m_lookZZ;
	GLdouble m_deltaMoveLR;
	GLdouble m_deltaMoveFB;
	GLdouble m_deltaMoveUD;
	GLdouble m_direction;

	/*!< movement speed (step size) */
	GLdouble m_rotateSpeed;
	GLdouble m_moveSpeed;
	
	// is it ok to move
	bool MoveFBOK();
	bool MoveLROK();
	bool MoveUDOK();
	bool RotateLROK();
	bool LookUDOK();

	// move around the world
	void MoveFB();
	void MoveLR();
	void MoveUD();
	void RotateLR();
	void LookUD();
	
	// overloaded function for setting plain
	void SetPlains(const int & moveX, const int & moveZ);

	// resets camera
	void ResetXYZ();
	// display new view
	void callGLLookAt();

	bool m_CollisionDetectionOn;

	// objects
	Collision m_colDetect;
	CameraMap m_map;
	PlainLinkedList m_Plain;

	// These functions were set up to climb stairs, but are not used.
	// The Plain object is used instead
	void ClimbSteps(GLdouble stepStart, GLdouble stepFinish, GLdouble stepHeight, GLdouble stepWidth, int noSteps);
	void CheckSteps();

	CEasySound *es;
	CSound* stepSound;

	//----------------------------------------------------------------------------------

    // Privatised copy constructor and assignment operator
    Camera (const Camera &cam) {};
    Camera &operator = (const Camera &cam) {};
};

#endif