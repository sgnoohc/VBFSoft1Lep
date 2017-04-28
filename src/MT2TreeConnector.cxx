// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

#include "MT2TreeConnector.h"

ObjUtil::Leptons getLeptons(MT2Tree& mytree)
{
  ObjUtil::Leptons leptons;
  for (int ilep = 0; ilep < mytree.nlep; ++ilep)
  {
    ObjUtil::Lepton lepton;
    lepton.lep_pt           = mytree.lep_pt[ilep];
    lepton.lep_eta          = mytree.lep_eta[ilep];
    lepton.lep_phi          = mytree.lep_phi[ilep];
    lepton.lep_mass         = mytree.lep_mass[ilep];
    lepton.lep_charge       = mytree.lep_charge[ilep];
    lepton.lep_pdgId        = mytree.lep_pdgId[ilep];
    lepton.lep_dxy          = mytree.lep_dxy[ilep];
    lepton.lep_dz           = mytree.lep_dz[ilep];
    lepton.lep_tightId      = mytree.lep_tightId[ilep];
    lepton.lep_heepId       = mytree.lep_heepId[ilep];
    lepton.lep_relIso03     = mytree.lep_relIso03[ilep];
    lepton.lep_relIso04     = mytree.lep_relIso04[ilep];
    lepton.lep_miniRelIso   = mytree.lep_miniRelIso[ilep];
    lepton.lep_relIsoAn04   = mytree.lep_relIsoAn04[ilep];
    lepton.lep_mcMatchId    = mytree.lep_mcMatchId[ilep];
    lepton.lep_lostHits     = mytree.lep_lostHits[ilep];
    lepton.lep_convVeto     = mytree.lep_convVeto[ilep];
    lepton.lep_tightCharge  = mytree.lep_tightCharge[ilep];
    lepton.lep_mva          = mytree.lep_mva[ilep];
    lepton.lep_ptRatio      = mytree.lep_ptRatio[ilep];
    lepton.lep_ptRel        = mytree.lep_ptRel[ilep];
    lepton.lep_tightIdNoIso = mytree.lep_tightIdNoIso[ilep];
    lepton.lep_sip3d        = mytree.lep_sip3d[ilep];
    lepton.p4.SetPtEtaPhiM(lepton.lep_pt, lepton.lep_eta, lepton.lep_phi, lepton.lep_mass);
    leptons.push_back(lepton);
  }
  return leptons;
}

ObjUtil::Jets getJets(MT2Tree& mytree)
{
  ObjUtil::Jets jets;
  for (int ijet = 0; ijet < mytree.njet; ++ijet)
  {
    ObjUtil::Jet jet;
    jet.jet_pt            = mytree.jet_pt[ijet];
    jet.jet_eta           = mytree.jet_eta[ijet];
    jet.jet_phi           = mytree.jet_phi[ijet];
    jet.jet_mass          = mytree.jet_mass[ijet];
    jet.jet_btagCSV       = mytree.jet_btagCSV[ijet];
    jet.jet_rawPt         = mytree.jet_rawPt[ijet];
    jet.jet_mcPt          = mytree.jet_mcPt[ijet];
    jet.jet_mcFlavour     = mytree.jet_mcFlavour[ijet];
    jet.jet_hadronFlavour = mytree.jet_hadronFlavour[ijet];
    jet.jet_qgl           = mytree.jet_qgl[ijet];
    jet.jet_area          = mytree.jet_area[ijet];
    jet.jet_id            = mytree.jet_id[ijet];
    jet.jet_puId          = mytree.jet_puId[ijet];
    jet.p4.SetPtEtaPhiM(jet.jet_pt, jet.jet_eta, jet.jet_phi, jet.jet_mass);
    jets.push_back(jet);
  }
  return jets;
}

ObjUtil::METs getMETs(MT2Tree& mytree)
{
  ObjUtil::METs mets;
  return mets;
}

ObjUtil::MET getMET(MT2Tree& mytree)
{
  ObjUtil::MET met;
  met.SetPtEtaPhiM(mytree.met_pt, 0, mytree.met_phi, 0);
  return met;
}

//eof
