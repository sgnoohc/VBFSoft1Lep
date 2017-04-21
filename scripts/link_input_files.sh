#!/bin/bash

# vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

#  .
# ..: P. Chang, philip@physics.ucsd.edu

# linking input files to input/
mkdir -p input
cd input
#ln -sf /home/users/phchang/analyses/vbfsusysoft1lep/babymaker-MT2Analysis-soft/MT2Analysis/babymaker signal
#ln -sf /home/users/phchang/analyses/vbfsusysoft1lep/babymaker-MT2Analysis-soft/MT2Analysis/babymaker/unknown_test.root signal.root
#ln -sf /nfs-6/userdata/mt2/softLep-v3_V00-01-10_25ns_miniaodv2
#ln -sf /home/users/phchang/analyses/vbfsusysoft1lep/samples/baby/met100presel_signal
ln -sf /home/users/phchang/analyses/vbfsusysoft1lep/samples/baby/met100presel
ln -sf /home/users/phchang/analyses/vbfsusysoft1lep/samples/baby/signal
cd -

#eof
