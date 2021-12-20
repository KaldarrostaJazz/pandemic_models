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
Double_t double_gaussian(Double_t* x, Double_t* par) {
	Float_t xx = x[0];
	Double_t gaus_1 = par[0] * exp(-0.5 * (xx - par[1]) * (xx - par[1]) / par[2]);
	Double_t gaus_2 = par[3] * exp(-0.5 * (xx - par[4]) * (xx - par[4]) / par[5]);
	Double_t val = gaus_1 + gaus_2;
	return val;
}
void italy() {
  gROOT->SetStyle("Modern");
  gStyle->SetOptFit(111);
  gStyle->SetOptStat(0);
  //TF1* logi = new TF1("logi", logistic, 620., 700., 3);
  //logi->SetLineColor(kBlue);
  //logi->SetParameters(300, 0.12, 66000);
  //logi->SetParNames("Costant", "r", "K");
  //TF1* gomp = new TF1("gomp", gompertz, 620., 700., 3);
  //gomp->SetLineColor(kGreen);
  //gomp->SetParameters(-100, 0.2, 8000);
  //gomp->SetParNames("Costant", "r", "K");
  //TF1* logi_gomp = new TF1("logi_gomp", sum, 620., 700., 6);
  //logi_gomp->SetLineColor(kYellow);
  //logi_gomp->SetParameters(300, 0.12, 65000, -100, 0.3, 7000);
  //TF1* d_gaus = new TF1("d_gaus", double_gaussian, 620., 700., 6);
  //d_gaus->SetLineColor(kOrange);
  //d_gaus->SetParameters(100000, 600, 45, 100000, 900, 45);
  TGraph* graph = new TGraph("dati.csv", "%lg %*lg %lg", " \t,");
  graph->SetTitle("Dati Italia dal 4/11/2021 (giorno 620); Giorni; Nuovi casi;");
  graph->SetMarkerStyle(kFullCircle);
  graph->SetMarkerColor(kBlack);
  TAxis* xAxis = graph->GetXaxis();
  xAxis->SetLimits(620, 700);
  graph->GetHistogram()->SetMaximum(9e4);
  //cout << "\nLogistic fit:\n";
  //graph->Fit("logi", "R");
  //cout << "\nGompertz fit:\n";
  //graph->Fit("gomp", "R");
  //cout << "\nLogistic + Gompertz fit:\n";
  //graph->Fit("logi_gomp", "R");
  //cout << "\nGaussian + Gaussian fit:\n";
  //graph->Fit("d_gaus");
  //cout << "\nGaussian fit:\n";
  //graph->Fit("gaus");
  //TLegend* leg = new TLegend(0.6, 0.75, 0.9, 0.9);
  //leg->SetFillColor(0);
  //leg->AddEntry(graph, "Dati");
  //leg->AddEntry(logi, "Fit logistico");
  //leg->AddEntry(gomp, "Fit gompertz");
  //leg->AddEntry(logi_gomp, "Fit logistico + gompertz");
  TF1* gauss = new TF1("gauss", "gaus", 620, 700);
  gauss->SetLineColor(kRed);
  gauss->SetLineStyle(kDotted);
  //gauss->SetParameters(15e5, 800, 80);

  graph->Fit("gauss");
  graph->Fit("expo");

  TF1* func = graph->GetFunction("expo");
  func->SetRange(620, 700);
  func->SetLineColor(kRed);
  TCanvas* canva = new TCanvas("Fit", "Fit");
  canva->SetGrid();
  graph->Draw("AP");
  func->Draw("SAME");
  gauss->Draw("SAME");
  //d_gaus->Draw("SAME");
  //logi->Draw("SAME");
  //gomp->Draw("SAME");
  //logi_gomp->Draw("SAME");
  //leg->Draw("SAME");
  canva->Print("Fit_Italia_4_11_2021_19_12_2021.pdf");
}
