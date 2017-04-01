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
using namespace AnalysisUtilities;

// VBF SUSY analysis headers
#include "MT2TreeBkg.h"
#include "MT2TreeSig.h"

int MT2TREELOOPER(TChain* chain, bool isSignal, TString output_name, int nEvents);

#endif
