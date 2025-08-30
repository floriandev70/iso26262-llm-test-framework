//
// Created by Florian Carstens on 24.04.24.
//
/****************************************************************************/
//! Berechnung des Signals PRES_WACOL_TEMP_48V abhänging von den NTCs Flowrate I and U of KL30
//Tinlet = Flow[L/min]* 0.2671+ I_KL30[A]* 0.0037+ I_KL30[A]* -0,0031*V_KL30[V]*0,05 + NTC1_CAN[degC]* 1.053+ NTC2_CAN[degC]* -0.4578 +NTC3_CAN[degC]* -0.6286+ NTC4_CAN[degC]* 0.2951+ NTC5_CAN[degC]* 1.8444+NTC6_CAN[degC]* -2.0185+ NTC7_CAN[degC]* 0.9187 + (-2.573)
/*!
*   \param ntc_temp      Pointer auf Struktur mit allen NTC-, Min- und Max-Temperaturen
*/
/****************************************************************************/

/*PRIVATE s_16 Temp_Calc_Pres_Wacol_Temp_48V (struct dcdc_ntc_temp_def const *ntc_temp)
{
//Flow[L/min]* 0.2671
    flow_rate_result = 1,8 *  0.2671;
//I_KL30[A]* 0.0037
i_kl30_result = ((float)SP_Get_I_Kl30() / 100) *  0.0037;
// I_KL30[A]* -0,0031*V_KL30[V]*0,05
u_i_abs_result = (((float)UTIL_ABS(SP_Get_I_Kl30()) / 100) * -0,0031) * (((float)UTIL_ABS(SP_Get_U_Kl30()) / 1000) * 0,05);
//NTC1_CAN[degC]* 1.053
ntc1_result = ((float)ntc_temp->temp_ntc1 / 10) * 1.053;
//NTC2_CAN[degC]* -0.4578
ntc2_result = ((float)ntc_temp->temp_ntc2 / 10) * -0.4578;
//NTC3_CAN[degC]* -0.6286
ntc3_result = ((float)ntc_temp->temp_ntc3 / 10) * -0.6286;
//NTC4_CAN[degC]* 0.2951
ntc4_result = ((float)ntc_temp->temp_ntc4 / 10) * 0.2951;
//NTC5_CAN[degC]* 1.8444
ntc5_result = ((float)ntc_temp->temp_ntc5 / 10) * 1.8444;
//NTC6_CAN[degC]* -2.0185
ntc6_result = ((float)ntc_temp->temp_ntc6 / 10) * -2.0185;
//NTC7_CAN[degC]* 0.9187
ntc7_result = ((float)ntc_temp->temp_ntc7 / 10) * 0.9187;

algorithm_result = flow_rate_result;
algorithm_result = algorithm_result + i_kl30_result;
algorithm_result = algorithm_result + u_i_abs_result;
algorithm_result = algorithm_result + ntc1_result;
algorithm_result = algorithm_result + ntc2_result;
algorithm_result = algorithm_result + ntc3_result;
algorithm_result = algorithm_result + ntc4_result;
algorithm_result = algorithm_result + ntc5_result;
algorithm_result = algorithm_result + ntc6_result;
algorithm_result = algorithm_result + ntc7_result;
algorithm_result = algorithm_result + (-2.573);

return((s_16)algorithm_result);
*/