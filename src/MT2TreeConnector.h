// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

#ifndef MT2TreeConnector_h
#define MT2TreeConnector_h

#include "Ditto.h"
#include "MT2Tree.h"

using namespace Ditto;

ObjUtil::Leptons getLeptons(MT2Tree& mytree);
ObjUtil::Jets getJets(MT2Tree& mytree);
ObjUtil::Jets getBJets(MT2Tree& mytree);
ObjUtil::METs getMETs(MT2Tree& mytree);
ObjUtil::MET getMET(MT2Tree& mytree);

#endif
//eof
