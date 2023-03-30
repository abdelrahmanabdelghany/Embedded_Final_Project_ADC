/*
 * keypad.h
 *
 *  Created on: May 15, 2022
 *      Author: Abdelrahman Muhsen
 */

#ifndef INCLUDE_KEYPAD_H_
#define INCLUDE_KEYPAD_H_

void KeyPad_INIT(void);
void KeyPad_MANAGE(void);
char KeyPad_GET_VALUE(void);
void KeypadCallouts_KeyPressNotificaton(void);
void sevensegment_init(void);

#endif /* INCLUDE_KEYPAD_H_ */
