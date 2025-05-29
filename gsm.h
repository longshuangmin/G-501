
//const unsigned	char  OPEN_URL[]="http://tf.ydjk5.com/gprs/receive/api/data?data="; //云渡健康
# define gsm_pown_off   98
unsigned char HEX_TO_Char(unsigned char Hex);
typedef unsigned char   uchar;
void start_gsm(void);
unsigned char gsm_send_data(void);
void goto_next_case(void);
void wait_loop_time(signed int time);
uchar getServerCallback(uchar *str,uchar len);
void getServerTime(char *str);
uchar getRssi(uchar *str,uchar len);
signed char starting_gsm(void);
signed char send_gsm_data(void);
void setRssi(void);



