#include "AnalysisUtilities.h"

//#################################################################################################
// TOC
//   + PlotUtil namespace
//
//#################################################################################################

namespace AnalysisUtilities
{

  //#################################################################################################
  //
  //
  // Plotting Utilities
  //
  //
  //#################################################################################################
  namespace PlotUtil
  {

    //################################################################################################
    // Plot 1D histogram. If a histogram doesn't exist book first and fill.
    //
    void plot1D(
        string name,
        float xval,
        double weight,
        Hist1D_DB &allhistos,
        string title,
        int numbinsx,
        float xmin,
        float xmax)
    {
      // If no title given, set title to name
      if (title == "") title = name;

      // Find whether a histogram with the name already exists
      map<string, TH1*>::iterator iter= allhistos.find(name);

      // If the histogram is not found, make a new one
      if(iter == allhistos.end())
      {
        TH1D* currentHisto= new TH1D(name.c_str(), title.c_str(), numbinsx, xmin, xmax);
        currentHisto->Sumw2();
        currentHisto->SetDirectory(0);
        currentHisto->Fill(xval, weight);
        allhistos.insert(pair<string, TH1D*> (name,currentHisto) );
      }
      // exists already, so just fill it
      else
      {
        (*iter).second->Fill(xval, weight);
      }

      return;
    }

    //################################################################################################
    // Plot 1D histogram. If a histogram doesn't exist book first and fill.
    //
    void savePlots(Hist1D_DB &h_1d, const char* outfilename)
    {

      // Create a TFile
      TFile outfile(outfilename,"RECREATE") ;

      // Print the info that I am saving to the file
      printf("[AnalysisUtilities::PlotUtil::savePlots] Saving histograms to %s\n", outfilename);

      // Loop over the histograms
      Hist1D_DB::iterator it1d;
      for (it1d = h_1d.begin(); it1d!=h_1d.end(); it1d++)
      {
        // save the histograms
        it1d->second->Write();
        delete it1d->second;
      }

      // Write to file and close
      outfile.Write();
      outfile.Close();

      return;
    }
  }

  //#################################################################################################
  //
  //
  // Printing Utilities
  //
  //
  //#################################################################################################
  namespace PrintUtilities
  {

    //#############################################################################
    // printf replacement
    //
    void print(TString msg, int flush_before, int flush_after)
    {
      if (flush_before) printf("\n");
      printf("AnaUtil:: %s\n", msg.Data());
      if (flush_after) printf("\n");
      fflush(stdout);
    }

    //#############################################################################
    // Warning
    //
    void warning(TString msg)
    {
      print("WARNING - "+msg+".\n");
    }


    //#############################################################################
    // Error & exit
    //
    void error(TString msg, int is_error)
    {
      if (!is_error)
        return;
      //exit();
      print("ERROR - "+msg+", exiting.\n");
      abort();
    }

    //#############################################################################
    // Fun start (from TM Hong's BaBar days)
    //
    void start(int q, int sleep_time)
    {
      if (q)
        return;

      print(" _");
      print("/\\\\");
      print("\\ \\\\  \\__/ \\__/");
      print(" \\ \\\\ (oo) (oo)  Here we come!");
      print("  \\_\\\\/~~\\_/~~\\_");
      print(" _.-~===========~-._");
      print("(___________________)");
      print("      \\_______/");
      print();
      print("System info:");
      gSystem->Exec("hostname");
      gSystem->Exec("uname -a");
      gSystem->Exec("date");
      gSystem->Exec("whoami");
      gSystem->Exec("pwd");
      fflush(stdout);
      if (sleep_time>0)
        sleep(sleep_time);
    }

  //#############################################################################
  // Fun message
  //
  void announce(TString msg, Int_t q)
  {
    if (q)
      return;

    // Random
    srand(time(NULL));      // Init rand seed
    Int_t   r = rand()%10+1;// Generate rand number
    Int_t   moose = r>4 ? 1 : 0;

    // Moose type
    TString eyes  = "open";
    if      (r==9) eyes = "closed";
    else if (r==8) eyes = "dead";
    else if (r==7) eyes = "small";
    else if (r==7) eyes = "sunny";
    else if (r==6) eyes = "calc";
    else if (r==4) eyes = "crazy";
    else if (r==3) eyes = "vampire";
    else if (r==2) eyes = "rich";
    else if (r==1) eyes = "sick";
    print();
    if      (msg.Length()>0) print("________________________________________");
    if      (msg.Length()>0) print(msg);
    if      (msg.Length()>0) print("--O-------------------------------------");
    if      (moose)          print("  O    \\_\\_    _/_/");
    if      (moose)          print("   O       \\__/");
    else                     print("   O       ^__^");
    if      (eyes=="open")   print("    o      (oo)\\_______");
    else if (eyes=="closed") print("    o      (==)\\_______");
    else if (eyes=="dead")   print("    o      (xx)\\_______");
    else if (eyes=="small")  print("    o      (..)\\_______");
    else if (eyes=="sunny")  print("    o      (66)\\_______");
    else if (eyes=="calc")   print("    o      (00)\\_______");
    else if (eyes=="crazy")  print("    o      (**)\\_______");
    else if (eyes=="vampire")print("    o      (@@)\\_______");
    else if (eyes=="rich")   print("    o      ($$)\\_______");
    else if (eyes=="sick")   print("    o      (++)\\_______");
    if (true)                print("     o     (__)\\       )\\/\\");
    if      (eyes=="dead")   print("            U  ||----w |");
    else if (eyes=="crazy")  print("            U  ||----w |");
    else if (eyes=="sick")   print("            U  ||----w |");
    else if (eyes=="vampire")print("            VV ||----w |");
    else                     print("               ||----w |");
    if (true)                print("               ||     ||");
    print();
    sleep(1);
  }

    //#############################################################################
    // Fun exit (from TM Hong's BaBar days)
    //
    void exit(int q)
    {
      if (q)
        return;
      print();
      print("   \\__/    \\__/");
      print("   (oo)    (oo)");
      print("(\\//~~\\\\  //~~\\\\");
      print(" \\/\\__//  \\\\__//\\");
      print("   ||||    ||\\\\ Who cares!");
      print("__ |||| __ |||| ___");
      print("  (_)(_)  (_)(_)");
      print();
    }

  }

  //#################################################################################################
  //
  //
  // Event Looping Utilities
  //
  //
  //#################################################################################################
  namespace LoopUtilities
  {

    // Total number of events in the input
    unsigned int max_nevents               = 0;
    unsigned int total_nevents             = 0;
    unsigned int current_ttree_max_nevents = 0;
    unsigned int current_ttree_event_index = 0;
    unsigned int total_nevents_processed   = 0;
    double fraction_of_booked_nevents      = 1;
    TObjArray* list_of_input_files         = 0;
    TChain* current_tchain                 = 0;
    TFile* current_tfile                   = 0;
    TTree* current_ttree                   = 0;
    TObjArrayIter* file_iter               = 0;
    TStopwatch my_timer;
    int bar_id                             = 0;
    int print_rate                         = 432;

    //################################################################################################
    // Get current ttree from the current file
    //
    TTree* getCurrentTTree()
    {
      if (current_ttree)
        return current_ttree;
      else
        PrintUtilities::error("current_ttree not set!");
      return 0;
    }

    //################################################################################################
    // Get current tfile
    //
    TFile* getCurrentTFile()
    {
      if (current_tfile)
        return current_tfile;
      else
        PrintUtilities::error("current_tfile not set!");
      return 0;
    }

    //################################################################################################
    // Get current tfile
    //
    TChain* getCurrentTChain()
    {
      if (current_tchain)
        return current_tchain;
      else
        PrintUtilities::error("current_tchain not set!");
      return 0;
    }

    //################################################################################################
    // Load current ttree from current tfile by TFile::Get method via name
    //
    void loadCurrentTTreeWithName(const char* treename)
    {

      current_ttree = (TTree*) getCurrentTFile()->Get(treename);

      if (!current_ttree)
      {
        PrintUtilities::warning("failed to retrieve the TTree from TFile");
        PrintUtilities::warning(TString::Format("TFile = %s", getCurrentTFile()->GetName()));
        PrintUtilities::warning(TString::Format("TTree = %s", treename));
        PrintUtilities::error("check the ttree name or tfile");
      }
      else
      {
        //current_ttree->Print("all");
      }
    }

    //################################################################################################
    // Set total number of events from the given TChain
    //
    void loadTotalNEvents()
    {
      total_nevents = getCurrentTChain()->GetEntries();
      return;
    }

    //################################################################################################
    // Set total number of ttree events
    //
    void setCurrentTTreeMaxNEvents()
    {
      current_ttree_max_nevents = getCurrentTTree()->GetEntries();
    }

    //################################################################################################
    // Set Loop conditions such as total number of events and files to loop over
    //
    void resetLoopCondition(TChain* chain, int nevents)
    {
      setCurrentTChain(chain);
      loadTotalNEvents();
      setMaxNEvents(nevents);
      loadFractionOfBookedNEvents();
      loadListOfFiles();
      loadFileIter();
      resetCurrentTTreeEventIndex();
      resetTotalNEventsProcessed();
      initProgressBar();
      return;
    }

    //################################################################################################
    // Reset loop condition for the TTree
    //
    void resetCurrentTTreeLoopCondition()
    {
      resetCurrentTTreeEventIndex();
      loadCurrentTTreeEvent();
    }

    //################################################################################################
    // Set TIter instance from list_of_input_files
    //
    void loadFileIter()
    {
      //PrintUtilities::print("LoopUtilities::loadFileIter() loaded file iterator from list of input files");
      if (!list_of_input_files)
        loadListOfFiles();
      file_iter = new TObjArrayIter(list_of_input_files);
    }

    //################################################################################################
    // Reset previous file that was being looped over
    //
    void resetPreviousFile()
    {
      current_tfile = 0; // TODO: Memory leak!!!!!!!
    }

    //################################################################################################
    // Go to next file in iteration. Return true, if the file is good and we should loop over
    //
    bool nextFile()
    {

      resetPreviousFile();

      if (!file_iter)
        PrintUtilities::error("file_iter not set but you are trying to access the next file");

      // Get the TChain element from TObjArrayIter
      TFile* file_elem = (TFile*) file_iter->Next(); // file_iter returns not exactly TFile....

      // If the file element exists in the TChain we open and process
      if (file_elem)
      {
        // Get the file path
        const char* filepath = file_elem->GetTitle();

        // Set the TFile
        setCurrentTFileByPath(filepath);

        // Announce
        PrintUtilities::announce(TString::Format("Working on file = %s", getCurrentTFile()->GetName()));

        return 1;
      }
      else
      {

        // Announce that we are done with this chain
        PrintUtilities::print("Done with all files in this chain");

        return 0;
      }

    }

    //################################################################################################
    // Go to next file in the event and load the ttree with the name of user's choice
    //
    bool nextFileAndLoadTTreeWithName(const char* treename)
    {
      bool is_next_file_good = nextFile();
      if (is_next_file_good)
      {
        loadCurrentTTreeWithName(treename);
        resetCurrentTTreeLoopCondition();
        return 1;
      }
      else
      {
        return 0;
      }
    }

    //################################################################################################
    // Load current ttree's event
    //
    int loadCurrentTTreeEvent()
    {
      if (!current_ttree)
        PrintUtilities::error("current ttree not set!");
      return current_ttree->LoadTree(current_ttree_event_index);
    }

    //################################################################################################
    // Go to next event in the ttree
    //
    bool nextEvent()
    {
      int loadresult = loadCurrentTTreeEvent();
      incrementCurrentTTreeEventIndex();
      incrementTotalNEventsProcessed();
      printProgressBar();
      if (loadresult == -2) // TTree::LoadTree returns -2 if no entry exist
        return false;
      else
        return true;
    }

    //################################################################################################
    // Is all events processed? i.e. is the total number of events processed >= max_nevents?
    //
    bool isAllEventsProcessed()
    {
      bool is_all_events_processed = total_nevents_processed >= max_nevents;
      if (is_all_events_processed)
        PrintUtilities::print(
          TString::Format("LoopUtilities::isAllEventsProcessed() Processed all events! %d",
            total_nevents_processed).Data()
        );
      return is_all_events_processed;
    }

    //################################################################################################
    int getCurrentTTreeEventIndex()
    {
      return current_ttree_event_index;
    }

    //################################################################################################
    void resetCurrentTTreeEventIndex()
    {
      //PrintUtilities::print("LoopUtilities::resetCurrentTTreeEventIndex(): set current ttree event index to 0");
      current_ttree_event_index = 0;
    }

    //################################################################################################
    void resetTotalNEventsProcessed()
    {
      //PrintUtilities::print("LoopUtilities::resetTotalNEventsProcessed(): set total nevents processed to 0");
      total_nevents_processed = 0;
    }

    //################################################################################################
    void incrementCurrentTTreeEventIndex()
    {
      current_ttree_event_index ++;
    }

    //################################################################################################
    void incrementTotalNEventsProcessed()
    {
      total_nevents_processed ++;
    }

    //################################################################################################
    void setCurrentTChain(TChain* chain)
    {
      //PrintUtilities::print("LoopUtilities::setCurrentTChain(): set current tchain");
      current_tchain = chain;
    }

    //################################################################################################
    void setCurrentTFile(TFile* file)
    {
      //PrintUtilities::print("LoopUtilities::setCurrentTFile(): set current tfile");
      current_tfile = file;
    }

    //################################################################################################
    void setCurrentTFileByPath(const char* path)
    {
      //PrintUtilities::print("LoopUtilities::setCurrentTFileByPath(): set current tfile");
      current_tfile = new TFile(path);
    }

    //################################################################################################
    void setCurrentTTree(TTree* tree)
    {
      //PrintUtilities::print("LoopUtilities::setCurrentTTree(): set current ttree");
      current_ttree = tree;
    }

    //################################################################################################
    void setMaxNEvents(int nevents)
    {
      if (nevents < 0)
      {
        PrintUtilities::print(TString::Format("LoopUtilities::setMaxNEvents(): The requested nevents < 0. Set max events to %d", total_nevents).Data());
        max_nevents = total_nevents;
      }
      else if (nevents > (int) total_nevents)
      {
        PrintUtilities::print(TString::Format("LoopUtilities::setMaxNEvents(): The requested nevents > total_nevents. Set max events to %d", total_nevents).Data());
        max_nevents = total_nevents;
      }
      else
      {
        PrintUtilities::print(TString::Format("LoopUtilities::setMaxNEvents(): set max events to %d", nevents).Data());
        max_nevents = nevents;
      }
    }

    //################################################################################################
    void loadListOfFiles()
    {
      //PrintUtilities::print("LoopUtilities::loadListOfFiles(): loaded list of files");
      list_of_input_files = getCurrentTChain()->GetListOfFiles();
    }

    //################################################################################################
    // Print progress bar
    //
    void printProgressBar()
    {

      int entry = total_nevents_processed;
      int totalN = max_nevents;

      if (totalN < 20)
        totalN = 20;

      // Progress bar
      if (entry%print_rate == 0)
      {

        // sanity check
        if (entry+1 > totalN)
          PrintUtilities::error("Total number of events processed went over max allowed! Check your loop boundary conditions!!");

        int nbars = entry/(totalN/20);
        Double_t elapsed = my_timer.RealTime();
        Double_t rate;
        if (elapsed!=0)
          rate = entry / elapsed;
        else
          rate = -999;
        Double_t percentage = entry / (totalN * 1.) * 100;
        const int mins_in_hour = 60;
        const int secs_to_min = 60;
        Int_t input_seconds = (totalN-entry)/rate;
        Int_t seconds = input_seconds % secs_to_min;
        Int_t minutes = input_seconds / secs_to_min % mins_in_hour;
        Int_t hours   = input_seconds / secs_to_min / mins_in_hour;

        print_rate = (int) (rate/4.);

        printf("\r");
        if (bar_id%4 == 3) printf("-");
        if (bar_id%4 == 2) printf("/");
        if (bar_id%4 == 1) printf("|");
        if (bar_id%4 == 0) printf("\\");
        printf("|");
        bar_id ++;

        for ( int nb = 0; nb < 20; ++nb )
        {
          if (nb < nbars) printf("=");
          else printf(".");
        }

        printf("| %.1f %% (%d/%d) with  [%d Hz]   ETA %.2d:%.2d:%.2d         ",percentage, entry+1, totalN,  (int)rate, hours, minutes, seconds);
        fflush(stdout);
      }
      else if ( entry == totalN - 1 ) {
        Double_t elapsed = my_timer.RealTime();
        Double_t rate;
        if (elapsed!=0)
          rate = entry / elapsed;
        else
          rate = -999;
        const int mins_in_hour = 60;
        const int secs_to_min = 60;
        Int_t input_seconds = elapsed;
        Int_t seconds = input_seconds % secs_to_min;
        Int_t minutes = input_seconds / secs_to_min % mins_in_hour;
        Int_t hours   = input_seconds / secs_to_min / mins_in_hour;

        printf("\r");
        printf("+");
        printf("|====================");

        //for ( int nb = 0; nb < 20; ++nb )
        //{
        //  printf("=");
        //}

        printf("| %.1f %% (%d/%d) with  [avg. %d Hz]   Total Time: %.2d:%.2d:%.2d         ", 100.0, entry+1, totalN, (int)rate, hours, minutes, seconds);
        fflush(stdout);
        printf("\n");
      }

      my_timer.Start(kFALSE);
    }

    //################################################################################################
    // Init progress bar
    //
    void initProgressBar()
    {
      my_timer.Start();
      bar_id = 0;
    }

    //################################################################################################
    // compute fraction of booked events
    //
    void loadFractionOfBookedNEvents()
    {
      fraction_of_booked_nevents = ((double) max_nevents) / ((double) total_nevents);
      PrintUtilities::print(TString::Format("LoopUtilities::loadFractionOfBookedNEvents(): fraction_of_booked_nevents = %.2f percent", (fraction_of_booked_nevents*100.)).Data());
    }

    //################################################################################################
    // Return the fraction of number of events being processed
    //
    double getFractionOfBookedNEvents()
    {
      return fraction_of_booked_nevents;
    }
  }

  //#################################################################################################
  //
  //
  // Lepton Efficiency Study Utility
  //
  //
  //#################################################################################################
  namespace LepEffStudyUtil
  {

    //################################################################################################
    // Fill histograms to make lepton efficiency study
    //
    void fillEffStudyHisto(
        string study_name,
        PlotUtil::Hist1D_DB& h_1d,
        double probe_el_pt, double probe_el_eta, double probe_el_phi,
        double tag_el_pt  , double tag_el_eta  , double tag_el_phi  ,
        bool pass,
        vector<double> pt_bin_edges,
        vector<double> eta_bin_edges
        )
    {

      // Compute the dilepton 4-vector
      TLorentzVector probe_el_tlv;
      TLorentzVector tag_el_tlv;
      TLorentzVector dilep_tlv;
      probe_el_tlv.SetPtEtaPhiM(probe_el_pt , probe_el_eta , probe_el_phi , 0);
      tag_el_tlv  .SetPtEtaPhiM(tag_el_pt   , tag_el_eta   , tag_el_phi   , 0);
      dilep_tlv = probe_el_tlv + tag_el_tlv;

      // Compute dilepton p4 quantities
      float dilep_pt   = dilep_tlv.Pt();
      float dilep_eta  = dilep_tlv.Eta();
      float dilep_phi  = dilep_tlv.Phi();
      float dilep_mass = dilep_tlv.M();

      // Histogram prefix
      string denom_prefix = "h_" + study_name + "_denom_";
      string numer_prefix = "h_" + study_name + "_numer_";

      // Book histograms first and later, loop fast

      // Nested for loop (loop up to size()-1)
      for (unsigned int ipt = 0; ipt < pt_bin_edges.size() - 1; ipt++)
      {

        // Retrieve the bin boundaries
        double pt_bin_low_edge  = pt_bin_edges.at(ipt);
        double pt_bin_high_edge = pt_bin_edges.at(ipt+1);
        for (unsigned int ieta = 0; ieta < eta_bin_edges.size() - 1; ieta++)
        {

          // Retrieve the bin boundaries
          double eta_bin_low_edge  = eta_bin_edges.at(ieta);
          double eta_bin_high_edge = eta_bin_edges.at(ieta+1);

          // Histograms will be binned by the probe electron
          // Check that the probe is in phase-space. If not, continue
          bool isProbeInPtPhaseSpace  = (probe_el_pt  >= pt_bin_low_edge  && probe_el_pt  < pt_bin_high_edge);
          bool isProbeInEtaPhaseSpace = (probe_el_eta >= eta_bin_low_edge && probe_el_eta < eta_bin_high_edge);
          if (!isProbeInEtaPhaseSpace || !isProbeInPtPhaseSpace)
            continue;

          // Phase-space prefix
          string ps_prefix = TString::Format("pt%d_%d_eta%d_%d_",
                                             (int) (pt_bin_low_edge   * 1000),  // In MeV, very likely I can make this an integer
                                             (int) (pt_bin_high_edge  * 1000),  // In MeV, very likely I can make this an integer
                                             (int) (eta_bin_low_edge  * 100 ),  // Multiplied by 100 will make it an integer
                                             (int) (eta_bin_high_edge * 100 )   // Multiplied by 100 will make it an integer
                                            ).Data();
          std::replace(ps_prefix.begin(), ps_prefix.end(), '-', 'm');

          // Numerator
          PlotUtil::plot1D(denom_prefix+ps_prefix+"dilep_pt"     , dilep_pt     , 1 , h_1d , "pT [GeV]"   , 150 , 0    , 150 );
          PlotUtil::plot1D(denom_prefix+ps_prefix+"dilep_eta"    , dilep_eta    , 1 , h_1d , "#eta"       , 150 , -3   , 3   );
          PlotUtil::plot1D(denom_prefix+ps_prefix+"dilep_phi"    , dilep_phi    , 1 , h_1d , "#phi"       , 150 , -3.5 , 3.5 );
          PlotUtil::plot1D(denom_prefix+ps_prefix+"dilep_mass"   , dilep_mass   , 1 , h_1d , "m_ll [GeV]" , 180 , 60   , 120 );

          // Denominator
          if (pass)
          {
            PlotUtil::plot1D(numer_prefix+ps_prefix+"dilep_pt"   , dilep_pt     , 1 , h_1d , "pT [GeV]"   , 150 , 0    , 150 );
            PlotUtil::plot1D(numer_prefix+ps_prefix+"dilep_eta"  , dilep_eta    , 1 , h_1d , "#eta"       , 150 , -3   , 3   );
            PlotUtil::plot1D(numer_prefix+ps_prefix+"dilep_phi"  , dilep_phi    , 1 , h_1d , "#phi"       , 150 , -3.5 , 3.5 );
            PlotUtil::plot1D(numer_prefix+ps_prefix+"dilep_mass" , dilep_mass   , 1 , h_1d , "m_ll [GeV]" , 180 , 60   , 120 );
          }
        }
      }

      return;
    }
  }

}


//eof
