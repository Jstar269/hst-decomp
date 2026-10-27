/* HSTMATCH module=hstp_trans_main.prx start=0x00157e10 end=0x00157e68 symbol=FUN_00157e10 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* script_command.cpp (debug build): asserts "0 <= index && index < 32" (line 375, empty variadic
   stub 0x157280, then the endless loop) and returns the address of the index-th int of the table at
   0x3e9634. The assert strings are the pooled module strings. */
extern char DAT_003834cc[];
extern char DAT_003835d0[];
extern char DAT_0038350c[];
extern int DAT_003e9634[];
extern void FUN_00157280(const char *fmt, ...);

#define ASSERT(c, text, line) \
    if (!(c)) { FUN_00157280(DAT_003834cc, text, DAT_0038350c, line); for (;;) {} }

int *FUN_00157e10(void *self, int index)
{
    ASSERT(0 <= index && index < 32, DAT_003835d0, 375);
    return &DAT_003e9634[index];
}
