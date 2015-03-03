/* rdict.x */

/* RPC declarations for dictionary program */

struct dictionary {	
	string	word<>;
	string	meaning<>;
};


/*------------------------------------------------------------------------
 * RDICTPROG - remote program that provides insert, delete, and lookup
 *------------------------------------------------------------------------
 */
program RDICTPROG {		/* name of remote program (not used)	*/
    version RDICTVERS {		/* declaration of version (see below)	*/
    string 
    INSERTW(dictionary) = 1;    /* first procedure in this program	*/
    string
    DELETEW(string)     = 2;    /* second procedure in this program	*/
    string
    LOOKUPW(string)     = 3;    /* third procedure in this program	*/
    } = 1;			/* definition of the program version	*/
} = 0x30090949;			/* remote program number (must be	*/
				/*  unique)				*/

