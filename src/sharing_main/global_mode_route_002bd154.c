/* HSTMATCH module=hstp_trans_main.prx start=0x002bd154 end=0x002bd1a4 symbol=FUN_002bd154 lang=c99 */
/* Clone of src/eboot/global_mode_route_002ad998.c (hstclone.py tag u6fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: expressed the four accepted values with a single switch; exact match verified; names and types await human review. */

extern int DAT_003f39a8;
extern void FUN_002bcf14(int, int, int);

void FUN_002bd154(int param_1, int param_2)
{
    int val = 0;
    switch (DAT_003f39a8) {
    case 0:
    case 0x2a:
    case 0x31:
    case 0x44:
        val = 4;
        break;
    }
    FUN_002bcf14(val, param_1, param_2);
}
