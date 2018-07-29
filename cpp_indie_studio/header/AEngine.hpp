//
// AEngine.hpp for  in /home/pugin_v/cpp/indie
// 
// Made by Victor Pugin
// Login   <pugin_v@epitech.net>
// 
// Started on  Wed Jun  1 13:09:38 2016 Victor Pugin
// Last update Wed Jun  1 14:26:36 2016 Victor Pugin
//

#ifndef __AENGINE_HPP__
# define __AENGINE_HPP__

class Game;
class GameEngine;
class GraphicsEngine;
class SoundEngine;

class AEngine
{
public:
  AEngine(Game *);
  virtual ~AEngine();

  virtual void frame() = 0;

  void setGameEngine(GameEngine *ge);
  void setGraphicsEngine(GraphicsEngine *gfxe);
  void setSoundEngine(SoundEngine *se);

protected:
  Game *_parent;

protected:
  GameEngine *_ge;
  GraphicsEngine *_gfxe;
  SoundEngine *_se;
};

#endif /* !__AENGINE_HPP__ */
