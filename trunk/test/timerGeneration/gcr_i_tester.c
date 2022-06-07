#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef RANDSEED
#define RANDSEED 1
#endif


/* routine to test*/
void do_gcr_i_loop(double* T1,double* T2,double* S,double* V,unsigned n,unsigned j) ;
/* macro for the value of routine parameter */
#ifndef NS
#define NS 35000
#endif
/* macro for the value of routine parameter */
#ifndef MS
#define MS 1000
#endif
void do_gcr_i_loop_ref(double* T1,double* T2,double* S,double* V,unsigned n,unsigned j) {
   for (unsigned i=0; i<j-1; i++)
     {
        double beta=0;
        for (unsigned k=0; k<n; k++)
          {
             beta = beta+V[i*n+k]*T2[k];
          }
        for (unsigned k=0; k<n; k++)
          {
             T1[k] = T1[k]-beta*S[i*n+k];
             T2[k] = T2[k]-beta*V[i*n+k];
          }
     }
}

int main(int argc, char **argv) 
{
  
  /* induction variables */
  int __pt_i0, __pt_i1, __pt_i2;
  
  
  
  /* Declaring parameters of the routine */
  double* T1_comp;
  double* T1;
  double* T2_comp;
  double* T2;
  double* S;
  double* V;
  unsigned n;
  unsigned j;
  double* T1_buf;
  int T1_size;
  double* T2_buf;
  int T2_size;
  double* S_buf;
  int S_size;
  double* V_buf;
  int V_size;
  double* T2_comp_buf;
  int T2_comp_size;
  double* T1_comp_buf;
  int T1_comp_size;
  
  /* parameter initializations */
  srand(RANDSEED);
  n = NS;
  j = MS;
  T1_size=n;
  T1_buf = (double*)calloc(T1_size, sizeof(double));
  T2_size=n;
  T2_buf = (double*)calloc(T2_size, sizeof(double));
  S_size=j*n;
  S_buf = (double*)calloc(S_size, sizeof(double));
  V_size=j*n;
  V_buf = (double*)calloc(V_size, sizeof(double));
  T2_comp_size=n;
  T2_comp_buf = (double*)calloc(T2_comp_size, sizeof(double));
  T1_comp_size=n;
  T1_comp_buf = (double*)calloc(T1_comp_size, sizeof(double));
  for (__pt_i0=0; __pt_i0<T1_size; ++__pt_i0)
  {
    T1_buf[__pt_i0] = rand();; 
  }
  T1 = T1_buf;
  for (__pt_i0=0; __pt_i0<T2_size; ++__pt_i0)
  {
    T2_buf[__pt_i0] = rand();; 
  }
  T2 = T2_buf;
  for (__pt_i0=0; __pt_i0<S_size; ++__pt_i0)
  {
    S_buf[__pt_i0] = rand();; 
  }
  S = S_buf;
  for (__pt_i0=0; __pt_i0<V_size; ++__pt_i0)
  {
    V_buf[__pt_i0] = rand();; 
  }
  V = V_buf;
  for (__pt_i0=0; __pt_i0<T2_comp_size; ++__pt_i0)
  {
    T2_comp_buf[__pt_i0] = rand();; 
  }
  T2_comp = T2_comp_buf;
  for (__pt_i0=0; __pt_i0<T1_comp_size; ++__pt_i0)
  {
    T1_comp_buf[__pt_i0] = rand();; 
  }
  T1_comp = T1_comp_buf;
  for (__pt_i0=0; __pt_i0<T2_size; ++__pt_i0)
  {
    T2_comp_buf[__pt_i0] = T2_buf[__pt_i0];
  }
  for (__pt_i0=0; __pt_i0<T1_size; ++__pt_i0)
  {
    T1_comp_buf[__pt_i0] = T1_buf[__pt_i0];
  }
  do_gcr_i_loop (T1_comp,T2_comp,S,V,n,j);
  
  do_gcr_i_loop_ref (T1,T2,S,V,n,j);
  
  {
  int diff_flag = 0;
  for (__pt_i0=0; __pt_i0<n; ++__pt_i0)
  {
    if(T2_comp_buf[__pt_i0] != T2_buf[__pt_i0]) {
      diff_flag = 1;
      printf("Position %d (%f) and Position %d (%f) differ by %.15f\n", __pt_i0,
          T2_comp_buf[__pt_i0], __pt_i0, T2_buf[__pt_i0],
      	fabs(T2_comp_buf[__pt_i0]-T2_buf[__pt_i0]));
    }
    /*else {
      printf("Identical output at index %d\n", __pt_i0);
    } */
  }
  if(diff_flag) {
    printf("Output differs\n");
  }else {
    printf("Output is identical\n");
  }
  }
  {
  int diff_flag = 0;
  for (__pt_i0=0; __pt_i0<n; ++__pt_i0)
  {
    if(T1_comp_buf[__pt_i0] != T1_buf[__pt_i0]) {
      diff_flag = 1;
      printf("Position %d (%f) and Position %d (%f) differ by %.15f\n", __pt_i0,
          T1_comp_buf[__pt_i0], __pt_i0, T1_buf[__pt_i0],
      	fabs(T1_comp_buf[__pt_i0]-T1_buf[__pt_i0]));
    }
    /*else {
      printf("Identical output at index %d\n", __pt_i0);
    } */
  }
  if(diff_flag) {
    printf("Output differs\n");
  }else {
    printf("Output is identical\n");
  }
  }
  return(0);
}
