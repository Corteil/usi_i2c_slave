/*
 * Copyright Brian Starkey 2014 <stark3y@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __I2C_SLAVE_DEFS__
#define __I2C_SLAVE_DEFS__

/* Set these appropriately for your platform */
#define USI_PORT PORTB
#define USI_DDR DDRB
#define I2C_SDA 0
#define I2C_SCL 2

/* Increase N_LEDS to support 8x8 matrix; I2C_N_GLB_REG expanded for new regs */
#define N_LEDS 64
#define I2C_N_GLB_REG 12
#define I2C_N_REG (I2C_N_GLB_REG + (N_LEDS * 3))
#define I2C_SLAVE_ADDR 0x40

#define I2C_GLOBAL_WRITE_MASK 0xFF

/* Register map */
#define REG_CTRL      i2c_reg[0]
#define     CTRL_RST      (1 << 0)
#define     CTRL_GLB      (1 << 1)
#define     CTRL_PAT_EN   (1 << 2)
#define REG_GLB_G     i2c_reg[1]
#define REG_GLB_R     i2c_reg[2]
#define REG_GLB_B     i2c_reg[3]
#define REG_PATTERN   i2c_reg[4]
#define REG_SPEED     i2c_reg[5]
#define REG_N_LEDS    i2c_reg[6]
#define REG_SEC_G     i2c_reg[7]
#define REG_SEC_R     i2c_reg[8]
#define REG_SEC_B     i2c_reg[9]
#define REG_PARAM1    i2c_reg[10]
#define REG_PAL_SEL   i2c_reg[11]
/* 0x0C+ : LED array, 3 bytes per LED (G, R, B) */

#endif /* __I2C_SLAVE_DEFS__ */
