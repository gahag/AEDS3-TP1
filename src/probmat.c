#include "probmat.h"

#include <assert.h>


ProbMat mk_probmat(Probability* matrix, size_t size) {
  assert(size > 1);
  
  return (ProbMat) {
    .size = size,
    .data = matrix
  };
}


size_t probmat_size(const ProbMat mat) {
  return mat.size;
}

Probability* probmat_query(const ProbMat mat, size_t i, size_t j) {
  assert(mat.data != NULL);
  assert(i < mat.size && j < mat.size);
  
  Probability (*data)[mat.size][mat.size] = (void*) mat.data;
  
  return &(*data)[i][j];
}
