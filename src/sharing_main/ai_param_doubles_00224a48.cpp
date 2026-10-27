/* HSTMATCH module=hstp_trans_main.prx start=0x00224a48 end=0x00224af4 symbol=FUN_00224a48 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_003978bc[];  /* "assertion \"%s\" failed: file \"%s\", line %d\n" (PlayerAI.cpp copy) */
extern char DAT_00397e08[];  /* "0 <= rank && rank < g_AIParameterDoubles->m_Param.size()" */
extern char DAT_003978fc[];  /* "PlayerAI.cpp" */
extern char DAT_002d9d70[];  /* "assertion \"%s\" failed: file \"%s\", line %d\n" (AIParameter.h copy) */
extern char DAT_002d9d48[];  /* "0 <= index && index < m_Param.size()" */
extern char DAT_002d9d38[];  /* "AIParameter.h" */

extern "C" void FUN_002164c4(const char *fmt, ...);
extern "C" int FUN_0021a14c(void);

#define ASSERT(c, fmt, text, file, line) \
    if (!(c)) { FUN_002164c4(fmt, text, file, line); for (;;) {} }

struct AIParam { char raw[0x48]; };

struct ParamArray {
    AIParam *data;
    unsigned count;
    unsigned size() const { return count; }
    const AIParam &operator[](unsigned i) const { return data[i]; }
};

/* AIParameter.h */
struct AIParameter {
    ParamArray m_Param;
    const AIParam &Get(int index) const
    {
        ASSERT(0 <= index && index < m_Param.size(), DAT_002d9d70, DAT_002d9d48, DAT_002d9d38, 345);
        return m_Param[index];
    }
};

extern AIParameter *DAT_003f39e4;  /* g_AIParameterDoubles */

/* PlayerAI.cpp: the doubles AI parameter set for the current rank */
extern "C" const AIParam *FUN_00224a48(void)
{
    int rank = FUN_0021a14c();
    ASSERT(0 <= rank && rank < DAT_003f39e4->m_Param.size(), DAT_003978bc, DAT_00397e08, DAT_003978fc, 5808);
    return &DAT_003f39e4->Get(rank);
}
