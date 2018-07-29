/*
** land.hpp for first in /home/denizo_r/test/irrlicht/first
**
** Made by romain denizot
** Login   <denizo_r@epitech.net>
**
** Started on  Thu Jun 02 16:50:04 2016 romain denizot
// Last update Sat Jun  4 16:33:39 2016 Victor Pugin
*/

#ifndef LAND_HPP
# define LAND_HPP

#include <irrlicht.h>
#include "GraphicsEngine.hpp"

class GraphicsEngine;

class Land
{
public:
  Land(GraphicsEngine* graph);
  ~Land();
  irr::scene::ITerrainSceneNode* getLand() const;
  void addCircuit();

private:
  GraphicsEngine *gfxe;
  irr::scene::ITerrainSceneNode* land;
  irr::scene::IAnimatedMeshSceneNode *circuit;
};

#endif /* !LAND_HPP */
