// /*
//  * Tema 2 ASC
//  * 2022 Spring
//  */

#include "utils.h"

void AxAt(int N, double* A, double *B, double *result) {
	register int i, j, k;

	for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            register double sum = 0.0;
            for (k = i; k < N; ++k) {
                sum += A[i * N + k] * B[j * N + k];
            }
            result[i * N + j] = sum;
        }
    }
}

void BxC(int N, double* A, double* B, double *result) {
	register int i, j, k;

	for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            register double sum = 0.0;
            for (k = 0; k < N; ++k) {
                sum += A[i * N + k] * B[k * N + j];
            }
            result[i * N + j] = sum;
        }
    }
}

void BtxB(int N, double* A, double* B, double *result) {
	register int i, j, k;

	for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            double register sum = 0;
            for (k = 0; k < N; k++) {
                sum += B[k * N + i] * B[k * N + j];
            }
            result[i * N + j] = sum;
        }
    }
}

double* my_solver(int N, double *A, double* B) {

	double *C = calloc (N * N, sizeof (double));
	if (!C)
		exit(EXIT_FAILURE);

    double *D = calloc (N * N, sizeof (double));
	if (!D)
		exit(EXIT_FAILURE);

    double *E = calloc (N * N, sizeof (double));
	if (!E)
		exit(EXIT_FAILURE);
	
    double *res = calloc (N * N, sizeof (double));
	if (!res)
		exit(EXIT_FAILURE);
    
	
	register int i, j;

    /* C = A * A' */
	AxAt(N, A, A, C);

    /* D = B x C */
    BxC(N, B, C, D);

    /* E = B' x B */
	BtxB(N, B, B, E);

    /* res = D + E */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            res[i * N + j] = D[i * N + j] + E[i * N + j];
        }
    }

	free(C);
	free(D);
	free(E);

    return res;
}
