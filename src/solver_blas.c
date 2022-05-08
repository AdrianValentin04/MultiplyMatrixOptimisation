/*
 * Tema 2 ASC
 * 2022 Spring
 */
#include "utils.h"
#include "cblas.h"
/* 
 * Add your BLAS implementation here
 */

double* my_solver(int N, double *A, double *B) {
	
	double *C = (double *) calloc(N * N, sizeof(double));
	if (!C) 
		exit(EXIT_FAILURE);

	/* C = B x A */ 
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, N, N, N, 1.0,
			B, N, A, N, 1.0, C, N);

	/* C = C x A' */
	cblas_dtrmm(CblasRowMajor, CblasRight, CblasUpper, CblasTrans, CblasNonUnit,
			N, N, 1.0, A, N, C, N);

	/* C = C + B' x B */
	cblas_dgemm(CblasRowMajor, CblasTrans, CblasNoTrans, N, N, N, 1.0, B,
			N, B, N, 1.0, C, N);
							
	return C;
}
