// /*
//  * Tema 2 ASC
//  * 2022 Spring
//  */

#include "utils.h"

void BxC(int N, double *A, double *B, double *result) {
    int i, j, k;

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			for (k = 0; k < N; ++k) {
				result[i * N + j] += A[i * N + k] * B[k * N + j];
			}
		}
	}
}

void BtxB(int N, double *A, double *B, double *result) {
    int i, j, k;

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			for (k = 0; k < N; ++k) {
				result[i * N + j] += A[k * N + i] * B[k * N + j];
			}
		}
	}
}

void AxAt(int N, double *A, double *B, double *result) {
    int i, j, k;

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			for (k = i; k < N; ++k) {
				result[i * N + j] += A[i * N + k] * B[j * N + k];
			}
		}
	}
}

/*
 * Add your unoptimized implementation here
 */
double* my_solver(int N, double *A, double* B) {

	
	double *C = (double *) calloc(N * N, sizeof(double));
	if (!C)
		exit(EXIT_FAILURE);
	
	double *D = (double *) calloc(N * N, sizeof(double));
	if (!D)
		exit(EXIT_FAILURE);
	
	double *E = (double *) calloc(N * N, sizeof(double));
	if (!E)
		exit(EXIT_FAILURE);
	
	double *result = (double *) calloc(N * N, sizeof(double));
	if (!result)
		exit(EXIT_FAILURE);

	
	// C = A x A'
	AxAt(N, A, A, C);

	// D = B x C	
	BxC(N, B, C, D);

	// E = B' x B
	BtxB(N, B, B, E);

	// result = D + E
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			result[i * N + j] += D[i * N + j] + E[i * N + j];
		}
	}

	free(C);
	free(D);
	free(E);
	return result;
}
