/* HSTMATCH module=hstp_trans_main.prx start=0x0026a4ac end=0x0026a598 symbol=FUN_0026a4ac lang=c99 */
/* Clone of src/eboot/create_player_obj_00259ffc.c (hstclone.py tag u6fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: reconstructed player string branch, decrement condition, and if ((puVar2 = alloc())) pattern; exact match verified; names and types await human review. */

typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined DAT_002cc260;
extern undefined DAT_003b0a68;
extern char DAT_002dad94[];
extern char DAT_002dada0[];
extern void *FUN_00000bcc(int);
extern int FUN_00014934(int, const char *);
extern undefined4 FUN_00056cac(void *);
extern undefined4 *FUN_001016c0(void *, void *);
extern undefined4 *FUN_00101748(void *, void *);
extern undefined4 *FUN_001017dc(void *);

undefined4 *FUN_0026a4ac(int param_1, int param_2, char *param_3)
{
    const char *str;
    if (*(unsigned char *)(param_1 + 0x644) != '\0') {
        str = DAT_002dada0;
    } else {
        str = DAT_002dad94;
    }

    if (FUN_00014934(param_2, str) == 0) {
        int val = *(int *)(param_1 + 0x648);
        *(int *)(param_1 + 0x648) = val - 1;
        *param_3 = 0 < val;
    } else {
        *param_3 = 0;
    }

    undefined4 *puVar2;
    if ((puVar2 = (undefined4 *)FUN_00000bcc(0xd0)) != 0) {
        FUN_001017dc(puVar2);
        FUN_00056cac(puVar2 + 0xc);
        *puVar2 = (unsigned int)&DAT_003b0a68;
        puVar2[0x1c] = 0;
        puVar2[0x1d] = 0xffffffff;
        puVar2[0x1e] = 0x3f800000;
        puVar2[0x1f] = 0x3f800000;
        FUN_00056cac(puVar2 + 0x20);
        puVar2[0x30] = param_2;
        FUN_00101748(puVar2, &DAT_002cc260);
        FUN_001016c0(puVar2 + 0x20, &DAT_002cc260);
    }
    return puVar2;
}
