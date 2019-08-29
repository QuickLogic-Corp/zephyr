/*
 * Copyright (c) 2019, Antmicro
 *
 * SPDX-License-Identifier: Apache-2.0
 */

void disable_ecc(void)
{
	__asm__(
		"mrc p15, 0, r0, c1, c0, 1\n\t" /* read ACTLR */
		"bic r0, r0, #0xe000000\n\t"  /* disable ecc */
		"mcr p15, 0, r0, c1, c0, 1\n\t" /* write ACTLR */
	);
}
