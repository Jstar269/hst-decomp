/* HSTMATCH module=hstp_trans_main.prx start=0x002beaa8 end=0x002beb28 symbol=FUN_002beaa8 lang=c++ */
/* Hand-written reconstruction from the disassembly (vs_history_data.cpp per the assert strings; strlen/memset/strcpy are FUN_00014a40/FUN_000114c0/FUN_000149a8); exact match verified; names and types await human review. */
struct HistoryData {
    char pad[0x1c];
    char comment[75];
};

extern "C" {
extern char DAT_003abef4[];
extern char DAT_003abf20[];
extern char DAT_003abf44[];
void FUN_002be7c0(...);
unsigned int FUN_00014a40(const char *s);
void *FUN_000114c0(void *p, int c, unsigned int n);
char *FUN_000149a8(char *d, const char *s);
}

#define ASSERT(c, line) if (!(c)) { FUN_002be7c0(DAT_003abef4, DAT_003abf20, DAT_003abf44, line); for (;;) {} }

extern "C" void FUN_002beaa8(HistoryData *self, const char *comment)
{
    ASSERT(FUN_00014a40(comment) < sizeof(self->comment), 784);
    FUN_000114c0(self->comment, 0, sizeof(self->comment));
    FUN_000149a8(self->comment, comment);
}
