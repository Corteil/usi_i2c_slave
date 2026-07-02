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

/*
 * Space Unicorn firmware v2 — buffer-free streaming.
 *
 * The whole 8-bit register space is addressable so the app can reach the
 * user palette (0x20) and the packed index buffer (0x50-0xFF). There is no
 * per-LED RGB frame buffer any more: patterns compute each pixel on the fly
 * as the WS2812 stream is clocked out, so the LED count is limited only by
 * power and frame rate, not by RAM.
 */
#define I2C_N_REG 256
#define I2C_SLAVE_ADDR 0x40

#define I2C_GLOBAL_WRITE_MASK 0xFF

/* ------------------------------------------------------------------ */
/* Register map (firmware v2)                                          */
/* ------------------------------------------------------------------ */

/* Block 0 — control (0x00-0x0A) */
#define REG_CTRL      i2c_reg[0x00]
#define     CTRL_RST      (1 << 0)   /* reset to defaults                */
#define     CTRL_GLB      (1 << 1)   /* solid global colour             */
#define     CTRL_PAT_EN   (1 << 2)   /* run the pattern engine          */
#define     CTRL_IDX_EN   (1 << 3)   /* stream from the index buffer    */
#define     CTRL_SAVE     (1 << 4)   /* persist current state to EEPROM */
#define REG_PATTERN   i2c_reg[0x01]
#define REG_SPEED     i2c_reg[0x02]  /* ticks/frame  1=fast  255=slow   */
#define REG_FALLBACK  i2c_reg[0x03]  /* EEPROM boot / inactivity pattern */
#define REG_N_LEDS_LO i2c_reg[0x04]
#define REG_N_LEDS_HI i2c_reg[0x05]
#define REG_N_COLS    i2c_reg[0x06]  /* matrix columns (0 => 8)         */
#define REG_IDLE_TO   i2c_reg[0x07]  /* inactivity timeout, s (0=off)   */
#define REG_PARAM1    i2c_reg[0x08]
#define REG_PARAM2    i2c_reg[0x09]
#define REG_PAL_SEL   i2c_reg[0x0A]  /* 0=user 16-colour, 1-7=preset    */

/* Block 1 — primary / secondary colours (WS2812 G/R/B wire order) */
#define REG_GLB_G     i2c_reg[0x10]
#define REG_GLB_R     i2c_reg[0x11]
#define REG_GLB_B     i2c_reg[0x12]
#define REG_SEC_G     i2c_reg[0x13]
#define REG_SEC_R     i2c_reg[0x14]
#define REG_SEC_B     i2c_reg[0x15]

/* Block 2 — 16-colour user palette, 16 x (G,R,B) at 0x20-0x4F */
#define PAL_BASE      0x20
#define PAL_ENTRIES   16

/* Block 3 — 4-bit packed index buffer, 0x50-0xFF (176 bytes = 352 LEDs) */
#define IDX_BASE      0x50
#define IDX_BYTES     176

#endif /* __I2C_SLAVE_DEFS__ */
