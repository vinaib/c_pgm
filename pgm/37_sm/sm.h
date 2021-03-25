#ifndef __SM_H__
#define __SM_H__

typedef enum __event_idx
{
	RINGON,	
	RINGOFF,
	ANSWER,
	ENDCALL,
	MUTEON,
	MUTEOFF,
	HOLDON,
	HOLDOFF,
	KEY_ANSWER,
	KEY_END,
	KEY_MUTE,
	KEY_UNMUTE,
	NULL_EVENT,
}event_idx;

typedef enum __state_idx
{
	STATE_IDLE,
	STATE_HOLD,
	STATE_RINGING,
	STATE_INCALL,
	STATE_INCALLMUTE,
	STATE_NULL,
}state_idx
	
typedef int (*func)(void);

typedef struct __state 
{
	event_idx	e;
	func		eh;
	state_idx	ns;
}state;

typedef struct __sm
{
	state 
}

#endif /*__SM_H__*/
