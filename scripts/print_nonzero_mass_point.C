void print_nonzero_mass_point()
{
  TFile* file = new TFile("haddoutput/hist_signal.root");
  TH1F* hist = (TH1F*) file->Get("rawcutflow_0.0_150.7_132.4");
  hist->Print("all");
}
