cores=38
mkdir -p output
sh scripts/link_input_files.sh
xargs --arg-file=scripts/testjobs.txt \
      --max-procs=$cores  \
      --replace \
      --verbose \
      /bin/sh -c "{}"
