/* HSTMATCH module=EBOOT.BIN start=0x000bd014 end=0x000bd26c symbol=FUN_000bd014 lang=c99 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef int code();
typedef unsigned char bool;

extern char s_ERROR__AdhocLib__Receiver____ePA_002d5400[];
extern char s_game_start_recv_002d53ec[];
extern char s_recv_unknown_packet_002d5440[];

extern int FUN_001268c4();
extern void FUN_001268b8();
extern void FUN_00126884();
extern void FUN_00011090();
extern void FUN_000ba3ac();
extern void FUN_000bc99c();

void FUN_000bd014(int param_1)
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  undefined4 local_4c[2];
  int local_44;
  int local_40;
  undefined4 local_3c[2];
  int local_34;
  int local_30;
  int local_2c;
  undefined4 local_28[2];
  int local_20;
  int local_1c;
  int local_14;
  int local_10;
  int local_4;

  if (*(int *)(param_1 + 0x17c) < 0) {
    return;
  }
LAB_000bd030:
  do {
    iVar3 = *(int *)(param_1 + 0x26c);
    while (1) {
      if (iVar3 == 0) {
        return;
      }
      uVar2 = FUN_001268c4();
      if (uVar2 < 0x10) {
        return;
      }
      FUN_001268b8(*(undefined4 *)(param_1 + 0x26c), &local_14, 0x10);
      if ((int)uVar2 < local_10) {
        return;
      }
      local_4 = local_10;
      FUN_00126884(*(undefined4 *)(param_1 + 0x26c), *(undefined4 *)(param_1 + 0x180), &local_4);
      if (local_14 == 5) {
        local_60 = 5;
        iVar4 = *(int *)(param_1 + 0x180);
        FUN_00011090(&local_60, iVar4, 0x14);
        iVar3 = *(int *)(param_1 + local_50 * 4 + 0x1dc);
        if (iVar3 != 0) {
          bVar1 = 0;
          if (*(int *)(param_1 + 0x280) == local_54) {
            bVar1 = *(int *)(param_1 + 0x27c) == local_58;
          }
          if (bVar1) {
            if (*(int *)(iVar3 + 8) == 0) {
              if (*(int *)(iVar3 + 4) != 0) {
                if (local_5c + -0x14 == *(int *)(iVar3 + 0xc)) {
                  FUN_00011090(*(int *)(iVar3 + 4), iVar4 + 0x14);
                  *(undefined1 *)(*(int *)(param_1 + local_50 * 4 + 0x1dc) + 0x10) = 1;
                }
                else {
                  FUN_000ba3ac(s_ERROR__AdhocLib__Receiver____ePA_002d5400, local_5c + -0x14,
                               *(int *)(iVar3 + 0xc));
                }
              }
            }
            else if (local_5c + -0x14 == *(int *)(iVar3 + 0xc)) {
              FUN_00011090(*(int *)(iVar3 + 8), iVar4 + 0x14);
              *(undefined1 *)(*(int *)(param_1 + local_50 * 4 + 0x1dc) + 0x10) = 1;
            }
            else {
              FUN_000ba3ac(s_ERROR__AdhocLib__Receiver____ePA_002d5400, local_5c + -0x14,
                           *(int *)(iVar3 + 0xc));
            }
          }
        }
        goto LAB_000bd030;
      }
      if (local_14 == 4) {
        local_4c[0] = 4;
        FUN_00011090(local_4c, *(undefined4 *)(param_1 + 0x180), 0x10);
        bVar1 = 0;
        if (*(int *)(param_1 + 0x280) == local_40) {
          bVar1 = *(int *)(param_1 + 0x27c) == local_44;
        }
        if (bVar1) {
          FUN_000ba3ac(s_game_start_recv_002d53ec);
          *(undefined4 *)(param_1 + 0x194) = *(undefined4 *)(param_1 + 400);
          *(undefined4 *)(param_1 + 400) = 0;
          *(undefined4 *)(param_1 + 0x28) = 0xb;
        }
        goto LAB_000bd030;
      }
      if (local_14 == 3) {
        local_3c[0] = 3;
        FUN_00011090(local_3c, *(undefined4 *)(param_1 + 0x180), 0x14);
        bVar1 = 0;
        if (*(int *)(param_1 + 0x280) == local_30) {
          bVar1 = *(int *)(param_1 + 0x27c) == local_34;
        }
        if (bVar1) {
          *(undefined1 *)(param_1 + local_2c + 0x21c) = 1;
        }
        goto LAB_000bd030;
      }
      if (local_14 != 0) {
        if (*(undefined4 **)(param_1 + 0x270) != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)(param_1 + 0x270))(*(undefined4 *)(param_1 + 0x180), local_10);
        }
        FUN_000ba3ac(s_recv_unknown_packet_002d5440);
        goto LAB_000bd030;
      }
      if (*(int *)(param_1 + 0x28) == 8) {
        break;
      }
      iVar3 = *(int *)(param_1 + 0x26c);
    }
    local_28[0] = 0;
    FUN_00011090(local_28, *(undefined4 *)(param_1 + 0x180), 0x14);
    bVar1 = 0;
    if (*(int *)(param_1 + 0x280) == local_1c) {
      bVar1 = *(int *)(param_1 + 0x27c) == local_20;
    }
    if (bVar1) {
      FUN_000bc99c(param_1, *(undefined4 *)(param_1 + 0x180));
    }
  } while (1);
}
// near miss from lane fm10 (unreviewed)
