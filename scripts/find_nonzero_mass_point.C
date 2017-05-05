void find_nonzero_mass_point()
{
  TFile* file = new TFile("haddoutput/hist_signal.root");
  TObjArray* keys = (TObjArray*) file->GetListOfKeys();
  TIter iter(keys);
  TKey* key = 0;
  while ( (key = (TKey*) iter.Next()) )
  {
    TString title = key->GetTitle();
    TString name  = key->GetName();
    if (name.Contains("rawcutflow"))
    {
      TH1F* hist = (TH1F*) file->Get(name);
      double nevent = hist->GetBinContent(23);
      if (nevent)
      {
        std::cout << name << std::endl;
      }
    }
  }
}
