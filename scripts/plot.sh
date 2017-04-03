#!/bin/bash



if [ "x$3" == "x" ]; then
  SCALE=36
  BKGCATEG="bkg"
  BKGCOLORING="Fill"
  LINEWIDTH=0
else
  SCALE=$3
  BKGCATEG="sig"
  BKGCOLORING="Line"
  LINEWIDTH=2
fi

python ~/login/python/scripts/makeplot.py \
  --plottype plot1d \
  --plotname ~/public_html/test \
  --sighist 'testsig.root                ::: '$1' ::: SetLineColor=>2 , SetLineWidth=>2 , SetName=>signal%l, Scale=>'$SCALE'' \
  --${BKGCATEG}hist 'hist_zinv.root      ::: '$1' ::: Set'${BKGCOLORING}'Color=>4    , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>4    , SetName=>Zinv%f, Scale=>'$SCALE'' \
  --${BKGCATEG}hist 'hist_dyjetsll.root  ::: '$1' ::: Set'${BKGCOLORING}'Color=>7004 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7004 , SetName=>Z%f, Scale=>'$SCALE'' \
  --${BKGCATEG}hist 'hist_wjets.root     ::: '$1' ::: Set'${BKGCOLORING}'Color=>7003 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7003 , SetName=>W%f, Scale=>'$SCALE'' \
  --bkghist 'hist_tt.root                ::: '$1' ::: Set'${BKGCOLORING}'Color=>7005 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7005 , SetName=>t#bar{t}%f, Scale=>'$SCALE'' \
  $2
  #--${BKGCATEG}hist 'hist_qcd.root       ::: '$1' ::: Set'${BKGCOLORING}'Color=>7002 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7002 , SetName=>QCD%f, Scale=>'$SCALE'' \
  #--${BKGCATEG}hist 'hist_gjet.root      ::: '$1' ::: Set'${BKGCOLORING}'Color=>7001 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7001 , SetName=>gjet%f, Scale=>'$SCALE'' \
  #--${BKGCATEG}hist 'hist_singletop.root ::: '$1' ::: Set'${BKGCOLORING}'Color=>7005 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7005 , SetName=>t%f, Scale=>'$SCALE'' \
  #--${BKGCATEG}hist 'hist_diboson.root   ::: '$1' ::: Set'${BKGCOLORING}'Color=>7007 , SetLineWidth=>'${LINEWIDTH}', SetLineColor=>7007 , SetName=>diboson%f, Scale=>'$SCALE'' \

#hist_diboson.root
#hist_dyjetsll.root
#hist_gjet.root
#hist_qcd.root
#hist_singletop.root
#hist_tt.root
#hist_wjets.root
#hist_zinv.root
