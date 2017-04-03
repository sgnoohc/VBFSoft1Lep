// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

//
// A short macro to read miniAOD directly and access truth information
//

// Protect headers from CINT getting confused when compiling with 'root -l macro.C+'
#if !defined(__CINT__) && !defined(__MAKECINT__)

// CMSSW
#include "DataFormats/FWLite/interface/Handle.h"
#include "DataFormats/FWLite/interface/Event.h"

// ROOT
#include "TFile.h"

#endif

void print_susy_particle_masses()
{

  // Open up an AOD file
  //TFile file("/home/users/fgolf/lhe/vbf/0215FD4B-42C0-E611-947F-10983627C3CE.root");
  //TFile file("/home/users/phchang/analyses/vbfsusysoft1lep/samples/miniaod/higgsinos/MSSM-higgsino_no1l_2lfilter.root");
  TFile file("/home/users/phchang/analyses/vbfsusysoft1lep/samples/miniaod/higgsinos/SMS-N2C1-higgsino.root");

  // Create an event instance
  fwlite::Event ev(&file);

  // Loop over the event
  for (ev.toBegin(); !ev.atEnd(); ++ev)
  {

    // NOTE: how to retreieve event data
    // When you see a name like the following from TBrowser:
    //
    //   "recoGenParticles_prunedGenParticles__PAT.",
    //    ~~~~~~~~~~~~~~~^ ~~~~~~~~~~~~~~~~~~
    //      Handle Name  |   Label Name
    //                   |
    //                  (ends with 's', therefore it's a vector)
    //
    // the first is the "Handle" name, the second is the "Label" name

    // Create a handle to access the data in the event.
    // Here the "Handle" part of the data I am accessing is used
    // In this case, "recoGenParticles" mean "std::vector<reco::GenParticle>"
    fwlite::Handle<std::vector<reco::GenParticle> > objs;

    // Retrieve the specific data using label.
    // The label name was "prunedGenParticles"
    objs.getByLabel(ev, "prunedGenParticles");

    // Now can access data
    // Testing whether I can access via "size" function of the vector
    std::cout << " size " << objs.ptr()->size() << std::endl;

    // Retrieve the pointer
    const std::vector<reco::GenParticle> * truth_particles = objs.ptr();

    // Create an iterator to loop over the vector gen particles
    std::vector<reco::GenParticle>::const_iterator it = truth_particles->begin();

    // Looping over the vector
    for (; it != truth_particles->end(); ++it)
    {

      // Retreive the particle
      reco::GenParticle truth_particle = *it;

      // Print the pdgId and status
      //std::cout << " pdgId " << truth_particle.pdgId() << " status " << truth_particle.status() << std::endl;

      // Print only status = 1 particles
      if (abs(truth_particle.pdgId()) > 1000000 && (truth_particle.status() == 22 || truth_particle.status() == 1))
        std::cout << " pdgId " << truth_particle.pdgId() << " status " << truth_particle.status() << " mass " << truth_particle.mass() << std::endl;
    }

    // break after first event for simplicity
    //break;
  }

}
