// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

void loop(const char* path, const char* output_tag)
{
  gROOT->ProcessLine(".L MT2TreeSig.C+");
  gROOT->ProcessLine(".L MT2TreeBkg.C+");
  gROOT->ProcessLine(".L AnalysisUtilities.cc+");
  gROOT->ProcessLine(".L MT2TreeLooperSig.C+");

  TChain *chsig = new TChain("mt2");
  chsig->Add(path);
  MT2TreeLooperSig(chsig, true, output_tag, -1);
}
