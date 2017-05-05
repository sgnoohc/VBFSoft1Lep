python scripts/make_classfiles.py -t mt2 input/signal.root  -l -c MT2Tree -o mt2tree_obj -n mt2tree
yes | mv MT2Tree.cc src/MT2Tree.cxx
yes | mv MT2Tree.h src/MT2Tree.h
rm ScanChain.C
rm doAll.C
