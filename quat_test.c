#include "linmath.h"
#include <math.h>
#include <stdio.h>

void copy_quat(quat dest, quat src) {
  dest[0] = src[0];
  dest[1] = src[1];
  dest[2] = src[2];
  dest[3] = src[3];
}

void rot_quat(quat res, quat target, quat rot) {
  quat inv_rot;
  quat prod;
  quat_conj(inv_rot, rot);
  quat_mul(prod, rot, target);
  quat new_prod;
  quat_mul(new_prod, prod, inv_rot);
  copy_quat(res, new_prod);
}

void quat_print(quat q) {
  printf("%f\n", q[0]);
  printf("%f\n", q[1]);
  printf("%f\n", q[2]);
  printf("%f\n", q[3]);
  printf("\n");
}

int main() {
  vec3 up = {0, 0, 1};
  quat q;
  quat_rotate(q, M_PI / 8, up);
  quat cur_orientation = {1, 0, 0, 0};
  for (int i = 0; i <= 8; i++) {
    quat_print(cur_orientation);
    rot_quat(cur_orientation, cur_orientation, q);
  }
}
