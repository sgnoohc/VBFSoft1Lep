#!/bin/bash

# vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

#  .
# ..: P. Chang, philip@physics.ucsd.edu

if [ "x${1}" == "x" ]; then
  echo "Usage:"
  echo ""
  echo "    $0 MINIAOD_FILE_PATH"
  echo ""
  exit
fi

echo "scanning ... "
root -l -b -q scripts/print_susy_ewkino_masses.C\(\"$1\"\) 1> scripts/fullscan.txt 2> /dev/null
awk '!seen[$0]++' scripts/fullscan.txt | sort -g > scripts/scan.txt
rm scripts/fullscan.txt
echo "done! see the result via"
echo "  $ cat scripts/scan.txt"
#eof
