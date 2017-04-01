// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

{
  gROOT->ProcessLine(".L MT2TreeSig.C+");
  gROOT->ProcessLine(".L MT2TreeBkg.C+");
  gROOT->ProcessLine(".L AnalysisUtilities.cc+");
  gROOT->ProcessLine(".L MT2TreeLooperSig.C+");
  gROOT->ProcessLine(".L MT2TreeLooperBkg.C+");

  TChain *chsig = new TChain("mt2");
  chsig->Add("signal.root");
  MT2TreeLooperSig(chsig, true, "testsig", -1);

  TChain *chttbar = new TChain("mt2");
  chttbar->Add("softLep-v3_V00-01-10_25ns_miniaodv2/ttsl_mg_lo_top.root");
  MT2TreeLooperBkg(chttbar, true, "testttbar", -1);

  TChain *chwjets = new TChain("mt2");
  chwjets->Add("softLep-v3_V00-01-10_25ns_miniaodv2/wjets_ht100to200.root");
  //chwjets->Add("softLep-v3_V00-01-10_25ns_miniaodv2/wjets_ht200to400.root");
  //chwjets->Add("softLep-v3_V00-01-10_25ns_miniaodv2/wjets_ht1200to2500.root");
  MT2TreeLooperBkg(chwjets, true, "testwjets", -1);
}
