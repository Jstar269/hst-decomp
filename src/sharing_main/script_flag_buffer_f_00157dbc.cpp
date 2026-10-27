/* HSTMATCH module=hstp_trans_main.prx start=0x00157dbc end=0x00157e10 symbol=FUN_00157dbc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* script_command.cpp (assert strings, line 368): bounds-checked element address of the float buffer m_FlagBufferF[64]. */
#define BULK_OF(a) (sizeof(a) / sizeof((a)[0]))

struct ScriptCommand {
    char pad0[0x10c];
    float m_FlagBufferF[64];  /* 0x10c */
};

extern char DAT_003834cc[];  /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern char DAT_003835a0[];  /* "0 <= index && index < BULK_OF(m_FlagBufferF)" */
extern char DAT_0038350c[];  /* "script_command.cpp" */

extern "C" void FUN_00157280(const char *fmt, ...);

#define ASSERT(c, text, line) \
    if (!(c)) { FUN_00157280(DAT_003834cc, text, DAT_0038350c, line); for (;;) {} }

extern "C" float *FUN_00157dbc(ScriptCommand *self, int index)
{
    ASSERT(0 <= index && index < BULK_OF(self->m_FlagBufferF), DAT_003835a0, 368);
    return &self->m_FlagBufferF[index];
}
