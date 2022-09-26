#include "vectormach.h"

int main(){
  VectorMach vmach;

  int dims[] = { 3, 3, 3 };

  auto vmtr = vmach.create_v_mtr(dims);

  return 0;
}
