/* HSTMATCH module=hstp_trans_main.prx start=0x0009378c end=0x00093860 symbol=FUN_0009378c lang=c99 */
/* Clone of src/eboot/initialize_state_00091af4.c (hstclone.py tag u2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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

extern undefined DAT_003e1a30;
extern char DAT_00378a5c[];
extern char DAT_00378a68[];
extern char DAT_00378af0[];
extern char DAT_00378afc[];
extern void FUN_000963e0();

void FUN_0009378c(int param_1)
{
  unsigned int count;
  unsigned int global_count;
  unsigned int sentinel_count;
  int *cursor;
  int *global_cursor;
  int *sentinel_cursor;

  count = 0;
  cursor = (int *)param_1;
  do {
    ++count;
    cursor[0x14] = 0;
    ++cursor;
  } while (count < 6);
  *(int *)(param_1 + 0x68) = -1;
  *(int *)(param_1 + 0x6c) = 0;
  *(int *)(param_1 + 0x70) = 0;
  *(unsigned char *)(param_1 + 0x74) = 0;
  *(unsigned char *)(param_1 + 0x75) = 0;
  global_count = 0;
  global_cursor = (int *)&DAT_003e1a30;
  do {
    global_cursor[0] = 0;
    global_cursor[1] = 0;
    ++global_count;
    global_cursor[2] = 0;
    global_cursor += 4;
  } while (global_count < 2);
  sentinel_count = 0;
  sentinel_cursor = (int *)param_1;
  do {
    ++sentinel_count;
    sentinel_cursor[1] = -1;
    ++sentinel_cursor;
  } while (sentinel_count < 7);
  *(int *)(param_1 + 0x20) = -1;
  *(int *)(param_1 + 0x24) = 0;
  FUN_000963e0(param_1 + 0x80,DAT_00378af0,DAT_00378a68);
  FUN_000963e0(param_1 + 0xb0,DAT_00378a5c,DAT_00378afc);
}
