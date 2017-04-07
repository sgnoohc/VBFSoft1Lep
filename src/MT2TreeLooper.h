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

// Booking histograms
void bookISRHistograms();
void bookISRHistogram(TString name, int nbins, float min, float max);
void bookISRHistogram(TString name, int nbins, const float* xbins);

// Filling histograms
void fillISRHistogram(TString name, float val, float wgt);
void fillCutflow(int cutflowbin);

void reproducingISRAnalysis();

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

  // histogram names
  extern TString cutflow_name    = "cutflow";
  extern TString rawcutflow_name = "rawcutflow";
  extern TString mee_name        = "mee";
  extern TString mmm_name        = "mmm";
  extern TString mee_low_name    = "mee_low";
  extern TString mee_med_name    = "mee_med";
  extern TString mee_high_name   = "mee_high";
  extern TString mmm_low_name    = "mmm_low";
  extern TString mmm_med_name    = "mmm_med";
  extern TString mmm_high_name   = "mmm_high";
  extern TString mll_med_name    = "mll_med";
  extern TString mll_high_name   = "mll_high";
  extern TString nbjet25_name    = "nBJet25";
  extern TString myNBjet25L_name = "MynBJet25L";
  extern TString myNBjet25M_name = "MynBJet25M";

  // bins
  extern float mllbin[5];


}

#endif
//eof
