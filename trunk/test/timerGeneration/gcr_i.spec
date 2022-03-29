
routine= 
void do_gcr_i_loop(double *T1, double *T2, double *S, double *V, unsigned n, unsigned j) {
      for (unsigned i=0; i < j; i++) {
        double beta = 0;
        for (unsigned k = 0; k < n; k++)
            beta = beta + V[i*n + k] * T2[k];
        for (unsigned k = 0; k < n; k++) {
            T1[k] -= beta * S[i*n+k];
            T2[k] -= beta * V[i*n+k];
        }
      }
}

init={ 
n=Macro(NS,35000);
j=Macro(MS,1000);
T1=Vector(double, RANDOM, flush, n);
T2=Vector(double, RANDOM, flush, n);
S=Matrix(double, j, n, RANDOM, flush);
V=Matrix(double, j, n, RANDOM, flush);
} ; 
returns (T1,T2);
flop="6*n*j";

