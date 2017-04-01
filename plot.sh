#!/bin/bash

python ~/login/python/scripts/makeplot.py \
  --plottype plot1d \
  --plotname ~/public_html/test \
  --sighist 'testsig.root ::: '$1' ::: SetLineColor=>2 , SetLineWidth=>2 , SetName=>signal%l, Scale=>norm1' \
  --sighist 'testwjets.root ::: '$1' ::: SetLineColor=>4 , SetLineWidth=>2 , SetName=>W_HT1200to2500%l, Scale=>norm1' \
  --bkghist 'testttbar.root ::: '$1' ::: SetLineColor=>1 , SetLineWidth=>2 , SetName=>ttsl%l, Scale=>norm1' \
  $2
