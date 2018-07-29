//
// SoundEngine.hpp for  in /home/pugin_v/cpp/indie
// 
// Made by Victor Pugin
// Login   <pugin_v@epitech.net>
// 
// Started on  Wed Jun  1 13:09:38 2016 Victor Pugin
// Last update Wed Jun  1 14:28:32 2016 Victor Pugin
//

#ifndef __SOUNDENGINE_HPP__
# define __SOUNDENGINE_HPP__

#include "AEngine.hpp"

class SoundEngine : public AEngine
{
public:
  SoundEngine(Game *);
  virtual ~SoundEngine();

  virtual void frame();
};

#endif /* !__SOUNDENGINE_HPP__ */
