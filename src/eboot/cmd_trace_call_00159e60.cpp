/* HSTMATCH module=EBOOT.BIN start=0x00159e60 end=0x00159ee0 symbol=FUN_00159e60 lang=c++ data=0x002dcc0c */
/* Clone of src/eboot/cmd_trace_call_00159ce0.cpp (hstclone.py tag c31): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dcc0c-0x002dcc19) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Command handler: optional trace hook (0x14d044) when the debug flag is set, call 0x63b20 with 65535.0f, a global
   and the object field at +8, then a debug print (empty variadic stub 0x14fd94) using the flag value read before
   the call. The flag copy must be unsigned char (no andi) and the callee needs a float prototype. Names provisional. */
extern "C" {
extern unsigned char DAT_003402f0;
extern int DAT_00331b84;
void FUN_00063a30(float f, int a, int b);
void FUN_0014d044(int a);
void FUN_0014fd94(char *fmt, ...);
}
struct Obj_00159e60 { int a; int b; int c; };
extern "C" int FUN_00159e60(Obj_00159e60 *self, int arg)
{
    if (DAT_003402f0)
        FUN_0014d044(arg);
    unsigned char on = DAT_003402f0;
    int v = self->c;
    FUN_00063a30(65535.0f, DAT_00331b84, v);
    if (on)
        FUN_0014fd94("BlackIn  %d\n", v);
    return 0;
}
