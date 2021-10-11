#include "FitGaus.hpp"

Gaus::Gaus(std::vector<double>& x, double mean, double sigma)
    : m_xvec{x}, m_mean{mean}, m_sigma{sigma} {
  if (x.empty()) {
    throw std::runtime_error("Insert a valid x range\n");
  }
  for (long unsigned int i = 1; i != x.size(); ++i) {
    if (x[i - 1] >= x[i]) {
      throw std::runtime_error("Insert a valid x range\n");
    }
  }
}

Gaus::Gaus(int start, int range, double mean, double sigma)
    : m_xvec(range, start), m_mean{mean}, m_sigma{sigma} {
  if (range <= 0) {
    throw std::runtime_error("Insert a valid x range\n");
  }
  std::iota(m_xvec.begin(), m_xvec.end(), 1);
}

std::vector<double> Gaus::noCumulative() {
  std::vector<double> result;
  for (double x : m_xvec) {
    double z = (x - m_mean) / m_sigma;
    double y = invSqrt2Pi / m_sigma * std::exp(-0.5 * z * z);
    result.push_back(y);
  }
  return result;
}

std::vector<double> Gaus::cumulative() {
  std::vector<double> result;
  for (double x : m_xvec) {
    double z = (x - m_mean) / m_sigma;
    double y = 0.5 * (1 + std::erf(z * invSqrt2));
    result.push_back(y);
  }
  return result;
}

GetVal::GetVal(std::vector<double> sample)
    : m_sample{sample}, m_weights(N, 1.) {
  if (sample.empty()) {
    throw std::runtime_error("The sample vector is empty\n");
  }
}

GetVal::GetVal(std::vector<double> sample, std::vector<double> weights)
    : m_sample{sample}, m_weights{weights} {
  if (sample.empty() || weights.empty()) {
    throw std::runtime_error(
        "The sample vector and/or the weights vector is empty\n");
  }
  if (weights.size() != sample.size()) {
    throw std::runtime_error("There aren't enough weights\n");
  }
}

double GetVal::mean() {
  double result{0.};
  for (int i = 0; i != N; ++i) {
    result += m_sample[i] * m_weights[i];
  }
  return result / W;
}

double GetVal::stdDev() {
  double result{0.};
  double m = mean();
  for (int i = 0; i != N; ++i) {
    double dev = m_sample[i] - m;
    result += m_weights[i] * dev * dev;
  }
  return std::sqrt(result / W);
}
