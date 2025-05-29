#include "include.h"
//----------------------------------
void Send_data(unsigned char data)
{
  _emi=0;	
	while(_tidle0==0)
	{
		_clrwdt();
	}
	_txr_rxr0=data;
//  _emi=1;
}


//unsigned char print_long(long  dat)
//{
//  unsigned long temp;	
//  unsigned char t[10],ret;
//
//    ret=0;
//
//	if(dat<0)
//	{
//		 Send_data('-');
//		 temp=-dat;
//	}	
//	else
//	{
//		temp=dat;
//	}
// 
//	if(temp==0)
//	{
//		Send_data('0');
//		ret++;
//	}
//	else
//    {
//  
//	    k=9;
//		for(m=0;m<10;m++)
//		{	
//			t[k--] = temp%10;		
//			temp /= 10;		
//		}
//		k=0;
//		for(m=0;m<10;m++)
//		{	
//			if(k)
//			{
//				Send_data(t[m]+0x30);
//				ret++;	
//			}
//			else
//			{
//				if(t[m] != 0)
//				{
//					Send_data(t[m]+0x30);
//					ret++;	
//					k=1;
//				}		  	
//			  	
//			 }
//	
//		}
//  }
//  
//  return ret;
//	
//}
//

unsigned char print_long(long  dat)
{
  unsigned long temp;	
  unsigned char t[10],ret;

    ret=0;


 
	if(dat==0)
	{
		Send_data('0');
		ret++;
	}
	else
    {
	 	if(dat<0)
		{
			 Send_data('-');
			 temp=-dat;
		}	
		else
		{
			temp=dat;
		} 
		
		memset((unsigned char *)t,0,sizeof(t));		
	    k=9;
		while(temp)
		{	
			t[k--] = temp%10+0x30;		
			temp /= 10;		
		}

		for(m=0;m<10;m++)
		{	

			if(t[m] != 0)
			{
				Send_data(t[m]);
				ret++;	
		
			}		  	

		}
  }
  
  return ret;
	
}


void print_double(double     dat)
{

 volatile double temp;	


  unsigned char i,k;	
  unsigned char t[10];
 volatile unsigned  long inter;
  
//  _emi=0;
  	memset((unsigned char *)t,0,sizeof(t));
  	
	temp=dat;
	if(dat<0)
	{
		 Send_data('-');
		 temp=-dat;
	}	

   
  inter=(unsigned long)temp;
  
  k=print_long(inter);
  if(k<8)//8Î»ÓÐÐ§Êý×Ö
  {

	  Send_data('.');
	  
	  temp-=inter;
	  
      k=8-k;	
	  for(i=0;i<k;i++)
	  {
		   temp*=10;
		   t[i]=temp;
		   temp-=t[i];
		
	  }
	  for(i=0;i<k;i++)
	  {
	  	Send_data(t[i]+0x30);	
	  }  
  }
 _emi=1;
}




void print_str(char *p)
{
 // _emi=0;
	while(*p!=0)
	{
		Send_data(*p++);

	}
//	_emi=1;
}

void print_DataLen(char *data,int len)
{
	int i;	
	for(i=0;i<len;i++)
	{
		Send_data(data[i]);
	}
}


