/* HSTMATCH module=EBOOT.BIN start=0x0010aa08 end=0x0010aae4 symbol=game_sharing_update_0010aa08 lang=c99 data=0x002d9014 */
/* Clone of src/sharing_main/game_sharing_update_001107c8.c (hstclone.py tag u3r2e): addresses substituted; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x002d9014-0x002d90b1) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */

extern void FUN_0010a4a8(const char *name, int val);
extern int FUN_002b7c68(int mode);
extern int FUN_002b7c80(void);
extern int FUN_002b7cc8(void);

int game_sharing_update_0010aa08(char *param_1)
{
    int res = 0;
    int mode = FUN_002b7c80();
    if (mode != 0) {
        switch (mode) {
        case 1:
            break;
        case 2:
            res = FUN_002b7c68(2);
            if (res != 0) {
                FUN_0010a4a8("ERROR: sceUtilityGameSharingUpdate failed - %x\n", res);
            }
            break;
        case 3:
            res = FUN_002b7cc8();
            if (res != 0) {
                FUN_0010a4a8("ERROR: sceUtilityGameSharingShutdownStart failed - %x\n", res);
            }
            break;
        case 4:
            break;
        default:
            break;
        }
    } else {
        FUN_0010a4a8("UtilityGameSharing::Update(): m_param.result = 0x%x\n", *(int *)(param_1 + 0x4c));
        res = *(int *)(param_1 + 0x4c);
    }
    return res;
}
