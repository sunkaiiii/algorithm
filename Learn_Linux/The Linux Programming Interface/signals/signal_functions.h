#ifndef singal_functions_h
#define singal_functions_h


void printSigset(FILE *of, const char *prefix, const sigset_t *sigset);
int printSigMask(FILE *of, const char *msg);
int printPendingSigs(FILE *of,const char *msg);
#endif 