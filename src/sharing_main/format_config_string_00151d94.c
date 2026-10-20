/* HSTMATCH module=hstp_trans_main.prx start=0x00151d94 end=0x00151de8 symbol=FUN_00151d94 lang=c99 */
/* Clone of src/eboot/format_config_string_001464ac.c (hstclone.py tag s10200333g2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
typedef struct {
    unsigned char pad0[0xd28];
    char key[0x40];
    char value[0x40];
} Cfg;

extern Cfg *DAT_003e95f0;
extern char DAT_002d1cf0;
extern char DAT_00383468;
extern int FUN_000143b0(char *, const char *, ...);

void FUN_00151d94(int unused, char *out)
{
    char buf[512];
    Cfg *c = DAT_003e95f0;

    FUN_000143b0(buf, &DAT_002d1cf0, c->value, c->key);
    FUN_000143b0(out, &DAT_00383468, buf);
}
