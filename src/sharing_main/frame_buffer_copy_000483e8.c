/* HSTMATCH module=hstp_trans_main.prx start=0x000483e8 end=0x00048560 symbol=FUN_000483e8 lang=c99 */
/* Clone of src/eboot/frame_buffer_copy_00048258.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern void FUN_00004f78(int a, int b);
extern void FUN_002c76b0(int a, int b);
extern void FUN_002c7818(void);
extern void FUN_002c76c8(int a, int b, int c);
extern int FUN_002c77f0(void);
extern int FUN_00004b74(void);
extern void FUN_00004fe4(int a);
extern void FUN_002c7768(void);
extern void FUN_00011090(void *dst, const void *src, unsigned n);

extern unsigned char DAT_0037596c;
extern int DAT_00375e84;
extern unsigned int DAT_003ba384;
extern int DAT_003ba2e0;
extern int DAT_003ba2e4;
extern int DAT_003ba2e8;
extern int DAT_003ba2ec;
extern int DAT_003ba2f0;
extern int DAT_003ba2c0;
extern int DAT_003d4584;
extern int DAT_003d4588;

void FUN_000483e8(void)
{
    if (DAT_0037596c == 0) {
        return;
    }
    FUN_00004f78(0, 0);
    FUN_002c76b0(DAT_00375e84, 1);
    do {
        FUN_002c7818();
    } while (DAT_003ba384 < 2 && DAT_003ba2e0 == 0);
    DAT_003ba384 = 0;
    FUN_002c76c8(DAT_00375e84, 1, 0);
    DAT_003d4588 = DAT_003ba2c0;
    {
        int v = FUN_002c77f0() + FUN_00004b74();
        DAT_003ba2c0 = v;
        DAT_003d4584 = v;
    }
    FUN_00004fe4(1);
    if (DAT_003ba2e0 != 0) {
        char *src = (char *)DAT_003ba2e0;
        char *dst = (char *)DAT_003ba2c0 + ((DAT_003ba2e4 + (DAT_003ba2e8 << 9)) << 1);
        int i = 0;

        while (i < DAT_003ba2f0) {
            FUN_00011090(dst, src, DAT_003ba2ec << 1);
            src += DAT_003ba2ec << 1;
            i++;
            dst += 1024;
        }
        FUN_002c7768();
        DAT_003ba2e0 = 0;
    }
    DAT_0037596c = 0;
}
