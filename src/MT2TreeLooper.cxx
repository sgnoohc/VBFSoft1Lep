// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

// guideline, "MT2Tree" specific stuff goes here, and other generic VBFSUSY related things go to AnalysisUtilites

//  .
// ..: P. Chang, philip@physics.ucsd.edu

#include "MT2TreeLooper.h"

//======================================================================================
// Namespace for "global" variable of the program (I just named it "Vbf". It's a misnomer.)
//======================================================================================
// variables
namespace Vbf {

  // Analysis level variables
  bool is_signal;
  TString output_name;
  PlotUtil::Hist1D_DB h_isr_1d;
  PlotUtil::Hist1D_DB h_vbf_1d;
  PlotUtil::Hist1D_DB h_arxiv_1d;

  // Event data
  MT2Tree mt2tree;
  float evt_scale1fb;

  // Histogram names
  TString cutflow_name    = "cutflow";
  TString rawcutflow_name = "rawcutflow";
  TString mee_name        = "mee";
  TString mmm_name        = "mmm";
  TString mee_low_name    = "mee_low";
  TString mee_med_name    = "mee_med";
  TString mee_high_name   = "mee_high";
  TString mmm_low_name    = "mmm_low";
  TString mmm_med_name    = "mmm_med";
  TString mmm_high_name   = "mmm_high";
  TString mll_med_name    = "mll_med";
  TString mll_high_name   = "mll_high";
  TString nbjet25_name    = "nBJet25";
  TString myNBjet25L_name = "MynBJet25L";
  TString myNBjet25M_name = "MynBJet25M";

  // VBF histogram names
  // multiplicity
  TString histname_vbf_cutflow    = "vbf_cutflow";
  TString histname_vbf_rawcutflow = "vbf_rawcutflow";
  TString histname_vbf_nsoftleps  = "vbf_nsoftleps";
  TString histname_vbf_njets      = "vbf_njets";
  TString histname_vbf_mjj        = "vbf_mjj";
  TString histname_vbf_detajj     = "vbf_detajj";
  TString histname_vbf_dphijj     = "vbf_dphijj";
  TString histname_vbf_cenjetpt   = "vbf_cenjetpt";
  TString histname_vbf_leadleppt  = "vbf_leadleppt";
  TString histname_vbf_met        = "vbf_met";
  TString histname_vbf_leadjetpt  = "vbf_leadjetpt";
  TString histname_vbf_subljetpt  = "vbf_subljetpt";
  TString histname_vbf_lepcent    = "vbf_lepcent";
  TString histname_vbf_mt         = "vbf_mt";
  TString histname_vbf_mlj0       = "vbf_mlj0";
  TString histname_vbf_mlj1       = "vbf_mlj1";
  TString histname_vbf_summlj     = "vbf_summlj";
  TString histname_vbf_ht         = "vbf_ht";
  TString histname_vbf_methtratio = "vbf_methtratio";
  TString histname_vbf_lepid      = "vbf_lepid";

  // mll bin
  float mllbin[5] = {5., 10., 20., 30., 50.};
}










//======================================================================================
//
//
//
//
// Main (The "Event Loop")
//
//
//
//
//======================================================================================

//__________________________________________________________________________________________________
int MT2TreeLooper(TChain* chain, TString output_name, int nevents)
{

  // Before the loop set up some configuration, histograms and etc.
  beforeLoop(chain, output_name, nevents);

  // During the event loop process each event one by one
  loop();

  // After the loop is done, save histograms and etc.
  afterLoop();

  return 0;
}

//__________________________________________________________________________________________________
void beforeLoop(TChain* chain, TString output_name, int nevents)
{

  // Fun start ASCII art
  PrintUtilities::start();

  // Initialize configurations for event looping
  LoopUtilities::resetLoopCondition(chain, nevents);

  // Set whether the sample being processed is signal or not
  // by checking the output file name
  Vbf::is_signal = output_name.Contains("sig")
                || output_name.Contains("higgsino")
                || output_name.Contains("VBF");

  // Set output name (outputs are "output_name"_blah.root)
  Vbf::output_name = output_name;

  // bookISR histograms
  bookISRHistograms();

  // bookVBF histograms
  bookVBFHistograms();

}


//______________________________________________________________________________________
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
      // <3 of the code
      // Do whatever you want to in the following function for each event
      //=================================================================
      processMT2TreeEvent();

    } // End TTree loop

  } // End Loop over files
}


//______________________________________________________________________________________
void afterLoop()
{
  // Save plots
  PlotUtil::savePlots(Vbf::h_isr_1d, Vbf::output_name+".root");
  PlotUtil::savePlots(Vbf::h_vbf_1d, Vbf::output_name+"_vbf.root");
  PlotUtil::savePlots(Vbf::h_arxiv_1d, Vbf::output_name+"_arxiv.root");

  // Fun exit
  PrintUtilities::exit();
}

















//______________________________________________________________________________________
//
//
//
//
// Per event actions
//
//
//
//
//______________________________________________________________________________________


//______________________________________________________________________________________
void processMT2TreeEvent()
{
  // compute scale 1fb
  loadScale1fb();

  // If signal, we parse the generator level information to read the masses of the ewkinos
  parseEwkinoMasses();

  // select objects
  selectObjects();

  ////===============================================================================================
  ////
  ////
  //// reproduce ISR analysis
  ////
  ////
  ////===============================================================================================

  //// Reproduce ISR analysis
  //reproduceISRAnalysis();

  ////===============================================================================================
  ////
  ////
  //// develop VBF analysis
  ////
  ////
  ////===============================================================================================
  doVBFAnalysis();

  //===============================================================================================
  //
  //
  // compute acceptance
  //
  //
  //===============================================================================================
  //computeAcceptanceWrtArxiv1502_05044();

}













//______________________________________________________________________________________
//
//
//
//
// Any functions related to specific to MT2Tree interface
//
//   e.g.  Object selections / Event weighting / Parsing information related functions
//
//
//
//
//______________________________________________________________________________________

//______________________________________________________________________________________
void initMT2Tree()
{
  // Init the Class
  Vbf::mt2tree.Init(LoopUtilities::getCurrentTTree());
}

//______________________________________________________________________________________
void loadMT2TreeEvent()
{
  Vbf::mt2tree.LoadTree(LoopUtilities::getCurrentTTreeEventIndex());
  Vbf::mt2tree.GetEntry(LoopUtilities::getCurrentTTreeEventIndex());
}

//______________________________________________________________________________________
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

//______________________________________________________________________________________
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

//______________________________________________________________________________________
void parseEwkinoMasses()
{
  // Parse the ewkino mass
  if (Vbf::is_signal)
  {
    VBFSUSYUtilities::parseEwkinoMasses(Vbf::mt2tree.ngenStat23,
                                        Vbf::mt2tree.genStat23_pdgId,
                                        Vbf::mt2tree.genStat23_status,
                                        Vbf::mt2tree.genStat23_mass);
    VBFSUSYUtilities::parseProductionMode(Vbf::mt2tree.ngenStat23,
                                          Vbf::mt2tree.genStat23_pdgId,
                                          Vbf::mt2tree.genStat23_status);
  }
}

//______________________________________________________________________________________
void selectObjects()
{
  selectLeptons();
  selectJets();
  setMET();
}

//______________________________________________________________________________________
void selectLeptons()
{
  // Select leptons
  VBFSUSYUtilities::Leptons mt2tree_leptons = getLeptonsFromMT2Tree();
  VBFSUSYUtilities::selectVBFLeptons(mt2tree_leptons);
  VBFSUSYUtilities::selectISRLeptons(mt2tree_leptons);
  VBFSUSYUtilities::selectGoodLeptons(mt2tree_leptons);

}

//______________________________________________________________________________________
void selectJets()
{
  // Select jets
  VBFSUSYUtilities::Jets mt2tree_jets = getJetsFromMT2Tree();
  VBFSUSYUtilities::selectGoodJets(mt2tree_jets);
}

//______________________________________________________________________________________
void setMET()
{
  VBFSUSYUtilities::setMET(Vbf::mt2tree.met_pt);
  VBFSUSYUtilities::setMETphi(Vbf::mt2tree.met_phi);
}

//______________________________________________________________________________________
void loadScale1fb()
{
  Vbf::evt_scale1fb = Vbf::mt2tree.evt_scale1fb / LoopUtilities::getFractionOfBookedNEvents();
  if (Vbf::is_signal)
  {
    Vbf::evt_scale1fb = 1.;
  }
}















//______________________________________________________________________________________
//
//
//
//
// ISR analysis
//
//
//
//
//______________________________________________________________________________________

//______________________________________________________________________________________
void reproduceISRAnalysis()
{
  // if signal need to fill different histograms
  if (Vbf::is_signal)
    bookISRHistograms();
  // cutflow histogram
  if ((true))
  {
    fillISRCutflow(0);
    if ((VBFSUSYUtilities::getNSelectedGoodLeptons() == 2 && VBFSUSYUtilities::getLeadingGoodLepton().p4.Pt() < 30.))
    {
      fillISRCutflow(1);
      if ((VBFSUSYUtilities::isEEChannel()))
      {
        fillISRCutflow(2);
        if (VBFSUSYUtilities::getNBTaggedJetsWithCSVCut(0.46) == 0)
        {
          fillISRCutflow(3);
          if (VBFSUSYUtilities::getMll() < 50.)
          {
            fillISRCutflow(4);
            if (VBFSUSYUtilities::getPtll() > 3.)
            {
              fillISRCutflow(5);
              if (Vbf::mt2tree.met_pt > 125.)
              {
                fillISRCutflow(6);
                if (((Vbf::mt2tree.met_pt / Vbf::mt2tree.ht) > 0.6) && ((Vbf::mt2tree.met_pt / Vbf::mt2tree.ht) < 1.4))
                {
                  fillISRCutflow(7);
                  if (Vbf::mt2tree.ht > 100.)
                  {
                    fillISRCutflow(8);
                    if (VBFSUSYUtilities::getMll() > 4.)
                    {
                      fillISRCutflow(9);
                      if (fabs(VBFSUSYUtilities::getMll() - 9.75) > 0.75)
                      {
                        fillISRCutflow(10);
                        if (VBFSUSYUtilities::getMTleadLep() < 70. && VBFSUSYUtilities::getMTleadLep() < 70.)
                        {
                          fillISRCutflow(11);
                          if (VBFSUSYUtilities::getMtt() < 0. || VBFSUSYUtilities::getMtt() > 160.)
                          {
                            fillISRCutflow(12);
                            if      (Vbf::mt2tree.met_pt < 200.) { fillISRHistogram(Vbf::mee_low_name , VBFSUSYUtilities::getMll(), Vbf::evt_scale1fb); }
                            else if (Vbf::mt2tree.met_pt < 250.) { fillISRHistogram(Vbf::mee_med_name , VBFSUSYUtilities::getMll(), Vbf::evt_scale1fb); fillISRHistogram(Vbf::mll_med_name , VBFSUSYUtilities::getMll(), Vbf::evt_scale1fb); }
                            else                                 { fillISRHistogram(Vbf::mee_high_name, VBFSUSYUtilities::getMll(), Vbf::evt_scale1fb); fillISRHistogram(Vbf::mll_high_name, VBFSUSYUtilities::getMll(), Vbf::evt_scale1fb); }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      if ((VBFSUSYUtilities::isMMChannel()))
      {
        fillISRCutflow(13);
        if (VBFSUSYUtilities::getNBTaggedJetsWithCSVCut(0.46) == 0)
        {
          fillISRCutflow(14);
          if (VBFSUSYUtilities::getMll() < 50.)
          {
            fillISRCutflow(15);
            if (VBFSUSYUtilities::getPtll() > 3.)
            {
              fillISRCutflow(16);
              if (Vbf::mt2tree.met_pt > 125.)
              {
                fillISRCutflow(17);
                if (((Vbf::mt2tree.met_pt / Vbf::mt2tree.ht) > 0.6) && ((Vbf::mt2tree.met_pt / Vbf::mt2tree.ht) < 1.4))
                {
                  fillISRCutflow(18);
                  if (Vbf::mt2tree.ht > 100.)
                  {
                    fillISRCutflow(19);
                    if (VBFSUSYUtilities::getMll() > 4.)
                    {
                      fillISRCutflow(20);
                      if (fabs(VBFSUSYUtilities::getMll() - 9.75) > 0.75)
                      {
                        fillISRCutflow(21);
                        if (VBFSUSYUtilities::getMTleadLep() < 70. && VBFSUSYUtilities::getMTleadLep() < 70.)
                        {
                          fillISRCutflow(22);
                          if (VBFSUSYUtilities::getMtt() < 0. || VBFSUSYUtilities::getMtt() > 160.)
                          {
                            fillISRCutflow(23);
                            if      (Vbf::mt2tree.met_pt < 200.) { fillISRHistogram(Vbf::mmm_low_name , VBFSUSYUtilities::getMll(), Vbf::evt_scale1fb); }
                            else if (Vbf::mt2tree.met_pt < 250.) { fillISRHistogram(Vbf::mmm_med_name , VBFSUSYUtilities::getMll(), Vbf::evt_scale1fb); fillISRHistogram(Vbf::mll_med_name , VBFSUSYUtilities::getMll(), Vbf::evt_scale1fb); }
                            else                                 { fillISRHistogram(Vbf::mmm_high_name, VBFSUSYUtilities::getMll(), Vbf::evt_scale1fb); fillISRHistogram(Vbf::mll_high_name, VBFSUSYUtilities::getMll(), Vbf::evt_scale1fb); }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

//______________________________________________________________________________________
void bookISRHistograms()
{
  // Book histograms
  bookISRHistogram(Vbf::cutflow_name    , 50, 0., 50.);
  bookISRHistogram(Vbf::rawcutflow_name , 50, 0., 50.);
  bookISRHistogram(Vbf::mee_name        ,  4, Vbf::mllbin);
  bookISRHistogram(Vbf::mmm_name        ,  4, Vbf::mllbin);
  bookISRHistogram(Vbf::mee_low_name    ,  4, Vbf::mllbin);
  bookISRHistogram(Vbf::mee_med_name    ,  4, Vbf::mllbin);
  bookISRHistogram(Vbf::mee_high_name   ,  4, Vbf::mllbin);
  bookISRHistogram(Vbf::mmm_low_name    ,  4, Vbf::mllbin);
  bookISRHistogram(Vbf::mmm_med_name    ,  4, Vbf::mllbin);
  bookISRHistogram(Vbf::mmm_high_name   ,  4, Vbf::mllbin);
  bookISRHistogram(Vbf::mll_med_name    ,  4, Vbf::mllbin);
  bookISRHistogram(Vbf::mll_high_name   ,  4, Vbf::mllbin);
  bookISRHistogram(Vbf::nbjet25_name    ,  4, Vbf::mllbin);
  bookISRHistogram(Vbf::myNBjet25L_name ,  5, 0., 5.);
  bookISRHistogram(Vbf::myNBjet25M_name ,  5, 0., 5.);
}

//______________________________________________________________________________________
void bookISRHistogram(TString name, int nbins, float min, float max)
{
  if (Vbf::is_signal) name += VBFSUSYUtilities::getMassSuffixTString();
  PlotUtil::plot1D(name.Data(), -999, 0, Vbf::h_isr_1d, name.Data(), nbins, min, max);
}

//______________________________________________________________________________________
void bookISRHistogram(TString name, int nbins, const float* xbins)
{
  if (Vbf::is_signal) name += VBFSUSYUtilities::getMassSuffixTString();
  PlotUtil::plot1D(name.Data(), -999, 0, Vbf::h_isr_1d, name.Data(), nbins, xbins);
}

//______________________________________________________________________________________
void fillISRHistogram(TString name, float val, float wgt)
{
  if (Vbf::is_signal)
    name += VBFSUSYUtilities::getMassSuffixTString();
  PlotUtil::plot1D(name.Data(), val, wgt, Vbf::h_isr_1d);
}

//______________________________________________________________________________________
void fillISRCutflow(int cutflowbin)
{
  fillISRHistogram(Vbf::cutflow_name.Data()   , cutflowbin, Vbf::evt_scale1fb);
  fillISRHistogram(Vbf::rawcutflow_name.Data(), cutflowbin,                1.);
}

















//______________________________________________________________________________________
//
//
//
//
// VBF analysis
//
//
//
//
//______________________________________________________________________________________


//______________________________________________________________________________________
void doVBFAnalysis()
{

  if (Vbf::is_signal)
    bookVBFHistograms();

  if (true)
  {
    fillVBFCutflow(0);
    fillVBFHistograms("NoCut");
    if (VBFSUSYUtilities::getNSelectedGoodJets() >= 2)
    {
      fillVBFCutflow(1);
      fillVBFHistograms("NJetCut");
      if (VBFSUSYUtilities::getNSelectedSoftGoodLeptons() >= 1)
      {
        fillVBFCutflow(2);
        fillVBFHistograms("NSoftLepCut");
        if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId == 13)
        {
          fillVBFCutflow(3);
          fillVBFHistograms("AntiMuonCut");
          if (VBFSUSYUtilities::getMETp4().Pt() > 200.)
          {
            fillVBFCutflow(4);
            fillVBFHistograms("METCut");
            if (VBFSUSYUtilities::getVBFDEtajj() > 3.5)
            {
              fillVBFCutflow(5);
              fillVBFHistograms("DEtajjCut");
              if (VBFSUSYUtilities::getSubleadingVBFJet().p4.Pt() > 50.)
              {
                fillVBFCutflow(6);
                fillVBFHistograms("SubleadJetPtCut");
                if (VBFSUSYUtilities::getMTleadLep() < 50.)
                {
                  fillVBFCutflow(7);
                  fillVBFHistograms("MTCut");
                  if (VBFSUSYUtilities::getVBFMjj() > 1400.)
                  {
                    fillVBFCutflow(8);
                    fillVBFHistograms("MjjCut");
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}


//______________________________________________________________________________________
void bookVBFHistograms()
{
  // Book histogram that does not require "prefix" of the cut
  bookVBFHistogram(Vbf::histname_vbf_cutflow    ,  50,    0.,   50.);
  bookVBFHistogram(Vbf::histname_vbf_rawcutflow ,  50,    0.,   50.);
  // Book histograms
  bookVBFHistogramsWithPrefix("NoCut");
  bookVBFHistogramsWithPrefix("NJetCut");
  bookVBFHistogramsWithPrefix("NSoftLepCut");
  bookVBFHistogramsWithPrefix("AntiMuonCut");
  bookVBFHistogramsWithPrefix("SubleadJetPtCut");
  bookVBFHistogramsWithPrefix("METCut");
  bookVBFHistogramsWithPrefix("MTCut");
  bookVBFHistogramsWithPrefix("DEtajjCut");
  bookVBFHistogramsWithPrefix("CJVCut");
  bookVBFHistogramsWithPrefix("MjjCut");
  bookVBFHistogramsWithPrefix("MET200Cut");
}

//______________________________________________________________________________________
void bookVBFHistogramsWithPrefix(TString prefix)
{
  // Book histograms
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_nsoftleps  ,   5,   -1.,     4.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_njets      ,   5,    0.,     5.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_mjj        , 180,    0.,  2500.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_detajj     , 180,    0.,     9.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_dphijj     , 180,    0.,     3.1416);
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_cenjetpt   , 180,  -30.,   150.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_leadleppt  , 180,    0.,    35.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_met        , 180,    0.,   450.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_leadjetpt  , 180,    0.,   350.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_subljetpt  , 180,    0.,   150.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_lepcent    , 180,    0.,     3.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_mt         , 180,    0.,   150.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_mlj0       , 180,    0.,   250.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_mlj1       , 180,    0.,   250.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_summlj     , 180,    0.,   750.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_ht         , 180,    0.,   350.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_methtratio , 180,    0.,     4.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_lepid      ,   4,    0.,     4.    );
}

//______________________________________________________________________________________
void fillVBFHistograms(TString cutprefix)
{

  fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_nsoftleps, VBFSUSYUtilities::getNSelectedSoftGoodLeptons()      );
  fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_njets,     VBFSUSYUtilities::getNSelectedGoodJets()             );

  if (VBFSUSYUtilities::getNSelectedGoodJets() >= 2)
  {
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_mjj,       VBFSUSYUtilities::getVBFMjj()                      );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_detajj,    VBFSUSYUtilities::getVBFDEtajj()                   );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_dphijj,    VBFSUSYUtilities::getVBFDPhijj()                   );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_met      , VBFSUSYUtilities::getMETp4().Pt()                  );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_leadjetpt, VBFSUSYUtilities::getLeadingVBFJet().p4.Pt()       );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_subljetpt, VBFSUSYUtilities::getSubleadingVBFJet().p4.Pt()    );

    if (VBFSUSYUtilities::getNSelectedGoodJets() > 2)
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_cenjetpt,  VBFSUSYUtilities::getLeadCenJetPt()                );

    if (VBFSUSYUtilities::getNSelectedGoodLeptons() > 0)
    {
      fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_leadleppt  , VBFSUSYUtilities::getLeadingGoodLepton().p4.Pt()  );
      fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_lepcent    , VBFSUSYUtilities::getLeptonCentrality()           );
      fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_mt         , VBFSUSYUtilities::getMTleadLep()                  );
      fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_mlj0       , VBFSUSYUtilities::getLeadMlj()                    );
      fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_mlj1       , VBFSUSYUtilities::getSubleadMlj()                 );
      fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_summlj     , VBFSUSYUtilities::getSumMlj()                     );
      fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_ht         , Vbf::mt2tree.ht                                   );
      fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_methtratio , Vbf::mt2tree.met_pt / Vbf::mt2tree.ht             );
      if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId == -11) fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_lepid , 0);
      if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId ==  11) fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_lepid , 1);
      if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId == -13) fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_lepid , 2);
      if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId ==  13) fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_lepid , 3);
    }
  }

}

//______________________________________________________________________________________
void bookVBFHistogram(TString name, int nbins, float min, float max)
{
  if (Vbf::is_signal) name = VBFSUSYUtilities::getSignalSuffix(name);
  PlotUtil::plot1D(name.Data(), -999, 0, Vbf::h_vbf_1d, name.Data(), nbins, min, max);
}

//______________________________________________________________________________________
void bookVBFHistogram(TString name, int nbins, const float* xbins)
{
  if (Vbf::is_signal) name = VBFSUSYUtilities::getSignalSuffix(name);
  PlotUtil::plot1D(name.Data(), -999, 0, Vbf::h_vbf_1d, name.Data(), nbins, xbins);
}

//______________________________________________________________________________________
void fillVBFHistogram(TString name, float val, float wgt)
{
  if (Vbf::is_signal)
    name = VBFSUSYUtilities::getSignalSuffix(name);
  if (wgt == -999)
    PlotUtil::plot1D(name.Data(), val, Vbf::evt_scale1fb, Vbf::h_vbf_1d);
  else
    PlotUtil::plot1D(name.Data(), val, wgt, Vbf::h_vbf_1d);
}

//______________________________________________________________________________________
void fillVBFCutflow(int cutflowbin)
{
  fillVBFHistogram(Vbf::histname_vbf_cutflow.Data()   , cutflowbin, Vbf::evt_scale1fb);
  fillVBFHistogram(Vbf::histname_vbf_rawcutflow.Data(), cutflowbin,                1.);
}



















//______________________________________________________________________________________
//
//
//
//
// Calculating acceptance to be able to use cross section from 1502_05044
//
//
//
//
//______________________________________________________________________________________

//______________________________________________________________________________________
void computeAcceptanceWrtArxiv1502_05044()
{
  if (!Vbf::output_name.Contains("VBF"))
    return;

  std::vector<int> LSPindices;
  for (int igen = 0; igen < Vbf::mt2tree.ngenStat23; ++igen)
  {
    if (Vbf::mt2tree.genStat23_pdgId[igen] == 1000022 && Vbf::mt2tree.genStat23_status[igen] == 1)
      LSPindices.push_back(igen);
  }

  if (LSPindices.size() != 2)
  {
    TString errormsg = TString::Format("Event #%d does not have two final state LSPs! (size = %d)", LoopUtilities::getCurrentTTreeEventIndex(), LSPindices.size());
    PrintUtilities::error(errormsg);
  }

  TString name = "arxiv_cutflow"; name = VBFSUSYUtilities::getSignalSuffix(name);

  // pass all
  PlotUtil::plot1D(name.Data(), 0, 1, Vbf::h_arxiv_1d, name.Data(), 2, 0, 2);

  TLorentzVector vbfparton0;
  TLorentzVector vbfparton1;
  vbfparton0.SetPtEtaPhiM(Vbf::mt2tree.genStat23_pt[4], Vbf::mt2tree.genStat23_eta[4], Vbf::mt2tree.genStat23_phi[4], Vbf::mt2tree.genStat23_mass[4]);
  vbfparton1.SetPtEtaPhiM(Vbf::mt2tree.genStat23_pt[5], Vbf::mt2tree.genStat23_eta[5], Vbf::mt2tree.genStat23_phi[5], Vbf::mt2tree.genStat23_mass[5]);
  if (vbfparton0.Pt() < 50. || vbfparton0.Pt() < 50.)
    return;

  TLorentzVector lspparton0;
  TLorentzVector lspparton1;
  lspparton0.SetPtEtaPhiM(Vbf::mt2tree.genStat23_pt[LSPindices[0]], Vbf::mt2tree.genStat23_eta[LSPindices[0]], Vbf::mt2tree.genStat23_phi[LSPindices[0]], Vbf::mt2tree.genStat23_mass[LSPindices[0]]);
  lspparton1.SetPtEtaPhiM(Vbf::mt2tree.genStat23_pt[LSPindices[1]], Vbf::mt2tree.genStat23_eta[LSPindices[1]], Vbf::mt2tree.genStat23_phi[LSPindices[1]], Vbf::mt2tree.genStat23_mass[LSPindices[1]]);

  if ( (lspparton0 + lspparton1).Pt() < 100. )
    return;

  // pass 1502_05044 selections (on figure 1. of their paper)
  PlotUtil::plot1D(name.Data(), 1, 1, Vbf::h_arxiv_1d, name.Data(), 2, 0, 2);

}













//eof
