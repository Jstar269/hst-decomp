/* HSTMATCH module=EBOOT.BIN start=0x00225090 end=0x00225288 symbol=FUN_00225090 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_parts.h"

extern void *FUN_00000bcc();
extern void *FUN_0018a5a8();
extern void *FUN_0021aa34();
extern void *FUN_0021aec0();
extern void *FUN_0021b328();
extern void *FUN_0021b478();
extern void *FUN_0021bb04();
extern void *FUN_0021f5c4();
extern void *FUN_0022060c();
extern void *FUN_002226b4();
extern void *FUN_002239ec();
extern void *FUN_00224468();
extern void *FUN_00224a28();
extern void FUN_00291b8c();
extern void FUN_002931f0(float, u32, int);
extern u32 FUN_002933fc();

extern u32 DAT_0034a820;

/* Build the part set: clear every pointer, then allocate and construct each part. */
ModeParts *FUN_00225090(ModeParts *parts)
{
    void *part;

    parts->part00 = 0;
    parts->part04 = 0;
    parts->part08 = 0;
    parts->part0c = 0;
    parts->part10 = 0;
    parts->part14 = 0;
    parts->part18 = 0;
    parts->part1c = 0;
    parts->part20 = 0;
    parts->part24 = 0;
    parts->part28 = 0;
    parts->part2c = 0;
    parts->part30 = 0;

    part = FUN_00000bcc(0x90);
    if (part != 0) part = FUN_0021aec0(part);
    parts->part00 = part;

    part = FUN_00000bcc(0x60);
    if (part != 0) part = FUN_0021b328(part);
    parts->part04 = part;

    part = FUN_00000bcc(0x19c);
    if (part != 0) part = FUN_0021b478(part);
    parts->part08 = part;

    part = FUN_00000bcc(0xe8);
    if (part != 0) part = FUN_0021bb04(part, 1);
    parts->part0c = part;

    part = FUN_00000bcc(0x90);
    if (part != 0) part = FUN_0021f5c4(part);
    parts->part10 = part;

    part = FUN_00000bcc(0xcc);
    if (part != 0) part = FUN_002226b4(part, 0);
    parts->part18 = part;

    part = FUN_00000bcc(0x78);
    if (part != 0) part = FUN_0022060c(part);
    parts->part1c = part;

    part = FUN_00000bcc(0xb4);
    if (part != 0) part = FUN_002239ec(part);
    parts->part20 = part;

    part = FUN_00000bcc(0x11c);
    if (part != 0) part = FUN_00224468(part);
    parts->part24 = part;

    part = FUN_00000bcc(8);
    if (part != 0) part = FUN_0021aa34(part);
    parts->part28 = part;

    part = FUN_00000bcc(0xc9c);
    if (part != 0) part = FUN_0018a5a8(part);
    parts->part2c = part;

    part = FUN_00000bcc(0x880);
    if (part != 0) part = FUN_00224a28(part);
    parts->part30 = part;

    if (DAT_0034a820 != 0) {
        FUN_00291b8c(DAT_0034a820, 1);
        if (FUN_002933fc(DAT_0034a820) != 0) {
            FUN_002931f0(65535.0f, DAT_0034a820, -1);
        }
    }
    return parts;
}
