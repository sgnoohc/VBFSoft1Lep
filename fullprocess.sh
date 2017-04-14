#!/bin/bash

usage ()
{
  echo "Usage: "
  echo ""
  echo "   $0 ANALYSIS_TAG [SKIP MT2TREELOOPER]"
  echo ""
  echo "     provide an analysis_tag (e.g. 'metcutstudy', 'optimization_study_1', etc.)"
  echo ""
  echo ""
  exit
}

if [ "x$1" == "x" ]; then
  usage;
fi

TAG=$(git log --pretty=oneline | head -n1 | awk '{print $1}')
echo $TAG

if [ -d "~/public_html/dump/plots_${1}_${TAG}" ]; then
  echo "ERROR - the output directory of this submission already exists!"
  echo "Did you forget to git commit?"
  echo ""
  usage
fi

if [ "x$2" == "x" ]; then
  make clean; make -j4
  sh scripts/xargs_run.sh
  sh scripts/hadd.sh
  cp -r haddoutput archive/haddoutput_${1}_${TAG}
  cp src/MT2TreeLooper.cxx archive/haddoutput_${1}_${TAG}
fi

# plotting
root -l -b -q scripts/print_plotting_job_commands.C | tail -n+3 > scripts/bulk_plot_jobs.txt
rm -rf plots
rm -rf ~/public_html/dump/plots_${1}_${TAG}
mkdir -p plots
sh scripts/xargs_plot.sh
cp src/MT2TreeLooper.cxx plots/
yes | niceplots plots plots_${1}_${TAG}
chmod 755 -R ~/public_html/dump/plots_${1}_${TAG}
