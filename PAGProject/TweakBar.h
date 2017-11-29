#pragma once
#include"Headers.h"

class TweakBar
{
public:
	TweakBar();
	void Draw();
	~TweakBar();

private:
	TwBar* bar;
	std::string str;
};

