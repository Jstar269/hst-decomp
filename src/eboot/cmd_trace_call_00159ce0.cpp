/* HSTMATCH module=EBOOT.BIN start=0x00159ce0 end=0x00159d60 symbol=FUN_00159ce0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Command handler: optional trace hook (0x14d044) when the debug flag is set, call 0x63b20 with 65535.0f, a global
   and the object field at +8, then a debug print (empty variadic stub 0x14fd94) using the flag value read before
   the call. The flag copy must be unsigned char (no andi) and the callee needs a float prototype. Names provisional. */
extern "C" {
extern unsigned char DAT_003402f0;
extern int DAT_00331b84;
extern char DAT_002dcbdc[];
void FUN_00063b20(float f, int a, int b);
void FUN_0014d044(int a);
void FUN_0014fd94(char *fmt, ...);
}
struct Obj_00159ce0 { int a; int b; int c; };
extern "C" int FUN_00159ce0(Obj_00159ce0 *self, int arg)
{
    if (DAT_003402f0)
        FUN_0014d044(arg);
    unsigned char on = DAT_003402f0;
    int v = self->c;
    FUN_00063b20(65535.0f, DAT_00331b84, v);
    if (on)
        FUN_0014fd94(DAT_002dcbdc, v);
    return 0;
}
