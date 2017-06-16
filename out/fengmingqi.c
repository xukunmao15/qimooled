#define BEEP P3_7    //?????
bit beep_st;     //???????
signed char shangxian=40;  //??????,????38
signed char xiaxian=10;   //??????,????5
void Alarm()
{
 if(x>=10){beep_st=~beep_st;x=0;}
 if((m>=shangxian&&beep_st==1)||(m<xiaxian&&beep_st==1))BEEP=0;
 else BEEP=1;
}
/*****???*****/
void main(void)
{
    uint z;
 InitTimer();    //??????
 EA=1;      //??????
 TR0=1;
 ET0=1;      //?????0
 IT0=1;        
 IT1=1;
 check_wendu();
 check_wendu();
 for(z=0;z<300;z++)
 {
  Disp_init();        
  }
 while(1)
  {
  if(SET==0)
  {
   Delay(2000);
   do{}while(SET==0);
   set_st++;x=0;shanshuo_st=1;
   if(set_st>2)set_st=0;
  }
  if(set_st==0)
  {
   EX0=0;    //??????0
   EX1=0;    //??????1
    check_wendu();
      Disp_Temperature();
   Alarm();   //????
  }
  else if(set_st==1)
  {
   BEEP=1;    //?????
   EX0=1;    //??????0
   EX1=1;    //??????1
   if(x>=10){shanshuo_st=~shanshuo_st;x=0;}
   if(shanshuo_st) {Disp_alarm(shangxian);}
  }
  else if(set_st==2)
  {
   BEEP=1;    //?????
   EX0=1;    //??????0
   EX1=1;    //??????1
   if(x>=10){shanshuo_st=~shanshuo_st;x=0;}
   if(shanshuo_st) {Disp_alarm(xiaxian);}
  }
    }
}
