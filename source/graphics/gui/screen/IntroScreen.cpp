#include "IntroScreen.h"

#include <cstdint>

#include "../Gui.h"
#include "../GuiBackgroundImage.h"

#include "engine/Engine.h"
#include "graphics/device/Device.h"
#include "input/Input.h"

namespace gfx
{

namespace gui
{

const std::string IntroScreen::logoTextureName = "sys/gfx/logo.bmp";

IntroScreen::InputHandler::InputHandler(Input& input,
		IntroScreen& introScreen) :
	super(&input),
	introScreen(introScreen)
{}

bool IntroScreen::InputHandler::onKeyPressed(uint8_t key, bool alt,
	bool control, bool shift, bool super)
{
	introScreen.skipIntro();

	return false;
}

bool IntroScreen::InputHandler::onMouseButtonPressed(uint8_t button, int x,
	int y)
{
	introScreen.skipIntro();

	return false;
}

IntroScreen::IntroScreen(Gui& gui, Input& input) :
	super(gui),
	inputHandler(new InputHandler(input, *this)),
	maxShowTime(3.0f),
	fadeStart(0.80f),
	fadeColor(0, 0, 0),
	introImage(nullptr),
	showTime(0.0f)
{}

IntroScreen::~IntroScreen()
{}

void IntroScreen::create()
{
	super::create();

	showTime = 0.0f;

	device::Device* device = gui.getDevice();
	if (device != nullptr)
	{
		introImage = gui.addBackgroundImage(
			device->grabTexture(gui.getModPath() + logoTextureName));
	}

	inputHandler->init();
}

void IntroScreen::destroy()
{
	inputHandler->remove();

	if (introImage != nullptr)
	{
		gui.deleteGuiElement(introImage);
		introImage = nullptr;
	}

	device::Device* device = gui.getDevice();
	if (device != nullptr)
	{
		device->releaseTexture(gui.getModPath() + logoTextureName);
	}

	super::destroy();
}

void IntroScreen::update(float deltaTime)
{
	showTime += deltaTime;
	if (showTime > maxShowTime)
	{
		skipIntro();
	}
	else
	{
		float fadeStartTime = maxShowTime * fadeStart;
		if (showTime > fadeStartTime)
		{
			float fadeLength = maxShowTime - fadeStartTime;
			float fade = (showTime - fadeStartTime) / fadeLength;

			fadeColor.setAlpha(static_cast<uint8_t>(255.0f * fade));
			introImage->setMaskColor(fadeColor);
		}
	}

	super::update(deltaTime);
}

void IntroScreen::skipIntro()
{
	Engine* engine = gui.getEngine();
	if (engine != nullptr)
	{
		engine->skipIntro();
	}
}

} // namespace gui

} // namespace gfx
