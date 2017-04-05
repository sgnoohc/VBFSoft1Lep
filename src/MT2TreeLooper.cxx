// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

#include "MT2TreeLooper.h"

// Variables
namespace Vbf {
  bool is_signal;
  TString output_name;
  PlotUtil::Hist1D_DB h_1d;
  MT2Tree mt2tree;
  VBFSUSYUtilities::Leptons mt2leptons;
  VBFSUSYUtilities::Jets mt2jets;
}

//##################################################################################################
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
void loop()
{
  //=================================================================
  // LOOP
  //=================================================================
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



//##################################################################################################
void processMT2TreeEvent()
{
  // Event variables
  float evt_scale1fb;
  evt_scale1fb = Vbf::mt2tree.evt_scale1fb / LoopUtilities::getFractionOfBookedNEvents();

  // Parse the ewkino mass
  if (Vbf::is_signal)
    VBFSUSYUtilities::parseEwkinoMasses(Vbf::mt2tree.ngenStat23,
                                        Vbf::mt2tree.genStat23_pdgId,
                                        Vbf::mt2tree.genStat23_status,
                                        Vbf::mt2tree.genStat23_mass);

  // histogram names
  TString cutflow_name = "cutflow";
  if (Vbf::is_signal)
    cutflow_name = VBFSUSYUtilities::getNameWithMassSuffix(cutflow_name);

  // select objects
  selectObjects();

  PlotUtil::plot1D(cutflow_name.Data(), 0, evt_scale1fb, Vbf::h_1d, cutflow_name.Data(), 50, 0, 50);
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
  Vbf::mt2leptons = getLeptonsFromMT2Tree();
  VBFSUSYUtilities::selectGoodLeptons(Vbf::mt2leptons);

}

//##################################################################################################
void selectJets()
{
  // Select jets
  Vbf::mt2jets = getJetsFromMT2Tree();
  VBFSUSYUtilities::selectGoodJets(Vbf::mt2jets);
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
    jets.push_back(jet);
  }
  return jets;
}

//eof

      //// Multiplicity variables
      //int nlep;
      //nlep = mt2tree.nlep;

      //int nsoftlep = 0;
      //int nhardlep = 0;

      //for (int ilep = 0; ilep < 4; ++ilep)
      //{
      //  if (nlep > ilep)
      //  {
      //    if (mt2tree.lep_pt[ilep] < 30.)
      //      nsoftlep++;
      //    if (mt2tree.lep_pt[ilep] >= 30.)
      //      nhardlep++;
      //  }
      //}

      //// histogram names
      //TString cutflow_name = "cutflow";
      //if (output_name.Contains("sig"))
      //  cutflow_name += TString::Format("_%.1f_%.1f_%.1f", mC1_event, mN2_event, mN1_event);

      //TString lep_pt0_name = "lep_pt0";
      //if (output_name.Contains("sig"))
      //  lep_pt0_name += TString::Format("_%.1f_%.1f_%.1f", mC1_event, mN2_event, mN1_event);

      //if (nhardlep == 0 && nsoftlep == 1) PlotUtil::plot1D(lep_pt0_name.Data(), mt2tree.lep_pt[0], evt_scale1fb, h_1d, lep_pt0_name.Data(), 50, 0, 50);
      //if (nhardlep == 0 && nsoftlep == 2) PlotUtil::plot1D(lep_pt0_name.Data(), mt2tree.lep_pt[0], evt_scale1fb, h_1d, lep_pt0_name.Data(), 50, 0, 50);

      //if (nhardlep == 0 && nsoftlep == 1) PlotUtil::plot1D(cutflow_name.Data(),  0, evt_scale1fb, h_1d, cutflow_name.Data(), 20, 0, 20);
      //if (nhardlep == 0 && nsoftlep == 2) PlotUtil::plot1D(cutflow_name.Data(), 10, evt_scale1fb, h_1d, cutflow_name.Data(), 20, 0, 20);

      //// MET preselection
      //if (mt2tree.met_pt < 200.)
      //  continue;

      //if (nhardlep == 0 && nsoftlep == 1) PlotUtil::plot1D(cutflow_name.Data(),  1, evt_scale1fb, h_1d, cutflow_name.Data(), 20, 0, 20);
      //if (nhardlep == 0 && nsoftlep == 2) PlotUtil::plot1D(cutflow_name.Data(), 11, evt_scale1fb, h_1d, cutflow_name.Data(), 20, 0, 20);

      //// VBF
      //if (nhardlep == 0 && nsoftlep == 1)
      //{

      //  if (mt2tree.njet >= 2)
      //  {

      //    PlotUtil::plot1D(cutflow_name.Data(),  2, evt_scale1fb, h_1d, cutflow_name.Data(), 20, 0, 20);
      //    TLorentzVector jet_tlv0;
      //    TLorentzVector jet_tlv1;
      //    jet_tlv0.SetPtEtaPhiM(mt2tree.jet_pt[0], mt2tree.jet_eta[0], mt2tree.jet_phi[0], mt2tree.jet_mass[0]);
      //    jet_tlv1.SetPtEtaPhiM(mt2tree.jet_pt[1], mt2tree.jet_eta[1], mt2tree.jet_phi[1], mt2tree.jet_mass[1]);
      //    TLorentzVector dijet;
      //    dijet = jet_tlv0 + jet_tlv1;
      //    // CJV
      //    bool is_cen_jet_exist = 0;
      //    for (int ijet = 2; ijet < 10; ++ijet)
      //    {
      //      if (mt2tree.njet > ijet)
      //      {
      //        if ( ((mt2tree.jet_eta[0]-mt2tree.jet_eta[ijet])*(mt2tree.jet_eta[1]-mt2tree.jet_eta[ijet])) < 0)
      //        {
      //          is_cen_jet_exist = 1;
      //        }
      //      }
      //    }
      //    if (fabs(mt2tree.jet_eta[0] - mt2tree.jet_eta[1]) > 3.5)
      //    {
      //      PlotUtil::plot1D(cutflow_name.Data(),  3, evt_scale1fb, h_1d, cutflow_name.Data(), 20, 0, 20);
      //      if (dijet.M() > 700.)
      //      {
      //        PlotUtil::plot1D(cutflow_name.Data(),  4, evt_scale1fb, h_1d, cutflow_name.Data(), 20, 0, 20);
      //        if (!is_cen_jet_exist)
      //        {
      //          PlotUtil::plot1D(cutflow_name.Data(),  5, evt_scale1fb, h_1d, cutflow_name.Data(), 20, 0, 20);
      //        }
      //      }
      //    }

      //  }

      //}

      //// Low Mll peak
      //if (nhardlep == 0 && nsoftlep == 2)
      //{

      //  TLorentzVector lep_tlv0;
      //  TLorentzVector lep_tlv1;
      //  std::vector<int> soft_lep_index;
      //  for (int ilep = 0; ilep < 4; ++ilep)
      //  {
      //    if (nlep > ilep)
      //      if (mt2tree.lep_pt[ilep] < 30.)
      //        soft_lep_index.push_back(ilep);
      //  }
      //  lep_tlv0.SetPtEtaPhiM(mt2tree.lep_pt[soft_lep_index[0]], mt2tree.lep_eta[soft_lep_index[0]], mt2tree.lep_phi[soft_lep_index[0]], mt2tree.lep_mass[soft_lep_index[0]]);
      //  lep_tlv1.SetPtEtaPhiM(mt2tree.lep_pt[soft_lep_index[1]], mt2tree.lep_eta[soft_lep_index[1]], mt2tree.lep_phi[soft_lep_index[1]], mt2tree.lep_mass[soft_lep_index[1]]);
      //  TLorentzVector dilep;
      //  dilep = lep_tlv0 + lep_tlv1;
      //  if (dilep.M() < 30.)
      //  {
      //    PlotUtil::plot1D(cutflow_name.Data(), 12, evt_scale1fb, h_1d, cutflow_name.Data(), 20, 0, 20);
      //    if (mt2tree.met_pt/mt2tree.ht > 0.6 && mt2tree.met_pt/mt2tree.ht < 1.4)
      //    {
      //      PlotUtil::plot1D(cutflow_name.Data(), 13, evt_scale1fb, h_1d, cutflow_name.Data(), 20, 0, 20);
      //      if (mt2tree.ht > 100.)
      //      {
      //        PlotUtil::plot1D(cutflow_name.Data(), 14, evt_scale1fb, h_1d, cutflow_name.Data(), 20, 0, 20);
      //      }
      //    }
      //  }

      //}

