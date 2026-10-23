/* HSTMATCH module=hstp_trans_main.prx start=0x0022d170 end=0x0022d1f8 symbol=FUN_0022d170 lang=c99 */
/* Clone of src/eboot/update_progress_state_0021dbfc.c (hstclone.py tag km3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: store the source field before calculating the percentage from that stored value. */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern void FUN_0022d4e0(void *param_1,int param_2);
extern void FUN_0022d604(void *param_1,float param_2);
extern int FUN_002bf370(int param_1);

void FUN_0022d170(int param_1)
{
  float percent;
  *(undefined4 *)(param_1 + 0x1fc) = FUN_002bf370(*(int *)(param_1 + 0x170));
  *(int *)(param_1 + 0x200) = *(int *)(param_1 + 0x1f8);
  percent = (float)(*(int *)(param_1 + 0x200) - *(int *)(param_1 + 0x1f0)) * 100.0f /
             (float)(*(int *)(param_1 + 0x1f4) - *(int *)(param_1 + 0x1f0));
  FUN_0022d4e0((void *)param_1,*(int *)(param_1 + 0x1cc) - 1);
  FUN_0022d604((void *)param_1,percent);
}
