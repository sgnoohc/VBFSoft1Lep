// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

#include "MT2TreeLooper.h"

//===============================================================================================
// Main Loop
//
int MT2TREELOOPER(TChain* chain, bool isSignal, TString output_name, int nevents)
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
    MT2TREECLASS MT2TREE(LoopUtilities::getCurrentTTree());

    // Loop over the TTree
    while (LoopUtilities::nextEvent())
    {
      if (LoopUtilities::isAllEventsProcessed())
        break;

      // Load MT2Trees
      MT2TREE.LoadTree(LoopUtilities::getCurrentTTreeEventIndex());
      MT2TREE.GetEntry(LoopUtilities::getCurrentTTreeEventIndex());

      // Event variables
      float evt_scale1fb;
      evt_scale1fb = MT2TREE.evt_scale1fb;

      // Multiplicity variables
      int nlep;
      nlep = MT2TREE.nlep;

      int nsoftlep = 0;

      // Plotting integrated lepPt
      for (int ilep = 0; ilep < 4; ++ilep)
      {
        if (nlep > ilep)
          if (MT2TREE.lep_pt[ilep] < 20.)
            nsoftlep++;
      }

      // Cutflow
      if (true)     PlotUtil::plot1D("cutflow", 0, evt_scale1fb, h_1d, "cutflow", 20, 0, 20);

      // Plots
      PlotUtil::plot1D("nlep"    , nlep    , evt_scale1fb, h_1d, "nlep"    , 4, 0, 4);
      PlotUtil::plot1D("nsoftlep", nsoftlep, evt_scale1fb, h_1d, "nsoftlep", 4, 0, 4);
    }

  }

  // Save plots
  PlotUtil::savePlots(h_1d, output_name+".root");

  // Fun exit
  PrintUtilities::exit();

  return 0;

}


//eof

      //// Event variables
      //float evt_scale1fb;
      //evt_scale1fb = MT2TREE.evt_scale1fb;

      //// Multiplicity variables
      //int nlep;
      //int njet;
      //nlep = MT2TREE.nlep;
      //njet = MT2TREE.njet;

      //// Lepton pt
      //float lep_pt0;
      //float lep_pt1;
      //float lep_pt2;
      //float lep_pt3;
      //lep_pt0 = MT2TREE.lep_pt[0];
      //lep_pt1 = MT2TREE.lep_pt[1];
      //lep_pt2 = MT2TREE.lep_pt[2];
      //lep_pt3 = MT2TREE.lep_pt[3];

      //// Jet pt
      //float jet_pt0;
      //float jet_pt1;
      //float jet_eta0;
      //float jet_eta1;
      //float jet_phi0;
      //float jet_phi1;
      //float jet_mass0;
      //float jet_mass1;
      //jet_pt0 = MT2TREE.jet_pt[0];
      //jet_pt1 = MT2TREE.jet_pt[1];
      //jet_eta0 = MT2TREE.jet_eta[0];
      //jet_eta1 = MT2TREE.jet_eta[1];
      //jet_phi0 = MT2TREE.jet_phi[0];
      //jet_phi1 = MT2TREE.jet_phi[1];
      //jet_mass0 = MT2TREE.jet_mass[0];
      //jet_mass1 = MT2TREE.jet_mass[1];

      //// Leading jet in one hemi-sphere
      //float jet_ptN;
      //float jet_etaN;
      //float jet_phiN;
      //float jet_massN;
      //jet_ptN = 0;
      //int jet_indexN;
      //jet_indexN = -1;
      //for (int ijet = 0; ijet < njet; ++ijet)
      //{
      //  if (MT2TREE.jet_eta[ijet] > 0)
      //    continue;
      //  if (MT2TREE.jet_pt[ijet] > jet_ptN)
      //  {
      //    jet_ptN   = MT2TREE.jet_pt  [ijet];
      //    jet_etaN  = MT2TREE.jet_eta [ijet];
      //    jet_phiN  = MT2TREE.jet_phi [ijet];
      //    jet_massN = MT2TREE.jet_mass[ijet];
      //    jet_indexN = ijet;
      //  }
      //}

      //// Leading jet in another hemi-sphere
      //float jet_ptP;
      //float jet_etaP;
      //float jet_phiP;
      //float jet_massP;
      //jet_ptP = 0;
      //int jet_indexP;
      //jet_indexP = -1;
      //for (int ijet = 0; ijet < njet; ++ijet)
      //{
      //  if (MT2TREE.jet_eta[ijet] < 0)
      //    continue;
      //  if (MT2TREE.jet_pt[ijet] > jet_ptP)
      //  {
      //    jet_ptP   = MT2TREE.jet_pt  [ijet];
      //    jet_etaP  = MT2TREE.jet_eta [ijet];
      //    jet_phiP  = MT2TREE.jet_phi [ijet];
      //    jet_massP = MT2TREE.jet_mass[ijet];
      //    jet_indexP = ijet;
      //  }
      //}

      //// Jet p4
      //TLorentzVector jet_tlv0;
      //TLorentzVector jet_tlv1;
      //jet_tlv0.SetPtEtaPhiM(jet_pt0, jet_eta0, jet_phi0, jet_mass0);
      //jet_tlv1.SetPtEtaPhiM(jet_pt1, jet_eta1, jet_phi1, jet_mass1);

      //// Forward Backward Jet p4
      //TLorentzVector jet_tlvN;
      //TLorentzVector jet_tlvP;
      //jet_tlvN.SetPtEtaPhiM(jet_ptN, jet_etaN, jet_phiN, jet_massN);
      //jet_tlvP.SetPtEtaPhiM(jet_ptP, jet_etaP, jet_phiP, jet_massP);

      //// Dijet variables
      //float mjj;
      //float detajj;
      //float mjj_tag;
      //float detajj_tag;
      //mjj = (jet_tlv0 + jet_tlv1).M();
      //detajj = fabs(jet_eta0 - jet_eta1);
      //mjj_tag = (jet_tlvN + jet_tlvP).M();
      //detajj_tag = fabs(jet_etaN - jet_etaP);

      //// Cutflow
      //if (true)                     PlotUtil::plot1D("cutflow", 0, evt_scale1fb, h_1d, "cutflow", 20, 0, 20);
      //if (nlep > 0)                 PlotUtil::plot1D("cutflow", 1, evt_scale1fb, h_1d, "cutflow", 20, 0, 20);
      //if (nlep > 1)                 PlotUtil::plot1D("cutflow", 2, evt_scale1fb, h_1d, "cutflow", 20, 0, 20);
      //if (njet > 1)                 PlotUtil::plot1D("cutflow", 3, evt_scale1fb, h_1d, "cutflow", 20, 0, 20);
      //if (njet > 1)                 PlotUtil::plot1D("cutflow", 4, evt_scale1fb, h_1d, "cutflow", 20, 0, 20);
      //if (njet > 1 && detajj > 3.5) PlotUtil::plot1D("cutflow", 5, evt_scale1fb, h_1d, "cutflow", 20, 0, 20);

      //// Plots
      //PlotUtil::plot1D("nlep", nlep, evt_scale1fb, h_1d, "nlep", 4, 0, 4);
      //PlotUtil::plot1D("njet", njet, evt_scale1fb, h_1d, "njet", 10, 0, 10);
      //if (nlep > 0) PlotUtil::plot1D("lep_pt0", lep_pt0, evt_scale1fb, h_1d, "lep_pt0", 100, 0, 100);
      //if (nlep > 1) PlotUtil::plot1D("lep_pt1", lep_pt1, evt_scale1fb, h_1d, "lep_pt1", 100, 0, 100);
      //if (nlep > 2) PlotUtil::plot1D("lep_pt2", lep_pt2, evt_scale1fb, h_1d, "lep_pt2", 100, 0, 100);
      //if (nlep > 3) PlotUtil::plot1D("lep_pt3", lep_pt3, evt_scale1fb, h_1d, "lep_pt3", 100, 0, 100);

      //if (njet > 0) PlotUtil::plot1D("jet_pt0", jet_pt0, evt_scale1fb, h_1d, "jet_pt0", 100, 0, 100);
      //if (njet > 1) PlotUtil::plot1D("jet_pt1", jet_pt1, evt_scale1fb, h_1d, "jet_pt1", 100, 0, 100);

      //if (njet > 0) PlotUtil::plot1D("jet_E0", jet_tlv0.E(), evt_scale1fb, h_1d, "jet_E0", 50, 0, 500);
      //if (njet > 1) PlotUtil::plot1D("jet_E1", jet_tlv1.E(), evt_scale1fb, h_1d, "jet_E1", 50, 0, 500);
      //if (njet > 0) PlotUtil::plot1D("jet_eta0", jet_eta0, evt_scale1fb, h_1d, "jet_eta0", 50, -5, 5);
      //if (njet > 1) PlotUtil::plot1D("jet_eta1", jet_eta1, evt_scale1fb, h_1d, "jet_eta1", 50, -5, 5);

      //if (njet > 1)
      //{
      //  //if (MT2TREE.jet_pt[1] > 50.)
      //  {
      //    PlotUtil::plot1D("mjj", mjj, evt_scale1fb, h_1d, "mjj", 1000, 0, 1000);
      //    PlotUtil::plot1D("detajj", detajj, evt_scale1fb, h_1d, "detajj", 45, 0, 9);
      //  }
      //}

      //if (jet_indexP >= 0 && jet_indexN >= 0)
      //{
      //  //if (jet_ptP > 50. && jet_ptN > 50.)
      //  {
      //    // Plotting jet auxillary variables for the tagged jet
      //    if (njet > 1)
      //    {
      //      if (njet > 1) PlotUtil::plot1D("mjj_tag", mjj_tag, evt_scale1fb, h_1d, "mjj_tag", 1000, 0, 1000);
      //      if (njet > 1) PlotUtil::plot1D("detajj_tag", detajj_tag, evt_scale1fb, h_1d, "detajj_tag", 45, 0, 9);
      //      int ijet;
      //      ijet = jet_indexN;
      //      PlotUtil::plot1D("jet_btagCSVN"       , MT2TREE.jet_btagCSV       [ijet] , evt_scale1fb , h_1d , "jet_btagCSVN"       , 100 , 0 , 2   );
      //      PlotUtil::plot1D("jet_rawPtN"         , MT2TREE.jet_rawPt         [ijet] , evt_scale1fb , h_1d , "jet_rawPtN"         , 100 , 0 , 100 );
      //      PlotUtil::plot1D("jet_mcPtN"          , MT2TREE.jet_mcPt          [ijet] , evt_scale1fb , h_1d , "jet_mcPtN"          , 100 , 0 , 100 );
      //      PlotUtil::plot1D("jet_mcFlavourN"     , MT2TREE.jet_mcFlavour     [ijet] , evt_scale1fb , h_1d , "jet_mcFlavourN"     , 30  , 0 , 30  );
      //      PlotUtil::plot1D("jet_hadronFlavourN" , MT2TREE.jet_hadronFlavour [ijet] , evt_scale1fb , h_1d , "jet_hadronFlavourN" , 10  , 0 , 10  );
      //      PlotUtil::plot1D("jet_qglN"           , MT2TREE.jet_qgl           [ijet] , evt_scale1fb , h_1d , "jet_qglN"           , 100 , 0 , 100 );
      //      PlotUtil::plot1D("jet_areaN"          , MT2TREE.jet_area          [ijet] , evt_scale1fb , h_1d , "jet_areaN"          , 100 , 0 , 100 );
      //      PlotUtil::plot1D("jet_idN"            , MT2TREE.jet_id            [ijet] , evt_scale1fb , h_1d , "jet_idN"            , 100 , 0 , 100 );
      //      PlotUtil::plot1D("jet_puIdN"          , MT2TREE.jet_puId          [ijet] , evt_scale1fb , h_1d , "jet_puIdN"          , 5   , 0 , 5   );
      //      ijet = jet_indexP;
      //      PlotUtil::plot1D("jet_btagCSVP"       , MT2TREE.jet_btagCSV       [ijet] , evt_scale1fb , h_1d , "jet_btagCSVP"       , 100 , 0 , 2   );
      //      PlotUtil::plot1D("jet_rawPtP"         , MT2TREE.jet_rawPt         [ijet] , evt_scale1fb , h_1d , "jet_rawPtP"         , 100 , 0 , 100 );
      //      PlotUtil::plot1D("jet_mcPtP"          , MT2TREE.jet_mcPt          [ijet] , evt_scale1fb , h_1d , "jet_mcPtP"          , 100 , 0 , 100 );
      //      PlotUtil::plot1D("jet_mcFlavourP"     , MT2TREE.jet_mcFlavour     [ijet] , evt_scale1fb , h_1d , "jet_mcFlavourP"     , 30  , 0 , 30  );
      //      PlotUtil::plot1D("jet_hadronFlavourP" , MT2TREE.jet_hadronFlavour [ijet] , evt_scale1fb , h_1d , "jet_hadronFlavourP" , 10  , 0 , 10  );
      //      PlotUtil::plot1D("jet_qglP"           , MT2TREE.jet_qgl           [ijet] , evt_scale1fb , h_1d , "jet_qglP"           , 100 , 0 , 100 );
      //      PlotUtil::plot1D("jet_areaP"          , MT2TREE.jet_area          [ijet] , evt_scale1fb , h_1d , "jet_areaP"          , 100 , 0 , 100 );
      //      PlotUtil::plot1D("jet_idP"            , MT2TREE.jet_id            [ijet] , evt_scale1fb , h_1d , "jet_idP"            , 100 , 0 , 100 );
      //      PlotUtil::plot1D("jet_puIdP"          , MT2TREE.jet_puId          [ijet] , evt_scale1fb , h_1d , "jet_puIdP"          , 5   , 0 , 5   );
      //    }
      //  }
      //}

      //// Plotting jet auxillary variable
      //for (int ijet = 0; ijet < 10; ++ijet)
      //{
      //  if (njet > ijet)
      //  {
      //    PlotUtil::plot1D(TString::Format("jet_btagCSV%d"       , ijet).Data() , MT2TREE.jet_btagCSV       [ijet] , evt_scale1fb , h_1d , TString::Format("jet_btagCSV%d"       , ijet).Data() , 100 , 0 , 2   );
      //    PlotUtil::plot1D(TString::Format("jet_rawPt%d"         , ijet).Data() , MT2TREE.jet_rawPt         [ijet] , evt_scale1fb , h_1d , TString::Format("jet_rawPt%d"         , ijet).Data() , 100 , 0 , 100 );
      //    PlotUtil::plot1D(TString::Format("jet_mcPt%d"          , ijet).Data() , MT2TREE.jet_mcPt          [ijet] , evt_scale1fb , h_1d , TString::Format("jet_mcPt%d"          , ijet).Data() , 100 , 0 , 100 );
      //    PlotUtil::plot1D(TString::Format("jet_mcFlavour%d"     , ijet).Data() , MT2TREE.jet_mcFlavour     [ijet] , evt_scale1fb , h_1d , TString::Format("jet_mcFlavour%d"     , ijet).Data() , 30  , 0 , 30  );
      //    PlotUtil::plot1D(TString::Format("jet_hadronFlavour%d" , ijet).Data() , MT2TREE.jet_hadronFlavour [ijet] , evt_scale1fb , h_1d , TString::Format("jet_hadronFlavour%d" , ijet).Data() , 10  , 0 , 10  );
      //    PlotUtil::plot1D(TString::Format("jet_qgl%d"           , ijet).Data() , MT2TREE.jet_qgl           [ijet] , evt_scale1fb , h_1d , TString::Format("jet_qgl%d"           , ijet).Data() , 100 , 0 , 100 );
      //    PlotUtil::plot1D(TString::Format("jet_area%d"          , ijet).Data() , MT2TREE.jet_area          [ijet] , evt_scale1fb , h_1d , TString::Format("jet_area%d"          , ijet).Data() , 100 , 0 , 100 );
      //    PlotUtil::plot1D(TString::Format("jet_id%d"            , ijet).Data() , MT2TREE.jet_id            [ijet] , evt_scale1fb , h_1d , TString::Format("jet_id%d"            , ijet).Data() , 100 , 0 , 100 );
      //    PlotUtil::plot1D(TString::Format("jet_puId%d"          , ijet).Data() , MT2TREE.jet_puId          [ijet] , evt_scale1fb , h_1d , TString::Format("jet_puId%d"          , ijet).Data() , 5   , 0 , 5   );
      //  }
      //}

      //// Plotting integrated lepPt
      //for (int ilep = 0; ilep < 4; ++ilep)
      //{
      //  if (nlep > ilep)
      //    PlotUtil::plot1D("lep_pt", MT2TREE.lep_pt[ilep], evt_scale1fb, h_1d, "lep_pt", 100, 0, 100);
      //}

      // Book keeping
      //++nEventsTotal;

  //  }
  //}

  // Save plots
  //PlotUtil::savePlots(h_1d, output_name+".root");

  //return 0;

