#include<ntddk.h>


VOID DriverUnload(PDRIVER_OBJECT DriverObject)
{
	if (DriverObject != NULL)
	{
		DbgPrint("[%ws]Driver Upload, Driver Object Address:%p", __FUNCTIONW__, DriverObject);	//打印当前函数名
	}
	return;
}


NTSTATUS DriverEntry(
	PDRIVER_OBJECT	DriverObject,
	PUNICODE_STRING RegistryPath
)
{
	DbgPrint("[%ws]Hello Kernel World\n", __FUNCTIONW__);
	if (RegistryPath != NULL)
	{
		DbgPrint("[%ws]Driver RegistryPath:%wZ\n", __FUNCTIONW__, RegistryPath);	//用%wZ打印UNICODE_STRING类型
	}
	if (DriverObject != NULL)
	{
		DbgPrint("[%ws]Driver Object Address:%p\n", __FUNCTIONW__, DriverObject);
		DriverObject->DriverUnload = DriverUnload;
	}
	return STATUS_SUCCESS;


}
