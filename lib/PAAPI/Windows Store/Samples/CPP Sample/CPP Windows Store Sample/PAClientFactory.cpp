#include "pch.h"
#include "PAClientFactory.h"

using namespace CPP_Windows_Store_Sample;

PreEmptive::Analytics::WinRT::PAClient^ PAClientFactory::GetPAClient()
{
	static PreEmptive::Analytics::WinRT::PAClient^ client;

	if (client == nullptr) 
	{
		// Required step: create the configuration structure and populate it
		// This tells the server who is sending the messages via the company and application IDs.
		// There are lots of other configuration settings that control the content and sending of messages.
		// The first GUID is the company ID provided by PreEmptive Solutions.
		// The second Guid is provided by you to identify the application.
		// This is the endpoint described here http://www.preemptive.com/support/resources/ris-ce
		auto configuration = ref new PreEmptive::Analytics::WinRT::Configuration("7d2b02e0-064d-49a0-bc1b-4be4381c62d3", "42AC2020-ABA1-9069-A2BD-98072B33309A");

		// Optional configuration
		configuration->CompanyName = "PreEmptive Solutions";
		configuration->ApplicationName = "C++ Sample App";
		configuration->ApplicationType = "C++ Sample";
		configuration->ApplicationVersion = "1.0";
		configuration->Endpoint = "message.runtimeintelligence.com/PreEmptive.Web.Services.Messaging/MessagingServiceV2.asmx";
		configuration->UseSSL = false;
		configuration->FullData = false;
		//configuration->SupportOfflineStorage = false;
		//configuration->OmitPersonalInfo = true;

		client = ref new PreEmptive::Analytics::WinRT::PAClient(configuration);
	}

	return client;
}

