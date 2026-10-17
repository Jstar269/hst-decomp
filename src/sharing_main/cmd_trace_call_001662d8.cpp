/* HSTMATCH module=hstp_trans_main.prx start=0x001662d8 end=0x00166358 symbol=FUN_001662d8 lang=c++ */
/* Clone of src/eboot/cmd_trace_call_00159ce0.cpp (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Command handler: optional trace hook (0x14d044) when the debug flag is set, call 0x63b20 with 65535.0f, a global
   and the object field at +8, then a debug print (empty variadic stub 0x14fd94) using the flag value read before
   the call. The flag copy must be unsigned char (no andi) and the callee needs a float prototype. Names provisional. */
extern "C" {
extern unsigned char DAT_003e9630;
extern int DAT_003daec4;
extern char DAT_00384154[];
void FUN_00064ad8(float f, int a, int b);
void FUN_00158b2c(int a);
void FUN_0015bb68(char *fmt, ...);
}
struct Obj_001662d8 { int a; int b; int c; };
extern "C" int FUN_001662d8(Obj_001662d8 *self, int arg)
{
    if (DAT_003e9630)
        FUN_00158b2c(arg);
    unsigned char on = DAT_003e9630;
    int v = self->c;
    FUN_00064ad8(65535.0f, DAT_003daec4, v);
    if (on)
        FUN_0015bb68(DAT_00384154, v);
    return 0;
}
