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

void loop();
void beforeLoop(TChain* chain, TString output_name, int nevents);
void afterLoop();

VBFSUSYUtilities::Leptons getLeptonsFromMT2Tree();
VBFSUSYUtilities::Jets getJetsFromMT2Tree();
void initMT2Tree();
void loadMT2TreeEvent();
void processMT2TreeEvent();

void parseEwkinoMasses();
void selectObjects();
void selectLeptons();
void selectJets();

// variables
namespace Vbf {
  extern bool is_signal;
  extern TString output_name;
  extern PlotUtil::Hist1D_DB h_1d;
  extern MT2Tree mt2tree;
  extern VBFSUSYUtilities::Leptons mt2leptons;
  extern VBFSUSYUtilities::Jets mt2jets;
}

#endif
//eof
