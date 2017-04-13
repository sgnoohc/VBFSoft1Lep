#!/bin/bash

# vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

#  .
# ..: P. Chang, philip@physics.ucsd.edu

# quick plotting script from the histogram root files

function usage()
{
  echo "Usage :"
  echo ""
  echo "    $0 HISTNAME mC1 mN2 mN1 [OPTION]"
  echo ""
  echo "  NOTE: If certain options are empty put single quotes to bypass the argument"
  echo ""
  echo ""
  exit
}

# parse the third option to decide whether to draw a plot with only the shape comparison. (each histogram scaled to unity or something alike)
SIGSCALE=norm1
LINEWIDTH=2

# parse 4th, 5h, 6th argument provided (must be provided all at once) plot a signal histogram with the chosen mass point
MASSPOINT=""
MASSPOINTLEGEND=""
if [ "x$2" != "x" ]; then
  if [ "x$3" != "x" ]; then
    if [ "x$4" != "x" ]; then
      MASSPOINT="_$2_$3_$4"
      MASSPOINTLEGEND="$2-$3-$4"
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
python scripts/makeplot.py \
  --plottype plot1d \
  --plotname ~/public_html/test \
  --sighist 'haddoutput/hist_truth_signal.root ::: '$1_vbf${MASSPOINT}'    ::: SetLineColor=>2 , SetLineWidth=>4 , SetName=>'${MASSPOINTLEGEND}'%l, Scale=>'$SIGSCALE'' \
  --sighist 'haddoutput/hist_truth_signal.root ::: '$1_vstar${MASSPOINT}'  ::: SetLineColor=>1 , SetLineWidth=>4 , SetName=>'${MASSPOINTLEGEND}'%l, Scale=>'$SIGSCALE'' \
  --sighist 'haddoutput/hist_truth_signal.root ::: '$1_strong${MASSPOINT}' ::: SetLineColor=>4 , SetLineWidth=>4 , SetName=>'${MASSPOINTLEGEND}'%l, Scale=>'$SIGSCALE'' \
  --bkghist 'haddoutput/hist_truth_signal.root ::: '$1_vbf${MASSPOINT}'    ::: SetLineColor=>2 , SetLineWidth=>4 , SetName=>'${MASSPOINTLEGEND}'%l, Scale=>'$SIGSCALE'' \
  $5

#eof
