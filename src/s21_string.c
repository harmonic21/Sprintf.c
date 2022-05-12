#include "s21_string.h"
#include <stdlib.h>

const char* s21_errmsg[] = {
  #ifdef __linux__
        [S21_SUCCESS] = "Success",
  #elif defined __APPLE__
        [S21_ERROR] = "Not used",
  #endif
        [S21_EDEADLK] = "Resource deadlock would occur",
        [S21_EAGAIN] = "Resource unavailable, try again",
        [S21_EINPROGRESS] = "Operation in progress",
        [S21_EALREADY] = "Connection already in progress",
        [S21_ENOTSOCK] = "Not a socket",
        [S21_EDESTADDRREQ] = "Destination address required",
        [S21_EMSGSIZE] = "Message too large",
        [S21_EPROTOTYPE] = "Protocol wrong type for socket",
        [S21_ENOPROTOOPT] = "Protocol not available",
        [S21_EPROTONOSUPPORT] = "Protocol not supported",
        [S21_ESOCKTNOSUPPORT] = "Socket type not supported",
        [S21_EPFNOSUPPORT] = "Protocol family not supported",
        [S21_EAFNOSUPPORT] = "Address family not supported",
        [S21_EADDRINUSE] = "Address in use",
        [S21_EADDRNOTAVAIL] = "Address not available",
        [S21_ENETDOWN] = "Network is down",
        [S21_ENETUNREACH] = "Network unreachable",
        [S21_ENETRESET] = "Connection aborted by network",
        [S21_ECONNABORTED] = "Connection aborted",
        [S21_ECONNRESET] = "Connection reset",
        [S21_ENOBUFS] = "No buffer space available",
        [S21_EISCONN] = "Socket is connected",
        [S21_ENOTCONN] = "The socket is not connected",
        [S21_ESHUTDOWN] = "Cannot send after transport endpoint shutdown",
        [S21_ETOOMANYREFS] = "Too many references: cannot splice",
        [S21_ETIMEDOUT] = "Connection timed out",
        [S21_ECONNREFUSED] = "Connection refused",
        [S21_ELOOP] = "Too many levels of symbolic links",
        [S21_ENAMETOOLONG] = "Filename too long",
        [S21_EHOSTDOWN] = "Host is down",
        [S21_EHOSTUNREACH] = "Host is unreachable",
        [S21_ENOTEMPTY] = "Directory not empty",
        [S21_EUSERS] = "Too many users",
        [S21_EDQUOT] = "Disk quota exceeded",
        [S21_ESTALE] = "Stale file handle",
        [S21_EREMOTE] = "Object is remote",
        [S21_ENOLCK] = "No locks available",
        [S21_ENOSYS] = "Functionality not supported",
        [S21_EOVERFLOW] = "Value too large to be stored in data type",
        [S21_ECANCELED] = "Operation canceled",
        [S21_EIDRM] = "Identifier removed",
        [S21_ENOMSG] = "No message of the desired type",
        [S21_EBADMSG] = "Bad message",
        [S21_EMULTIHOP] = "Reserved",
        [S21_ENODATA] = "No message is available on the STREAM head read queue",
        [S21_ENOLINK] = "Reserved",
        [S21_ENOSR] = "No STREAM resources",
        [S21_ENOSTR] = "Not a STREAM",
        [S21_EPROTO] = "Protocol error",
        [S21_EOPNOTSUPP] = "Operation not supported on socket",
        [S21_ENOTRECOVERABLE] = "State not recoverable",
        [S21_EOWNERDEAD] = "Previous owner died",
        [S21_EPERM] = "Operation not permitted",
        [S21_ENOENT] = "No such file or directory",
        [S21_EINTR] = "Interrupted function",
        [S21_EIO] = "I/O error",
        [S21_ENXIO] = "No such device or address",
        [S21_E2BIG] = "Argument list too long",
        [S21_ENOEXEC] = "Executable file format error",
        [S21_EBADF] = "Bad file descriptor",
        [S21_ECHILD] = "No child processes",
        [S21_ENOMEM] = "Not enough space",
        [S21_EACCES] = "Permission denied",
        [S21_EFAULT] = "Bad address",
        [S21_ENOTBLK] = "Block device required",
        [S21_EBUSY] = "Device or resource busy",
        [S21_EEXIST] = "File exists",
        [S21_EXDEV] = "Cross-device link",
        [S21_ENODEV] = "No such device",
        [S21_EISDIR] = "Is a directory",
        [S21_EINVAL] = "Invalid argument",
        [S21_ENFILE] = "Too many files open in system",
        [S21_ENOTTY] = "Inappropriate I/O control operation",
        [S21_ETXTBSY] = "Text file busy",
        [S21_EFBIG] = "File too large",
        [S21_ENOSPC] = "No space left on device",
        [S21_ESPIPE] = "Invalid seek",
        [S21_EROFS] = "Read-only file system",
        [S21_EMLINK] = "Too many links",
        [S21_EPIPE] = "Broken pipe",
        [S21_EDOM] = "Mathematics argument out of domain of function",
        [S21_ERANGE] = "Result too large",
        [S21_EBADE] = "Invalid exchange",
        [S21_ESRCH] = "No such process",
        [s21_EMFILE] = "File descriptor value too large",
        [s21_EMLINK] = "Too many links",
        [s21_ETIME] = "Timer expired",
        [s21_EILSEQ] = "Illegal byte sequence",
#ifdef __linux__
        [S21_EL2NSYNC] = "Level 2 not synchronized",
        [S21_ENOTDIR] = "Not a directory or a symbolic link to a directory",
        [S21_ECHRNG] = "Channel number out of range",
        [S21_EL3HLT] = "Level 3 halted",
        [S21_EL3RST] = "Level 3 reset",
        [S21_ELNRNG] = "Link number out of range",
        [S21_EUNATCH] = "Protocol driver not attached",
        [S21_ENOCSI] = "No CSI structure available",
        [S21_EL2HLT] = "Level 2 halted",
        [S21_EBADR] = "Invalid request descriptor",
        [S21_EXFULL] = "Exchange full",
        [S21_ENOANO] = "No anode",
        [S21_EBADRQC] = "Invalid request code",
        [S21_EBADSLT] = "Invalid slot",
        [S21_ENONET] = "Machine is not on the network",
        [S21_ENOPKG] = "Package not installed",
        [S21_EADV] = "Advertise error",
        [S21_ESRMNT] = "Srmount error",
        [S21_ECOMM] = "Communication error on send",
        [S21_EDOTDOT] = "RFS specific error",
        [S21_ENOTUNIQ] = "Name not unique on network",
        [S21_EBADFD] = "File descriptor in bad state",
        [S21_EREMCHG] = "Remote address changed",
        [S21_ELIBACC] = "Can not access a needed shared library",
        [S21_ELIBBAD] = "Accessing a corrupted shared library",
        [S21_ELIBSCN] = ".lib section in a.out corrupted",
        [S21_ELIBMAX] = "Attempting to link in too many shared libraries",
        [S21_ELIBEXEC] = "Cannot exec a shared library directly",
        [S21_ERESTART] = "Interrupted system call should be restarted",
        [S21_ESTRPIPE] = "Streams pipe error",
        [S21_EUCLEAN] = "Structure needs cleaning",
        [S21_ENOTNAM] = "Not a XENIX named type file",
        [S21_ENAVAIL] = "No XENIX semaphores available",
        [S21_EISNAM] = "Is a named type file",
        [S21_EREMOTEIO] = "I/O error",
        [S21_ENOMEDIUM] = "No medium found",
        [S21_EMEDIUMTYPE] = "Wrong medium type",
        [S21_ENOKEY] = "Required key not available",
        [S21_EKEYEXPIRED] = "Key has expired",
        [S21_EKEYREVOKED] = "Key has been revoked",
        [S21_EKEYREJECTED] = "Key was rejected by service",
        [S21_EBFONT] = "Bad font file format",
#elif defined __APPLE__
        [S21_ENOTSUP] = "Not supported",
        [S21_EPROCLIM] = "Too many processes",
        [S21_EBADRPC] = "RPC struct is bad",
        [S21_ERPCMISMATCH] = "RPC version wrong",
        [S21_EPROGUNAVAIL] = "RPC prog. not avail",
        [S21_EPROGMISMATCH] = "Program version wrong",
        [S21_EPROCUNAVAIL] = "Bad procedure for program",
        [S21_EFTYPE] = "Inappropriate file type or format",
        [S21_EAUTH] = "Authentication error",
        [S21_ENEEDAUTH] = "Need authenticator",
        [S21_EPWROFF] = "Device power is off",
        [S21_EDEVERR] = "Device error",
        [S21_ENOATTR] = "Attribute not found",
        [S21_EBADARCH] = "Bad CPU type in executable",
        [S21_ESHLIBVERS] = "Shared library version mismatch",
        [S21_EBADMACHO] = "Malformed Mach-o file",
        [S21_EQFULL] = "Interface output queue is full",
        [S21_ELAST] = "Must be equal largest errno",
        [S21_ENOPOLICY] = "No such policy registered",
#endif
};

void* s21_memset(void* str, int c, s21_size_t n) {
  char* result_str = (char*)str;
  for (s21_size_t i = 0; i < n; i++) {
    result_str[i] =(char) c;
  }
  return str;
}

s21_size_t s21_strlen(const char *str) {
	const char *s;
	for (s = str; *s; ++s) {}
	return (s - str);
}

char *s21_strcat(char *dest, const char *src) {
	char* d = dest;
	char* src_work = (char*)src;
	while (*dest) {
		dest++;
	}
	while (*src_work) {
		*dest++ = *src_work++;
	}
	*dest = '\0';
	return d;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
	char *d = dest;
	const char *s = src;
	while (n--) {
		*d++ = *s++;
	}
	return dest;
}

char *s21_strcpy(char *dest, const char *src) {
	return s21_memcpy (dest, src, s21_strlen(src) + 1);
}

char* s21_strerror(int errnum) {
	char *result  = "Undefined error";

#ifdef __linux__
	if (errnum <= MAX_ERRNUM) {
        result = (char*)ERRMSG(errnum);
    }
#elif defined __APPLE__
	if (errnum <= MAX_ERRNUM) {
        result = (char*)ERRMSG(errnum);
    }
#endif
	return result;
}

char* s21_strpbrk(const char* str1, const char* str2) {
  int flag = 0;
  char* result = s21_NULL;
  for (int i = 0; str1[i] != '\0'; i++) {
    for (int j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        result = (char*)(str1 + i);
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      break;
    }
  }
  return result;
}

static int s21_delimetr(const char* delim, char symb) {
  int result = 0;

  for (int i = 0; delim[i] != '\0'; i++) {
    if (delim[i] == symb) {
      result = 1;
      break;
    }
  }
  return result;
}

char* s21_strtok(char* str, const char* delim) {
  static char* result = s21_NULL;
  int flag = 0;

  if (str != s21_NULL) {
    result = str;
  }
  char* ptr = s21_NULL;

  while (result != s21_NULL && *result) {
    if (flag == 0 && !s21_delimetr(delim, *result)) {
      ptr = result;
      flag = 1;
    }
    if (flag == 1 && s21_delimetr(delim, *result)) {
      *result = '\0';
      result++;
      break;
    }
    result++;
  }
  return ptr;
}

void* s21_to_upper(const char* str) {
  char* result = s21_NULL;
  size_t size = s21_strlen(str);
  if (size != 0) {
    result = (char*)malloc(sizeof(char) * size + 1);
    s21_strcpy(result, str);
    for (size_t i = 0; result[i] != '\0'; i++) {
      if (result[i] >= 'a' && result[i] <= 'z') {
        result[i] -= 32;
      }
    }
  }
  return result;
}
