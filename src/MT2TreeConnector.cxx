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
    lepton.charge       = mytree.lep_charge[ilep];
    lepton.pdgId        = mytree.lep_pdgId[ilep];
    lepton.dxy          = mytree.lep_dxy[ilep];
    lepton.dz           = mytree.lep_dz[ilep];
    lepton.tightId      = mytree.lep_tightId[ilep];
    lepton.heepId       = mytree.lep_heepId[ilep];
    lepton.relIso03     = mytree.lep_relIso03[ilep];
    lepton.relIso04     = mytree.lep_relIso04[ilep];
    lepton.miniRelIso   = mytree.lep_miniRelIso[ilep];
    lepton.relIsoAn04   = mytree.lep_relIsoAn04[ilep];
    lepton.mcMatchId    = mytree.lep_mcMatchId[ilep];
    lepton.lostHits     = mytree.lep_lostHits[ilep];
    lepton.convVeto     = mytree.lep_convVeto[ilep];
    lepton.tightCharge  = mytree.lep_tightCharge[ilep];
    lepton.mva          = mytree.lep_mva[ilep];
    lepton.ptRatio      = mytree.lep_ptRatio[ilep];
    lepton.ptRel        = mytree.lep_ptRel[ilep];
    lepton.tightIdNoIso = mytree.lep_tightIdNoIso[ilep];
    lepton.sip3d        = mytree.lep_sip3d[ilep];
    lepton.p4.SetPtEtaPhiM(mytree.lep_pt[ilep], mytree.lep_eta[ilep], mytree.lep_phi[ilep], mytree.lep_mass[ilep]);
    if (isGoodLepton(lepton))
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
    jet.btagCSV       = mytree.jet_btagCSV[ijet];
    jet.rawPt         = mytree.jet_rawPt[ijet];
    jet.mcPt          = mytree.jet_mcPt[ijet];
    jet.mcFlavour     = mytree.jet_mcFlavour[ijet];
    jet.hadronFlavour = mytree.jet_hadronFlavour[ijet];
    jet.qgl           = mytree.jet_qgl[ijet];
    jet.area          = mytree.jet_area[ijet];
    jet.id            = mytree.jet_id[ijet];
    jet.puId          = mytree.jet_puId[ijet];
    jet.p4.SetPtEtaPhiM(mytree.jet_pt[ijet], mytree.jet_eta[ijet], mytree.jet_phi[ijet], mytree.jet_mass[ijet]);
    if (isGoodJet(jet))
      jets.push_back(jet);
  }
  return jets;
}

ObjUtil::Jets getBJets(MT2Tree& mytree)
{
  ObjUtil::Jets jets;
  for (int ijet = 0; ijet < mytree.njet; ++ijet)
  {
    ObjUtil::Jet jet;
    jet.btagCSV       = mytree.jet_btagCSV[ijet];
    jet.rawPt         = mytree.jet_rawPt[ijet];
    jet.mcPt          = mytree.jet_mcPt[ijet];
    jet.mcFlavour     = mytree.jet_mcFlavour[ijet];
    jet.hadronFlavour = mytree.jet_hadronFlavour[ijet];
    jet.qgl           = mytree.jet_qgl[ijet];
    jet.area          = mytree.jet_area[ijet];
    jet.id            = mytree.jet_id[ijet];
    jet.puId          = mytree.jet_puId[ijet];
    jet.p4.SetPtEtaPhiM(mytree.jet_pt[ijet], mytree.jet_eta[ijet], mytree.jet_phi[ijet], mytree.jet_mass[ijet]);
    if (isGoodBJet(jet))
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
  met.p4.SetPtEtaPhiM(mytree.met_pt, 0, mytree.met_phi, 0);
  return met;
}

bool isGoodLepton(ObjUtil::Lepton& lepton)
{
  if ( !(lepton.p4.Pt() >= 5.                                        ) ) return false;
  if ( (abs(lepton.pdgId) == 11) && !( (fabs(lepton.p4.Eta()) < 2.5) ) ) return false;
  if ( (abs(lepton.pdgId) == 13) && !( (fabs(lepton.p4.Eta()) < 2.4) ) ) return false;
  if ( !( fabs(lepton.sip3d) < 2.                                    ) ) return false;
  if ( !( fabs(lepton.dxy)   < 0.01                                  ) ) return false;
  if ( !( fabs(lepton.dz)    < 0.01                                  ) ) return false;
  if ( !( fabs(lepton.relIso03) < 0.5                                ) ) return false;
  if ( !( fabs(lepton.relIso03*lepton.p4.Pt()) < 5.                  ) ) return false;
  //if ( (abs(lepton.lep_pdgId) == 11) && !( (lepton.lep_tightId > ELECTRON_ID) ) ) return false;
  //if ( (abs(lepton.lep_pdgId) == 13) && !( (lepton.lep_tightId > MUON_ID)     ) ) return false;
  return true;
}

bool isGoodJet(ObjUtil::Jet& jet)
{
  if ( !(jet.p4.Pt() > 25. ) ) return false;
  return true;
}

bool isGoodBJet(ObjUtil::Jet& jet)
{
  if ( !(jet.p4.Pt() > 25.        ) ) return false;
  if ( !(fabs(jet.p4.Eta()) < 2.4 ) ) return false;
  if ( !(jet.btagCSV > 0.46       ) ) return false;
  return true;
}

//eof
