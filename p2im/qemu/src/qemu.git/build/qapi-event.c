/* AUTOMATICALLY GENERATED, DO NOT MODIFY */

/*
 * schema-defined QAPI event functions
 *
 * Copyright (c) 2014 Wenchao Xia
 *
 * Authors:
 *  Wenchao Xia   <wenchaoqemu@gmail.com>
 *
 * This work is licensed under the terms of the GNU LGPL, version 2.1 or later.
 * See the COPYING.LIB file in the top-level directory.
 *
 */

#include "qemu-common.h"
#include "qapi-event.h"
#include "qapi-visit.h"
#include "qapi/qmp-output-visitor.h"
#include "qapi/qmp-event.h"


void qapi_event_send_block_image_corrupted(const char *device,
                                           bool has_node_name,
                                           const char *node_name,
                                           const char *msg,
                                           bool has_offset,
                                           int64_t offset,
                                           bool has_size,
                                           int64_t size,
                                           bool fatal,
                                           Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("BLOCK_IMAGE_CORRUPTED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "BLOCK_IMAGE_CORRUPTED", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    visit_type_str(v, (char **)&device, "device", &local_err);
    if (local_err) {
        goto clean;
    }
    if (has_node_name) {
        visit_type_str(v, (char **)&node_name, "node-name", &local_err);
        if (local_err) {
            goto clean;
        }
    }
    visit_type_str(v, (char **)&msg, "msg", &local_err);
    if (local_err) {
        goto clean;
    }
    if (has_offset) {
        visit_type_int(v, &offset, "offset", &local_err);
        if (local_err) {
            goto clean;
        }
    }
    if (has_size) {
        visit_type_int(v, &size, "size", &local_err);
        if (local_err) {
            goto clean;
        }
    }
    visit_type_bool(v, &fatal, "fatal", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_BLOCK_IMAGE_CORRUPTED, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_block_io_error(const char *device,
                                    IoOperationType operation,
                                    BlockErrorAction action,
                                    bool has_nospace,
                                    bool nospace,
                                    const char *reason,
                                    Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("BLOCK_IO_ERROR");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "BLOCK_IO_ERROR", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    visit_type_str(v, (char **)&device, "device", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_IoOperationType(v, &operation, "operation", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_BlockErrorAction(v, &action, "action", &local_err);
    if (local_err) {
        goto clean;
    }
    if (has_nospace) {
        visit_type_bool(v, &nospace, "nospace", &local_err);
        if (local_err) {
            goto clean;
        }
    }
    visit_type_str(v, (char **)&reason, "reason", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_BLOCK_IO_ERROR, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_block_job_completed(BlockJobType type,
                                         const char *device,
                                         int64_t len,
                                         int64_t offset,
                                         int64_t speed,
                                         bool has_error,
                                         const char *error,
                                         Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("BLOCK_JOB_COMPLETED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "BLOCK_JOB_COMPLETED", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    visit_type_BlockJobType(v, &type, "type", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_str(v, (char **)&device, "device", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_int(v, &len, "len", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_int(v, &offset, "offset", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_int(v, &speed, "speed", &local_err);
    if (local_err) {
        goto clean;
    }
    if (has_error) {
        visit_type_str(v, (char **)&error, "error", &local_err);
        if (local_err) {
            goto clean;
        }
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_BLOCK_JOB_COMPLETED, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_block_job_cancelled(BlockJobType type,
                                         const char *device,
                                         int64_t len,
                                         int64_t offset,
                                         int64_t speed,
                                         Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("BLOCK_JOB_CANCELLED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "BLOCK_JOB_CANCELLED", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    visit_type_BlockJobType(v, &type, "type", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_str(v, (char **)&device, "device", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_int(v, &len, "len", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_int(v, &offset, "offset", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_int(v, &speed, "speed", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_BLOCK_JOB_CANCELLED, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_block_job_error(const char *device,
                                     IoOperationType operation,
                                     BlockErrorAction action,
                                     Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("BLOCK_JOB_ERROR");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "BLOCK_JOB_ERROR", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    visit_type_str(v, (char **)&device, "device", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_IoOperationType(v, &operation, "operation", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_BlockErrorAction(v, &action, "action", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_BLOCK_JOB_ERROR, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_block_job_ready(BlockJobType type,
                                     const char *device,
                                     int64_t len,
                                     int64_t offset,
                                     int64_t speed,
                                     Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("BLOCK_JOB_READY");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "BLOCK_JOB_READY", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    visit_type_BlockJobType(v, &type, "type", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_str(v, (char **)&device, "device", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_int(v, &len, "len", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_int(v, &offset, "offset", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_int(v, &speed, "speed", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_BLOCK_JOB_READY, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_block_write_threshold(const char *node_name,
                                           uint64_t amount_exceeded,
                                           uint64_t write_threshold,
                                           Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("BLOCK_WRITE_THRESHOLD");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "BLOCK_WRITE_THRESHOLD", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    visit_type_str(v, (char **)&node_name, "node-name", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_uint64(v, &amount_exceeded, "amount-exceeded", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_uint64(v, &write_threshold, "write-threshold", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_BLOCK_WRITE_THRESHOLD, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_device_tray_moved(const char *device,
                                       bool tray_open,
                                       Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("DEVICE_TRAY_MOVED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "DEVICE_TRAY_MOVED", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    visit_type_str(v, (char **)&device, "device", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_bool(v, &tray_open, "tray-open", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_DEVICE_TRAY_MOVED, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_shutdown(Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("SHUTDOWN");

    emit(QAPI_EVENT_SHUTDOWN, qmp, &local_err);

    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_powerdown(Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("POWERDOWN");

    emit(QAPI_EVENT_POWERDOWN, qmp, &local_err);

    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_reset(Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("RESET");

    emit(QAPI_EVENT_RESET, qmp, &local_err);

    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_stop(Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("STOP");

    emit(QAPI_EVENT_STOP, qmp, &local_err);

    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_resume(Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("RESUME");

    emit(QAPI_EVENT_RESUME, qmp, &local_err);

    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_suspend(Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("SUSPEND");

    emit(QAPI_EVENT_SUSPEND, qmp, &local_err);

    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_suspend_disk(Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("SUSPEND_DISK");

    emit(QAPI_EVENT_SUSPEND_DISK, qmp, &local_err);

    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_wakeup(Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("WAKEUP");

    emit(QAPI_EVENT_WAKEUP, qmp, &local_err);

    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_rtc_change(int64_t offset,
                                Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("RTC_CHANGE");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "RTC_CHANGE", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    visit_type_int(v, &offset, "offset", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_RTC_CHANGE, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_watchdog(WatchdogExpirationAction action,
                              Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("WATCHDOG");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "WATCHDOG", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    visit_type_WatchdogExpirationAction(v, &action, "action", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_WATCHDOG, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_device_deleted(bool has_device,
                                    const char *device,
                                    const char *path,
                                    Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("DEVICE_DELETED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "DEVICE_DELETED", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    if (has_device) {
        visit_type_str(v, (char **)&device, "device", &local_err);
        if (local_err) {
            goto clean;
        }
    }
    visit_type_str(v, (char **)&path, "path", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_DEVICE_DELETED, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_nic_rx_filter_changed(bool has_name,
                                           const char *name,
                                           const char *path,
                                           Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("NIC_RX_FILTER_CHANGED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "NIC_RX_FILTER_CHANGED", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    if (has_name) {
        visit_type_str(v, (char **)&name, "name", &local_err);
        if (local_err) {
            goto clean;
        }
    }
    visit_type_str(v, (char **)&path, "path", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_NIC_RX_FILTER_CHANGED, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_vnc_connected(VncServerInfo *server,
                                   VncBasicInfo *client,
                                   Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("VNC_CONNECTED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "VNC_CONNECTED", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    visit_type_VncServerInfo(v, &server, "server", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_VncBasicInfo(v, &client, "client", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_VNC_CONNECTED, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_vnc_initialized(VncServerInfo *server,
                                     VncClientInfo *client,
                                     Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("VNC_INITIALIZED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "VNC_INITIALIZED", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    visit_type_VncServerInfo(v, &server, "server", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_VncClientInfo(v, &client, "client", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_VNC_INITIALIZED, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_vnc_disconnected(VncServerInfo *server,
                                      VncClientInfo *client,
                                      Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("VNC_DISCONNECTED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "VNC_DISCONNECTED", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    visit_type_VncServerInfo(v, &server, "server", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_VncClientInfo(v, &client, "client", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_VNC_DISCONNECTED, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_spice_connected(SpiceBasicInfo *server,
                                     SpiceBasicInfo *client,
                                     Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("SPICE_CONNECTED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "SPICE_CONNECTED", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    visit_type_SpiceBasicInfo(v, &server, "server", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_SpiceBasicInfo(v, &client, "client", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_SPICE_CONNECTED, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_spice_initialized(SpiceServerInfo *server,
                                       SpiceChannel *client,
                                       Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("SPICE_INITIALIZED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "SPICE_INITIALIZED", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    visit_type_SpiceServerInfo(v, &server, "server", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_SpiceChannel(v, &client, "client", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_SPICE_INITIALIZED, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_spice_disconnected(SpiceBasicInfo *server,
                                        SpiceBasicInfo *client,
                                        Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("SPICE_DISCONNECTED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "SPICE_DISCONNECTED", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    visit_type_SpiceBasicInfo(v, &server, "server", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_SpiceBasicInfo(v, &client, "client", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_SPICE_DISCONNECTED, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_spice_migrate_completed(Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("SPICE_MIGRATE_COMPLETED");

    emit(QAPI_EVENT_SPICE_MIGRATE_COMPLETED, qmp, &local_err);

    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_acpi_device_ost(ACPIOSTInfo *info,
                                     Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("ACPI_DEVICE_OST");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "ACPI_DEVICE_OST", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    visit_type_ACPIOSTInfo(v, &info, "info", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_ACPI_DEVICE_OST, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_balloon_change(int64_t actual,
                                    Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("BALLOON_CHANGE");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "BALLOON_CHANGE", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    visit_type_int(v, &actual, "actual", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_BALLOON_CHANGE, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_guest_panicked(GuestPanicAction action,
                                    Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("GUEST_PANICKED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "GUEST_PANICKED", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    visit_type_GuestPanicAction(v, &action, "action", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_GUEST_PANICKED, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_quorum_failure(const char *reference,
                                    int64_t sector_num,
                                    int64_t sectors_count,
                                    Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("QUORUM_FAILURE");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "QUORUM_FAILURE", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    visit_type_str(v, (char **)&reference, "reference", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_int(v, &sector_num, "sector-num", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_int(v, &sectors_count, "sectors-count", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_QUORUM_FAILURE, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_quorum_report_bad(bool has_error,
                                       const char *error,
                                       const char *node_name,
                                       int64_t sector_num,
                                       int64_t sectors_count,
                                       Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("QUORUM_REPORT_BAD");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "QUORUM_REPORT_BAD", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    if (has_error) {
        visit_type_str(v, (char **)&error, "error", &local_err);
        if (local_err) {
            goto clean;
        }
    }
    visit_type_str(v, (char **)&node_name, "node-name", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_int(v, &sector_num, "sector-num", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_int(v, &sectors_count, "sectors-count", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_QUORUM_REPORT_BAD, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_vserport_change(const char *id,
                                     bool open,
                                     Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("VSERPORT_CHANGE");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "VSERPORT_CHANGE", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    visit_type_str(v, (char **)&id, "id", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_bool(v, &open, "open", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_VSERPORT_CHANGE, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_mem_unplug_error(const char *device,
                                      const char *msg,
                                      Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("MEM_UNPLUG_ERROR");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "MEM_UNPLUG_ERROR", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    visit_type_str(v, (char **)&device, "device", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_str(v, (char **)&msg, "msg", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_MEM_UNPLUG_ERROR, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

const char *QAPIEvent_lookup[] = {
    "BLOCK_IMAGE_CORRUPTED",
    "BLOCK_IO_ERROR",
    "BLOCK_JOB_COMPLETED",
    "BLOCK_JOB_CANCELLED",
    "BLOCK_JOB_ERROR",
    "BLOCK_JOB_READY",
    "BLOCK_WRITE_THRESHOLD",
    "DEVICE_TRAY_MOVED",
    "SHUTDOWN",
    "POWERDOWN",
    "RESET",
    "STOP",
    "RESUME",
    "SUSPEND",
    "SUSPEND_DISK",
    "WAKEUP",
    "RTC_CHANGE",
    "WATCHDOG",
    "DEVICE_DELETED",
    "NIC_RX_FILTER_CHANGED",
    "VNC_CONNECTED",
    "VNC_INITIALIZED",
    "VNC_DISCONNECTED",
    "SPICE_CONNECTED",
    "SPICE_INITIALIZED",
    "SPICE_DISCONNECTED",
    "SPICE_MIGRATE_COMPLETED",
    "ACPI_DEVICE_OST",
    "BALLOON_CHANGE",
    "GUEST_PANICKED",
    "QUORUM_FAILURE",
    "QUORUM_REPORT_BAD",
    "VSERPORT_CHANGE",
    "MEM_UNPLUG_ERROR",
    NULL,
};
