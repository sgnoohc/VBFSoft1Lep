#!/bin/bash

# vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

#  .
# ..: P. Chang, philip@physics.ucsd.edu

# quick plotting script from the histogram root files

function usage()
{
  echo "Usage :"
  echo ""
  echo "    $0 HISTNAME PLOTTEROPTION SIGNALONLY? [PLOTNAMESUFFIX]"
  echo ""
  echo "  NOTE: If certain options are empty put single quotes to bypass the argument"
  echo ""
  echo ""
  exit
}

# parse the third option to decide whether to draw a plot with only the shape comparison. (each histogram scaled to unity or something alike)
if [ "x$3" == "x" ]; then
  #SIGSCALE="36*13.2*0.04"
  #SIGSCALE="36*0.06"
  #SIGSCALE="36*1000*0.06*0.20"
  SIGSCALE="36*1000*0.06*0.20"
  SCALE=36
  BKGCATEG="bkg"
  BKGCOLORING="Fill"
  LINEWIDTH=0
else
  # if plotting signal only
  SIGSCALE="36*1000*0.06*0.20"
  SCALE="36*1000*0.06*0.20"
  BKGCATEG="sig"
  BKGCOLORING="Line"
  LINEWIDTH=2
fi

# parse 4th, 5h, 6th argument provided (must be provided all at once) plot a signal histogram with the chosen mass point
#MASSPOINT="_100.0_0.0_95.0"
MASSPOINT="_100.0_95.0"
MASSPOINTLEGEND="100"
#if [ "x$4" != "x" ]; then
#  if [ "x$5" != "x" ]; then
#    if [ "x$6" != "x" ]; then
#      MASSPOINT="_$4_$5_$6"
#      MASSPOINTLEGEND="$4-$5-$6"
#    else
#      usage
#    fi
#  else
#    usage
#  fi
#else
#  usage
#fi

# parse whether it is for vbf analysis or not
BKG1="w"
BKG2="nolep"
BKG3="ewkw_vv"
BKG4="dyll"
BKG5="tt"
BKG6="top"
BKGLEGEND1="W"
BKGLEGEND2="Fakes(0l)"
BKGLEGEND3="EWK-W/VV"
BKGLEGEND4="DY(2l)"
BKGLEGEND5="Top(2l)"
BKGLEGEND6="Top(1l)"

# parse 7th argument to decide whether to draw signal only or bkg as well.
if [ "x$3" == "x" ]; then
  python scripts/makeplot.py \
    --plottype plot1dsig \
    --plotname plots/$1$4 \
    --${BKGCATEG}hist 'haddoutput/hist_vbf_'${BKG1}'.root  ::: '$1' ::: Set'${BKGCOLORING}'Color=>7003 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7003 , SetName=>'${BKGLEGEND1}'%f, Scale=>'$SCALE'' \
    --${BKGCATEG}hist 'haddoutput/hist_vbf_'${BKG2}'.root  ::: '$1' ::: Set'${BKGCOLORING}'Color=>7006 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7006 , SetName=>'${BKGLEGEND2}'%f, Scale=>'$SCALE'' \
    --${BKGCATEG}hist 'haddoutput/hist_vbf_'${BKG3}'.root  ::: '$1' ::: Set'${BKGCOLORING}'Color=>7008 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7008 , SetName=>'${BKGLEGEND3}'%f, Scale=>'$SCALE'' \
    --${BKGCATEG}hist 'haddoutput/hist_vbf_'${BKG4}'.root  ::: '$1' ::: Set'${BKGCOLORING}'Color=>7004 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7004 , SetName=>'${BKGLEGEND4}'%f, Scale=>'$SCALE'' \
    --${BKGCATEG}hist 'haddoutput/hist_vbf_'${BKG5}'.root  ::: '$1' ::: Set'${BKGCOLORING}'Color=>7005 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7005 , SetName=>'${BKGLEGEND5}'%f, Scale=>'$SCALE'' \
    --${BKGCATEG}hist 'haddoutput/hist_vbf_'${BKG6}'.root  ::: '$1' ::: Set'${BKGCOLORING}'Color=>7002 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7002 , SetName=>'${BKGLEGEND6}'%f, Scale=>'$SCALE'' \
    --sighist         'haddoutput/hist_vbf_signal.root ::: '${1}${MASSPOINT}'    ::: SetLineColor=>2 , SetLineWidth=>4 , SetName=>100%l, Scale=>normhaddoutput/hist_vbf_signal.root%vbf_rawcutflow'${MASSPOINT}'%bin1%'$SIGSCALE'' \
    $2
    #--sighist         'haddoutput/hist_vbf_signal.root ::: '${1}_vbf_150.0_0.0_145.0'   ::: SetLineColor=>1 , SetLineWidth=>4 , SetName=>150%l, Scale=>normhaddoutput/hist_vbf_signal.root%vbf_rawcutflow_vbf'${MASSPOINT}'%bin1%'$SIGSCALE'' \
    #--sighist         'haddoutput/hist_vbf_signal.root ::: '${1}_vbf_200.0_0.0_195.0'   ::: SetLineColor=>4 , SetLineWidth=>4 , SetName=>'${MASSPOINTLEGEND}'%l, Scale=>normhaddoutput/hist_vbf_signal.root%vbf_rawcutflow_vbf'${MASSPOINT}'%bin1%'$SIGSCALE'' \
    #--sighist         'haddoutput/hist_vbf_signal.root ::: '${1}_vstar${MASSPOINT}'  ::: SetLineColor=>4 , SetLineWidth=>4 , SetName=>'${MASSPOINTLEGEND}'%l, Scale=>normhaddoutput/hist_vbf_signal.root%vbf_rawcutflow_vstar'${MASSPOINT}'%bin1%'$SIGSCALE'' \
    #--sighist         'haddoutput/hist_vbf_signal.root ::: '${1}_strong${MASSPOINT}' ::: SetLineColor=>1 , SetLineWidth=>4 , SetName=>'${MASSPOINTLEGEND}'%l, Scale=>normhaddoutput/hist_vbf_signal.root%vbf_rawcutflow_strong'${MASSPOINT}'%bin1%'$SIGSCALE'' \
    #--sighist         'haddoutput/hist_signal.root    ::: '$1${MASSPOINT}' ::: SetLineColor=>2 , SetLineWidth=>4 , SetName=>'${MASSPOINTLEGEND}'%l, Scale=>'$SIGSCALE'' \
else
  python scripts/makeplot.py \
    --plottype plot1d \
    --plotname plots/${1}_sigonly${4} \
    --sighist 'haddoutput/hist_vbf_signal.root ::: '${1}${MASSPOINT}'     ::: SetLineColor=>2 , SetLineWidth=>4 , SetName=>'${MASSPOINTLEGEND}'%l, Scale=>normhaddoutput/hist_vbf_signal.root%vbf_rawcutflow'${MASSPOINT}'%bin1%'$SIGSCALE'' \
    --sighist 'haddoutput/hist_vbf_signal.root ::: '${1}_qcd${MASSPOINT}' ::: SetLineColor=>4 , SetLineWidth=>4 , SetName=>'${MASSPOINTLEGEND}'%l, Scale=>normhaddoutput/hist_vbf_signal.root%vbf_rawcutflow_qcd'${MASSPOINT}'%bin1%'$SIGSCALE'' \
    --bkghist 'haddoutput/hist_vbf_signal.root ::: '${1}${MASSPOINT}' ::: SetLineColor=>2 , SetLineWidth=>4 , SetName=>'${MASSPOINTLEGEND}'%l, Scale=>normhaddoutput/hist_vbf_signal.root%vbf_rawcutflow'${MASSPOINT}'%bin1%'$SIGSCALE'' \
    $2
    #--sighist 'haddoutput/hist_vbf_signal.root ::: '${1}_100.0_100.0_90.0' ::: SetLineColor=>3 , SetLineWidth=>4 , SetName=>'${MASSPOINTLEGEND}'%l, Scale=>normhaddoutput/hist_vbf_signal.root%vbf_rawcutflow_vbf'${MASSPOINT}'%bin1%'$SIGSCALE'' \
fi

#eof
