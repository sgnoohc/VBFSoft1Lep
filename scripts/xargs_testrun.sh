cores=38
mkdir -p output
xargs --arg-file=scripts/testjobs.txt \
      --max-procs=$cores  \
      --replace \
      --verbose \
      /bin/sh -c "{}"
