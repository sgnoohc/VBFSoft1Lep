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

  // Loop over file:ttree -> and loop over events in ttree
  while (LoopUtilities::nextFileAndLoadTTreeWithName("mt2")) // two parantheses to suppress warning
  {

    // Load the Class
    MT2Tree mt2tree(LoopUtilities::getCurrentTTree());

    // Loop over the TTree
    while (LoopUtilities::nextEvent())
    {
      if (LoopUtilities::isAllEventsProcessed())
        break;

      // Load MT2Trees
      mt2tree.LoadTree(LoopUtilities::getCurrentTTreeEventIndex());
      mt2tree.GetEntry(LoopUtilities::getCurrentTTreeEventIndex());

      // Event variables
      float evt_scale1fb;
      evt_scale1fb = mt2tree.evt_scale1fb / LoopUtilities::getFractionOfBookedNEvents();

      // Multiplicity variables
      int nlep;
      nlep = mt2tree.nlep;

      int nsoftlep = 0;
      int nhardlep = 0;

      for (int ilep = 0; ilep < 4; ++ilep)
      {
        if (nlep > ilep)
        {
          if (mt2tree.lep_pt[ilep] < 30.)
            nsoftlep++;
          if (mt2tree.lep_pt[ilep] >= 30.)
            nhardlep++;
        }
      }

      if (nhardlep == 0 && nsoftlep == 1) PlotUtil::plot1D("cutflow",  0, evt_scale1fb, h_1d, "cutflow", 20, 0, 20);
      if (nhardlep == 0 && nsoftlep == 2) PlotUtil::plot1D("cutflow", 10, evt_scale1fb, h_1d, "cutflow", 20, 0, 20);

      // MET preselection
      if (mt2tree.met_pt < 200.)
        continue;

      if (nhardlep == 0 && nsoftlep == 1) PlotUtil::plot1D("cutflow",  1, evt_scale1fb, h_1d, "cutflow", 20, 0, 20);
      if (nhardlep == 0 && nsoftlep == 2) PlotUtil::plot1D("cutflow", 11, evt_scale1fb, h_1d, "cutflow", 20, 0, 20);

      // VBF
      if (nhardlep == 0 && nsoftlep == 1)
      {

        if (mt2tree.njet >= 2)
        {

          PlotUtil::plot1D("cutflow",  2, evt_scale1fb, h_1d, "cutflow", 20, 0, 20);
          TLorentzVector jet_tlv0;
          TLorentzVector jet_tlv1;
          jet_tlv0.SetPtEtaPhiM(mt2tree.jet_pt[0], mt2tree.jet_eta[0], mt2tree.jet_phi[0], mt2tree.jet_mass[0]);
          jet_tlv1.SetPtEtaPhiM(mt2tree.jet_pt[1], mt2tree.jet_eta[1], mt2tree.jet_phi[1], mt2tree.jet_mass[1]);
          TLorentzVector dijet;
          dijet = jet_tlv0 + jet_tlv1;
          // CJV
          bool is_cen_jet_exist = 0;
          for (int ijet = 2; ijet < 10; ++ijet)
          {
            if (mt2tree.njet > ijet)
            {
              if ( ((mt2tree.jet_eta[0]-mt2tree.jet_eta[ijet])*(mt2tree.jet_eta[1]-mt2tree.jet_eta[ijet])) < 0)
              {
                is_cen_jet_exist = 1;
              }
            }
          }
          if (fabs(mt2tree.jet_eta[0] - mt2tree.jet_eta[1]) > 3.5)
          {
            PlotUtil::plot1D("cutflow",  3, evt_scale1fb, h_1d, "cutflow", 20, 0, 20);
            if (dijet.M() > 700.)
            {
              PlotUtil::plot1D("cutflow",  4, evt_scale1fb, h_1d, "cutflow", 20, 0, 20);
              if (!is_cen_jet_exist)
              {
                PlotUtil::plot1D("cutflow",  5, evt_scale1fb, h_1d, "cutflow", 20, 0, 20);
              }
            }
          }

        }

      }

      // Low Mll peak
      if (nhardlep == 0 && nsoftlep == 2)
      {

        TLorentzVector lep_tlv0;
        TLorentzVector lep_tlv1;
        std::vector<int> soft_lep_index;
        for (int ilep = 0; ilep < 4; ++ilep)
        {
          if (nlep > ilep)
            if (mt2tree.lep_pt[ilep] < 30.)
              soft_lep_index.push_back(ilep);
        }
        lep_tlv0.SetPtEtaPhiM(mt2tree.lep_pt[soft_lep_index[0]], mt2tree.lep_eta[soft_lep_index[0]], mt2tree.lep_phi[soft_lep_index[0]], mt2tree.lep_mass[soft_lep_index[0]]);
        lep_tlv1.SetPtEtaPhiM(mt2tree.lep_pt[soft_lep_index[1]], mt2tree.lep_eta[soft_lep_index[1]], mt2tree.lep_phi[soft_lep_index[1]], mt2tree.lep_mass[soft_lep_index[1]]);
        TLorentzVector dilep;
        dilep = lep_tlv0 + lep_tlv1;
        if (dilep.M() < 30.)
        {
          PlotUtil::plot1D("cutflow", 12, evt_scale1fb, h_1d, "cutflow", 20, 0, 20);
          if (mt2tree.met_pt/mt2tree.ht > 0.6 && mt2tree.met_pt/mt2tree.ht < 1.4)
          {
            PlotUtil::plot1D("cutflow", 13, evt_scale1fb, h_1d, "cutflow", 20, 0, 20);
            if (mt2tree.ht > 100.)
            {
              PlotUtil::plot1D("cutflow", 14, evt_scale1fb, h_1d, "cutflow", 20, 0, 20);
            }
          }
        }

      }

    }

  }

  // Save plots
  PlotUtil::savePlots(h_1d, output_name+".root");

  // Fun exit
  PrintUtilities::exit();

  return 0;

}


//eof
