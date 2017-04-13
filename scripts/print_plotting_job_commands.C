//
//
int determine_nbins(TH1F* hist)
{

  std::vector<int> possible_bins;
  possible_bins.push_back(2);
  possible_bins.push_back(3);
  possible_bins.push_back(4);
  possible_bins.push_back(5);
  possible_bins.push_back(6);
  possible_bins.push_back(9);
  possible_bins.push_back(10);
  possible_bins.push_back(12);
  possible_bins.push_back(15);
  possible_bins.push_back(18);
  //possible_bins.push_back(20);
  //possible_bins.push_back(30);
  //possible_bins.push_back(36);
  //possible_bins.push_back(45);
  //possible_bins.push_back(60);
  //possible_bins.push_back(90);
  //possible_bins.push_back(180);

  for (unsigned int iconf = 0; iconf < possible_bins.size(); ++iconf)
  {
    TH1F* clonedhist = (TH1F*) hist->Clone();
    clonedhist->Rebin(possible_bins.at(iconf));
    std::vector<float> frac_errors;
    for (int ibin = 1; ibin <= clonedhist->GetNbinsX(); ++ibin)
    {
      float error = clonedhist->GetBinError(ibin);
      float content = clonedhist->GetBinContent(ibin);
      frac_errors.push_back(error / content);
    }
    float sum = 0;
    for (unsigned int icontent = 0; icontent < frac_errors.size(); ++icontent)
    {
      sum += frac_errors.at(icontent);
    }
    float avg = sum / frac_errors.size();
    if (avg < 0.5)
      return 180 / possible_bins.at(iconf);
  }
  return 10;
}

void print_plotting_job_commands()
{
  TFile* file = new TFile("haddoutput/hist_vbf_w.root");
  TList* list = file->GetListOfKeys();
  for (int ikey = 0; ikey < list->GetEntries(); ++ikey)
  {
    TKey* key = (TKey*) list->At(ikey);
    TString histname = key->GetName();
    if (histname.Contains("Cut_vbf"))
    {
      TH1F* hist = (TH1F*) file->Get(key->GetName());
      int desired_nbins = hist->GetNbinsX();
      if (hist->Integral() == 0)
        continue;
      if (!histname.Contains("vbf_n") && !histname.Contains("vbf_lepid"))
        desired_nbins = determine_nbins(hist);
      printf("sh scripts/plot_vbf.sh %50s \\' --autostack --nbinx %3d --auto_scale_signal \\' \\'\\' 100.0 0.0 95.0 \\'\\' \\'1\\' \\'_sigshape\\'\n",
             key->GetName(),
             desired_nbins);
      printf("sh scripts/plot_vbf.sh %50s \\' --autostack --nbinx %3d                     \\' \\'\\' 100.0 0.0 95.0 \\'\\' \\'1\\' \\'_signorm\\'\n",
             key->GetName(),
             desired_nbins);
    }
  }
}
