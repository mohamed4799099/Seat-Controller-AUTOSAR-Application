

#include "Rte_InclineMotor.h"


/**
 *
 * Runnable InclineMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppInclineMotor_Move
 *
 */

void InclineMotor_Move (StepMotorStepType Step)
{

	if(Step == MOTOR_STEP_PLUS)
	{
		(void)Rte_Call_rpIOSetIncline_IOSetForward();
	}
	if(Step == MOTOR_STEP_MINUS)
	{
		(void)Rte_Call_rpIOSetIncline_IOSetReverse();
	}

}

