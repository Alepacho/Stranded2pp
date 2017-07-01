#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "common/CmdLineArgs.h"
#include "common/Modification.h"
#include "input/RawInputHandler.h"
#include "window/Window.h"

class Engine;
class Input;
class Network;
class Sound;

namespace gfx
{

	class Graphics;

} // namespace gfx

class Stranded
{
	class QuitEventHandler : public RawInputHandler
	{
		typedef RawInputHandler super;
	public:
		QuitEventHandler(Input* input, Stranded& stranded) :
			super(input),
			stranded(stranded)
		{}

		bool onClosed() override
		{
			stranded.stop();

			return false;
		}
	private:
		Stranded & stranded;
	};
	friend class QuitEventHandler;
public:
	Stranded(std::vector<std::string> const & arguments);

	bool init();
	void run();
private:
	void stop();

	void printWelcomeMessage();
private:
	common::CmdLineArgs cmdLineArgs;

	Modification modification;

	Window window;

	std::shared_ptr<Input>		input;
	std::shared_ptr<QuitEventHandler> quitEventHandler;

	std::shared_ptr<gfx::Graphics>	graphics;

	std::shared_ptr<Network>	network;

	std::shared_ptr<Sound>		sound;

	std::shared_ptr<Engine>		engine;

	bool shouldStop;
};
