/* AUTOMATICALLY GENERATED, DO NOT MODIFY */

/*
 * schema-defined QAPI event functions
 *
 * Copyright (c) 2014 Wenchao Xia
 *
 * Authors:
 *  Wenchao Xia  <wenchaoqemu@gmail.com>
 *
 * This work is licensed under the terms of the GNU LGPL, version 2.1 or later.
 * See the COPYING.LIB file in the top-level directory.
 *
 */

#ifndef TEST_QAPI_EVENT_H
#define TEST_QAPI_EVENT_H

#include "qapi/error.h"
#include "qapi/qmp/qdict.h"
#include "test-qapi-types.h"


void qapi_event_send_event_a(Error **errp);

void qapi_event_send_event_b(Error **errp);

void qapi_event_send_event_c(bool has_a,
                             int64_t a,
                             bool has_b,
                             UserDefOne *b,
                             const char *c,
                             Error **errp);

void qapi_event_send_event_d(EventStructOne *a,
                             const char *b,
                             bool has_c,
                             const char *c,
                             bool has_enum3,
                             EnumOne enum3,
                             Error **errp);

void qapi_event_send___org_qemu_x_event(const char *__org_qemu_x_member2,
                                        Error **errp);

extern const char *TEST_QAPIEvent_lookup[];
typedef enum TEST_QAPIEvent
{
    TEST_QAPI_EVENT_EVENT_A = 0,
    TEST_QAPI_EVENT_EVENT_B = 1,
    TEST_QAPI_EVENT_EVENT_C = 2,
    TEST_QAPI_EVENT_EVENT_D = 3,
    TEST_QAPI_EVENT___ORG_QEMU_X_EVENT = 4,
    TEST_QAPI_EVENT_MAX = 5,
} TEST_QAPIEvent;

#endif
