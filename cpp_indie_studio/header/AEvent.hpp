//
// AEvent.hpp for  in /home/pugin_v/cpp/cpp_indie_studio/victor
//
// Made by Victor Pugin
// Login   <pugin_v@epitech.net>
//
// Started on  Sat Jun  4 18:16:53 2016 Victor Pugin
// Last update Sat Jun  4 18:42:22 2016 Victor Pugin
//

#ifndef __AEVENT_HPP__
# define __AEVENT_HPP__

#include <irrlicht.h>

class GraphicsEngine;

class AEvent : public irr::IEventReceiver
{
public:
  AEvent(GraphicsEngine *);
  virtual ~AEvent();
  virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const;
  virtual bool OnEvent(const irr::SEvent& event);

protected:
  GraphicsEngine *_parent;
  bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
};

#endif /* !__AEVENT_HPP__ */
