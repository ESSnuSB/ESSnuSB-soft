
/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *              GNU Lesser General Public Licence (LGPL) version 3,             *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

// -------------------------------------------------------------------------
// -----                    EsbCave  file                               -----
// -----                Created 26/03/14  by M. Al-Turany              -----
// -------------------------------------------------------------------------
#include "EsbGeometry/Cave.h"
#include "EsbGeometry/GeoCave.h"                // for EsbGeoCave

#include "FairGeoInterface.h"           // for FairGeoInterface
#include "FairGeoLoader.h"              // for FairGeoLoader
#include "FairGeoNode.h"                // for FairGeoNode
#include "FairGeoPassivePar.h"          // for FairGeoPassivePar
#include "FairGeoVolume.h"              // for FairGeoVolume
#include "FairRun.h"                    // for FairRun
#include "FairRuntimeDb.h"              // for FairRuntimeDb

#include "TList.h"                      // for TListIter, TList (ptr only)
#include "TObjArray.h"                  // for TObjArray
#include "TString.h"                    // for TString

#include <stddef.h>                     // for NULL

//~ ClassImp(EsbCave)

namespace esbroot {
namespace geometry {

void Cave::ConstructGeometry()
{
  FairGeoLoader* loader=FairGeoLoader::Instance();
  FairGeoInterface* GeoInterface =loader->getGeoInterface();
  GeoCave* MGeo=new GeoCave();
  MGeo->setGeomFile(GetGeometryFileName());
  GeoInterface->addGeoModule(MGeo);
  Bool_t rc = GeoInterface->readSet(MGeo);
  if ( rc ) { MGeo->create(loader->getGeoBuilder()); }
 
}

Cave::Cave()
:FairModule()
{
}

Cave::~Cave()
{

}

Cave::Cave(const char* name,  const char* Title)
  : FairModule(name ,Title)
{
  world[0] = 0;
  world[1] = 0;
  world[2] = 0;
}

}
}
