#include "Input.h"
BEGIN_CM_NAMESPACE
Input::Input() {}

void Input::readInput() {}

bool Input::getMouseDown() { return false; }

bool Input::getKeyDown() { return false; }

KeyCode Input::getKey() { return KeyCode(); }

MouseButton Input::getMouse() { return MouseButton(); }
END_CM_NAMESPACE