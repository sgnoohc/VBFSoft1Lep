cores=77
mkdir -p output
sh scripts/link_input_files.sh
xargs --arg-file=scripts/jobs.txt \
      --max-procs=$cores  \
      --replace \
      --verbose \
      /bin/sh -c "{}"
