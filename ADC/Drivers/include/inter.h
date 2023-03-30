/*
 * inter.h
 *
 *  Created on: May 29, 2022
 *      Author: Abdelrahman Muhsen
 */

#ifndef INTER_H_
#define INTER_H_
enum port{A,B,C,D,E,l,G,H} ;
enum edge{F,R};
void interruptInit(char interrupt_line , char  port_num, char  edge_type);

#endif /* INTER_H_ */
