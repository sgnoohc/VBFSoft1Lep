// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

#include "MT2TreeLooper.h"

//===============================================================================================
// Main Loop
//
int MT2TreeLooper(TChain* chain, TString output_name, int nevents)
{

  // histograms
  PlotUtil::Hist1D_DB h_1d;

  // Fun start
  PrintUtilities::start();

  // Set configurations for event looping
  LoopUtilities::resetLoopCondition(chain, nevents);

  // Parse output name to obtain mass values of interest

  // Loop over file:ttree -> and loop over events in ttree
  while (LoopUtilities::nextFileAndLoadTTreeWithName("mt2")) // two parantheses to suppress warning
  {

    // Load the Class
    MT2Tree mt2tree(LoopUtilities::getCurrentTTree());

    // Loop over the TTree
    while (LoopUtilities::nextEvent())
    {

      // If required events are processed break the loop
      if (LoopUtilities::isAllEventsProcessed())
        break;

      // Load MT2Trees
      mt2tree.LoadTree(LoopUtilities::getCurrentTTreeEventIndex());
      mt2tree.GetEntry(LoopUtilities::getCurrentTTreeEventIndex());

      // Event variables
      float evt_scale1fb;
      evt_scale1fb = mt2tree.evt_scale1fb / LoopUtilities::getFractionOfBookedNEvents();

      // Parse the ewkino mass
      if (output_name.Contains("sig"))
        VBFSUSYUtilities::parseEwkinoMasses(mt2tree.ngenStat23,
                                            mt2tree.genStat23_pdgId,
                                            mt2tree.genStat23_status,
                                            mt2tree.genStat23_mass);

      // histogram names
      TString cutflow_name = "cutflow";
      if (output_name.Contains("sig"))
        cutflow_name = VBFSUSYUtilities::getNameWithMassSuffix(cutflow_name);

      PlotUtil::plot1D(cutflow_name.Data(), 0, evt_scale1fb, h_1d, cutflow_name.Data(), 50, 0, 50);

      // Select leptons
      VBFSUSYUtilities::Leptons mt2leptons = getLeptonsFromMT2Tree(mt2tree);
      VBFSUSYUtilities::selectGoodLeptons(mt2leptons);

      PlotUtil::plot1D(cutflow_name.Data(), 0, evt_scale1fb, h_1d, cutflow_name.Data(), 50, 0, 50);
    }

  }

  // Save plots
  PlotUtil::savePlots(h_1d, output_name+".root");

  // Fun exit
  PrintUtilities::exit();

  return 0;

}

VBFSUSYUtilities::Leptons getLeptonsFromMT2Tree(MT2Tree& mt2tree)
{
  VBFSUSYUtilities::Leptons leptons;
  for (int ilep = 0; ilep < mt2tree.nlep; ++ilep)
  {
    VBFSUSYUtilities::Lepton lepton;
    lepton.lep_pt           = mt2tree.lep_pt[ilep];
    lepton.lep_eta          = mt2tree.lep_eta[ilep];
    lepton.lep_phi          = mt2tree.lep_phi[ilep];
    lepton.lep_mass         = mt2tree.lep_mass[ilep];
    lepton.lep_charge       = mt2tree.lep_charge[ilep];
    lepton.lep_pdgId        = mt2tree.lep_pdgId[ilep];
    lepton.lep_dxy          = mt2tree.lep_dxy[ilep];
    lepton.lep_dz           = mt2tree.lep_dz[ilep];
    lepton.lep_tightId      = mt2tree.lep_tightId[ilep];
    lepton.lep_heepId       = mt2tree.lep_heepId[ilep];
    lepton.lep_relIso03     = mt2tree.lep_relIso03[ilep];
    lepton.lep_relIso04     = mt2tree.lep_relIso04[ilep];
    lepton.lep_miniRelIso   = mt2tree.lep_miniRelIso[ilep];
    lepton.lep_relIsoAn04   = mt2tree.lep_relIsoAn04[ilep];
    lepton.lep_mcMatchId    = mt2tree.lep_mcMatchId[ilep];
    lepton.lep_lostHits     = mt2tree.lep_lostHits[ilep];
    lepton.lep_convVeto     = mt2tree.lep_convVeto[ilep];
    lepton.lep_tightCharge  = mt2tree.lep_tightCharge[ilep];
    lepton.lep_mva          = mt2tree.lep_mva[ilep];
    lepton.lep_ptRatio      = mt2tree.lep_ptRatio[ilep];
    lepton.lep_ptRel        = mt2tree.lep_ptRel[ilep];
    lepton.lep_tightIdNoIso = mt2tree.lep_tightIdNoIso[ilep];
    lepton.lep_sip3d        = mt2tree.lep_sip3d[ilep];
    leptons.push_back(lepton);
  }
  return leptons;
}

VBFSUSYUtilities::Jets getJetsFromMT2Tree(MT2Tree& mt2tree)
{
  VBFSUSYUtilities::Jets jets;
  for (int ijet = 0; ijet < mt2tree.njet; ++ijet)
  {
    VBFSUSYUtilities::Jet jet;
    jet.jet_pt            = mt2tree.jet_pt[ijet];
    jet.jet_eta           = mt2tree.jet_eta[ijet];
    jet.jet_phi           = mt2tree.jet_phi[ijet];
    jet.jet_mass          = mt2tree.jet_mass[ijet];
    jet.jet_btagCSV       = mt2tree.jet_btagCSV[ijet];
    jet.jet_rawPt         = mt2tree.jet_rawPt[ijet];
    jet.jet_mcPt          = mt2tree.jet_mcPt[ijet];
    jet.jet_mcFlavour     = mt2tree.jet_mcFlavour[ijet];
    jet.jet_hadronFlavour = mt2tree.jet_hadronFlavour[ijet];
    jet.jet_qgl           = mt2tree.jet_qgl[ijet];
    jet.jet_area          = mt2tree.jet_area[ijet];
    jet.jet_id            = mt2tree.jet_id[ijet];
    jet.jet_puId          = mt2tree.jet_puId[ijet];
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

