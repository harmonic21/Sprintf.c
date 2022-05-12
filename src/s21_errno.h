#ifndef SRC_S21_ERRNO_H_
#define SRC_S21_ERRNO_H_

#ifdef __linux__
#define S21_SUCCESS 0

#elif defined __APPLE__
#define S21_ERROR 0
#endif

//  common
#define S21_EDEADLK 1
#define S21_EAGAIN 2
#define S21_EINPROGRESS 3
#define S21_EALREADY 4
#define S21_ENOTSOCK 5
#define S21_EDESTADDRREQ 6
#define S21_EMSGSIZE 7
#define S21_EPROTOTYPE 8
#define S21_ENOPROTOOPT 9
#define S21_EPROTONOSUPPORT 10
#define S21_ESOCKTNOSUPPORT 11
#define S21_EPFNOSUPPORT 12
#define S21_EAFNOSUPPORT 13
#define S21_EADDRINUSE 14
#define S21_EADDRNOTAVAIL 15
#define S21_ENETDOWN 16
#define S21_ENETUNREACH 17
#define S21_ENETRESET 18
#define S21_ECONNABORTED 19
#define S21_ECONNRESET 20
#define S21_ENOBUFS 21
#define S21_EISCONN 22
#define S21_ENOTCONN 23
#define S21_ESHUTDOWN 24
#define S21_ETOOMANYREFS 25
#define S21_ETIMEDOUT 26
#define S21_ECONNREFUSED 27
#define S21_ELOOP 28
#define S21_ENAMETOOLONG 29
#define S21_EHOSTDOWN 30
#define S21_EHOSTUNREACH 31
#define S21_ENOTEMPTY 32
#define S21_EUSERS 33
#define S21_EDQUOT 34
#define S21_ESTALE 35
#define S21_EREMOTE 36
#define S21_ENOLCK 37
#define S21_ENOSYS 38
#define S21_EOVERFLOW 39
#define S21_ECANCELED 40
#define S21_EIDRM 41
#define S21_ENOMSG 42
#define S21_EBADMSG 43
#define S21_EMULTIHOP 44
#define S21_ENODATA 45
#define S21_ENOLINK 46
#define S21_ENOSR 47
#define S21_ENOSTR 48
#define S21_EPROTO 49
#define S21_EOPNOTSUPP 50
#define S21_ENOTRECOVERABLE 51
#define S21_EOWNERDEAD 52
#define S21_EPERM 53
#define S21_ENOENT 54
#define S21_EINTR 55
#define S21_EIO 56
#define S21_ENXIO 57
#define S21_E2BIG 58
#define S21_ENOEXEC 59
#define S21_EBADF 60
#define S21_ECHILD 61
#define S21_ENOMEM 62
#define S21_EACCES 63
#define S21_EFAULT 64
#define S21_ENOTBLK 65
#define S21_EBUSY 66
#define S21_EEXIST 67
#define S21_EXDEV 68
#define S21_ENODEV 69
#define S21_EISDIR 70
#define S21_EINVAL 71
#define S21_ENFILE 72
#define S21_ENOTTY 73
#define S21_ETXTBSY 74
#define S21_EFBIG 75
#define S21_ENOSPC 76
#define S21_ESPIPE 77
#define S21_EROFS 78
#define S21_EMLINK 79
#define S21_EPIPE 80
#define S21_EDOM 81
#define S21_ERANGE 82
#define S21_EBADE 83
#define S21_ESRCH 84
#define s21_EMFILE 85
#define s21_EMLINK 86
#define s21_ETIME 87
#define s21_EILSEQ 88

//  linux
#ifdef __linux__
#define S21_EL2NSYNC 89
#define S21_ENOTDIR 90
#define S21_ECHRNG 91
#define S21_EL3HLT 92
#define S21_EL3RST 93
#define S21_ELNRNG 94
#define S21_EUNATCH 95
#define S21_ENOCSI 96
#define S21_EL2HLT 97
#define S21_EBADR 98
#define S21_EXFULL 99
#define S21_ENOANO 100
#define S21_EBADRQC 101
#define S21_EBADSLT 102
#define S21_ENONET 103
#define S21_ENOPKG 104
#define S21_EADV 105
#define S21_ESRMNT 106
#define S21_ECOMM 107
#define S21_EDOTDOT 108
#define S21_ENOTUNIQ 109
#define S21_EBADFD 110
#define S21_EREMCHG 111
#define S21_ELIBACC 112
#define S21_ELIBBAD 113
#define S21_ELIBSCN 114
#define S21_ELIBMAX 115
#define S21_ELIBEXEC 116
#define S21_ERESTART 117
#define S21_ESTRPIPE 118
#define S21_EUCLEAN 119
#define S21_ENOTNAM 120
#define S21_ENAVAIL 121
#define S21_EISNAM 122
#define S21_EREMOTEIO 123
#define S21_ENOMEDIUM 124
#define S21_EMEDIUMTYPE 125
#define S21_ENOKEY 126
#define S21_EKEYEXPIRED 127
#define S21_EKEYREVOKED 128
#define S21_EKEYREJECTED 129
#define S21_EBFONT 130

//  mac
#elif defined __APPLE__
#define S21_ENOTSUP 89
#define S21_EPROCLIM 90
#define S21_EBADRPC 91
#define S21_ERPCMISMATCH 92
#define S21_EPROGUNAVAIL 93
#define S21_EPROGMISMATCH 94
#define S21_EPROCUNAVAIL 95
#define S21_EFTYPE 96
#define S21_EAUTH 97
#define S21_ENEEDAUTH 98
#define S21_EPWROFF 99
#define S21_EDEVERR 100
#define S21_ENOATTR 101
#define S21_EBADARCH 102
#define S21_ESHLIBVERS 103
#define S21_EBADMACHO 104
#define S21_EQFULL 105
#define S21_ELAST 106
#define S21_ENOPOLICY 107
#endif

//  linux
#ifdef __linux__
#define MAX_ERRNUM 130

//  mac
#elif defined __APPLE__
#define MAX_ERRNUM 107

#elif defined _WIN32

#define MAX_ERRNUM 88

#endif

#define ERRMSG(err_num) (s21_errmsg[err_num])

#endif  //  SRC_S21_ERRNO_H_
