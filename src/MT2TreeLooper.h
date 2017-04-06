// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

#ifndef MT2TREELOOPER_H
#define MT2TREELOOPER_H

// ROOT
#include <TChain.h>
#include <TFile.h>
#include <TLorentzVector.h>
#include <TObjArray.h>
#include <TString.h>
#include <TTree.h>

// C++
#include <iostream>

// AnalysisUtilties
#include "AnalysisUtilities.h"

// VBF SUSY analysis headers
#include "MT2Tree.h"

using namespace AnalysisUtilities;

int MT2TreeLooper(TChain* chain, TString output_name, int nEvents);

// Looping over events
void loop();
void beforeLoop(TChain* chain, TString output_name, int nevents);
void afterLoop();

// Reading MT2Tree
VBFSUSYUtilities::Leptons getLeptonsFromMT2Tree();
VBFSUSYUtilities::Jets getJetsFromMT2Tree();
void initMT2Tree();
void loadMT2TreeEvent();

// Processing MT2Tree events
void processMT2TreeEvent();
void parseEwkinoMasses();
void selectObjects();
void selectLeptons();
void selectJets();
void setMET();
void loadScale1fb();

// variables
namespace Vbf {

  // Analysis level variables
  extern bool is_signal;
  extern TString output_name;
  extern PlotUtil::Hist1D_DB h_1d;

  // Event data
  extern MT2Tree mt2tree;
  extern float evt_scale1fb;

  // Objects
  extern VBFSUSYUtilities::Leptons mt2leptons;
  extern VBFSUSYUtilities::Jets mt2jets;


}

#endif
//eof
