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
  bool is_signal_tchiwz;
  TString output_name;
  PlotUtil::Hist_DB h_isr_1d;
  PlotUtil::Hist_DB h_vbf_1d;
  PlotUtil::Hist_DB h_vbf_2d;
  PlotUtil::Hist_DB h_arxiv_1d;
  PlotUtil::Hist_DB h_truth_1d;
  PlotUtil::Hist_DB h_truthlepaccept_1d;

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
  TString histname_vbf_cutflow          = "vbf_cutflow";
  TString histname_vbf_rawcutflow       = "vbf_rawcutflow";
  TString histname_vbf_nsoftleps        = "vbf_nsoftleps";
  TString histname_vbf_njets            = "vbf_njets";
  TString histname_vbf_nbjets           = "vbf_nbjets";
  TString histname_vbf_mjj              = "vbf_mjj";
  TString histname_vbf_detajj           = "vbf_detajj";
  TString histname_vbf_dphijj           = "vbf_dphijj";
  TString histname_vbf_cenjetpt         = "vbf_cenjetpt";
  TString histname_vbf_leadleppt        = "vbf_leadleppt";
  TString histname_vbf_leadlepeta       = "vbf_leadlepeta";
  TString histname_vbf_met              = "vbf_met";
  TString histname_vbf_leadjetpt        = "vbf_leadjetpt";
  TString histname_vbf_subljetpt        = "vbf_subljetpt";
  TString histname_vbf_leadjeteta       = "vbf_leadjeteta";
  TString histname_vbf_subljeteta       = "vbf_subljeteta";
  TString histname_vbf_leadjete         = "vbf_leadjete";
  TString histname_vbf_subljete         = "vbf_subljete";
  TString histname_vbf_leadjeteoverpt   = "vbf_leadjeteoverpt";
  TString histname_vbf_subljeteoverpt   = "vbf_subljeteoverpt";
  TString histname_vbf_lepcent          = "vbf_lepcent";
  TString histname_vbf_mt               = "vbf_mt";
  TString histname_vbf_modmt            = "vbf_modmt";
  TString histname_vbf_mlj0             = "vbf_mlj0";
  TString histname_vbf_mlj1             = "vbf_mlj1";
  TString histname_vbf_summlj           = "vbf_summlj";
  TString histname_vbf_ht               = "vbf_ht";
  TString histname_vbf_methtratio       = "vbf_methtratio";
  TString histname_vbf_lepid            = "vbf_lepid";
  TString histname_vbf_dphilepmet       = "vbf_dphilepmet";
  TString histname_vbf_sumpt            = "vbf_sumpt";
  TString histname_vbf_sumptall         = "vbf_sumptall";
  TString histname_vbf_dphileadjetmet   = "vbf_dphileadjetmet";
  TString histname_vbf_dphisubljetmet   = "vbf_dphisubljetmet";
  TString histname_vbf_dphileadjetlep   = "vbf_dphileadjetlep";
  TString histname_vbf_dphisubljetlep   = "vbf_dphisubljetlep";
  TString histname_vbf_dphidijetmet     = "vbf_dphidijetmet";
  TString histname_vbf_dphidijetlep     = "vbf_dphidijetlep";
  TString histname_vbf_metphicent       = "vbf_metphicent";
  TString histname_vbf_lepphicent       = "vbf_lepphicent";
  TString histname_vbf_metphicentboost  = "vbf_metphicentboost";
  TString histname_vbf_lepphicentboost  = "vbf_lepphicentboost";
  TString histname_vbf_dphidijetlepmet  = "vbf_dphidijetlepmet";
  TString histname_vbf_dphilepmetboost  = "vbf_dphilepmetboost";
  TString histname_vbf_dphilepmetwframe = "vbf_dphilepmetwframe";
  TString histname_vbf_dphileadjetmetlep= "vbf_dphileadjetmetlep";
  TString histname_vbf_dphisubljetmetlep= "vbf_dphisubljetmetlep";
  TString histname_vbf_dphidijetmetlep  = "vbf_dphidijetmetlep";
  TString histname_vbf_dptjet           = "vbf_dptjet";
  TString histname_vbf_ptrel            = "vbf_ptrel";
  TString histname_vbf_superptrel       = "vbf_superptrel";
  TString histname_vbf_superptrelnowgt  = "vbf_superptrelnowgt";
  TString histname_vbf_prodptrel        = "vbf_prodptrel";
  TString histname_vbf_metrel           = "vbf_metrel";
  TString histname_vbf_mtrel            = "vbf_mtrel";
  TString histname_vbf_cenjetdr         = "vbf_cenjetdr";
  // dilepton channel
  TString histname_vbf_mll          = "vbf_mll";
  TString histname_vbf_dphill       = "vbf_dphill";
  TString histname_vbf_ptll         = "vbf_ptll";
  TString histname_vbf_sublleppt    = "vbf_sublleppt";
  TString histname_vbf_dilepchannel = "vbf_dilepchannel";
  TString histname_vbf_mtt          = "vbf_mtt";
  TString histname_vbf_multibin     = "vbf_multibin";

  // 2d histogram
  TString histname_vbf_met_v_dphilepmet = "vbf2d_met_v_dphilepmet";

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
                || output_name.Contains("TChiWZ")
                || output_name.Contains("VBF");
  Vbf::is_signal_tchiwz = output_name.Contains("TChiWZ");

  // Set output name (outputs are "output_name"_blah.root)
  Vbf::output_name = output_name;

  if (!Vbf::is_signal)
  {
    // bookISR histograms
    //bookISRHistograms();

    // bookVBF histograms
    bookVBFHistograms();
  }

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
  PlotUtil::savePlots(Vbf::h_vbf_2d, Vbf::output_name+"_vbf_2d.root");
  PlotUtil::savePlots(Vbf::h_arxiv_1d, Vbf::output_name+"_arxiv.root");
  PlotUtil::savePlots(Vbf::h_truth_1d, Vbf::output_name+"_truth.root");
  PlotUtil::savePlots(Vbf::h_truthlepaccept_1d, Vbf::output_name+"_truth.root");

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

  // select objects
  selectObjects();

  // Correct N2 for signal samples (if returned false, move on to next event)
  if (!correctN2()) return;

  //// if both are N2, skip
  //if (Vbf::mt2tree.genStat23_pdgId[2] == 1000023 && Vbf::mt2tree.genStat23_pdgId[3] == 1000023)
  //  return;

  //// if either of the produced susy does not have N2 skip
  //if (Vbf::mt2tree.genStat23_pdgId[2] != 1000023 && Vbf::mt2tree.genStat23_pdgId[3] != 1000023)
  //  return;


  // If signal, we parse the generator level information to read the masses of the ewkinos
  parseEwkinoMasses();

  //===============================================================================================
  //
  //
  // reproduce ISR analysis
  //
  //
  //===============================================================================================

  // Reproduce ISR analysis
  //reproduceISRAnalysis();

  //===============================================================================================
  //
  //
  // develop VBF analysis
  //
  //
  //===============================================================================================
  doVBFAnalysis();

  //===============================================================================================
  //
  //
  // truth level VBF analysis
  //
  //
  //===============================================================================================
  //truthVBFAnalysis();

  //===============================================================================================
  //
  //
  // compute acceptance
  //
  //
  //===============================================================================================
  //computeAcceptanceWrtArxiv1502_05044();

  //===============================================================================================
  //
  //
  // compute lepton acceptance from TChiWZ truth
  //
  //
  //===============================================================================================
  //truthTChiWZLeptonAcceptance();

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
VBFSUSYUtilities::Truths getTruthsFromMT2Tree()
{
  VBFSUSYUtilities::Truths truths;
  for (int igen = 0; igen < Vbf::mt2tree.ngenStat23; ++igen)
  {
    VBFSUSYUtilities::Truth truth;
    truth.truth_pt            = Vbf::mt2tree.genStat23_pt[igen];
    truth.truth_eta           = Vbf::mt2tree.genStat23_eta[igen];
    truth.truth_phi           = Vbf::mt2tree.genStat23_phi[igen];
    truth.truth_mass          = Vbf::mt2tree.genStat23_mass[igen];
    truth.truth_pdgId         = Vbf::mt2tree.genStat23_pdgId[igen];
    truth.truth_sourceId      = Vbf::mt2tree.genStat23_sourceId[igen];
    truth.p4.SetPtEtaPhiM(truth.truth_pt, truth.truth_eta, truth.truth_phi, truth.truth_mass);
    truths.push_back(truth);
  }
  return truths;
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
bool correctN2()
{
  if (Vbf::is_signal_tchiwz)
  {
    //std::cout << "before" << VBFSUSYUtilities::getNSelectedGoodLeptons() << " " << VBFSUSYUtilities::getMETp4().Pt() << " " << VBFSUSYUtilities::getMETp4().Phi()<< std::endl;
    bool res =  VBFSUSYUtilities::correctTChiWZ_ZLLFilter(Vbf::mt2tree.ngenStat23,
                                                          Vbf::mt2tree.genStat23_pdgId,
                                                          Vbf::mt2tree.genStat23_sourceId,
                                                          Vbf::mt2tree.genStat23_mass,
                                                          Vbf::mt2tree.genStat23_pt,
                                                          Vbf::mt2tree.genStat23_eta,
                                                          Vbf::mt2tree.genStat23_phi);
    //std::cout << "after " << VBFSUSYUtilities::getNSelectedGoodLeptons() << " " << VBFSUSYUtilities::getMETp4().Pt() << " " << VBFSUSYUtilities::getMETp4().Phi()<< std::endl;
    return res;
  }
  else if (Vbf::is_signal)
  {
    //std::cout << "before" << VBFSUSYUtilities::getNSelectedGoodLeptons() << " " << VBFSUSYUtilities::getMETp4().Pt() << " " << VBFSUSYUtilities::getMETp4().Phi()<< std::endl;
    bool res =  VBFSUSYUtilities::correctN2(Vbf::mt2tree.ngenStat23,
                                            Vbf::mt2tree.genStat23_pdgId,
                                            Vbf::mt2tree.genStat23_sourceId,
                                            Vbf::mt2tree.genStat23_mass,
                                            Vbf::mt2tree.genStat23_pt,
                                            Vbf::mt2tree.genStat23_eta,
                                            Vbf::mt2tree.genStat23_phi,
                                            Vbf::mt2tree.evt%2);
    //std::cout << "after " << VBFSUSYUtilities::getNSelectedGoodLeptons() << " " << VBFSUSYUtilities::getMETp4().Pt() << " " << VBFSUSYUtilities::getMETp4().Phi()<< std::endl;
    return res;
  }
  return true;
}

//______________________________________________________________________________________
void selectObjects()
{
  selectLeptons();
  selectJets();
  setMET();
  if (Vbf::output_name.Contains("TChiWZ"))
    selectTruths();
}

//______________________________________________________________________________________
void selectLeptons()
{
  // Select leptons
  VBFSUSYUtilities::Leptons mt2tree_leptons = getLeptonsFromMT2Tree();
  //VBFSUSYUtilities::selectVBFLeptons(mt2tree_leptons);
  //VBFSUSYUtilities::selectISRLeptons(mt2tree_leptons);
  VBFSUSYUtilities::selectGoodLeptons(mt2tree_leptons);

}

//______________________________________________________________________________________
void selectJets()
{
  // Select jets
  VBFSUSYUtilities::Jets mt2tree_jets = getJetsFromMT2Tree();
  VBFSUSYUtilities::selectGoodJets(mt2tree_jets);
  VBFSUSYUtilities::selectGoodBJets(mt2tree_jets);
}

//______________________________________________________________________________________
void selectTruths()
{
  // Select jets
  VBFSUSYUtilities::Truths mt2tree_truths = getTruthsFromMT2Tree();
  VBFSUSYUtilities::selectTruths(mt2tree_truths);
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
        if (VBFSUSYUtilities::getNSelectedGoodBJets() == 0)
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
        if (VBFSUSYUtilities::getNSelectedGoodBJets() == 0)
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
    fillVBFCutflow(__COUNTER__);
    fillVBFHistograms("NoCut");
    if (VBFSUSYUtilities::getMETp4().Pt() > 200.)
    {
      fillVBFCutflow(__COUNTER__);
      fillVBFHistograms("METCut");
      if (VBFSUSYUtilities::getNSelectedSoftGoodLeptons() >= 1)
      {
        fillVBFCutflow(__COUNTER__);
        fillVBFHistograms("OneLepInclCut");
        if (VBFSUSYUtilities::getNSelectedSoftGoodLeptons() == 1)
        {
          fillVBFCutflow(__COUNTER__);
          fillVBFHistograms("OneLepCut");
          if (VBFSUSYUtilities::getMTleadLep() < 40.)
          {
            fillVBFCutflow(__COUNTER__);
            fillVBFHistograms("MTCut");
            if (VBFSUSYUtilities::getNSelectedGoodJets() >= 2)
            {
              fillVBFCutflow(__COUNTER__);
              fillVBFHistograms("NJetCut");
              if (VBFSUSYUtilities::getSubleadingVBFJet().p4.Pt() > 50.)
              {
                fillVBFCutflow(__COUNTER__);
                fillVBFHistograms("SubleadJetPtCut");
                if (VBFSUSYUtilities::getVBFDEtajj() > 3.8)
                {
                  fillVBFCutflow(__COUNTER__);
                  fillVBFHistograms("DEtajjCut");
                  // 1 lepton case
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
  int cutflow_nbin = __COUNTER__;
  bool alreadyprocessed = bookVBFHistogram(Vbf::histname_vbf_cutflow,  cutflow_nbin, 0., cutflow_nbin);
  if (alreadyprocessed) return;
  bookVBFHistogram(Vbf::histname_vbf_rawcutflow, cutflow_nbin, 0., cutflow_nbin);

  // Book histograms
  bookVBFHistogramsWithPrefix("NoCut");
  bookVBFHistogramsWithPrefix("METCut");
  bookVBFHistogramsWithPrefix("OneLepInclCut");
  bookVBFHistogramsWithPrefix("PreselCut");
  bookVBFHistogramsWithPrefix("NJetCut");
  bookVBFHistogramsWithPrefix("DEtajjCut");
  bookVBFHistogramsWithPrefix("OneLepCut");
  bookVBFHistogramsWithPrefix("SubleadJetPtCut");
  bookVBFHistogramsWithPrefix("MTCut");
}

//______________________________________________________________________________________
void bookVBFHistogramsWithPrefix(TString prefix)
{
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_nsoftleps       ,   5,   -1.  ,     4.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_njets           ,   5,    0.  ,     5.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_nbjets          ,   5,    0.  ,     5.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_mjj             , 180,    0.    ,  3500.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_detajj          , 180,    0.    ,     9.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_dphijj          , 180,    0.    ,     3.1416);
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_cenjetpt        , 180,  -30.    ,   150.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_leadleppt       , 180,    0.    ,    35.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_leadlepeta      , 180,   -3.    ,     3.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_met             , 180,    0.    ,   450.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_leadjetpt       , 180,    0.    ,   350.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_subljetpt       , 180,    0.    ,   150.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_leadjeteta      , 180,   -5.    ,     5.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_subljeteta      , 180,   -5.    ,     5.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_leadjete        , 180,    0.    ,  1750.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_subljete        , 180,    0.    ,  1500.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_leadjeteoverpt  , 180,    0.    ,     5.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_subljeteoverpt  , 180,    0.    ,     5.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_lepcent         , 180,    0.    ,     3.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_mt              , 180,    0.    ,   150.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_modmt           , 180,    0.    ,    10.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_mlj0            , 180,    0.    ,   250.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_mlj1            , 180,    0.    ,   250.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_summlj          , 180,    0.    ,   750.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_ht              , 180,    0.    ,   350.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_methtratio      , 180,    0.    ,     4.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_lepid           ,   4,    0.    ,     4.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_dphilepmet      , 180,    0.    ,     3.1416);
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_sumpt           , 180,    0.    ,   100.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_sumptall        , 180,    0.    ,   100.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_dphileadjetmet  , 180,    0.    ,     3.1416);
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_dphisubljetmet  , 180,    0.    ,     3.1416);
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_dphileadjetlep  , 180,    0.    ,     3.1416);
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_dphisubljetlep  , 180,    0.    ,     3.1416);
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_dphidijetmet    , 180,    0.    ,     3.1416);
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_dphidijetlep    , 180,    0.    ,     3.1416);
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_metphicent      , 180,   -1.42  ,     1.42  );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_lepphicent      , 180,   -1.42  ,     1.42  );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_dphidijetlepmet , 180,    0.    ,     3.1416);
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_dphilepmetboost , 180,    0.    ,     3.1416);
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_dphileadjetmetlep, 180,    0.    ,     3.1416);
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_dphisubljetmetlep, 180,    0.    ,     3.1416);
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_dphidijetmetlep  , 180,    0.    ,     3.1416);
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_dptjet          , 180,    0.    ,    300.   );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_ptrel           , 180,    0.    ,     30.   );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_superptrel      , 180,    0.    ,    100.   );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_superptrelnowgt , 180,    0.    ,    100.   );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_prodptrel       , 180,    0.    ,    100.   );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_metrel          , 180, -200.    ,    600.   );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_mtrel           , 180,  -50.    ,    200. );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_cenjetdr        , 180,    0.    ,      9.   );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_mll             , 180,    0.    ,    30.0   );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_dphill          , 180,    0.    ,     3.1416);
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_ptll            , 180,    0.    ,    30.0   );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_sublleppt       , 180,    0.    ,    20.0   );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_dilepchannel    ,   4,    0.    ,     4.    );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_mtt             , 180,    0.    ,    60.0   );
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_multibin        ,   9,    0.    ,     9.    );

  // 2d histograms
  bookVBFHistogram(prefix + "_" + Vbf::histname_vbf_met_v_dphilepmet,  10,    0.    ,   450.    ,  10,    0.     , 3.1416);

}

//______________________________________________________________________________________
void fillVBFHistograms(TString cutprefix_)
{

  fillVBFHistogram(cutprefix_ + "_" + Vbf::histname_vbf_nsoftleps, VBFSUSYUtilities::getNSelectedSoftGoodLeptons()      );
  fillVBFHistogram(cutprefix_ + "_" + Vbf::histname_vbf_njets,     VBFSUSYUtilities::getNSelectedGoodJets()             );
  fillVBFHistogram(cutprefix_ + "_" + Vbf::histname_vbf_nbjets,    VBFSUSYUtilities::getNSelectedGoodBJets()            );

  TString cutprefix = cutprefix_;

  if (VBFSUSYUtilities::getNSelectedGoodJets() >= 2)
  {
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_mjj            , VBFSUSYUtilities::getVBFMjj()                                                                    );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_detajj         , VBFSUSYUtilities::getVBFDEtajj()                                                                 );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_dphijj         , VBFSUSYUtilities::getVBFDPhijj()                                                                 );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_met            , VBFSUSYUtilities::getMETp4().Pt()                                                                );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_leadjetpt      , VBFSUSYUtilities::getLeadingVBFJet().p4.Pt()                                                     );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_subljetpt      , VBFSUSYUtilities::getSubleadingVBFJet().p4.Pt()                                                  );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_cenjetpt       , VBFSUSYUtilities::getLeadCenJetPt()                                                              );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_leadjeteta     , VBFSUSYUtilities::getLeadingVBFJet().p4.Eta()                                                    );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_subljeteta     , VBFSUSYUtilities::getSubleadingVBFJet().p4.Eta()                                                 );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_leadjete       , VBFSUSYUtilities::getLeadingVBFJet().p4.E()                                                      );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_subljete       , VBFSUSYUtilities::getSubleadingVBFJet().p4.E()                                                   );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_leadjeteoverpt , VBFSUSYUtilities::getLeadingVBFJet().p4.E() / VBFSUSYUtilities::getLeadingVBFJet().p4.Pt()       );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_subljeteoverpt , VBFSUSYUtilities::getSubleadingVBFJet().p4.E() / VBFSUSYUtilities::getSubleadingVBFJet().p4.Pt() );
  }

  if (VBFSUSYUtilities::getNSelectedGoodLeptons() > 0)
  {
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_leadleppt       , VBFSUSYUtilities::getLeadingGoodLepton().p4.Pt()  );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_leadlepeta      , VBFSUSYUtilities::getLeadingGoodLepton().p4.Eta() );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_mt              , VBFSUSYUtilities::getMTleadLep()                  );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_modmt           , VBFSUSYUtilities::getModMTleadLep()               );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_ht              , VBFSUSYUtilities::getHT()                         );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_methtratio      , Vbf::mt2tree.met_pt / VBFSUSYUtilities::getHT()   );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_dphilepmet      , VBFSUSYUtilities::getDPhiLepMET()                 );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_ptrel           , VBFSUSYUtilities::getLeadLepPtRel()               );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_metrel          , VBFSUSYUtilities::getLeadLepMETRel()              );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_mtrel           , VBFSUSYUtilities::getMTRel()                      );
    if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId == -11) fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_lepid , 0);
    if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId ==  11) fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_lepid , 1);
    if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId == -13) fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_lepid , 2);
    if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId ==  13) fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_lepid , 3);
    fillVBFHistogram2D(cutprefix + "_" + Vbf::histname_vbf_met_v_dphilepmet, VBFSUSYUtilities::getMETp4().Pt(), VBFSUSYUtilities::getDPhiLepMET());
  }

  if ((VBFSUSYUtilities::getNSelectedGoodJets() >= 2) && (VBFSUSYUtilities::getNSelectedGoodLeptons() > 0))
  {
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_lepcent         , VBFSUSYUtilities::getLeptonCentrality()           );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_mlj0            , VBFSUSYUtilities::getLeadMlj()                    );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_mlj1            , VBFSUSYUtilities::getSubleadMlj()                 );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_summlj          , VBFSUSYUtilities::getSumMlj()                     );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_sumpt           , VBFSUSYUtilities::getVecSumPt()                   );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_sumptall        , VBFSUSYUtilities::getVecSumPtAll()                );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_dphileadjetmet  , VBFSUSYUtilities::getDPhiLeadJetMET()             );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_dphisubljetmet  , VBFSUSYUtilities::getDPhiSubleadJetMET()          );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_dphileadjetlep  , VBFSUSYUtilities::getDPhiLeadJetLep()             );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_dphisubljetlep  , VBFSUSYUtilities::getDPhiSubleadJetLep()          );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_dphidijetmet    , VBFSUSYUtilities::getDPhiDiJetMET()               );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_dphidijetlep    , VBFSUSYUtilities::getDPhiDiJetLep()               );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_metphicent      , VBFSUSYUtilities::getMETPhiCent()                 );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_lepphicent      , VBFSUSYUtilities::getLepPhiCent()                 );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_dphidijetlepmet , VBFSUSYUtilities::getDPhiDiJetLepMet()            );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_dphilepmetboost , VBFSUSYUtilities::getDPhiLepMETInvDijetFrame()    );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_dphileadjetmetlep,VBFSUSYUtilities::getDPhiLeadJetMetLep()            );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_dphisubljetmetlep,VBFSUSYUtilities::getDPhiSubleadJetMetLep()            );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_dphidijetmetlep  ,VBFSUSYUtilities::getDPhiDiJetMetLep()            );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_dptjet          , VBFSUSYUtilities::getDPtJet()                     );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_cenjetdr        , VBFSUSYUtilities::getMinDRLeadCenJet()            );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_superptrel      , VBFSUSYUtilities::getSuperPtRel()                 );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_superptrelnowgt , VBFSUSYUtilities::getSuperPtRelNoWgt()            );
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_prodptrel       , VBFSUSYUtilities::getProdPtRel()                  );
    fillMultiBin(cutprefix);
  }

  if (VBFSUSYUtilities::getNSelectedGoodLeptons() > 1)
  {
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_mll       , VBFSUSYUtilities::getMll());
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_dphill    , VBFSUSYUtilities::getDPhill());
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_ptll      , VBFSUSYUtilities::getPtll());
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_sublleppt , VBFSUSYUtilities::getSubleadingGoodLepton().p4.Pt());
    fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_mtt       , VBFSUSYUtilities::getMtt());
    int leadid = VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId;
    int sublid = VBFSUSYUtilities::getSubleadingGoodLepton().lep_pdgId;
    if (leadid * sublid > 0) fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_dilepchannel, 0);
    else if (leadid * sublid == -121) fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_dilepchannel, 1);
    else if (leadid * sublid == -143) fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_dilepchannel, 2);
    else if (leadid * sublid == -169) fillVBFHistogram(cutprefix + "_" + Vbf::histname_vbf_dilepchannel, 3);
    else PrintUtilities::error("two lepton events were not categorized correctly. Check your leptons");
  }

}

//______________________________________________________________________________________
int getMultiBinIndex()
{
  // if no lepton skip
  if (VBFSUSYUtilities::getNSelectedGoodLeptons() < 1)
    return -1;

  // if no two jets skip
  if (VBFSUSYUtilities::getNSelectedGoodJets() < 2)
    return -1;

  int met_bin_idx = -1;
  int mjj_bin_idx = -1;
  int lpt_bin_idx = -1;

  float met = VBFSUSYUtilities::getMETp4().Pt();
  float mjj = VBFSUSYUtilities::getVBFMjj();
  float lpt = VBFSUSYUtilities::getLeadingGoodLepton().p4.Pt();

  // TODO: generalize the function
  // MET [200 ,  300 ,  400 , inf]
  // Mjj [500 , 1000 , 1500 , inf]
  // lPt [  5 ,   10 ,   20 ,  30]

  if      (met <  200) met_bin_idx = -1;
  else if (met <  300) met_bin_idx =  0;
  else if (met <  400) met_bin_idx =  1;
  else                 met_bin_idx =  2;

  if      (mjj <  500) mjj_bin_idx = -1;
  else if (mjj < 1000) mjj_bin_idx =  0;
  else                 mjj_bin_idx =  1;
  //else if (mjj < 1500) mjj_bin_idx =  1;
  //else                 mjj_bin_idx =  2;

  if      (lpt <   10) lpt_bin_idx =  2;
  else if (lpt <   20) lpt_bin_idx =  1;
  else if (lpt <   30) lpt_bin_idx =  0;
  else                 lpt_bin_idx = -1;

  // if any of them don't fall into the bin return -1
  if (met_bin_idx < 0 || mjj_bin_idx < 0 || lpt_bin_idx < 0) return -1;

  return 1 * met_bin_idx + 3 * lpt_bin_idx;
  //return 1 * lpt_bin_idx + 3 * met_bin_idx;
  //return 1 * lpt_bin_idx + 3 * met_bin_idx;

}

//______________________________________________________________________________________
void fillMultiBin(TString cutname)
{
  TString name = cutname + "_" + Vbf::histname_vbf_multibin;
  if (Vbf::is_signal) name = VBFSUSYUtilities::getSignalSuffix(name);
  PlotUtil::plot1D(name.Data(), getMultiBinIndex(), Vbf::evt_scale1fb, Vbf::h_vbf_1d);
}

//______________________________________________________________________________________
bool bookVBFHistogram(TString name, int nbins, float min, float max)
{
  if (Vbf::is_signal) name = VBFSUSYUtilities::getSignalSuffix(name);
  return PlotUtil::plot1D(name.Data(), -999, 0, Vbf::h_vbf_1d, name.Data(), nbins, min, max);
}

//______________________________________________________________________________________
bool bookVBFHistogram(TString name, int nbins, const float* xbins)
{
  if (Vbf::is_signal) name = VBFSUSYUtilities::getSignalSuffix(name);
  return PlotUtil::plot1D(name.Data(), -999, 0, Vbf::h_vbf_1d, name.Data(), nbins, xbins);
}

//______________________________________________________________________________________
bool bookVBFHistogram(TString name, int nbins, float min, float max, int nbinsy, float ymin, float ymax)
{
  if (Vbf::is_signal) name = VBFSUSYUtilities::getSignalSuffix(name);
  return PlotUtil::plot2D(name.Data(), -999, -999, 0, Vbf::h_vbf_2d, name.Data(), nbins, min, max, nbinsy, ymin, ymax);
}

//______________________________________________________________________________________
bool bookVBFHistogram(TString name, int nbins, const float* xbins, int nbinsy, const float* ybins)
{
  if (Vbf::is_signal) name = VBFSUSYUtilities::getSignalSuffix(name);
  return PlotUtil::plot2D(name.Data(), -999, -999, 0, Vbf::h_vbf_2d, name.Data(), nbins, xbins, nbinsy, ybins);
}

//______________________________________________________________________________________
void fillVBFHistogram(TString name, float val, float wgt)
{
  if (Vbf::is_signal)
    name = VBFSUSYUtilities::getSignalSuffix(name);
  if (wgt == -999)
    PlotUtil::plot1D(name.Data(), val, Vbf::evt_scale1fb, Vbf::h_vbf_1d);
  else
    PlotUtil::plot1D(name.Data(), val,               wgt, Vbf::h_vbf_1d);
}

//______________________________________________________________________________________
void fillVBFHistogram2D(TString name, float val, float yval, float wgt)
{
  if (Vbf::is_signal)
    name = VBFSUSYUtilities::getSignalSuffix(name);
  if (wgt == -999)
    PlotUtil::plot2D(name.Data(), val, yval, Vbf::evt_scale1fb, Vbf::h_vbf_2d);
  else
    PlotUtil::plot2D(name.Data(), val, yval,               wgt, Vbf::h_vbf_2d);
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
// truth VBF analysis
//
//
//
//
//______________________________________________________________________________________

//______________________________________________________________________________________
void truthVBFAnalysis()
{

  // if not VBF sample no need to do anything
  if (!Vbf::output_name.Contains("VBF"))
    return;

  // obtaining LSPs and leptons
  std::vector<int> LSPindices;
  std::vector<int> leptonindices;
  for (int igen = 0; igen < Vbf::mt2tree.ngenStat23; ++igen)
  {
    if (Vbf::mt2tree.genStat23_pdgId[igen] == 1000022 && Vbf::mt2tree.genStat23_status[igen] == 1)
      LSPindices.push_back(igen);
    if (abs(Vbf::mt2tree.genStat23_pdgId[igen]) == 11 || abs(Vbf::mt2tree.genStat23_pdgId[igen]) == 13 || abs(Vbf::mt2tree.genStat23_pdgId[igen]) == 15)
      leptonindices.push_back(igen);
  }

  // parse VBF partons
  TLorentzVector vbfparton0;
  TLorentzVector vbfparton1;
  vbfparton0.SetPtEtaPhiM(Vbf::mt2tree.genStat23_pt[4], Vbf::mt2tree.genStat23_eta[4], Vbf::mt2tree.genStat23_phi[4], Vbf::mt2tree.genStat23_mass[4]);
  vbfparton1.SetPtEtaPhiM(Vbf::mt2tree.genStat23_pt[5], Vbf::mt2tree.genStat23_eta[5], Vbf::mt2tree.genStat23_phi[5], Vbf::mt2tree.genStat23_mass[5]);

  // check I got two LSPs
  if (LSPindices.size() != 2)
  {
    TString errormsg = TString::Format("Event #%d does not have two final state LSPs! (size = %d)", LoopUtilities::getCurrentTTreeEventIndex(), (int) LSPindices.size());
    PrintUtilities::error(errormsg);
  }

  // parse LSP partons
  TLorentzVector lspparton0;
  TLorentzVector lspparton1;
  lspparton0.SetPtEtaPhiM(Vbf::mt2tree.genStat23_pt[LSPindices[0]], Vbf::mt2tree.genStat23_eta[LSPindices[0]], Vbf::mt2tree.genStat23_phi[LSPindices[0]], Vbf::mt2tree.genStat23_mass[LSPindices[0]]);
  lspparton1.SetPtEtaPhiM(Vbf::mt2tree.genStat23_pt[LSPindices[1]], Vbf::mt2tree.genStat23_eta[LSPindices[1]], Vbf::mt2tree.genStat23_phi[LSPindices[1]], Vbf::mt2tree.genStat23_mass[LSPindices[1]]);

  // parse leptons
  TLorentzVector lep0;
  TLorentzVector lep1;
  TLorentzVector lep2;
  if (leptonindices.size() > 0)
  lep0.SetPtEtaPhiM(Vbf::mt2tree.genStat23_pt[leptonindices[0]], Vbf::mt2tree.genStat23_eta[leptonindices[0]], Vbf::mt2tree.genStat23_phi[leptonindices[0]], Vbf::mt2tree.genStat23_mass[leptonindices[0]]);
  if (leptonindices.size() > 1)
  lep1.SetPtEtaPhiM(Vbf::mt2tree.genStat23_pt[leptonindices[1]], Vbf::mt2tree.genStat23_eta[leptonindices[1]], Vbf::mt2tree.genStat23_phi[leptonindices[1]], Vbf::mt2tree.genStat23_mass[leptonindices[1]]);
  if (leptonindices.size() > 2)
  lep2.SetPtEtaPhiM(Vbf::mt2tree.genStat23_pt[leptonindices[2]], Vbf::mt2tree.genStat23_eta[leptonindices[2]], Vbf::mt2tree.genStat23_phi[leptonindices[2]], Vbf::mt2tree.genStat23_mass[leptonindices[2]]);

  // form combined objects
  TLorentzVector dijet = vbfparton0 + vbfparton1;
  TLorentzVector dilsp = lspparton0 + lspparton1;

  // setting up histogram names
  TString histname_prodmode = "truth_prodmode"; histname_prodmode+= VBFSUSYUtilities::getMassSuffixTString();
  TString histname_mjj      = "truth_mjj";      histname_mjj      = VBFSUSYUtilities::getSignalSuffix(histname_mjj);
  TString histname_detajj   = "truth_detajj";   histname_detajj   = VBFSUSYUtilities::getSignalSuffix(histname_detajj);
  TString histname_dphijj   = "truth_dphijj";   histname_dphijj   = VBFSUSYUtilities::getSignalSuffix(histname_dphijj);
  TString histname_met      = "truth_met";      histname_met      = VBFSUSYUtilities::getSignalSuffix(histname_met);
  TString histname_nlep     = "truth_nlep";     histname_nlep     = VBFSUSYUtilities::getSignalSuffix(histname_nlep);
  TString histname_lep_pt0  = "truth_lep_pt0";  histname_lep_pt0  = VBFSUSYUtilities::getSignalSuffix(histname_lep_pt0);
  TString histname_lep_pt1  = "truth_lep_pt1";  histname_lep_pt1  = VBFSUSYUtilities::getSignalSuffix(histname_lep_pt1);
  TString histname_lep_pt2  = "truth_lep_pt2";  histname_lep_pt2  = VBFSUSYUtilities::getSignalSuffix(histname_lep_pt2);
  TString histname_jet_pt0  = "truth_jet_pt0";  histname_jet_pt0  = VBFSUSYUtilities::getSignalSuffix(histname_jet_pt0);
  TString histname_jet_pt1  = "truth_jet_pt1";  histname_jet_pt1  = VBFSUSYUtilities::getSignalSuffix(histname_jet_pt1);

  float nlep    = leptonindices.size();
  float mjj     = dijet.M();
  float detajj  = fabs(vbfparton0.Eta() - vbfparton1.Eta());
  float dphijj  = fabs(vbfparton0.DeltaPhi(vbfparton1));
  float met     = dilsp.Pt();
  float lep_pt0 = nlep > 0 ? lep0.Pt() : -999;
  float lep_pt1 = nlep > 1 ? lep1.Pt() : -999;
  float lep_pt2 = nlep > 2 ? lep2.Pt() : -999;
  float jet_pt0 = vbfparton0.Pt();
  float jet_pt1 = vbfparton1.Pt();

  // pass 1502_05044 selections (on figure 1. of their paper)
  PlotUtil::plot1D(histname_mjj    .Data() , mjj     , 1 , Vbf::h_truth_1d , histname_mjj    .Data() , 180. , 0 , 3500.     );
  PlotUtil::plot1D(histname_detajj .Data() , detajj  , 1 , Vbf::h_truth_1d , histname_detajj .Data() , 180. , 0 ,    9.     );
  PlotUtil::plot1D(histname_dphijj .Data() , dphijj  , 1 , Vbf::h_truth_1d , histname_dphijj .Data() , 180. , 0 ,    3.1416 );
  PlotUtil::plot1D(histname_met    .Data() , met     , 1 , Vbf::h_truth_1d , histname_met    .Data() , 180. , 0 ,  350.     );
  PlotUtil::plot1D(histname_nlep   .Data() , nlep    , 1 , Vbf::h_truth_1d , histname_nlep   .Data() ,   4. , 0 ,    4.     );
  PlotUtil::plot1D(histname_lep_pt0.Data() , lep_pt0 , 1 , Vbf::h_truth_1d , histname_lep_pt0.Data() , 180. , 0 ,   30.     );
  PlotUtil::plot1D(histname_lep_pt1.Data() , lep_pt1 , 1 , Vbf::h_truth_1d , histname_lep_pt1.Data() , 180. , 0 ,   30.     );
  PlotUtil::plot1D(histname_lep_pt2.Data() , lep_pt2 , 1 , Vbf::h_truth_1d , histname_lep_pt2.Data() , 180. , 0 ,   30.     );
  PlotUtil::plot1D(histname_jet_pt0.Data() , jet_pt0 , 1 , Vbf::h_truth_1d , histname_jet_pt0.Data() , 180. , 0 ,  250.     );
  PlotUtil::plot1D(histname_jet_pt1.Data() , jet_pt1 , 1 , Vbf::h_truth_1d , histname_jet_pt1.Data() , 180. , 0 ,  150.     );

  // fill by "production" mode
  PlotUtil::plot1D(histname_prodmode.Data(), VBFSUSYUtilities::getProductionMode(), 1, Vbf::h_truth_1d, histname_prodmode.Data(), 3, 0, 3);

}




























//______________________________________________________________________________________
//
//
//
//
// truth VBF analysis
//
//
//
//
//______________________________________________________________________________________

//______________________________________________________________________________________
void truthTChiWZLeptonAcceptance()
{

  if (!Vbf::output_name.Contains("TChiWZ"))
    return;

  if (VBFSUSYUtilities::eventHasTaus(Vbf::mt2tree.ngenStat23, Vbf::mt2tree.genStat23_pdgId))
    return;

  VBFSUSYUtilities::Truths w_leptons = VBFSUSYUtilities::getWLeptons();
  VBFSUSYUtilities::Truths z_leptons = VBFSUSYUtilities::getZLeptons();

  if (w_leptons.size() > 1)
  {
    VBFSUSYUtilities::printTruth(Vbf::mt2tree.ngenStat23, Vbf::mt2tree.genStat23_pdgId, Vbf::mt2tree.genStat23_sourceId, Vbf::mt2tree.genStat23_mass, Vbf::mt2tree.genStat23_pt, Vbf::mt2tree.genStat23_eta, Vbf::mt2tree.genStat23_phi);
    PrintUtilities::error("truthTChiWZLeptonAcceptance(): Found >1 leptons from W. somethings not right!");
  }

  for (auto& lep: w_leptons)
    PlotUtil::plot1D("wleppt" , lep.truth_pt, 1 , Vbf::h_truthlepaccept_1d , "wleppt" , 180. , 0 , 50.);

  if (z_leptons.size() != 2)
  {
    PrintUtilities::error("truthTChiWZLeptonAcceptance(): Found !=2 leptons from Z. somethings not right!");
  }

  float leadpt = z_leptons[0].truth_pt > z_leptons[1].truth_pt ? z_leptons[0].truth_pt : z_leptons[1].truth_pt;
  float sublpt = z_leptons[0].truth_pt > z_leptons[1].truth_pt ? z_leptons[1].truth_pt : z_leptons[0].truth_pt;

  PlotUtil::plot1D("zleppt"  , leadpt, 1 , Vbf::h_truthlepaccept_1d , "zleppt"  , 180. , 0 , 50.);
  PlotUtil::plot1D("zleppt"  , sublpt, 1 , Vbf::h_truthlepaccept_1d , "zleppt"  , 180. , 0 , 50.);
  PlotUtil::plot1D("zleppt0" , leadpt, 1 , Vbf::h_truthlepaccept_1d , "zleppt0" , 180. , 0 , 50.);
  PlotUtil::plot1D("zleppt1" , sublpt, 1 , Vbf::h_truthlepaccept_1d , "zleppt1" , 180. , 0 , 50.);

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
    TString errormsg = TString::Format("Event #%d does not have two final state LSPs! (size = %d)", LoopUtilities::getCurrentTTreeEventIndex(), (int) LSPindices.size());
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
              //if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId == 13)
              //{
              //  fillVBFCutflow(__COUNTER__);
              //  fillVBFHistograms("MMCut");
              //  if (VBFSUSYUtilities::getModMTleadLep() < 3.)
              //  {
              //    fillVBFCutflow(__COUNTER__);
              //    fillVBFHistograms("ModMTCut");
              //    if (VBFSUSYUtilities::getLeadingGoodLepton().p4.Pt() < 12.)
              //    {
              //      fillVBFCutflow(__COUNTER__);
              //      fillVBFHistograms("LeadPtCut");
              //      if (VBFSUSYUtilities::getNSelectedGoodBJets() == 0)
              //      {
              //        fillVBFCutflow(__COUNTER__);
              //        fillVBFHistograms("NBJetCut");
              //        if (VBFSUSYUtilities::getMETp4().Pt() > 300.)
              //        {
              //          fillVBFCutflow(__COUNTER__);
              //          fillVBFHistograms("MET300infCut");
              //        }
              //      }
              //    }
              //  }
              //}

//        //  // apply to all to get rid of low MET QCD junk and also helps reject W+jets for higher MET bins too
//        //  if (VBFSUSYUtilities::getSubleadingVBFJet().p4.Pt() > 50.)
//        //  {
//        //    fillVBFHistograms("SubleadJetPtCut");
//        //    if (VBFSUSYUtilities::getMETp4().Pt() > 200.)
//        //    {
//        //      fillVBFHistograms("METCut");
//        //      if (VBFSUSYUtilities::getNSelectedGoodBJets() == 0)
//        //      {
//        //        fillVBFHistograms("NBJetCut");
//        //        if (VBFSUSYUtilities::getModMTleadLep() < 3.)
//        //        {
//        //          fillVBFHistograms("ModMTCut");
//        //          if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId ==  13)
//        //          {
//        //            fillVBFHistograms("MMCut");
//        //          }
//        //          else if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId ==  11)
//        //          {
//        //            fillVBFHistograms("MPCut");
//        //          }
//        //          else if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId == -13)
//        //          {
//        //            fillVBFHistograms("EMCut");
//        //          }
//        //          else if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId == -11)
//        //          {
//        //            fillVBFHistograms("EPCut");
//        //          }
//        //        }
//        //      }
//        //    }
//
//        //    //int nbtag = VBFSUSYUtilities::getNBTaggedJetsWithCSVCut(0.46);
//        //    //// 100 - 200 MET bin
//        //    //if (VBFSUSYUtilities::getMETp4().Pt() > 100. && VBFSUSYUtilities::getMETp4().Pt() <= 200.)
//        //    //{
//        //    //  fillVBFCutflow(5);
//        //    //  fillVBFHistograms("MET100200Cut");
//        //    //  if (VBFSUSYUtilities::getLeadingGoodLepton().p4.Pt() < 10.)
//        //    //  {
//        //    //    fillVBFCutflow(6);
//        //    //    fillVBFHistograms("MET100200LeadLepPtCut");
//        //    //    if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId ==-11)
//        //    //    {
//        //    //      fillVBFHistograms("MET100200ElPlusCut");
//        //    //    }
//        //    //    if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId == 11)
//        //    //    {
//        //    //      fillVBFHistograms("MET100200ElMinusCut");
//        //    //    }
//        //    //    if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId ==-13)
//        //    //    {
//        //    //      fillVBFHistograms("MET100200MuPlusCut");
//        //    //    }
//        //    //    if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId == 13)
//        //    //    {
//        //    //      fillVBFHistograms("MET100200MuMinusCut");
//        //    //    }
//        //    //  }
//        //    //}
//
//        //    //// 200 - 300 MET bin
//        //    //if (VBFSUSYUtilities::getMETp4().Pt() > 200. && VBFSUSYUtilities::getMETp4().Pt() <= 300.)
//        //    //{
//        //    //  fillVBFCutflow(7);
//        //    //  fillVBFHistograms("MET200300Cut");
//        //    //  if (VBFSUSYUtilities::getMTleadLep() < 50.)
//        //    //  {
//        //    //    fillVBFCutflow(6);
//        //    //    fillVBFHistograms("MET200300MTCut");
//        //    //    if (VBFSUSYUtilities::getLeadingGoodLepton().p4.Pt() < 12.)
//        //    //    {
//        //    //      fillVBFCutflow(6);
//        //    //      fillVBFHistograms("MET200300LeadLepPtCut");
//        //    //      if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId ==-11)
//        //    //      {
//        //    //        fillVBFHistograms("MET200300ElPlusCut");
//        //    //      }
//        //    //      if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId == 11)
//        //    //      {
//        //    //        fillVBFHistograms("MET200300ElMinusCut");
//        //    //      }
//        //    //      if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId ==-13)
//        //    //      {
//        //    //        fillVBFHistograms("MET200300MuPlusCut");
//        //    //      }
//        //    //      if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId == 13)
//        //    //      {
//        //    //        fillVBFHistograms("MET200300MuMinusCut");
//        //    //      }
//        //    //    }
//        //    //  }
//        //    //}
//
//        //    //// 300 - inf MET bin
//        //    //if (VBFSUSYUtilities::getMETp4().Pt() > 300.)
//        //    //{
//        //    //  fillVBFCutflow(8);
//        //    //  fillVBFHistograms("MET300infCut");
//        //    //  if (VBFSUSYUtilities::getMTleadLep() < 50.)
//        //    //  {
//        //    //    fillVBFCutflow(6);
//        //    //    fillVBFHistograms("MET300infMTCut");
//        //    //    if (VBFSUSYUtilities::getLeadingGoodLepton().p4.Pt() < 15.)
//        //    //    {
//        //    //      fillVBFCutflow(6);
//        //    //      fillVBFHistograms("MET300infLeadLepPtCut");
//        //    //      if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId ==-11 && nbtag < 1)
//        //    //      {
//        //    //        fillVBFHistograms("MET300infElPlusCut");
//        //    //      }
//        //    //      if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId == 11 && nbtag < 1)
//        //    //      {
//        //    //        fillVBFHistograms("MET300infElMinusCut");
//        //    //      }
//        //    //      if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId ==-13 && nbtag < 2)
//        //    //      {
//        //    //        fillVBFHistograms("MET300infMuPlusCut");
//        //    //      }
//        //    //      if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId == 13 && nbtag < 2)
//        //    //      {
//        //    //        fillVBFHistograms("MET300infMuMinusCut");
//        //    //      }
//        //    //    }
//        //    //  }
//        //    //}
//        //  }
//
//      //// 2 soft lepton case
//      //if (VBFSUSYUtilities::getNSelectedSoftGoodLeptons() == 2)
//      //{
//      //  fillVBFCutflow(9);
//      //  fillVBFHistograms("TwoLepCut");
//      //  if (VBFSUSYUtilities::getNBTaggedJetsWithCSVCut(0.46) == 0)
//      //  {
//      //    fillVBFCutflow(10);
//      //    fillVBFHistograms("TwoLepBVetoCut");
//      //    if (VBFSUSYUtilities::getVBFDEtajj() > 3.8)
//      //    {
//      //      fillVBFCutflow(10);
//      //      fillVBFHistograms("TwoLepDEtajjCut");
//      //      // 100 - 200 MET bin
//      //      if (VBFSUSYUtilities::getMETp4().Pt() > 100. && VBFSUSYUtilities::getMETp4().Pt() <= 200.)
//      //      {
//      //        fillVBFCutflow(5);
//      //        fillVBFHistograms("TwoLepMET100200Cut");
//      //        //	            if (VBFSUSYUtilities::getLeadingGoodLepton().p4.Pt() < 10.)
//      //        //	            {
//      //        //	              fillVBFCutflow(6);
//      //        //	              fillVBFHistograms("MET100200LeadLepPtCut");
//      //        //	            }
//      //      }
//
//      //      // 200 - 300 MET bin
//      //      if (VBFSUSYUtilities::getMETp4().Pt() > 200.)
//      //      {
//      //        fillVBFCutflow(7);
//      //        fillVBFHistograms("TwoLepMET200infCut");
//      //        //	            if (VBFSUSYUtilities::getMTleadLep() < 50.)
//      //        //	            {
//      //        //	              fillVBFCutflow(6);
//      //        //	              fillVBFHistograms("MET200300MTCut");
//      //        //	            }
//      //      }
//
//      //    }
//      //  }
//      //}
//
//      //if (VBFSUSYUtilities::getNBTaggedJetsWithCSVCut(0.46) == 0)
//      //{
//      //  fillVBFCutflow(2);
//      //  fillVBFHistograms("NBJetCut");
//      //  if (VBFSUSYUtilities::getNSelectedSoftGoodLeptons() >= 1)
//      //  {
//      //    fillVBFCutflow(3);
//      //    fillVBFHistograms("NSoftLepCut");
//      //    if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pdgId == 13)
//      //    {
//      //      fillVBFCutflow(4);
//      //      fillVBFHistograms("MuonCut");
//      //      if (VBFSUSYUtilities::getLeadingGoodLepton().lep_pt < 20.)
//      //      {
//      //        fillVBFCutflow(5);
//      //        fillVBFHistograms("LeadPtCut");
//      //        if (VBFSUSYUtilities::getMETp4().Pt() > 200.)
//      //        {
//      //          fillVBFCutflow(6);
//      //          fillVBFHistograms("METCut");
//      //          if (VBFSUSYUtilities::getVBFDEtajj() > 3.8)
//      //          {
//      //            fillVBFCutflow(7);
//      //            fillVBFHistograms("DEtajjCut");
//      //            if (VBFSUSYUtilities::getSubleadingVBFJet().p4.Pt() > 50.)
//      //            {
//      //              fillVBFCutflow(8);
//      //              fillVBFHistograms("SubleadJetPtCut");
//      //              if (VBFSUSYUtilities::getMTleadLep() < 50.)
//      //              {
//      //                fillVBFCutflow(9);
//      //                fillVBFHistograms("MTCut");
//      //                if (VBFSUSYUtilities::getVBFMjj() > 1400.)
//      //                {
//      //                  fillVBFCutflow(10);
//      //                  fillVBFHistograms("MjjCut");
//      //                }
//      //              }
//      //            }
//      //          }
//      //        }
//      //        else
//      //        {
//      //          fillVBFCutflow(11);
//      //          fillVBFHistograms("LowMETCut");
//      //          if (VBFSUSYUtilities::getVBFDEtajj() > 3.8)
//      //          {
//      //            fillVBFCutflow(12);
//      //            fillVBFHistograms("DEtajjCut");
//      //          //  if (VBFSUSYUtilities::getSubleadingVBFJet().p4.Pt() > 50.)
//      //          //  {
//      //          //    fillVBFCutflow(13);
//      //          //    fillVBFHistograms("SubleadJetPtCut");
//      //          //    if (VBFSUSYUtilities::getMTleadLep() < 50.)
//      //          //    {
//      //          //      fillVBFCutflow(14);
//      //          //      fillVBFHistograms("MTCut");
//      //          //      if (VBFSUSYUtilities::getVBFMjj() > 1400.)
//      //          //      {
//      //          //        fillVBFCutflow(15);
//      //          //        fillVBFHistograms("MjjCut");
//      //          //      }
//      //          //    }
//      //          //  }
//      //          }
//      //        }
//      //      }
//      //    }
//      //  }
//      //}
