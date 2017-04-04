#!/bin/bash

# vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

#  .
# ..: P. Chang, philip@physics.ucsd.edu


# The following creates some separate hadded files
mkdir -p haddoutput
hadd -f haddoutput/hist_dyjetsll.root    output/hist_dyjetsll_*root
hadd -f haddoutput/hist_qcd.root         output/hist_qcd_ht*root
hadd -f haddoutput/hist_gjet.root        output/hist_gjet_ht*root.root
hadd -f haddoutput/hist_tt.root          output/hist_tt*.root.root
hadd -f haddoutput/hist_zinv.root        output/hist_zinv_ht*root.root
hadd -f haddoutput/hist_diboson.root     output/hist_ww*root.root output/hist_wz*root.root output/hist_zz*root.root

# But the following five are what's really used in the plotting
hadd -f haddoutput/hist_top.root         output/hist_tt*.root.root output/hist_singletop_*root.root
hadd -f haddoutput/hist_z.root           output/hist_zinv_ht*root.root output/hist_dyjetsll_*root
hadd -f haddoutput/hist_wjets.root       output/hist_wjets_ht*root.root
hadd -f haddoutput/hist_others.root      output/hist_ww*root.root output/hist_wz*root.root output/hist_zz*root.root output/hist_gjet_ht*root.root output/hist_qcd_ht*root
ln -sf ../output/hist_signal.root.root haddoutput/hist_signal.root

#eof
