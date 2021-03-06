#pragma once
#include "stdafx.h"
#include "feet.h"

class Player
{
public:
	Player(Ogre::SceneManager *sceneMgr, Ogre::SceneNode* eyeNode);
	~Player(void);
	void addKeyboardInput(Ogre::Vector3 input);
	void mouseInput(Ogre::Vector2 input);
	void processMovement(Ogre::Real timeSinceLastFrame);
	void jump();
	void changeHeight(bool change);
	void step();

private:
	bool OnGround();
	void processJump(bool onGround, Ogre::Real timeSinceLastFrame);
	bool checkHorizontalColisions( Ogre::Vector3 normal);
	float checkVerticalClearance(bool up, float travel);
	void checkBounds();
	Feet* mFeet;
	Ogre::SceneNode* mPlayerNode;
	Ogre::SceneNode* mBody;
	Ogre::SceneNode* mEyeNode;
	MOC::CollisionTools* mCollisionTools;
	Ogre::Vector3 mInput;
	bool mJumping;
	bool mDoubleJumping;
	bool mOnGround;
	bool mChangeHeight;

	Ogre::Vector3 mJumpVector;
	Ogre::Real mJumpDuration;
};

