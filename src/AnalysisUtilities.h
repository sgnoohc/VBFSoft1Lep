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
    extern unsigned int max_nevents;
    extern unsigned int total_nevents;
    extern unsigned int current_ttree_max_nevents;
    extern unsigned int current_ttree_event_index;
    extern unsigned int total_nevents_processed;
    extern double fraction_of_booked_nevents;
    extern TObjArray* list_of_input_files;
    extern TChain* current_tchain;
    extern TFile* current_tfile;
    extern TTree* current_ttree;
    extern TObjArrayIter* file_iter;
    extern TStopwatch my_timer;
    extern int bar_id;
    extern int print_rate;

    void loadFileIter();
    void loadTotalNEvents();
    void loadCurrentTTreeWithName(const char* treename);
    TFile* getCurrentTFile();
    TTree* getCurrentTTree();
    TChain* getCurrentTChain();
    int getCurrentTTreeEventIndex();
    void setCurrentTTreeMaxNEvents();
    void setFractionOfBookedNEvents();
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
    void loadFractionOfBookedNEvents();
    double getFractionOfBookedNEvents();
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

  //#################################################################################################
  namespace VBFSUSYUtilities
  {
    // Reading EWKino mass from signal sample
    extern double mC1_event;
    extern double mN2_event;
    extern double mN1_event;
    void setMC1(double mC1);
    void setMN2(double mN2);
    void setMN1(double mN1);
    double getMC1();
    double getMN2();
    double getMN1();
    void parseEwkinoMasses(int ngen, int* gen_pdgId, int* gen_status, float* gen_mass);
    TString getMassSuffixTString();
    TString getNameWithMassSuffix(TString name);

    // Lepton struct
    struct Lepton {
      float lep_pt;
      float lep_eta;
      float lep_phi;
      float lep_mass;
      int   lep_charge;
      int   lep_pdgId;
      float lep_dxy;
      float lep_dz;
      int   lep_tightId;
      int   lep_heepId;
      float lep_relIso03;
      float lep_relIso04;
      float lep_miniRelIso;
      float lep_relIsoAn04;
      int   lep_mcMatchId;
      int   lep_lostHits;
      int   lep_convVeto;
      int   lep_tightCharge;
      float lep_mva;
      float lep_ptRatio;
      float lep_ptRel;
      int   lep_tightIdNoIso;
      float lep_sip3d;
    };
    typedef std::vector<Lepton> Leptons;
    extern Leptons selected_leptons;
    void resetSelectedLeptons();
    void addLepton(Lepton lepton);
    bool isGoodLepton(Lepton lepton);
    void selectGoodLeptons(Leptons leptons);

    // Jet struct
    struct Jet {
      float jet_pt;
      float jet_eta;
      float jet_phi;
      float jet_mass;
      float jet_btagCSV;
      float jet_rawPt;
      float jet_mcPt;
      //float jet_chf;
      //int   jet_FSveto;
      int   jet_mcFlavour;
      int   jet_hadronFlavour;
      float jet_qgl;
      float jet_area;
      int   jet_id;
      int   jet_puId;
    };
    typedef std::vector<Jet> Jets;
    extern Jets selected_jets;
    void resetSelectedJets();
    void addJet(Jet jet);
    bool isGoodJet(Jet jet);
    void selectGoodJets(Jets jets);
  }
}


#endif
//eof
