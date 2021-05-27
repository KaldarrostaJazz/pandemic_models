void setStyle() {
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(57);
  gStyle->SetOptTitle(0);
}
void pandemy(const char *argv) {
  TCanvas *c = new TCanvas("c", "Grafico dati pandemia");
  c->SetGrid();
  TGraph *g1 = new TGraph(argv, "%lg %lg %*lg %*lg");
  g1->SetLineColor(kRed);
  TGraph *g2 = new TGraph(argv, "%lg %*lg %lg %*lg");
  g2->SetLineColor(kBlue);
  TGraph *g3 = new TGraph(argv, "%lg %*lg %*lg %lg");
  g3->SetLineColor(kYellow);
  TMultiGraph *mg = new TMultiGraph;
  mg->SetTitle("Andamento Pandemia; tempo(days); persone");
  mg->Add(g1);
  mg->Add(g2);
  mg->Add(g3);
  mg->Draw("AC");
}
