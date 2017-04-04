#!/bin/bash

# vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

#  .
# ..: P. Chang, philip@physics.ucsd.edu

# quick plotting script from the histogram root files

function usage()
{
  echo "Usage :"
  echo ""
  echo "    $0 HISTNAME PLOTTEROPTION NORM? mC1 mN2 mN1 SIGNALONLY?"
  echo ""
  echo "  NOTE: If certain options are empty put single quotes to bypass the argument"
  echo ""
  echo ""
  exit
}

# The plot will be created here http://uaf-7.t2.ucsd.edu/~phchang/test.pdf or http://uaf-7.t2.ucsd.edu/~${USERNAME}/test.pdf
mkdir -p public_html

# parse the third option to decide whether to draw a plot with only the shape comparison. (each histogram scaled to unity or something alike)
if [ "x$3" == "x" ]; then
  SIGSCALE=360
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

# parse 4th, 5h, 6th argument provided (must be provided all at once) plot a signal histogram with the chosen mass point
MASSPOINT=""
MASSPOINTLEGEND=""
if [ "x$4" != "x" ]; then
  if [ "x$5" != "x" ]; then
    if [ "x$6" != "x" ]; then
      MASSPOINT="_$4_$5_$6"
      MASSPOINTLEGEND="$4-$5-$6"
    else
      usage
    fi
  else
    usage
  fi
else
  usage
fi

# parse 7th argument to decide whether to draw signal only or bkg as well.
if [ "x$7" == "x" ]; then
  python scripts/makeplot.py \
    --plottype plot1d \
    --plotname ~/public_html/test \
    --sighist 'haddoutput/hist_signal.root            ::: '$1${MASSPOINT}' ::: SetLineColor=>2 , SetLineWidth=>4 , SetName=>'${MASSPOINTLEGEND}'%l, Scale=>'$SIGSCALE'' \
    --${BKGCATEG}hist 'haddoutput/hist_z.root         ::: '$1' ::: Set'${BKGCOLORING}'Color=>7004 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7004 , SetName=>Z%f, Scale=>'$SCALE'' \
    --${BKGCATEG}hist 'haddoutput/hist_wjets.root     ::: '$1' ::: Set'${BKGCOLORING}'Color=>7003 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7003 , SetName=>W%f, Scale=>'$SCALE'' \
    --bkghist 'haddoutput/hist_top.root               ::: '$1' ::: Set'${BKGCOLORING}'Color=>7005 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7005 , SetName=>t#bar{t}%f, Scale=>'$SCALE'' \
    --${BKGCATEG}hist 'haddoutput/hist_others.root    ::: '$1' ::: Set'${BKGCOLORING}'Color=>7007 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7007 , SetName=>QCD%f, Scale=>'$SCALE'' \
    $2
else
  python scripts/makeplot.py \
    --plottype plot1d \
    --plotname ~/public_html/test \
    --sighist 'haddoutput/hist_signal.root            ::: '$1${MASSPOINT}' ::: SetLineColor=>2 , SetLineWidth=>4 , SetName=>'${MASSPOINTLEGEND}'%l, Scale=>'$SIGSCALE'' \
    --bkghist 'haddoutput/hist_signal.root            ::: '$1${MASSPOINT}' ::: SetLineColor=>2 , SetLineWidth=>4 , SetName=>'${MASSPOINTLEGEND}'%l, Scale=>'$SIGSCALE'' \
    #--${BKGCATEG}hist 'haddoutput/hist_z.root         ::: '$1' ::: Set'${BKGCOLORING}'Color=>7004 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7004 , SetName=>Z%f, Scale=>'$SCALE'' \
    #--${BKGCATEG}hist 'haddoutput/hist_wjets.root     ::: '$1' ::: Set'${BKGCOLORING}'Color=>7003 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7003 , SetName=>W%f, Scale=>'$SCALE'' \
    #--bkghist 'haddoutput/hist_top.root               ::: '$1' ::: Set'${BKGCOLORING}'Color=>7005 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7005 , SetName=>t#bar{t}%f, Scale=>'$SCALE'' \
    #--${BKGCATEG}hist 'haddoutput/hist_others.root    ::: '$1' ::: Set'${BKGCOLORING}'Color=>7007 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7007 , SetName=>QCD%f, Scale=>'$SCALE'' \
    $2
fi

#eof
