// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

#include "MT2TreeLooper.h"

MT2Tree mytree;

//______________________________________________________________________________________
int MT2TreeLooper(TChain* chain, TString output_name, int nevents)
{

  // Before the loop set up some configuration, histograms and etc.
  beforeLoop(chain, output_name, nevents);

  // During the event loop process each event one by one
  loop();

  // After the loop is done, save histograms and etc.
  afterLoop();

  return 0;
}

//______________________________________________________________________________________
void beforeLoop(TChain* chain, TString output_name, int nevents)
{

  // Fun start ASCII art
  PrintUtil::start();

  // Initialize configurations for event looping
  LoopUtil::resetLoopCondition(chain, nevents);

}


//______________________________________________________________________________________
void loop()
{

  // Loop over file:ttree -> and loop over events in ttree
  // (usually I only have one file each.. so kinda redundant)
  while (LoopUtil::nextFileAndLoadTTreeWithName("mt2"))
  {

    initMT2Tree();

    // Loop over the TTree
    while (LoopUtil::nextEvent())
    {

      if (LoopUtil::isAllEventsProcessed()) break;

      loadMT2TreeEvent();

      //=================================================================
      // <3 of the code
      // Do whatever you want to in the following function for each event
      //=================================================================
      processMT2TreeEvent();

    } // End TTree loop

  } // End Loop over files
}

//______________________________________________________________________________________
void initMT2Tree()
{
  // Init the Class
  mytree.Init(LoopUtil::getCurrentTTree());
}

//______________________________________________________________________________________
void loadMT2TreeEvent()
{
  mytree.LoadTree(LoopUtil::getCurrentTTreeEventIndex());
  mytree.GetEntry(LoopUtil::getCurrentTTreeEventIndex());
}

//______________________________________________________________________________________
void processMT2TreeEvent()
{
}

//______________________________________________________________________________________
void afterLoop()
{
  // Fun exit
  PrintUtil::exit();
}

//eof
