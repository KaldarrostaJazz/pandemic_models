#ifndef FITGAUS_HPP
#define FITGAUS_HPP
#include <cmath>
#include <iostream>
#include <numeric>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

double const invSqrt2Pi = 0.3989422804014327;
double const invSqrt2 = 0.7071067811865475;

class Gaus {
 public:
  Gaus(std::vector<double>& x, double mean, double sigma);
  Gaus(int start, int end, double mean, double sigma);
  std::vector<double> noCumulative();
  std::vector<double> cumulative();

 private:
  std::vector<double> m_xvec;
  double m_mean;
  double m_sigma;
};

class GetVal {
 public:
  GetVal(std::vector<double> sample);
  GetVal(std::vector<double> sample, std::vector<double> weights);
  double mean();
  double stdDev();
  double getN();
  double getW();

 private:
  std::vector<double> m_sample;
  std::vector<double> m_weights;
  int N = m_sample.size();
  double W = std::accumulate(m_weights.begin(), m_weights.end(), 0.);
};
inline doule GetVal::getN() { return N; }
inline double GetVal::getW() { return W; }
#endif
