/* HSTMATCH module=EBOOT.BIN start=0x000aaf54 end=0x000ab044 symbol=FUN_000aaf54 lang=c99 */
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

extern float DAT_002d46b0;
extern float DAT_002d46b4;
extern int FUN_000b3c68();

float FUN_000aaf54(float param_1,undefined4 param_2)
{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar3 = ABS((param_1 - -2.0f) / -4.4007998f);
  fVar5 = DAT_002d46b0;
  if ((DAT_002d46b0 <= fVar3) && (fVar5 = DAT_002d46b4, fVar3 <= DAT_002d46b4)) {
    fVar5 = fVar3;
  }
  iVar1 = FUN_000b3c68(param_2);
  iVar2 = FUN_000b3c68(param_2);
  fVar4 = *(float *)(iVar1 + 0x140);
  fVar3 = *(float *)(iVar2 + 0x144);
  iVar1 = FUN_000b3c68(param_2);
  return (fVar3 + fVar5 * (fVar4 - fVar3)) * 0.01f * -(*(float *)(iVar1 + 0x24) * 0.01f);
}
// near miss from lane dsn3 (unreviewed)
