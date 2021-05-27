void setStyle() {
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(57);
  gStyle->SetOptTitle(0);
}
void print_fit(const char* argv) {
  TCanvas* canva = new TCanvas("canva", "Data Fitting");
  canva->SetGrid();
  TGraph* graph_data = new TGraph(argv, "%lg %lg");
  graph_data->SetFillColor(kGray + 1);
  TGraph* graph_prev = new TGraph("logistic_pred.dat", "%lg %lg");
  graph_prev->SetLineColor(kRed + 1);
  graph_prev->SetLineWidth(2);
  TMultiGraph* multi = new TMultiGraph;
  multi->SetTitle(
      "Pandemy data fitting using the logistic model; days of pandemic; number "
      "of cases");
  multi->Add(graph_data, "B");
  multi->Add(graph_prev, "L");
  multi->Draw();
  multi->Draw("A");
}
