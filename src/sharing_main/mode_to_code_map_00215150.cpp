/* HSTMATCH module=hstp_trans_main.prx start=0x00215150 end=0x002151fc symbol=FUN_00215150 lang=c++ rodata=0x002d9860 */
/* Clone of src/eboot/mode_to_code_map_002068e8.cpp (hstclone.py tag ds1011s2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" int FUN_00215150(int param_1, int param_2, int param_3)
{
    int r = -1;
    switch (param_3) {
    case 0:
        switch (param_2) {
        case 0:
            r = 1;
            break;
        case 1:
            r = 2;
            break;
        case 2:
            r = 3;
            break;
        }
        break;
    case 1:
        r = 10;
        break;
    case 2:
        r = 9;
        break;
    case 3:
        r = 5;
        break;
    case 4:
        r = 7;
        break;
    case 5:
        r = 8;
        break;
    case 6:
        r = 6;
        break;
    case 7:
        r = 12;
        break;
    case 8:
        r = 4;
        break;
    case 9:
        r = 4;
        break;
    case 10:
        r = 4;
        break;
    case 11:
        r = 11;
        break;
    case 12:
        break;
    }
    return r;
}
