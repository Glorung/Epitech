//
// AEvent.cpp for  in /home/pugin_v/cpp/cpp_indie_studio/victor
//
// Made by Victor Pugin
// Login   <pugin_v@epitech.net>
//
// Started on  Sat Jun  4 18:42:28 2016 Victor Pugin
// Last update Sun Jun  5 22:34:21 2016 romain denizot
//

#include "AEvent.hpp"
#include <iostream>

AEvent::AEvent(GraphicsEngine *gfxe) : _parent(gfxe)
{
  for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
    KeyIsDown[i] = false;
}

AEvent::~AEvent()
{
}

bool AEvent::OnEvent(const irr::SEvent& event)
{
  if (event.EventType == irr::EET_KEY_INPUT_EVENT)
  {
    KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    return (true);
  }
  return (false);
}

bool AEvent::IsKeyDown(irr::EKEY_CODE keyCode) const
{
  return KeyIsDown[keyCode];
}
