#include "MT2Tree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

MT2Tree::MT2Tree(TTree *tree) : fChain(0) 
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

MT2Tree::~MT2Tree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t MT2Tree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t MT2Tree::LoadTree(Long64_t entry)
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

void MT2Tree::Init(TTree *tree)
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

   fChain ->SetBranchStatus("*",0);
   fChain ->SetBranchStatus("run"                                            , 0); fChain ->SetBranchAddress("run"                                            , &run                                            , &b_run);
   fChain ->SetBranchStatus("lumi"                                           , 0); fChain ->SetBranchAddress("lumi"                                           , &lumi                                           , &b_lumi);
   fChain ->SetBranchStatus("evt"                                            , 0); fChain ->SetBranchAddress("evt"                                            , &evt                                            , &b_evt);
   fChain ->SetBranchStatus("isData"                                         , 0); fChain ->SetBranchAddress("isData"                                         , &isData                                         , &b_isData);
   fChain ->SetBranchStatus("evt_scale1fb"                                   , 1); fChain ->SetBranchAddress("evt_scale1fb"                                   , &evt_scale1fb                                   , &b_evt_scale1fb);
   fChain ->SetBranchStatus("evt_xsec"                                       , 0); fChain ->SetBranchAddress("evt_xsec"                                       , &evt_xsec                                       , &b_evt_xsec);
   fChain ->SetBranchStatus("evt_kfactor"                                    , 0); fChain ->SetBranchAddress("evt_kfactor"                                    , &evt_kfactor                                    , &b_evt_kfactor);
   fChain ->SetBranchStatus("evt_filter"                                     , 0); fChain ->SetBranchAddress("evt_filter"                                     , &evt_filter                                     , &b_evt_filter);
   fChain ->SetBranchStatus("evt_nEvts"                                      , 0); fChain ->SetBranchAddress("evt_nEvts"                                      , &evt_nEvts                                      , &b_evt_nEvts);
   fChain ->SetBranchStatus("evt_id"                                         , 0); fChain ->SetBranchAddress("evt_id"                                         , &evt_id                                         , &b_evt_id);
   fChain ->SetBranchStatus("genWeight"                                      , 0); fChain ->SetBranchAddress("genWeight"                                      , &genWeight                                      , &b_genWeight);
   fChain ->SetBranchStatus("puWeight"                                       , 0); fChain ->SetBranchAddress("puWeight"                                       , &puWeight                                       , &b_puWeight);
   fChain ->SetBranchStatus("nVert"                                          , 0); fChain ->SetBranchAddress("nVert"                                          , &nVert                                          , &b_nVert);
   fChain ->SetBranchStatus("nTrueInt"                                       , 0); fChain ->SetBranchAddress("nTrueInt"                                       , &nTrueInt                                       , &b_nTrueInt);
   fChain ->SetBranchStatus("rho"                                            , 0); fChain ->SetBranchAddress("rho"                                            , &rho                                            , &b_rho);
   fChain ->SetBranchStatus("nJet30"                                         , 0); fChain ->SetBranchAddress("nJet30"                                         , &nJet30                                         , &b_nJet30);
   fChain ->SetBranchStatus("nJet30JECup"                                    , 0); fChain ->SetBranchAddress("nJet30JECup"                                    , &nJet30JECup                                    , &b_nJet30JECup);
   fChain ->SetBranchStatus("nJet30JECdn"                                    , 0); fChain ->SetBranchAddress("nJet30JECdn"                                    , &nJet30JECdn                                    , &b_nJet30JECdn);
   fChain ->SetBranchStatus("nJet40"                                         , 0); fChain ->SetBranchAddress("nJet40"                                         , &nJet40                                         , &b_nJet40);
   fChain ->SetBranchStatus("nBJet20"                                        , 0); fChain ->SetBranchAddress("nBJet20"                                        , &nBJet20                                        , &b_nBJet20);
   fChain ->SetBranchStatus("nBJet20JECup"                                   , 0); fChain ->SetBranchAddress("nBJet20JECup"                                   , &nBJet20JECup                                   , &b_nBJet20JECup);
   fChain ->SetBranchStatus("nBJet20JECdn"                                   , 0); fChain ->SetBranchAddress("nBJet20JECdn"                                   , &nBJet20JECdn                                   , &b_nBJet20JECdn);
   fChain ->SetBranchStatus("nBJet25"                                        , 1); fChain ->SetBranchAddress("nBJet25"                                        , &nBJet25                                        , &b_nBJet25);
   fChain ->SetBranchStatus("nBJet30"                                        , 0); fChain ->SetBranchAddress("nBJet30"                                        , &nBJet30                                        , &b_nBJet30);
   fChain ->SetBranchStatus("nBJet40"                                        , 0); fChain ->SetBranchAddress("nBJet40"                                        , &nBJet40                                        , &b_nBJet40);
   fChain ->SetBranchStatus("nJet30FailId"                                   , 0); fChain ->SetBranchAddress("nJet30FailId"                                   , &nJet30FailId                                   , &b_nJet30FailId);
   fChain ->SetBranchStatus("nJet100FailId"                                  , 0); fChain ->SetBranchAddress("nJet100FailId"                                  , &nJet100FailId                                  , &b_nJet100FailId);
   fChain ->SetBranchStatus("nMuons10"                                       , 0); fChain ->SetBranchAddress("nMuons10"                                       , &nMuons10                                       , &b_nMuons10);
   fChain ->SetBranchStatus("nElectrons10"                                   , 0); fChain ->SetBranchAddress("nElectrons10"                                   , &nElectrons10                                   , &b_nElectrons10);
   fChain ->SetBranchStatus("nLepLowMT"                                      , 0); fChain ->SetBranchAddress("nLepLowMT"                                      , &nLepLowMT                                      , &b_nLepLowMT);
   fChain ->SetBranchStatus("nTaus20"                                        , 0); fChain ->SetBranchAddress("nTaus20"                                        , &nTaus20                                        , &b_nTaus20);
   fChain ->SetBranchStatus("nGammas20"                                      , 0); fChain ->SetBranchAddress("nGammas20"                                      , &nGammas20                                      , &b_nGammas20);
   fChain ->SetBranchStatus("nPFCHCand3"                                     , 0); fChain ->SetBranchAddress("nPFCHCand3"                                     , &nPFCHCand3                                     , &b_nPFCHCand3);
   fChain ->SetBranchStatus("deltaPhiMin"                                    , 0); fChain ->SetBranchAddress("deltaPhiMin"                                    , &deltaPhiMin                                    , &b_deltaPhiMin);
   fChain ->SetBranchStatus("deltaPhiMinJECup"                               , 0); fChain ->SetBranchAddress("deltaPhiMinJECup"                               , &deltaPhiMinJECup                               , &b_deltaPhiMinJECup);
   fChain ->SetBranchStatus("deltaPhiMinJECdn"                               , 0); fChain ->SetBranchAddress("deltaPhiMinJECdn"                               , &deltaPhiMinJECdn                               , &b_deltaPhiMinJECdn);
   fChain ->SetBranchStatus("diffMetMht"                                     , 0); fChain ->SetBranchAddress("diffMetMht"                                     , &diffMetMht                                     , &b_diffMetMht);
   fChain ->SetBranchStatus("diffMetMhtJECup"                                , 0); fChain ->SetBranchAddress("diffMetMhtJECup"                                , &diffMetMhtJECup                                , &b_diffMetMhtJECup);
   fChain ->SetBranchStatus("diffMetMhtJECdn"                                , 0); fChain ->SetBranchAddress("diffMetMhtJECdn"                                , &diffMetMhtJECdn                                , &b_diffMetMhtJECdn);
   fChain ->SetBranchStatus("minMTBMet"                                      , 0); fChain ->SetBranchAddress("minMTBMet"                                      , &minMTBMet                                      , &b_minMTBMet);
   fChain ->SetBranchStatus("zll_minMTBMet"                                  , 0); fChain ->SetBranchAddress("zll_minMTBMet"                                  , &zll_minMTBMet                                  , &b_zll_minMTBMet);
   fChain ->SetBranchStatus("gamma_minMTBMet"                                , 0); fChain ->SetBranchAddress("gamma_minMTBMet"                                , &gamma_minMTBMet                                , &b_gamma_minMTBMet);
   fChain ->SetBranchStatus("ht"                                             , 1); fChain ->SetBranchAddress("ht"                                             , &ht                                             , &b_ht);
   fChain ->SetBranchStatus("htJECup"                                        , 0); fChain ->SetBranchAddress("htJECup"                                        , &htJECup                                        , &b_htJECup);
   fChain ->SetBranchStatus("htJECdn"                                        , 0); fChain ->SetBranchAddress("htJECdn"                                        , &htJECdn                                        , &b_htJECdn);
   fChain ->SetBranchStatus("mt2"                                            , 0); fChain ->SetBranchAddress("mt2"                                            , &mt2                                            , &b_mt2);
   fChain ->SetBranchStatus("mt2JECup"                                       , 0); fChain ->SetBranchAddress("mt2JECup"                                       , &mt2JECup                                       , &b_mt2JECup);
   fChain ->SetBranchStatus("mt2JECdn"                                       , 0); fChain ->SetBranchAddress("mt2JECdn"                                       , &mt2JECdn                                       , &b_mt2JECdn);
   fChain ->SetBranchStatus("mt2_gen"                                        , 0); fChain ->SetBranchAddress("mt2_gen"                                        , &mt2_gen                                        , &b_mt2_gen);
   fChain ->SetBranchStatus("jet1_pt"                                        , 0); fChain ->SetBranchAddress("jet1_pt"                                        , &jet1_pt                                        , &b_jet1_pt);
   fChain ->SetBranchStatus("jet2_pt"                                        , 0); fChain ->SetBranchAddress("jet2_pt"                                        , &jet2_pt                                        , &b_jet2_pt);
   fChain ->SetBranchStatus("jet1_ptJECup"                                   , 0); fChain ->SetBranchAddress("jet1_ptJECup"                                   , &jet1_ptJECup                                   , &b_jet1_ptJECup);
   fChain ->SetBranchStatus("jet2_ptJECup"                                   , 0); fChain ->SetBranchAddress("jet2_ptJECup"                                   , &jet2_ptJECup                                   , &b_jet2_ptJECup);
   fChain ->SetBranchStatus("jet1_ptJECdn"                                   , 0); fChain ->SetBranchAddress("jet1_ptJECdn"                                   , &jet1_ptJECdn                                   , &b_jet1_ptJECdn);
   fChain ->SetBranchStatus("jet2_ptJECdn"                                   , 0); fChain ->SetBranchAddress("jet2_ptJECdn"                                   , &jet2_ptJECdn                                   , &b_jet2_ptJECdn);
   fChain ->SetBranchStatus("jet_failFSveto"                                 , 0); fChain ->SetBranchAddress("jet_failFSveto"                                 , &jet_failFSveto                                 , &b_jet_failFSveto);
   fChain ->SetBranchStatus("gamma_jet1_pt"                                  , 0); fChain ->SetBranchAddress("gamma_jet1_pt"                                  , &gamma_jet1_pt                                  , &b_gamma_jet1_pt);
   fChain ->SetBranchStatus("gamma_jet2_pt"                                  , 0); fChain ->SetBranchAddress("gamma_jet2_pt"                                  , &gamma_jet2_pt                                  , &b_gamma_jet2_pt);
   fChain ->SetBranchStatus("pseudoJet1_pt"                                  , 0); fChain ->SetBranchAddress("pseudoJet1_pt"                                  , &pseudoJet1_pt                                  , &b_pseudoJet1_pt);
   fChain ->SetBranchStatus("pseudoJet1_eta"                                 , 0); fChain ->SetBranchAddress("pseudoJet1_eta"                                 , &pseudoJet1_eta                                 , &b_pseudoJet1_eta);
   fChain ->SetBranchStatus("pseudoJet1_phi"                                 , 0); fChain ->SetBranchAddress("pseudoJet1_phi"                                 , &pseudoJet1_phi                                 , &b_pseudoJet1_phi);
   fChain ->SetBranchStatus("pseudoJet1_mass"                                , 0); fChain ->SetBranchAddress("pseudoJet1_mass"                                , &pseudoJet1_mass                                , &b_pseudoJet1_mass);
   fChain ->SetBranchStatus("pseudoJet2_pt"                                  , 0); fChain ->SetBranchAddress("pseudoJet2_pt"                                  , &pseudoJet2_pt                                  , &b_pseudoJet2_pt);
   fChain ->SetBranchStatus("pseudoJet2_eta"                                 , 0); fChain ->SetBranchAddress("pseudoJet2_eta"                                 , &pseudoJet2_eta                                 , &b_pseudoJet2_eta);
   fChain ->SetBranchStatus("pseudoJet2_phi"                                 , 0); fChain ->SetBranchAddress("pseudoJet2_phi"                                 , &pseudoJet2_phi                                 , &b_pseudoJet2_phi);
   fChain ->SetBranchStatus("pseudoJet2_mass"                                , 0); fChain ->SetBranchAddress("pseudoJet2_mass"                                , &pseudoJet2_mass                                , &b_pseudoJet2_mass);
   fChain ->SetBranchStatus("mht_pt"                                         , 0); fChain ->SetBranchAddress("mht_pt"                                         , &mht_pt                                         , &b_mht_pt);
   fChain ->SetBranchStatus("mht_phi"                                        , 0); fChain ->SetBranchAddress("mht_phi"                                        , &mht_phi                                        , &b_mht_phi);
   fChain ->SetBranchStatus("mht_ptJECup"                                    , 0); fChain ->SetBranchAddress("mht_ptJECup"                                    , &mht_ptJECup                                    , &b_mht_ptJECup);
   fChain ->SetBranchStatus("mht_phiJECup"                                   , 0); fChain ->SetBranchAddress("mht_phiJECup"                                   , &mht_phiJECup                                   , &b_mht_phiJECup);
   fChain ->SetBranchStatus("mht_ptJECdn"                                    , 0); fChain ->SetBranchAddress("mht_ptJECdn"                                    , &mht_ptJECdn                                    , &b_mht_ptJECdn);
   fChain ->SetBranchStatus("mht_phiJECdn"                                   , 0); fChain ->SetBranchAddress("mht_phiJECdn"                                   , &mht_phiJECdn                                   , &b_mht_phiJECdn);
   fChain ->SetBranchStatus("met_pt"                                         , 1); fChain ->SetBranchAddress("met_pt"                                         , &met_pt                                         , &b_met_pt);
   fChain ->SetBranchStatus("met_phi"                                        , 1); fChain ->SetBranchAddress("met_phi"                                        , &met_phi                                        , &b_met_phi);
   fChain ->SetBranchStatus("met_ptJECup"                                    , 0); fChain ->SetBranchAddress("met_ptJECup"                                    , &met_ptJECup                                    , &b_met_ptJECup);
   fChain ->SetBranchStatus("met_phiJECup"                                   , 0); fChain ->SetBranchAddress("met_phiJECup"                                   , &met_phiJECup                                   , &b_met_phiJECup);
   fChain ->SetBranchStatus("met_ptJECdn"                                    , 0); fChain ->SetBranchAddress("met_ptJECdn"                                    , &met_ptJECdn                                    , &b_met_ptJECdn);
   fChain ->SetBranchStatus("met_phiJECdn"                                   , 0); fChain ->SetBranchAddress("met_phiJECdn"                                   , &met_phiJECdn                                   , &b_met_phiJECdn);
   fChain ->SetBranchStatus("met_rawPt"                                      , 0); fChain ->SetBranchAddress("met_rawPt"                                      , &met_rawPt                                      , &b_met_rawPt);
   fChain ->SetBranchStatus("met_rawPhi"                                     , 0); fChain ->SetBranchAddress("met_rawPhi"                                     , &met_rawPhi                                     , &b_met_rawPhi);
   fChain ->SetBranchStatus("met_caloPt"                                     , 0); fChain ->SetBranchAddress("met_caloPt"                                     , &met_caloPt                                     , &b_met_caloPt);
   fChain ->SetBranchStatus("met_caloPhi"                                    , 0); fChain ->SetBranchAddress("met_caloPhi"                                    , &met_caloPhi                                    , &b_met_caloPhi);
   fChain ->SetBranchStatus("met_trkPt"                                      , 0); fChain ->SetBranchAddress("met_trkPt"                                      , &met_trkPt                                      , &b_met_trkPt);
   fChain ->SetBranchStatus("met_trkPhi"                                     , 0); fChain ->SetBranchAddress("met_trkPhi"                                     , &met_trkPhi                                     , &b_met_trkPhi);
   fChain ->SetBranchStatus("met_genPt"                                      , 0); fChain ->SetBranchAddress("met_genPt"                                      , &met_genPt                                      , &b_met_genPt);
   fChain ->SetBranchStatus("met_genPhi"                                     , 0); fChain ->SetBranchAddress("met_genPhi"                                     , &met_genPhi                                     , &b_met_genPhi);
   fChain ->SetBranchStatus("Flag_EcalDeadCellTriggerPrimitiveFilter"        , 0); fChain ->SetBranchAddress("Flag_EcalDeadCellTriggerPrimitiveFilter"        , &Flag_EcalDeadCellTriggerPrimitiveFilter        , &b_Flag_EcalDeadCellTriggerPrimitiveFilter);
   fChain ->SetBranchStatus("Flag_trkPOG_manystripclus53X"                   , 0); fChain ->SetBranchAddress("Flag_trkPOG_manystripclus53X"                   , &Flag_trkPOG_manystripclus53X                   , &b_Flag_trkPOG_manystripclus53X);
   fChain ->SetBranchStatus("Flag_ecalLaserCorrFilter"                       , 0); fChain ->SetBranchAddress("Flag_ecalLaserCorrFilter"                       , &Flag_ecalLaserCorrFilter                       , &b_Flag_ecalLaserCorrFilter);
   fChain ->SetBranchStatus("Flag_trkPOG_toomanystripclus53X"                , 0); fChain ->SetBranchAddress("Flag_trkPOG_toomanystripclus53X"                , &Flag_trkPOG_toomanystripclus53X                , &b_Flag_trkPOG_toomanystripclus53X);
   fChain ->SetBranchStatus("Flag_hcalLaserEventFilter"                      , 0); fChain ->SetBranchAddress("Flag_hcalLaserEventFilter"                      , &Flag_hcalLaserEventFilter                      , &b_Flag_hcalLaserEventFilter);
   fChain ->SetBranchStatus("Flag_trkPOG_logErrorTooManyClusters"            , 0); fChain ->SetBranchAddress("Flag_trkPOG_logErrorTooManyClusters"            , &Flag_trkPOG_logErrorTooManyClusters            , &b_Flag_trkPOG_logErrorTooManyClusters);
   fChain ->SetBranchStatus("Flag_trkPOGFilters"                             , 0); fChain ->SetBranchAddress("Flag_trkPOGFilters"                             , &Flag_trkPOGFilters                             , &b_Flag_trkPOGFilters);
   fChain ->SetBranchStatus("Flag_trackingFailureFilter"                     , 0); fChain ->SetBranchAddress("Flag_trackingFailureFilter"                     , &Flag_trackingFailureFilter                     , &b_Flag_trackingFailureFilter);
   fChain ->SetBranchStatus("Flag_CSCTightHaloFilter"                        , 0); fChain ->SetBranchAddress("Flag_CSCTightHaloFilter"                        , &Flag_CSCTightHaloFilter                        , &b_Flag_CSCTightHaloFilter);
   fChain ->SetBranchStatus("Flag_HBHENoiseFilter"                           , 0); fChain ->SetBranchAddress("Flag_HBHENoiseFilter"                           , &Flag_HBHENoiseFilter                           , &b_Flag_HBHENoiseFilter);
   fChain ->SetBranchStatus("Flag_HBHEIsoNoiseFilter"                        , 0); fChain ->SetBranchAddress("Flag_HBHEIsoNoiseFilter"                        , &Flag_HBHEIsoNoiseFilter                        , &b_Flag_HBHEIsoNoiseFilter);
   fChain ->SetBranchStatus("Flag_goodVertices"                              , 0); fChain ->SetBranchAddress("Flag_goodVertices"                              , &Flag_goodVertices                              , &b_Flag_goodVertices);
   fChain ->SetBranchStatus("Flag_eeBadScFilter"                             , 0); fChain ->SetBranchAddress("Flag_eeBadScFilter"                             , &Flag_eeBadScFilter                             , &b_Flag_eeBadScFilter);
   fChain ->SetBranchStatus("Flag_METFilters"                                , 0); fChain ->SetBranchAddress("Flag_METFilters"                                , &Flag_METFilters                                , &b_Flag_METFilters);
   fChain ->SetBranchStatus("HLT_PFHT800"                                    , 0); fChain ->SetBranchAddress("HLT_PFHT800"                                    , &HLT_PFHT800                                    , &b_HLT_PFHT800);
   fChain ->SetBranchStatus("HLT_PFHT900"                                    , 0); fChain ->SetBranchAddress("HLT_PFHT900"                                    , &HLT_PFHT900                                    , &b_HLT_PFHT900);
   fChain ->SetBranchStatus("HLT_PFMET170"                                   , 0); fChain ->SetBranchAddress("HLT_PFMET170"                                   , &HLT_PFMET170                                   , &b_HLT_PFMET170);
   fChain ->SetBranchStatus("HLT_PFHT350_PFMET100"                           , 0); fChain ->SetBranchAddress("HLT_PFHT350_PFMET100"                           , &HLT_PFHT350_PFMET100                           , &b_HLT_PFHT350_PFMET100);
   fChain ->SetBranchStatus("HLT_PFHT350_PFMET120"                           , 0); fChain ->SetBranchAddress("HLT_PFHT350_PFMET120"                           , &HLT_PFHT350_PFMET120                           , &b_HLT_PFHT350_PFMET120);
   fChain ->SetBranchStatus("HLT_PFMETNoMu90_PFMHTNoMu90"                    , 0); fChain ->SetBranchAddress("HLT_PFMETNoMu90_PFMHTNoMu90"                    , &HLT_PFMETNoMu90_PFMHTNoMu90                    , &b_HLT_PFMETNoMu90_PFMHTNoMu90);
   fChain ->SetBranchStatus("HLT_MonoCentralPFJet80_PFMETNoMu90_PFMHTNoMu90" , 0); fChain ->SetBranchAddress("HLT_MonoCentralPFJet80_PFMETNoMu90_PFMHTNoMu90" , &HLT_MonoCentralPFJet80_PFMETNoMu90_PFMHTNoMu90 , &b_HLT_MonoCentralPFJet80_PFMETNoMu90_PFMHTNoMu90);
   fChain ->SetBranchStatus("HLT_PFMETNoMu120_PFMHTNoMu120"                  , 0); fChain ->SetBranchAddress("HLT_PFMETNoMu120_PFMHTNoMu120"                  , &HLT_PFMETNoMu120_PFMHTNoMu120                  , &b_HLT_PFMETNoMu120_PFMHTNoMu120);
   fChain ->SetBranchStatus("HLT_PFMET90_PFMHT90"                            , 0); fChain ->SetBranchAddress("HLT_PFMET90_PFMHT90"                            , &HLT_PFMET90_PFMHT90                            , &b_HLT_PFMET90_PFMHT90);
   fChain ->SetBranchStatus("HLT_SingleMu"                                   , 0); fChain ->SetBranchAddress("HLT_SingleMu"                                   , &HLT_SingleMu                                   , &b_HLT_SingleMu);
   fChain ->SetBranchStatus("HLT_SingleEl"                                   , 0); fChain ->SetBranchAddress("HLT_SingleEl"                                   , &HLT_SingleEl                                   , &b_HLT_SingleEl);
   fChain ->SetBranchStatus("HLT_DoubleEl"                                   , 0); fChain ->SetBranchAddress("HLT_DoubleEl"                                   , &HLT_DoubleEl                                   , &b_HLT_DoubleEl);
   fChain ->SetBranchStatus("HLT_DoubleEl33"                                 , 0); fChain ->SetBranchAddress("HLT_DoubleEl33"                                 , &HLT_DoubleEl33                                 , &b_HLT_DoubleEl33);
   fChain ->SetBranchStatus("HLT_MuX_Ele12"                                  , 0); fChain ->SetBranchAddress("HLT_MuX_Ele12"                                  , &HLT_MuX_Ele12                                  , &b_HLT_MuX_Ele12);
   fChain ->SetBranchStatus("HLT_Mu8_EleX"                                   , 0); fChain ->SetBranchAddress("HLT_Mu8_EleX"                                   , &HLT_Mu8_EleX                                   , &b_HLT_Mu8_EleX);
   fChain ->SetBranchStatus("HLT_DoubleMu"                                   , 0); fChain ->SetBranchAddress("HLT_DoubleMu"                                   , &HLT_DoubleMu                                   , &b_HLT_DoubleMu);
   fChain ->SetBranchStatus("HLT_Photon120"                                  , 0); fChain ->SetBranchAddress("HLT_Photon120"                                  , &HLT_Photon120                                  , &b_HLT_Photon120);
   fChain ->SetBranchStatus("HLT_Photon165_HE10"                             , 0); fChain ->SetBranchAddress("HLT_Photon165_HE10"                             , &HLT_Photon165_HE10                             , &b_HLT_Photon165_HE10);
   fChain ->SetBranchStatus("HLT_PFHT200_Prescale"                           , 0); fChain ->SetBranchAddress("HLT_PFHT200_Prescale"                           , &HLT_PFHT200_Prescale                           , &b_HLT_PFHT200_Prescale);
   fChain ->SetBranchStatus("HLT_PFHT300_Prescale"                           , 0); fChain ->SetBranchAddress("HLT_PFHT300_Prescale"                           , &HLT_PFHT300_Prescale                           , &b_HLT_PFHT300_Prescale);
   fChain ->SetBranchStatus("HLT_PFHT350_Prescale"                           , 0); fChain ->SetBranchAddress("HLT_PFHT350_Prescale"                           , &HLT_PFHT350_Prescale                           , &b_HLT_PFHT350_Prescale);
   fChain ->SetBranchStatus("HLT_PFHT475_Prescale"                           , 0); fChain ->SetBranchAddress("HLT_PFHT475_Prescale"                           , &HLT_PFHT475_Prescale                           , &b_HLT_PFHT475_Prescale);
   fChain ->SetBranchStatus("HLT_PFHT600_Prescale"                           , 0); fChain ->SetBranchAddress("HLT_PFHT600_Prescale"                           , &HLT_PFHT600_Prescale                           , &b_HLT_PFHT600_Prescale);
   fChain ->SetBranchStatus("HLT_DiCentralPFJet70_PFMET120"                  , 0); fChain ->SetBranchAddress("HLT_DiCentralPFJet70_PFMET120"                  , &HLT_DiCentralPFJet70_PFMET120                  , &b_HLT_DiCentralPFJet70_PFMET120);
   fChain ->SetBranchStatus("HLT_DiCentralPFJet55_PFMET110"                  , 0); fChain ->SetBranchAddress("HLT_DiCentralPFJet55_PFMET110"                  , &HLT_DiCentralPFJet55_PFMET110                  , &b_HLT_DiCentralPFJet55_PFMET110);
   fChain ->SetBranchStatus("nlep"                                           , 1); fChain ->SetBranchAddress("nlep"                                           , &nlep                                           , &b_nlep);
   fChain ->SetBranchStatus("nlepIso"                                        , 0); fChain ->SetBranchAddress("nlepIso"                                        , &nlepIso                                        , &b_nlepIso);
   fChain ->SetBranchStatus("nlepIso20"                                      , 0); fChain ->SetBranchAddress("nlepIso20"                                      , &nlepIso20                                      , &b_nlepIso20);
   fChain ->SetBranchStatus("lep_pt"                                         , 1); fChain ->SetBranchAddress("lep_pt"                                         , lep_pt                                          , &b_lep_pt);
   fChain ->SetBranchStatus("lep_eta"                                        , 1); fChain ->SetBranchAddress("lep_eta"                                        , lep_eta                                         , &b_lep_eta);
   fChain ->SetBranchStatus("lep_phi"                                        , 1); fChain ->SetBranchAddress("lep_phi"                                        , lep_phi                                         , &b_lep_phi);
   fChain ->SetBranchStatus("lep_mass"                                       , 1); fChain ->SetBranchAddress("lep_mass"                                       , lep_mass                                        , &b_lep_mass);
   fChain ->SetBranchStatus("lep_charge"                                     , 1); fChain ->SetBranchAddress("lep_charge"                                     , lep_charge                                      , &b_lep_charge);
   fChain ->SetBranchStatus("lep_pdgId"                                      , 1); fChain ->SetBranchAddress("lep_pdgId"                                      , lep_pdgId                                       , &b_lep_pdgId);
   fChain ->SetBranchStatus("lep_dxy"                                        , 1); fChain ->SetBranchAddress("lep_dxy"                                        , lep_dxy                                         , &b_lep_dxy);
   fChain ->SetBranchStatus("lep_dz"                                         , 1); fChain ->SetBranchAddress("lep_dz"                                         , lep_dz                                          , &b_lep_dz);
   fChain ->SetBranchStatus("lep_tightId"                                    , 1); fChain ->SetBranchAddress("lep_tightId"                                    , lep_tightId                                     , &b_lep_tightId);
   fChain ->SetBranchStatus("lep_heepId"                                     , 1); fChain ->SetBranchAddress("lep_heepId"                                     , lep_heepId                                      , &b_lep_heepId);
   fChain ->SetBranchStatus("lep_relIso03"                                   , 1); fChain ->SetBranchAddress("lep_relIso03"                                   , lep_relIso03                                    , &b_lep_relIso03);
   fChain ->SetBranchStatus("lep_relIso04"                                   , 1); fChain ->SetBranchAddress("lep_relIso04"                                   , lep_relIso04                                    , &b_lep_relIso04);
   fChain ->SetBranchStatus("lep_miniRelIso"                                 , 1); fChain ->SetBranchAddress("lep_miniRelIso"                                 , lep_miniRelIso                                  , &b_lep_miniRelIso);
   fChain ->SetBranchStatus("lep_relIsoAn04"                                 , 1); fChain ->SetBranchAddress("lep_relIsoAn04"                                 , lep_relIsoAn04                                  , &b_lep_relIsoAn04);
   fChain ->SetBranchStatus("lep_mcMatchId"                                  , 1); fChain ->SetBranchAddress("lep_mcMatchId"                                  , lep_mcMatchId                                   , &b_lep_mcMatchId);
   fChain ->SetBranchStatus("lep_lostHits"                                   , 1); fChain ->SetBranchAddress("lep_lostHits"                                   , lep_lostHits                                    , &b_lep_lostHits);
   fChain ->SetBranchStatus("lep_convVeto"                                   , 1); fChain ->SetBranchAddress("lep_convVeto"                                   , lep_convVeto                                    , &b_lep_convVeto);
   fChain ->SetBranchStatus("lep_tightCharge"                                , 1); fChain ->SetBranchAddress("lep_tightCharge"                                , lep_tightCharge                                 , &b_lep_tightCharge);
   fChain ->SetBranchStatus("lep_mva"                                        , 1); fChain ->SetBranchAddress("lep_mva"                                        , lep_mva                                         , &b_lep_mva);
   fChain ->SetBranchStatus("lep_ptRatio"                                    , 1); fChain ->SetBranchAddress("lep_ptRatio"                                    , lep_ptRatio                                     , &b_lep_ptRatio);
   fChain ->SetBranchStatus("lep_ptRel"                                      , 1); fChain ->SetBranchAddress("lep_ptRel"                                      , lep_ptRel                                       , &b_lep_ptRel);
   fChain ->SetBranchStatus("lep_tightIdNoIso"                               , 1); fChain ->SetBranchAddress("lep_tightIdNoIso"                               , lep_tightIdNoIso                                , &b_lep_tightIdNoIso);
   fChain ->SetBranchStatus("lep_sip3d"                                      , 1); fChain ->SetBranchAddress("lep_sip3d"                                      , lep_sip3d                                       , &b_lep_sip3d);
   fChain ->SetBranchStatus("nisoTrack"                                      , 0); fChain ->SetBranchAddress("nisoTrack"                                      , &nisoTrack                                      , &b_nisoTrack);
   fChain ->SetBranchStatus("isoTrack_pt"                                    , 0); fChain ->SetBranchAddress("isoTrack_pt"                                    , isoTrack_pt                                     , &b_isoTrack_pt);
   fChain ->SetBranchStatus("isoTrack_eta"                                   , 0); fChain ->SetBranchAddress("isoTrack_eta"                                   , isoTrack_eta                                    , &b_isoTrack_eta);
   fChain ->SetBranchStatus("isoTrack_phi"                                   , 0); fChain ->SetBranchAddress("isoTrack_phi"                                   , isoTrack_phi                                    , &b_isoTrack_phi);
   fChain ->SetBranchStatus("isoTrack_mass"                                  , 0); fChain ->SetBranchAddress("isoTrack_mass"                                  , isoTrack_mass                                   , &b_isoTrack_mass);
   fChain ->SetBranchStatus("isoTrack_absIso"                                , 0); fChain ->SetBranchAddress("isoTrack_absIso"                                , isoTrack_absIso                                 , &b_isoTrack_absIso);
   fChain ->SetBranchStatus("isoTrack_relIsoAn04"                            , 0); fChain ->SetBranchAddress("isoTrack_relIsoAn04"                            , isoTrack_relIsoAn04                             , &b_isoTrack_relIsoAn04);
   fChain ->SetBranchStatus("isoTrack_dz"                                    , 0); fChain ->SetBranchAddress("isoTrack_dz"                                    , isoTrack_dz                                     , &b_isoTrack_dz);
   fChain ->SetBranchStatus("isoTrack_pdgId"                                 , 0); fChain ->SetBranchAddress("isoTrack_pdgId"                                 , isoTrack_pdgId                                  , &b_isoTrack_pdgId);
   fChain ->SetBranchStatus("isoTrack_mcMatchId"                             , 0); fChain ->SetBranchAddress("isoTrack_mcMatchId"                             , isoTrack_mcMatchId                              , &b_isoTrack_mcMatchId);
   fChain ->SetBranchStatus("nPFLep5LowMT"                                   , 0); fChain ->SetBranchAddress("nPFLep5LowMT"                                   , &nPFLep5LowMT                                   , &b_nPFLep5LowMT);
   fChain ->SetBranchStatus("nPFHad10LowMT"                                  , 0); fChain ->SetBranchAddress("nPFHad10LowMT"                                  , &nPFHad10LowMT                                  , &b_nPFHad10LowMT);
   fChain ->SetBranchStatus("nPFHad10"                                       , 0); fChain ->SetBranchAddress("nPFHad10"                                       , &nPFHad10                                       , &b_nPFHad10);
   fChain ->SetBranchStatus("ntau"                                           , 0); fChain ->SetBranchAddress("ntau"                                           , &ntau                                           , &b_ntau);
   fChain ->SetBranchStatus("tau_pt"                                         , 0); fChain ->SetBranchAddress("tau_pt"                                         , tau_pt                                          , &b_tau_pt);
   fChain ->SetBranchStatus("tau_eta"                                        , 0); fChain ->SetBranchAddress("tau_eta"                                        , tau_eta                                         , &b_tau_eta);
   fChain ->SetBranchStatus("tau_phi"                                        , 0); fChain ->SetBranchAddress("tau_phi"                                        , tau_phi                                         , &b_tau_phi);
   fChain ->SetBranchStatus("tau_mass"                                       , 0); fChain ->SetBranchAddress("tau_mass"                                       , tau_mass                                        , &b_tau_mass);
   fChain ->SetBranchStatus("tau_charge"                                     , 0); fChain ->SetBranchAddress("tau_charge"                                     , tau_charge                                      , &b_tau_charge);
   fChain ->SetBranchStatus("tau_dxy"                                        , 0); fChain ->SetBranchAddress("tau_dxy"                                        , tau_dxy                                         , &b_tau_dxy);
   fChain ->SetBranchStatus("tau_dz"                                         , 0); fChain ->SetBranchAddress("tau_dz"                                         , tau_dz                                          , &b_tau_dz);
   fChain ->SetBranchStatus("tau_idCI3hit"                                   , 0); fChain ->SetBranchAddress("tau_idCI3hit"                                   , tau_idCI3hit                                    , &b_tau_idCI3hit);
   fChain ->SetBranchStatus("tau_isoCI3hit"                                  , 0); fChain ->SetBranchAddress("tau_isoCI3hit"                                  , tau_isoCI3hit                                   , &b_tau_isoCI3hit);
   fChain ->SetBranchStatus("tau_mcMatchId"                                  , 0); fChain ->SetBranchAddress("tau_mcMatchId"                                  , tau_mcMatchId                                   , &b_tau_mcMatchId);
   fChain ->SetBranchStatus("ngamma"                                         , 0); fChain ->SetBranchAddress("ngamma"                                         , &ngamma                                         , &b_ngamma);
   fChain ->SetBranchStatus("gamma_pt"                                       , 0); fChain ->SetBranchAddress("gamma_pt"                                       , gamma_pt                                        , &b_gamma_pt);
   fChain ->SetBranchStatus("gamma_eta"                                      , 0); fChain ->SetBranchAddress("gamma_eta"                                      , gamma_eta                                       , &b_gamma_eta);
   fChain ->SetBranchStatus("gamma_phi"                                      , 0); fChain ->SetBranchAddress("gamma_phi"                                      , gamma_phi                                       , &b_gamma_phi);
   fChain ->SetBranchStatus("gamma_mass"                                     , 0); fChain ->SetBranchAddress("gamma_mass"                                     , gamma_mass                                      , &b_gamma_mass);
   fChain ->SetBranchStatus("gamma_mcMatchId"                                , 0); fChain ->SetBranchAddress("gamma_mcMatchId"                                , gamma_mcMatchId                                 , &b_gamma_mcMatchId);
   fChain ->SetBranchStatus("gamma_genIso04"                                 , 0); fChain ->SetBranchAddress("gamma_genIso04"                                 , gamma_genIso04                                  , &b_gamma_genIso04);
   fChain ->SetBranchStatus("gamma_drMinParton"                              , 0); fChain ->SetBranchAddress("gamma_drMinParton"                              , gamma_drMinParton                               , &b_gamma_drMinParton);
   fChain ->SetBranchStatus("gamma_chHadIso"                                 , 0); fChain ->SetBranchAddress("gamma_chHadIso"                                 , gamma_chHadIso                                  , &b_gamma_chHadIso);
   fChain ->SetBranchStatus("gamma_neuHadIso"                                , 0); fChain ->SetBranchAddress("gamma_neuHadIso"                                , gamma_neuHadIso                                 , &b_gamma_neuHadIso);
   fChain ->SetBranchStatus("gamma_phIso"                                    , 0); fChain ->SetBranchAddress("gamma_phIso"                                    , gamma_phIso                                     , &b_gamma_phIso);
   fChain ->SetBranchStatus("gamma_sigmaIetaIeta"                            , 0); fChain ->SetBranchAddress("gamma_sigmaIetaIeta"                            , gamma_sigmaIetaIeta                             , &b_gamma_sigmaIetaIeta);
   fChain ->SetBranchStatus("gamma_r9"                                       , 0); fChain ->SetBranchAddress("gamma_r9"                                       , gamma_r9                                        , &b_gamma_r9);
   fChain ->SetBranchStatus("gamma_hOverE"                                   , 0); fChain ->SetBranchAddress("gamma_hOverE"                                   , gamma_hOverE                                    , &b_gamma_hOverE);
   fChain ->SetBranchStatus("gamma_idCutBased"                               , 0); fChain ->SetBranchAddress("gamma_idCutBased"                               , gamma_idCutBased                                , &b_gamma_idCutBased);
   fChain ->SetBranchStatus("sl_mt2"                                         , 0); fChain ->SetBranchAddress("sl_mt2"                                         , &sl_mt2                                         , &b_sl_mt2);
   fChain ->SetBranchStatus("gamma_mt2"                                      , 0); fChain ->SetBranchAddress("gamma_mt2"                                      , &gamma_mt2                                      , &b_gamma_mt2);
   fChain ->SetBranchStatus("gamma_nJet30"                                   , 0); fChain ->SetBranchAddress("gamma_nJet30"                                   , &gamma_nJet30                                   , &b_gamma_nJet30);
   fChain ->SetBranchStatus("gamma_nJet40"                                   , 0); fChain ->SetBranchAddress("gamma_nJet40"                                   , &gamma_nJet40                                   , &b_gamma_nJet40);
   fChain ->SetBranchStatus("gamma_nJet30FailId"                             , 0); fChain ->SetBranchAddress("gamma_nJet30FailId"                             , &gamma_nJet30FailId                             , &b_gamma_nJet30FailId);
   fChain ->SetBranchStatus("gamma_nJet100FailId"                            , 0); fChain ->SetBranchAddress("gamma_nJet100FailId"                            , &gamma_nJet100FailId                            , &b_gamma_nJet100FailId);
   fChain ->SetBranchStatus("gamma_nBJet20"                                  , 0); fChain ->SetBranchAddress("gamma_nBJet20"                                  , &gamma_nBJet20                                  , &b_gamma_nBJet20);
   fChain ->SetBranchStatus("gamma_nBJet25"                                  , 0); fChain ->SetBranchAddress("gamma_nBJet25"                                  , &gamma_nBJet25                                  , &b_gamma_nBJet25);
   fChain ->SetBranchStatus("gamma_nBJet30"                                  , 0); fChain ->SetBranchAddress("gamma_nBJet30"                                  , &gamma_nBJet30                                  , &b_gamma_nBJet30);
   fChain ->SetBranchStatus("gamma_nBJet40"                                  , 0); fChain ->SetBranchAddress("gamma_nBJet40"                                  , &gamma_nBJet40                                  , &b_gamma_nBJet40);
   fChain ->SetBranchStatus("gamma_ht"                                       , 0); fChain ->SetBranchAddress("gamma_ht"                                       , &gamma_ht                                       , &b_gamma_ht);
   fChain ->SetBranchStatus("gamma_deltaPhiMin"                              , 0); fChain ->SetBranchAddress("gamma_deltaPhiMin"                              , &gamma_deltaPhiMin                              , &b_gamma_deltaPhiMin);
   fChain ->SetBranchStatus("gamma_diffMetMht"                               , 0); fChain ->SetBranchAddress("gamma_diffMetMht"                               , &gamma_diffMetMht                               , &b_gamma_diffMetMht);
   fChain ->SetBranchStatus("gamma_mht_pt"                                   , 0); fChain ->SetBranchAddress("gamma_mht_pt"                                   , &gamma_mht_pt                                   , &b_gamma_mht_pt);
   fChain ->SetBranchStatus("gamma_mht_phi"                                  , 0); fChain ->SetBranchAddress("gamma_mht_phi"                                  , &gamma_mht_phi                                  , &b_gamma_mht_phi);
   fChain ->SetBranchStatus("gamma_met_pt"                                   , 0); fChain ->SetBranchAddress("gamma_met_pt"                                   , &gamma_met_pt                                   , &b_gamma_met_pt);
   fChain ->SetBranchStatus("gamma_met_phi"                                  , 0); fChain ->SetBranchAddress("gamma_met_phi"                                  , &gamma_met_phi                                  , &b_gamma_met_phi);
   fChain ->SetBranchStatus("zll_mt2"                                        , 0); fChain ->SetBranchAddress("zll_mt2"                                        , &zll_mt2                                        , &b_zll_mt2);
   fChain ->SetBranchStatus("zll_deltaPhiMin"                                , 0); fChain ->SetBranchAddress("zll_deltaPhiMin"                                , &zll_deltaPhiMin                                , &b_zll_deltaPhiMin);
   fChain ->SetBranchStatus("zll_diffMetMht"                                 , 0); fChain ->SetBranchAddress("zll_diffMetMht"                                 , &zll_diffMetMht                                 , &b_zll_diffMetMht);
   fChain ->SetBranchStatus("zll_met_pt"                                     , 0); fChain ->SetBranchAddress("zll_met_pt"                                     , &zll_met_pt                                     , &b_zll_met_pt);
   fChain ->SetBranchStatus("zll_met_phi"                                    , 0); fChain ->SetBranchAddress("zll_met_phi"                                    , &zll_met_phi                                    , &b_zll_met_phi);
   fChain ->SetBranchStatus("zll_mht_pt"                                     , 0); fChain ->SetBranchAddress("zll_mht_pt"                                     , &zll_mht_pt                                     , &b_zll_mht_pt);
   fChain ->SetBranchStatus("zll_mht_phi"                                    , 0); fChain ->SetBranchAddress("zll_mht_phi"                                    , &zll_mht_phi                                    , &b_zll_mht_phi);
   fChain ->SetBranchStatus("zll_mass"                                       , 0); fChain ->SetBranchAddress("zll_mass"                                       , &zll_mass                                       , &b_zll_mass);
   fChain ->SetBranchStatus("zll_pt"                                         , 0); fChain ->SetBranchAddress("zll_pt"                                         , &zll_pt                                         , &b_zll_pt);
   fChain ->SetBranchStatus("zll_eta"                                        , 0); fChain ->SetBranchAddress("zll_eta"                                        , &zll_eta                                        , &b_zll_eta);
   fChain ->SetBranchStatus("zll_phi"                                        , 0); fChain ->SetBranchAddress("zll_phi"                                        , &zll_phi                                        , &b_zll_phi);
   fChain ->SetBranchStatus("zll_ht"                                         , 0); fChain ->SetBranchAddress("zll_ht"                                         , &zll_ht                                         , &b_zll_ht);
   fChain ->SetBranchStatus("zllmt_mt2"                                      , 0); fChain ->SetBranchAddress("zllmt_mt2"                                      , &zllmt_mt2                                      , &b_zllmt_mt2);
   fChain ->SetBranchStatus("zllmt_deltaPhiMin"                              , 0); fChain ->SetBranchAddress("zllmt_deltaPhiMin"                              , &zllmt_deltaPhiMin                              , &b_zllmt_deltaPhiMin);
   fChain ->SetBranchStatus("zllmt_diffMetMht"                               , 0); fChain ->SetBranchAddress("zllmt_diffMetMht"                               , &zllmt_diffMetMht                               , &b_zllmt_diffMetMht);
   fChain ->SetBranchStatus("zllmt_met_pt"                                   , 0); fChain ->SetBranchAddress("zllmt_met_pt"                                   , &zllmt_met_pt                                   , &b_zllmt_met_pt);
   fChain ->SetBranchStatus("zllmt_met_phi"                                  , 0); fChain ->SetBranchAddress("zllmt_met_phi"                                  , &zllmt_met_phi                                  , &b_zllmt_met_phi);
   fChain ->SetBranchStatus("zllmt_mht_pt"                                   , 0); fChain ->SetBranchAddress("zllmt_mht_pt"                                   , &zllmt_mht_pt                                   , &b_zllmt_mht_pt);
   fChain ->SetBranchStatus("zllmt_mht_phi"                                  , 0); fChain ->SetBranchAddress("zllmt_mht_phi"                                  , &zllmt_mht_phi                                  , &b_zllmt_mht_phi);
   fChain ->SetBranchStatus("zllmt_ht"                                       , 0); fChain ->SetBranchAddress("zllmt_ht"                                       , &zllmt_ht                                       , &b_zllmt_ht);
   fChain ->SetBranchStatus("zllmt_mt"                                       , 0); fChain ->SetBranchAddress("zllmt_mt"                                       , &zllmt_mt                                       , &b_zllmt_mt);
   fChain ->SetBranchStatus("rl_mt2"                                         , 0); fChain ->SetBranchAddress("rl_mt2"                                         , &rl_mt2                                         , &b_rl_mt2);
   fChain ->SetBranchStatus("rl_deltaPhiMin"                                 , 0); fChain ->SetBranchAddress("rl_deltaPhiMin"                                 , &rl_deltaPhiMin                                 , &b_rl_deltaPhiMin);
   fChain ->SetBranchStatus("rl_diffMetMht"                                  , 0); fChain ->SetBranchAddress("rl_diffMetMht"                                  , &rl_diffMetMht                                  , &b_rl_diffMetMht);
   fChain ->SetBranchStatus("rl_met_pt"                                      , 0); fChain ->SetBranchAddress("rl_met_pt"                                      , &rl_met_pt                                      , &b_rl_met_pt);
   fChain ->SetBranchStatus("rl_met_phi"                                     , 0); fChain ->SetBranchAddress("rl_met_phi"                                     , &rl_met_phi                                     , &b_rl_met_phi);
   fChain ->SetBranchStatus("rl_mht_pt"                                      , 0); fChain ->SetBranchAddress("rl_mht_pt"                                      , &rl_mht_pt                                      , &b_rl_mht_pt);
   fChain ->SetBranchStatus("rl_mht_phi"                                     , 0); fChain ->SetBranchAddress("rl_mht_phi"                                     , &rl_mht_phi                                     , &b_rl_mht_phi);
   fChain ->SetBranchStatus("rl_mass"                                        , 0); fChain ->SetBranchAddress("rl_mass"                                        , &rl_mass                                        , &b_rl_mass);
   fChain ->SetBranchStatus("rl_pt"                                          , 0); fChain ->SetBranchAddress("rl_pt"                                          , &rl_pt                                          , &b_rl_pt);
   fChain ->SetBranchStatus("rl_eta"                                         , 0); fChain ->SetBranchAddress("rl_eta"                                         , &rl_eta                                         , &b_rl_eta);
   fChain ->SetBranchStatus("rl_phi"                                         , 0); fChain ->SetBranchAddress("rl_phi"                                         , &rl_phi                                         , &b_rl_phi);
   fChain ->SetBranchStatus("rl_ht"                                          , 0); fChain ->SetBranchAddress("rl_ht"                                          , &rl_ht                                          , &b_rl_ht);
   fChain ->SetBranchStatus("ngenLep"                                        , 0); fChain ->SetBranchAddress("ngenLep"                                        , &ngenLep                                        , &b_ngenLep);
   fChain ->SetBranchStatus("genLep_pt"                                      , 0); fChain ->SetBranchAddress("genLep_pt"                                      , genLep_pt                                       , &b_genLep_pt);
   fChain ->SetBranchStatus("genLep_eta"                                     , 0); fChain ->SetBranchAddress("genLep_eta"                                     , genLep_eta                                      , &b_genLep_eta);
   fChain ->SetBranchStatus("genLep_phi"                                     , 0); fChain ->SetBranchAddress("genLep_phi"                                     , genLep_phi                                      , &b_genLep_phi);
   fChain ->SetBranchStatus("genLep_mass"                                    , 0); fChain ->SetBranchAddress("genLep_mass"                                    , genLep_mass                                     , &b_genLep_mass);
   fChain ->SetBranchStatus("genLep_pdgId"                                   , 0); fChain ->SetBranchAddress("genLep_pdgId"                                   , genLep_pdgId                                    , &b_genLep_pdgId);
   fChain ->SetBranchStatus("genLep_status"                                  , 0); fChain ->SetBranchAddress("genLep_status"                                  , genLep_status                                   , &b_genLep_status);
   fChain ->SetBranchStatus("genLep_charge"                                  , 0); fChain ->SetBranchAddress("genLep_charge"                                  , genLep_charge                                   , &b_genLep_charge);
   fChain ->SetBranchStatus("genLep_sourceId"                                , 0); fChain ->SetBranchAddress("genLep_sourceId"                                , genLep_sourceId                                 , &b_genLep_sourceId);
   fChain ->SetBranchStatus("ngenStat23"                                     , 1); fChain ->SetBranchAddress("ngenStat23"                                     , &ngenStat23                                     , &b_ngenStat23);
   fChain ->SetBranchStatus("genStat23_pt"                                   , 0); fChain ->SetBranchAddress("genStat23_pt"                                   , genStat23_pt                                    , &b_genStat23_pt);
   fChain ->SetBranchStatus("genStat23_eta"                                  , 0); fChain ->SetBranchAddress("genStat23_eta"                                  , genStat23_eta                                   , &b_genStat23_eta);
   fChain ->SetBranchStatus("genStat23_phi"                                  , 0); fChain ->SetBranchAddress("genStat23_phi"                                  , genStat23_phi                                   , &b_genStat23_phi);
   fChain ->SetBranchStatus("genStat23_mass"                                 , 1); fChain ->SetBranchAddress("genStat23_mass"                                 , genStat23_mass                                  , &b_genStat23_mass);
   fChain ->SetBranchStatus("genStat23_pdgId"                                , 1); fChain ->SetBranchAddress("genStat23_pdgId"                                , genStat23_pdgId                                 , &b_genStat23_pdgId);
   fChain ->SetBranchStatus("genStat23_status"                               , 1); fChain ->SetBranchAddress("genStat23_status"                               , genStat23_status                                , &b_genStat23_status);
   fChain ->SetBranchStatus("genStat23_charge"                               , 0); fChain ->SetBranchAddress("genStat23_charge"                               , genStat23_charge                                , &b_genStat23_charge);
   fChain ->SetBranchStatus("genStat23_sourceId"                             , 0); fChain ->SetBranchAddress("genStat23_sourceId"                             , genStat23_sourceId                              , &b_genStat23_sourceId);
   fChain ->SetBranchStatus("ngenGamma"                                      , 0); fChain ->SetBranchAddress("ngenGamma"                                      , &ngenGamma                                      , &b_ngenGamma);
   fChain ->SetBranchStatus("genGamma_pt"                                    , 0); fChain ->SetBranchAddress("genGamma_pt"                                    , genGamma_pt                                     , &b_genGamma_pt);
   fChain ->SetBranchStatus("genGamma_eta"                                   , 0); fChain ->SetBranchAddress("genGamma_eta"                                   , genGamma_eta                                    , &b_genGamma_eta);
   fChain ->SetBranchStatus("genGamma_phi"                                   , 0); fChain ->SetBranchAddress("genGamma_phi"                                   , genGamma_phi                                    , &b_genGamma_phi);
   fChain ->SetBranchStatus("genGamma_motherId"                              , 0); fChain ->SetBranchAddress("genGamma_motherId"                              , genGamma_motherId                               , &b_genGamma_motherId);
   fChain ->SetBranchStatus("ngenTau"                                        , 0); fChain ->SetBranchAddress("ngenTau"                                        , &ngenTau                                        , &b_ngenTau);
   fChain ->SetBranchStatus("ngenTau1Prong"                                  , 0); fChain ->SetBranchAddress("ngenTau1Prong"                                  , &ngenTau1Prong                                  , &b_ngenTau1Prong);
   fChain ->SetBranchStatus("ngenTau3Prong"                                  , 0); fChain ->SetBranchAddress("ngenTau3Prong"                                  , &ngenTau3Prong                                  , &b_ngenTau3Prong);
   fChain ->SetBranchStatus("genTau_pt"                                      , 0); fChain ->SetBranchAddress("genTau_pt"                                      , genTau_pt                                       , &b_genTau_pt);
   fChain ->SetBranchStatus("genTau_eta"                                     , 0); fChain ->SetBranchAddress("genTau_eta"                                     , genTau_eta                                      , &b_genTau_eta);
   fChain ->SetBranchStatus("genTau_phi"                                     , 0); fChain ->SetBranchAddress("genTau_phi"                                     , genTau_phi                                      , &b_genTau_phi);
   fChain ->SetBranchStatus("genTau_mass"                                    , 0); fChain ->SetBranchAddress("genTau_mass"                                    , genTau_mass                                     , &b_genTau_mass);
   fChain ->SetBranchStatus("genTau_pdgId"                                   , 0); fChain ->SetBranchAddress("genTau_pdgId"                                   , genTau_pdgId                                    , &b_genTau_pdgId);
   fChain ->SetBranchStatus("genTau_status"                                  , 0); fChain ->SetBranchAddress("genTau_status"                                  , genTau_status                                   , &b_genTau_status);
   fChain ->SetBranchStatus("genTau_charge"                                  , 0); fChain ->SetBranchAddress("genTau_charge"                                  , genTau_charge                                   , &b_genTau_charge);
   fChain ->SetBranchStatus("genTau_sourceId"                                , 0); fChain ->SetBranchAddress("genTau_sourceId"                                , genTau_sourceId                                 , &b_genTau_sourceId);
   fChain ->SetBranchStatus("genTau_decayMode"                               , 0); fChain ->SetBranchAddress("genTau_decayMode"                               , genTau_decayMode                                , &b_genTau_decayMode);
   fChain ->SetBranchStatus("genTau_leadTrackPt"                             , 0); fChain ->SetBranchAddress("genTau_leadTrackPt"                             , genTau_leadTrackPt                              , &b_genTau_leadTrackPt);
   fChain ->SetBranchStatus("genTau_neutralDaughters"                        , 0); fChain ->SetBranchAddress("genTau_neutralDaughters"                        , genTau_neutralDaughters                         , &b_genTau_neutralDaughters);
   fChain ->SetBranchStatus("ngenLepFromTau"                                 , 0); fChain ->SetBranchAddress("ngenLepFromTau"                                 , &ngenLepFromTau                                 , &b_ngenLepFromTau);
   fChain ->SetBranchStatus("genLepFromTau_pt"                               , 0); fChain ->SetBranchAddress("genLepFromTau_pt"                               , genLepFromTau_pt                                , &b_genLepFromTau_pt);
   fChain ->SetBranchStatus("genLepFromTau_eta"                              , 0); fChain ->SetBranchAddress("genLepFromTau_eta"                              , genLepFromTau_eta                               , &b_genLepFromTau_eta);
   fChain ->SetBranchStatus("genLepFromTau_phi"                              , 0); fChain ->SetBranchAddress("genLepFromTau_phi"                              , genLepFromTau_phi                               , &b_genLepFromTau_phi);
   fChain ->SetBranchStatus("genLepFromTau_mass"                             , 0); fChain ->SetBranchAddress("genLepFromTau_mass"                             , genLepFromTau_mass                              , &b_genLepFromTau_mass);
   fChain ->SetBranchStatus("genLepFromTau_pdgId"                            , 0); fChain ->SetBranchAddress("genLepFromTau_pdgId"                            , genLepFromTau_pdgId                             , &b_genLepFromTau_pdgId);
   fChain ->SetBranchStatus("genLepFromTau_status"                           , 0); fChain ->SetBranchAddress("genLepFromTau_status"                           , genLepFromTau_status                            , &b_genLepFromTau_status);
   fChain ->SetBranchStatus("genLepFromTau_charge"                           , 0); fChain ->SetBranchAddress("genLepFromTau_charge"                           , genLepFromTau_charge                            , &b_genLepFromTau_charge);
   fChain ->SetBranchStatus("genLepFromTau_sourceId"                         , 0); fChain ->SetBranchAddress("genLepFromTau_sourceId"                         , genLepFromTau_sourceId                          , &b_genLepFromTau_sourceId);
   fChain ->SetBranchStatus("GenSusyMScan1"                                  , 0); fChain ->SetBranchAddress("GenSusyMScan1"                                  , &GenSusyMScan1                                  , &b_GenSusyMScan1);
   fChain ->SetBranchStatus("GenSusyMScan2"                                  , 0); fChain ->SetBranchAddress("GenSusyMScan2"                                  , &GenSusyMScan2                                  , &b_GenSusyMScan2);
   fChain ->SetBranchStatus("GenSusyMScan3"                                  , 0); fChain ->SetBranchAddress("GenSusyMScan3"                                  , &GenSusyMScan3                                  , &b_GenSusyMScan3);
   fChain ->SetBranchStatus("GenSusyMScan4"                                  , 0); fChain ->SetBranchAddress("GenSusyMScan4"                                  , &GenSusyMScan4                                  , &b_GenSusyMScan4);
   fChain ->SetBranchStatus("nLHEweight"                                     , 0); fChain ->SetBranchAddress("nLHEweight"                                     , &nLHEweight                                     , &b_nLHEweight);
   fChain ->SetBranchStatus("LHEweight_wgt"                                  , 0); fChain ->SetBranchAddress("LHEweight_wgt"                                  , LHEweight_wgt                                   , &b_LHEweight_wgt);
   fChain ->SetBranchStatus("njet"                                           , 1); fChain ->SetBranchAddress("njet"                                           , &njet                                           , &b_njet);
   fChain ->SetBranchStatus("jet_pt"                                         , 1); fChain ->SetBranchAddress("jet_pt"                                         , jet_pt                                          , &b_jet_pt);
   fChain ->SetBranchStatus("jet_eta"                                        , 1); fChain ->SetBranchAddress("jet_eta"                                        , jet_eta                                         , &b_jet_eta);
   fChain ->SetBranchStatus("jet_phi"                                        , 1); fChain ->SetBranchAddress("jet_phi"                                        , jet_phi                                         , &b_jet_phi);
   fChain ->SetBranchStatus("jet_mass"                                       , 1); fChain ->SetBranchAddress("jet_mass"                                       , jet_mass                                        , &b_jet_mass);
   fChain ->SetBranchStatus("jet_btagCSV"                                    , 1); fChain ->SetBranchAddress("jet_btagCSV"                                    , jet_btagCSV                                     , &b_jet_btagCSV);
   fChain ->SetBranchStatus("jet_rawPt"                                      , 1); fChain ->SetBranchAddress("jet_rawPt"                                      , jet_rawPt                                       , &b_jet_rawPt);
   fChain ->SetBranchStatus("jet_mcPt"                                       , 1); fChain ->SetBranchAddress("jet_mcPt"                                       , jet_mcPt                                        , &b_jet_mcPt);
   fChain ->SetBranchStatus("jet_chf"                                        , 1); fChain ->SetBranchAddress("jet_chf"                                        , jet_chf                                         , &b_jet_chf);
   fChain ->SetBranchStatus("jet_FSveto"                                     , 1); fChain ->SetBranchAddress("jet_FSveto"                                     , jet_FSveto                                      , &b_jet_FSveto);
   fChain ->SetBranchStatus("jet_mcFlavour"                                  , 1); fChain ->SetBranchAddress("jet_mcFlavour"                                  , jet_mcFlavour                                   , &b_jet_mcFlavour);
   fChain ->SetBranchStatus("jet_hadronFlavour"                              , 1); fChain ->SetBranchAddress("jet_hadronFlavour"                              , jet_hadronFlavour                               , &b_jet_hadronFlavour);
   fChain ->SetBranchStatus("jet_qgl"                                        , 1); fChain ->SetBranchAddress("jet_qgl"                                        , jet_qgl                                         , &b_jet_qgl);
   fChain ->SetBranchStatus("jet_area"                                       , 1); fChain ->SetBranchAddress("jet_area"                                       , jet_area                                        , &b_jet_area);
   fChain ->SetBranchStatus("jet_id"                                         , 1); fChain ->SetBranchAddress("jet_id"                                         , jet_id                                          , &b_jet_id);
   fChain ->SetBranchStatus("jet_puId"                                       , 1); fChain ->SetBranchAddress("jet_puId"                                       , jet_puId                                        , &b_jet_puId);
   fChain ->SetBranchStatus("weight_lepsf"                                   , 0); fChain ->SetBranchAddress("weight_lepsf"                                   , &weight_lepsf                                   , &b_weight_lepsf);
   fChain ->SetBranchStatus("weight_lepsf_UP"                                , 0); fChain ->SetBranchAddress("weight_lepsf_UP"                                , &weight_lepsf_UP                                , &b_weight_lepsf_UP);
   fChain ->SetBranchStatus("weight_lepsf_DN"                                , 0); fChain ->SetBranchAddress("weight_lepsf_DN"                                , &weight_lepsf_DN                                , &b_weight_lepsf_DN);
   fChain ->SetBranchStatus("weight_btagsf"                                  , 0); fChain ->SetBranchAddress("weight_btagsf"                                  , &weight_btagsf                                  , &b_weight_btagsf);
   fChain ->SetBranchStatus("weight_btagsf_heavy_UP"                         , 0); fChain ->SetBranchAddress("weight_btagsf_heavy_UP"                         , &weight_btagsf_heavy_UP                         , &b_weight_btagsf_heavy_UP);
   fChain ->SetBranchStatus("weight_btagsf_light_UP"                         , 0); fChain ->SetBranchAddress("weight_btagsf_light_UP"                         , &weight_btagsf_light_UP                         , &b_weight_btagsf_light_UP);
   fChain ->SetBranchStatus("weight_btagsf_heavy_DN"                         , 0); fChain ->SetBranchAddress("weight_btagsf_heavy_DN"                         , &weight_btagsf_heavy_DN                         , &b_weight_btagsf_heavy_DN);
   fChain ->SetBranchStatus("weight_btagsf_light_DN"                         , 0); fChain ->SetBranchAddress("weight_btagsf_light_DN"                         , &weight_btagsf_light_DN                         , &b_weight_btagsf_light_DN);
   fChain ->SetBranchStatus("weight_sigtrigsf"                               , 0); fChain ->SetBranchAddress("weight_sigtrigsf"                               , &weight_sigtrigsf                               , &b_weight_sigtrigsf);
   fChain ->SetBranchStatus("weight_dileptrigsf"                             , 0); fChain ->SetBranchAddress("weight_dileptrigsf"                             , &weight_dileptrigsf                             , &b_weight_dileptrigsf);
   fChain ->SetBranchStatus("weight_phottrigsf"                              , 0); fChain ->SetBranchAddress("weight_phottrigsf"                              , &weight_phottrigsf                              , &b_weight_phottrigsf);
   fChain ->SetBranchStatus("weight_pu"                                      , 0); fChain ->SetBranchAddress("weight_pu"                                      , &weight_pu                                      , &b_weight_pu);
   fChain ->SetBranchStatus("weight_isr"                                     , 0); fChain ->SetBranchAddress("weight_isr"                                     , &weight_isr                                     , &b_weight_isr);
   fChain ->SetBranchStatus("weight_scales_UP"                               , 0); fChain ->SetBranchAddress("weight_scales_UP"                               , &weight_scales_UP                               , &b_weight_scales_UP);
   fChain ->SetBranchStatus("weight_scales_DN"                               , 0); fChain ->SetBranchAddress("weight_scales_DN"                               , &weight_scales_DN                               , &b_weight_scales_DN);
   fChain ->SetBranchStatus("weight_pdfs_UP"                                 , 0); fChain ->SetBranchAddress("weight_pdfs_UP"                                 , &weight_pdfs_UP                                 , &b_weight_pdfs_UP);
   fChain ->SetBranchStatus("weight_pdfs_DN"                                 , 0); fChain ->SetBranchAddress("weight_pdfs_DN"                                 , &weight_pdfs_DN                                 , &b_weight_pdfs_DN);
   fChain ->SetBranchStatus("weight_toppt"                                   , 0); fChain ->SetBranchAddress("weight_toppt"                                   , &weight_toppt                                   , &b_weight_toppt);
   fChain ->SetBranchStatus("genRecoil_pt"                                   , 0); fChain ->SetBranchAddress("genRecoil_pt"                                   , &genRecoil_pt                                   , &b_genRecoil_pt);
   fChain ->SetBranchStatus("genTop_pt"                                      , 0); fChain ->SetBranchAddress("genTop_pt"                                      , &genTop_pt                                      , &b_genTop_pt);
   fChain ->SetBranchStatus("genTbar_pt"                                     , 0); fChain ->SetBranchAddress("genTbar_pt"                                     , &genTbar_pt                                     , &b_genTbar_pt);
   Notify();
}

Bool_t MT2Tree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void MT2Tree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t MT2Tree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

void MT2Tree::Loop()
{
//   In a ROOT session, you can do:
//      root> .L MT2Tree.C
//      root> MT2Tree t
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
