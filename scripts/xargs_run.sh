#!/bin/bash

# vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

#  .
# ..: P. Chang, philip@physics.ucsd.edu

cores=40

# create output directory if needed
mkdir -p output

# filter some jobs
if [ "x${1}" != "x" ]; then
  cat scripts/jobs.txt | grep $1 > /tmp/jobs.txt
else
  cat scripts/jobs.txt > /tmp/jobs.txt
fi

# link input files if needed
sh scripts/link_input_files.sh

# run the job in parallel
xargs --arg-file=/tmp/jobs.txt \
      --max-procs=$cores  \
      --replace \
      --verbose \
      /bin/sh -c "{}"

#eof
