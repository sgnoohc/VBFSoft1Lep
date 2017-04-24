// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

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
    // if the histogram exists, return true
    //
    bool plot1D(
        string name,
        float xval,
        double weight,
        Hist_DB &allhistos,
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
        return false;
      }
      // exists already, so just fill it
      else
      {
        (*iter).second->Fill(xval, weight);
        return true;
      }
    }

    //################################################################################################
    // Plot 1D histogram. If a histogram doesn't exist book first and fill. (with variable binning)
    //
    bool plot1D(string name, float xval, double weight, std::map<string, TH1*> &allhistos,
        string title, int numbinsx, const float * xbins)
    {
      // If no title given, set title to name
      if (title=="") title=name;

      // Find whether a histogram with the name already exists
      std::map<string, TH1*>::iterator iter= allhistos.find(name);

      // If the histogram is not found, make a new one.
      if(iter == allhistos.end())
      {
        TH1D* currentHisto= new TH1D(name.c_str(), title.c_str(), numbinsx, xbins);
        currentHisto->Sumw2();
        currentHisto->SetDirectory(0);
        currentHisto->Fill(xval, weight);
        allhistos.insert(std::pair<string, TH1D*> (name,currentHisto) );
        return false;
      }
      else // exists already, so just fill it
      {
        (*iter).second->Fill(xval, weight);
        return true;
      }
    }

    //################################################################################################
    // Plot 1D histogram. If a histogram doesn't exist throw an error
    //
    void plot1D(
        string name,
        float xval,
        double weight,
        Hist_DB &allhistos)
    {

      //// Find whether a histogram with the name already exists
      //map<string, TH1*>::iterator iter= allhistos.find(name);

      //// If the histogram is not found, make a new one
      //if (iter == allhistos.end())
      //{
      //  TString error_msg = TString::Format("PlotUtil::plot1D() trying to fill %s when it doesn't exist", name.c_str());
      //  PrintUtilities::error(error_msg);
      //}
      //// exists already, so just fill it
      //else
      //{
      //  (*iter).second->Fill(xval, weight);
      //}


      allhistos[name]->Fill(xval, weight);

      return;
    }

    //################################################################################################
    // Plot 1D histogram. If a histogram doesn't exist book first and fill.
    // if the histogram exists, return true
    //
    bool plot2D(
        string name,
        float xval,
        float yval,
        double weight,
        Hist_DB &allhistos,
        string title,
        int numbinsx,
        float xmin,
        float xmax,
        int numbinsy,
        float ymin,
        float ymax
        )
    {
      // If no title given, set title to name
      if (title == "") title = name;

      // Find whether a histogram with the name already exists
      map<string, TH1*>::iterator iter= allhistos.find(name);

      // If the histogram is not found, make a new one
      if(iter == allhistos.end())
      {
        TH2D* currentHisto= new TH2D(name.c_str(), title.c_str(), numbinsx, xmin, xmax, numbinsy, ymin, ymax);
        currentHisto->Sumw2();
        currentHisto->SetDirectory(0);
        currentHisto->Fill(xval, yval, weight);
        allhistos.insert(pair<string, TH1*> (name,currentHisto) );
        return false;
      }
      // exists already, so just fill it
      else
      {
        ((TH2D*) (*iter).second)->Fill(xval, yval, weight);
        return true;
      }
    }

    //################################################################################################
    // Plot 1D histogram. If a histogram doesn't exist book first and fill. (with variable binning)
    //
    bool plot2D(string name, float xval, float yval, double weight, std::map<string, TH1*> &allhistos,
        string title, int numbinsx, const float * xbins, int numbinsy, const float* ybins)
    {
      // If no title given, set title to name
      if (title=="") title=name;

      // Find whether a histogram with the name already exists
      std::map<string, TH1*>::iterator iter= allhistos.find(name);

      // If the histogram is not found, make a new one.
      if(iter == allhistos.end())
      {
        TH2D* currentHisto= new TH2D(name.c_str(), title.c_str(), numbinsx, xbins, numbinsy, ybins);
        currentHisto->Sumw2();
        currentHisto->SetDirectory(0);
        currentHisto->Fill(xval, yval, weight);
        allhistos.insert(std::pair<string, TH1*> (name,currentHisto) );
        return false;
      }
      else // exists already, so just fill it
      {
        ((TH2D*) (*iter).second)->Fill(xval, yval, weight);
        return true;
      }
    }

    //################################################################################################
    // Plot 1D histogram. If a histogram doesn't exist throw an error
    //
    void plot2D(
        string name,
        float xval,
        float yval,
        double weight,
        Hist_DB &allhistos)
    {

      //// Find whether a histogram with the name already exists
      //map<string, TH1*>::iterator iter= allhistos.find(name);

      //// If the histogram is not found, make a new one
      //if (iter == allhistos.end())
      //{
      //  TString error_msg = TString::Format("PlotUtil::plot2D() trying to fill %s when it doesn't exist", name.c_str());
      //  PrintUtilities::error(error_msg);
      //}
      //// exists already, so just fill it
      //else
      //{
      //  (*iter).second->Fill(xval, weight);
      //}


      ((TH2D*) allhistos[name])->Fill(xval, yval, weight);

      return;
    }

    //################################################################################################
    // Plot 1D histogram. If a histogram doesn't exist book first and fill.
    //
    void savePlots(Hist_DB &h_1d, const char* outfilename)
    {

      // Create a TFile
      TFile outfile(outfilename,"RECREATE") ;

      // Print the info that I am saving to the file
      printf("[AnalysisUtilities::PlotUtil::savePlots] Saving histograms to %s\n", outfilename);

      // Loop over the histograms
      Hist_DB::iterator it1d;
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

    //################################################################################################
    // Plot 1D histogram. If a histogram doesn't exist book first and fill.
    //
    void savePlots2D(Hist_DB &h_1d, const char* outfilename)
    {

      // Create a TFile
      TFile outfile(outfilename,"RECREATE") ;

      // Print the info that I am saving to the file
      printf("[AnalysisUtilities::PlotUtil::savePlots] Saving histograms to %s\n", outfilename);

      // Loop over the histograms
      Hist_DB::iterator it1d;
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
    unsigned int current_ttree_event_index = -1;
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
      //loadCurrentTTreeEvent();
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
      current_tchain->LoadTree(current_ttree_event_index);
      current_tchain->GetEntry(current_ttree_event_index);
      return current_ttree->LoadTree(current_ttree_event_index);
    }

    //################################################################################################
    // Go to next event in the ttree
    //
    bool nextEvent()
    {
      incrementCurrentTTreeEventIndex();
      int loadresult = loadCurrentTTreeEvent();
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
      current_ttree_event_index = -1;
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
        if (entry >= totalN+1) // +2 instead of +1 since, the loop might be a while loop where to check I got a bad event the index may go over 1.
        {
          TString msg = TString::Format("%d %d", entry, totalN);
          PrintUtilities::print(msg);
          PrintUtilities::error("Total number of events processed went over max allowed! Check your loop boundary conditions!!");
        }

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
        PlotUtil::Hist_DB& h_1d,
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

  //#################################################################################################
  //
  //
  // VBF SUSY study utilities
  //
  //
  //#################################################################################################
  namespace VBFSUSYUtilities
  {

    double mC1_event = 0;
    double mN2_event = 0;
    double mN1_event = 0;

    Leptons selected_good_leptons;
    Leptons selected_vbf_leptons;
    Leptons selected_isr_leptons;
    Jets    selected_good_jets;
    Jets    selected_good_bjets;
    Truths selected_ewkinos;
    Truths selected_lsps;
    Truths selected_z_leptons;
    Truths selected_w_leptons;
    Truths selected_leptons;

    float met_pt;
    float met_phi;
    TLorentzVector met_p4;

    ELECTRON_ID_type ELECTRON_ID = kELECTRON_LOOSE;
    MUON_ID_type MUON_ID = kMUON_LOOSE;
    PROD_type prodmode = kPRODSTRONG;

    //################################################################################################
    void setMC1(double mC1) { mC1_event = mC1; }
    void setMN2(double mN2) { mN2_event = mN2; }
    void setMN1(double mN1) { mN1_event = mN1; }
    double getMC1() { return mC1_event; }
    double getMN2() { return mN2_event; }
    double getMN1() { return mN1_event; }

    //################################################################################################
    // Parse the generator particles pdgId and status to read the masses and set it to member variable
    //
    void parseEwkinoMasses(int ngen, int* gen_pdgId, int* gen_status, float* gen_mass)
    {

      // parse the ewkino masses
      setMC1(0);
      setMN2(0);
      setMN1(0);


      if (abs(gen_pdgId[2]) == 1000024) setMC1(gen_mass[2]);
      if (abs(gen_pdgId[3]) == 1000024) setMC1(gen_mass[3]);

      if (abs(gen_pdgId[2]) == 1000023) setMN2(gen_mass[2]);
      if (abs(gen_pdgId[3]) == 1000023) setMN2(gen_mass[3]);

      //if (abs(gen_pdgId[10])== 1000022) setMN1(gen_mass[10]);

      //if (abs(gen_pdgId[10])!= 1000022)
      //  PrintUtilities::error("VBFSUSYUtilities::parseEwkinoMasses() the gen_pdgId[10] != 1000022");

      // Old deprecated way of computing
      // If signal sample by checking whether the output name contains "sig"
      for (int igen = 0; igen < ngen; ++igen)
      {
        if (abs(gen_pdgId[igen]) == 1000022 && (gen_status[igen] == 23
                                              ||gen_status[igen] == 1)) setMN1(gen_mass[igen]);
      }

      //if (fabs(mC1_event - 0) < 0.1 && fabs(mN2_event) < 0.1)
      //{
      //  for (int igen = 0; igen < ngen; ++igen)
      //  {
      //    TString msg = TString::Format("%d %f", gen_pdgId[igen], gen_mass[igen]);
      //    PrintUtilities::print(msg);
      //  }
      //}

      return;
    }

    //################################################################################################
    // parse production mode
    //
    void parseProductionMode(int ngen, int* gen_pdgId, int* gen_status)
    {
      if      (gen_pdgId[0] == 21 || gen_pdgId[1] == 21)
        setProductionMode(kPRODSTRONG);
      else if (gen_pdgId[4] == 21 || gen_pdgId[5] == 21)
        setProductionMode(kPRODVSTAR);
      else
        setProductionMode(kPRODVBF);
    }

    //################################################################################################
    // set production mode
    //
    void setProductionMode(PROD_type prodmode_)
    {
      prodmode = prodmode_;
    }

    //################################################################################################
    // get production mode
    //
    PROD_type getProductionMode()
    {
      return prodmode;
    }

    //################################################################################################
    // Create the mass suffix for the ewkino spectrum
    //
    TString getMassSuffixTString()
    {
      if (fabs(mC1_event-0) > 0.1)
        return TString::Format("_%.1f_%.1f", mC1_event, mN1_event).Data();
      else if (fabs(mN2_event-0) > 0.1)
        return TString::Format("_%.1f_%.1f", mN2_event, mN1_event).Data();
      else
      {
        TString msg = TString::Format("%f %f", mC1_event, mN2_event);
        PrintUtilities::print(msg);
        PrintUtilities::error("VBFSUSYUtilities::getMassSuffixTString() asked for a mass suffix but falled into an unknown category");
      }
      return "";
      //return TString::Format("_%.1f_%.1f_%.1f", mC1_event, mN2_event, mN1_event).Data();
      //return TString::Format("_%.1f_%.1f", mC1_event, mN1_event).Data();
    }

    //################################################################################################
    // Create the suffix for production mode
    //
    TString getProdSuffixTString()
    {
      //if (getProductionMode() == kPRODSTRONG) return "_strong";
      //else if (getProductionMode() == kPRODVSTAR ) return "_vstar";
      //else if (getProductionMode() == kPRODVBF) return "_vbf";
      if (getProductionMode() == kPRODSTRONG) return "_qcd";
      else if (getProductionMode() == kPRODVSTAR ) return "_qcd";
      else if (getProductionMode() == kPRODVBF) return "";
      else
        PrintUtilities::error("VBFSUSYUtilities::getProdSuffixTString() production mode not recognized!");
      return "";
    }

    //################################################################################################
    // return a new name with suffix attached.
    //
    TString getSignalSuffix(TString name)
    {
      //return (name + getProdSuffixTString() + getMassSuffixTString()).Data();
      return (name + getMassSuffixTString()).Data();
    }

    //################################################################################################
    // Clear leptons
    //
    void resetSelectedISRLeptons()
    {
      selected_isr_leptons.clear();
    }

    //################################################################################################
    // Add leptons
    //
    void addISRLepton(Lepton lepton)
    {
      selected_isr_leptons.push_back(lepton);
    }

    //################################################################################################
    // Is good lepton
    //
    bool isISRLepton(Lepton lepton)
    {
      bool fail = false;
      if ( !(lepton.lep_pt >= 5.) ) fail |= true;
      if ( !(lepton.lep_pt < 30.) ) fail |= true;
      return ( !fail );
    }

    //################################################################################################
    // get n selected good leptons
    //
    int getNSelectedISRLeptons()
    {
      return selected_isr_leptons.size();
    }

    //################################################################################################
    // Select leptons
    //
    void selectISRLeptons(Leptons leptons)
    {
      resetSelectedISRLeptons();
      for (auto& lep: leptons)
        if (isISRLepton(lep))
          addISRLepton(lep);
    }

    //################################################################################################
    // Clear leptons
    //
    void resetSelectedGoodLeptons()
    {
      selected_good_leptons.clear();
    }

    //################################################################################################
    // Add leptons
    //
    void addGoodLepton(Lepton lepton)
    {
      selected_good_leptons.push_back(lepton);
    }

    //################################################################################################
    // Is good lepton
    //
    bool isGoodLepton(Lepton lepton)
    {
      bool fail = false;
      if ( !(lepton.lep_pt >= 5.) ) fail |= true;
      if ( (abs(lepton.lep_pdgId) == 11) && !( (fabs(lepton.lep_eta) < 2.5)       ) ) fail |= true;
      if ( (abs(lepton.lep_pdgId) == 13) && !( (fabs(lepton.lep_eta) < 2.4)       ) ) fail |= true;
      //if ( (abs(lepton.lep_pdgId) == 11) && !( (lepton.lep_tightId > ELECTRON_ID) ) ) fail |= true;
      //if ( (abs(lepton.lep_pdgId) == 13) && !( (lepton.lep_tightId > MUON_ID)     ) ) fail |= true;
      if ( !( fabs(lepton.lep_sip3d) < 2.                                         ) ) fail |= true;
      if ( !( fabs(lepton.lep_dxy)   < 0.01                                       ) ) fail |= true;
      if ( !( fabs(lepton.lep_dz)    < 0.01                                       ) ) fail |= true;
      if ( !( fabs(lepton.lep_relIso03) < 0.5                                     ) ) fail |= true;
      if ( !( fabs(lepton.lep_relIso03*lepton.lep_pt) < 5.                        ) ) fail |= true;
      return ( !fail );
    }

    //################################################################################################
    // get n selected good leptons
    //
    int getNSelectedGoodLeptons()
    {
      return selected_good_leptons.size();
    }

    //################################################################################################
    // return number of soft vbf leptons
    //
    int getNSelectedSoftGoodLeptons()
    {
      int nlep = getNSelectedGoodLeptons();
      if (nlep == 0)
      {
        return 0;
      }
      else
      {
        if (getLeadingGoodLepton().p4.Pt() > 30.)
          return -1;
        else
          return getNSelectedGoodLeptons();
      }
    }

    //################################################################################################
    // get leading good lepton
    //
    Lepton getLeadingGoodLepton()
    {
      checkOneLepton(__FUNCTION__);
      return selected_good_leptons.at(0);
    }

    //################################################################################################
    // get leading good lepton
    //
    Lepton getSubleadingGoodLepton()
    {
      checkTwoLeptons(__FUNCTION__);
      return selected_good_leptons.at(1);
    }


    //################################################################################################
    // Select leptons
    //
    void selectGoodLeptons(Leptons leptons)
    {
      resetSelectedGoodLeptons();
      for (auto& lep: leptons)
        if (isGoodLepton(lep))
          addGoodLepton(lep);
    }

    //################################################################################################
    // Clear leptons
    //
    void resetSelectedVBFLeptons()
    {
      selected_vbf_leptons.clear();
    }

    //################################################################################################
    // Add leptons
    //
    void addVBFLepton(Lepton lepton)
    {
      selected_vbf_leptons.push_back(lepton);
    }

    //################################################################################################
    // Is good lepton
    //
    bool isVBFLepton(Lepton lepton)
    {
      bool fail = false;
      if ( !(lepton.lep_pt >= 5.) ) fail |= true;
      if ( (abs(lepton.lep_pdgId) == 11) && !( (fabs(lepton.lep_eta) < 2.5)       ) ) fail |= true;
      if ( (abs(lepton.lep_pdgId) == 13) && !( (fabs(lepton.lep_eta) < 2.4)       ) ) fail |= true;
      if ( (abs(lepton.lep_pdgId) == 11) && !( (lepton.lep_tightId > ELECTRON_ID) ) ) fail |= true;
      if ( (abs(lepton.lep_pdgId) == 13) && !( (lepton.lep_tightId > MUON_ID)     ) ) fail |= true;
      if ( !( fabs(lepton.lep_sip3d) < 2.                                         ) ) fail |= true;
      if ( !( fabs(lepton.lep_dxy)   < 0.01                                       ) ) fail |= true;
      if ( !( fabs(lepton.lep_dz)    < 0.01                                       ) ) fail |= true;
      if ( !( fabs(lepton.lep_relIso03) < 0.5                                     ) ) fail |= true;
      if ( !( fabs(lepton.lep_relIso03*lepton.lep_pt) < 5.                        ) ) fail |= true;
      return ( !fail );
    }

    //################################################################################################
    // get n selected good leptons
    //
    int getNSelectedVBFLeptons()
    {
      return selected_vbf_leptons.size();
    }

    //################################################################################################
    // Select leptons
    //
    void selectVBFLeptons(Leptons leptons)
    {
      resetSelectedVBFLeptons();
      for (auto& lep: leptons)
        if (isVBFLepton(lep))
          addVBFLepton(lep);
    }

    //################################################################################################
    // Clear jets
    //
    void resetSelectedGoodJets()
    {
      selected_good_jets.clear();
    }

    //################################################################################################
    // Clear jets
    //
    void resetSelectedGoodBJets()
    {
      selected_good_bjets.clear();
    }

    //################################################################################################
    // Add jets
    //
    void addGoodJet(Jet jet)
    {
      selected_good_jets.push_back(jet);
    }

    //################################################################################################
    // Add jets
    //
    void addGoodBJet(Jet jet)
    {
      selected_good_bjets.push_back(jet);
    }

    //################################################################################################
    // Count the number of bjets
    bool isBTaggedWithCSVCut(Jet jet, float csvcut)
    {
      return jet.jet_btagCSV > csvcut;
    }

    //################################################################################################
    // Count the number of bjets
    int getNBTaggedJetsWithCSVCut(float csvcut)
    {
      int nbtag = 0;
      for (auto& jet: selected_good_jets)
        if (isBTaggedWithCSVCut(jet, csvcut))
          nbtag++;
      return nbtag;
    }

    //################################################################################################
    // Is good jet
    //
    bool isGoodJet(Jet jet)
    {
      bool fail = false;
      if ( !(jet.jet_pt > 25.       ) ) fail |= true;
      //if ( !(fabs(jet.jet_eta) < 2.4) ) fail |= true;
      return ( !fail );
    }
    //################################################################################################
    // Is good jet
    //
    bool isGoodBJet(Jet jet)
    {
      bool fail = false;
      if ( !(jet.jet_pt > 25.        ) ) fail |= true;
      if ( !(fabs(jet.jet_eta) < 2.4 ) ) fail |= true;
      if ( !(jet.jet_btagCSV > 0.46  ) ) fail |= true;
      return ( !fail );
    }


    //################################################################################################
    // Select jets
    //
    void selectGoodJets(Jets jets)
    {
      resetSelectedGoodJets();
      for (auto& jet: jets)
        if (isGoodJet(jet))
          addGoodJet(jet);
    }

    //################################################################################################
    // Select jets
    //
    void selectGoodBJets(Jets jets)
    {
      resetSelectedGoodBJets();
      for (auto& jet: jets)
        if (isGoodBJet(jet))
          addGoodBJet(jet);
    }

    //################################################################################################
    void resetSelectedTruths()
    {
      selected_ewkinos.clear();
      selected_lsps.clear();
      selected_leptons.clear();
      selected_w_leptons.clear();
      selected_z_leptons.clear();
    }

    //################################################################################################
    bool isWLepton(Truth truth)
    {
      if (abs(truth.truth_pdgId) == 11 || abs(truth.truth_pdgId) == 13)
        if (abs(truth.truth_sourceId) == 24)
          return true;
      return false;
    }

    //################################################################################################
    void addWLepton(Truth truth)
    {
      selected_w_leptons.push_back(truth);
      addLepton(truth);
    }

    //################################################################################################
    bool isZLepton(Truth truth)
    {
      if (abs(truth.truth_pdgId) == 11 || abs(truth.truth_pdgId) == 13)
        if (abs(truth.truth_sourceId) == 23)
          return true;
      return false;
    }

    //################################################################################################
    void addZLepton(Truth truth)
    {
      selected_z_leptons.push_back(truth);
      addLepton(truth);
    }

    //################################################################################################
    void addLepton(Truth truth)
    {
      selected_leptons.push_back(truth);
    }

    //################################################################################################
    Truths getWLeptons()
    {
      return selected_w_leptons;
    }

    //################################################################################################
    Truths getZLeptons()
    {
      return selected_z_leptons;
    }

    //################################################################################################
    Truths getLeptons()
    {
      return selected_leptons;
    }

    //################################################################################################
    void selectTruths(Truths truths)
    {
      resetSelectedTruths();
      for (auto& truth: truths)
        if (isWLepton(truth))
          addWLepton(truth);
        else if (isZLepton(truth))
          addZLepton(truth);
    }

    //################################################################################################
    // get number of selected jets
    //
    int getNSelectedGoodJets()
    {
      return selected_good_jets.size();
    }

    //################################################################################################
    // get number of selected jets
    //
    int getNSelectedGoodBJets()
    {
      return selected_good_bjets.size();
    }

    //################################################################################################
    // has VBF jets
    //
    bool hasVBFJets()
    {
      if (getNSelectedGoodJets() < 2)
        return false;
      else
        return true;
    }

    //################################################################################################
    // get leading VBF jet
    Jet getLeadingVBFJet()
    {
      checkTwoJets(__FUNCTION__);
      return selected_good_jets.at(0);
    }

    //################################################################################################
    // get subleading VBF jet
    Jet getSubleadingVBFJet()
    {
      checkTwoJets(__FUNCTION__);
      return selected_good_jets.at(1);
    }

    //################################################################################################
    // Set MET and MET phi
    //
    void setMET   (float met_pt_ ) { met_pt  = met_pt_;  setMETp4(); }
    void setMETphi(float met_phi_) { met_phi = met_phi_; setMETp4(); }
    void setMETp4 () { met_p4.SetPtEtaPhiM(met_pt, 0, met_phi, 0); }
    TLorentzVector getMETp4() { return met_p4; }

    //################################################################################################
    // Is this jet a central jet
    //
    bool isCenJet(Jet jet)
    {
      // case 1: if n(selected_good_jets) < 3, the question doesn't even make sense. return false.
      if (getNSelectedGoodJets() < 3)
        return false;
      // case 2: check against the two leading jet
      return (
              (getLeadingVBFJet   ().p4.Eta() - jet.p4.Eta())*
              (getSubleadingVBFJet().p4.Eta() - jet.p4.Eta())
             ) < 0;
    }

    //################################################################################################
    // Does central jet exists between the two leading jets
    //
    bool doesCenJetsExist()
    {
      for (unsigned int ijet = 2; ijet < selected_good_jets.size(); ++ijet)
        if (isCenJet(selected_good_jets.at(ijet)))
          return true;
      return false;
    }

    //################################################################################################
    // compute VBF Delta Eta variable
    //
    float getVBFDEtajj()
    {
      checkTwoJets(__FUNCTION__);
      return fabs(getLeadingVBFJet().p4.Eta() - getSubleadingVBFJet().p4.Eta());
    }

    //################################################################################################
    // compute VBF Delta Eta variable
    //
    float getVBFDPhijj()
    {
      checkTwoJets(__FUNCTION__);
      return fabs(getLeadingVBFJet().p4.DeltaPhi(getSubleadingVBFJet().p4));
    }

    //################################################################################################
    // compute VBF Delta Eta variable
    //
    float getVBFMjj()
    {
      checkTwoJets(__FUNCTION__);
      return (getLeadingVBFJet().p4 + getSubleadingVBFJet().p4).M();
    }

    //################################################################################################
    // compute VBF Delta Eta variable
    //
    float getLeptonCentrality()
    {
      checkTwoJets(__FUNCTION__);
      checkOneLepton(__FUNCTION__);

      float avgeta = (getLeadingVBFJet().p4.Eta() + getSubleadingVBFJet().p4.Eta())/2.;
      float dlepeta = fabs(getLeadingGoodLepton().p4.Eta() - avgeta);
      float deta_div_2 = getVBFDEtajj() / 2.;
      return dlepeta / deta_div_2;

    }

    //################################################################################################
    // compute VBF Delta Eta variable
    //
    float getLeadCenJetPt()
    {
      checkTwoJets(__FUNCTION__);
      if (getNSelectedGoodJets() == 2)
        return -20;
      for (unsigned int ijet = 2; ijet < selected_good_jets.size(); ++ijet)
        if (isCenJet(selected_good_jets.at(ijet)))
          return selected_good_jets.at(ijet).p4.Pt();
      return -10;
    }

    //################################################################################################
    // isEEChannel()
    //
    bool isEEChannel()
    {
      checkTwoLeptons(__FUNCTION__);
      return (getLeadingGoodLepton().lep_pdgId*getSubleadingGoodLepton().lep_pdgId == -121);
    }

    //################################################################################################
    // isMMChannel()
    //
    bool isMMChannel()
    {
      checkTwoLeptons(__FUNCTION__);
      return (getLeadingGoodLepton().lep_pdgId*getSubleadingGoodLepton().lep_pdgId == -169);
    }

    //################################################################################################
    // get Mll
    //
    float getMll()
    {
      checkTwoLeptons(__FUNCTION__);
      return (getLeadingGoodLepton().p4 + getSubleadingGoodLepton().p4).M();
    }

    //################################################################################################
    // get Mll
    //
    float getDPhill()
    {
      checkTwoLeptons(__FUNCTION__);
      return fabs(getLeadingGoodLepton().p4.DeltaPhi(getSubleadingGoodLepton().p4));
    }

    //################################################################################################
    // get Ptll
    //
    float getPtll()
    {
      checkTwoLeptons(__FUNCTION__);
      return (getLeadingGoodLepton().p4 + getSubleadingGoodLepton().p4).Pt();
    }

    //################################################################################################
    // get MT
    //
    float getModMT(Lepton lep)
    {
      float mt = sqrt(2 * lep.p4.Pt() * ( 1 - cos(met_p4.DeltaPhi(lep.p4) ) ));
      return mt;
    }

    //################################################################################################
    // get MT leading lepton
    //
    float getModMTleadLep()
    {
      checkOneLepton(__FUNCTION__);
      return getModMT(getLeadingGoodLepton());
    }

    //################################################################################################
    // get MT leading lepton
    //
    float getModMTsubleadLep()
    {
      checkTwoLeptons(__FUNCTION__);
      return getModMT(getSubleadingGoodLepton());
    }

    //################################################################################################
    // get MT
    //
    float getMT(Lepton lep)
    {
      float mt = sqrt(2 * lep.p4.Pt() * met_p4.Pt() * ( 1 - cos(met_p4.DeltaPhi(lep.p4) ) ));
      return mt;
    }

    //################################################################################################
    // get MT leading lepton
    //
    float getMTleadLep()
    {
      checkOneLepton(__FUNCTION__);
      return getMT(getLeadingGoodLepton());
    }

    //################################################################################################
    // get MT leading lepton
    //
    float getMTsubleadLep()
    {
      checkTwoLeptons(__FUNCTION__);
      return getMT(getSubleadingGoodLepton());
    }

    //################################################################################################
    // get MT leading lepton
    //
    float getMlj(Jet jet, Lepton lep)
    {
      return (jet.p4 + lep.p4).M();
    }

    //################################################################################################
    // get MT leading lepton
    //
    float getLeadMlj()
    {
      checkOneLepton(__FUNCTION__);
      checkOneJet(__FUNCTION__);
      return getMlj(getLeadingVBFJet(), getLeadingGoodLepton());
    }

    //################################################################################################
    // get MT leading lepton
    //
    float getSubleadMlj()
    {
      checkOneLepton(__FUNCTION__);
      checkTwoJets(__FUNCTION__);
      return getMlj(getSubleadingVBFJet(), getLeadingGoodLepton());
    }

    //################################################################################################
    // get sum mlj
    //
    float getSumMlj()
    {
      return getLeadMlj() + getSubleadMlj();
    }

    //################################################################################################
    // get Mtt (collinear approximation)
    //
    float getMtt()
    {

      checkTwoLeptons(__FUNCTION__);

      TLorentzVector lep0_tlv;
      TLorentzVector lep1_tlv;
      TLorentzVector tmp_met;
      float x_1;
      float x_2;
      float mtt;
      float Mll;

      lep0_tlv = getLeadingGoodLepton().p4;
      lep1_tlv = getSubleadingGoodLepton().p4;
      tmp_met = met_p4;
      Mll = (lep0_tlv + lep1_tlv).M();

      //lep0_tlv.Print();
      //lep1_tlv.Print();
      //tmp_met.Print();

      // below from HWWlvlvCode.cxx https://svnweb.cern.ch/trac/atlasoff/browser/PhysicsAnalysis/HiggsPhys/HSG3/WWDileptonAnalysisCode/HWWlvlvCode/trunk/Root/HWWlvlvCode.cxx
      x_1= (lep0_tlv.Px()*lep1_tlv.Py()-lep0_tlv.Py()*lep1_tlv.Px())/(lep1_tlv.Py()*tmp_met.Px()-lep1_tlv.Px()*tmp_met.Py()+lep0_tlv.Px()*lep1_tlv.Py()-lep0_tlv.Py()*lep1_tlv.Px());
      x_2= (lep0_tlv.Px()*lep1_tlv.Py()-lep0_tlv.Py()*lep1_tlv.Px())/(lep0_tlv.Px()*tmp_met.Py()-lep0_tlv.Py()*tmp_met.Px()+lep0_tlv.Px()*lep1_tlv.Py()-lep0_tlv.Py()*lep1_tlv.Px());
      if (x_1 > 0 && x_2 > 0)
        mtt = Mll/sqrt(x_1*x_2);
      else
        mtt = -9999.;

      return mtt;

    }

    //################################################################################################
    // get DPhi(lep,met)
    //
    float getDPhiLepMET()
    {
      checkOneLepton(__FUNCTION__);
      return fabs(getLeadingGoodLepton().p4.DeltaPhi(getMETp4()));
    }

    //################################################################################################
    // get vector sum of pt of all objects
    //
    float getVecSumPt()
    {
      checkOneLepton(__FUNCTION__);
      checkTwoJets(__FUNCTION__);
      TLorentzVector lep = getLeadingGoodLepton().p4;
      TLorentzVector jet0 = getLeadingVBFJet().p4;
      TLorentzVector jet1 = getSubleadingVBFJet().p4;
      TLorentzVector met = getMETp4();
      TLorentzVector system = lep + jet0 + jet1 + met;
      return system.Pt();
    }

    //################################################################################################
    // get vector sum of pt of all objects
    //
    float getVecSumPtAll()
    {
      checkOneLepton(__FUNCTION__);
      TLorentzVector lep = getLeadingGoodLepton().p4;
      TLorentzVector met = getMETp4();
      TLorentzVector system = lep + met;
      for (int ijet = 0; ijet < getNSelectedGoodJets(); ++ijet)
      {
        system = selected_good_jets.at(ijet).p4;
      }
      return system.Pt();
    }

    //################################################################################################
    // get delta phi between leading jet and met
    //
    float getDPhiLeadJetMET()
    {
      checkOneJet(__FUNCTION__);
      return fabs(getLeadingVBFJet().p4.DeltaPhi(getMETp4()));
    }

    //################################################################################################
    // get delta phi between subleading jet and met
    //
    float getDPhiSubleadJetMET()
    {
      checkOneLepton(__FUNCTION__);
      checkTwoJets(__FUNCTION__);
      return fabs(getSubleadingVBFJet().p4.DeltaPhi(getMETp4()));
    }


    //################################################################################################
    // get delta phi between leading jet and met
    //
    float getDPhiLeadJetLep()
    {
      checkOneLepton(__FUNCTION__);
      checkOneJet(__FUNCTION__);
      return fabs(getLeadingVBFJet().p4.DeltaPhi(getLeadingGoodLepton().p4));
    }

    //################################################################################################
    // get delta phi between subleading jet and met
    //
    float getDPhiSubleadJetLep()
    {
      checkOneLepton(__FUNCTION__);
      checkTwoJets(__FUNCTION__);
      return fabs(getSubleadingVBFJet().p4.DeltaPhi(getLeadingGoodLepton().p4));
    }

    //################################################################################################
    // get delta phi between dijet and lepton
    //
    float getDPhiDiJetLep()
    {
      checkOneLepton(__FUNCTION__);
      checkTwoJets(__FUNCTION__);
      TLorentzVector dijet = getLeadingVBFJet().p4 + getSubleadingVBFJet().p4;
      return fabs(dijet.DeltaPhi(getLeadingGoodLepton().p4));
    }

    //################################################################################################
    // get delta phi between dijet and met
    //
    float getDPhiDiJetMET()
    {
      checkTwoJets(__FUNCTION__);
      TLorentzVector dijet = getLeadingVBFJet().p4 + getSubleadingVBFJet().p4;
      return fabs(dijet.DeltaPhi(getMETp4()));
    }

    //################################################################################################
    float getDPhiLeadJetMetLep()
    {
      checkOneLepton(__FUNCTION__);
      checkOneJet(__FUNCTION__);
      TLorentzVector jetmet = getLeadingVBFJet().p4 + getMETp4();
      return fabs(jetmet.DeltaPhi(getLeadingGoodLepton().p4));
    }

    //################################################################################################
    float getDPhiSubleadJetMetLep()
    {
      checkOneLepton(__FUNCTION__);
      checkTwoJets(__FUNCTION__);
      TLorentzVector jetmet = getSubleadingVBFJet().p4 + getMETp4();
      return fabs(jetmet.DeltaPhi(getLeadingGoodLepton().p4));
    }

    //################################################################################################
    float getDPhiDiJetMetLep()
    {
      checkOneLepton(__FUNCTION__);
      checkTwoJets(__FUNCTION__);
      TLorentzVector tristate = getLeadingVBFJet().p4 + getSubleadingVBFJet().p4 + getMETp4();
      return fabs(tristate.DeltaPhi(getLeadingGoodLepton().p4));
    }

    //################################################################################################
    // get met phi centrality wrt to jets
    //
    float getMETPhiCent()
    {
      checkTwoJets(__FUNCTION__);
      // Additional Variables for the VBF BDT
      float var_aPhi = getLeadingVBFJet().p4.Phi();
      float var_bPhi = getSubleadingVBFJet().p4.Phi();
      float var_cPhi = getMETp4().Phi();
      if (var_bPhi==var_aPhi) {
          var_aPhi+=0.01 ;
          var_bPhi-=0.01 ;
      }
      float var_A = TMath::Sin(var_cPhi - var_aPhi)/TMath::Sin(var_bPhi - var_aPhi);
      float var_B = TMath::Sin(var_bPhi - var_cPhi)/TMath::Sin(var_bPhi - var_aPhi);
      float cent = (var_A+var_B)/TMath::Sqrt(var_A*var_A + var_B*var_B);
      return cent;
    }

    //################################################################################################
    // get met phi centrality wrt to jets
    //
    float getLepPhiCent()
    {
      checkOneLepton(__FUNCTION__);
      checkTwoJets(__FUNCTION__);
      // Additional Variables for the VBF BDT
      float var_aPhi = getLeadingVBFJet().p4.Phi();
      float var_bPhi = getSubleadingVBFJet().p4.Phi();
      float var_cPhi = getLeadingGoodLepton().p4.Phi();
      if (var_bPhi==var_aPhi) {
          var_aPhi+=0.01 ;
          var_bPhi-=0.01 ;
      }
      float var_A = TMath::Sin(var_cPhi - var_aPhi)/TMath::Sin(var_bPhi - var_aPhi);
      float var_B = TMath::Sin(var_bPhi - var_cPhi)/TMath::Sin(var_bPhi - var_aPhi);
      float cent = (var_A+var_B)/TMath::Sqrt(var_A*var_A + var_B*var_B);
      return cent;
    }

    //################################################################################################
    // get met phi centrality wrt to jets
    //
    float getMETPhiCentBoost()
    {
      checkTwoJets(__FUNCTION__);
      // Additional Variables for the VBF BDT
      TLorentzVector vbf0 = getLeadingVBFJet().p4;
      TLorentzVector vbf1 = getSubleadingVBFJet().p4;
      TLorentzVector met = getMETp4();
      TLorentzVector dijet = vbf0 + vbf1;
      TVector3 boost = dijet.BoostVector();
      met.Boost(-boost);
      return TVector2::Phi_mpi_pi(met.Phi());
    }

    //################################################################################################
    // get met phi centrality wrt to jets
    //
    float getLepPhiCentBoost()
    {
      checkOneLepton(__FUNCTION__);
      checkTwoJets(__FUNCTION__);
      // Additional Variables for the VBF BDT
      TLorentzVector vbf0 = getLeadingVBFJet().p4;
      TLorentzVector vbf1 = getSubleadingVBFJet().p4;
      TLorentzVector lep = getLeadingGoodLepton().p4;
      TLorentzVector dijet = vbf0 + vbf1;
      TVector3 boost = dijet.BoostVector();
      lep.Boost(-boost);
      return TVector2::Phi_mpi_pi(lep.Phi());
    }

    //################################################################################################
    // get dphi between dijet , lepmet system
    //
    float getDPhiDiJetLepMet()
    {
      checkOneLepton(__FUNCTION__);
      checkTwoJets(__FUNCTION__);
      TLorentzVector lep = getLeadingGoodLepton().p4;
      TLorentzVector jet0 = getLeadingVBFJet().p4;
      TLorentzVector jet1 = getSubleadingVBFJet().p4;
      TLorentzVector met = getMETp4();
      TLorentzVector system = lep + jet0 + jet1 + met;
      TLorentzVector dijet = jet0 + jet1;
      TLorentzVector lepmet = lep + met;
      return fabs(dijet.DeltaPhi(lepmet));
    }

    //################################################################################################
    // get DPhi(lep,met)
    //
    float getDPhiLepMETInvDijetFrame()
    {
      checkOneLepton(__FUNCTION__);
      checkTwoJets(__FUNCTION__);
      TLorentzVector jet0 = getLeadingVBFJet().p4;
      TLorentzVector jet1 = getSubleadingVBFJet().p4;
      TLorentzVector dijet = jet0 + jet1;
      TVector3 boost = dijet.BoostVector();
      TLorentzVector lep = getLeadingGoodLepton().p4;
      TLorentzVector met = getMETp4();
      lep.Boost(boost);
      met.Boost(boost);
      return fabs(lep.DeltaPhi(met));
    }

    //################################################################################################
    // get DPhi(lep,met)
    //
    float getDPhiLepMETWFrame()
    {
      checkOneLepton(__FUNCTION__);
      checkTwoJets(__FUNCTION__);
      TLorentzVector jet0 = getLeadingVBFJet().p4;
      TLorentzVector jet1 = getSubleadingVBFJet().p4;
      TLorentzVector dijet = jet0 + jet1;
      TLorentzVector lep = getLeadingGoodLepton().p4;
      TLorentzVector met = getMETp4();
      TLorentzVector wpt = lep + met;
      TVector3 boost = wpt.BoostVector();
      lep.Boost(-boost);
      met.Boost(-boost);
      return fabs(lep.DeltaPhi(met));
    }

    //################################################################################################
    float getPtRel(Lepton lepton)
    {
      TLorentzVector lep = lepton.p4;
      TLorentzVector met = getMETp4();
      if (lep.DeltaPhi(met) < TMath::PiOver2())
        return lep.Pt() * sin( fabs( lep.DeltaPhi( met ) ) );
      return lep.Pt();
    }

    //################################################################################################
    float getSuperPtRel()
    {
      checkOneLepton(__FUNCTION__);
      checkTwoJets(__FUNCTION__);
      TLorentzVector lep = getLeadingGoodLepton().p4;
      TLorentzVector met = getMETp4();
      TLorentzVector jet0 = getLeadingVBFJet().p4;
      TLorentzVector jet1 = getSubleadingVBFJet().p4;
      float dphi_lep_met   = fabs(lep.DeltaPhi(met));
      float dphi_lep_dijet = fabs(lep.DeltaPhi((jet0+jet1)));
      float dphi_lep_jet0  = fabs(lep.DeltaPhi(jet0));
      float dphi_lep_jet1  = fabs(lep.DeltaPhi(jet1));
      float w_dphi_lep_met   = 1.7 * (1-cos(dphi_lep_met)  );
      float w_dphi_lep_dijet = 1.5 * (1+cos(dphi_lep_dijet));
      float w_dphi_lep_jet0  = 1.4 * (1+cos(dphi_lep_jet0) );
      float w_dphi_lep_jet1  = 1.0 * (1+cos(dphi_lep_jet1) );
      float w_total = w_dphi_lep_met + w_dphi_lep_dijet + w_dphi_lep_jet0 + w_dphi_lep_jet1;
      return lep.Pt() * w_total;
    }

    //################################################################################################
    float getSuperPtRelNoWgt()
    {
      checkOneLepton(__FUNCTION__);
      checkTwoJets(__FUNCTION__);
      TLorentzVector lep = getLeadingGoodLepton().p4;
      TLorentzVector met = getMETp4();
      TLorentzVector jet0 = getLeadingVBFJet().p4;
      TLorentzVector jet1 = getSubleadingVBFJet().p4;
      float dphi_lep_met   = fabs(lep.DeltaPhi(met));
      float dphi_lep_dijet = fabs(lep.DeltaPhi((jet0+jet1)));
      float dphi_lep_jet0  = fabs(lep.DeltaPhi(jet0));
      float dphi_lep_jet1  = fabs(lep.DeltaPhi(jet1));
      float w_dphi_lep_met   = (1-cos(dphi_lep_met)  );
      float w_dphi_lep_dijet = (1+cos(dphi_lep_dijet));
      float w_dphi_lep_jet0  = (1+cos(dphi_lep_jet0) );
      float w_dphi_lep_jet1  = (1+cos(dphi_lep_jet1) );
      float w_total = w_dphi_lep_met + w_dphi_lep_dijet + w_dphi_lep_jet0 + w_dphi_lep_jet1;
      return lep.Pt() * w_total;
    }

    //################################################################################################
    float getProdPtRel()
    {
      checkOneLepton(__FUNCTION__);
      checkTwoJets(__FUNCTION__);
      TLorentzVector lep = getLeadingGoodLepton().p4;
      TLorentzVector met = getMETp4();
      TLorentzVector jet0 = getLeadingVBFJet().p4;
      TLorentzVector jet1 = getSubleadingVBFJet().p4;
      float dphi_lep_met   = fabs(lep.DeltaPhi(met));
      float dphi_lep_dijet = fabs(lep.DeltaPhi((jet0+jet1)));
      float dphi_lep_jet0  = fabs(lep.DeltaPhi(jet0));
      float dphi_lep_jet1  = fabs(lep.DeltaPhi(jet1));
      float w_dphi_lep_met   = 1.7 * (1-cos(dphi_lep_met)  );
      float w_dphi_lep_dijet = 1.5 * (1+cos(dphi_lep_dijet));
      float w_dphi_lep_jet0  = 1.4 * (1+cos(dphi_lep_jet0) );
      float w_dphi_lep_jet1  = 1.0 * (1+cos(dphi_lep_jet1) );
      float w_total = w_dphi_lep_met * w_dphi_lep_dijet * w_dphi_lep_jet0 * w_dphi_lep_jet1;
      return lep.Pt() * w_total;
    }

    //################################################################################################
    float getMETRel(Lepton lepton)
    {
      TLorentzVector lep = lepton.p4;
      TLorentzVector met = getMETp4();
      return met.Pt() * cos( fabs( lep.DeltaPhi( met ) ) );
      //if (lep.DeltaPhi(met) < TMath::PiOver2())
      //  return met.Pt() * cos( fabs( lep.DeltaPhi( met ) ) );
      //else if (lep.DeltaPhi(met) >= TMath::PiOver2())
      //  return met.Pt() * sin( fabs( lep.DeltaPhi( met ) ) );
      //else
      //  return met.Pt();
    }

    //################################################################################################
    float getLeadLepPtRel()
    {
      checkOneLepton(__FUNCTION__);
      return getPtRel(getLeadingGoodLepton());
    }

    //################################################################################################
    float getLeadLepMETRel()
    {
      checkOneLepton(__FUNCTION__);
      return getMETRel(getLeadingGoodLepton());
    }

    //################################################################################################
    float getMTRel()
    {
      checkOneLepton(__FUNCTION__);
      //float mt = sqrt(2 * getLeadLepPtRel() * getLeadLepMETRel() * ( 1 - cos( getDPhiLepMET() ) ));
      float mt = getLeadLepMETRel() / getLeadLepPtRel();
      return mt;
    }

    //################################################################################################
    float getHT()
    {
      float ht = 0;
      for (auto& jet: selected_good_jets)
        ht += jet.p4.Pt();
      return ht;
    }

    //################################################################################################
    float getDPtJet()
    {
      checkTwoJets(__FUNCTION__);
      return getLeadingVBFJet().p4.Pt() - getSubleadingVBFJet().p4.Pt();
    }

    //################################################################################################
    float getMinDRLeadCenJet()
    {
      checkTwoJets(__FUNCTION__);
      if (getNSelectedGoodJets() == 2)
        return -20;
      TLorentzVector jet0 = getLeadingVBFJet().p4;
      TLorentzVector jet1 = getSubleadingVBFJet().p4;
      for (unsigned int ijet = 2; ijet < selected_good_jets.size(); ++ijet)
      {
        if (isCenJet(selected_good_jets.at(ijet)))
        {
          TLorentzVector cenjet = selected_good_jets.at(ijet).p4;
          float drjet0;
          float drjet1;
          drjet0 = jet0.DeltaR(cenjet);
          drjet1 = jet0.DeltaR(cenjet);
          float localmindr = drjet0 < drjet1 ? drjet0 : drjet1;
          return localmindr;
        }
      }
      return -10;
    }

    //################################################################################################
    float getMinDRCenJet()
    {
      checkTwoJets(__FUNCTION__);
      if (getNSelectedGoodJets() == 2)
        return -20;
      float mindr = 99;
      TLorentzVector jet0 = getLeadingVBFJet().p4;
      TLorentzVector jet1 = getSubleadingVBFJet().p4;
      for (unsigned int ijet = 2; ijet < selected_good_jets.size(); ++ijet)
      {
        if (isCenJet(selected_good_jets.at(ijet)))
        {
          TLorentzVector cenjet = selected_good_jets.at(ijet).p4;
          float drjet0;
          float drjet1;
          drjet0 = jet0.DeltaR(cenjet);
          drjet1 = jet0.DeltaR(cenjet);
          float localmindr = drjet0 < drjet1 ? drjet0 : drjet1;
          if (localmindr < mindr) mindr = localmindr;
        }
      }
      return mindr;
    }

    //################################################################################################
    void checkNJets(int N, TString function)
    {
      if (getNSelectedGoodJets() < N)
        PrintUtilities::error(TString::Format("VBFSUSYUtilities::%s() asked when there are less than %d jet", function.Data(), N));
    }
    void checkNLeptons(int N, TString function)
    {
      if (getNSelectedGoodLeptons() < N)
        PrintUtilities::error(TString::Format("VBFSUSYUtilities::%s() asked when there are less than %d lepton", function.Data(), N));
    }
    void checkOneJet    (TString function) { checkNJets   (1, function); }
    void checkTwoJets   (TString function) { checkNJets   (2, function); }
    void checkThreeJets (TString function) { checkNJets   (3, function); }
    void checkOneLepton (TString function) { checkNLeptons(1, function); }
    void checkTwoLeptons(TString function) { checkNLeptons(2, function); }

    //################################################################################################
    //
    void printTruth(int ngen, int* gen_pdgId, int* gen_sourceId, float* gen_mass, float* gen_pt, float* gen_eta, float* gen_phi)
    {

      // debug print
      int idx = 0;
      for (int igen = 0; igen < ngen; ++igen)
      {

        float my_genPart_pt      = gen_pt[igen];
        float my_genPart_eta     = gen_eta[igen];
        float my_genPart_phi     = gen_phi[igen];
        float my_genPart_mass    = gen_mass[igen];
        int my_genPart_pdgId     = gen_pdgId[igen];
        int my_genPart_status    = 0;
        int my_genPart_motherId  = gen_sourceId[igen];
        int my_genPart_motherIdx = 0;

        if (my_genPart_pdgId == 1000022)
          continue;

        printf("%5d = %5d: %10d %4d %6.2f %6.2f %6.2f %6.2f  <-- %5d : %10d\n",
            idx,
            igen,
            my_genPart_pdgId,
            my_genPart_status,
            my_genPart_pt,
            my_genPart_eta,
            my_genPart_phi,
            my_genPart_mass,
            my_genPart_motherIdx,
            my_genPart_motherId);
        idx++;

      }

    }

    //################################################################################################
    bool eventHasTaus(int ngen, int* gen_pdgId)
    {
      for (int igen = 0; igen < ngen; ++igen)
        if (abs(gen_pdgId[igen]) == 15)
          return true;
      return false;
    }

    //################################################################################################
    // return if the correction was "successful"
    // if not, return false and reject the event
    //
    bool correctTChiWZ_ZLLFilter(int ngen, int* gen_pdgId, int* gen_sourceId, float* gen_mass, float* gen_pt, float* gen_eta, float* gen_phi, bool binary_random)
    {

      // vector to hold indices
      std::vector<int> lep_to_rm_idx;

      // vector to hold indices
      std::vector<int> w_leps;

      // Loop over and select indices
      for (int igen = 0; igen < ngen; ++igen)
      {

        // NOTE: If there are taus, don't even bother
        if (abs(gen_pdgId[igen]) == 15)
          return false;

        bool is_lepton = (abs(gen_pdgId[igen]) == 11 || abs(gen_pdgId[igen]) == 13);
        bool is_from_z = gen_sourceId[igen] == 23;
        bool is_from_w = gen_sourceId[igen] == 24;

        if      ( is_lepton && is_from_z ) lep_to_rm_idx.push_back(igen);
        else if ( is_lepton && is_from_z ) lep_to_rm_idx.push_back(igen);

        if ( is_lepton && is_from_w )
          w_leps.push_back(igen);

      }

      // if not a W->leptonic remove
      if (w_leps.size() == 0)
        return false;

      removeGoodLeptonsOverlappingWithTruthLeptonsAndAddToMET(gen_mass, gen_pt, gen_eta, gen_phi, lep_to_rm_idx);

      return true;

    }

    //################################################################################################
    // return if the correction was "successful"
    // if not, return false and reject the event
    //
    void removeGoodLeptonsOverlappingWithTruthLeptonsAndAddToMET(float* gen_mass, float* gen_pt, float* gen_eta, float* gen_phi, std::vector<int> lep_to_rm_idx)
    {

      std::vector<TLorentzVector> lep_to_rm;
      for (unsigned int ilep_to_rm_idx = 0; ilep_to_rm_idx < lep_to_rm_idx.size(); ++ilep_to_rm_idx)
      {
        //std::cout << "idx to remove from good selected leptons = " << lep_to_rm_idx.at(ilep_to_rm_idx) << std::endl;
        float pt  = gen_pt  [lep_to_rm_idx.at(ilep_to_rm_idx)];
        float eta = gen_eta [lep_to_rm_idx.at(ilep_to_rm_idx)];
        float phi = gen_phi [lep_to_rm_idx.at(ilep_to_rm_idx)];
        float mass= gen_mass[lep_to_rm_idx.at(ilep_to_rm_idx)];
        //std::cout << pt << " " << eta << " " << phi << " " << mass << std::endl;
        TLorentzVector p4;
        p4.SetPtEtaPhiM(pt, eta, phi, mass);
        //p4.Print();
        lep_to_rm.push_back(p4);
      }

      Leptons selected_good_leptons_new;
      for (unsigned int ilep = 0; ilep < selected_good_leptons.size(); ++ilep)
      {
        TLorentzVector tag = selected_good_leptons.at(ilep).p4;
        //std::cout << " tag " << std::endl;
        //tag.Print();
        bool removed = false;
        for (unsigned int ilep_to_rm = 0; ilep_to_rm < lep_to_rm.size(); ++ilep_to_rm)
        {
          TLorentzVector probe = lep_to_rm.at(ilep_to_rm);
          //std::cout << " probe " << std::endl;
          //probe.Print();
          //std::cout << tag.DeltaR(probe) << std::endl;
          //std::cout << fabs(tag.Pt() - probe.Pt()) << std::endl;
          if (tag.DeltaR(probe) < 0.1 && fabs(tag.Pt() - probe.Pt()) < 1)
            removed = true;
        }
        if (!removed)
          selected_good_leptons_new.push_back(selected_good_leptons.at(ilep));
        if (removed)
        {
          TLorentzVector newmet = getMETp4() + tag;
          setMET(newmet.Pt());
          setMETphi(newmet.Phi());
        }
      }

      //std::cout << " test" << selected_good_leptons.size() << std::endl;
      selected_good_leptons = Leptons(selected_good_leptons_new);
      //std::cout << " test2 " << selected_good_leptons.size() << std::endl;

      return;

    }

    //################################################################################################
    // return if the correction was "successful"
    // if not, return false and reject the event
    //
    bool correctN2(int ngen, int* gen_pdgId, int* gen_sourceId, float* gen_mass, float* gen_pt, float* gen_eta, float* gen_phi, bool binary_random)
    {

      // if both are N2, skip
      //if (gen_pdgId[2] == 1000023 && gen_pdgId[3] == 1000023)
      //  return false;

      //// if both are C1, choose one to randomly remove
      //if (gen_pdgId[2] == 1000024 && gen_pdgId[3] == 1000024)
      //  return ;

      // if either of the produced susy does not have N2 skip
      //if (gen_pdgId[2] != 1000023 && gen_pdgId[3] != 1000023)
      //  return false;

      //  0 *        -3 *      2212 *
      //  1 *        21 *      2212 *
      //  2 *   1000024 *        -3 *
      //  3 *   1000023 *        -3 *
      //  4 *        21 *        -3 *
      //  5 *        -4 *        -3 *
      //  6 *  -1000015 *   1000024 *
      //  7 *        16 *   1000024 *
      //  8 *   1000013 *   1000023 *
      //  9 *       -13 *   1000023 *
      // 10 *       -15 *  -1000015 *
      // 11 *        13 *   1000013 *

      // vector to hold the indices
      std::vector<int> gen_idx;

      // Loop over and select indices
      for (int igen = 0; igen < ngen; ++igen)
      {

        // NOTE: If there are taus, don't even bother
        if (abs(gen_pdgId[igen]) == 15)
          return false;

        // NOTE: If there are pions don't even bother
        if (abs(gen_pdgId[igen]) == 211)
          return false;

        if (abs(gen_pdgId[igen]) != 1000022)
          gen_idx.push_back(igen);
      }

      // find out which mode this is
      enum {
        kC1N2 = 0,
        kN2N1 = 1,
        kC1C1 = 2,
        kC1N1 = 3,
        kN2N2 = 4,
      };
      int prod_mode = -1;

      int ewkino0_pdgId_unsorted = abs(gen_pdgId[2]);
      int ewkino1_pdgId_unsorted = abs(gen_pdgId[3]);
      int ewkino0_pdgId = ewkino0_pdgId_unsorted > ewkino1_pdgId_unsorted ? ewkino0_pdgId_unsorted : ewkino1_pdgId_unsorted;
      int ewkino1_pdgId = ewkino0_pdgId_unsorted > ewkino1_pdgId_unsorted ? ewkino1_pdgId_unsorted : ewkino0_pdgId_unsorted;

      if (ewkino0_pdgId == 1000024 && ewkino1_pdgId == 1000024) prod_mode = kC1C1;
      if (ewkino0_pdgId == 1000024 && ewkino1_pdgId == 1000023) prod_mode = kC1N2;
      if (ewkino0_pdgId == 1000024 && ewkino1_pdgId == 1000022) prod_mode = kC1N1;
      if (ewkino0_pdgId == 1000023 && ewkino1_pdgId == 1000022) prod_mode = kN2N1;
      if (ewkino0_pdgId == 1000023 && ewkino1_pdgId == 1000023) prod_mode = kN2N2;

      int ewkino_pdgId_to_remove = 0;

      switch (prod_mode)
      {
        // total two e/mu in the event, remove randomly one (the random number will be Vbf::mt2tree.evt%2)
        case kC1C1:
          ewkino_pdgId_to_remove = 1000024;
          break;
        // total three e/mu in the event, remove corresponding to N2
        case kC1N2:
          ewkino_pdgId_to_remove = 1000023;
          break;
        // Just skip for now this is harder to deal with
        case kN2N2: return false; break;
        // Don't remove anything and exit.
        case kC1N1: return true; break;
        // total two e/mu in the event, accept as is.
        case kN2N1: return true; break;
      }

      if (ewkino_pdgId_to_remove == 0)
      {
        printTruth(ngen, gen_pdgId, gen_sourceId, gen_mass, gen_pt, gen_eta, gen_phi);
        TString msg = TString::Format("VBFSUSYUtilities::correctN2() got no Ewkino decays to remove from the event. The function shouldn't reach this point. check the code.");
        PrintUtilities::error(msg);
      }

      std::vector<int> lep_to_rm_idx;

      // add if from N2/C1 directly and is to be removed
      if (abs(gen_sourceId[gen_idx[ 7]]) == ewkino_pdgId_to_remove && (abs(gen_pdgId[gen_idx[ 7]]) == 11 || abs(gen_pdgId[gen_idx[ 7]]) == 13) ) lep_to_rm_idx.push_back(gen_idx[ 7]);
      if (abs(gen_sourceId[gen_idx[ 9]]) == ewkino_pdgId_to_remove && (abs(gen_pdgId[gen_idx[ 9]]) == 11 || abs(gen_pdgId[gen_idx[ 9]]) == 13) ) lep_to_rm_idx.push_back(gen_idx[ 9]);

      int pdgid_ewkino_derived_susy = 0;
      if (abs(gen_sourceId[gen_idx[6]]) == ewkino_pdgId_to_remove) pdgid_ewkino_derived_susy = gen_pdgId[gen_idx[6]];
      if (abs(gen_sourceId[gen_idx[8]]) == ewkino_pdgId_to_remove) pdgid_ewkino_derived_susy = gen_pdgId[gen_idx[8]];

      if (pdgid_ewkino_derived_susy == 0)
      {
        printTruth(ngen, gen_pdgId, gen_sourceId, gen_mass, gen_pt, gen_eta, gen_phi);
        TString msg = TString::Format("VBFSUSYUtilities::correctN2() got zero slepton from N2. This is very weird");
        PrintUtilities::error(msg);
      }

      // add if from the derived SUSY particle from N2
      if (prod_mode == kC1N2)
      {
        if (gen_sourceId[gen_idx[10]] == pdgid_ewkino_derived_susy && (abs(gen_pdgId[gen_idx[11]]) == 11 || abs(gen_pdgId[gen_idx[11]]) == 13)) lep_to_rm_idx.push_back(gen_idx[10]);
        if (gen_sourceId[gen_idx[11]] == pdgid_ewkino_derived_susy && (abs(gen_pdgId[gen_idx[11]]) == 11 || abs(gen_pdgId[gen_idx[11]]) == 13)) lep_to_rm_idx.push_back(gen_idx[11]);
      }
      // add if C1C1 mode, there will always be two 11 or 13, so just add them all
      else if (prod_mode == kC1C1)
      {
        if (abs(gen_pdgId[gen_idx[10]]) == 11 || abs(gen_pdgId[gen_idx[10]]) == 13) lep_to_rm_idx.push_back(gen_idx[10]);
        if (abs(gen_pdgId[gen_idx[11]]) == 11 || abs(gen_pdgId[gen_idx[11]]) == 13) lep_to_rm_idx.push_back(gen_idx[11]);
      }

      if (lep_to_rm_idx.size() == 0)
      {
        printTruth(ngen, gen_pdgId, gen_sourceId, gen_mass, gen_pt, gen_eta, gen_phi);
        TString msg = TString::Format("VBFSUSYUtilities::correctN2() got zero lepton to remove from N2 or C1. This is very weird");
        PrintUtilities::error(msg);
      }

      if (prod_mode == kC1N2 && lep_to_rm_idx.size() == 3)
        return false;

      if (lep_to_rm_idx.size() != 2)
      {
        printTruth(ngen, gen_pdgId, gen_sourceId, gen_mass, gen_pt, gen_eta, gen_phi);
        TString msg = TString::Format("VBFSUSYUtilities::correctN2() got %d leptons to remove from prod mode = %d This is very weird", (int) lep_to_rm_idx.size(), prod_mode);
        PrintUtilities::error(msg);
      }

      if (prod_mode == kC1C1)
      {
        if (binary_random)
          lep_to_rm_idx.erase(lep_to_rm_idx.begin());
        else
          lep_to_rm_idx.erase(lep_to_rm_idx.begin()+1);
      }

      removeGoodLeptonsOverlappingWithTruthLeptonsAndAddToMET(gen_mass, gen_pt, gen_eta, gen_phi, lep_to_rm_idx);

      return true;
    }

  }

}


//eof
