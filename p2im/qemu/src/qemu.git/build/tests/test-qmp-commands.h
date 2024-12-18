/* AUTOMATICALLY GENERATED, DO NOT MODIFY */

/*
 * schema-defined QAPI function prototypes
 *
 * Copyright IBM, Corp. 2011
 *
 * Authors:
 *  Anthony Liguori   <aliguori@us.ibm.com>
 *
 * This work is licensed under the terms of the GNU LGPL, version 2.1 or later.
 * See the COPYING.LIB file in the top-level directory.
 *
 */

#ifndef TEST_QMP_COMMANDS_H
#define TEST_QMP_COMMANDS_H

#include "test-qapi-types.h"
#include "qapi/qmp/qdict.h"
#include "qapi/error.h"

void qmp_user_def_cmd(Error **errp);
void qmp_user_def_cmd1(UserDefOne *ud1a, Error **errp);
UserDefTwo *qmp_user_def_cmd2(UserDefOne *ud1a, bool has_ud1b, UserDefOne *ud1b, Error **errp);
int64_t qmp_user_def_cmd3(int64_t a, bool has_b, int64_t b, Error **errp);
__org_qemu_x_Union1 *qmp___org_qemu_x_command(__org_qemu_x_EnumList *a, __org_qemu_x_StructList *b, __org_qemu_x_Union2 *c, __org_qemu_x_Alt *d, Error **errp);

#endif
