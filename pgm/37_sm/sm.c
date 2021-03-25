#include<stdio.h>
#include"sm.h"

state sidle[] = { 
	{RINGON, ringOnEh, STATE_RINGING},
	{RINGOFF, ringOffEh, STATE_IDLE},
	{ANSWER, hookOnEh, STATE_INCALL},
	{ENDCALL, hookOffEh, STATE_IDLE},
	{HOLDON, holdOnEh, STATE_HOLD},
	{HOLDOFF, holdOffEh, STATE_IDLE},
	{MUTEOFF, muteOffEh, STATE_IDLE},
	{KEY_ANSWER, sendOnHookEh, STATE_INCALL},
	{KEY_}}
