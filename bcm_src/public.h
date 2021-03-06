#ifndef  _PUBLIC_H_
#define  _PUBLIC_H_
#include <stdarg.h>
#include <posapi.h>


//#define LAN_HUB	//主要是LAN_HUB的测试程序
//#define PORT_TEST //主要是接口板的测试
//#define DEBUG		//调试打印
//#define LIB_SO		//主要是有一些函数是静态编译上没有定义的

//#define ALL_WNET_VER_MATCH //国内WNET版本完整比对
#define BCM      //国内
//#define Venezuela //委内瑞拉
//#define BAXI      //巴西


#ifdef  BCM
#define APPNAME    "BCM_FTEST"
#define STRING_VERSION	 " SXX_POS_FTEST_V3.13  " 
#define SOFT_VERSION	"_BCM_V3.13"
#define SPEECH_ON
#define WIFI_ON
#define BT_ON
#endif


#ifdef  BAXI
#define APPNAME    "BAXI_FTEST"
#define STRING_VERSION	 "BAXI_POS_FTEST_V3.11  " 
#define SOFT_VERSION	"_BAXI_V3.11"
#define SPEECH_ON
#define WIFI_ON
#define BT_ON
#endif


#ifdef  Venezuela
#define APPNAME    "VEN_FTEST"
#define STRING_VERSION	 "  VEN_POS_FTEST_V3.08 " 
#define SOFT_VERSION	"_VEN_V3.08"
#define SPEECH_ON
#define WIFI_ON
#define BT_ON
#endif

#ifdef ALL_WNET_VER_MATCH
#define BCM
#define APPNAME    "MATCH_FTEST"
#define STRING_VERSION	 " SXX_POS_FTEST_V3.13A " 
#define SOFT_VERSION	"_MATCH_V3.13A"
#define SPEECH_ON
#define WIFI_ON
#define BT_ON
#endif


//定义通过终端信息函数所选的机型：
#define  S80   7   
#define  SP30  8
#define  S60   9
#define  S90   10
#define  S78   11
#define  S58   14 
#define  T60   0x86 
#define  T52   13
#define  MT30  12
#define  D200  15
#define  D210  16
#define  T610  18
#define  T620  19
#define  S810  200//20
#define  S300  20
#define  S800  21
#define  S900  22
#define  S500  24
#define  S200  0x89

#define  S910	26
#define  CHINESE 1


// T52_POS按键
    #define KEYNO 31
	#define KEYSET		0x81		//设置
	#define KEYLEFT	    0x83		//左键
	#define KEYPBOOK	0x85		//电话本
	#define KEYPAY		0x86		//支付
	#define KEYPHONE	0x87		//IP/输入法
	#define KEYBACK		0x88		//回拨
	#define KEYRIGHT	0x89		//右键
	#define KEYMSG		0x8a		//账单
	#define KEYDIALED   0x8e		//去电

//T610_T620 增加的按键
#define     KEYF1               0x01                    
#define     KEYF2               0x02                    
#define     KEYF3               0x03                    
#define     FNKEYF2             0xa5             
#define     FNKEYF3             0Xa6               

#define     KEYADD              0x2B
#define     KEYSUB              0x2D
#define     KEYMUL              0x26
#define     KEYDOT              0x2E

//T620增加的组合键
#define     FNKEYADD              0xBB
#define     FNKEYSUB              0xBD
#define     FNKEYMUL              0xB6
#define     FNKEYDOT              0xBE




//在posapi.h里面有定义
#ifdef WIN32
#define TelDial(a) 0
#define TelOffHook() 
#define TelCheck(a)
#define GetHardwareConfig(_A_,_B_,_C_) 1   //通过关键字查询硬件配置信息
#define WlSelSim(_A_) 0
#define GetTermInfoExt(_A_,_B_) 0     
#define EnumBaseFont(_A_,_B_) 0
#define s_GetPrnPinTime()     1
#define s_OpenPrnPinTime()    1
#define s_PrnStart(_A_)        1
#define s_ClosePrnPinTime()  1
#define EthMacGet(_A_) 1
#define s_ModemInfo(_A,_B,_C,_D) NULL

#else
extern void s_ModemInfo(uchar *drv_ver,uchar *mdm_name,uchar *last_make_date,uchar *others);
#endif

#ifdef WIN32
int TouchScreenCalibration(void);
void ScrRect(int X1,int Y1,int X2,int Y2,COLORREF BorderColor,COLORREF FillColor);
#endif


#define PICC_LED_ALL 0xff
#define WIFIPORT 5
#define PINPAD 3
#define RS232  0
#define LANPORT	2
#define COM1 0


char Cmu200Result,gBaseChange;
#define F_BASE_CHANGE	"baseChange.dat"
#define F_TSCB			"tscb.dat"
#define F_CMU200		"cmu200.dat"
#define F_TELNUM		"TelNum.dat"
#define F_LANPARA		"LANPara.dat"
#define F_BASIC_INFO	"basicinfo.ini"
#define LOOP_TIME_RECORD  "LoopTimeRecord.dat"//煲机时间记录，总大小是5个LOOP_STRUCT的大小记录5次的煲机时间
#define LOOP_FIRST_ERR_RECORD "CycErrRecord.dat"//煲机第一次出错的相对时间和出错的返回码。

#define WNET_TEST_RECORD  "WNETTEST.DAT"  //无线测试记录
#define BT_LOG "bt.dat"

typedef struct
{
	uchar StartTime[7];//煲机开始时间
	uchar StopTime[7]; //煲机结束时间
	ulong LoopSeconds; //煲机总时间，单位s
	ulong LoopCnt;	   //煲机次数
}LOOP_STRUCT;

uint LoopStartMs;
uint LoopTempMs;
uint LoopStopMs;
uint LoopMin;


//下面是煲机各模块失败次数记录
int RecordLog(const char *FileName,const char * fmt,...);
void CalcLoopTime(ulong *Time,ulong *Cnt);

//#define LOOP_FAIL_RECORD  "LoopFailRecord.dat"//煲机异常记录,详细记录各种煲机的情况,大小没有限制,有问题都在文件后面追加


/*
void LoopFailCnt(void);
void ShowLoopErr(int LoopAllTime,int LoopAllCnt);
int CycFailCnt[20];
#define LOOP_FAIL_CNT	"LoopFailCnt.dat"//煲机失败次数记录，总大小是20个int型数据
#define CYC_LED     0
#define CYC_LCD		1
#define CYC_KB		2
#define CYC_IC		3
#define CYC_MODEM	4
#define CYC_WNET	5
#define CYC_PRT		6
#define CYC_SPEECH	7
#define CYC_MAG		8
#define CYC_RF		9
#define CYC_FELICA	10
#define CYC_GSEN	11
#define CYC_UHOST	12
#define CYC_SD		13
#define CYC_LAN		14
#define CYC_WIFI	15
#define CYC_BT		16
*/


//获取版本信息的算法函数

void xml_strlwr(char *turned);
int  xml_find(uchar *doc, int doc_len, char *find_flag, int find_flag_len, int *find_location);
int  XmlGetElement(uchar *xml_doc, int xmldoc_len, char *ele_name, uchar *ele_value, int va_max_len, int *value_real_len);
int  XmlAddElement(uchar *xml_doc, int xml_doc_max_len, char *ele_name, uchar *ele_value, int value_len, int *xml_real_len);
int  XmlDelElement(uchar *xml_doc, char *ele_name, int *xml_len);

// Public.c的公共函数
int SetCombKey(void);
void DelFacApp(void);
void AppManager(void);
void GetConfig(void);
void SetSrand(void);
void SetComPort(int port);
void BeepOK(void);
void BeepFail(void);
void BeepPrompt(void);
void ShowVer(void);
void ShowFileCtrlErr(uint Line);
uchar *DispTimer(unsigned char line);
int   WaitEsc(unsigned char flag,unsigned short seconds);
int   SendCommand(char *command);
int   RecvReturn(ushort inTimeOut);
void  ShowErr(char *msg);
int   Select(void);
ulong PubCalInterval(uchar *psTimeBegin, uchar *psTimeEnd, uchar *psCalMode, uchar *pucSignal);
unsigned char InputDec(unsigned char inlen,char *dispEnglish,char *dispChinese,unsigned short *dec,unsigned char flag);
uchar InputAsc(uchar *StrCh,uchar *StrEn,uchar *asc, uchar ascLen, uchar ascMaxLen, uchar flag);
uchar GetInputStr(uchar line,uchar mode,uchar maxlen,char *Str);
void ModifyRecord(void);
void DeleteLog(char *fileName);
void ShowSuccessRate(uint TotalNum,uint FailNum);
void Wl_handle_ver(uchar *s,int len);
void AscToBcd(uchar *Bcd, uchar *Asc, ushort Asc_len);
void ScrDispStr(uchar col,uchar row,uchar mode,uchar * szStrCH, uchar * szStrEn,...);
uchar JudgeState(uchar *StrCh,uchar *StrEn);
uchar IsQuitOrDone(uchar *StrCh,uchar *StrEn);
int  ComSendBuf(void *buf,ushort size);
int  ComSends(char * Str,...);
void see_debug(char * Str,...);
int  ComRecvBuf(void);
int  UploadFile(void);
int  UploadLog(void);
int  GetStep(void);
int  CancelCheck(void);
int  GetWirelessVer(void);
int WlSendCmdEx(char *Cmd,char *rsp,int len);
int get_1_num(int input);
int get_0_num(int input);
int  GetInfoExt(void);

int _cat_record_function_for_none_GNUC_(int result,const char * fmt,...);
#define RECORD _cat_record_function_for_none_GNUC_ 




//
void TestAll(void);
void TestCyc(void);
void TestSingle(void);

// flag=0 整机测试      flag=1 单次测试        flag=2 循环测试
// 返回0  测试成功		返回1  测试失败
uchar PrinterTest(uchar flag);
uchar ModemTest(uchar flag);
uchar UsbHostTest(uchar flag);
uchar UsbDevTest(uchar flag);
uchar LanTest(uchar flag);

uchar WnetTest(uchar flag);
uchar Cmu200Test(uchar flag);

uchar RfTest(uchar flag);
uchar WifiTest(uchar flag);  
uchar IcTest(uchar flag);
uchar MagTest(uchar flag);
uchar GSensorTest(uchar flag);
uchar TScreenTest(uchar flag);
uchar BtTest(uchar flag);
uchar BeepTest(uchar flag);
uchar KbTest(uchar flag);
uchar LcdTest(uchar flag);
uchar ComATest(uchar flag);
uchar ComBTest(uchar flag);
uchar UDiskTest(uchar flag);
uchar ClkTest(uchar flag);
uchar SpeechTest(uchar flag);
uchar BatteryTest(uchar flag);
uchar PinpadTest(uchar flag);
uchar FelicaTest(uchar flag);
uchar LedTest(uchar flag);
uchar ByPhoneTest(uchar flag);
uchar PaperBackTest(uchar flag);
uchar ScanTest(uchar flag);
uchar LedplyTest(uchar flag);
uchar TelTest(uchar flag);
uchar SDCardTest(uchar flag);
uchar VerTest(uchar flag);
uchar TsTest(uchar flag);
uchar KbLedTest(uchar flag);
uchar TestSim0 (uchar flag);
uchar TestSim1 (uchar flag);
uchar  UDiskATest(uchar flag);//S800双USB口增加
uchar SM2Test(uchar flag);
uchar BaseTest(uchar flag);
uchar Lan2Test(uchar flag);


//单项测试总菜单
void PrinterTestAll(void);
void ModemTestAll(void);
void UsbHostTestAll(void);
void UsbDevTestAll(void);
void LanTestAll(void);
void WnetTestAll(void);
void RfTestAll(void);
void WifiTestAll(void);  
void IcTestAll(void);
void MagTestAll(void);
void GSensorTestAll(void);
void TScreenTestAll(void);
void BtTestAll(void);
void BeepTestAll(void);
void KbTestAll(void);
void LcdTestAll(void);
void ComBTestAll(void);
void UDiskTestAll(void);
void ClkTestAll(void);
void SpeechTestAll(void);
void BatteryTestAll(void);
void PinpadTestAll(void);
void FelicaTestAll(void);
void LedTestAll(void);
void ByPhoneTestAll(void);
void PaperBackTestAll(void);
void ScanTestAll(void);
void LedplyTestAll(void);
void TelTestAll(void);
void PortTestAll(void);
void FlashTestAll(void);
void IrdaTestAll(void);
void ComTestAll(void);
void BandTestAll(void);
void SDCardTestAll(void);
void TsTestAll(void);
void LogTestAll(void);

//煲机总菜单
uchar PrinterTestCyc(ulong);
uchar ModemTestCyc(ulong);
uchar UsbHostTestCyc(ulong);
uchar UsbDevTestCyc(ulong);
uchar LanTestCyc(ulong);
uchar WnetTestCyc(ulong);
uchar RfTestCyc(ulong);
uchar WifiTestCyc(ulong);  
uchar IcTestCyc(ulong);
uchar MagTestCyc(ulong);
uchar GSensorTestCyc(ulong);
uchar TScreenTestCyc(ulong);
uchar BtTestCyc(ulong);
uchar BeepTestCyc(ulong);
uchar KbTestCyc(ulong);
uchar LcdTestCyc(ulong);
uchar ComBTestCyc(ulong);
uchar UDiskTestCyc(ulong);
uchar ClkTestCyc(ulong);
uchar SpeechTestCyc(ulong);
uchar BatteryTestCyc(ulong);
uchar PinpadTestCyc(ulong);
uchar FelicaTestCyc(ulong);
uchar LedTestCyc(ulong);
uchar ByPhoneTestCyc(ulong);
uchar PaperBackTestCyc(ulong);
uchar ScanTestCyc(ulong);
uchar LedplyTestCyc(ulong);
uchar TelTestCyc(ulong);
uchar SDCardTestCyc(ulong);
uchar TsTestCyc(ulong);



//整机测试
typedef uchar(*ALL_FUN_P)(uchar flag);
typedef struct
{
	uchar flag;   // 'Y' 需要测试    'N' 不需要测试
	uchar result; //  0  测试未通过   1  测试通过
	uchar itemStr[10]; //测试项目名
	ALL_FUN_P  TestFun; //测试函数指针
} TEST_ITEM;

//单项菜单
typedef void(*SINGLE_FUN_P)(void);
typedef struct 
{
	char ChStr[20];
	char EnStr[20];
	SINGLE_FUN_P TestSingleFun;
}TESTSINGLE_ITEM;


//煲机测试
typedef uchar(*CYC_FUN_P)(ulong Loops);
typedef struct
{
	uchar flag;   // 'Y' 需要测试    'N' 不需要测试
	CYC_FUN_P  TestCycFun; //测试函数指针
} TESTCYC_ITEM;


//各种配置获取
uchar gBtAppleFlag;//是否有苹果蓝牙认证，1：是    0：否
unsigned char gIsColorLcd;  // 1是彩屏  0不是彩屏
unsigned char gBatChange;   //是否检测充电模块，1：是      0：否
unsigned char gTemperature; //是否测试温度   1：检测温度    0：不检测温度
unsigned char gTsTest;		//触摸屏 1：需要测试  0：不需要测试  S200在S1/S2要取消
unsigned char gComPort;  //通讯串口
unsigned char gIcNum;     //IC卡个数
unsigned char gSamNum;    //SAM卡个数 
unsigned char gSimNum;    //SIM卡个数
unsigned char gMac[6];    //Mac地址

unsigned char TestModule[100];   //需要测试的模块
unsigned char VerInfo[10];      //要求8字节
unsigned char TermInfo[32];     //要求30字节

unsigned char TelNum[20];       //modem拨号号码
unsigned char LANPara[10][20];
unsigned char FontType;
unsigned char RcvBuff[200];//

uchar gSn[33],gExSn[33];
uchar gModemSVer[30],gModemHVer[30],gLMDate[30],gOtVer[30];
uchar gWnetVer[50];
uchar gWireVer[50];
uchar gImei[30];
uchar GetWnetVerFlag;
uchar GetExtInfoFlag;
uchar gPPQcom;

char gConfigFileName[20];//只需17个字节
char gFontFileName[30]; 
uint gFontLength;
uint gFlashSize;
uint gNandFlashSize;
uint gSdramSize;
uint gDdrSize;
uint gRfHeight;


uchar gPrinterType[25];
uchar BaseFontSize[10];
uchar BaseMain[5];
uchar BaseBios[5];
uchar BaseDriver[5];
uchar BaseFlashSize[10];
uchar BaseSdramSize[10];
uchar gBTVer[20]; //BT版本信息
uchar gBtMac[6];  //BT MAC地址
uchar gWifiMac[6]; // WIFI MAC地址
uchar gErrnoMsg[100];//测试的错误码


//T_ 表示跟Terminfo对应，也跟测试项目TestModule[]对应
#define T_TYPE     0
#define T_PRINTER  1
#define T_MODEM    2
//3 MODEM模块配置信息
//4 MODEM最高异步速率信息
//5 PCI配置信息
#define T_USBHOST  6
#define T_USBDEV   7
#define T_LAN      8
#define T_GPRS     9
#define T_CDMA     10
#define T_WIFI     11
#define T_RF       12
#define T_FONT     13

//14 字库版本号
#define T_IC	   15
#define T_MAG      16
#define T_GSENSOR  17
#define T_WCDMA    18
#define T_TSCREEN  19
#define T_BT       20
//下面 跟测试项目对应

#define T_BEEP		21
#define T_KB		22
#define T_LCD		23
#define T_COMB		24
#define T_WNET		25
#define T_UDISK	    26
#define T_SPEECH		27
#define T_CLK			28
#define T_BATTERY		29
#define T_PINPORT		30
#define T_FELICA		31
#define T_LED			32
#define T_BYPHONE		33
#define T_PAPERBACK	34
#define T_SCAN		35
#define T_LEDPLY		36
#define T_TEL			37
#define T_SDCARD        38
#define T_KEYLED		39
#define T_SIM1			40
#define T_UDEV_TEST		41
#define T_COMB_TEST		42	
#define T_UDISKA		43
#define T_FELICA_ALL	44
#define T_SM2			45
#define T_COMA_TEST		46
#define T_BASE			47
#define T_VER			48
#define T_LAN2			49



//版本信息审核    //系统返回码
//#define VER				0
#define PC_READY			1
#define PC_SAVEOK			2
#define PC_VER_CHECK_OK		3
#define PC_NOANSWER			4
#define POS_NO_RECORD		5
#define OPEN_PORT_ERR		6
#define PC_TIMEOUT			7
#define OPEN_RECORD_ERR		8



char InfoOut[50][25];
/*可以声明,不能定义,不然就是重定义
char *KeyWord[]=
{
	"PRINTER",		"TOUCH_SCREEN",		"MAG_CARD",			"IC_CARD",
	"RF_1356M",		"RF_24G",			"G_SENSOR",			"ETHERNET",
	"MODEM",		"CDMA",				"GPRS",				"WCDMA",
	"TD",			"WIFI_NET",			"BAR_CODE",			"BLUE_TOOTH",
	"SD_READER",	"CONFIG_FILE_VER",	"MAIN_BOARD",		"PORT_BOARD",
	"MODEM_BOARD",	"RF_BOARD",			"ANT_BOARD",		"GPRS_BOARD",
	"WCDMA_BOARD",	"TD_BOARD",			"WIFI_BOARD",		"KEY_BOARD",
	"IP_BOARD",		"PRINT_BOARD",		"POWER_BOARD",		"SAM_BOARD",
	"ICCARD_BOARD",	"MESH_BOARD",		"TELEPHONE_BOARD",	"DISP_BOARD",
	"RF_PARA",		"G_SENSOR_PARA",	"DUAL_SIM",			"PN",
	"RF_PARA_1",	"RF_PARA_2",		"RF_PARA_3",		""
};
*/
//C_ 表示跟配置表对应 即与KeyWord[]对应
#define C_PRINTER 0 
#define C_TOUCH_SCREEN 1 
#define C_MAG_CARD 2
#define C_IC_CARD 3
#define C_RF_1356M 4
#define C_RF_24G 5
#define C_G_SENSOR 6
#define C_ETHERNET 7
#define C_MODEM 8
#define C_CDMA 9
#define C_GPRS 10
#define C_WCDMA 11
#define C_TD 12
#define C_WIFI_NET 13
#define C_BAR_CODE 14
#define C_BLUE_TOOTH 15
#define C_SD_READER 16
#define C_CONFIG_FILE_VER 17
#define C_MAIN_BOARD 18
#define C_PORT_BOARD 19
#define C_MODEM_BOARD 20
#define C_RF_BOARD 21
#define C_ANT_BOARD 22
#define C_GPRS_BOARD 23
#define C_WCDMA_BOARD 24
#define C_TD_BOARD 25
#define C_WIFI_BOARD 26
#define C_KEY_BOARD  27
#define C_IP_BOARD 28
#define C_PRINT_BOARD 29
#define C_POWER_BOARD 30
#define C_SAM_BOARD 31
#define C_ICCARD_BOARD 32
#define C_MESH_BOARD 33
#define C_TELEPHONE_BOARD 34
#define C_DISP_BOARD 35
#define C_RF_PARA 36
#define C_G_SENSOR_PARA 37
#define C_DUAL_SIM 38
#define C_PN  39
#define C_RF_PARA_1  40
#define C_RF_PARA_2  41
#define C_RF_PARA_3  42	
#define C_LCD		 43
#define C_SM_CHIP	 44
#define C_CIPHER_CHIP 45



void  DisSubMenuEx(TESTSINGLE_ITEM TestItem[],char TestNum,char *ChTitle,char *EnTitle,uchar mode);
void  PEDTestAll(void);
uchar PEDTest(uchar flag);
uchar PEDInit(uchar flag);

ST_LCD_INFO stLcdInfo;

#define C_BLUE		0xff0000ff
#define C_GREEN		0xff00ff00
#define C_RED		0xffff0000
#define C_WHITE     0xffffffff
#define C_BLACK     0xff000000
#define C_YELLOW    0x00ffffff


#define ROUTE_LAN 0 //以太网网卡
#define ROUTE_PPPOE 1 //表示PPPoE
#define ROUTE_MODEM 10//表示modem PPP链路
#define ROUTE_WNET 11//表示无线(GPRS/CDMA)PPP链路
#define ROUTE_WIFI 12//表示WIFI链路



#endif

