/*	$OpenBSD: refuse.c,v 1.1 1997/02/26 03:06:55 downsj Exp $	*/

 /*
  * refuse() reports a refused connection, and takes the consequences: in
  * case of a datagram-oriented service, the unread datagram is taken from
  * the input queue (or inetd would see the same datagram again and again);
  * the program is terminated.
  * 
  * Author: Wietse Venema, Eindhoven University of Technology, The Netherlands.
  */

#ifndef lint
#if 0
static char sccsid[] = "@(#) refuse.c 1.5 94/12/28 17:42:39";
#else
static char rcsid[] = "$OpenBSD: refuse.c,v 1.1 1997/02/26 03:06:55 downsj Exp $";
#endif
#endif

/* System libraries. */

#include <stdio.h>
#include <syslog.h>

/* Local stuff. */

#include "tcpd.h"

/* refuse - refuse request */

void    refuse(request)
struct request_info *request;
{
    syslog(deny_severity, "refused connect from %s", eval_client(request));
    clean_exit(request);
    /* NOTREACHED */
}

