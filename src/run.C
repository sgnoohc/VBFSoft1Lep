// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

#include "MT2TreeLooperSig.C"

void run(const char* path="", bool is_signal=true)
{
  gROOT->ProcessLine(".L MT2TreeSig.C+");
  gROOT->ProcessLine(".L MT2TreeBkg.C+");
  gROOT->ProcessLine(".L AnalysisUtilities.cc+");
  gROOT->ProcessLine(".L MT2TreeLooperSig.C+");
  gROOT->ProcessLine(".L MT2TreeLooperBkg.C+");

  TChain *chsig = new TChain("mt2");
  chsig->Add("signal.root");
  MT2TreeLooperSig(chsig, true, "testsig", -1);

  //TChain *chttbar = new TChain("mt2");
  //chttbar->Add("softLep-v3_V00-01-10_25ns_miniaodv2/ttsl_mg_lo_top.root");
  //MT2TreeLooperBkg(chttbar, true, "testttbar", -1);

  //TChain *chwjets = new TChain("mt2");
  //chwjets->Add("softLep-v3_V00-01-10_25ns_miniaodv2/wjets_ht100to200.root");
  ////chwjets->Add("softLep-v3_V00-01-10_25ns_miniaodv2/wjets_ht200to400.root");
  ////chwjets->Add("softLep-v3_V00-01-10_25ns_miniaodv2/wjets_ht1200to2500.root");
  //MT2TreeLooperBkg(chwjets, true, "testwjets", -1);
}
//softLep-v3_V00-01-10_25ns_miniaodv2/dyjetsll_ht100to200.root
//softLep-v3_V00-01-10_25ns_miniaodv2/dyjetsll_ht200to400.root
//softLep-v3_V00-01-10_25ns_miniaodv2/dyjetsll_ht400to600.root
//softLep-v3_V00-01-10_25ns_miniaodv2/dyjetsll_ht600toInf.root
//softLep-v3_V00-01-10_25ns_miniaodv2/dyjetsll_lowMll_ht100to200.root
//softLep-v3_V00-01-10_25ns_miniaodv2/dyjetsll_lowMll_ht200to400.root
//softLep-v3_V00-01-10_25ns_miniaodv2/dyjetsll_lowMll_ht400to600.root
//softLep-v3_V00-01-10_25ns_miniaodv2/dyjetsll_lowMll_ht600toInf.root
//softLep-v3_V00-01-10_25ns_miniaodv2/gjet_ht100to200.root
//softLep-v3_V00-01-10_25ns_miniaodv2/gjet_ht200to400.root
//softLep-v3_V00-01-10_25ns_miniaodv2/gjet_ht200to400_1.root
//softLep-v3_V00-01-10_25ns_miniaodv2/gjet_ht400to600.root
//softLep-v3_V00-01-10_25ns_miniaodv2/gjet_ht600toInf.root
//softLep-v3_V00-01-10_25ns_miniaodv2/qcd_ht1000to1500.root
//softLep-v3_V00-01-10_25ns_miniaodv2/qcd_ht100to200.root
//softLep-v3_V00-01-10_25ns_miniaodv2/qcd_ht100to200_1.root
//softLep-v3_V00-01-10_25ns_miniaodv2/qcd_ht100to200_2.root
//softLep-v3_V00-01-10_25ns_miniaodv2/qcd_ht100to200_3.root
//softLep-v3_V00-01-10_25ns_miniaodv2/qcd_ht100to200_4.root
//softLep-v3_V00-01-10_25ns_miniaodv2/qcd_ht100to200_5.root
//softLep-v3_V00-01-10_25ns_miniaodv2/qcd_ht1500to2000.root
//softLep-v3_V00-01-10_25ns_miniaodv2/qcd_ht2000toInf.root
//softLep-v3_V00-01-10_25ns_miniaodv2/qcd_ht200to300.root
//softLep-v3_V00-01-10_25ns_miniaodv2/qcd_ht200to300_1.root
//softLep-v3_V00-01-10_25ns_miniaodv2/qcd_ht300to500.root
//softLep-v3_V00-01-10_25ns_miniaodv2/qcd_ht300to500_1.root
//softLep-v3_V00-01-10_25ns_miniaodv2/qcd_ht500to700.root
//softLep-v3_V00-01-10_25ns_miniaodv2/qcd_ht500to700_1.root
//softLep-v3_V00-01-10_25ns_miniaodv2/qcd_ht700to1000.root
//softLep-v3_V00-01-10_25ns_miniaodv2/qcd_ht700to1000_1.root
//softLep-v3_V00-01-10_25ns_miniaodv2/singletop_amcatnlo_4f_schan.root
//softLep-v3_V00-01-10_25ns_miniaodv2/singletop_powheg_4f_tbartchan_l.root
//softLep-v3_V00-01-10_25ns_miniaodv2/singletop_powheg_4f_ttchan_l.root
//softLep-v3_V00-01-10_25ns_miniaodv2/singletop_powheg_5f_tWchan.root
//softLep-v3_V00-01-10_25ns_miniaodv2/singletop_powheg_5f_tbarWchan.root
//softLep-v3_V00-01-10_25ns_miniaodv2/ttdl_mg_lo.root
//softLep-v3_V00-01-10_25ns_miniaodv2/ttg_amcatnlo.root
//softLep-v3_V00-01-10_25ns_miniaodv2/tth_bb_amcatnlo.root
//softLep-v3_V00-01-10_25ns_miniaodv2/tth_nonbb_amcatnlo.root
//softLep-v3_V00-01-10_25ns_miniaodv2/tth_nonbb_amcatnlo_1.root
//softLep-v3_V00-01-10_25ns_miniaodv2/ttsl_mg_lo_tbar.root
//softLep-v3_V00-01-10_25ns_miniaodv2/ttsl_mg_lo_tbar_1.root
//softLep-v3_V00-01-10_25ns_miniaodv2/ttsl_mg_lo_top.root
//softLep-v3_V00-01-10_25ns_miniaodv2/ttsl_mg_lo_top_1.root
//softLep-v3_V00-01-10_25ns_miniaodv2/ttw_lnu_amcatnlo.root
//softLep-v3_V00-01-10_25ns_miniaodv2/ttw_qq_amcatnlo.root
//softLep-v3_V00-01-10_25ns_miniaodv2/ttz_llnunu_amcatnlo.root
//softLep-v3_V00-01-10_25ns_miniaodv2/ttz_qq_amcatnlo.root
//softLep-v3_V00-01-10_25ns_miniaodv2/wjets_ht100to200.root
//softLep-v3_V00-01-10_25ns_miniaodv2/wjets_ht100to200_1.root
//softLep-v3_V00-01-10_25ns_miniaodv2/wjets_ht1200to2500.root
//softLep-v3_V00-01-10_25ns_miniaodv2/wjets_ht200to400.root
//softLep-v3_V00-01-10_25ns_miniaodv2/wjets_ht2500toInf.root
//softLep-v3_V00-01-10_25ns_miniaodv2/wjets_ht400to600.root
//softLep-v3_V00-01-10_25ns_miniaodv2/wjets_ht600to800.root
//softLep-v3_V00-01-10_25ns_miniaodv2/wjets_ht800to1200.root
//softLep-v3_V00-01-10_25ns_miniaodv2/wwlnln_powheg.root
//softLep-v3_V00-01-10_25ns_miniaodv2/wwlnqq_powheg.root
//softLep-v3_V00-01-10_25ns_miniaodv2/wzllln_powheg.root
//softLep-v3_V00-01-10_25ns_miniaodv2/wzllqq_amcnlo.root
//softLep-v3_V00-01-10_25ns_miniaodv2/wzllqq_amcnlo_1.root
//softLep-v3_V00-01-10_25ns_miniaodv2/wzllqq_amcnlo_2.root
//softLep-v3_V00-01-10_25ns_miniaodv2/wzllqq_amcnlo_3.root
//softLep-v3_V00-01-10_25ns_miniaodv2/wzlnnn_amcnlo.root
//softLep-v3_V00-01-10_25ns_miniaodv2/wzlnqq_amcnlo.root
//softLep-v3_V00-01-10_25ns_miniaodv2/wzlnqq_amcnlo_1.root
//softLep-v3_V00-01-10_25ns_miniaodv2/wzlnqq_amcnlo_2.root
//softLep-v3_V00-01-10_25ns_miniaodv2/zinv_ht100to200.root
//softLep-v3_V00-01-10_25ns_miniaodv2/zinv_ht200to400.root
//softLep-v3_V00-01-10_25ns_miniaodv2/zinv_ht400to600.root
//softLep-v3_V00-01-10_25ns_miniaodv2/zinv_ht600toInf.root
//softLep-v3_V00-01-10_25ns_miniaodv2/zzllll_powheg.root
//softLep-v3_V00-01-10_25ns_miniaodv2/zzllnn_powheg.root
//softLep-v3_V00-01-10_25ns_miniaodv2/zzllqq_amcatnlo.root
//softLep-v3_V00-01-10_25ns_miniaodv2/zzllqq_amcatnlo_1.root
//softLep-v3_V00-01-10_25ns_miniaodv2/zzllqq_amcatnlo_2.root
