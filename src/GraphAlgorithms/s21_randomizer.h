//
// Created by joaquind on 27.12.23.
//

#ifndef SIMPLENAVIGATOR_S21_RANDOMIZER_H
#define SIMPLENAVIGATOR_S21_RANDOMIZER_H

#include <random>

namespace s21 {

struct Chance {
  int city;
  double chance;
};

class Randomizer {
  Randomizer() : mt_(rd_()){};
  int GetCityNumber(const std::vector<Chance> &chances);

 private:
  std::random_device rd_{};
  std::mt19937 mt_;
  std::uniform_real_distribution<double> dist_{0, 1};
};

}  // namespace s21

#endif  // SIMPLENAVIGATOR_S21_RANDOMIZER_H
