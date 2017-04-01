// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

#include "susyvbf.h"

int main(int argc, char* argv[])
{

  if (argc != 3 && argc != 4)
  {
    PrintUtilities::print("Usage:");
    PrintUtilities::print("");
    PrintUtilities::print("        ./susyvbf INPUT_FILE_PATH OUTPUT.root [MAXEVENTS]");
    PrintUtilities::print("");
    PrintUtilities::error("Please check your arguement!");
  }

  const char* input_file_path = argv[1];
  const char* output_file_path = argv[2];
  int max_nevents = -1;
  if (argc == 4)
    max_nevents = atoi(argv[3]);

  TChain *chsig = new TChain("mt2");
  chsig->Add(input_file_path);
  MT2TreeLooper(chsig, output_file_path, max_nevents);

}
