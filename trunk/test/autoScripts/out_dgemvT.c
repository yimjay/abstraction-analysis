#define max(a,b) (((a) < (b))? (b) : (a))
#define min(a,b) (((a) < (b))? (a) : (b))
#include <omp.h>

void dgemvT(const int  M,const int  N,const double  alpha,const double*  A,const int  lda,const double*  X,const int  incX,const double  beta,double*  Y,const int  incY) 
{
   int  i;
   int  j;
   int i_par;
   int j_bk;
   int i_bk;
   double* _Y_buf_fd_0;
   double _Y_1_scalar_0;
   double _Y_1_scalar_1;
   double* _Y_1_scalar_fd_0;
   double _X_2_scalar_0;
   double* _X_2_scalar_fd_0;
   omp_set_num_threads(2);
   #pragma omp  parallel  
    {
    #pragma omp  for private(_X_2_scalar_fd_0,_X_2_scalar_0,_Y_1_scalar_fd_0,_Y_1_scalar_0,_Y_1_scalar_1,_Y_buf_fd_0,j_bk,i_bk,j,i_par,i)
    for (i_par=0; i_par<M; i_par+=256) 
      {
         _Y_buf_fd_0 = Y;
         for (i_bk=0; i_bk<-15+min(256,M-i_par); i_bk+=16) 
           {
              if (0<-15+N)  
                {
                   _Y_1_scalar_fd_0 = _Y_buf_fd_0;
                   for (i=0; i<16; i+=2) 
                     {
                        _Y_1_scalar_0 = _Y_1_scalar_fd_0[i_par];
                        _Y_1_scalar_1 = _Y_1_scalar_fd_0[1+i_par];
                        _X_2_scalar_fd_0 = X;
                        _X_2_scalar_0 = _X_2_scalar_fd_0[0];
                        _Y_1_scalar_0 = beta*_Y_1_scalar_0;
                        _Y_1_scalar_0 = _Y_1_scalar_0+A[i_par*lda+(i_bk*lda+i*lda)]*_X_2_scalar_0;
                        _Y_1_scalar_1 = beta*_Y_1_scalar_1;
                        _Y_1_scalar_1 = _Y_1_scalar_1+A[i_par*lda+(i_bk*lda+(lda+i*lda))]*_X_2_scalar_0;
                        _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                        _X_2_scalar_0 = _X_2_scalar_fd_0[0];
                        _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(1+i_par*lda))]*_X_2_scalar_0;
                        _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(1+i_par*lda)))]*_X_2_scalar_0;
                        _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                        _X_2_scalar_0 = _X_2_scalar_fd_0[0];
                        _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(2+i_par*lda))]*_X_2_scalar_0;
                        _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(2+i_par*lda)))]*_X_2_scalar_0;
                        _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                        _X_2_scalar_0 = _X_2_scalar_fd_0[0];
                        _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(3+i_par*lda))]*_X_2_scalar_0;
                        _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(3+i_par*lda)))]*_X_2_scalar_0;
                        _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                        for (j=4; j<16; j+=4) 
                          {
                             _X_2_scalar_0 = _X_2_scalar_fd_0[0];
                             _Y_1_scalar_0 = _Y_1_scalar_0+A[j+(i_par*lda+(i_bk*lda+i*lda))]*_X_2_scalar_0;
                             _Y_1_scalar_1 = _Y_1_scalar_1+A[j+(i_par*lda+(i_bk*lda+(lda+i*lda)))]*_X_2_scalar_0;
                             _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                             _X_2_scalar_0 = _X_2_scalar_fd_0[0];
                             _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(i_par*lda+(1+j)))]*_X_2_scalar_0;
                             _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(i_par*lda+(1+j))))]*_X_2_scalar_0;
                             _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                             _X_2_scalar_0 = _X_2_scalar_fd_0[0];
                             _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(i_par*lda+(2+j)))]*_X_2_scalar_0;
                             _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(i_par*lda+(2+j))))]*_X_2_scalar_0;
                             _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                             _X_2_scalar_0 = _X_2_scalar_fd_0[0];
                             _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(i_par*lda+(3+j)))]*_X_2_scalar_0;
                             _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(i_par*lda+(3+j))))]*_X_2_scalar_0;
                             _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                          }
                        _Y_1_scalar_fd_0[i_par] = _Y_1_scalar_0;
                        _Y_1_scalar_fd_0[1+i_par] = _Y_1_scalar_1;
                        _Y_1_scalar_fd_0 = 2+_Y_1_scalar_fd_0;
                     }
                }
              for (j_bk=16; j_bk<-15+N; j_bk+=16) 
                {
                   _Y_1_scalar_fd_0 = _Y_buf_fd_0;
                   for (i=0; i<16; i+=2) 
                     {
                        _Y_1_scalar_0 = _Y_1_scalar_fd_0[i_par];
                        _Y_1_scalar_1 = _Y_1_scalar_fd_0[1+i_par];
                        _X_2_scalar_fd_0 = X;
                        for (j=0; j<16; j+=4) 
                          {
                             _X_2_scalar_0 = _X_2_scalar_fd_0[j_bk];
                             _Y_1_scalar_0 = _Y_1_scalar_0+A[j+(j_bk+(i_par*lda+(i_bk*lda+i*lda)))]*_X_2_scalar_0;
                             _Y_1_scalar_1 = _Y_1_scalar_1+A[j+(j_bk+(i_par*lda+(i_bk*lda+(lda+i*lda))))]*_X_2_scalar_0;
                             _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                             _X_2_scalar_0 = _X_2_scalar_fd_0[j_bk];
                             _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(i_par*lda+(j_bk+(1+j))))]*_X_2_scalar_0;
                             _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(i_par*lda+(j_bk+(1+j)))))]*_X_2_scalar_0;
                             _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                             _X_2_scalar_0 = _X_2_scalar_fd_0[j_bk];
                             _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(i_par*lda+(j_bk+(2+j))))]*_X_2_scalar_0;
                             _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(i_par*lda+(j_bk+(2+j)))))]*_X_2_scalar_0;
                             _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                             _X_2_scalar_0 = _X_2_scalar_fd_0[j_bk];
                             _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(i_par*lda+(j_bk+(3+j))))]*_X_2_scalar_0;
                             _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(i_par*lda+(j_bk+(3+j)))))]*_X_2_scalar_0;
                             _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                          }
                        _Y_1_scalar_fd_0[i_par] = _Y_1_scalar_0;
                        _Y_1_scalar_fd_0[1+i_par] = _Y_1_scalar_1;
                        _Y_1_scalar_fd_0 = 2+_Y_1_scalar_fd_0;
                     }
                }
              if (j_bk<N)  
                {
                   _Y_1_scalar_fd_0 = _Y_buf_fd_0;
                   for (i=0; i<16; i+=2) 
                     {
                        _Y_1_scalar_0 = _Y_1_scalar_fd_0[i_par];
                        _Y_1_scalar_1 = _Y_1_scalar_fd_0[i_par+1];
                        _X_2_scalar_fd_0 = X;
                        for (j=0; j<N-j_bk; j+=4) 
                          {
                             _X_2_scalar_0 = _X_2_scalar_fd_0[j_bk];
                             /*SPLIT-START*/if (j_bk+j==0)  
                               _Y_1_scalar_0 = beta*_Y_1_scalar_0;
                             _Y_1_scalar_0 = _Y_1_scalar_0+A[j+(j_bk+(i_par*lda+(i_bk*lda+i*lda)))]*_X_2_scalar_0;
                             /*SPLIT-START*/if (j_bk+j==0)  
                               _Y_1_scalar_1 = beta*_Y_1_scalar_1;
                             _Y_1_scalar_1 = _Y_1_scalar_1+A[j+(j_bk+(i_par*lda+(i_bk*lda+(lda+i*lda))))]*_X_2_scalar_0;
                             _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                             /*Unroll Check*/if (1+j<N-j_bk)  
                               {
                                  _X_2_scalar_0 = _X_2_scalar_fd_0[j_bk];
                                  /*SPLIT-START*/if (j_bk+(1+j)==0)  
                                    _Y_1_scalar_0 = beta*_Y_1_scalar_0;
                                  _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(i_par*lda+(j_bk+(1+j))))]*_X_2_scalar_0;
                                  /*SPLIT-START*/if (j_bk+(1+j)==0)  
                                    _Y_1_scalar_1 = beta*_Y_1_scalar_1;
                                  _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(i_par*lda+(j_bk+(1+j)))))]*_X_2_scalar_0;
                                  _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                               }
                             /*Unroll Check*/if (2+j<N-j_bk)  
                               {
                                  _X_2_scalar_0 = _X_2_scalar_fd_0[j_bk];
                                  /*SPLIT-START*/if (j_bk+(2+j)==0)  
                                    _Y_1_scalar_0 = beta*_Y_1_scalar_0;
                                  _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(i_par*lda+(j_bk+(2+j))))]*_X_2_scalar_0;
                                  /*SPLIT-START*/if (j_bk+(2+j)==0)  
                                    _Y_1_scalar_1 = beta*_Y_1_scalar_1;
                                  _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(i_par*lda+(j_bk+(2+j)))))]*_X_2_scalar_0;
                                  _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                               }
                             /*Unroll Check*/if (3+j<N-j_bk)  
                               {
                                  _X_2_scalar_0 = _X_2_scalar_fd_0[j_bk];
                                  /*SPLIT-START*/if (j_bk+(3+j)==0)  
                                    _Y_1_scalar_0 = beta*_Y_1_scalar_0;
                                  _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(i_par*lda+(j_bk+(3+j))))]*_X_2_scalar_0;
                                  /*SPLIT-START*/if (j_bk+(3+j)==0)  
                                    _Y_1_scalar_1 = beta*_Y_1_scalar_1;
                                  _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(i_par*lda+(j_bk+(3+j)))))]*_X_2_scalar_0;
                                  _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                               }
                          }
                        _Y_1_scalar_fd_0[i_par] = _Y_1_scalar_0;
                        _Y_1_scalar_fd_0[i_par+1] = _Y_1_scalar_1;
                        _Y_1_scalar_fd_0 = _Y_1_scalar_fd_0+2;
                     }
                }
              _Y_buf_fd_0 = _Y_buf_fd_0+16;
           }
         if (i_bk<min(256,M-i_par))  
           {
              if (0<-15+N)  
                {
                   _Y_1_scalar_fd_0 = _Y_buf_fd_0;
                   for (i=0; i<min(256-i_bk,-i_bk+(M-i_par)); i+=2) 
                     {
                        _Y_1_scalar_0 = _Y_1_scalar_fd_0[i_par];
                        _Y_1_scalar_1 = _Y_1_scalar_fd_0[1+i_par];
                        _X_2_scalar_fd_0 = X;
                        _X_2_scalar_0 = _X_2_scalar_fd_0[0];
                        _Y_1_scalar_0 = beta*_Y_1_scalar_0;
                        _Y_1_scalar_0 = _Y_1_scalar_0+A[i_par*lda+(i_bk*lda+i*lda)]*_X_2_scalar_0;
                        /*Unroll Check*/if (1+i<min(256-i_bk,-i_bk+(M-i_par)))  
                          {
                             _Y_1_scalar_1 = beta*_Y_1_scalar_1;
                             _Y_1_scalar_1 = _Y_1_scalar_1+A[i_par*lda+(i_bk*lda+(lda+i*lda))]*_X_2_scalar_0;
                          }
                        _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                        _X_2_scalar_0 = _X_2_scalar_fd_0[0];
                        _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(1+i_par*lda))]*_X_2_scalar_0;
                        /*Unroll Check*/if (1+i<min(256-i_bk,-i_bk+(M-i_par)))  
                          _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(1+i_par*lda)))]*_X_2_scalar_0;
                        _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                        _X_2_scalar_0 = _X_2_scalar_fd_0[0];
                        _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(2+i_par*lda))]*_X_2_scalar_0;
                        /*Unroll Check*/if (1+i<min(256-i_bk,-i_bk+(M-i_par)))  
                          _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(2+i_par*lda)))]*_X_2_scalar_0;
                        _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                        _X_2_scalar_0 = _X_2_scalar_fd_0[0];
                        _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(3+i_par*lda))]*_X_2_scalar_0;
                        /*Unroll Check*/if (1+i<min(256-i_bk,-i_bk+(M-i_par)))  
                          _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(3+i_par*lda)))]*_X_2_scalar_0;
                        _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                        for (j=4; j<16; j+=4) 
                          {
                             _X_2_scalar_0 = _X_2_scalar_fd_0[0];
                             _Y_1_scalar_0 = _Y_1_scalar_0+A[j+(i_par*lda+(i_bk*lda+i*lda))]*_X_2_scalar_0;
                             /*Unroll Check*/if (1+i<min(256-i_bk,-i_bk+(M-i_par)))  
                               _Y_1_scalar_1 = _Y_1_scalar_1+A[j+(i_par*lda+(i_bk*lda+(lda+i*lda)))]*_X_2_scalar_0;
                             _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                             _X_2_scalar_0 = _X_2_scalar_fd_0[0];
                             _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(i_par*lda+(1+j)))]*_X_2_scalar_0;
                             /*Unroll Check*/if (1+i<min(256-i_bk,-i_bk+(M-i_par)))  
                               _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(i_par*lda+(1+j))))]*_X_2_scalar_0;
                             _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                             _X_2_scalar_0 = _X_2_scalar_fd_0[0];
                             _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(i_par*lda+(2+j)))]*_X_2_scalar_0;
                             /*Unroll Check*/if (1+i<min(256-i_bk,-i_bk+(M-i_par)))  
                               _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(i_par*lda+(2+j))))]*_X_2_scalar_0;
                             _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                             _X_2_scalar_0 = _X_2_scalar_fd_0[0];
                             _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(i_par*lda+(3+j)))]*_X_2_scalar_0;
                             /*Unroll Check*/if (1+i<min(256-i_bk,-i_bk+(M-i_par)))  
                               _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(i_par*lda+(3+j))))]*_X_2_scalar_0;
                             _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                          }
                        _Y_1_scalar_fd_0[i_par] = _Y_1_scalar_0;
                        _Y_1_scalar_fd_0[1+i_par] = _Y_1_scalar_1;
                        _Y_1_scalar_fd_0 = 2+_Y_1_scalar_fd_0;
                     }
                }
              for (j_bk=16; j_bk<-15+N; j_bk+=16) 
                {
                   _Y_1_scalar_fd_0 = _Y_buf_fd_0;
                   for (i=0; i<min(256-i_bk,-i_bk+(M-i_par)); i+=2) 
                     {
                        _Y_1_scalar_0 = _Y_1_scalar_fd_0[i_par];
                        _Y_1_scalar_1 = _Y_1_scalar_fd_0[1+i_par];
                        _X_2_scalar_fd_0 = X;
                        for (j=0; j<16; j+=4) 
                          {
                             _X_2_scalar_0 = _X_2_scalar_fd_0[j_bk];
                             _Y_1_scalar_0 = _Y_1_scalar_0+A[j+(j_bk+(i_par*lda+(i_bk*lda+i*lda)))]*_X_2_scalar_0;
                             /*Unroll Check*/if (1+i<min(256-i_bk,-i_bk+(M-i_par)))  
                               _Y_1_scalar_1 = _Y_1_scalar_1+A[j+(j_bk+(i_par*lda+(i_bk*lda+(lda+i*lda))))]*_X_2_scalar_0;
                             _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                             _X_2_scalar_0 = _X_2_scalar_fd_0[j_bk];
                             _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(i_par*lda+(j_bk+(1+j))))]*_X_2_scalar_0;
                             /*Unroll Check*/if (1+i<min(256-i_bk,-i_bk+(M-i_par)))  
                               _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(i_par*lda+(j_bk+(1+j)))))]*_X_2_scalar_0;
                             _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                             _X_2_scalar_0 = _X_2_scalar_fd_0[j_bk];
                             _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(i_par*lda+(j_bk+(2+j))))]*_X_2_scalar_0;
                             /*Unroll Check*/if (1+i<min(256-i_bk,-i_bk+(M-i_par)))  
                               _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(i_par*lda+(j_bk+(2+j)))))]*_X_2_scalar_0;
                             _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                             _X_2_scalar_0 = _X_2_scalar_fd_0[j_bk];
                             _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(i_par*lda+(j_bk+(3+j))))]*_X_2_scalar_0;
                             /*Unroll Check*/if (1+i<min(256-i_bk,-i_bk+(M-i_par)))  
                               _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(i_par*lda+(j_bk+(3+j)))))]*_X_2_scalar_0;
                             _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                          }
                        _Y_1_scalar_fd_0[i_par] = _Y_1_scalar_0;
                        _Y_1_scalar_fd_0[1+i_par] = _Y_1_scalar_1;
                        _Y_1_scalar_fd_0 = 2+_Y_1_scalar_fd_0;
                     }
                }
              if (j_bk<N)  
                {
                   _Y_1_scalar_fd_0 = _Y_buf_fd_0;
                   for (i=0; i<min(256-i_bk,-i_bk+(M-i_par)); i+=2) 
                     {
                        _Y_1_scalar_0 = _Y_1_scalar_fd_0[i_par];
                        _Y_1_scalar_1 = _Y_1_scalar_fd_0[i_par+1];
                        _X_2_scalar_fd_0 = X;
                        for (j=0; j<N-j_bk; j+=4) 
                          {
                             _X_2_scalar_0 = _X_2_scalar_fd_0[j_bk];
                             /*SPLIT-START*/if (j_bk+j==0)  
                               _Y_1_scalar_0 = beta*_Y_1_scalar_0;
                             _Y_1_scalar_0 = _Y_1_scalar_0+A[j+(j_bk+(i_par*lda+(i_bk*lda+i*lda)))]*_X_2_scalar_0;
                             /*Unroll Check*/if (1+i<min(256-i_bk,-i_bk+(M-i_par)))  
                               {
                                  /*SPLIT-START*/if (j_bk+j==0)  
                                    _Y_1_scalar_1 = beta*_Y_1_scalar_1;
                                  _Y_1_scalar_1 = _Y_1_scalar_1+A[j+(j_bk+(i_par*lda+(i_bk*lda+(lda+i*lda))))]*_X_2_scalar_0;
                               }
                             _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                             /*Unroll Check*/if (1+j<N-j_bk)  
                               {
                                  _X_2_scalar_0 = _X_2_scalar_fd_0[j_bk];
                                  /*SPLIT-START*/if (j_bk+(1+j)==0)  
                                    _Y_1_scalar_0 = beta*_Y_1_scalar_0;
                                  _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(i_par*lda+(j_bk+(1+j))))]*_X_2_scalar_0;
                                  /*Unroll Check*/if (1+i<min(256-i_bk,-i_bk+(M-i_par)))  
                                    {
                                       /*SPLIT-START*/if (j_bk+(1+j)==0)  
                                         _Y_1_scalar_1 = beta*_Y_1_scalar_1;
                                       _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(i_par*lda+(j_bk+(1+j)))))]*_X_2_scalar_0;
                                    }
                                  _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                               }
                             /*Unroll Check*/if (2+j<N-j_bk)  
                               {
                                  _X_2_scalar_0 = _X_2_scalar_fd_0[j_bk];
                                  /*SPLIT-START*/if (j_bk+(2+j)==0)  
                                    _Y_1_scalar_0 = beta*_Y_1_scalar_0;
                                  _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(i_par*lda+(j_bk+(2+j))))]*_X_2_scalar_0;
                                  /*Unroll Check*/if (1+i<min(256-i_bk,-i_bk+(M-i_par)))  
                                    {
                                       /*SPLIT-START*/if (j_bk+(2+j)==0)  
                                         _Y_1_scalar_1 = beta*_Y_1_scalar_1;
                                       _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(i_par*lda+(j_bk+(2+j)))))]*_X_2_scalar_0;
                                    }
                                  _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                               }
                             /*Unroll Check*/if (3+j<N-j_bk)  
                               {
                                  _X_2_scalar_0 = _X_2_scalar_fd_0[j_bk];
                                  /*SPLIT-START*/if (j_bk+(3+j)==0)  
                                    _Y_1_scalar_0 = beta*_Y_1_scalar_0;
                                  _Y_1_scalar_0 = _Y_1_scalar_0+A[i*lda+(i_bk*lda+(i_par*lda+(j_bk+(3+j))))]*_X_2_scalar_0;
                                  /*Unroll Check*/if (1+i<min(256-i_bk,-i_bk+(M-i_par)))  
                                    {
                                       /*SPLIT-START*/if (j_bk+(3+j)==0)  
                                         _Y_1_scalar_1 = beta*_Y_1_scalar_1;
                                       _Y_1_scalar_1 = _Y_1_scalar_1+A[i*lda+(lda+(i_bk*lda+(i_par*lda+(j_bk+(3+j)))))]*_X_2_scalar_0;
                                    }
                                  _X_2_scalar_fd_0 = 1+_X_2_scalar_fd_0;
                               }
                          }
                        _Y_1_scalar_fd_0[i_par] = _Y_1_scalar_0;
                        _Y_1_scalar_fd_0[i_par+1] = _Y_1_scalar_1;
                        _Y_1_scalar_fd_0 = _Y_1_scalar_fd_0+2;
                     }
                }
              _Y_buf_fd_0 = _Y_buf_fd_0+16;
           }
      }
    }
   
}
