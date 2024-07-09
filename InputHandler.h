#pragma once
#include<Command.h>

class InputHandler {
public:
	ICommand* HandleInput();

	void AssignMoveLeftCommand2PressKeyA();
	void AssignMoveRightCommand2PressKeyD();
	void AssignMoveUPCommand2PressKeyW();
	void AssignMoveDownCommand2PressKeyS();

private:

	ICommand* pressKeyD_;
	ICommand* pressKeyA_;
	ICommand* pressKeyW_;
	ICommand* pressKeyS_;
};