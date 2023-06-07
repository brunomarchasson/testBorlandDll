
#ifndef CalDevDefsH
#define CalDevDefsH

enum Type { DEV = 1, FTP,ODF };

typedef struct _OPTIONS {
  bool  autoOut;
} *P_OPTIONS;



typedef struct _RESULT {
  char* str;
   int   num;
} *P_RESULT;

 #endif
