/* HSTMATCH module=EBOOT.BIN start=0x001c1d0c end=0x001c1d58 symbol=FUN_001c1d0c lang=c99 helpers=FUN_001be424@0x001be424-0x001be450 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* WIP: 18 of 19 words differ after including param_5 in the call. The callee is variadic and saves a0-a3,t0-t3;
   target passes the string plus five values in order (a,b,d,c,e). Remaining differences are register colors and
   store/setup scheduling: retail uses v1 for the global base, writes DAT_003419f4 during argument setup, and puts
   the DAT_00341c34 store in the tail-jump delay slot. */
extern int DAT_003417c4;
extern int DAT_003418d4;
extern int DAT_003419f4;
extern int DAT_00341b14;
extern int DAT_00341c34;
extern int DAT_002ea2b0[];

static void FUN_001be424(...)
{
}

void FUN_001c1d0c(int param_1, int param_2, int param_3, int param_4, int param_5)
{
  DAT_003417c4 = param_1;
  DAT_003418d4 = param_2;
  DAT_00341b14 = param_3;
  DAT_003419f4 = param_4;
  DAT_00341c34 = param_5;
  FUN_001be424(DAT_002ea2b0, param_1, param_2, param_4, param_3, param_5);
}
