Double_t logistic(Double_t* x, Double_t* par) {
  Float_t xx = x[0];
  Double_t expo = par[0] * exp(-par[1] * xx);
  Double_t val = par[1] * par[2] * expo / ((1 + expo) * (1 + expo));
  return val;
}
Double_t gompertz(Double_t* x, Double_t* par) {
  Float_t xx = x[0];
  Double_t expo = par[0] * exp(-par[1] * xx);
  Double_t val = -par[1] * par[2] * expo * exp(expo);
  return val;
}
Double_t sum(Double_t* x, Double_t* par) {
  Double_t xx = x[0];
  Double_t expo_l = par[0] * exp(-par[1] * xx);
  Double_t expo_g = par[3] * exp(-par[4] * xx);
  Double_t val_l = par[1] * par[2] * expo_l / ((1 + expo_l) * (1 + expo_l));
  Double_t val_g = -par[4] * par[5] * expo_g * exp(expo_g);
  Double_t val = val_l + val_g;
  return val;
}
void root() {
  gROOT->SetStyle("Modern");
  gStyle->SetOptFit(0);
  // gStyle->SetOptStat("neMR");
  TF1* logi = new TF1("logi", logistic, 0., 60., 3);
  logi->SetLineColor(kBlue);
  logi->SetParameters(30, 0.12, 6600);
  logi->SetParNames("Costant", "r", "K");
  TF1* gomp = new TF1("gomp", gompertz, 0., 60., 3);
  gomp->SetLineColor(kGreen);
  gomp->SetParameters(-8, 0.2, 6650);
  gomp->SetParNames("Costant", "r", "K");
  TF1* logi_gomp = new TF1("logi_gomp", sum, 0., 60., 6);
  logi_gomp->SetLineColor(kYellow);
  logi_gomp->SetParameters(30, 0.12, 6500, -8, 0.3, 700);
  TGraph* graph = new TGraph("geneva.csv", "%lg %*lg %lg", "\t,");
  graph->SetTitle("Dati Ginevra; giorni; nuovi casi;");
  graph->SetMarkerStyle(kFullCircle);
  graph->SetMarkerColor(kBlack);
  cout << "\nLogistic fit:\n";
  graph->Fit("logi", "R");
  cout << "\nGompertz fit:\n";
  graph->Fit("gomp", "R");
  cout << "\nLogistic + Gompertz fit:\n";
  graph->Fit("logi_gomp", "R");
  cout << "\nGaussian fit:\n";
  graph->Fit("gaus");
  TLegend* leg = new TLegend(0.6, 0.75, 0.9, 0.9);
  leg->SetFillColor(0);
  leg->AddEntry(graph, "Dati");
  leg->AddEntry(logi, "Fit logistico");
  leg->AddEntry(gomp, "Fit gompertz");
  leg->AddEntry(logi_gomp, "Fit logistico + gompertz");
  TCanvas* canva = new TCanvas("Fit_Ginevra");
  canva->SetGrid();
  graph->Draw("AP");
  logi->Draw("SAME");
  gomp->Draw("SAME");
  logi_gomp->Draw("SAME");
  leg->Draw("SAME");
  canva->Print("Fit_Ginevra.pdf");
}
