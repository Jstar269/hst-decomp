/* HSTMATCH module=hstp_trans_main.prx start=0x001107c8 end=0x001108a4 symbol=game_sharing_update_001107c8 lang=c99 data=0x0037fde8 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. Data: its string literals (3 strings, 0x0037fde8-0x0037fe85) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern void FUN_00110268(const char *name, int val);
extern int FUN_002c7a08(int mode);
extern int FUN_002c7a20(void);
extern int FUN_002c7a68(void);

int game_sharing_update_001107c8(char *param_1)
{
    int res = 0;
    int mode = FUN_002c7a20();
    if (mode != 0) {
        switch (mode) {
        case 1:
            break;
        case 2:
            res = FUN_002c7a08(2);
            if (res != 0) {
                FUN_00110268("ERROR: sceUtilityGameSharingUpdate failed - %x\n", res);
            }
            break;
        case 3:
            res = FUN_002c7a68();
            if (res != 0) {
                FUN_00110268("ERROR: sceUtilityGameSharingShutdownStart failed - %x\n", res);
            }
            break;
        case 4:
            break;
        default:
            break;
        }
    } else {
        FUN_00110268("UtilityGameSharing::Update(): m_param.result = 0x%x\n", *(int *)(param_1 + 0x4c));
        res = *(int *)(param_1 + 0x4c);
    }
    return res;
}
