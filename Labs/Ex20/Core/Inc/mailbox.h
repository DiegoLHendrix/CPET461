/*
 * mailbox.h
 *
 *  Created on: Apr 2, 2024
 *      Author: Diego
 */

#ifndef INC_MAILBOX_H_
#define INC_MAILBOX_H_

#define SYNC1 111
#define SYNC2 222

void InitMailBox(void);
void Post(int syncMessage);
int Pend(void);

#endif /* INC_MAILBOX_H_ */
