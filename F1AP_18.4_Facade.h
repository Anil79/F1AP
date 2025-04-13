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

#include "sirik_core.h"
#include "libAsn.h"
#include "F1AP_18.4.h"

#ifndef SIRIK_F1AP_H
#define SIRIK_F1AP_H

#pragma pack(4)
typedef struct __si_f1ap_node
{
	SI_Socket * siSocket;
	//SI_RAN_Client * RANClient;
	int NodeType;
	uint8_t * transportEng;
	
} SI_F1APNode;


typedef void (*fp_f1ap_on_message)( uint8_t procedureCode, uint8_t messageType, void * msg, SI_F1APNode * ngNode);

void 	__si_f1ap_handle_message( SI_F1APNode * s1apNode, SI_SocketSCTPBuffer * sctpBuffer);

int 	__si_f1ap_sendmsg( uint8_t * buffer, uint32_t len, SI_F1APNode * ngNode);
void 	__si_f1ap_app_message_handler( uint8_t procedureCode, uint8_t messageType, void * msg, SI_F1APNode * ngNode);
void 	__si_f1ap_set_app_message_handler( fp_f1ap_on_message handler);

//int 	__si_f1ap_transport__init( ASNTransport_t * f1ap_ASNTransport);


int __si_f1ap_send_Reset( SI_F1AP_DT_PDU_Reset * objReset, SI_F1APNode * f1apNode);
int __si_f1ap_send_ResetAcknowledge( SI_F1AP_DT_PDU_ResetAcknowledge * objResetAcknowledge, SI_F1APNode * f1apNode);
int __si_f1ap_send_F1SetupRequest( SI_F1AP_DT_PDU_F1SetupRequest * objF1SetupRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_F1SetupResponse( SI_F1AP_DT_PDU_F1SetupResponse * objF1SetupResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_F1SetupFailure( SI_F1AP_DT_PDU_F1SetupFailure * objF1SetupFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_GNBDUConfigurationUpdate( SI_F1AP_DT_PDU_GNBDUConfigurationUpdate * objGNBDUConfigurationUpdate, SI_F1APNode * f1apNode);
int __si_f1ap_send_GNBDUConfigurationUpdateAcknowledge( SI_F1AP_DT_PDU_GNBDUConfigurationUpdateAcknowledge * objGNBDUConfigurationUpdateAcknowledge, SI_F1APNode * f1apNode);
int __si_f1ap_send_GNBDUConfigurationUpdateFailure( SI_F1AP_DT_PDU_GNBDUConfigurationUpdateFailure * objGNBDUConfigurationUpdateFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_GNBCUConfigurationUpdate( SI_F1AP_DT_PDU_GNBCUConfigurationUpdate * objGNBCUConfigurationUpdate, SI_F1APNode * f1apNode);
int __si_f1ap_send_GNBCUConfigurationUpdateAcknowledge( SI_F1AP_DT_PDU_GNBCUConfigurationUpdateAcknowledge * objGNBCUConfigurationUpdateAcknowledge, SI_F1APNode * f1apNode);
int __si_f1ap_send_GNBCUConfigurationUpdateFailure( SI_F1AP_DT_PDU_GNBCUConfigurationUpdateFailure * objGNBCUConfigurationUpdateFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_UEContextSetupRequest( SI_F1AP_DT_PDU_UEContextSetupRequest * objUEContextSetupRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_UEContextSetupResponse( SI_F1AP_DT_PDU_UEContextSetupResponse * objUEContextSetupResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_UEContextSetupFailure( SI_F1AP_DT_PDU_UEContextSetupFailure * objUEContextSetupFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_UEContextReleaseCommand( SI_F1AP_DT_PDU_UEContextReleaseCommand * objUEContextReleaseCommand, SI_F1APNode * f1apNode);
int __si_f1ap_send_UEContextReleaseComplete( SI_F1AP_DT_PDU_UEContextReleaseComplete * objUEContextReleaseComplete, SI_F1APNode * f1apNode);
int __si_f1ap_send_UEContextModificationRequest( SI_F1AP_DT_PDU_UEContextModificationRequest * objUEContextModificationRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_UEContextModificationResponse( SI_F1AP_DT_PDU_UEContextModificationResponse * objUEContextModificationResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_UEContextModificationFailure( SI_F1AP_DT_PDU_UEContextModificationFailure * objUEContextModificationFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_UEContextModificationRequired( SI_F1AP_DT_PDU_UEContextModificationRequired * objUEContextModificationRequired, SI_F1APNode * f1apNode);
int __si_f1ap_send_UEContextModificationConfirm( SI_F1AP_DT_PDU_UEContextModificationConfirm * objUEContextModificationConfirm, SI_F1APNode * f1apNode);
int __si_f1ap_send_UEContextModificationRefuse( SI_F1AP_DT_PDU_UEContextModificationRefuse * objUEContextModificationRefuse, SI_F1APNode * f1apNode);
int __si_f1ap_send_WriteReplaceWarningRequest( SI_F1AP_DT_PDU_WriteReplaceWarningRequest * objWriteReplaceWarningRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_WriteReplaceWarningResponse( SI_F1AP_DT_PDU_WriteReplaceWarningResponse * objWriteReplaceWarningResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_PWSCancelRequest( SI_F1AP_DT_PDU_PWSCancelRequest * objPWSCancelRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_PWSCancelResponse( SI_F1AP_DT_PDU_PWSCancelResponse * objPWSCancelResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_ErrorIndication( SI_F1AP_DT_PDU_ErrorIndication * objErrorIndication, SI_F1APNode * f1apNode);
int __si_f1ap_send_UEContextReleaseRequest( SI_F1AP_DT_PDU_UEContextReleaseRequest * objUEContextReleaseRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_InitialULRRCMessageTransfer( SI_F1AP_DT_PDU_InitialULRRCMessageTransfer * objInitialULRRCMessageTransfer, SI_F1APNode * f1apNode);
int __si_f1ap_send_DLRRCMessageTransfer( SI_F1AP_DT_PDU_DLRRCMessageTransfer * objDLRRCMessageTransfer, SI_F1APNode * f1apNode);
int __si_f1ap_send_ULRRCMessageTransfer( SI_F1AP_DT_PDU_ULRRCMessageTransfer * objULRRCMessageTransfer, SI_F1APNode * f1apNode);
int __si_f1ap_send_UEInactivityNotification( SI_F1AP_DT_PDU_UEInactivityNotification * objUEInactivityNotification, SI_F1APNode * f1apNode);
int __si_f1ap_send_GNBDUResourceCoordinationRequest( SI_F1AP_DT_PDU_GNBDUResourceCoordinationRequest * objGNBDUResourceCoordinationRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_GNBDUResourceCoordinationResponse( SI_F1AP_DT_PDU_GNBDUResourceCoordinationResponse * objGNBDUResourceCoordinationResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_PrivateMessage( SI_F1AP_DT_PDU_PrivateMessage * objPrivateMessage, SI_F1APNode * f1apNode);
int __si_f1ap_send_SystemInformationDeliveryCommand( SI_F1AP_DT_PDU_SystemInformationDeliveryCommand * objSystemInformationDeliveryCommand, SI_F1APNode * f1apNode);
int __si_f1ap_send_Paging( SI_F1AP_DT_PDU_Paging * objPaging, SI_F1APNode * f1apNode);
int __si_f1ap_send_Notify( SI_F1AP_DT_PDU_Notify * objNotify, SI_F1APNode * f1apNode);
int __si_f1ap_send_NetworkAccessRateReduction( SI_F1AP_DT_PDU_NetworkAccessRateReduction * objNetworkAccessRateReduction, SI_F1APNode * f1apNode);
int __si_f1ap_send_PWSRestartIndication( SI_F1AP_DT_PDU_PWSRestartIndication * objPWSRestartIndication, SI_F1APNode * f1apNode);
int __si_f1ap_send_PWSFailureIndication( SI_F1AP_DT_PDU_PWSFailureIndication * objPWSFailureIndication, SI_F1APNode * f1apNode);
int __si_f1ap_send_GNBDUStatusIndication( SI_F1AP_DT_PDU_GNBDUStatusIndication * objGNBDUStatusIndication, SI_F1APNode * f1apNode);
int __si_f1ap_send_RRCDeliveryReport( SI_F1AP_DT_PDU_RRCDeliveryReport * objRRCDeliveryReport, SI_F1APNode * f1apNode);
int __si_f1ap_send_F1RemovalRequest( SI_F1AP_DT_PDU_F1RemovalRequest * objF1RemovalRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_F1RemovalResponse( SI_F1AP_DT_PDU_F1RemovalResponse * objF1RemovalResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_F1RemovalFailure( SI_F1AP_DT_PDU_F1RemovalFailure * objF1RemovalFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_TraceStart( SI_F1AP_DT_PDU_TraceStart * objTraceStart, SI_F1APNode * f1apNode);
int __si_f1ap_send_DeactivateTrace( SI_F1AP_DT_PDU_DeactivateTrace * objDeactivateTrace, SI_F1APNode * f1apNode);
int __si_f1ap_send_DUCURadioInformationTransfer( SI_F1AP_DT_PDU_DUCURadioInformationTransfer * objDUCURadioInformationTransfer, SI_F1APNode * f1apNode);
int __si_f1ap_send_CUDURadioInformationTransfer( SI_F1AP_DT_PDU_CUDURadioInformationTransfer * objCUDURadioInformationTransfer, SI_F1APNode * f1apNode);
int __si_f1ap_send_BAPMappingConfiguration( SI_F1AP_DT_PDU_BAPMappingConfiguration * objBAPMappingConfiguration, SI_F1APNode * f1apNode);
int __si_f1ap_send_BAPMappingConfigurationAcknowledge( SI_F1AP_DT_PDU_BAPMappingConfigurationAcknowledge * objBAPMappingConfigurationAcknowledge, SI_F1APNode * f1apNode);
int __si_f1ap_send_BAPMappingConfigurationFailure( SI_F1AP_DT_PDU_BAPMappingConfigurationFailure * objBAPMappingConfigurationFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_GNBDUResourceConfiguration( SI_F1AP_DT_PDU_GNBDUResourceConfiguration * objGNBDUResourceConfiguration, SI_F1APNode * f1apNode);
int __si_f1ap_send_GNBDUResourceConfigurationAcknowledge( SI_F1AP_DT_PDU_GNBDUResourceConfigurationAcknowledge * objGNBDUResourceConfigurationAcknowledge, SI_F1APNode * f1apNode);
int __si_f1ap_send_GNBDUResourceConfigurationFailure( SI_F1AP_DT_PDU_GNBDUResourceConfigurationFailure * objGNBDUResourceConfigurationFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_IABTNLAddressRequest( SI_F1AP_DT_PDU_IABTNLAddressRequest * objIABTNLAddressRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_IABTNLAddressResponse( SI_F1AP_DT_PDU_IABTNLAddressResponse * objIABTNLAddressResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_IABTNLAddressFailure( SI_F1AP_DT_PDU_IABTNLAddressFailure * objIABTNLAddressFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_IABUPConfigurationUpdateRequest( SI_F1AP_DT_PDU_IABUPConfigurationUpdateRequest * objIABUPConfigurationUpdateRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_IABUPConfigurationUpdateResponse( SI_F1AP_DT_PDU_IABUPConfigurationUpdateResponse * objIABUPConfigurationUpdateResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_IABUPConfigurationUpdateFailure( SI_F1AP_DT_PDU_IABUPConfigurationUpdateFailure * objIABUPConfigurationUpdateFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_ResourceStatusRequest( SI_F1AP_DT_PDU_ResourceStatusRequest * objResourceStatusRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_ResourceStatusResponse( SI_F1AP_DT_PDU_ResourceStatusResponse * objResourceStatusResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_ResourceStatusFailure( SI_F1AP_DT_PDU_ResourceStatusFailure * objResourceStatusFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_ResourceStatusUpdate( SI_F1AP_DT_PDU_ResourceStatusUpdate * objResourceStatusUpdate, SI_F1APNode * f1apNode);
int __si_f1ap_send_AccessAndMobilityIndication( SI_F1AP_DT_PDU_AccessAndMobilityIndication * objAccessAndMobilityIndication, SI_F1APNode * f1apNode);
int __si_f1ap_send_ReferenceTimeInformationReportingControl( SI_F1AP_DT_PDU_ReferenceTimeInformationReportingControl * objReferenceTimeInformationReportingControl, SI_F1APNode * f1apNode);
int __si_f1ap_send_ReferenceTimeInformationReport( SI_F1AP_DT_PDU_ReferenceTimeInformationReport * objReferenceTimeInformationReport, SI_F1APNode * f1apNode);
int __si_f1ap_send_AccessSuccess( SI_F1AP_DT_PDU_AccessSuccess * objAccessSuccess, SI_F1APNode * f1apNode);
int __si_f1ap_send_CellTrafficTrace( SI_F1AP_DT_PDU_CellTrafficTrace * objCellTrafficTrace, SI_F1APNode * f1apNode);
int __si_f1ap_send_PositioningAssistanceInformationControl( SI_F1AP_DT_PDU_PositioningAssistanceInformationControl * objPositioningAssistanceInformationControl, SI_F1APNode * f1apNode);
int __si_f1ap_send_PositioningAssistanceInformationFeedback( SI_F1AP_DT_PDU_PositioningAssistanceInformationFeedback * objPositioningAssistanceInformationFeedback, SI_F1APNode * f1apNode);
int __si_f1ap_send_PositioningMeasurementRequest( SI_F1AP_DT_PDU_PositioningMeasurementRequest * objPositioningMeasurementRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_PositioningMeasurementResponse( SI_F1AP_DT_PDU_PositioningMeasurementResponse * objPositioningMeasurementResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_PositioningMeasurementFailure( SI_F1AP_DT_PDU_PositioningMeasurementFailure * objPositioningMeasurementFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_PositioningMeasurementReport( SI_F1AP_DT_PDU_PositioningMeasurementReport * objPositioningMeasurementReport, SI_F1APNode * f1apNode);
int __si_f1ap_send_PositioningMeasurementAbort( SI_F1AP_DT_PDU_PositioningMeasurementAbort * objPositioningMeasurementAbort, SI_F1APNode * f1apNode);
int __si_f1ap_send_PositioningMeasurementFailureIndication( SI_F1AP_DT_PDU_PositioningMeasurementFailureIndication * objPositioningMeasurementFailureIndication, SI_F1APNode * f1apNode);
int __si_f1ap_send_PositioningMeasurementUpdate( SI_F1AP_DT_PDU_PositioningMeasurementUpdate * objPositioningMeasurementUpdate, SI_F1APNode * f1apNode);
int __si_f1ap_send_TRPInformationRequest( SI_F1AP_DT_PDU_TRPInformationRequest * objTRPInformationRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_TRPInformationResponse( SI_F1AP_DT_PDU_TRPInformationResponse * objTRPInformationResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_TRPInformationFailure( SI_F1AP_DT_PDU_TRPInformationFailure * objTRPInformationFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_PositioningInformationRequest( SI_F1AP_DT_PDU_PositioningInformationRequest * objPositioningInformationRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_PositioningInformationResponse( SI_F1AP_DT_PDU_PositioningInformationResponse * objPositioningInformationResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_PositioningInformationFailure( SI_F1AP_DT_PDU_PositioningInformationFailure * objPositioningInformationFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_PositioningActivationRequest( SI_F1AP_DT_PDU_PositioningActivationRequest * objPositioningActivationRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_PositioningActivationResponse( SI_F1AP_DT_PDU_PositioningActivationResponse * objPositioningActivationResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_PositioningActivationFailure( SI_F1AP_DT_PDU_PositioningActivationFailure * objPositioningActivationFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_PositioningDeactivation( SI_F1AP_DT_PDU_PositioningDeactivation * objPositioningDeactivation, SI_F1APNode * f1apNode);
int __si_f1ap_send_E_CIDMeasurementInitiationRequest( SI_F1AP_DT_PDU_E_CIDMeasurementInitiationRequest * objE_CIDMeasurementInitiationRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_E_CIDMeasurementInitiationResponse( SI_F1AP_DT_PDU_E_CIDMeasurementInitiationResponse * objE_CIDMeasurementInitiationResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_E_CIDMeasurementInitiationFailure( SI_F1AP_DT_PDU_E_CIDMeasurementInitiationFailure * objE_CIDMeasurementInitiationFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_E_CIDMeasurementFailureIndication( SI_F1AP_DT_PDU_E_CIDMeasurementFailureIndication * objE_CIDMeasurementFailureIndication, SI_F1APNode * f1apNode);
int __si_f1ap_send_E_CIDMeasurementReport( SI_F1AP_DT_PDU_E_CIDMeasurementReport * objE_CIDMeasurementReport, SI_F1APNode * f1apNode);
int __si_f1ap_send_E_CIDMeasurementTerminationCommand( SI_F1AP_DT_PDU_E_CIDMeasurementTerminationCommand * objE_CIDMeasurementTerminationCommand, SI_F1APNode * f1apNode);
int __si_f1ap_send_PositioningInformationUpdate( SI_F1AP_DT_PDU_PositioningInformationUpdate * objPositioningInformationUpdate, SI_F1APNode * f1apNode);
int __si_f1ap_send_BroadcastContextSetupRequest( SI_F1AP_DT_PDU_BroadcastContextSetupRequest * objBroadcastContextSetupRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_BroadcastContextSetupResponse( SI_F1AP_DT_PDU_BroadcastContextSetupResponse * objBroadcastContextSetupResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_BroadcastContextSetupFailure( SI_F1AP_DT_PDU_BroadcastContextSetupFailure * objBroadcastContextSetupFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_BroadcastContextReleaseCommand( SI_F1AP_DT_PDU_BroadcastContextReleaseCommand * objBroadcastContextReleaseCommand, SI_F1APNode * f1apNode);
int __si_f1ap_send_BroadcastContextReleaseComplete( SI_F1AP_DT_PDU_BroadcastContextReleaseComplete * objBroadcastContextReleaseComplete, SI_F1APNode * f1apNode);
int __si_f1ap_send_BroadcastContextReleaseRequest( SI_F1AP_DT_PDU_BroadcastContextReleaseRequest * objBroadcastContextReleaseRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_BroadcastContextModificationRequest( SI_F1AP_DT_PDU_BroadcastContextModificationRequest * objBroadcastContextModificationRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_BroadcastContextModificationResponse( SI_F1AP_DT_PDU_BroadcastContextModificationResponse * objBroadcastContextModificationResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_BroadcastContextModificationFailure( SI_F1AP_DT_PDU_BroadcastContextModificationFailure * objBroadcastContextModificationFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_MulticastGroupPaging( SI_F1AP_DT_PDU_MulticastGroupPaging * objMulticastGroupPaging, SI_F1APNode * f1apNode);
int __si_f1ap_send_MulticastContextSetupRequest( SI_F1AP_DT_PDU_MulticastContextSetupRequest * objMulticastContextSetupRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_MulticastContextSetupResponse( SI_F1AP_DT_PDU_MulticastContextSetupResponse * objMulticastContextSetupResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_MulticastContextSetupFailure( SI_F1AP_DT_PDU_MulticastContextSetupFailure * objMulticastContextSetupFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_MulticastContextReleaseCommand( SI_F1AP_DT_PDU_MulticastContextReleaseCommand * objMulticastContextReleaseCommand, SI_F1APNode * f1apNode);
int __si_f1ap_send_MulticastContextReleaseComplete( SI_F1AP_DT_PDU_MulticastContextReleaseComplete * objMulticastContextReleaseComplete, SI_F1APNode * f1apNode);
int __si_f1ap_send_MulticastContextReleaseRequest( SI_F1AP_DT_PDU_MulticastContextReleaseRequest * objMulticastContextReleaseRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_MulticastContextModificationRequest( SI_F1AP_DT_PDU_MulticastContextModificationRequest * objMulticastContextModificationRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_MulticastContextModificationResponse( SI_F1AP_DT_PDU_MulticastContextModificationResponse * objMulticastContextModificationResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_MulticastContextModificationFailure( SI_F1AP_DT_PDU_MulticastContextModificationFailure * objMulticastContextModificationFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_MulticastDistributionSetupRequest( SI_F1AP_DT_PDU_MulticastDistributionSetupRequest * objMulticastDistributionSetupRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_MulticastDistributionSetupResponse( SI_F1AP_DT_PDU_MulticastDistributionSetupResponse * objMulticastDistributionSetupResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_MulticastDistributionSetupFailure( SI_F1AP_DT_PDU_MulticastDistributionSetupFailure * objMulticastDistributionSetupFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_MulticastDistributionReleaseCommand( SI_F1AP_DT_PDU_MulticastDistributionReleaseCommand * objMulticastDistributionReleaseCommand, SI_F1APNode * f1apNode);
int __si_f1ap_send_MulticastDistributionReleaseComplete( SI_F1AP_DT_PDU_MulticastDistributionReleaseComplete * objMulticastDistributionReleaseComplete, SI_F1APNode * f1apNode);
int __si_f1ap_send_PDCMeasurementInitiationRequest( SI_F1AP_DT_PDU_PDCMeasurementInitiationRequest * objPDCMeasurementInitiationRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_PDCMeasurementInitiationResponse( SI_F1AP_DT_PDU_PDCMeasurementInitiationResponse * objPDCMeasurementInitiationResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_PDCMeasurementInitiationFailure( SI_F1AP_DT_PDU_PDCMeasurementInitiationFailure * objPDCMeasurementInitiationFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_PDCMeasurementReport( SI_F1AP_DT_PDU_PDCMeasurementReport * objPDCMeasurementReport, SI_F1APNode * f1apNode);
int __si_f1ap_send_PDCMeasurementTerminationCommand( SI_F1AP_DT_PDU_PDCMeasurementTerminationCommand * objPDCMeasurementTerminationCommand, SI_F1APNode * f1apNode);
int __si_f1ap_send_PDCMeasurementFailureIndication( SI_F1AP_DT_PDU_PDCMeasurementFailureIndication * objPDCMeasurementFailureIndication, SI_F1APNode * f1apNode);
int __si_f1ap_send_PRSConfigurationRequest( SI_F1AP_DT_PDU_PRSConfigurationRequest * objPRSConfigurationRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_PRSConfigurationResponse( SI_F1AP_DT_PDU_PRSConfigurationResponse * objPRSConfigurationResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_PRSConfigurationFailure( SI_F1AP_DT_PDU_PRSConfigurationFailure * objPRSConfigurationFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_MeasurementPreconfigurationRequired( SI_F1AP_DT_PDU_MeasurementPreconfigurationRequired * objMeasurementPreconfigurationRequired, SI_F1APNode * f1apNode);
int __si_f1ap_send_MeasurementPreconfigurationConfirm( SI_F1AP_DT_PDU_MeasurementPreconfigurationConfirm * objMeasurementPreconfigurationConfirm, SI_F1APNode * f1apNode);
int __si_f1ap_send_MeasurementPreconfigurationRefuse( SI_F1AP_DT_PDU_MeasurementPreconfigurationRefuse * objMeasurementPreconfigurationRefuse, SI_F1APNode * f1apNode);
int __si_f1ap_send_MeasurementActivation( SI_F1AP_DT_PDU_MeasurementActivation * objMeasurementActivation, SI_F1APNode * f1apNode);
int __si_f1ap_send_QoEInformationTransfer( SI_F1AP_DT_PDU_QoEInformationTransfer * objQoEInformationTransfer, SI_F1APNode * f1apNode);
int __si_f1ap_send_PosSystemInformationDeliveryCommand( SI_F1AP_DT_PDU_PosSystemInformationDeliveryCommand * objPosSystemInformationDeliveryCommand, SI_F1APNode * f1apNode);
int __si_f1ap_send_DUCUCellSwitchNotification( SI_F1AP_DT_PDU_DUCUCellSwitchNotification * objDUCUCellSwitchNotification, SI_F1APNode * f1apNode);
int __si_f1ap_send_CUDUCellSwitchNotification( SI_F1AP_DT_PDU_CUDUCellSwitchNotification * objCUDUCellSwitchNotification, SI_F1APNode * f1apNode);
int __si_f1ap_send_DUCUTAInformationTransfer( SI_F1AP_DT_PDU_DUCUTAInformationTransfer * objDUCUTAInformationTransfer, SI_F1APNode * f1apNode);
int __si_f1ap_send_CUDUTAInformationTransfer( SI_F1AP_DT_PDU_CUDUTAInformationTransfer * objCUDUTAInformationTransfer, SI_F1APNode * f1apNode);
int __si_f1ap_send_QoEInformationTransferControl( SI_F1AP_DT_PDU_QoEInformationTransferControl * objQoEInformationTransferControl, SI_F1APNode * f1apNode);
int __si_f1ap_send_RachIndication( SI_F1AP_DT_PDU_RachIndication * objRachIndication, SI_F1APNode * f1apNode);
int __si_f1ap_send_TimingSynchronisationStatusRequest( SI_F1AP_DT_PDU_TimingSynchronisationStatusRequest * objTimingSynchronisationStatusRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_TimingSynchronisationStatusResponse( SI_F1AP_DT_PDU_TimingSynchronisationStatusResponse * objTimingSynchronisationStatusResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_TimingSynchronisationStatusFailure( SI_F1AP_DT_PDU_TimingSynchronisationStatusFailure * objTimingSynchronisationStatusFailure, SI_F1APNode * f1apNode);
int __si_f1ap_send_TimingSynchronisationStatusReport( SI_F1AP_DT_PDU_TimingSynchronisationStatusReport * objTimingSynchronisationStatusReport, SI_F1APNode * f1apNode);
int __si_f1ap_send_MIABF1SetupTriggering( SI_F1AP_DT_PDU_MIABF1SetupTriggering * objMIABF1SetupTriggering, SI_F1APNode * f1apNode);
int __si_f1ap_send_MIABF1SetupOutcomeNotification( SI_F1AP_DT_PDU_MIABF1SetupOutcomeNotification * objMIABF1SetupOutcomeNotification, SI_F1APNode * f1apNode);
int __si_f1ap_send_MulticastContextNotificationIndication( SI_F1AP_DT_PDU_MulticastContextNotificationIndication * objMulticastContextNotificationIndication, SI_F1APNode * f1apNode);
int __si_f1ap_send_MulticastContextNotificationConfirm( SI_F1AP_DT_PDU_MulticastContextNotificationConfirm * objMulticastContextNotificationConfirm, SI_F1APNode * f1apNode);
int __si_f1ap_send_MulticastContextNotificationRefuse( SI_F1AP_DT_PDU_MulticastContextNotificationRefuse * objMulticastContextNotificationRefuse, SI_F1APNode * f1apNode);
int __si_f1ap_send_MulticastCommonConfigurationRequest( SI_F1AP_DT_PDU_MulticastCommonConfigurationRequest * objMulticastCommonConfigurationRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_MulticastCommonConfigurationResponse( SI_F1AP_DT_PDU_MulticastCommonConfigurationResponse * objMulticastCommonConfigurationResponse, SI_F1APNode * f1apNode);
int __si_f1ap_send_MulticastCommonConfigurationRefuse( SI_F1AP_DT_PDU_MulticastCommonConfigurationRefuse * objMulticastCommonConfigurationRefuse, SI_F1APNode * f1apNode);
int __si_f1ap_send_BroadcastTransportResourceRequest( SI_F1AP_DT_PDU_BroadcastTransportResourceRequest * objBroadcastTransportResourceRequest, SI_F1APNode * f1apNode);
int __si_f1ap_send_DUCUAccessAndMobilityIndication( SI_F1AP_DT_PDU_DUCUAccessAndMobilityIndication * objDUCUAccessAndMobilityIndication, SI_F1APNode * f1apNode);
int __si_f1ap_send_SRSInformationReservationNotification( SI_F1AP_DT_PDU_SRSInformationReservationNotification * objSRSInformationReservationNotification, SI_F1APNode * f1apNode);



#endif

