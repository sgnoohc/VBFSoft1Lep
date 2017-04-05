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

// Instantiate histograms
PlotUtil::Hist1D_DB h_1d;
MT2Tree mt2tree;

VBFSUSYUtilities::Leptons getLeptonsFromMT2Tree(MT2Tree& mt2tree);
VBFSUSYUtilities::Jets getJetsFromMT2Tree(MT2Tree& mt2tree);
void initMT2Tree();
void loadMT2TreeEvent();
void processMT2TreeEvent(bool is_signal);
int MT2TreeLooper(TChain* chain, TString output_name, int nEvents);

#endif
//eof
