#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "Keyboard.h"
#include "Mouse.h"

class Modification;
class Window;

class Input
{
public:
	Input(const std::shared_ptr<Window>& window);
	~Input();

	bool init(const std::shared_ptr<const Modification>& modification);

	std::string getMouseButtonName(uint8_t button) const;
	std::string getMouseWheelUpName() const;
	std::string getMouseWheelDownName() const;
	std::string getKeyName(uint8_t key) const;
private:
	static const std::string keyNameInfoPath;
private:
	bool loadKeyNames(const std::string& modificationPath);
private:
	std::shared_ptr<Window>	window;

	std::vector<std::string> mouseButtonNames;
	std::string mouseWheelUpName;
	std::string mouseWheelDownName;
	std::vector<std::string> keyNames;
};
