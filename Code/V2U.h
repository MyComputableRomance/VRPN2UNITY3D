#if defined (EXPORTBUILD)  
# define _DLLExport __declspec (dllexport)  
# else  
# define _DLLExport __declspec (dllimport)  
#endif

extern "C" float _DLLExport getPosX();
extern "C" float _DLLExport getPosY();
extern "C" float _DLLExport getPosZ();
extern "C" float _DLLExport getQuatX();
extern "C" float _DLLExport getQuatY();
extern "C" float _DLLExport getQuatZ();
extern "C" float _DLLExport getQuatW();
extern "C" void _DLLExport setUp(char*,int);
extern "C" void _DLLExport vrpnRun(int);
extern "C" void _DLLExport vrpnStatus();