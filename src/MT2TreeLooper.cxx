// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

// guideline, "MT2Tree" specific stuff goes here, and other generic VBFSUSY related things go to AnalysisUtilites

//  .
// ..: P. Chang, philip@physics.ucsd.edu

#include "MT2TreeLooper.h"

// variables
namespace Vbf {

  // Analysis level variables
  bool is_signal;
  TString output_name;
  PlotUtil::Hist1D_DB h_1d;

  // Event data
  MT2Tree mt2tree;
  float evt_scale1fb;

}

//
// Main
//
int MT2TreeLooper(TChain* chain, TString output_name, int nevents)
{
  beforeLoop(chain, output_name, nevents);
  loop();
  afterLoop();
  return 0;
}



//--------------------====================--------------------====================------------------------====================--------------------====================--------------------
//--------------------====================--------------------====================------------------------====================--------------------====================--------------------
//--------------------====================--------------------====================------------------------====================--------------------====================--------------------


//##################################################################################################
void processMT2TreeEvent()
{
  // compute scale 1fb
  loadScale1fb();

  // If signal, we parse the generator level information to read the masses of the ewkinos
  parseEwkinoMasses();

  // select objects
  selectObjects();

  // histogram names
  TString cutflow_name = "cutflow";
  if (Vbf::is_signal)
    cutflow_name = VBFSUSYUtilities::getNameWithMassSuffix(cutflow_name);

  // cutflow histogram
  PlotUtil::plot1D(cutflow_name.Data(), 0, Vbf::evt_scale1fb, Vbf::h_1d, cutflow_name.Data(), 50, 0, 50);
}

//##################################################################################################
void parseEwkinoMasses()
{
  // Parse the ewkino mass
  if (Vbf::is_signal)
    VBFSUSYUtilities::parseEwkinoMasses(Vbf::mt2tree.ngenStat23,
                                        Vbf::mt2tree.genStat23_pdgId,
                                        Vbf::mt2tree.genStat23_status,
                                        Vbf::mt2tree.genStat23_mass);
}

//##################################################################################################
void initMT2Tree()
{
  // Init the Class
  Vbf::mt2tree.Init(LoopUtilities::getCurrentTTree());
}

//##################################################################################################
void loadMT2TreeEvent()
{
  Vbf::mt2tree.LoadTree(LoopUtilities::getCurrentTTreeEventIndex());
  Vbf::mt2tree.GetEntry(LoopUtilities::getCurrentTTreeEventIndex());
}

//##################################################################################################
void selectObjects()
{
  selectLeptons();
  selectJets();
}

//##################################################################################################
void selectLeptons()
{
  // Select leptons
  VBFSUSYUtilities::Leptons mt2tree_leptons = getLeptonsFromMT2Tree();
  VBFSUSYUtilities::selectGoodLeptons(mt2tree_leptons);

}

//##################################################################################################
void selectJets()
{
  // Select jets
  VBFSUSYUtilities::Jets mt2tree_jets = getJetsFromMT2Tree();
  VBFSUSYUtilities::selectGoodJets(mt2tree_jets);
}

//##################################################################################################
void loadScale1fb()
{
  Vbf::evt_scale1fb = Vbf::mt2tree.evt_scale1fb / LoopUtilities::getFractionOfBookedNEvents();
}

//##################################################################################################
VBFSUSYUtilities::Leptons getLeptonsFromMT2Tree()
{
  VBFSUSYUtilities::Leptons leptons;
  for (int ilep = 0; ilep < Vbf::mt2tree.nlep; ++ilep)
  {
    VBFSUSYUtilities::Lepton lepton;
    lepton.lep_pt           = Vbf::mt2tree.lep_pt[ilep];
    lepton.lep_eta          = Vbf::mt2tree.lep_eta[ilep];
    lepton.lep_phi          = Vbf::mt2tree.lep_phi[ilep];
    lepton.lep_mass         = Vbf::mt2tree.lep_mass[ilep];
    lepton.lep_charge       = Vbf::mt2tree.lep_charge[ilep];
    lepton.lep_pdgId        = Vbf::mt2tree.lep_pdgId[ilep];
    lepton.lep_dxy          = Vbf::mt2tree.lep_dxy[ilep];
    lepton.lep_dz           = Vbf::mt2tree.lep_dz[ilep];
    lepton.lep_tightId      = Vbf::mt2tree.lep_tightId[ilep];
    lepton.lep_heepId       = Vbf::mt2tree.lep_heepId[ilep];
    lepton.lep_relIso03     = Vbf::mt2tree.lep_relIso03[ilep];
    lepton.lep_relIso04     = Vbf::mt2tree.lep_relIso04[ilep];
    lepton.lep_miniRelIso   = Vbf::mt2tree.lep_miniRelIso[ilep];
    lepton.lep_relIsoAn04   = Vbf::mt2tree.lep_relIsoAn04[ilep];
    lepton.lep_mcMatchId    = Vbf::mt2tree.lep_mcMatchId[ilep];
    lepton.lep_lostHits     = Vbf::mt2tree.lep_lostHits[ilep];
    lepton.lep_convVeto     = Vbf::mt2tree.lep_convVeto[ilep];
    lepton.lep_tightCharge  = Vbf::mt2tree.lep_tightCharge[ilep];
    lepton.lep_mva          = Vbf::mt2tree.lep_mva[ilep];
    lepton.lep_ptRatio      = Vbf::mt2tree.lep_ptRatio[ilep];
    lepton.lep_ptRel        = Vbf::mt2tree.lep_ptRel[ilep];
    lepton.lep_tightIdNoIso = Vbf::mt2tree.lep_tightIdNoIso[ilep];
    lepton.lep_sip3d        = Vbf::mt2tree.lep_sip3d[ilep];
    lepton.p4.SetPtEtaPhiM(lepton.lep_pt, lepton.lep_eta, lepton.lep_phi, lepton.lep_mass);
    leptons.push_back(lepton);
  }
  return leptons;
}

//##################################################################################################
VBFSUSYUtilities::Jets getJetsFromMT2Tree()
{
  VBFSUSYUtilities::Jets jets;
  for (int ijet = 0; ijet < Vbf::mt2tree.njet; ++ijet)
  {
    VBFSUSYUtilities::Jet jet;
    jet.jet_pt            = Vbf::mt2tree.jet_pt[ijet];
    jet.jet_eta           = Vbf::mt2tree.jet_eta[ijet];
    jet.jet_phi           = Vbf::mt2tree.jet_phi[ijet];
    jet.jet_mass          = Vbf::mt2tree.jet_mass[ijet];
    jet.jet_btagCSV       = Vbf::mt2tree.jet_btagCSV[ijet];
    jet.jet_rawPt         = Vbf::mt2tree.jet_rawPt[ijet];
    jet.jet_mcPt          = Vbf::mt2tree.jet_mcPt[ijet];
    jet.jet_mcFlavour     = Vbf::mt2tree.jet_mcFlavour[ijet];
    jet.jet_hadronFlavour = Vbf::mt2tree.jet_hadronFlavour[ijet];
    jet.jet_qgl           = Vbf::mt2tree.jet_qgl[ijet];
    jet.jet_area          = Vbf::mt2tree.jet_area[ijet];
    jet.jet_id            = Vbf::mt2tree.jet_id[ijet];
    jet.jet_puId          = Vbf::mt2tree.jet_puId[ijet];
    jet.p4.SetPtEtaPhiM(jet.jet_pt, jet.jet_eta, jet.jet_phi, jet.jet_mass);
    jets.push_back(jet);
  }
  return jets;
}

//##################################################################################################
void loop()
{

  // Loop over file:ttree -> and loop over events in ttree
  // (usually I only have one file each.. so kinda redundant)
  while (LoopUtilities::nextFileAndLoadTTreeWithName("mt2"))
  {

    initMT2Tree();

    // Loop over the TTree
    while (LoopUtilities::nextEvent())
    {

      if (LoopUtilities::isAllEventsProcessed()) break;

      loadMT2TreeEvent();

      //=================================================================
      //
      // <3 of the code
      // Do whatever you want to in the following function for each event
      //
      //
      //=================================================================
      // pass a bool whether output name has "sig" or not
      processMT2TreeEvent();

    } // End TTree loop

  } // End Loop over files
}




//##################################################################################################
void beforeLoop(TChain* chain, TString output_name, int nevents)
{

  // Fun start ASCII art
  PrintUtilities::start();

  // Initialize configurations for event looping
  LoopUtilities::resetLoopCondition(chain, nevents);

  // Set whether the sample being processed is signal or not
  // by checking the output file name
  Vbf::is_signal = output_name.Contains("sig");

  // Set output name
  Vbf::output_name = output_name;
}



//##################################################################################################
void afterLoop()
{
  // Save plots
  PlotUtil::savePlots(Vbf::h_1d, Vbf::output_name+".root");

  // Fun exit
  PrintUtilities::exit();
}



//eof
