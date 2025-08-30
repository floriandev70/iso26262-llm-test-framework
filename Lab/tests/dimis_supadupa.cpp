//
// Created by Florian Carstens on 24.04.24.
//
/****************************************************************************/
//! Berechnung des Signals PRES_WACOL_TEMP_48V abhänging von den NTCs Flowrate I and U of KL30
//Tinlet = Flow[L/min]* 0.2671
//+ I_KL30[A]* 0.0037
//+ I_KL30[A]* -0,0031*V_KL30[V]*0,05
//+ NTC1_CAN[degC]* 1.053
//+ NTC2_CAN[degC]* -0.4578
//+NTC3_CAN[degC]* -0.6286
//+ NTC4_CAN[degC]* 0.2951
//+ NTC5_CAN[degC]* 1.8444
//+NTC6_CAN[degC]* -2.0185
//+ NTC7_CAN[degC]* 0.9187
//+ (-2.573)
/*!
*   \param ntc_temp      Pointer auf Struktur mit allen NTC-, Min- und Max-Temperaturen
*/
/****************************************************************************/

/*PRIVATE s_16 Temp_Calc_Pres_Wacol_Temp_48V (struct dcdc_ntc_temp_def const *ntc_temp)
{
    float parameter = 0; //Parameter der mit factor versehen werden soll
    float factor = 0; //Parameterfactor
    float interim_result = 0; // Ergebnis der Berechnung Parameter * Parameterfactor
    float flow_rate_result = 0; //Flow[L/min]* 0.2671
    float i_kl30_result = 0; //I_KL30[A]* 0.0037
    float i_kl30_abs_result = 0; //I_KL30[A]* -0,0031
    float u_kl30_abs_result = 0; //V_KL30[V]*0,05
    float u_i_abs_result = 0; //I_KL30[A]* -0,0031*V_KL30[V]*0,05
    float ntc1_result = 0;
    float ntc2_result = 0;
    float ntc3_result = 0;
    float ntc4_result = 0;
    float ntc5_result = 0;
    float ntc6_result = 0;
    float ntc7_result = 0;
    float correction_factor = -2573; // -2.573 * 1000
    float algorithm_result = 0;

    //Flow[L/min]* 0.2671
    parameter = (float)18; //in 10L/min -> 1,8L/min
    factor = (float)2671; //0,2671 * 10000
    interim_result = (interim_result) * (factor / (float)10000);
    flow_rate_result = interim_result;

    //I_KL30[A]* 0.0037
    parameter = (float)SP_Get_I_Kl30(); //in 10mA
    factor = (float)37; //0,0037 * 10000
    interim_result = parameter * (float)100; //10mA -> A
    interim_result = (interim_result) * (factor / (float)10000);
    i_kl30_result = interim_result;

    //I_KL30[A]* -0,0031
    parameter = (float)UTIL_ABS(SP_Get_I_Kl30()); //in 10mA
    factor = (float)-31; //-0,0031 * 10000
    interim_result = parameter * (float)100; //10mA -> A
    interim_result = (interim_result) * (factor / (float)10000);
    i_kl30_abs_result = interim_result;

    //V_KL30[V]*0,05
    parameter = (float)UTIL_ABS(SP_Get_U_Kl30()); //in mV
    factor = (float)5; //0,05 * 100
    interim_result = parameter * (float)1000; //mV -> V
    interim_result = (interim_result) * (factor / (float)100);
    u_kl30_abs_result = interim_result;

    u_i_abs_result = i_kl30_abs_result * u_kl30_abs_result;

    //NTC1_CAN[degC]* 1.053
    parameter = (float)ntc_temp->temp_ntc1; //in 0,1°C
    factor = (float)1053; //1,053 * 1000
    interim_result = parameter * (float)1000; //mV -> V
    interim_result = (interim_result) * (factor / (float)1000);
    ntc1_result = interim_result;

    //NTC2_CAN[degC]* -0.4578
    parameter = (float)ntc_temp->temp_ntc2; //in 0,1°C
    factor = (float)-4578; //-0.4578 * 10000
    interim_result = parameter * (float)1000; //mV -> V
    interim_result = (interim_result) * (factor / (float)10000);
    ntc2_result = interim_result;

    //NTC3_CAN[degC]* -0.6286
    parameter = (float)ntc_temp->temp_ntc3; //in 0,1°C
    factor = (float)-6286; //-0.6286 * 10000
    interim_result = parameter * (float)1000; //mV -> V
    interim_result = (interim_result) * (factor / 10000);
    ntc3_result = interim_result;

    //NTC4_CAN[degC]* 0.2951
    parameter = (float)ntc_temp->temp_ntc4; //in 0,1°C
    factor = (float)2951; //0.2951 * 10000
    interim_result = parameter * (float)1000; //mV -> V
    interim_result = (interim_result) * (factor / (float)10000);
    ntc4_result = interim_result;

    //NTC5_CAN[degC]* 1.8444
    parameter = (float)ntc_temp->temp_ntc5; //in 0,1°C
    factor = (float)18444; //1.8444 * 10000
    interim_result = parameter * (float)1000; //mV -> V
    interim_result = (interim_result) * (factor / (float)10000);
    ntc5_result = interim_result;

    //NTC6_CAN[degC]* -2.0185
    parameter = (float)ntc_temp->temp_ntc6; //in 0,1°C
    factor = (float)-20185; //-2.0185 * 10000
    interim_result = parameter * (float)1000; //mV -> V
    interim_result = (interim_result) * (factor / (float)10000);
    ntc6_result = interim_result;

    //NTC7_CAN[degC]* 0.9187
    parameter = (float)ntc_temp->temp_ntc7; //in 0,1°C
    factor = (float)9187; //0.9187 * 10000
    interim_result = parameter * (float)1000; //mV -> V
    interim_result = (interim_result) * (factor / (float)10000);
    ntc7_result = interim_result;


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
    algorithm_result = (algorithm_result + (correction_factor / 1000)) * 10; //in 0,1°C

    return((s_16)algorithm_result);
}*/