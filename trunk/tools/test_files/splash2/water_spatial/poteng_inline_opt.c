/*@;BEGIN(Func1=FunctionDecl)@*/void CSHIFT(double* XA,double* XB,double XMA,double XMB,double* XL,double BOXH,double BOXL) {
   
   long I;
   XL[0] = XMA-XMB;
   XL[1] = XMA-XB[0];
   XL[2] = XMA-XB[2];
   XL[3] = XA[0]-XMB;
   XL[4] = XA[2]-XMB;
   XL[5] = XA[0]-XB[0];
   XL[6] = XA[0]-XB[2];
   XL[7] = XA[2]-XB[0];
   XL[8] = XA[2]-XB[2];
   XL[9] = XA[1]-XB[1];
   XL[10] = XA[1]-XB[0];
   XL[11] = XA[1]-XB[2];
   XL[12] = XA[0]-XB[1];
   XL[13] = XA[2]-XB[1];
   for (I=0; I<14; I+=1)
     {
        if (fabs(XL[I])>BOXH) 
          {
             XL[I] = XL[I]-(XL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
          }
     }
}
/*@;BEGIN(Func2=FunctionDecl)@*/void POTENG(double* POTA,double* POTR,double* PTRF,long ProcID) {
   LPOTR = 0.0;
   LPTRF = 0.0;
   curr_box = my_boxes[ProcID];
   while (curr_box)
     {
        i = curr_box->coord[XDIR];
        j = curr_box->coord[YDIR];
        k = curr_box->coord[ZDIR];
        for (XBOX=i-1; XBOX<2+i; XBOX+=1)
          {
             for (YBOX=j-1; YBOX<2+j; YBOX+=1)
               {
                  for (ZBOX=k-1; ZBOX<2+k; ZBOX+=1)
                    {
                       X_NUM = XBOX;
                       Y_NUM = YBOX;
                       Z_NUM = ZBOX;
                       if (BOX_PER_SIDE==2&&(((((XBOX<0||XBOX==2)||YBOX<0)||YBOX==2)||ZBOX<0)||ZBOX==2)) 
                         {
                            continue;
                         }
                       if (X_NUM==-1) 
                         {
                            X_NUM = X_NUM+BOX_PER_SIDE;
                         }
                       else if (X_NUM>=BOX_PER_SIDE) 
                         {
                            X_NUM = X_NUM-BOX_PER_SIDE;
                         }
                       if (Y_NUM==-1) 
                         {
                            Y_NUM = Y_NUM+BOX_PER_SIDE;
                         }
                       else if (Y_NUM>=BOX_PER_SIDE) 
                         {
                            Y_NUM = Y_NUM-BOX_PER_SIDE;
                         }
                       if (Z_NUM==-1) 
                         {
                            Z_NUM = Z_NUM+BOX_PER_SIDE;
                         }
                       else if (Z_NUM>=BOX_PER_SIDE) 
                         {
                            Z_NUM = Z_NUM-BOX_PER_SIDE;
                         }
                       if (((X_NUM==i&&Y_NUM==j)&&Z_NUM==k)&&((XBOX!=i||YBOX!=j)||ZBOX!=k)) 
                         {
                            continue;
                         }
                       neighbor_ptr = BOX[X_NUM][Y_NUM][Z_NUM].list;
                       while (neighbor_ptr)
                         {
                            curr_ptr = BOX[i][j][k].list;
                            while (curr_ptr)
                              {
                                 if (curr_ptr==neighbor_ptr) 
                                   {
                                      curr_ptr = curr_ptr->next_mol;
                                      continue;
                                   }
                                 {
                                    long I;
                                    XL[0] = curr_ptr->mol.VM[XDIR]-neighbor_ptr->mol.VM[XDIR];
                                    XL[1] = curr_ptr->mol.VM[XDIR]-neighbor_ptr->mol.F[DISP][XDIR][0];
                                    XL[2] = curr_ptr->mol.VM[XDIR]-neighbor_ptr->mol.F[DISP][XDIR][2];
                                    XL[3] = curr_ptr->mol.F[DISP][XDIR][0]-neighbor_ptr->mol.VM[XDIR];
                                    XL[4] = curr_ptr->mol.F[DISP][XDIR][2]-neighbor_ptr->mol.VM[XDIR];
                                    XL[5] = curr_ptr->mol.F[DISP][XDIR][0]-neighbor_ptr->mol.F[DISP][XDIR][0];
                                    XL[6] = curr_ptr->mol.F[DISP][XDIR][0]-neighbor_ptr->mol.F[DISP][XDIR][2];
                                    XL[7] = curr_ptr->mol.F[DISP][XDIR][2]-neighbor_ptr->mol.F[DISP][XDIR][0];
                                    XL[8] = curr_ptr->mol.F[DISP][XDIR][2]-neighbor_ptr->mol.F[DISP][XDIR][2];
                                    XL[9] = curr_ptr->mol.F[DISP][XDIR][1]-neighbor_ptr->mol.F[DISP][XDIR][1];
                                    XL[10] = curr_ptr->mol.F[DISP][XDIR][1]-neighbor_ptr->mol.F[DISP][XDIR][0];
                                    XL[11] = curr_ptr->mol.F[DISP][XDIR][1]-neighbor_ptr->mol.F[DISP][XDIR][2];
                                    XL[12] = curr_ptr->mol.F[DISP][XDIR][0]-neighbor_ptr->mol.F[DISP][XDIR][1];
                                    XL[13] = curr_ptr->mol.F[DISP][XDIR][2]-neighbor_ptr->mol.F[DISP][XDIR][1];
                                    for (I=0; I<14; I+=1)
                                      {
                                         if (fabs(XL[I])>BOXH) 
                                           {
                                              XL[I] = XL[I]-(XL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                           }
                                      }
                                 }
                                 {
                                    long I;
                                    YL[0] = curr_ptr->mol.VM[YDIR]-neighbor_ptr->mol.VM[YDIR];
                                    YL[1] = curr_ptr->mol.VM[YDIR]-neighbor_ptr->mol.F[DISP][YDIR][0];
                                    YL[2] = curr_ptr->mol.VM[YDIR]-neighbor_ptr->mol.F[DISP][YDIR][2];
                                    YL[3] = curr_ptr->mol.F[DISP][YDIR][0]-neighbor_ptr->mol.VM[YDIR];
                                    YL[4] = curr_ptr->mol.F[DISP][YDIR][2]-neighbor_ptr->mol.VM[YDIR];
                                    YL[5] = curr_ptr->mol.F[DISP][YDIR][0]-neighbor_ptr->mol.F[DISP][YDIR][0];
                                    YL[6] = curr_ptr->mol.F[DISP][YDIR][0]-neighbor_ptr->mol.F[DISP][YDIR][2];
                                    YL[7] = curr_ptr->mol.F[DISP][YDIR][2]-neighbor_ptr->mol.F[DISP][YDIR][0];
                                    YL[8] = curr_ptr->mol.F[DISP][YDIR][2]-neighbor_ptr->mol.F[DISP][YDIR][2];
                                    YL[9] = curr_ptr->mol.F[DISP][YDIR][1]-neighbor_ptr->mol.F[DISP][YDIR][1];
                                    YL[10] = curr_ptr->mol.F[DISP][YDIR][1]-neighbor_ptr->mol.F[DISP][YDIR][0];
                                    YL[11] = curr_ptr->mol.F[DISP][YDIR][1]-neighbor_ptr->mol.F[DISP][YDIR][2];
                                    YL[12] = curr_ptr->mol.F[DISP][YDIR][0]-neighbor_ptr->mol.F[DISP][YDIR][1];
                                    YL[13] = curr_ptr->mol.F[DISP][YDIR][2]-neighbor_ptr->mol.F[DISP][YDIR][1];
                                    for (I=0; I<14; I+=1)
                                      {
                                         if (fabs(YL[I])>BOXH) 
                                           {
                                              YL[I] = YL[I]-(YL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                           }
                                      }
                                 }
                                 {
                                    long I;
                                    ZL[0] = curr_ptr->mol.VM[ZDIR]-neighbor_ptr->mol.VM[ZDIR];
                                    ZL[1] = curr_ptr->mol.VM[ZDIR]-neighbor_ptr->mol.F[DISP][ZDIR][0];
                                    ZL[2] = curr_ptr->mol.VM[ZDIR]-neighbor_ptr->mol.F[DISP][ZDIR][2];
                                    ZL[3] = curr_ptr->mol.F[DISP][ZDIR][0]-neighbor_ptr->mol.VM[ZDIR];
                                    ZL[4] = curr_ptr->mol.F[DISP][ZDIR][2]-neighbor_ptr->mol.VM[ZDIR];
                                    ZL[5] = curr_ptr->mol.F[DISP][ZDIR][0]-neighbor_ptr->mol.F[DISP][ZDIR][0];
                                    ZL[6] = curr_ptr->mol.F[DISP][ZDIR][0]-neighbor_ptr->mol.F[DISP][ZDIR][2];
                                    ZL[7] = curr_ptr->mol.F[DISP][ZDIR][2]-neighbor_ptr->mol.F[DISP][ZDIR][0];
                                    ZL[8] = curr_ptr->mol.F[DISP][ZDIR][2]-neighbor_ptr->mol.F[DISP][ZDIR][2];
                                    ZL[9] = curr_ptr->mol.F[DISP][ZDIR][1]-neighbor_ptr->mol.F[DISP][ZDIR][1];
                                    ZL[10] = curr_ptr->mol.F[DISP][ZDIR][1]-neighbor_ptr->mol.F[DISP][ZDIR][0];
                                    ZL[11] = curr_ptr->mol.F[DISP][ZDIR][1]-neighbor_ptr->mol.F[DISP][ZDIR][2];
                                    ZL[12] = curr_ptr->mol.F[DISP][ZDIR][0]-neighbor_ptr->mol.F[DISP][ZDIR][1];
                                    ZL[13] = curr_ptr->mol.F[DISP][ZDIR][2]-neighbor_ptr->mol.F[DISP][ZDIR][1];
                                    for (I=0; I<14; I+=1)
                                      {
                                         if (fabs(ZL[I])>BOXH) 
                                           {
                                              ZL[I] = ZL[I]-(ZL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                           }
                                      }
                                 }
                                 KC = 0;
                                 for (K=0; K<9; K+=1)
                                   {
                                      RS[K] = XL[K]*XL[K]+YL[K]*YL[K]+ZL[K]*ZL[K];
                                      if (RS[K]>CUT2) 
                                        {
                                           KC++;
                                        }
                                   }
                                 if (KC!=9) 
                                   {
                                      for (K=0; K<9; K+=1)
                                        {
                                           if (RS[K]<=CUT2) 
                                             {
                                                RL[K] = sqrt(RS[K]);
                                             }
                                           else 
                                             {
                                                RL[K] = CUTOFF;
                                                RS[K] = CUT2;
                                             }
                                        }
                                      LPOTR = LPOTR-QQ2/RL[1]-QQ2/RL[2]-QQ2/RL[3]-QQ2/RL[4]+QQ/RL[5]+QQ/RL[6]+QQ/RL[7]+QQ/RL[8]+QQ4/RL[0];
                                      LPTRF = LPTRF-REF2*RS[0]-REF1*((RS[5]+RS[6]+RS[7]+RS[8])*0.5-RS[1]-RS[2]-RS[3]-RS[4]);
                                      if (KC<=0) 
                                        {
                                           for (K=9; K<14; K+=1)
                                             {
                                                RL[K] = sqrt(XL[K]*XL[K]+YL[K]*YL[K]+ZL[K]*ZL[K]);
                                             }
                                           LPOTR = LPOTR+A1*exp(-B1*RL[9])+A2*(exp(-B2*RL[5])+exp(-B2*RL[6])+exp(-B2*RL[7])+exp(-B2*RL[8]))+A3*(exp(-B3*RL[10])+exp(-B3*RL[11])+exp(-B3*RL[12])+exp(-B3*RL[13]))-A4*(exp(-B4*RL[10])+exp(-B4*RL[11])+exp(-B4*RL[12])+exp(-B4*RL[13]));
                                        }
                                   }
                                 curr_ptr = curr_ptr->next_mol;
                              }
                            neighbor_ptr = neighbor_ptr->next_mol;
                         }
                    }
               }
          }
        curr_box = curr_box->next_box;
     }
}
