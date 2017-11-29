#include "TweakBar.h"



TweakBar::TweakBar()
{
	bar = TwNewBar("MyTweakBar");
	TwAddVarRW(bar, "MyVariable", TW_TYPE_STDSTRING, &str, "test");
}

void TweakBar::Draw()
{
	TwDraw();
}


TweakBar::~TweakBar()
{
}
