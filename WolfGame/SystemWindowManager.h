#pragma once
#include "SystemWindow.h"
#include "SceneManagerExtensions.h"
#include "CameraController.h"
#include "CollisionTools.h"

class SystemWindowManager
{
private: 
	std::vector<SystemWindow*> m_Windows;
	Ogre::SceneManager *m_SceneManager;
	Ogre::RTShader::ShaderGenerator *m_ShaderGenerator;
	CameraController* m_Controller;
	MOC::CollisionTools m_CollisionTools;

	bool m_ThumbnaislActive;
	Ogre::SceneNode* m_ThumbnailNode;
	Ogre::SceneNode* m_HighlightedNode;

	SystemWindow* m_SelectedWindow;

	bool m_ZoomMode;


	void CheckActiveThumbnail();
	void ChangeHighlightedThumbnail( String name);
	void RemoveHighlightedThumbnail();

public:
	SystemWindowManager(Ogre::SceneManager *sceneManager,
						Ogre::RTShader::ShaderGenerator *shaderGenerator,
						CameraController *cameraController);
	~SystemWindowManager(void);


	void RefreshWindowHandles();

	void ShowThumbnails();
	void RemoveThumbnails();

	void MoveSelected();
	void ReleaseSelected();

	void ScaleSelected(float scale);
	void SetZoomActive(bool zoomAcitve);

	void PostMessageSelected(UINT msg, WPARAM wParam, LPARAM lParam);
	void PostMessageSelected(UINT msg, WPARAM wParam, Ogre::Vector2 relativeMousePos);
	void SendMessageSelected(UINT msg, WPARAM wParam, LPARAM lParam);
	void SendMessageSelected(UINT msg, Ogre::Vector2 relativeMousePos);
	void SendMessageSelected(UINT msg, LPARAM lParam);

	void OnMouseMoved(Ogre::Vector3 mouseMovement);

	bool CheckWindowCollision(bool canChangeSelection, Vector2 *outRelativePosition);
};

