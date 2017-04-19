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
#include <TVector3.h>
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

    bool plot1D(
        string name, float xval, double weight, Hist1D_DB &allhistos,
        string title, int numbinsx, float xmin, float xmax);
    bool plot1D(
        string name, float xval, double weight, Hist1D_DB &allhistos,
        string title, int numbinsx, const float* xbins);
    void plot1D(
        string name, float xval, double weight, Hist1D_DB &allhistos);
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
    int getProductionMode(int ngen, int* gen_pdgId, int* gen_status);
    TString getMassSuffixTString();
    TString getProdSuffixTString();
    TString getSignalSuffix(TString name);

    //
    // Lepton objects
    //

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
      TLorentzVector p4;
    };
    typedef std::vector<Lepton> Leptons;
    extern Leptons selected_good_leptons;
    extern Leptons selected_vbf_leptons;
    extern Leptons selected_isr_leptons;

    enum ELECTRON_ID_type {
      kELECTRON_TIGHT = 2,
      kELECTRON_MED   = 1,
      kELECTRON_LOOSE = 0,
      kELECTRON_VETO  = -1
    };

    enum MUON_ID_type {
      kMUON_TIGHT = 0,
      kMUON_LOOSE = -1
    };

    enum PROD_type {
      kPRODSTRONG = 0,
      kPRODVBF    = 1,
      kPRODVSTAR  = 2
    };
    extern PROD_type prodmode;

    void parseProductionMode(int ngen, int* gen_pdgId, int* gen_status);
    void setProductionMode(PROD_type);
    PROD_type getProductionMode();

    extern ELECTRON_ID_type ELECTRON_ID;
    extern MUON_ID_type MUON_ID;

    void setElectronID(ELECTRON_ID_type electronid);
    void setMuonID(MUON_ID_type muonid);

    void resetSelectedGoodLeptons();
    void addGoodLepton(Lepton lepton);
    bool isGoodLepton(Lepton lepton);
    void selectGoodLeptons(Leptons leptons);
    int getNSelectedGoodLeptons();
    int getNSelectedSoftGoodLeptons();

    Lepton getLeadingGoodLepton();
    Lepton getSubleadingGoodLepton();

    void resetSelectedVBFLeptons();
    void addVBFLepton(Lepton lepton);
    bool isVBFLepton(Lepton lepton);
    void selectVBFLeptons(Leptons leptons);
    int getNSelectedVBFLeptons();

    void resetSelectedISRLeptons();
    void addISRLepton(Lepton lepton);
    bool isISRLepton(Lepton lepton);
    void selectISRLeptons(Leptons leptons);
    int getNSelectedISRLeptons();

    bool correctN2(int ngen, int* gen_pdgId, int* gen_sourceId, float* gen_mass, float* gen_pt, float* gen_eta, float* gen_phi);

    //
    // Jet variables
    //

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
      TLorentzVector p4;
    };
    typedef std::vector<Jet> Jets;
    extern Jets selected_good_jets;
    extern Jets selected_good_bjets;
    void resetSelectedGoodJets();
    void resetSelectedGoodBJets();
    void addGoodJet(Jet jet);
    void addGoodBJet(Jet jet);
    bool isGoodJet(Jet jet);
    bool isGoodBJet(Jet jet);
    void selectGoodJets(Jets jets);
    void selectGoodBJets(Jets jets);

    int getNBTaggedJetsWithCSVCut(float csvcut);

    int getNSelectedGoodBJets();

    int getNSelectedGoodJets();
    Jet getLeadingVBFJet();
    Jet getSubleadingVBFJet();

    extern float met_pt;
    extern float met_phi;
    extern TLorentzVector met_p4;
    void setMET(float met);
    void setMETphi(float met_phi);
    void setMETp4();
    TLorentzVector getMETp4();

    //
    // guarntee functions
    //
    void checkNJets(int N, TString function="");
    void checkNLeptons(int N, TString function="");
    void checkOneJet(TString function="");
    void checkTwoJets(TString function="");
    void checkThreeJets(TString function="");
    void checkOneLepton(TString function="");
    void checkTwoLeptons(TString function="");

    //
    // VBF Topology variables
    //
    bool hasVBFJets();
    bool isCenJet(Jet jet);
    bool doesCenJetsExist();
    float getVBFDEtajj();
    float getVBFMjj();
    float getLeadCenJetPt();
    float getVBFDPhijj();

    //
    // Lepton variables
    //
    bool isEEChannel();
    bool isMMChannel();
    float getMll();
    float getPtll();
    float getDPhill();
    float getModMT(Lepton lep);
    float getModMTleadLep();
    float getModMTsubleadLep();
    float getMT(Lepton lep);
    float getMTleadLep();
    float getMTsubleadLep();
    float getMtt();
    float getDPhiLepMET();
    float getVecSumPt();
    float getVecSumPtAll();
    float getDPhiLeadJetMET();
    float getDPhiSubleadJetMET();
    float getDPhiLeadJetLep();
    float getDPhiSubleadJetLep();
    float getDPhiDiJetMET();
    float getDPhiDiJetLep();
    float getMETPhiCent();
    float getLepPhiCent();
    float getMETPhiCentBoost();
    float getLepPhiCentBoost();
    float getDPhiDiJetLepMet();
    float getDPhiLepMETInvDijetFrame();
    float getDPhiLepMETWFrame();
    float getDPhiLeadJetMetLep();
    float getDPhiSubleadJetMetLep();
    float getDPhiDiJetMetLep();
    float getDPtJet();
    float getPtRel(Lepton lep);
    float getMETRel(Lepton lep);
    float getLeadLepPtRel();
    float getLeadLepMETRel();
    float getMTRel();
    float getSuperPtRel();
    float getSuperPtRelNoWgt();
    float getProdPtRel();
    float getHT();

    float getMinDRLeadCenJet();
    float getMinDRCenJet();

    // lep jet variables
    float getLeptonCentrality();
    float getMlj(Jet jet, Lepton lep);
    float getLeadMlj();
    float getSubleadMlj();
    float getSumMlj();

  }
}


#endif
//eof
