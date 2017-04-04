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

VBFSUSYUtilities::Leptons getLeptonsFromMT2Tree(MT2Tree& mt2tree);
VBFSUSYUtilities::Jets getJetsFromMT2Tree(MT2Tree& mt2tree);
int MT2TreeLooper(TChain* chain, TString output_name, int nEvents);

#endif
//eof
