#pragma once

enum SCENE{TITLE,STAGE,CLEAR};

class IScene {
protected: 

	static int sceneNo_;


public:

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual ~IScene();

	int GetSceneNo();


};