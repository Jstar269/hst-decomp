/* HSTMATCH module=EBOOT.BIN start=0x00048258 end=0x000483d0 symbol=FUN_00048258 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

/* The frame buffer is 512 pixels wide at two bytes per pixel. */
enum { FRAME_ROW_BYTES = 1024 };

extern void FUN_00004f60(int a, int b);
extern void FUN_002b7910(int a, int b);
extern void FUN_002b7a78(void);
extern void FUN_002b7928(int a, int b, int c);
extern int FUN_002b7a50(void);
extern int FUN_00004b74(void);
extern void FUN_00004fcc(int a);
extern void FUN_002b79c8(void);
extern void FUN_00011090(void *dst, const void *src, unsigned n);

extern unsigned char DAT_002d0224;
extern int DAT_002d072c;
extern unsigned int DAT_0031105c;
extern int DAT_00310fe0;   /* pending image: source pixels, 0 when none */
extern int DAT_00310fe4;   /* pending image: x */
extern int DAT_00310fe8;   /* pending image: y */
extern int DAT_00310fec;   /* pending image: width in pixels */
extern int DAT_00310ff0;   /* pending image: height in rows */
extern int DAT_00310fc0;   /* frame buffer base */
extern int DAT_0032b244;
extern int DAT_0032b248;

/* Waits for the display, then copies the pending 16-bit image into the frame buffer. */
void FUN_00048258(void)
{
    if (DAT_002d0224 == 0) {
        return;
    }
    FUN_00004f60(0, 0);
    FUN_002b7910(DAT_002d072c, 1);
    do {
        FUN_002b7a78();
    } while (DAT_0031105c < 2 && DAT_00310fe0 == 0);
    DAT_0031105c = 0;
    FUN_002b7928(DAT_002d072c, 1, 0);
    DAT_0032b248 = DAT_00310fc0;
    {
        int buffer = FUN_002b7a50() + FUN_00004b74();
        DAT_00310fc0 = buffer;
        DAT_0032b244 = buffer;
    }
    FUN_00004fcc(1);
    if (DAT_00310fe0 != 0) {
        char *src = (char *)DAT_00310fe0;
        char *dst = (char *)DAT_00310fc0 + ((DAT_00310fe4 + (DAT_00310fe8 << 9)) << 1);
        int i = 0;

        while (i < DAT_00310ff0) {
            FUN_00011090(dst, src, DAT_00310fec << 1);
            src += DAT_00310fec << 1;
            i++;
            dst += FRAME_ROW_BYTES;
        }
        FUN_002b79c8();
        DAT_00310fe0 = 0;
    }
    DAT_002d0224 = 0;
}
