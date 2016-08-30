#pragma once

// ========================================
//   Device information

#define DEVICE_NAME             L"\\Device\\HiddenGate"
#define DOS_DEVICES_LINK_NAME   L"\\DosDevices\\HiddenGate"
#define DEVICE_WIN32_NAME       L"\\\\.\\HiddenGate"

// ========================================
//   IOCTL codes

#define HID_IOCTL_SET_DRIVER_STATE               CTL_CODE (FILE_DEVICE_UNKNOWN, (0x800 +  0), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define HID_IOCTL_GET_DRIVER_STATE               CTL_CODE (FILE_DEVICE_UNKNOWN, (0x800 +  1), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)

#define HID_IOCTL_SET_STEALTH_MODE               CTL_CODE (FILE_DEVICE_UNKNOWN, (0x800 +  2), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)

#define HID_IOCTL_ADD_HIDDEN_OBJECT              CTL_CODE (FILE_DEVICE_UNKNOWN, (0x800 + 60), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define HID_IOCTL_REMOVE_HIDDEN_OBJECT           CTL_CODE (FILE_DEVICE_UNKNOWN, (0x800 + 61), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define HID_IOCTL_REMOVE_ALL_HIDDEN_OBJECTS      CTL_CODE (FILE_DEVICE_UNKNOWN, (0x800 + 62), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)

#define HID_IOCTL_ADD_OBJECT                     CTL_CODE (FILE_DEVICE_UNKNOWN, (0x800 + 70), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define HID_IOCTL_GET_OBJECT_STATE               CTL_CODE (FILE_DEVICE_UNKNOWN, (0x800 + 71), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define HID_IOCTL_SET_OBJECT_STATE               CTL_CODE (FILE_DEVICE_UNKNOWN, (0x800 + 72), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define HID_IOCTL_REMOVE_OBJECT                  CTL_CODE (FILE_DEVICE_UNKNOWN, (0x800 + 73), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define HID_IOCTL_REMOVE_ALL_OBJECTS             CTL_CODE (FILE_DEVICE_UNKNOWN, (0x800 + 74), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)

enum Hid_ObjectTypes {
	RegKeyObject,
	RegValueObject,
	FsFileObject,
	FsDirObject,
	PsExcludedObject,
	PsProtectedObject,
};

#pragma pack(push, 4)

typedef struct _Hid_HideObjectPacket {
	unsigned short objType;
	unsigned short size;
}  Hid_HideObjectPacket, *PHid_HideObjectPacket;

typedef struct _Hid_UnhideObjectPacket {
	unsigned short objType;
	unsigned short reserved;
	unsigned long long id;
}  Hid_UnhideObjectPacket, *PHid_UnhideObjectPacket;

typedef struct _Hid_UnhideAllObjectsPacket {
	unsigned short objType;
	unsigned short reserved;
}  Hid_UnhideAllObjectsPacket, *PHid_UnhideAllObjectsPacket;

typedef struct _Hid_StatusPacket {
	unsigned int status;
	union {
		unsigned long long id;
		unsigned long state;
	} info;
}  Hid_StatusPacket, *PHid_StatusPacket;

#pragma pack(pop)