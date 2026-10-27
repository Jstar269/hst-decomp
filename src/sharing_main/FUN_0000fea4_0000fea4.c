/* HSTMATCH module=hstp_trans_main.prx start=0x0000fea4 end=0x0000ff38 symbol=FUN_0000fea4 lang=c99 cc=gcc171-O2 */
/* Clone of src/eboot/FUN_0000fea4.c (hstclone.py tag a2c3s): addresses substituted; exact match verified; names and types await human review. */
/* Library source: newlib libc locale locale.c function _setlocale_r (newlib, Red Hat / Cygnus licence), adapted by hand from the newlib source, newlib version not recorded; exact match verified; names and types await human review. */
struct reent { char pad[48]; int cat; const char *loc; }; extern char DAT_002ca6f8[], DAT_002ca6b8[]; extern int FUN_00014934(const char *a, const char *b);
char *FUN_0000fea4(struct reent *p, int category, const char *locale) { if (locale) { if (FUN_00014934(locale, DAT_002ca6f8) && FUN_00014934(locale, DAT_002ca6b8)) return 0; p->cat = category; p->loc = locale; } return DAT_002ca6f8; }
