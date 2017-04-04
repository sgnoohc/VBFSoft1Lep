//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Mar 24 17:12:33 2017 by ROOT version 6.06/01
// from TTree mt2/A Baby Ntuple
// found on file: signal.root
//////////////////////////////////////////////////////////

#ifndef MT2Tree_h
#define MT2Tree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class MT2Tree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           run;
   Int_t           lumi;
   ULong64_t       evt;
   Int_t           isData;
   Float_t         evt_scale1fb;
   Float_t         evt_xsec;
   Float_t         evt_kfactor;
   Float_t         evt_filter;
   ULong64_t       evt_nEvts;
   Int_t           evt_id;
   Float_t         genWeight;
   Float_t         puWeight;
   Int_t           nVert;
   Int_t           nTrueInt;
   Float_t         rho;
   Int_t           nJet30;
   Int_t           nJet30JECup;
   Int_t           nJet30JECdn;
   Int_t           nJet40;
   Int_t           nBJet20;
   Int_t           nBJet20JECup;
   Int_t           nBJet20JECdn;
   Int_t           nBJet25;
   Int_t           nBJet30;
   Int_t           nBJet40;
   Int_t           nJet30FailId;
   Int_t           nJet100FailId;
   Int_t           nMuons10;
   Int_t           nElectrons10;
   Int_t           nLepLowMT;
   Int_t           nTaus20;
   Int_t           nGammas20;
   Int_t           nPFCHCand3;
   Float_t         deltaPhiMin;
   Float_t         deltaPhiMinJECup;
   Float_t         deltaPhiMinJECdn;
   Float_t         diffMetMht;
   Float_t         diffMetMhtJECup;
   Float_t         diffMetMhtJECdn;
   Float_t         minMTBMet;
   Float_t         zll_minMTBMet;
   Float_t         gamma_minMTBMet;
   Float_t         ht;
   Float_t         htJECup;
   Float_t         htJECdn;
   Float_t         mt2;
   Float_t         mt2JECup;
   Float_t         mt2JECdn;
   Float_t         mt2_gen;
   Float_t         jet1_pt;
   Float_t         jet2_pt;
   Float_t         jet1_ptJECup;
   Float_t         jet2_ptJECup;
   Float_t         jet1_ptJECdn;
   Float_t         jet2_ptJECdn;
   Int_t           jet_failFSveto;
   Float_t         gamma_jet1_pt;
   Float_t         gamma_jet2_pt;
   Float_t         pseudoJet1_pt;
   Float_t         pseudoJet1_eta;
   Float_t         pseudoJet1_phi;
   Float_t         pseudoJet1_mass;
   Float_t         pseudoJet2_pt;
   Float_t         pseudoJet2_eta;
   Float_t         pseudoJet2_phi;
   Float_t         pseudoJet2_mass;
   Float_t         mht_pt;
   Float_t         mht_phi;
   Float_t         mht_ptJECup;
   Float_t         mht_phiJECup;
   Float_t         mht_ptJECdn;
   Float_t         mht_phiJECdn;
   Float_t         met_pt;
   Float_t         met_phi;
   Float_t         met_ptJECup;
   Float_t         met_phiJECup;
   Float_t         met_ptJECdn;
   Float_t         met_phiJECdn;
   Float_t         met_rawPt;
   Float_t         met_rawPhi;
   Float_t         met_caloPt;
   Float_t         met_caloPhi;
   Float_t         met_trkPt;
   Float_t         met_trkPhi;
   Float_t         met_genPt;
   Float_t         met_genPhi;
   Int_t           Flag_EcalDeadCellTriggerPrimitiveFilter;
   Int_t           Flag_trkPOG_manystripclus53X;
   Int_t           Flag_ecalLaserCorrFilter;
   Int_t           Flag_trkPOG_toomanystripclus53X;
   Int_t           Flag_hcalLaserEventFilter;
   Int_t           Flag_trkPOG_logErrorTooManyClusters;
   Int_t           Flag_trkPOGFilters;
   Int_t           Flag_trackingFailureFilter;
   Int_t           Flag_CSCTightHaloFilter;
   Int_t           Flag_HBHENoiseFilter;
   Int_t           Flag_HBHEIsoNoiseFilter;
   Int_t           Flag_goodVertices;
   Int_t           Flag_eeBadScFilter;
   Int_t           Flag_METFilters;
   Int_t           HLT_PFHT800;
   Int_t           HLT_PFHT900;
   Int_t           HLT_PFMET170;
   Int_t           HLT_PFHT350_PFMET100;
   Int_t           HLT_PFHT350_PFMET120;
   Int_t           HLT_PFMETNoMu90_PFMHTNoMu90;
   Int_t           HLT_MonoCentralPFJet80_PFMETNoMu90_PFMHTNoMu90;
   Int_t           HLT_PFMETNoMu120_PFMHTNoMu120;
   Int_t           HLT_PFMET90_PFMHT90;
   Int_t           HLT_SingleMu;
   Int_t           HLT_SingleEl;
   Int_t           HLT_DoubleEl;
   Int_t           HLT_DoubleEl33;
   Int_t           HLT_MuX_Ele12;
   Int_t           HLT_Mu8_EleX;
   Int_t           HLT_DoubleMu;
   Int_t           HLT_Photon120;
   Int_t           HLT_Photon165_HE10;
   Int_t           HLT_PFHT200_Prescale;
   Int_t           HLT_PFHT300_Prescale;
   Int_t           HLT_PFHT350_Prescale;
   Int_t           HLT_PFHT475_Prescale;
   Int_t           HLT_PFHT600_Prescale;
   Int_t           HLT_DiCentralPFJet70_PFMET120;
   Int_t           HLT_DiCentralPFJet55_PFMET110;
   Int_t           nlep;
   Int_t           nlepIso;
   Int_t           nlepIso20;
   Float_t         lep_pt[4];   //[nlep]
   Float_t         lep_eta[4];   //[nlep]
   Float_t         lep_phi[4];   //[nlep]
   Float_t         lep_mass[4];   //[nlep]
   Int_t           lep_charge[4];   //[nlep]
   Int_t           lep_pdgId[4];   //[nlep]
   Float_t         lep_dxy[4];   //[nlep]
   Float_t         lep_dz[4];   //[nlep]
   Int_t           lep_tightId[4];   //[nlep]
   Int_t           lep_heepId[4];   //[nlep]
   Float_t         lep_relIso03[4];   //[nlep]
   Float_t         lep_relIso04[4];   //[nlep]
   Float_t         lep_miniRelIso[4];   //[nlep]
   Float_t         lep_relIsoAn04[4];   //[nlep]
   Int_t           lep_mcMatchId[4];   //[nlep]
   Int_t           lep_lostHits[4];   //[nlep]
   Int_t           lep_convVeto[4];   //[nlep]
   Int_t           lep_tightCharge[4];   //[nlep]
   Float_t         lep_mva[4];   //[nlep]
   Float_t         lep_ptRatio[4];   //[nlep]
   Float_t         lep_ptRel[4];   //[nlep]
   Int_t           lep_tightIdNoIso[4];   //[nlep]
   Float_t         lep_sip3d[4];   //[nlep]
   Int_t           nisoTrack;
   Float_t         isoTrack_pt[3];   //[nisoTrack]
   Float_t         isoTrack_eta[3];   //[nisoTrack]
   Float_t         isoTrack_phi[3];   //[nisoTrack]
   Float_t         isoTrack_mass[3];   //[nisoTrack]
   Float_t         isoTrack_absIso[3];   //[nisoTrack]
   Float_t         isoTrack_relIsoAn04[3];   //[nisoTrack]
   Float_t         isoTrack_dz[3];   //[nisoTrack]
   Int_t           isoTrack_pdgId[3];   //[nisoTrack]
   Int_t           isoTrack_mcMatchId[3];   //[nisoTrack]
   Int_t           nPFLep5LowMT;
   Int_t           nPFHad10LowMT;
   Int_t           nPFHad10;
   Int_t           ntau;
   Float_t         tau_pt[4];   //[ntau]
   Float_t         tau_eta[4];   //[ntau]
   Float_t         tau_phi[4];   //[ntau]
   Float_t         tau_mass[4];   //[ntau]
   Int_t           tau_charge[4];   //[ntau]
   Float_t         tau_dxy[4];   //[ntau]
   Float_t         tau_dz[4];   //[ntau]
   Int_t           tau_idCI3hit[4];   //[ntau]
   Float_t         tau_isoCI3hit[4];   //[ntau]
   Int_t           tau_mcMatchId[4];   //[ntau]
   Int_t           ngamma;
   Float_t         gamma_pt[1];   //[ngamma]
   Float_t         gamma_eta[1];   //[ngamma]
   Float_t         gamma_phi[1];   //[ngamma]
   Float_t         gamma_mass[1];   //[ngamma]
   Int_t           gamma_mcMatchId[1];   //[ngamma]
   Float_t         gamma_genIso04[1];   //[ngamma]
   Float_t         gamma_drMinParton[1];   //[ngamma]
   Float_t         gamma_chHadIso[1];   //[ngamma]
   Float_t         gamma_neuHadIso[1];   //[ngamma]
   Float_t         gamma_phIso[1];   //[ngamma]
   Float_t         gamma_sigmaIetaIeta[1];   //[ngamma]
   Float_t         gamma_r9[1];   //[ngamma]
   Float_t         gamma_hOverE[1];   //[ngamma]
   Int_t           gamma_idCutBased[1];   //[ngamma]
   Float_t         sl_mt2;
   Float_t         gamma_mt2;
   Int_t           gamma_nJet30;
   Int_t           gamma_nJet40;
   Int_t           gamma_nJet30FailId;
   Int_t           gamma_nJet100FailId;
   Int_t           gamma_nBJet20;
   Int_t           gamma_nBJet25;
   Int_t           gamma_nBJet30;
   Int_t           gamma_nBJet40;
   Float_t         gamma_ht;
   Float_t         gamma_deltaPhiMin;
   Float_t         gamma_diffMetMht;
   Float_t         gamma_mht_pt;
   Float_t         gamma_mht_phi;
   Float_t         gamma_met_pt;
   Float_t         gamma_met_phi;
   Float_t         zll_mt2;
   Float_t         zll_deltaPhiMin;
   Float_t         zll_diffMetMht;
   Float_t         zll_met_pt;
   Float_t         zll_met_phi;
   Float_t         zll_mht_pt;
   Float_t         zll_mht_phi;
   Float_t         zll_mass;
   Float_t         zll_pt;
   Float_t         zll_eta;
   Float_t         zll_phi;
   Float_t         zll_ht;
   Float_t         zllmt_mt2;
   Float_t         zllmt_deltaPhiMin;
   Float_t         zllmt_diffMetMht;
   Float_t         zllmt_met_pt;
   Float_t         zllmt_met_phi;
   Float_t         zllmt_mht_pt;
   Float_t         zllmt_mht_phi;
   Float_t         zllmt_ht;
   Float_t         zllmt_mt;
   Float_t         rl_mt2;
   Float_t         rl_deltaPhiMin;
   Float_t         rl_diffMetMht;
   Float_t         rl_met_pt;
   Float_t         rl_met_phi;
   Float_t         rl_mht_pt;
   Float_t         rl_mht_phi;
   Float_t         rl_mass;
   Float_t         rl_pt;
   Float_t         rl_eta;
   Float_t         rl_phi;
   Float_t         rl_ht;
   Int_t           ngenLep;
   Float_t         genLep_pt[4];   //[ngenLep]
   Float_t         genLep_eta[4];   //[ngenLep]
   Float_t         genLep_phi[4];   //[ngenLep]
   Float_t         genLep_mass[4];   //[ngenLep]
   Int_t           genLep_pdgId[4];   //[ngenLep]
   Int_t           genLep_status[4];   //[ngenLep]
   Float_t         genLep_charge[4];   //[ngenLep]
   Int_t           genLep_sourceId[4];   //[ngenLep]
   Int_t           ngenStat23;
   Float_t         genStat23_pt[11];   //[ngenStat23]
   Float_t         genStat23_eta[11];   //[ngenStat23]
   Float_t         genStat23_phi[11];   //[ngenStat23]
   Float_t         genStat23_mass[11];   //[ngenStat23]
   Int_t           genStat23_pdgId[11];   //[ngenStat23]
   Int_t           genStat23_status[11];   //[ngenStat23]
   Float_t         genStat23_charge[11];   //[ngenStat23]
   Int_t           genStat23_sourceId[11];   //[ngenStat23]
   Int_t           ngenGamma;
   Float_t         genGamma_pt[5];   //[ngenGamma]
   Float_t         genGamma_eta[5];   //[ngenGamma]
   Float_t         genGamma_phi[5];   //[ngenGamma]
   Int_t           genGamma_motherId[5];   //[ngenGamma]
   Int_t           ngenTau;
   Int_t           ngenTau1Prong;
   Int_t           ngenTau3Prong;
   Float_t         genTau_pt[3];   //[ngenTau]
   Float_t         genTau_eta[3];   //[ngenTau]
   Float_t         genTau_phi[3];   //[ngenTau]
   Float_t         genTau_mass[3];   //[ngenTau]
   Int_t           genTau_pdgId[3];   //[ngenTau]
   Int_t           genTau_status[3];   //[ngenTau]
   Float_t         genTau_charge[3];   //[ngenTau]
   Int_t           genTau_sourceId[3];   //[ngenTau]
   Int_t           genTau_decayMode[3];   //[ngenTau]
   Float_t         genTau_leadTrackPt[3];   //[ngenTau]
   Int_t           genTau_neutralDaughters[3];   //[ngenTau]
   Int_t           ngenLepFromTau;
   Float_t         genLepFromTau_pt[2];   //[ngenLepFromTau]
   Float_t         genLepFromTau_eta[2];   //[ngenLepFromTau]
   Float_t         genLepFromTau_phi[2];   //[ngenLepFromTau]
   Float_t         genLepFromTau_mass[2];   //[ngenLepFromTau]
   Int_t           genLepFromTau_pdgId[2];   //[ngenLepFromTau]
   Int_t           genLepFromTau_status[2];   //[ngenLepFromTau]
   Float_t         genLepFromTau_charge[2];   //[ngenLepFromTau]
   Int_t           genLepFromTau_sourceId[2];   //[ngenLepFromTau]
   Int_t           GenSusyMScan1;
   Int_t           GenSusyMScan2;
   Int_t           GenSusyMScan3;
   Int_t           GenSusyMScan4;
   Int_t           nLHEweight;
   Float_t         LHEweight_wgt[9];   //[nLHEweight]
   Int_t           njet;
   Float_t         jet_pt[10];   //[njet]
   Float_t         jet_eta[10];   //[njet]
   Float_t         jet_phi[10];   //[njet]
   Float_t         jet_mass[10];   //[njet]
   Float_t         jet_btagCSV[10];   //[njet]
   Float_t         jet_rawPt[10];   //[njet]
   Float_t         jet_mcPt[10];   //[njet]
   Float_t         jet_chf[10];   //[njet]
   Int_t           jet_FSveto[10];   //[njet]
   Int_t           jet_mcFlavour[10];   //[njet]
   Int_t           jet_hadronFlavour[10];   //[njet]
   Float_t         jet_qgl[10];   //[njet]
   Float_t         jet_area[10];   //[njet]
   Int_t           jet_id[10];   //[njet]
   Int_t           jet_puId[10];   //[njet]
   Float_t         weight_lepsf;
   Float_t         weight_lepsf_UP;
   Float_t         weight_lepsf_DN;
   Float_t         weight_btagsf;
   Float_t         weight_btagsf_heavy_UP;
   Float_t         weight_btagsf_light_UP;
   Float_t         weight_btagsf_heavy_DN;
   Float_t         weight_btagsf_light_DN;
   Float_t         weight_sigtrigsf;
   Float_t         weight_dileptrigsf;
   Float_t         weight_phottrigsf;
   Float_t         weight_pu;
   Float_t         weight_isr;
   Float_t         weight_scales_UP;
   Float_t         weight_scales_DN;
   Float_t         weight_pdfs_UP;
   Float_t         weight_pdfs_DN;
   Float_t         weight_toppt;
   Float_t         genRecoil_pt;
   Float_t         genTop_pt;
   Float_t         genTbar_pt;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_evt;   //!
   TBranch        *b_isData;   //!
   TBranch        *b_evt_scale1fb;   //!
   TBranch        *b_evt_xsec;   //!
   TBranch        *b_evt_kfactor;   //!
   TBranch        *b_evt_filter;   //!
   TBranch        *b_evt_nEvts;   //!
   TBranch        *b_evt_id;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_puWeight;   //!
   TBranch        *b_nVert;   //!
   TBranch        *b_nTrueInt;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_nJet30;   //!
   TBranch        *b_nJet30JECup;   //!
   TBranch        *b_nJet30JECdn;   //!
   TBranch        *b_nJet40;   //!
   TBranch        *b_nBJet20;   //!
   TBranch        *b_nBJet20JECup;   //!
   TBranch        *b_nBJet20JECdn;   //!
   TBranch        *b_nBJet25;   //!
   TBranch        *b_nBJet30;   //!
   TBranch        *b_nBJet40;   //!
   TBranch        *b_nJet30FailId;   //!
   TBranch        *b_nJet100FailId;   //!
   TBranch        *b_nMuons10;   //!
   TBranch        *b_nElectrons10;   //!
   TBranch        *b_nLepLowMT;   //!
   TBranch        *b_nTaus20;   //!
   TBranch        *b_nGammas20;   //!
   TBranch        *b_nPFCHCand3;   //!
   TBranch        *b_deltaPhiMin;   //!
   TBranch        *b_deltaPhiMinJECup;   //!
   TBranch        *b_deltaPhiMinJECdn;   //!
   TBranch        *b_diffMetMht;   //!
   TBranch        *b_diffMetMhtJECup;   //!
   TBranch        *b_diffMetMhtJECdn;   //!
   TBranch        *b_minMTBMet;   //!
   TBranch        *b_zll_minMTBMet;   //!
   TBranch        *b_gamma_minMTBMet;   //!
   TBranch        *b_ht;   //!
   TBranch        *b_htJECup;   //!
   TBranch        *b_htJECdn;   //!
   TBranch        *b_mt2;   //!
   TBranch        *b_mt2JECup;   //!
   TBranch        *b_mt2JECdn;   //!
   TBranch        *b_mt2_gen;   //!
   TBranch        *b_jet1_pt;   //!
   TBranch        *b_jet2_pt;   //!
   TBranch        *b_jet1_ptJECup;   //!
   TBranch        *b_jet2_ptJECup;   //!
   TBranch        *b_jet1_ptJECdn;   //!
   TBranch        *b_jet2_ptJECdn;   //!
   TBranch        *b_jet_failFSveto;   //!
   TBranch        *b_gamma_jet1_pt;   //!
   TBranch        *b_gamma_jet2_pt;   //!
   TBranch        *b_pseudoJet1_pt;   //!
   TBranch        *b_pseudoJet1_eta;   //!
   TBranch        *b_pseudoJet1_phi;   //!
   TBranch        *b_pseudoJet1_mass;   //!
   TBranch        *b_pseudoJet2_pt;   //!
   TBranch        *b_pseudoJet2_eta;   //!
   TBranch        *b_pseudoJet2_phi;   //!
   TBranch        *b_pseudoJet2_mass;   //!
   TBranch        *b_mht_pt;   //!
   TBranch        *b_mht_phi;   //!
   TBranch        *b_mht_ptJECup;   //!
   TBranch        *b_mht_phiJECup;   //!
   TBranch        *b_mht_ptJECdn;   //!
   TBranch        *b_mht_phiJECdn;   //!
   TBranch        *b_met_pt;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_met_ptJECup;   //!
   TBranch        *b_met_phiJECup;   //!
   TBranch        *b_met_ptJECdn;   //!
   TBranch        *b_met_phiJECdn;   //!
   TBranch        *b_met_rawPt;   //!
   TBranch        *b_met_rawPhi;   //!
   TBranch        *b_met_caloPt;   //!
   TBranch        *b_met_caloPhi;   //!
   TBranch        *b_met_trkPt;   //!
   TBranch        *b_met_trkPhi;   //!
   TBranch        *b_met_genPt;   //!
   TBranch        *b_met_genPhi;   //!
   TBranch        *b_Flag_EcalDeadCellTriggerPrimitiveFilter;   //!
   TBranch        *b_Flag_trkPOG_manystripclus53X;   //!
   TBranch        *b_Flag_ecalLaserCorrFilter;   //!
   TBranch        *b_Flag_trkPOG_toomanystripclus53X;   //!
   TBranch        *b_Flag_hcalLaserEventFilter;   //!
   TBranch        *b_Flag_trkPOG_logErrorTooManyClusters;   //!
   TBranch        *b_Flag_trkPOGFilters;   //!
   TBranch        *b_Flag_trackingFailureFilter;   //!
   TBranch        *b_Flag_CSCTightHaloFilter;   //!
   TBranch        *b_Flag_HBHENoiseFilter;   //!
   TBranch        *b_Flag_HBHEIsoNoiseFilter;   //!
   TBranch        *b_Flag_goodVertices;   //!
   TBranch        *b_Flag_eeBadScFilter;   //!
   TBranch        *b_Flag_METFilters;   //!
   TBranch        *b_HLT_PFHT800;   //!
   TBranch        *b_HLT_PFHT900;   //!
   TBranch        *b_HLT_PFMET170;   //!
   TBranch        *b_HLT_PFHT350_PFMET100;   //!
   TBranch        *b_HLT_PFHT350_PFMET120;   //!
   TBranch        *b_HLT_PFMETNoMu90_PFMHTNoMu90;   //!
   TBranch        *b_HLT_MonoCentralPFJet80_PFMETNoMu90_PFMHTNoMu90;   //!
   TBranch        *b_HLT_PFMETNoMu120_PFMHTNoMu120;   //!
   TBranch        *b_HLT_PFMET90_PFMHT90;   //!
   TBranch        *b_HLT_SingleMu;   //!
   TBranch        *b_HLT_SingleEl;   //!
   TBranch        *b_HLT_DoubleEl;   //!
   TBranch        *b_HLT_DoubleEl33;   //!
   TBranch        *b_HLT_MuX_Ele12;   //!
   TBranch        *b_HLT_Mu8_EleX;   //!
   TBranch        *b_HLT_DoubleMu;   //!
   TBranch        *b_HLT_Photon120;   //!
   TBranch        *b_HLT_Photon165_HE10;   //!
   TBranch        *b_HLT_PFHT200_Prescale;   //!
   TBranch        *b_HLT_PFHT300_Prescale;   //!
   TBranch        *b_HLT_PFHT350_Prescale;   //!
   TBranch        *b_HLT_PFHT475_Prescale;   //!
   TBranch        *b_HLT_PFHT600_Prescale;   //!
   TBranch        *b_HLT_DiCentralPFJet70_PFMET120;   //!
   TBranch        *b_HLT_DiCentralPFJet55_PFMET110;   //!
   TBranch        *b_nlep;   //!
   TBranch        *b_nlepIso;   //!
   TBranch        *b_nlepIso20;   //!
   TBranch        *b_lep_pt;   //!
   TBranch        *b_lep_eta;   //!
   TBranch        *b_lep_phi;   //!
   TBranch        *b_lep_mass;   //!
   TBranch        *b_lep_charge;   //!
   TBranch        *b_lep_pdgId;   //!
   TBranch        *b_lep_dxy;   //!
   TBranch        *b_lep_dz;   //!
   TBranch        *b_lep_tightId;   //!
   TBranch        *b_lep_heepId;   //!
   TBranch        *b_lep_relIso03;   //!
   TBranch        *b_lep_relIso04;   //!
   TBranch        *b_lep_miniRelIso;   //!
   TBranch        *b_lep_relIsoAn04;   //!
   TBranch        *b_lep_mcMatchId;   //!
   TBranch        *b_lep_lostHits;   //!
   TBranch        *b_lep_convVeto;   //!
   TBranch        *b_lep_tightCharge;   //!
   TBranch        *b_lep_mva;   //!
   TBranch        *b_lep_ptRatio;   //!
   TBranch        *b_lep_ptRel;   //!
   TBranch        *b_lep_tightIdNoIso;   //!
   TBranch        *b_lep_sip3d;   //!
   TBranch        *b_nisoTrack;   //!
   TBranch        *b_isoTrack_pt;   //!
   TBranch        *b_isoTrack_eta;   //!
   TBranch        *b_isoTrack_phi;   //!
   TBranch        *b_isoTrack_mass;   //!
   TBranch        *b_isoTrack_absIso;   //!
   TBranch        *b_isoTrack_relIsoAn04;   //!
   TBranch        *b_isoTrack_dz;   //!
   TBranch        *b_isoTrack_pdgId;   //!
   TBranch        *b_isoTrack_mcMatchId;   //!
   TBranch        *b_nPFLep5LowMT;   //!
   TBranch        *b_nPFHad10LowMT;   //!
   TBranch        *b_nPFHad10;   //!
   TBranch        *b_ntau;   //!
   TBranch        *b_tau_pt;   //!
   TBranch        *b_tau_eta;   //!
   TBranch        *b_tau_phi;   //!
   TBranch        *b_tau_mass;   //!
   TBranch        *b_tau_charge;   //!
   TBranch        *b_tau_dxy;   //!
   TBranch        *b_tau_dz;   //!
   TBranch        *b_tau_idCI3hit;   //!
   TBranch        *b_tau_isoCI3hit;   //!
   TBranch        *b_tau_mcMatchId;   //!
   TBranch        *b_ngamma;   //!
   TBranch        *b_gamma_pt;   //!
   TBranch        *b_gamma_eta;   //!
   TBranch        *b_gamma_phi;   //!
   TBranch        *b_gamma_mass;   //!
   TBranch        *b_gamma_mcMatchId;   //!
   TBranch        *b_gamma_genIso04;   //!
   TBranch        *b_gamma_drMinParton;   //!
   TBranch        *b_gamma_chHadIso;   //!
   TBranch        *b_gamma_neuHadIso;   //!
   TBranch        *b_gamma_phIso;   //!
   TBranch        *b_gamma_sigmaIetaIeta;   //!
   TBranch        *b_gamma_r9;   //!
   TBranch        *b_gamma_hOverE;   //!
   TBranch        *b_gamma_idCutBased;   //!
   TBranch        *b_sl_mt2;   //!
   TBranch        *b_gamma_mt2;   //!
   TBranch        *b_gamma_nJet30;   //!
   TBranch        *b_gamma_nJet40;   //!
   TBranch        *b_gamma_nJet30FailId;   //!
   TBranch        *b_gamma_nJet100FailId;   //!
   TBranch        *b_gamma_nBJet20;   //!
   TBranch        *b_gamma_nBJet25;   //!
   TBranch        *b_gamma_nBJet30;   //!
   TBranch        *b_gamma_nBJet40;   //!
   TBranch        *b_gamma_ht;   //!
   TBranch        *b_gamma_deltaPhiMin;   //!
   TBranch        *b_gamma_diffMetMht;   //!
   TBranch        *b_gamma_mht_pt;   //!
   TBranch        *b_gamma_mht_phi;   //!
   TBranch        *b_gamma_met_pt;   //!
   TBranch        *b_gamma_met_phi;   //!
   TBranch        *b_zll_mt2;   //!
   TBranch        *b_zll_deltaPhiMin;   //!
   TBranch        *b_zll_diffMetMht;   //!
   TBranch        *b_zll_met_pt;   //!
   TBranch        *b_zll_met_phi;   //!
   TBranch        *b_zll_mht_pt;   //!
   TBranch        *b_zll_mht_phi;   //!
   TBranch        *b_zll_mass;   //!
   TBranch        *b_zll_pt;   //!
   TBranch        *b_zll_eta;   //!
   TBranch        *b_zll_phi;   //!
   TBranch        *b_zll_ht;   //!
   TBranch        *b_zllmt_mt2;   //!
   TBranch        *b_zllmt_deltaPhiMin;   //!
   TBranch        *b_zllmt_diffMetMht;   //!
   TBranch        *b_zllmt_met_pt;   //!
   TBranch        *b_zllmt_met_phi;   //!
   TBranch        *b_zllmt_mht_pt;   //!
   TBranch        *b_zllmt_mht_phi;   //!
   TBranch        *b_zllmt_ht;   //!
   TBranch        *b_zllmt_mt;   //!
   TBranch        *b_rl_mt2;   //!
   TBranch        *b_rl_deltaPhiMin;   //!
   TBranch        *b_rl_diffMetMht;   //!
   TBranch        *b_rl_met_pt;   //!
   TBranch        *b_rl_met_phi;   //!
   TBranch        *b_rl_mht_pt;   //!
   TBranch        *b_rl_mht_phi;   //!
   TBranch        *b_rl_mass;   //!
   TBranch        *b_rl_pt;   //!
   TBranch        *b_rl_eta;   //!
   TBranch        *b_rl_phi;   //!
   TBranch        *b_rl_ht;   //!
   TBranch        *b_ngenLep;   //!
   TBranch        *b_genLep_pt;   //!
   TBranch        *b_genLep_eta;   //!
   TBranch        *b_genLep_phi;   //!
   TBranch        *b_genLep_mass;   //!
   TBranch        *b_genLep_pdgId;   //!
   TBranch        *b_genLep_status;   //!
   TBranch        *b_genLep_charge;   //!
   TBranch        *b_genLep_sourceId;   //!
   TBranch        *b_ngenStat23;   //!
   TBranch        *b_genStat23_pt;   //!
   TBranch        *b_genStat23_eta;   //!
   TBranch        *b_genStat23_phi;   //!
   TBranch        *b_genStat23_mass;   //!
   TBranch        *b_genStat23_pdgId;   //!
   TBranch        *b_genStat23_status;   //!
   TBranch        *b_genStat23_charge;   //!
   TBranch        *b_genStat23_sourceId;   //!
   TBranch        *b_ngenGamma;   //!
   TBranch        *b_genGamma_pt;   //!
   TBranch        *b_genGamma_eta;   //!
   TBranch        *b_genGamma_phi;   //!
   TBranch        *b_genGamma_motherId;   //!
   TBranch        *b_ngenTau;   //!
   TBranch        *b_ngenTau1Prong;   //!
   TBranch        *b_ngenTau3Prong;   //!
   TBranch        *b_genTau_pt;   //!
   TBranch        *b_genTau_eta;   //!
   TBranch        *b_genTau_phi;   //!
   TBranch        *b_genTau_mass;   //!
   TBranch        *b_genTau_pdgId;   //!
   TBranch        *b_genTau_status;   //!
   TBranch        *b_genTau_charge;   //!
   TBranch        *b_genTau_sourceId;   //!
   TBranch        *b_genTau_decayMode;   //!
   TBranch        *b_genTau_leadTrackPt;   //!
   TBranch        *b_genTau_neutralDaughters;   //!
   TBranch        *b_ngenLepFromTau;   //!
   TBranch        *b_genLepFromTau_pt;   //!
   TBranch        *b_genLepFromTau_eta;   //!
   TBranch        *b_genLepFromTau_phi;   //!
   TBranch        *b_genLepFromTau_mass;   //!
   TBranch        *b_genLepFromTau_pdgId;   //!
   TBranch        *b_genLepFromTau_status;   //!
   TBranch        *b_genLepFromTau_charge;   //!
   TBranch        *b_genLepFromTau_sourceId;   //!
   TBranch        *b_GenSusyMScan1;   //!
   TBranch        *b_GenSusyMScan2;   //!
   TBranch        *b_GenSusyMScan3;   //!
   TBranch        *b_GenSusyMScan4;   //!
   TBranch        *b_nLHEweight;   //!
   TBranch        *b_LHEweight_wgt;   //!
   TBranch        *b_njet;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_mass;   //!
   TBranch        *b_jet_btagCSV;   //!
   TBranch        *b_jet_rawPt;   //!
   TBranch        *b_jet_mcPt;   //!
   TBranch        *b_jet_chf;   //!
   TBranch        *b_jet_FSveto;   //!
   TBranch        *b_jet_mcFlavour;   //!
   TBranch        *b_jet_hadronFlavour;   //!
   TBranch        *b_jet_qgl;   //!
   TBranch        *b_jet_area;   //!
   TBranch        *b_jet_id;   //!
   TBranch        *b_jet_puId;   //!
   TBranch        *b_weight_lepsf;   //!
   TBranch        *b_weight_lepsf_UP;   //!
   TBranch        *b_weight_lepsf_DN;   //!
   TBranch        *b_weight_btagsf;   //!
   TBranch        *b_weight_btagsf_heavy_UP;   //!
   TBranch        *b_weight_btagsf_light_UP;   //!
   TBranch        *b_weight_btagsf_heavy_DN;   //!
   TBranch        *b_weight_btagsf_light_DN;   //!
   TBranch        *b_weight_sigtrigsf;   //!
   TBranch        *b_weight_dileptrigsf;   //!
   TBranch        *b_weight_phottrigsf;   //!
   TBranch        *b_weight_pu;   //!
   TBranch        *b_weight_isr;   //!
   TBranch        *b_weight_scales_UP;   //!
   TBranch        *b_weight_scales_DN;   //!
   TBranch        *b_weight_pdfs_UP;   //!
   TBranch        *b_weight_pdfs_DN;   //!
   TBranch        *b_weight_toppt;   //!
   TBranch        *b_genRecoil_pt;   //!
   TBranch        *b_genTop_pt;   //!
   TBranch        *b_genTbar_pt;   //!

   MT2Tree(TTree *tree=0);
   virtual ~MT2Tree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

