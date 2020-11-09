

#include "Rte_HMI.h"


static MultiStateBtnType btnValueToState(uint8 value)
{
	MultiStateBtnType btnState;

	if(value == 1)
	{
		btnState = MULTI_STATE_BTN_MINUS;
	}
	if(value == 2)
	{
		btnState = MULTI_STATE_BTN_PLUS;
	}
	else
	{
		btnState = MULTI_STATE_BTN_INIT;
	}

	return btnState;
}




void HMI_MainFunction (void)
{
	Std_ReturnType status;
	MultiStateBtnType HeightBtnState;
	MultiStateBtnType InclineBtnState;
	MultiStateBtnType SlideBtnState;
	uint8 Height;
	uint8 Incline;
	uint8 Slide;
	boolean IsUpdated;

	IsUpdated = Rte_IsUpdated_rpSeatCtrlData_Height();
	status = Rte_Read_rpSeatCtrlData_Height(&Height);
	if(status == RTE_E_OK && IsUpdated == TRUE)
	{
		HeightBtnState = btnValueToState(Height);
		(void)Rte_Write_ppSeatCtrlBtns_HeightBtnState(HeightBtnState);
	}

	IsUpdated = Rte_IsUpdated_rpSeatCtrlData_Incline();
	status = Rte_Read_rpSeatCtrlData_Incline(&Incline);
	if(status == RTE_E_OK && IsUpdated == TRUE)
	{
		InclineBtnState = btnValueToState(Incline);
		(void)Rte_Write_ppSeatCtrlBtns_InclineBtnState(InclineBtnState);
	}

	IsUpdated = Rte_IsUpdated_rpSeatCtrlData_Slide();
	status = Rte_Read_rpSeatCtrlData_Slide(&Slide);
	if(status == RTE_E_OK && IsUpdated == TRUE)
	{
		SlideBtnState = btnValueToState(Slide);
		(void)Rte_Write_ppSeatCtrlBtns_SlideBtnState(SlideBtnState);
	}
}




void HMI_SeatModeChanged (void)
{

	SeatModeBtnType SeatModeBtn;
	uint8 SeatCtrlMode = RTE_MODE_SeatCtrlMode_INIT;

	(void)Rte_Read_rpSeatModeBtn_SeatModeBtn(&SeatModeBtn);

	if(SeatModeBtn == SEAT_MODE_BTN_MANUAL)
	{
		SeatCtrlMode = RTE_MODE_SeatCtrlMode_MANUAL;
	}
	if(SeatModeBtn == SEAT_MODE_BTN_AUTO)
	{
		SeatCtrlMode = RTE_MODE_SeatCtrlMode_AUTO;
	}


	(void)Rte_Switch_ppSeatCtrlMode_SeatCtrlMode(SeatCtrlMode);
}



