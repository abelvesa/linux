/*
 * livepatch.h - arm specific Kernel Live Patching Core
 *
 * Copyright (C) 2017 Abel Vesa <abelvesa@linux.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _ASM_ARM_LIVEPATCH_H
#define _ASM_ARM_LIVEPATCH_H

#include <asm/setup.h>
#include <linux/module.h>
#include <linux/ftrace.h>

static inline void klp_arch_set_pc(struct pt_regs *regs, unsigned long ip)
{
	regs->uregs[15] = ip;
}

static inline int klp_check_compiler_support(void)
{
#ifdef CONFIG_LIVEPATCH
	return 0;
#else
	return 1;
#endif
}

#define klp_get_ftrace_location klp_get_ftrace_location
static inline unsigned long klp_get_ftrace_location(unsigned long faddr)
{
	return ftrace_location_range(faddr, faddr + MCOUNT_CALL_OFFSET_MAX);
}

#endif /* _ASM_ARM_LIVEPATCH_H */
