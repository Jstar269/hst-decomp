/* HSTMATCH module=EBOOT.BIN start=0x00192b7c end=0x00192c98 symbol=FUN_00192b7c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: the 16-word copy from DAT_002bc410.. is four Vec4 struct assignments in plain C (batched lwc1 then swc1; in C++ MWCC interleaves or reorders them), the tail words stay integer constants; readability pass; exact match verified; names and types await human review. */
#include "hst/pose_holder.h"

extern Float4 DAT_002bc410;
extern Float4 DAT_002bc420;
extern Float4 DAT_002bc430;
extern Float4 DAT_002bc440;

/* Initializes a pose: four rows copied from constants, the tail words set to 1.0f bit patterns or zero, flag set. */
PoseObj *FUN_00192b7c(PoseObj *pose)
{
    pose->rows[0] = DAT_002bc410;
    pose->rows[1] = DAT_002bc420;
    pose->rows[2] = DAT_002bc430;
    pose->rows[3] = DAT_002bc440;
    pose->tail[0] = 0x3f800000;
    pose->tail[1] = 0x3f800000;
    pose->tail[2] = 0x3f800000;
    pose->tail[3] = 0x3f800000;
    pose->tail[4] = 0x3f800000;
    pose->tail[5] = 0;
    pose->tail[6] = 0;
    pose->tail[7] = 0x3f800000;
    pose->tail[8] = 0;
    pose->tail[9] = 0x3f800000;
    pose->tail[10] = 0;
    pose->tail[11] = 0x3f800000;
    pose->tail[12] = 0;
    pose->tail[13] = 0;
    pose->tail[14] = 0x3f800000;
    pose->tail[15] = 0x3f800000;
    pose->tail[16] = 0x3f800000;
    pose->tail[17] = 0x3f800000;
    pose->flag = 1;
    return pose;
}
