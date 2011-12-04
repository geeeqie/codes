/*
 * LocalHostInfo.c
 *
 * @author Geeeqie@gmail.com
 * @date 2011/12/04
 * @description
 */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iphlpapi.h>

int main(int argc, char** argv)
{
	WSADATA wsaData;
	PIP_ADAPTER_INFO pAdapterInfo = NULL, pAdapter = NULL;
	ULONG ulOutBufLen;
	u_char p[6];

	WSAStartup(MAKEWORD(2,2), &wsaData);

	if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW) {
		free(pAdapterInfo);
		pAdapterInfo = (PIP_ADAPTER_INFO) malloc(ulOutBufLen);
	}
	GetAdaptersInfo(pAdapterInfo, &ulOutBufLen);
	pAdapter = pAdapterInfo;
	while(pAdapter) {
		printf("\tAdapter Name: \t%s\n", pAdapter->AdapterName);
		printf("\tAdapter Desc: \t%s\n", pAdapter->Description);
		memcpy(p, pAdapter->Address, 6);
		printf("\tAdapter Addr: \t%02X:%02X:%02X:%02X:%02X:%02X\n",
				p[0],p[1],p[2],p[3],p[4],p[5]);
		printf("\tIP Addr: \t%s\n", pAdapter->IpAddressList.IpAddress.String);
		printf("\tIP Mask: \t%s\n", pAdapter->IpAddressList.IpMask.String);
		printf("\tIP Gateway: \t%s\n", pAdapter->GatewayList.IpAddress.String);
		if (pAdapter->DhcpEnabled) {
			printf("\tDHCP Enable: Yes\n");
			printf("\tLease Obtained: %ld\n", pAdapter->LeaseObtained);
		} else {
			printf("\tDHCP Enable: No\n");
		}
		if (pAdapter->HaveWins) {
			printf("\tHave Wins: Yes\n");
			printf("\t\tPrimary Wins Server: \t%s\n", pAdapter->PrimaryWinsServer.IpAddress.String);
			printf("\t\tSecondary Wins Server: \t%s\n", pAdapter->SecondaryWinsServer.IpAddress.String);
		} else {
			printf("\tHave Wins: No\n");
		}
		pAdapter = pAdapter->Next;
	}

	return 0;
}
