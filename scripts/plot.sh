#!/bin/bash

python ~/login/python/scripts/makeplot.py \
  --plottype plot1d \
  --plotname ~/public_html/test \
  --sighist 'testsig.root ::: '$1' ::: SetLineColor=>2 , SetLineWidth=>2 , SetName=>signal%l, Scale=>36' \
  --bkghist 'hist_tt.root ::: '$1' ::: SetFillColor=>7005 , SetLineWidth=>0, SetLineColor=>7005 , SetName=>t#bar{t}%f, Scale=>36' \
  --bkghist 'hist_dyjetsll.root ::: '$1' ::: SetFillColor=>7004 , SetLineWidth=>0, SetLineColor=>7004 , SetName=>Z%f, Scale=>36' \
  --bkghist 'hist_wjets.root ::: '$1' ::: SetFillColor=>7003 , SetLineWidth=>0, SetLineColor=>7003 , SetName=>W%f, Scale=>36' \
  --bkghist 'hist_qcd.root ::: '$1' ::: SetFillColor=>7002 , SetLineWidth=>0, SetLineColor=>7002 , SetName=>QCD%f, Scale=>36' \
  --bkghist 'hist_gjet.root ::: '$1' ::: SetFillColor=>7001 , SetLineWidth=>0, SetLineColor=>7001 , SetName=>gjet%f, Scale=>36' \
  --bkghist 'hist_singletop.root ::: '$1' ::: SetFillColor=>7005 , SetLineWidth=>0, SetLineColor=>7005 , SetName=>t%f, Scale=>36' \
  --bkghist 'hist_zinv.root ::: '$1' ::: SetFillColor=>7004 , SetLineWidth=>0, SetLineColor=>7004 , SetName=>Zinv%f, Scale=>36' \
  --bkghist 'hist_diboson.root ::: '$1' ::: SetFillColor=>7007 , SetLineWidth=>0, SetLineColor=>7007 , SetName=>diboson%f, Scale=>36' \
  $2

#hist_diboson.root
#hist_dyjetsll.root
#hist_gjet.root
#hist_qcd.root
#hist_singletop.root
#hist_tt.root
#hist_wjets.root
#hist_zinv.root
