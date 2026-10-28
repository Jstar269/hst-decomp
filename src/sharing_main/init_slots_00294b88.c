/* HSTMATCH module=hstp_trans_main.prx start=0x00294b88 end=0x00294d9c symbol=FUN_00294b88 lang=c99 */
/* Hand-written reconstruction (port of src/eboot/init_slots_00283660.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */

#include "hst/types.h"

extern char * DAT_003e1e04;
extern char * DAT_003ea8e8;
extern void FUN_000133f4(u32);
extern u32 FUN_0001342c(void);
extern void * FUN_0008e818(void *, void *);
extern void * FUN_0008e830(void *, void *);
extern void FUN_0008e860(void *);
extern void FUN_0008ea40(void *);
extern int FUN_000c08c8(void *, void *, int);
extern int FUN_000c09d0(void *, int, void *, int);
extern u32 FUN_002c7698(void);

void FUN_00294b88(char *param_1)
{
    int i = 0;
    int off = 0;
    char *p = param_1;

    do {
        if ((*(u8 *)(DAT_003e1e04 + off + 0x5e) != 0) && (*(u8 *)(p + 0xa6d) == 0)) {
            if (i == *(int *)(DAT_003e1e04 + 0x198)) {
                if ((u8)FUN_000c08c8(DAT_003e1e04, p + 0x940, 0x458)) {
                    u32 k = 0;
                    char *q = p;
                    do {
                        k++;
                        *(int *)(q + 0x940) = -1;
                        q += 4;
                    } while (k < 4);
                    *(int *)(p + 0x950) = -1;
                    *(u8 *)(p + 0x954) = 0;
                    FUN_0008e860(p + 0x958);
                    FUN_0008ea40(p + 0x980);
                    *(u8 *)(p + 0xa4c) = 0;
                    FUN_0008ea40(p + 0xaa0);
                    FUN_0008ea40(p + 0xbc0);
                    *(u8 *)(p + 0xb6c) = 0;
                    *(u8 *)(p + 0xc8c) = 0;
                    FUN_0008e830(p + 0xa88, DAT_003ea8e8 + 4);
                    FUN_0008e818(p + 0xa98, DAT_003ea8e8 + 0x18);
                    *(u8 *)(p + 0xa6d) = 1;
                    FUN_000133f4(FUN_002c7698());
                    *(u32 *)(p + 0xa84) = FUN_0001342c();
                    *(u8 *)(param_1 + 0x615) = 1;
                    FUN_000133f4(FUN_002c7698());
                    *(u32 *)(param_1 + 0x62c) = FUN_0001342c();
                }
            } else {
                if ((u8)FUN_000c09d0(DAT_003e1e04, i, p + 0x940, 0x458)) {
                    u32 k = 0;
                    char *q = p;
                    do {
                        k++;
                        *(int *)(q + 0x940) = -1;
                        q += 4;
                    } while (k < 4);
                    *(int *)(p + 0x950) = -1;
                    *(u8 *)(p + 0x954) = 0;
                    FUN_0008e860(p + 0x958);
                    FUN_0008ea40(p + 0x980);
                    *(u8 *)(p + 0xa4c) = 0;
                    FUN_0008ea40(p + 0xaa0);
                    FUN_0008ea40(p + 0xbc0);
                    *(u8 *)(p + 0xb6c) = 0;
                    *(u8 *)(p + 0xc8c) = 0;
                    FUN_0008e830(p + 0xa88, DAT_003ea8e8 + 4);
                    FUN_0008e818(p + 0xa98, DAT_003ea8e8 + 0x18);
                    *(u8 *)(p + 0xa6d) = 1;
                    FUN_000133f4(FUN_002c7698());
                    *(u32 *)(p + 0xa84) = FUN_0001342c();
                }
            }
        }
        i++;
        off += 7;
        p += 0x458;
    } while (i < 4);
}
