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

//=============================================================================
// Entry point function for what occurs in each event in the loop
//=============================================================================
// Processing MT2Tree events
void processMT2TreeEvent();

//=============================================================================
// Any functions related to specific to MT2Tree interface
//=============================================================================

// Load MT2Tree
void initMT2Tree();
void loadMT2TreeEvent();

// Read MT2Tree
VBFSUSYUtilities::Leptons getLeptonsFromMT2Tree();
VBFSUSYUtilities::Jets getJetsFromMT2Tree();
VBFSUSYUtilities::Truths getTruthsFromMT2Tree();
void parseEwkinoMasses();

// Prep MT2Tree for analysis
void selectObjects();
void selectLeptons();
void selectJets();
void selectTruths();
void setMET();
void loadScale1fb();
bool correctN2();

//=============================================================================
// ISR analysis
//=============================================================================

// The per event analysis module
void reproduceISRAnalysis();

// Booking histograms
void bookISRHistograms();
void bookISRHistogram(TString name, int nbins, float min, float max);
void bookISRHistogram(TString name, int nbins, const float* xbins);

// Filling histograms
void fillISRHistogram(TString name, float val, float wgt=-999);
void fillISRCutflow(int cutflowbin);

//=============================================================================
// VBF analysis
//=============================================================================

// The per event analysis module
void doVBFAnalysis();

// Booking histograms
void bookVBFHistograms();
void bookVBFHistogramsWithPrefix(TString cutprefix = "");
bool bookVBFHistogram(TString name, int nbins, float min, float max);
bool bookVBFHistogram(TString name, int nbins, const float* xbins);

// Filling histograms
void fillVBFHistograms(TString cutprefix = "");
void fillVBFHistogram(TString name, float val, float wgt=-999);
void fillVBFCutflow(int cutflowbin);

int getMultiBinIndex();
void fillMultiBin(TString cutname);

//=============================================================================
// truth level VBF analysis (mostly to understand signal sample)
//=============================================================================

// The per event analysis module
void truthVBFAnalysis();

//=============================================================================
// arXiv analysis
//=============================================================================

// The per event analysis module
void computeAcceptanceWrtArxiv1502_05044();

//=============================================================================
// truth level VBF analysis (mostly to understand signal sample)
//=============================================================================

// The per event analysis module
void truthTChiWZLeptonAcceptance();




//=============================================================================
// Namespace for global variables
//=============================================================================

// variables
namespace Vbf {

  // Analysis level variables
  extern bool is_signal;
  extern bool is_signal_tchiwz;
  extern TString output_name;
  extern PlotUtil::Hist1D_DB h_isr_1d;
  extern PlotUtil::Hist1D_DB h_vbf_1d;
  extern PlotUtil::Hist1D_DB h_arxiv_1d;
  extern PlotUtil::Hist1D_DB h_truth_1d;
  extern PlotUtil::Hist1D_DB h_truthlepaccept_1d;

  // Event data
  extern MT2Tree mt2tree;
  extern float evt_scale1fb;

  // Objects
  extern VBFSUSYUtilities::Leptons mt2leptons;
  extern VBFSUSYUtilities::Jets mt2jets;

  // histogram names
  extern TString cutflow_name;
  extern TString rawcutflow_name;
  extern TString mee_name;
  extern TString mmm_name;
  extern TString mee_low_name;
  extern TString mee_med_name;
  extern TString mee_high_name;
  extern TString mmm_low_name;
  extern TString mmm_med_name;
  extern TString mmm_high_name;
  extern TString mll_med_name;
  extern TString mll_high_name;
  extern TString nbjet25_name;
  extern TString myNBjet25L_name;
  extern TString myNBjet25M_name;

  // Mll bins for ISR analysis
  extern float mllbin[5];

  // VBF histogram names
  extern TString histname_vbf_cutflow;
  extern TString histname_vbf_rawcutflow;
  extern TString histname_vbf_nsoftleps;
  extern TString histname_vbf_njets;
  extern TString histname_vbf_nbjets;
  extern TString histname_vbf_mjj;
  extern TString histname_vbf_detajj;
  extern TString histname_vbf_dphijj;
  extern TString histname_vbf_cenjetpt;
  extern TString histname_vbf_leadleppt;
  extern TString histname_vbf_leadlepeta;
  extern TString histname_vbf_met;
  extern TString histname_vbf_leadjetpt;
  extern TString histname_vbf_subljetpt;
  extern TString histname_vbf_leadjeteta;
  extern TString histname_vbf_subljeteta;
  extern TString histname_vbf_leadjete;
  extern TString histname_vbf_subljete;
  extern TString histname_vbf_leadjeteoverpt;
  extern TString histname_vbf_subljeteoverpt;
  extern TString histname_vbf_lepcent;
  extern TString histname_vbf_mt;
  extern TString histname_vbf_modmt;
  extern TString histname_vbf_mlj0;
  extern TString histname_vbf_mlj1;
  extern TString histname_vbf_summlj;
  extern TString histname_vbf_ht;
  extern TString histname_vbf_methtratio;
  extern TString histname_vbf_lepid;
  extern TString histname_vbf_dphilepmet;
  extern TString histname_vbf_sumpt;
  extern TString histname_vbf_sumptall;
  extern TString histname_vbf_dphileadjetmet;
  extern TString histname_vbf_dphisubljetmet;
  extern TString histname_vbf_dphidijetmet;
  extern TString histname_vbf_dphidijetlep;
  extern TString histname_vbf_metphicent;
  extern TString histname_vbf_lepphicent;
  extern TString histname_vbf_lepphicentboost;
  extern TString histname_vbf_metphicentboost;
  extern TString histname_vbf_dphidijetlepmet;
  extern TString histname_vbf_dphileadjetlep;
  extern TString histname_vbf_dphisubljetlep;
  extern TString histname_vbf_dphilepmetboost;
  extern TString histname_vbf_dphilepmetwframe;
  extern TString histname_vbf_dphileadjetmetlep;
  extern TString histname_vbf_dphisubljetmetlep;
  extern TString histname_vbf_dphidijetmetlep;
  extern TString histname_vbf_dptjet;
  extern TString histname_vbf_ptrel;
  extern TString histname_vbf_superptrel;
  extern TString histname_vbf_superptrelnowgt;
  extern TString histname_vbf_prodptrel;
  extern TString histname_vbf_metrel;
  extern TString histname_vbf_mtrel;
  extern TString histname_vbf_cenjetdr;
  // dilepton channel
  extern TString histname_vbf_mll;
  extern TString histname_vbf_dphill;
  extern TString histname_vbf_ptll;
  extern TString histname_vbf_sublleppt;
  extern TString histname_vbf_dilepchannel;
  extern TString histname_vbf_mtt;
  extern TString histname_vbf_multibin;

}

#endif
//eof
