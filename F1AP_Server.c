#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <semaphore.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <unistd.h>
#include <signal.h>
#include <limits.h>
#include <poll.h>
#include <sys/epoll.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <error.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <net/if.h> 
#include <resolv.h>

#include "F1AP_18.4_Stack.h"


void F1AP__Handle__F1Setup( uint8_t messageType, SI_F1AP_DT_PDU_F1SetupRequest * oF1SetupRequest, SI_F1APNode * ngNode)
{
	// SI_F1AP_DT_PDU_F1SetupResponse * oF1SetupResponse = (SI_F1AP_DT_PDU_F1SetupResponse *) __si_allocM( sizeof( SI_F1AP_DT_PDU_F1SetupResponse)); 
	// memset( oF1SetupResponse, 0, sizeof( SI_F1AP_DT_PDU_F1SetupResponse));

	// oF1SetupResponse->transactionID = oF1SetupRequest->transactionID;
	// oF1SetupResponse->transactionID_isset = 1;

	// __si_f1ap_init_RRC_Version( &oF1SetupResponse->gNBCURRCVersion);
	// oF1SetupResponse->gNBCURRCVersion_isset = 1;

	// __si_f1ap_init_RRCVersion_latest_RRC_Version2( &oF1SetupResponse->gNBCURRCVersion->latest_RRC_Version, "\xFF", 1, 3);

	// __si_f1ap_send_F1SetupResponse( oF1SetupResponse, ngNode);
	//__si_f1ap_memfree_pdu_F1SetupResponse( oF1SetupResponse);
	// __si_f1ap_memfree_pdu_F1SetupRequest( oF1SetupRequest);
	
	//UN_SUCCESSFUL_OUTCOME_PDU_CHOICE
	
	
	SI_F1AP_DT_PDU_F1SetupFailure * oF1SetupFailure = (SI_F1AP_DT_PDU_F1SetupFailure *) __si_allocM( sizeof( SI_F1AP_DT_PDU_F1SetupFailure)); 
	memset( oF1SetupFailure, 0, sizeof( SI_F1AP_DT_PDU_F1SetupFailure));
	
	oF1SetupFailure->transactionID = oF1SetupRequest->transactionID;
	oF1SetupFailure->transactionID_isset = 1;	
	
	
	__si_f1ap_init_Cause( &oF1SetupFailure->cause);
	oF1SetupFailure->cause->SelectedChoice = 0;
	oF1SetupFailure->cause->u.radioNetwork = __si_f1ap__CauseRadioNetwork_unknown_or_inconsistent_pair_of_ue_f1ap_id_val;//__si_f1ap__CauseRadioNetwork_rl_failure_rlc_val;
	// oF1SetupFailure->cause->SelectedChoice = 1;
	// oF1SetupFailure->cause->u.transport = __si_f1ap__CauseTransport_transport_resource_unavailable_val;
	oF1SetupFailure->cause_isset = 1;

	// ID = id-TimeToWait, PRESENCE = optional L:10238
	oF1SetupFailure->timeToWait = __si_f1ap__TimeToWait_v60s_val;
	oF1SetupFailure->timeToWait_isset = 1;
	
	__si_f1ap_send_F1SetupFailure( oF1SetupFailure, ngNode);
	
	__si_f1ap_memfree_pdu_F1SetupFailure( oF1SetupFailure);
	__si_f1ap_memfree_pdu_F1SetupRequest( oF1SetupRequest);
	
	
	
	
	
}


void F1AP_ReceiveMessage( uint8_t procedureCode, uint8_t messageType, void * msg, SI_F1APNode * ngNode)
{
	switch( procedureCode)
	{
		case __si_f1ap__id_Reset_ProcedureCode:
			break;
		case __si_f1ap__id_F1Setup_ProcedureCode:
			F1AP__Handle__F1Setup( messageType, (SI_F1AP_DT_PDU_F1SetupRequest*)msg, ngNode);
			break;
		case __si_f1ap__id_ErrorIndication_ProcedureCode:
			break;
		case __si_f1ap__id_gNBDUConfigurationUpdate_ProcedureCode:
			break;
		case __si_f1ap__id_gNBCUConfigurationUpdate_ProcedureCode:
			break;
		case __si_f1ap__id_UEContextSetup_ProcedureCode:
			break;
		case __si_f1ap__id_UEContextRelease_ProcedureCode:
			break;
		case __si_f1ap__id_UEContextModification_ProcedureCode:
			break;
		case __si_f1ap__id_UEContextModificationRequired_ProcedureCode:
			break;
		case __si_f1ap__id_procedure_code_9_not_to_be_used_ProcedureCode:
			break;
		case __si_f1ap__id_UEContextReleaseRequest_ProcedureCode:
			break;
		case __si_f1ap__id_InitialULRRCMessageTransfer_ProcedureCode:
			break;
		case __si_f1ap__id_DLRRCMessageTransfer_ProcedureCode:
			break;
		case __si_f1ap__id_ULRRCMessageTransfer_ProcedureCode:
			break;
		case __si_f1ap__id_privateMessage_ProcedureCode:
			break;
		case __si_f1ap__id_UEInactivityNotification_ProcedureCode:
			break;
		case __si_f1ap__id_GNBDUResourceCoordination_ProcedureCode:
			break;
		case __si_f1ap__id_SystemInformationDeliveryCommand_ProcedureCode:
			break;
		case __si_f1ap__id_Paging_ProcedureCode:
			break;
		case __si_f1ap__id_Notify_ProcedureCode:
			break;
		case __si_f1ap__id_WriteReplaceWarning_ProcedureCode:
			break;
		case __si_f1ap__id_PWSCancel_ProcedureCode:
			break;
		case __si_f1ap__id_PWSRestartIndication_ProcedureCode:
			break;
		case __si_f1ap__id_PWSFailureIndication_ProcedureCode:
			break;
		case __si_f1ap__id_GNBDUStatusIndication_ProcedureCode:
			break;
		case __si_f1ap__id_RRCDeliveryReport_ProcedureCode:
			break;
		case __si_f1ap__id_F1Removal_ProcedureCode:
			break;
		case __si_f1ap__id_NetworkAccessRateReduction_ProcedureCode:
			break;
		case __si_f1ap__id_TraceStart_ProcedureCode:
			break;
		case __si_f1ap__id_DeactivateTrace_ProcedureCode:
			break;
		case __si_f1ap__id_DUCURadioInformationTransfer_ProcedureCode:
			break;
		case __si_f1ap__id_CUDURadioInformationTransfer_ProcedureCode:
			break;
		case __si_f1ap__id_BAPMappingConfiguration_ProcedureCode:
			break;
		case __si_f1ap__id_GNBDUResourceConfiguration_ProcedureCode:
			break;
		case __si_f1ap__id_IABTNLAddressAllocation_ProcedureCode:
			break;
		case __si_f1ap__id_IABUPConfigurationUpdate_ProcedureCode:
			break;
		case __si_f1ap__id_resourceStatusReportingInitiation_ProcedureCode:
			break;
		case __si_f1ap__id_resourceStatusReporting_ProcedureCode:
			break;
		case __si_f1ap__id_accessAndMobilityIndication_ProcedureCode:
			break;
		case __si_f1ap__id_accessSuccess_ProcedureCode:
			break;
		case __si_f1ap__id_cellTrafficTrace_ProcedureCode:
			break;
		case __si_f1ap__id_PositioningMeasurementExchange_ProcedureCode:
			break;
		case __si_f1ap__id_PositioningAssistanceInformationControl_ProcedureCode:
			break;
		case __si_f1ap__id_PositioningAssistanceInformationFeedback_ProcedureCode:
			break;
		case __si_f1ap__id_PositioningMeasurementReport_ProcedureCode:
			break;
		case __si_f1ap__id_PositioningMeasurementAbort_ProcedureCode:
			break;
		case __si_f1ap__id_PositioningMeasurementFailureIndication_ProcedureCode:
			break;
		case __si_f1ap__id_PositioningMeasurementUpdate_ProcedureCode:
			break;
		case __si_f1ap__id_TRPInformationExchange_ProcedureCode:
			break;
		case __si_f1ap__id_PositioningInformationExchange_ProcedureCode:
			break;
		case __si_f1ap__id_PositioningActivation_ProcedureCode:
			break;
		case __si_f1ap__id_PositioningDeactivation_ProcedureCode:
			break;
		case __si_f1ap__id_E_CIDMeasurementInitiation_ProcedureCode:
			break;
		case __si_f1ap__id_E_CIDMeasurementFailureIndication_ProcedureCode:
			break;
		case __si_f1ap__id_E_CIDMeasurementReport_ProcedureCode:
			break;
		case __si_f1ap__id_E_CIDMeasurementTermination_ProcedureCode:
			break;
		case __si_f1ap__id_PositioningInformationUpdate_ProcedureCode:
			break;
		case __si_f1ap__id_ReferenceTimeInformationReport_ProcedureCode:
			break;
		case __si_f1ap__id_ReferenceTimeInformationReportingControl_ProcedureCode:
			break;
		case __si_f1ap__id_BroadcastContextSetup_ProcedureCode:
			break;
		case __si_f1ap__id_BroadcastContextRelease_ProcedureCode:
			break;
		case __si_f1ap__id_BroadcastContextReleaseRequest_ProcedureCode:
			break;
		case __si_f1ap__id_BroadcastContextModification_ProcedureCode:
			break;
		case __si_f1ap__id_MulticastGroupPaging_ProcedureCode:
			break;
		case __si_f1ap__id_MulticastContextSetup_ProcedureCode:
			break;
		case __si_f1ap__id_MulticastContextRelease_ProcedureCode:
			break;
		case __si_f1ap__id_MulticastContextReleaseRequest_ProcedureCode:
			break;
		case __si_f1ap__id_MulticastContextModification_ProcedureCode:
			break;
		case __si_f1ap__id_MulticastDistributionSetup_ProcedureCode:
			break;
		case __si_f1ap__id_MulticastDistributionRelease_ProcedureCode:
			break;
		case __si_f1ap__id_PDCMeasurementInitiation_ProcedureCode:
			break;
		case __si_f1ap__id_PDCMeasurementReport_ProcedureCode:
			break;
		case __si_f1ap__id_procedure_code_72_not_to_be_used_ProcedureCode:
			break;
		case __si_f1ap__id_procedure_code_73_not_to_be_used_ProcedureCode:
			break;
		case __si_f1ap__id_procedure_code_74_not_to_be_used_ProcedureCode:
			break;
		case __si_f1ap__id_pRSConfigurationExchange_ProcedureCode:
			break;
		case __si_f1ap__id_measurementPreconfiguration_ProcedureCode:
			break;
		case __si_f1ap__id_measurementActivation_ProcedureCode:
			break;
		case __si_f1ap__id_QoEInformationTransfer_ProcedureCode:
			break;
		case __si_f1ap__id_PDCMeasurementTerminationCommand_ProcedureCode:
			break;
		case __si_f1ap__id_PDCMeasurementFailureIndication_ProcedureCode:
			break;
		case __si_f1ap__id_PosSystemInformationDeliveryCommand_ProcedureCode:
			break;
		case __si_f1ap__id_DUCUCellSwitchNotification_ProcedureCode:
			break;
		case __si_f1ap__id_CUDUCellSwitchNotification_ProcedureCode:
			break;
		case __si_f1ap__id_DUCUTAInformationTransfer_ProcedureCode:
			break;
		case __si_f1ap__id_CUDUTAInformationTransfer_ProcedureCode:
			break;
		case __si_f1ap__id_QoEInformationTransferControl_ProcedureCode:
			break;
		case __si_f1ap__id_RachIndication_ProcedureCode:
			break;
		case __si_f1ap__id_TimingSynchronisationStatus_ProcedureCode:
			break;
		case __si_f1ap__id_TimingSynchronisationStatusReport_ProcedureCode:
			break;
		case __si_f1ap__id_MIABF1SetupTriggering_ProcedureCode:
			break;
		case __si_f1ap__id_MIABF1SetupOutcomeNotification_ProcedureCode:
			break;
		case __si_f1ap__id_MulticastContextNotification_ProcedureCode:
			break;
		case __si_f1ap__id_MulticastCommonConfiguration_ProcedureCode:
			break;
		case __si_f1ap__id_BroadcastTransportResourceRequest_ProcedureCode:
			break;
		case __si_f1ap__id_DUCUAccessAndMobilityIndication_ProcedureCode:
			break;
		case __si_f1ap__id_SRSInformationReservationNotification_ProcedureCode:
			break;
		default:
			__si_log( SI_STK_LOG, 0, SI_LOG_CRITICAL, "Unknown ProcedureCode=%d, dropping request <%s|%s|%d>", procedureCode, __FILE__, __FUNCTION__, __LINE__);
			break;
	}
}

int main( int argc, char* argv[])
{
	printf( "F1AP Server\n");
	F1AP__InitStack( "./f1ap_s_logs/");
	F1AP__SetHost( "192.160.1.3", NULL, 38472);
	F1AP__SetOnMessageRecv( F1AP_ReceiveMessage);
	F1AP__StartStack();



	// cat /proc/net/sctp/eps 
	// lsof -R | grep 
		
	__si_core_wait();
}

