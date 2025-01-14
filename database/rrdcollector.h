// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef NETDATA_RRDCOLLECTOR_H
#define NETDATA_RRDCOLLECTOR_H

#include "rrd.h"

#ifdef NETDATA_RRDCOLLECTOR_INTERNALS

// ----------------------------------------------------------------------------
// private API

struct rrd_collector;
struct rrd_collector *rrd_collector_acquire_current_thread(void);
void rrd_collector_release(struct rrd_collector *rdc);
extern __thread struct rrd_collector *thread_rrd_collector;
bool rrd_collector_running(struct rrd_collector *rdc);
pid_t rrd_collector_tid(struct rrd_collector *rdc);
bool rrd_collector_dispatcher_acquire(struct rrd_collector *rdc);
void rrd_collector_dispatcher_release(struct rrd_collector *rdc);

#endif // NETDATA_RRDCOLLECTOR_INTERNALS

// ----------------------------------------------------------------------------
// public API

void rrd_collector_started(void);
void rrd_collector_finished(void);

#endif //NETDATA_RRDCOLLECTOR_H
