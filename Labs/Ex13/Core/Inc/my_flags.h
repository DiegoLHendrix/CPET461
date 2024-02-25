/*
 * my_flags.h
 *
 *  Created on: Feb 23, 2024
 *      Author: diego
 */

#ifndef INC_MY_FLAGS_H_
#define INC_MY_FLAGS_H_

typedef enum {Set, Reset} Flag;

void Set_Flag (int);

void Reset_Flag (int);

Flag Check_Flag(int);

#endif /* INC_MY_FLAGS_H_ */
