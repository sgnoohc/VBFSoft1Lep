#!/bin/bash

# vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

#  .
# ..: P. Chang, philip@physics.ucsd.edu


mkdir -p haddoutput
# The following creates some separate hadded files

# top process with two leptons expected
hadd -f haddoutput/hist_tt.root          output/hist_ttdl_mg_lo.root.root output/hist_ttg_amcatnlo.root.root output/hist_tth_bb_amcatnlo.root.root output/hist_tth_nonbb_amcatnlo.root.root output/hist_tth_nonbb_amcatnlo_1.root.root output/hist_ttw_lnu_amcatnlo.root.root output/hist_ttw_qq_amcatnlo.root.root output/hist_ttz_llnunu_amcatnlo.root.root output/hist_ttz_qq_amcatnlo.root.root

# DY
hadd -f haddoutput/hist_dy.root          output/hist_zinv_ht*root.root output/hist_dyjetsll_*root

# VV
hadd -f haddoutput/hist_vv.root          output/hist_ww*root.root output/hist_wz*root.root output/hist_zz*root.root

# tW
hadd -f haddoutput/hist_tW.root          output/hist_singletop_powheg_5f_tWchan.root.root output/hist_singletop_powheg_5f_tbarWchan.root.root

# single top or ttbar with single lepton chnnael and QCD/g+jet and W+jets
hadd -f haddoutput/hist_fakes.root       output/hist_ttsl_mg_lo_tbar.root.root output/hist_ttsl_mg_lo_tbar_1.root.root output/hist_ttsl_mg_lo_top.root.root output/hist_ttsl_mg_lo_top_1.root.root output/hist_singletop_amcatnlo_4f_schan.root.root output/hist_singletop_powheg_4f_tbartchan_l.root.root output/hist_singletop_powheg_4f_ttchan_l.root.root output/hist_gjet_ht*root.root output/hist_qcd_ht*root output/hist_wjets_ht*root.root

# signal
hadd -f haddoutput/hist_signal.root      output/hist_MSSM*.root.root output/hist_SMS*.root.root

#eof
