/* HSTMATCH module=hstp_trans_main.prx start=0x002639f0 end=0x00263a60 symbol=FUN_002639f0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* adhoc_common.cpp (assert strings, line 173): index of a court id in m_court_id; member names from the neighbouring
   getter's assert "court_id >= 0 && court_id < m_court_id_num" (0x00263998). */
struct AdhocCommon {
    char pad0[0x38];
    int m_court_id_num;  /* 0x38 */
    int m_court_id[1];   /* 0x3c, length not visible here */
};

extern char DAT_003a5740[];  /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern char DAT_003a57ac[];  /* "index >= 0" */
extern char DAT_003a5798[];  /* "adhoc_common.cpp" */

extern "C" void FUN_0026396c(const char *fmt, ...);

#define ASSERT(c, text, line) \
    if (!(c)) { FUN_0026396c(DAT_003a5740, text, DAT_003a5798, line); for (;;) {} }

extern "C" int FUN_002639f0(AdhocCommon *self, int id)
{
    int index = -1;
    for (int i = 0; i < self->m_court_id_num; i++) {
        if (self->m_court_id[i] == id) {
            index = i;
            break;
        }
    }
    ASSERT(index >= 0, DAT_003a57ac, 173);
    return index;
}
