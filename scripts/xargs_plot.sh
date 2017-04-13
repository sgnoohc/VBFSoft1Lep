#!/bin/bash

# vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

#  .
# ..: P. Chang, philip@physics.ucsd.edu

cores=40

# filter some jobs
if [ "x${1}" != "x" ]; then
  cat scripts/bulk_plot_jobs.txt | grep $1 > /tmp/bulk_plot_jobs.txt
else
  cat scripts/bulk_plot_jobs.txt > /tmp/bulk_plot_jobs.txt
fi

# run the job in parallel
xargs --arg-file=/tmp/bulk_plot_jobs.txt \
      --max-procs=$cores  \
      --replace \
      --verbose \
      /bin/sh -c "{}"

#eof
