/*
** Land.cpp for first in /home/denizo_r/test/irrlicht/first
**
** Made by romain denizot
** Login   <denizo_r@epitech.net>
**
** Started on  Thu Jun 02 16:53:49 2016 romain denizot
// Last update Sat Jun  4 16:37:10 2016 Victor Pugin
*/

#include "Land.hpp"


Land::Land(GraphicsEngine* graph) : gfxe(graph)
{
  this->land = graph->getSmgr()->addTerrainSceneNode(
    "file/black.bmp",
    0,					// parent node
    -1,					// node id
    irr::core::vector3df(0.f, 0.f, 0.f),		// position
    irr::core::vector3df(0.f, 0.f, 0.f),		// rotation
    irr::core::vector3df(5.f, 5.f, 5.f),	// scale
    irr::video::SColor ( 255, 255, 255, 255 ),	// vertexColor
    5,					// maxLOD
    irr::scene::ETPS_17,				// patchSize
    4					// smoothFactor
    );

  land->setMaterialFlag(irr::video::EMF_LIGHTING, false);

  land->setMaterialTexture(0,
      gfxe->getDriver()->getTexture("file/herbe.jpg"));
  land->setMaterialTexture(1,
      gfxe->getDriver()->getTexture("irrlicht-1.8.3/media/detailmap3.jpg"));
  land->setMaterialType(irr::video::EMT_DETAIL_MAP);
  land->scaleTexture(20.f, 20.f);
}

Land::~Land()
{
}

irr::scene::ITerrainSceneNode* Land::getLand() const
{
  return (this->land);
}

void Land::addCircuit()
{
  irr::scene::IAnimatedMesh* mesh = gfxe->getSmgr()->getMesh("file/viper.obj");
	circuit = gfxe->getSmgr()->addAnimatedMeshSceneNode( mesh );

	if (circuit)
	{
		circuit->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		circuit->setFrameLoop(0, 310);
		circuit->setMaterialTexture( 0, gfxe->getDriver()->getTexture("file/text.jpg") );
	}
}
