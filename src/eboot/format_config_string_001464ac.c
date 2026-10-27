/* HSTMATCH module=EBOOT.BIN start=0x001464ac end=0x00146500 symbol=FUN_001464ac lang=c99 data=0x002dc110 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc110-0x002dc11e) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
typedef struct {
    unsigned char pad0[0xd28];
    char key[0x40];
    char value[0x40];
} Cfg;

extern Cfg *DAT_003402b0;
extern char DAT_002c1910;
extern int FUN_000143b0(char *, const char *, ...);

void FUN_001464ac(int unused, char *out)
{
    char buf[512];
    Cfg *c = DAT_003402b0;

    FUN_000143b0(buf, &DAT_002c1910, c->value, c->key);
    FUN_000143b0(out, "%s/sedata.dat", buf);
}
