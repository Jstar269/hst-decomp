/* HSTMATCH module=hstp_trans_main.prx start=0x00157e68 end=0x00157ec0 symbol=FUN_00157e68 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* script_command.cpp line 382: bounds-checked slot of a 32-entry static table (debug build keeps the assert). */
extern "C" {
extern char DAT_003834cc[]; /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern char DAT_003835d0[]; /* "0 <= index && index < 32" */
extern char DAT_0038350c[]; /* "script_command.cpp" */
extern int DAT_003e96b4[32];
void FUN_00157280(const char *fmt, ...);
}

#define ASSERT(c, text, line) \
    if (!(c)) { FUN_00157280(DAT_003834cc, text, DAT_0038350c, line); for (;;) {} }

extern "C" int *FUN_00157e68(void *self, int index)
{
    ASSERT(0 <= index && index < 32, DAT_003835d0, 382);
    return &DAT_003e96b4[index];
}
