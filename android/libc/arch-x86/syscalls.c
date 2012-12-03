/*****************************************************************************
 * syscalls.c: Add syscalls missing from bionic for x86 port.
*****************************************************************************
 *
 * Copyright (C) 2012-2013 The MITRE Corporation
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111, USA.
 *
 *****************************************************************************/


#ifndef SYSCALLS_H_VAM53S7Y
#define SYSCALLS_H_VAM53S7Y

#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>


#define SYS_adjtimex 124
#define SYS_stime 25
#define SYS_swapon 87
#define SYS_swapoff 115
#define SYS_getsid 147
struct timex {
	int modes;           /* mode selector */
	long offset;         /* time offset (usec) */
	long freq;           /* frequency offset (scaled ppm) */
	long maxerror;       /* maximum error (usec) */
	long esterror;       /* estimated error (usec) */
	int status;          /* clock command/status */
	long constant;       /* pll time constant */
	long precision;      /* clock precision (usec) (read-only) */
	long tolerance;      /* clock frequency tolerance (ppm)
				(read-only) */
	struct timeval time; /* current time (read-only) */
	long tick;           /* usecs between clock ticks */
};

int adjtimex(struct timex *txc) {
	    return syscall(SYS_adjtimex, (void *)txc);
}

int stime(time_t *t) {
	    return syscall(SYS_stime, (void *)t);
}

int swapon(const char *a, int i) {
	    return syscall(SYS_swapon, (void *)a, i);
}

int swapoff(const char *a, int i) {
	    return syscall(SYS_swapoff, (void *)a, i);
}


pid_t getsid(pid_t pid) {
	    return syscall(SYS_getsid, pid);
}

#endif /* end of include guard: SYSCALLS_H_VAM53S7Y */
