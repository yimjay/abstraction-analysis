
void dtrmm_ru(const int M,const int N,const int K,const double alpha,const double *A,const int lda,double *B,const int ldb,const double beta,double *C,const int ldc)
{
	int i, j, k;
	
/*@; BEGIN(nest1=MM_pat[type="double";tri_array=("A")]) @*/
	for(j=0; j < N; j++) { 
		for(i = 0; i < M; i++) {
			for(k = 0; k<=j; k++) {
				B[j*ldb+i] += B[k*ldb+i] * A[j*lda+k];
			}
		}
	}

}

