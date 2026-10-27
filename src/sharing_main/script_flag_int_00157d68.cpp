/* HSTMATCH module=hstp_trans_main.prx start=0x00157d68 end=0x00157dbc symbol=FUN_00157d68 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* script_command.cpp (debug build): bounds-asserted access to the integer flag buffer (assert line 362). */
#define BULK_OF(a) (sizeof(a) / sizeof((a)[0]))

struct ScriptCommand {
  char pad0[0xc];
  int m_FlagBufferI[64];
};

extern "C" {
extern const char DAT_003834cc[];   /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern const char DAT_00383570[];   /* "0 <= index && index < BULK_OF(m_FlagBufferI)" */
extern const char DAT_0038350c[];   /* "script_command.cpp" */
void FUN_00157280(...);
}

#define HST_ASSERT(cond, text, line) \
  do { if (!(cond)) { FUN_00157280(DAT_003834cc, text, DAT_0038350c, line); for (;;) {} } } while (0)

extern "C" int *FUN_00157d68(ScriptCommand *self, int index)
{
  HST_ASSERT(0 <= index && index < BULK_OF(self->m_FlagBufferI), DAT_00383570, 362);
  return &self->m_FlagBufferI[index];
}
