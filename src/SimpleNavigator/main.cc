#include "Controller/s21_controller.h"
#include "Model/s21_model.h"
#include "View/s21_view.h"

int main(int argc, char *argv[]) {
  s21::View view;
  s21::Model model;

  s21::Controller controller(model, view);
  controller.handleInput(argc, argv);
  return 0;
}