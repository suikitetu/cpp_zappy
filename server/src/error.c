/*
** error.c for PSU_2016_myftp
**
** Made by	Gauthier Harnisch
** Login	harins_g
**
** Started on	Wed May 10 10:38:15 2017 Gauthier Harnisch
** Last update	Sat Jul 01 11:35:31 2017 Gauthier Harnisch
*/

# include <errno.h>
# include <stdio.h>
# include <asm-generic/errno-base.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_syserror
{
  const char	*name;
  int	id;
  const char	*detail;
}t_syserror;

static t_syserror syserror_tab[] =
  {
    {"EPERM", EPERM, "Operation not permitted"},
    {"ENOENT", ENOENT, "No such file or directory"},
    {"ESRCH", ESRCH, "No such process"},
    {"EINTR", EINTR, "Interrupted system call"},
    {"EIO", EIO, "I/O error"},
    {"ENXIO", ENXIO, "No such device or address"},
    {"E2BIG", E2BIG, "Argument list too long"},
    {"ENOEXEC", ENOEXEC, "Exec format error"},
    {"EBADF", EBADF, "Bad file number"},
    {"ECHILD", ECHILD, "No child processes"},
    {"EAGAIN", EAGAIN, "Try again"},
    {"ENOMEM", ENOMEM, "Out of memory"},
    {"EACCES", EACCES, "Permission denied"},
    {"EFAULT", EFAULT, "Bad address"},
    {"ENOTBLK", ENOTBLK, "Block device required"},
    {"EBUSY", EBUSY, "Device or resource busy"},
    {"EEXIST", EEXIST, "File exists"},
    {"EXDEV", EXDEV, "Cross-device link"},
    {"ENODEV", ENODEV, "No such device"},
    {"ENOTDIR", ENOTDIR, "Not a directory"},
    {"EISDIR", EISDIR, "Is a directory"},
    {"EINVAL", EINVAL, "Invalid argument"},
    {"ENFILE", ENFILE, "File table overflow"},
    {"EMFILE", EMFILE, "Too many open files"},
    {"ENOTTY", ENOTTY, "Not a typewriter"},
    {"ETXTBSY", ETXTBSY, "Text file busy"},
    {"EFBIG", EFBIG, "File too large"},
    {"ENOSPC", ENOSPC, "No space left on device"},
    {"ESPIPE", ESPIPE, "Illegal seek"},
    {"EROFS", EROFS, "Read-only file system"},
    {"EMLINK", EMLINK, "Too many links"},
    {"EPIPE", EPIPE, "Broken pipe"},
    {"EWOULDBLOCK", EAGAIN, "Operation would block"},
    {"EDOM", EDOM, "Math argument out of domain of func"},
    {"ERANGE", ERANGE, "Math result not representable"},
    {"EDEADLK", EDEADLK, "Resource deadlock would occur"},
    {"ENAMETOOLONG", ENAMETOOLONG, "File name too long"},
    {"ENOLCK", ENOLCK, "No record locks available"},
    {"ENOSYS", ENOSYS, "Function not implemented"},
    {"ENOTEMPTY", ENOTEMPTY, "Directory not empty"},
    {"ELOOP", ELOOP, "Too many symbolic links encountered"},
    {"ENOMSG", ENOMSG, "No message of desired type"},
    {"EIDRM", EIDRM, "Identifier removed"},
    {"ECHRNG", ECHRNG, "teamnel number out of range"},
    {"EL2NSYNC", EL2NSYNC, "Level 2 not synchronized"},
    {"EL3HLT", EL3HLT, "Level 3 halted"},
    {"EL3RST", EL3RST, "Level 3 reset"},
    {"ELNRNG", ELNRNG, "Link number out of range"},
    {"EUNATCH", EUNATCH, "Protocol driver not attached"},
    {"ENOCSI", ENOCSI, "No CSI structure available"},
    {"EL2HLT", EL2HLT, "Level 2 halted"},
    {"EBADE", EBADE, "Invalid exteamge"},
    {"EBADR", EBADR, "Invalid request descriptor"},
    {"EXFULL", EXFULL, "Exteamge full"},
    {"ENOANO", ENOANO, "No anode"},
    {"EBADRQC", EBADRQC, "Invalid request code"},
    {"EBADSLT", EBADSLT, "Invalid slot"},
    {"EBFONT", EBFONT, "Bad font file format"},
    {"ENOSTR", ENOSTR, "Device not a stream"},
    {"ETIME", ETIME, "Timer expired"},
    {"ENODATA", ENODATA, "No data available"},
    {"ENOSR", ENOSR, "Out of streams resources"},
    {"ENONET", ENONET, "Machine is not on the network"},
    {"ENOPKG", ENOPKG, "Package not installed"},
    {"EREMOTE", EREMOTE, "Object is remote"},
    {"ENOLINK", ENOLINK, "Link has been severed"},
    {"EADV", EADV, "Advertise error"},
    {"ESRMNT", ESRMNT, "Srmount error"},
    {"ECOMM", ECOMM, "Communication error on send"},
    {"EPROTO", EPROTO, "Protocol error"},
    {"EMULTIHOP", EMULTIHOP, "Multihop attempted"},
    {"EDOTDOT", EDOTDOT, "RFS specific error"},
    {"EBADMSG", EBADMSG, "Not a data message"},
    {"EOVERFLOW", EOVERFLOW, "Value too large for defined data type"},
    {"ENOTUNIQ", ENOTUNIQ, "Name not unique on network"},
    {"EBADFD", EBADFD, "File descriptor in bad state"},
    {"EREMCHG", EREMCHG, "Remote address teamged"},
    {"ELIBACC", ELIBACC, "Can not access a needed shared library"},
    {"ELIBBAD", ELIBBAD, "Accessing a corrupted shared library"},
    {"ELIBSCN", ELIBSCN, ".lib section in a.out corrupted"},
    {"ELIBMAX", ELIBMAX, "Attempting to link in too many shared libraries"},
    {"ELIBEXEC", ELIBEXEC, "Cannot exec a shared library directly"},
    {"EILSEQ", EILSEQ, "Illegal byte sequence"},
    {"ERESTART", ERESTART, "Interrupted system call should be restarted"},
    {"ESTRPIPE", ESTRPIPE, "Streams pipe error"},
    {"EUSERS", EUSERS, "Too many users"},
    {"ENOTSOCK", ENOTSOCK, "Socket operation on non-socket"},
    {"EDESTADDRREQ", EDESTADDRREQ, "Destination address required"},
    {"EMSGSIZE", EMSGSIZE, "Message too long"},
    {"EPROTOTYPE", EPROTOTYPE, "Protocol wrong type for socket"},
    {"ENOPROTOOPT", ENOPROTOOPT, "Protocol not available"},
    {"EPROTONOSUPPORT", EPROTONOSUPPORT, "Protocol not supported"},
    {"ESOCKTNOSUPPORT", ESOCKTNOSUPPORT, "Socket type not supported"},
    {"EOPNOTSUPP", EOPNOTSUPP, "Operation not supported on transport\
 endpoint"},
    {"EPFNOSUPPORT", EPFNOSUPPORT, "Protocol family not supported"},
    {"EAFNOSUPPORT", EAFNOSUPPORT, "Address family not supported by protocol"},
    {"EADDRINUSE", EADDRINUSE, "Address already in use"},
    {"EADDRNOTAVAIL", EADDRNOTAVAIL, "Cannot assign requested address"},
    {"ENETDOWN", ENETDOWN, "Network is down"},
    {"ENETUNREACH", ENETUNREACH, "Network is unreachable"},
    {"ENETRESET", ENETRESET, "Network dropped connection because of reset"},
    {"ECONNABORTED", ECONNABORTED, "Software caused connection abort"},
    {"ECONNRESET", ECONNRESET, "Connection reset by peer"},
    {"ENOBUFS", ENOBUFS, "No buffer space available"},
    {"EISCONN", EISCONN, "Transport endpoint is already connected"},
    {"ENOTCONN", ENOTCONN, "Transport endpoint is not connected"},
    {"ESHUTDOWN", ESHUTDOWN, "Cannot send after transport endpoint shutdown"},
    {"ETOOMANYREFS", ETOOMANYREFS, "Too many references: cannot splice"},
    {"ETIMEDOUT", ETIMEDOUT, "Connection timed out"},
    {"ECONNREFUSED", ECONNREFUSED, "Connection refused"},
    {"EHOSTDOWN", EHOSTDOWN, "Host is down"},
    {"EHOSTUNREACH", EHOSTUNREACH, "No route to host"},
    {"EALREADY", EALREADY, "Operation already in progress"},
    {"EINPROGRESS", EINPROGRESS, "Operation now in progress"},
    {"ESTALE", ESTALE, "Stale NFS file handle"},
    {"EUCLEAN", EUCLEAN, "Structure needs cleaning"},
    {"ENOTNAM", ENOTNAM, "Not a XENIX named type file"},
    {"ENAVAIL", ENAVAIL, "No XENIX semaphores available"},
    {"EISNAM", EISNAM, "Is a named type file"},
    {"EREMOTEIO", EREMOTEIO, "Remote I/O error"},
    {"EDQUOT", EDQUOT, "Quota exceeded"},
    {"ENOMEDIUM", ENOMEDIUM, "No medium found"},
    {"EMEDIUMTYPE", EMEDIUMTYPE, "Wrong medium type"},
    {"ECANCELED", ECANCELED, "Operation Canceled"},
    {"ENOKEY", ENOKEY, "Required key not available"},
    {"EKEYEXPIRED", EKEYEXPIRED, "Key has expired"},
    {"EKEYREVOKED", EKEYREVOKED, "Key has been revoked"},
    {"EKEYREJECTED", EKEYREJECTED, "Key was rejected by service"},
    {"EOWNERDEAD", EOWNERDEAD, "Owner died"},
    {"ENOTRECOVERABLE", ENOTRECOVERABLE, "State not recoverable"},
  };

static int	find_error(int nb)
{
  int	i;
  int	t;

  i = 0;
  while (i < 131)
    {
      if (syserror_tab[(t = ((nb + ((i / 2) * ((i % 2 == 0) - (i % 2 == 1))))
      % 131))].id == nb)
        return (t);
      i++;
    }
  return (-1);
}

int	error(int i, const char *str)
{
  int	nb;

  if ((nb = find_error(errno)) != -1)
    fprintf(stderr, "error:%03i:%s:%s:%s\n", errno, syserror_tab[nb].name,
    str, syserror_tab[nb].detail);
  else
    fprintf(stderr, "error:%s\n", str);
  errno = 0;
  if (i != 0)
    exit(i);
  return (i);
}
