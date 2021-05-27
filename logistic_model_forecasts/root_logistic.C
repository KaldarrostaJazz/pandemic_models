void setStyle() {
  gROOT->SetStyle("Modern");
  gStyle->SetPalette(62);
  gStyle->SetOptTitle(0);
}
void print_fit(const char* argv) {
	std::string name= std::string("Fitting of ") + std::string(argv);
	const char* name_conv = name.c_str();
  TCanvas* canva = new TCanvas("canva", "Data Fitting");
  canva->SetGrid();
  TGraph* graph_data = new TGraph(argv, "%lg %lg");
  graph_data->SetFillColor(kGray + 1);
  TGraph* graph_prev = new TGraph("logistic_pred.dat", "%lg %lg %*lg");
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
  TLegend* legend = new TLegend(0.1, 0.7, 0.48, 0.9);
  legend->SetHeader(name_conv, "C");
  legend->AddEntry(graph_data, "Experimental data", "f");
  legend->AddEntry(graph_prev, "Model previsions and fitting", "l");
  legend->Draw();
  canva->Print("canva.pdf");
}
