#include "MT2TreeSig.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

MT2TreeSig::MT2TreeSig(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("signal.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("signal.root");
      }
      f->GetObject("mt2",tree);

   }
   Init(tree);
}

MT2TreeSig::~MT2TreeSig()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t MT2TreeSig::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t MT2TreeSig::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void MT2TreeSig::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("evt", &evt, &b_evt);
   fChain->SetBranchAddress("isData", &isData, &b_isData);
   fChain->SetBranchAddress("evt_scale1fb", &evt_scale1fb, &b_evt_scale1fb);
   fChain->SetBranchAddress("evt_xsec", &evt_xsec, &b_evt_xsec);
   fChain->SetBranchAddress("evt_kfactor", &evt_kfactor, &b_evt_kfactor);
   fChain->SetBranchAddress("evt_filter", &evt_filter, &b_evt_filter);
   fChain->SetBranchAddress("evt_nEvts", &evt_nEvts, &b_evt_nEvts);
   fChain->SetBranchAddress("evt_id", &evt_id, &b_evt_id);
   fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
   fChain->SetBranchAddress("puWeight", &puWeight, &b_puWeight);
   fChain->SetBranchAddress("nVert", &nVert, &b_nVert);
   fChain->SetBranchAddress("nTrueInt", &nTrueInt, &b_nTrueInt);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("nJet30", &nJet30, &b_nJet30);
   fChain->SetBranchAddress("nJet30JECup", &nJet30JECup, &b_nJet30JECup);
   fChain->SetBranchAddress("nJet30JECdn", &nJet30JECdn, &b_nJet30JECdn);
   fChain->SetBranchAddress("nJet40", &nJet40, &b_nJet40);
   fChain->SetBranchAddress("nBJet20", &nBJet20, &b_nBJet20);
   fChain->SetBranchAddress("nBJet20JECup", &nBJet20JECup, &b_nBJet20JECup);
   fChain->SetBranchAddress("nBJet20JECdn", &nBJet20JECdn, &b_nBJet20JECdn);
   fChain->SetBranchAddress("nBJet25", &nBJet25, &b_nBJet25);
   fChain->SetBranchAddress("nBJet30", &nBJet30, &b_nBJet30);
   fChain->SetBranchAddress("nBJet40", &nBJet40, &b_nBJet40);
   fChain->SetBranchAddress("nJet30FailId", &nJet30FailId, &b_nJet30FailId);
   fChain->SetBranchAddress("nJet100FailId", &nJet100FailId, &b_nJet100FailId);
   fChain->SetBranchAddress("nMuons10", &nMuons10, &b_nMuons10);
   fChain->SetBranchAddress("nElectrons10", &nElectrons10, &b_nElectrons10);
   fChain->SetBranchAddress("nLepLowMT", &nLepLowMT, &b_nLepLowMT);
   fChain->SetBranchAddress("nTaus20", &nTaus20, &b_nTaus20);
   fChain->SetBranchAddress("nGammas20", &nGammas20, &b_nGammas20);
   fChain->SetBranchAddress("nPFCHCand3", &nPFCHCand3, &b_nPFCHCand3);
   fChain->SetBranchAddress("deltaPhiMin", &deltaPhiMin, &b_deltaPhiMin);
   fChain->SetBranchAddress("deltaPhiMinJECup", &deltaPhiMinJECup, &b_deltaPhiMinJECup);
   fChain->SetBranchAddress("deltaPhiMinJECdn", &deltaPhiMinJECdn, &b_deltaPhiMinJECdn);
   fChain->SetBranchAddress("diffMetMht", &diffMetMht, &b_diffMetMht);
   fChain->SetBranchAddress("diffMetMhtJECup", &diffMetMhtJECup, &b_diffMetMhtJECup);
   fChain->SetBranchAddress("diffMetMhtJECdn", &diffMetMhtJECdn, &b_diffMetMhtJECdn);
   fChain->SetBranchAddress("minMTBMet", &minMTBMet, &b_minMTBMet);
   fChain->SetBranchAddress("zll_minMTBMet", &zll_minMTBMet, &b_zll_minMTBMet);
   fChain->SetBranchAddress("gamma_minMTBMet", &gamma_minMTBMet, &b_gamma_minMTBMet);
   fChain->SetBranchAddress("ht", &ht, &b_ht);
   fChain->SetBranchAddress("htJECup", &htJECup, &b_htJECup);
   fChain->SetBranchAddress("htJECdn", &htJECdn, &b_htJECdn);
   fChain->SetBranchAddress("mt2", &mt2, &b_mt2);
   fChain->SetBranchAddress("mt2JECup", &mt2JECup, &b_mt2JECup);
   fChain->SetBranchAddress("mt2JECdn", &mt2JECdn, &b_mt2JECdn);
   fChain->SetBranchAddress("mt2_gen", &mt2_gen, &b_mt2_gen);
   fChain->SetBranchAddress("jet1_pt", &jet1_pt, &b_jet1_pt);
   fChain->SetBranchAddress("jet2_pt", &jet2_pt, &b_jet2_pt);
   fChain->SetBranchAddress("jet1_ptJECup", &jet1_ptJECup, &b_jet1_ptJECup);
   fChain->SetBranchAddress("jet2_ptJECup", &jet2_ptJECup, &b_jet2_ptJECup);
   fChain->SetBranchAddress("jet1_ptJECdn", &jet1_ptJECdn, &b_jet1_ptJECdn);
   fChain->SetBranchAddress("jet2_ptJECdn", &jet2_ptJECdn, &b_jet2_ptJECdn);
   fChain->SetBranchAddress("jet_failFSveto", &jet_failFSveto, &b_jet_failFSveto);
   fChain->SetBranchAddress("gamma_jet1_pt", &gamma_jet1_pt, &b_gamma_jet1_pt);
   fChain->SetBranchAddress("gamma_jet2_pt", &gamma_jet2_pt, &b_gamma_jet2_pt);
   fChain->SetBranchAddress("pseudoJet1_pt", &pseudoJet1_pt, &b_pseudoJet1_pt);
   fChain->SetBranchAddress("pseudoJet1_eta", &pseudoJet1_eta, &b_pseudoJet1_eta);
   fChain->SetBranchAddress("pseudoJet1_phi", &pseudoJet1_phi, &b_pseudoJet1_phi);
   fChain->SetBranchAddress("pseudoJet1_mass", &pseudoJet1_mass, &b_pseudoJet1_mass);
   fChain->SetBranchAddress("pseudoJet2_pt", &pseudoJet2_pt, &b_pseudoJet2_pt);
   fChain->SetBranchAddress("pseudoJet2_eta", &pseudoJet2_eta, &b_pseudoJet2_eta);
   fChain->SetBranchAddress("pseudoJet2_phi", &pseudoJet2_phi, &b_pseudoJet2_phi);
   fChain->SetBranchAddress("pseudoJet2_mass", &pseudoJet2_mass, &b_pseudoJet2_mass);
   fChain->SetBranchAddress("mht_pt", &mht_pt, &b_mht_pt);
   fChain->SetBranchAddress("mht_phi", &mht_phi, &b_mht_phi);
   fChain->SetBranchAddress("mht_ptJECup", &mht_ptJECup, &b_mht_ptJECup);
   fChain->SetBranchAddress("mht_phiJECup", &mht_phiJECup, &b_mht_phiJECup);
   fChain->SetBranchAddress("mht_ptJECdn", &mht_ptJECdn, &b_mht_ptJECdn);
   fChain->SetBranchAddress("mht_phiJECdn", &mht_phiJECdn, &b_mht_phiJECdn);
   fChain->SetBranchAddress("met_pt", &met_pt, &b_met_pt);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("met_ptJECup", &met_ptJECup, &b_met_ptJECup);
   fChain->SetBranchAddress("met_phiJECup", &met_phiJECup, &b_met_phiJECup);
   fChain->SetBranchAddress("met_ptJECdn", &met_ptJECdn, &b_met_ptJECdn);
   fChain->SetBranchAddress("met_phiJECdn", &met_phiJECdn, &b_met_phiJECdn);
   fChain->SetBranchAddress("met_rawPt", &met_rawPt, &b_met_rawPt);
   fChain->SetBranchAddress("met_rawPhi", &met_rawPhi, &b_met_rawPhi);
   fChain->SetBranchAddress("met_caloPt", &met_caloPt, &b_met_caloPt);
   fChain->SetBranchAddress("met_caloPhi", &met_caloPhi, &b_met_caloPhi);
   fChain->SetBranchAddress("met_trkPt", &met_trkPt, &b_met_trkPt);
   fChain->SetBranchAddress("met_trkPhi", &met_trkPhi, &b_met_trkPhi);
   fChain->SetBranchAddress("met_genPt", &met_genPt, &b_met_genPt);
   fChain->SetBranchAddress("met_genPhi", &met_genPhi, &b_met_genPhi);
   fChain->SetBranchAddress("Flag_EcalDeadCellTriggerPrimitiveFilter", &Flag_EcalDeadCellTriggerPrimitiveFilter, &b_Flag_EcalDeadCellTriggerPrimitiveFilter);
   fChain->SetBranchAddress("Flag_trkPOG_manystripclus53X", &Flag_trkPOG_manystripclus53X, &b_Flag_trkPOG_manystripclus53X);
   fChain->SetBranchAddress("Flag_ecalLaserCorrFilter", &Flag_ecalLaserCorrFilter, &b_Flag_ecalLaserCorrFilter);
   fChain->SetBranchAddress("Flag_trkPOG_toomanystripclus53X", &Flag_trkPOG_toomanystripclus53X, &b_Flag_trkPOG_toomanystripclus53X);
   fChain->SetBranchAddress("Flag_hcalLaserEventFilter", &Flag_hcalLaserEventFilter, &b_Flag_hcalLaserEventFilter);
   fChain->SetBranchAddress("Flag_trkPOG_logErrorTooManyClusters", &Flag_trkPOG_logErrorTooManyClusters, &b_Flag_trkPOG_logErrorTooManyClusters);
   fChain->SetBranchAddress("Flag_trkPOGFilters", &Flag_trkPOGFilters, &b_Flag_trkPOGFilters);
   fChain->SetBranchAddress("Flag_trackingFailureFilter", &Flag_trackingFailureFilter, &b_Flag_trackingFailureFilter);
   fChain->SetBranchAddress("Flag_CSCTightHaloFilter", &Flag_CSCTightHaloFilter, &b_Flag_CSCTightHaloFilter);
   fChain->SetBranchAddress("Flag_HBHENoiseFilter", &Flag_HBHENoiseFilter, &b_Flag_HBHENoiseFilter);
   fChain->SetBranchAddress("Flag_HBHEIsoNoiseFilter", &Flag_HBHEIsoNoiseFilter, &b_Flag_HBHEIsoNoiseFilter);
   fChain->SetBranchAddress("Flag_goodVertices", &Flag_goodVertices, &b_Flag_goodVertices);
   fChain->SetBranchAddress("Flag_eeBadScFilter", &Flag_eeBadScFilter, &b_Flag_eeBadScFilter);
   fChain->SetBranchAddress("Flag_METFilters", &Flag_METFilters, &b_Flag_METFilters);
   fChain->SetBranchAddress("HLT_PFHT800", &HLT_PFHT800, &b_HLT_PFHT800);
   fChain->SetBranchAddress("HLT_PFHT900", &HLT_PFHT900, &b_HLT_PFHT900);
   fChain->SetBranchAddress("HLT_PFMET170", &HLT_PFMET170, &b_HLT_PFMET170);
   fChain->SetBranchAddress("HLT_PFHT350_PFMET100", &HLT_PFHT350_PFMET100, &b_HLT_PFHT350_PFMET100);
   fChain->SetBranchAddress("HLT_PFHT350_PFMET120", &HLT_PFHT350_PFMET120, &b_HLT_PFHT350_PFMET120);
   fChain->SetBranchAddress("HLT_PFMETNoMu90_PFMHTNoMu90", &HLT_PFMETNoMu90_PFMHTNoMu90, &b_HLT_PFMETNoMu90_PFMHTNoMu90);
   fChain->SetBranchAddress("HLT_MonoCentralPFJet80_PFMETNoMu90_PFMHTNoMu90", &HLT_MonoCentralPFJet80_PFMETNoMu90_PFMHTNoMu90, &b_HLT_MonoCentralPFJet80_PFMETNoMu90_PFMHTNoMu90);
   fChain->SetBranchAddress("HLT_PFMETNoMu120_PFMHTNoMu120", &HLT_PFMETNoMu120_PFMHTNoMu120, &b_HLT_PFMETNoMu120_PFMHTNoMu120);
   fChain->SetBranchAddress("HLT_PFMET90_PFMHT90", &HLT_PFMET90_PFMHT90, &b_HLT_PFMET90_PFMHT90);
   fChain->SetBranchAddress("HLT_SingleMu", &HLT_SingleMu, &b_HLT_SingleMu);
   fChain->SetBranchAddress("HLT_SingleEl", &HLT_SingleEl, &b_HLT_SingleEl);
   fChain->SetBranchAddress("HLT_DoubleEl", &HLT_DoubleEl, &b_HLT_DoubleEl);
   fChain->SetBranchAddress("HLT_DoubleEl33", &HLT_DoubleEl33, &b_HLT_DoubleEl33);
   fChain->SetBranchAddress("HLT_MuX_Ele12", &HLT_MuX_Ele12, &b_HLT_MuX_Ele12);
   fChain->SetBranchAddress("HLT_Mu8_EleX", &HLT_Mu8_EleX, &b_HLT_Mu8_EleX);
   fChain->SetBranchAddress("HLT_DoubleMu", &HLT_DoubleMu, &b_HLT_DoubleMu);
   fChain->SetBranchAddress("HLT_Photon120", &HLT_Photon120, &b_HLT_Photon120);
   fChain->SetBranchAddress("HLT_Photon165_HE10", &HLT_Photon165_HE10, &b_HLT_Photon165_HE10);
   fChain->SetBranchAddress("HLT_PFHT200_Prescale", &HLT_PFHT200_Prescale, &b_HLT_PFHT200_Prescale);
   fChain->SetBranchAddress("HLT_PFHT300_Prescale", &HLT_PFHT300_Prescale, &b_HLT_PFHT300_Prescale);
   fChain->SetBranchAddress("HLT_PFHT350_Prescale", &HLT_PFHT350_Prescale, &b_HLT_PFHT350_Prescale);
   fChain->SetBranchAddress("HLT_PFHT475_Prescale", &HLT_PFHT475_Prescale, &b_HLT_PFHT475_Prescale);
   fChain->SetBranchAddress("HLT_PFHT600_Prescale", &HLT_PFHT600_Prescale, &b_HLT_PFHT600_Prescale);
   fChain->SetBranchAddress("HLT_DiCentralPFJet70_PFMET120", &HLT_DiCentralPFJet70_PFMET120, &b_HLT_DiCentralPFJet70_PFMET120);
   fChain->SetBranchAddress("HLT_DiCentralPFJet55_PFMET110", &HLT_DiCentralPFJet55_PFMET110, &b_HLT_DiCentralPFJet55_PFMET110);
   fChain->SetBranchAddress("nlep", &nlep, &b_nlep);
   fChain->SetBranchAddress("nlepIso", &nlepIso, &b_nlepIso);
   fChain->SetBranchAddress("nlepIso20", &nlepIso20, &b_nlepIso20);
   fChain->SetBranchAddress("lep_pt", lep_pt, &b_lep_pt);
   fChain->SetBranchAddress("lep_eta", lep_eta, &b_lep_eta);
   fChain->SetBranchAddress("lep_phi", lep_phi, &b_lep_phi);
   fChain->SetBranchAddress("lep_mass", lep_mass, &b_lep_mass);
   fChain->SetBranchAddress("lep_charge", lep_charge, &b_lep_charge);
   fChain->SetBranchAddress("lep_pdgId", lep_pdgId, &b_lep_pdgId);
   fChain->SetBranchAddress("lep_dxy", lep_dxy, &b_lep_dxy);
   fChain->SetBranchAddress("lep_dz", lep_dz, &b_lep_dz);
   fChain->SetBranchAddress("lep_tightId", lep_tightId, &b_lep_tightId);
   fChain->SetBranchAddress("lep_heepId", lep_heepId, &b_lep_heepId);
   fChain->SetBranchAddress("lep_relIso03", lep_relIso03, &b_lep_relIso03);
   fChain->SetBranchAddress("lep_relIso04", lep_relIso04, &b_lep_relIso04);
   fChain->SetBranchAddress("lep_miniRelIso", lep_miniRelIso, &b_lep_miniRelIso);
   fChain->SetBranchAddress("lep_relIsoAn04", lep_relIsoAn04, &b_lep_relIsoAn04);
   fChain->SetBranchAddress("lep_mcMatchId", lep_mcMatchId, &b_lep_mcMatchId);
   fChain->SetBranchAddress("lep_lostHits", lep_lostHits, &b_lep_lostHits);
   fChain->SetBranchAddress("lep_convVeto", lep_convVeto, &b_lep_convVeto);
   fChain->SetBranchAddress("lep_tightCharge", lep_tightCharge, &b_lep_tightCharge);
   fChain->SetBranchAddress("lep_mva", lep_mva, &b_lep_mva);
   fChain->SetBranchAddress("lep_ptRatio", lep_ptRatio, &b_lep_ptRatio);
   fChain->SetBranchAddress("lep_ptRel", lep_ptRel, &b_lep_ptRel);
   fChain->SetBranchAddress("lep_tightIdNoIso", lep_tightIdNoIso, &b_lep_tightIdNoIso);
   fChain->SetBranchAddress("lep_sip3d", lep_sip3d, &b_lep_sip3d);
   fChain->SetBranchAddress("nisoTrack", &nisoTrack, &b_nisoTrack);
   fChain->SetBranchAddress("isoTrack_pt", isoTrack_pt, &b_isoTrack_pt);
   fChain->SetBranchAddress("isoTrack_eta", isoTrack_eta, &b_isoTrack_eta);
   fChain->SetBranchAddress("isoTrack_phi", isoTrack_phi, &b_isoTrack_phi);
   fChain->SetBranchAddress("isoTrack_mass", isoTrack_mass, &b_isoTrack_mass);
   fChain->SetBranchAddress("isoTrack_absIso", isoTrack_absIso, &b_isoTrack_absIso);
   fChain->SetBranchAddress("isoTrack_relIsoAn04", isoTrack_relIsoAn04, &b_isoTrack_relIsoAn04);
   fChain->SetBranchAddress("isoTrack_dz", isoTrack_dz, &b_isoTrack_dz);
   fChain->SetBranchAddress("isoTrack_pdgId", isoTrack_pdgId, &b_isoTrack_pdgId);
   fChain->SetBranchAddress("isoTrack_mcMatchId", isoTrack_mcMatchId, &b_isoTrack_mcMatchId);
   fChain->SetBranchAddress("nPFLep5LowMT", &nPFLep5LowMT, &b_nPFLep5LowMT);
   fChain->SetBranchAddress("nPFHad10LowMT", &nPFHad10LowMT, &b_nPFHad10LowMT);
   fChain->SetBranchAddress("nPFHad10", &nPFHad10, &b_nPFHad10);
   fChain->SetBranchAddress("ntau", &ntau, &b_ntau);
   fChain->SetBranchAddress("tau_pt", tau_pt, &b_tau_pt);
   fChain->SetBranchAddress("tau_eta", tau_eta, &b_tau_eta);
   fChain->SetBranchAddress("tau_phi", tau_phi, &b_tau_phi);
   fChain->SetBranchAddress("tau_mass", tau_mass, &b_tau_mass);
   fChain->SetBranchAddress("tau_charge", tau_charge, &b_tau_charge);
   fChain->SetBranchAddress("tau_dxy", tau_dxy, &b_tau_dxy);
   fChain->SetBranchAddress("tau_dz", tau_dz, &b_tau_dz);
   fChain->SetBranchAddress("tau_idCI3hit", tau_idCI3hit, &b_tau_idCI3hit);
   fChain->SetBranchAddress("tau_isoCI3hit", tau_isoCI3hit, &b_tau_isoCI3hit);
   fChain->SetBranchAddress("tau_mcMatchId", tau_mcMatchId, &b_tau_mcMatchId);
   fChain->SetBranchAddress("ngamma", &ngamma, &b_ngamma);
   fChain->SetBranchAddress("gamma_pt", gamma_pt, &b_gamma_pt);
   fChain->SetBranchAddress("gamma_eta", gamma_eta, &b_gamma_eta);
   fChain->SetBranchAddress("gamma_phi", gamma_phi, &b_gamma_phi);
   fChain->SetBranchAddress("gamma_mass", gamma_mass, &b_gamma_mass);
   fChain->SetBranchAddress("gamma_mcMatchId", gamma_mcMatchId, &b_gamma_mcMatchId);
   fChain->SetBranchAddress("gamma_genIso04", gamma_genIso04, &b_gamma_genIso04);
   fChain->SetBranchAddress("gamma_drMinParton", gamma_drMinParton, &b_gamma_drMinParton);
   fChain->SetBranchAddress("gamma_chHadIso", gamma_chHadIso, &b_gamma_chHadIso);
   fChain->SetBranchAddress("gamma_neuHadIso", gamma_neuHadIso, &b_gamma_neuHadIso);
   fChain->SetBranchAddress("gamma_phIso", gamma_phIso, &b_gamma_phIso);
   fChain->SetBranchAddress("gamma_sigmaIetaIeta", gamma_sigmaIetaIeta, &b_gamma_sigmaIetaIeta);
   fChain->SetBranchAddress("gamma_r9", gamma_r9, &b_gamma_r9);
   fChain->SetBranchAddress("gamma_hOverE", gamma_hOverE, &b_gamma_hOverE);
   fChain->SetBranchAddress("gamma_idCutBased", gamma_idCutBased, &b_gamma_idCutBased);
   fChain->SetBranchAddress("sl_mt2", &sl_mt2, &b_sl_mt2);
   fChain->SetBranchAddress("gamma_mt2", &gamma_mt2, &b_gamma_mt2);
   fChain->SetBranchAddress("gamma_nJet30", &gamma_nJet30, &b_gamma_nJet30);
   fChain->SetBranchAddress("gamma_nJet40", &gamma_nJet40, &b_gamma_nJet40);
   fChain->SetBranchAddress("gamma_nJet30FailId", &gamma_nJet30FailId, &b_gamma_nJet30FailId);
   fChain->SetBranchAddress("gamma_nJet100FailId", &gamma_nJet100FailId, &b_gamma_nJet100FailId);
   fChain->SetBranchAddress("gamma_nBJet20", &gamma_nBJet20, &b_gamma_nBJet20);
   fChain->SetBranchAddress("gamma_nBJet25", &gamma_nBJet25, &b_gamma_nBJet25);
   fChain->SetBranchAddress("gamma_nBJet30", &gamma_nBJet30, &b_gamma_nBJet30);
   fChain->SetBranchAddress("gamma_nBJet40", &gamma_nBJet40, &b_gamma_nBJet40);
   fChain->SetBranchAddress("gamma_ht", &gamma_ht, &b_gamma_ht);
   fChain->SetBranchAddress("gamma_deltaPhiMin", &gamma_deltaPhiMin, &b_gamma_deltaPhiMin);
   fChain->SetBranchAddress("gamma_diffMetMht", &gamma_diffMetMht, &b_gamma_diffMetMht);
   fChain->SetBranchAddress("gamma_mht_pt", &gamma_mht_pt, &b_gamma_mht_pt);
   fChain->SetBranchAddress("gamma_mht_phi", &gamma_mht_phi, &b_gamma_mht_phi);
   fChain->SetBranchAddress("gamma_met_pt", &gamma_met_pt, &b_gamma_met_pt);
   fChain->SetBranchAddress("gamma_met_phi", &gamma_met_phi, &b_gamma_met_phi);
   fChain->SetBranchAddress("zll_mt2", &zll_mt2, &b_zll_mt2);
   fChain->SetBranchAddress("zll_deltaPhiMin", &zll_deltaPhiMin, &b_zll_deltaPhiMin);
   fChain->SetBranchAddress("zll_diffMetMht", &zll_diffMetMht, &b_zll_diffMetMht);
   fChain->SetBranchAddress("zll_met_pt", &zll_met_pt, &b_zll_met_pt);
   fChain->SetBranchAddress("zll_met_phi", &zll_met_phi, &b_zll_met_phi);
   fChain->SetBranchAddress("zll_mht_pt", &zll_mht_pt, &b_zll_mht_pt);
   fChain->SetBranchAddress("zll_mht_phi", &zll_mht_phi, &b_zll_mht_phi);
   fChain->SetBranchAddress("zll_mass", &zll_mass, &b_zll_mass);
   fChain->SetBranchAddress("zll_pt", &zll_pt, &b_zll_pt);
   fChain->SetBranchAddress("zll_eta", &zll_eta, &b_zll_eta);
   fChain->SetBranchAddress("zll_phi", &zll_phi, &b_zll_phi);
   fChain->SetBranchAddress("zll_ht", &zll_ht, &b_zll_ht);
   fChain->SetBranchAddress("zllmt_mt2", &zllmt_mt2, &b_zllmt_mt2);
   fChain->SetBranchAddress("zllmt_deltaPhiMin", &zllmt_deltaPhiMin, &b_zllmt_deltaPhiMin);
   fChain->SetBranchAddress("zllmt_diffMetMht", &zllmt_diffMetMht, &b_zllmt_diffMetMht);
   fChain->SetBranchAddress("zllmt_met_pt", &zllmt_met_pt, &b_zllmt_met_pt);
   fChain->SetBranchAddress("zllmt_met_phi", &zllmt_met_phi, &b_zllmt_met_phi);
   fChain->SetBranchAddress("zllmt_mht_pt", &zllmt_mht_pt, &b_zllmt_mht_pt);
   fChain->SetBranchAddress("zllmt_mht_phi", &zllmt_mht_phi, &b_zllmt_mht_phi);
   fChain->SetBranchAddress("zllmt_ht", &zllmt_ht, &b_zllmt_ht);
   fChain->SetBranchAddress("zllmt_mt", &zllmt_mt, &b_zllmt_mt);
   fChain->SetBranchAddress("rl_mt2", &rl_mt2, &b_rl_mt2);
   fChain->SetBranchAddress("rl_deltaPhiMin", &rl_deltaPhiMin, &b_rl_deltaPhiMin);
   fChain->SetBranchAddress("rl_diffMetMht", &rl_diffMetMht, &b_rl_diffMetMht);
   fChain->SetBranchAddress("rl_met_pt", &rl_met_pt, &b_rl_met_pt);
   fChain->SetBranchAddress("rl_met_phi", &rl_met_phi, &b_rl_met_phi);
   fChain->SetBranchAddress("rl_mht_pt", &rl_mht_pt, &b_rl_mht_pt);
   fChain->SetBranchAddress("rl_mht_phi", &rl_mht_phi, &b_rl_mht_phi);
   fChain->SetBranchAddress("rl_mass", &rl_mass, &b_rl_mass);
   fChain->SetBranchAddress("rl_pt", &rl_pt, &b_rl_pt);
   fChain->SetBranchAddress("rl_eta", &rl_eta, &b_rl_eta);
   fChain->SetBranchAddress("rl_phi", &rl_phi, &b_rl_phi);
   fChain->SetBranchAddress("rl_ht", &rl_ht, &b_rl_ht);
   fChain->SetBranchAddress("ngenLep", &ngenLep, &b_ngenLep);
   fChain->SetBranchAddress("genLep_pt", genLep_pt, &b_genLep_pt);
   fChain->SetBranchAddress("genLep_eta", genLep_eta, &b_genLep_eta);
   fChain->SetBranchAddress("genLep_phi", genLep_phi, &b_genLep_phi);
   fChain->SetBranchAddress("genLep_mass", genLep_mass, &b_genLep_mass);
   fChain->SetBranchAddress("genLep_pdgId", genLep_pdgId, &b_genLep_pdgId);
   fChain->SetBranchAddress("genLep_status", genLep_status, &b_genLep_status);
   fChain->SetBranchAddress("genLep_charge", genLep_charge, &b_genLep_charge);
   fChain->SetBranchAddress("genLep_sourceId", genLep_sourceId, &b_genLep_sourceId);
   fChain->SetBranchAddress("ngenStat23", &ngenStat23, &b_ngenStat23);
   fChain->SetBranchAddress("genStat23_pt", genStat23_pt, &b_genStat23_pt);
   fChain->SetBranchAddress("genStat23_eta", genStat23_eta, &b_genStat23_eta);
   fChain->SetBranchAddress("genStat23_phi", genStat23_phi, &b_genStat23_phi);
   fChain->SetBranchAddress("genStat23_mass", genStat23_mass, &b_genStat23_mass);
   fChain->SetBranchAddress("genStat23_pdgId", genStat23_pdgId, &b_genStat23_pdgId);
   fChain->SetBranchAddress("genStat23_status", genStat23_status, &b_genStat23_status);
   fChain->SetBranchAddress("genStat23_charge", genStat23_charge, &b_genStat23_charge);
   fChain->SetBranchAddress("genStat23_sourceId", genStat23_sourceId, &b_genStat23_sourceId);
   fChain->SetBranchAddress("ngenGamma", &ngenGamma, &b_ngenGamma);
   fChain->SetBranchAddress("genGamma_pt", genGamma_pt, &b_genGamma_pt);
   fChain->SetBranchAddress("genGamma_eta", genGamma_eta, &b_genGamma_eta);
   fChain->SetBranchAddress("genGamma_phi", genGamma_phi, &b_genGamma_phi);
   fChain->SetBranchAddress("genGamma_motherId", genGamma_motherId, &b_genGamma_motherId);
   fChain->SetBranchAddress("ngenTau", &ngenTau, &b_ngenTau);
   fChain->SetBranchAddress("ngenTau1Prong", &ngenTau1Prong, &b_ngenTau1Prong);
   fChain->SetBranchAddress("ngenTau3Prong", &ngenTau3Prong, &b_ngenTau3Prong);
   fChain->SetBranchAddress("genTau_pt", genTau_pt, &b_genTau_pt);
   fChain->SetBranchAddress("genTau_eta", genTau_eta, &b_genTau_eta);
   fChain->SetBranchAddress("genTau_phi", genTau_phi, &b_genTau_phi);
   fChain->SetBranchAddress("genTau_mass", genTau_mass, &b_genTau_mass);
   fChain->SetBranchAddress("genTau_pdgId", genTau_pdgId, &b_genTau_pdgId);
   fChain->SetBranchAddress("genTau_status", genTau_status, &b_genTau_status);
   fChain->SetBranchAddress("genTau_charge", genTau_charge, &b_genTau_charge);
   fChain->SetBranchAddress("genTau_sourceId", genTau_sourceId, &b_genTau_sourceId);
   fChain->SetBranchAddress("genTau_decayMode", genTau_decayMode, &b_genTau_decayMode);
   fChain->SetBranchAddress("genTau_leadTrackPt", genTau_leadTrackPt, &b_genTau_leadTrackPt);
   fChain->SetBranchAddress("genTau_neutralDaughters", genTau_neutralDaughters, &b_genTau_neutralDaughters);
   fChain->SetBranchAddress("ngenLepFromTau", &ngenLepFromTau, &b_ngenLepFromTau);
   fChain->SetBranchAddress("genLepFromTau_pt", genLepFromTau_pt, &b_genLepFromTau_pt);
   fChain->SetBranchAddress("genLepFromTau_eta", genLepFromTau_eta, &b_genLepFromTau_eta);
   fChain->SetBranchAddress("genLepFromTau_phi", genLepFromTau_phi, &b_genLepFromTau_phi);
   fChain->SetBranchAddress("genLepFromTau_mass", genLepFromTau_mass, &b_genLepFromTau_mass);
   fChain->SetBranchAddress("genLepFromTau_pdgId", genLepFromTau_pdgId, &b_genLepFromTau_pdgId);
   fChain->SetBranchAddress("genLepFromTau_status", genLepFromTau_status, &b_genLepFromTau_status);
   fChain->SetBranchAddress("genLepFromTau_charge", genLepFromTau_charge, &b_genLepFromTau_charge);
   fChain->SetBranchAddress("genLepFromTau_sourceId", genLepFromTau_sourceId, &b_genLepFromTau_sourceId);
   fChain->SetBranchAddress("GenSusyMScan1", &GenSusyMScan1, &b_GenSusyMScan1);
   fChain->SetBranchAddress("GenSusyMScan2", &GenSusyMScan2, &b_GenSusyMScan2);
   fChain->SetBranchAddress("GenSusyMScan3", &GenSusyMScan3, &b_GenSusyMScan3);
   fChain->SetBranchAddress("GenSusyMScan4", &GenSusyMScan4, &b_GenSusyMScan4);
   fChain->SetBranchAddress("nLHEweight", &nLHEweight, &b_nLHEweight);
   fChain->SetBranchAddress("LHEweight_wgt", LHEweight_wgt, &b_LHEweight_wgt);
   fChain->SetBranchAddress("njet", &njet, &b_njet);
   fChain->SetBranchAddress("jet_pt", jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("jet_eta", jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_phi", jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_mass", jet_mass, &b_jet_mass);
   fChain->SetBranchAddress("jet_btagCSV", jet_btagCSV, &b_jet_btagCSV);
   fChain->SetBranchAddress("jet_rawPt", jet_rawPt, &b_jet_rawPt);
   fChain->SetBranchAddress("jet_mcPt", jet_mcPt, &b_jet_mcPt);
   fChain->SetBranchAddress("jet_chf", jet_chf, &b_jet_chf);
   fChain->SetBranchAddress("jet_FSveto", jet_FSveto, &b_jet_FSveto);
   fChain->SetBranchAddress("jet_mcFlavour", jet_mcFlavour, &b_jet_mcFlavour);
   fChain->SetBranchAddress("jet_hadronFlavour", jet_hadronFlavour, &b_jet_hadronFlavour);
   fChain->SetBranchAddress("jet_qgl", jet_qgl, &b_jet_qgl);
   fChain->SetBranchAddress("jet_area", jet_area, &b_jet_area);
   fChain->SetBranchAddress("jet_id", jet_id, &b_jet_id);
   fChain->SetBranchAddress("jet_puId", jet_puId, &b_jet_puId);
   fChain->SetBranchAddress("weight_lepsf", &weight_lepsf, &b_weight_lepsf);
   fChain->SetBranchAddress("weight_lepsf_UP", &weight_lepsf_UP, &b_weight_lepsf_UP);
   fChain->SetBranchAddress("weight_lepsf_DN", &weight_lepsf_DN, &b_weight_lepsf_DN);
   fChain->SetBranchAddress("weight_btagsf", &weight_btagsf, &b_weight_btagsf);
   fChain->SetBranchAddress("weight_btagsf_heavy_UP", &weight_btagsf_heavy_UP, &b_weight_btagsf_heavy_UP);
   fChain->SetBranchAddress("weight_btagsf_light_UP", &weight_btagsf_light_UP, &b_weight_btagsf_light_UP);
   fChain->SetBranchAddress("weight_btagsf_heavy_DN", &weight_btagsf_heavy_DN, &b_weight_btagsf_heavy_DN);
   fChain->SetBranchAddress("weight_btagsf_light_DN", &weight_btagsf_light_DN, &b_weight_btagsf_light_DN);
   fChain->SetBranchAddress("weight_sigtrigsf", &weight_sigtrigsf, &b_weight_sigtrigsf);
   fChain->SetBranchAddress("weight_dileptrigsf", &weight_dileptrigsf, &b_weight_dileptrigsf);
   fChain->SetBranchAddress("weight_phottrigsf", &weight_phottrigsf, &b_weight_phottrigsf);
   fChain->SetBranchAddress("weight_pu", &weight_pu, &b_weight_pu);
   fChain->SetBranchAddress("weight_isr", &weight_isr, &b_weight_isr);
   fChain->SetBranchAddress("weight_scales_UP", &weight_scales_UP, &b_weight_scales_UP);
   fChain->SetBranchAddress("weight_scales_DN", &weight_scales_DN, &b_weight_scales_DN);
   fChain->SetBranchAddress("weight_pdfs_UP", &weight_pdfs_UP, &b_weight_pdfs_UP);
   fChain->SetBranchAddress("weight_pdfs_DN", &weight_pdfs_DN, &b_weight_pdfs_DN);
   fChain->SetBranchAddress("weight_toppt", &weight_toppt, &b_weight_toppt);
   fChain->SetBranchAddress("genRecoil_pt", &genRecoil_pt, &b_genRecoil_pt);
   fChain->SetBranchAddress("genTop_pt", &genTop_pt, &b_genTop_pt);
   fChain->SetBranchAddress("genTbar_pt", &genTbar_pt, &b_genTbar_pt);
   Notify();
}

Bool_t MT2TreeSig::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void MT2TreeSig::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t MT2TreeSig::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

void MT2TreeSig::Loop()
{
//   In a ROOT session, you can do:
//      root> .L MT2TreeSig.C
//      root> MT2TreeSig t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }
}
