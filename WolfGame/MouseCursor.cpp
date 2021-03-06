#include "stdafx.h"
#include "MouseCursor.h"

const float minX = -1.0f;
const float minY = -1.5f;
const float maxX = 1.0f;
const float maxY = 1.5f;


MouseCursor::MouseCursor(Ogre::SceneManager *sceneMgr, 
					     Ogre::SceneNode* rotationNode,
						 Ogre::SceneNode* orientationNode)
	:m_Sensitivity(0.00175f),
	m_RotationNode(rotationNode)
{
	m_Cursor = orientationNode->createChildSceneNode("bodyNode");
	Ogre::SceneNode* child= m_Cursor->createChildSceneNode("iconNode");
	Ogre::Entity *cursorEntity = sceneMgr->createEntity("Cursor", "Cursor.mesh");

	Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().getByName("Cursor");
	cursorEntity->setMaterial(material);
	child->attachObject(cursorEntity);

	child->yaw(Ogre::Radian(3*Ogre::Math::PI/2));
	child->roll(Ogre::Radian(-Ogre::Math::PI/2));
	m_Cursor->setPosition(Ogre::Vector3(0,0,-1.9f));
	child->setScale(.1f,.1f,.1f);
	
}


void MouseCursor::mouseInput(Ogre::Vector2 input)
{
	input =  input * m_Sensitivity;

	Ogre::Vector3 position = m_Cursor->getPosition();

	position.x += input.x;
	position.y -= input.y;

	if(position.x < minX)
	{
		float difference =  position.x-minX ;
		position.x = minX;
		m_RotationNode->yaw(Ogre::Radian(difference/-1.75f));
	}
	else if(position.x > maxX)
	{
		float difference =  position.x - maxX;
		position.x = maxX;
		m_RotationNode->yaw(Ogre::Radian(difference/-1.75f));
	}

	if(position.y < minY)
	{
		float difference =  position.y - minY ;
		position.y = minY;
		//m_RotationNode->pitch(Ogre::Radian(difference/10));
	}
	else if(position.y > maxY)
	{
		float difference =  position.y - maxY ;
		position.y = maxY;
		//m_RotationNode->pitch(Ogre::Radian(difference/10));
	}

	m_Cursor->setPosition(position);
}

Ogre::Vector3 MouseCursor::GetPosition()
{
	return m_Cursor->convertLocalToWorldPosition(Ogre::Vector3::ZERO);
}

void MouseCursor::SetVisible(bool visible)
{
	m_Cursor->setVisible(visible);
}
