/* HSTMATCH module=hstp_trans_main.prx start=0x00227bb4 end=0x00227d2c symbol=FUN_00227bb4 lang=c99 */
/* Clone of src/eboot/map_id_to_slot_0021869c.c (hstclone.py tag u5fr4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
void FUN_00227bb4(int *param_1, int *param_2, int param_3)
{
    if (param_3 == 0x8f) {
        *param_1 = 0;
        *param_2 = 0x29;
    } else if (param_3 == 0x90) {
        *param_1 = 0;
        *param_2 = 0x2c;
    } else if (param_3 == 0xfa) {
        *param_1 = 0;
        *param_2 = 0x2f;
    } else if (param_3 == 0xfb) {
        *param_1 = 0;
        *param_2 = 0x31;
    } else if (param_3 == 0xfc) {
        *param_1 = 1;
        *param_2 = 0x27;
    } else if (param_3 == 0xfd) {
        *param_1 = 2;
        *param_2 = 5;
    } else if (param_3 == 0xfe) {
        *param_1 = 2;
        *param_2 = 9;
    } else if (param_3 == 0xff) {
        *param_1 = 2;
        *param_2 = 0xe;
    } else if (param_3 >= 600) {
        *param_1 = 6;
        *param_2 = param_3 - 600;
    } else if (param_3 >= 500) {
        *param_1 = 5;
        *param_2 = param_3 - 500;
    } else if (param_3 >= 400) {
        *param_1 = 4;
        *param_2 = param_3 - 400;
    } else if (param_3 >= 300) {
        *param_1 = 3;
        *param_2 = param_3 - 300;
    } else {
        *param_1 = param_3 / 64;
        *param_2 = param_3 % 64;
    }
}
