//
// GameEngine.hpp for  in /home/pugin_v/cpp/indie
//
// Made by Victor Pugin
// Login   <pugin_v@epitech.net>
//
// Started on  Wed Jun  1 13:09:38 2016 Victor Pugin
// Last update Sun Jun  5 02:31:48 2016 Victor Pugin
//

#ifndef __GAMEENGINE_HPP__
# define __GAMEENGINE_HPP__

#include <list>
#include "AEngine.hpp"
#include "Session.hpp"

class GameEngine : public AEngine
{
public:
  GameEngine(Game *);
  virtual ~GameEngine();

  virtual void frame();
  Session *getSession() const;
  void save() const;

  GraphicsEngine *getGraphicsEngine() const;

private:
  std::list<Session *> _sessionSaved;
  Session *_session;
};

#endif /* !__GAMEENGINE_HPP__ */
