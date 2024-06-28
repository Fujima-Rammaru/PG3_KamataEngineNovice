#pragma once
#include"IScene.h"

class TitleScene:public IScene
{
public:
	void Init() override;
		void Update() override;
		void Draw() override;
		

private:
	char preKeys[256];
	char keys[256];
	
};

