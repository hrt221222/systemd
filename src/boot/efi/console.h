/* SPDX-License-Identifier: LGPL-2.1+ */
/*
 * Copyright © 2012-2013 Kay Sievers <kay@vrfy.org>
 * Copyright © 2012 Harald Hoyer <harald@redhat.com>
 */

#ifndef __SDBOOT_CONSOLE_H
#define __SDBOOT_CONSOLE_H

#define EFI_SHIFT_STATE_VALID           0x80000000
#define EFI_RIGHT_CONTROL_PRESSED       0x00000004
#define EFI_LEFT_CONTROL_PRESSED        0x00000008
#define EFI_RIGHT_ALT_PRESSED           0x00000010
#define EFI_LEFT_ALT_PRESSED            0x00000020

#define EFI_CONTROL_PRESSED             (EFI_RIGHT_CONTROL_PRESSED|EFI_LEFT_CONTROL_PRESSED)
#define EFI_ALT_PRESSED                 (EFI_RIGHT_ALT_PRESSED|EFI_LEFT_ALT_PRESSED)
#define KEYPRESS(keys, scan, uni) ((((UINT64)keys) << 32) | ((scan) << 16) | (uni))
#define KEYCHAR(k) ((k) & 0xffff)
#define CHAR_CTRL(c) ((c) - 'a' + 1)

enum console_mode_change_type {
        CONSOLE_MODE_KEEP = 0,
        CONSOLE_MODE_SET,
        CONSOLE_MODE_AUTO,
        CONSOLE_MODE_MAX,
};

EFI_STATUS console_key_read(UINT64 *key, BOOLEAN wait);
EFI_STATUS console_set_mode(UINTN *mode, enum console_mode_change_type how);
#endif
