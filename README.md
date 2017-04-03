
## VBF Soft 1 Lepton analysis code

Repository to study VBF soft 1 lep analysis possibility.

### To run the code

Must be ran on uaf as it uses input ntuples from uaf.

Set up vanilla ROOT (tested with 6.06).

    sh scripts/link_input_files.sh
    make clean
    make -j4
    sh scripts/xargs_run.sh
    sh scripts/hadd.sh
    ls haddoutput/* # to see the outputs
    sh scripts/plot.sh cutflow # to create cutflow plot to ~/public_html/test.pdf

### Ntuples

Slightly outdated MT2 soft lepton ntuples.

    /nfs-6/userdata/mt2/softLep-v3_V00-01-10_25ns_miniaodv2

Mark Derdzinsky has a new version somewhere.

One signal sample can be found here:

    /home/users/phchang/analyses/vbfsusysoft1lep/analysis/VBFSoft1Lep/signal.root

To produce the above signal sample the following were used

    /home/users/phchang/analyses/vbfsusysoft1lep/cms3ntuplemaker-v08-00-16
    /home/users/phchang/analyses/vbfsusysoft1lep/babymaker-MT2Analysis-soft
