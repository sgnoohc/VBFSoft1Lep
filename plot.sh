#!/bin/bash

python ~/login/python/scripts/makeplot.py \
  --plottype plot1d \
  --plotname ~/public_html/test \
  --sighist 'testsig.root ::: '$1' ::: SetLineColor=>2 , SetLineWidth=>2 , SetName=>signal%l, Scale=>36' \
  --bkghist 'testttbar.root ::: '$1' ::: SetFillColor=>7005 , SetLineWidth=>0, SetLineColor=>7005 , SetName=>t#bar{t}%f, Scale=>36' \
  --bkghist 'testwjets.root ::: '$1' ::: SetFillColor=>7003 , SetLineWidth=>0, SetLineColor=>7003 , SetName=>W%f, Scale=>36' \
  $2
