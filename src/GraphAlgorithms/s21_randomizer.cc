//
// Created by joaquind on 27.12.23.
//

#include "s21_randomizer.h"

namespace s21 {
int Randomizer::GetCityNumber(const std::vector<Chance> &chances) {
  double cumulative_chance{};
  double random_num{dist_(mt_)};
  for (const auto &chance : chances) {
    cumulative_chance += chance.chance;
    if (random_num < cumulative_chance)
      return chance.city;
  }
  return -1;
}
} // namespace s21