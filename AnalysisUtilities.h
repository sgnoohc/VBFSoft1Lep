// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

#ifndef AnalysisUtilities_h
#define AnalysisUtilities_h

// C++
#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
#include <utility>
#include <cstdlib> // exit
#include <time.h>  // rand seed
#include <unistd.h> // sleep
#include <iostream>

// ROOT
#include <TCanvas.h>
#include <TChain.h>
#include <TFile.h>
#include <TGraph.h>
#include <TLorentzVector.h>
#include <TObjArray.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TSystem.h>
#include <TTree.h>
#include <TStopwatch.h>

// For simplicity use namespace. (I generally avoid this.)
using namespace std;

//#################################################################################################
// TOC
//   + PlotUtil namespace
//
//#################################################################################################

namespace AnalysisUtilities
{
  //#################################################################################################
  // Following code was ported from, (Mark Derdzinsky, Gio Zevi Della Porta)
  // https://github.com/gzevi/LeptonTreeLooper/blob/master/PlotUtilities.h
  namespace PlotUtil
  {
    // Map to hold 1D histograms with unique names
    typedef map<string, TH1*> Hist1D_DB;

    void plot1D(
        string name, float xval, double weight, Hist1D_DB &allhistos,
        string title, int numbinsx, float xmin, float xmax);
    void savePlots(Hist1D_DB&, const char*);
  }

  //#################################################################################################
  namespace PrintUtilities
  {

    void print   (TString msg="", int flush_before=0, int flush_after=0);
    void error   (TString msg, int is_error=1);
    void warning (TString msg);
    void announce(TString msg="", int quiet=0);
    void start   (int quiet=0, int sleep_time=0);
    void exit    (int quiet=0);

  }

  //#################################################################################################
  namespace LoopUtilities
  {

    // Total number of events in the input
    unsigned int max_nevents = 0;
    unsigned int total_nevents = 0;
    unsigned int current_ttree_max_nevents = 0;
    unsigned int current_ttree_event_index = 0;
    unsigned int total_nevents_processed = 0;
    TObjArray* list_of_input_files = 0;
    TChain* current_tchain = 0;
    TFile* current_tfile = 0;
    TTree* current_ttree = 0;
    TObjArrayIter* file_iter = 0;
    TStopwatch timer;
    int bar_id = 0;

    void loadFileIter();
    void loadTotalNEvents();
    void loadCurrentTTreeWithName(const char* treename);
    TFile* getCurrentTFile();
    TTree* getCurrentTTree();
    TChain* getCurrentTChain();
    int getCurrentTTreeEventIndex();
    void setCurrentTTreeMaxNEvents();
    bool nextFile();
    bool nextFileAndLoadTTreeWithName(const char* treename);
    void resetLoopCondition(TChain* chain, int nevents = -1);
    void resetCurrentTTreeLoopCondition();
    void resetTotalNEventsProcessed();
    int loadCurrentTTreeEvent();
    void setTotalCurrentTTreeNEvents();
    bool nextEvent();
    bool isAllEventsProcessed();
    void resetCurrentTTreeEventIndex();
    void incrementCurrentTTreeEventIndex();
    void incrementTotalNEventsProcessed();
    void setCurrentTChain(TChain* chain);
    void setCurrentTFile(TFile* file);
    void setCurrentTFileByPath(const char* path);
    void setCurrentTTree(TTree* tree);
    void setMaxNEvents(int nevents);
    void loadListOfFiles();
    void resetPreviousFile();
    void printProgressBar();
    void initProgressBar();
  }

  //#################################################################################################
  namespace LepEffStudyUtil
  {
    void fillEffStudyHisto(
      string study_name,
      PlotUtil::Hist1D_DB& h_1d,
      double probe_el_pt, double probe_el_eta, double probe_el_phi,
      double tag_el_pt  , double tag_el_eta  , double tag_el_phi  ,
      bool passIsoCleaning,
      vector<double> pt_bin_edges,
      vector<double> eta_bin_edges
      );
  }

}


#endif
//eof
