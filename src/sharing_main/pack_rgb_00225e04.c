/* HSTMATCH module=hstp_trans_main.prx start=0x00225e04 end=0x00225e74 symbol=FUN_00225e04 lang=c99 */
/* Clone of src/eboot/pack_rgb_00216e00.c (hstclone.py tag u5fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: RGB local declaration order and nested packing ORs; exact match verified; names and types await human review. */

#include "hst/types.h"

u32 FUN_00225e04(u32 *param_1)
{
    int r;
    int b;
    int g;

    r = (int)param_1[0] >> 1;
    if (param_1[0] & 1) {
        r++;
    }

    b = (int)param_1[2] >> 1;
    if (param_1[2] & 1) {
        b++;
    }

    g = (int)param_1[1] >> 1;
    if (param_1[1] & 1) {
        g++;
    }

    return (((0x80000000 | ((b & 0xff) << 16)) | ((g & 0xff) << 8)) | (r & 0xff));
}
