/* HSTMATCH module=hstp_trans_main.prx start=0x00166258 end=0x001662d8 symbol=FUN_00166258 lang=c++ data=0x00384144 */
/* Clone of src/eboot/cmd_trace_call_00159ce0.cpp (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00384144-0x00384151) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Command handler: optional trace hook (0x14d044) when the debug flag is set, call 0x63b20 with 65535.0f, a global
   and the object field at +8, then a debug print (empty variadic stub 0x14fd94) using the flag value read before
   the call. The flag copy must be unsigned char (no andi) and the callee needs a float prototype. Names provisional. */
extern "C" {
extern unsigned char DAT_003e9630;
extern int DAT_003daec4;
void FUN_000649e4(float f, int a, int b);
void FUN_00158b2c(int a);
void FUN_0015bb68(char *fmt, ...);
}
struct Obj_00166258 { int a; int b; int c; };
extern "C" int FUN_00166258(Obj_00166258 *self, int arg)
{
    if (DAT_003e9630)
        FUN_00158b2c(arg);
    unsigned char on = DAT_003e9630;
    int v = self->c;
    FUN_000649e4(65535.0f, DAT_003daec4, v);
    if (on)
        FUN_0015bb68("WhiteOut %d\n", v);
    return 0;
}
