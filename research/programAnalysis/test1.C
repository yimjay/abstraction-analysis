class FOO{
   //typedef enum {Start, End} State;
  typedef int State;

  State  var; 
  
  FOO() { var = 0; } 
 
  //int var;
  void state1() {
     if (var == 0)
        var = 1;
   }
   void state2() {
     if (var == 1)
        var = 2;
   }
   void state3() {
     while  (var <= 3)
   {
         var = var + 1;
       
    }
   }
   void state4(){
    switch (var)
  {
    case 1: var = 2;
	    break;
    case 2: var = 3;
            break;
    case 3: var = 4;
            break;
   }
  }
};
