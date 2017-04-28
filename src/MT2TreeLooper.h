// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

#ifndef MT2TreeLooper_h
#define MT2TreeLooper_h

// ROOT
#include <TChain.h>
#include <TFile.h>
#include <TLorentzVector.h>
#include <TObjArray.h>
#include <TString.h>
#include <TTree.h>

// C++
#include <iostream>

// Ditto
#include "Ditto.h"
#include "MT2Tree.h"
#include "MT2TreeConnector.h"

using namespace Ditto;

extern MT2Tree mytree;
extern TString output_name;
extern Analyses::AnalysisData ana_data;

int MT2TreeLooper(TChain* chain, TString output_name, int nEvents);
void loop();
void beforeLoop(TChain* chain, TString output_name, int nevents);
void afterLoop();
void initMT2Tree();
void loadMT2TreeEvent();
void processMT2TreeEvent();
void setObjects();

#endif
//eof
