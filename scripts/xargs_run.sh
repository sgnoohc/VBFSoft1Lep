#!/bin/bash

# vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

#  .
# ..: P. Chang, philip@physics.ucsd.edu

cores=20
mkdir -p output
sh scripts/link_input_files.sh
xargs --arg-file=scripts/jobs.txt \
      --max-procs=$cores  \
      --replace \
      --verbose \
      /bin/sh -c "{}"
#eof
