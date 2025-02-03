#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<complex.h>

void generate_alphas(double alpha_start, double alpha_end, int N, double *alpha){
	double r = pow(alpha_end / alpha_start, 1.0/(N-1));
	printf("Value of r: %lf\n ", r);
	alpha[0] = alpha_start;
	for (int i=1; i<N; i++){
		alpha[i] = alpha[i-1]*r;
	}
}

int main(){
	double alpha_start, alpha_end;
	int N;

	printf("Enter alpha_start: ");
	scanf("%lf", &alpha_start);
	printf("Enter alpha_end: ");
	scanf("%lf", &alpha_end);
	printf("Enter N: ");
	scanf("%d", &N);

	double *alpha = (double *)malloc(N*sizeof(double));
	generate_alphas(alpha_start,alpha_end,N,alpha);

	FILE *out = fopen("normal_float.txt","w");
	for (int i=0; i<N; i++){
		float a = alpha[i];
		double complex root1 = -a + csqrt(a*a - 1);
		double complex root2 = -a - csqrt(a*a - 1);

		fprintf(out, "%0.15lf,%0.15lf,%0.15lf,%0.15lf\n", creal(root1),cimag(root1),creal(root2),cimag(root2));
	}

	fclose(out);
	free(alpha);
	return 0;
}
