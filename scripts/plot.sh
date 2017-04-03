#!/bin/bash

# vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

#  .
# ..: P. Chang, philip@physics.ucsd.edu

# quick plotting script from the histogram root files

# if the third option is provided you can draw a shape comparison only plot
if [ "x$3" == "x" ]; then
  SIGSCALE=5
  SCALE=36
  BKGCATEG="bkg"
  BKGCOLORING="Fill"
  LINEWIDTH=0
else
  SIGSCALE=$3
  SCALE=$3
  BKGCATEG="sig"
  BKGCOLORING="Line"
  LINEWIDTH=2
fi

# The plot will be created here http://uaf-7.t2.ucsd.edu/~phchang/test.pdf or http://uaf-7.t2.ucsd.edu/~${USERNAME}/test.pdf
mkdir -p public_html

python scripts/makeplot.py \
  --plottype plot1d \
  --plotname ~/public_html/test \
  --sighist 'haddoutput/hist_signal.root            ::: '$1' ::: SetLineColor=>2 , SetLineWidth=>2 , SetName=>signal%l, Scale=>'$SIGSCALE'' \
  --${BKGCATEG}hist 'haddoutput/hist_z.root         ::: '$1' ::: Set'${BKGCOLORING}'Color=>7004 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7004 , SetName=>Z%f, Scale=>'$SCALE'' \
  --${BKGCATEG}hist 'haddoutput/hist_wjets.root     ::: '$1' ::: Set'${BKGCOLORING}'Color=>7003 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7003 , SetName=>W%f, Scale=>'$SCALE'' \
  --bkghist 'haddoutput/hist_top.root               ::: '$1' ::: Set'${BKGCOLORING}'Color=>7005 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7005 , SetName=>t#bar{t}%f, Scale=>'$SCALE'' \
  --${BKGCATEG}hist 'haddoutput/hist_others.root    ::: '$1' ::: Set'${BKGCOLORING}'Color=>7007 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7007 , SetName=>QCD%f, Scale=>'$SCALE'' \
  $2

#eof
